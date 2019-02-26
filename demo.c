#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include "DVP_CamAPI.h"
#include "DVP_Define.h"
#include "DVP_Paramdef.h"

// #ifdef _MSC_VER
//     #define DLL_EXPORT __declspec( dllexport ) 
// #else
//     #define DLL_EXPORT
// #endif

int m_iCameraID = 0;
char m_sCameraName[NAME_LEN_MAX] = {};
BYTE* m_pImgBuf = NULL;
BYTE* m_pRTImgBuf = NULL;
int iRTImgLen = 0;
char* m_sTimeBuf[128] = {};
volatile char m_signal = 0;

extern "C" {

void myprintf(BYTE* buffer){
    if(buffer == NULL)return;
    for(int i=0;i<30;i++){
        if(i%15 == 0){
            printf("\n");
        }
        printf("%02x ", *(buffer+i));
    }
    printf("\n");
}

DLL_EXPORT void trace(){    
    struct timeval tv;    
    gettimeofday(&tv,NULL);
    printf("[%d.%03d]\n", tv.tv_sec, tv.tv_usec / 1000);    
}    

void openCam()
{
    tDSCameraDevInfo DSCameraList[5];   
    int m_iNum = 0;   
    //int m_iCameraID = 0;
    //CameraStop(m_iCameraID);   
    //CameraUnInit(m_iCameraID);   
    CameraGetDevList(DSCameraList, &m_iNum);   
    if (m_iNum < 1){
        printf("no camera\n");
    }    
    else{   
        for (int i=0; i<m_iNum; i++){   
            memset(m_sCameraName, 0, NAME_LEN_MAX);
            memcpy(m_sCameraName, DSCameraList[i].acFriendlyName, NAME_LEN_MAX-1);
            printf("%s\n", DSCameraList[i].acFriendlyName);
        }                  
    }   
}

INT CALLBACK SnapCallBack(INT iCamID, BYTE *pImageBuffer, tDSFrameInfo *pFrInfo)
{
	//TRACE("%ld\n",pFrInfo->uiTimeStamp);
    // printf("***********************************************\n");
    // printf("entry snap call back\n");
    // trace();
	BYTE* pImg = CameraISP(iCamID, pImageBuffer, pFrInfo);
    if(pImg){
        // printf("cameraisp success\n");
        // CameraDisplayRGB24(iCamID, pBmp24, pFrInfo);
        // printf("num: %d\n", pFrInfo->uBytes);
        // printf("W&H: %d, %d\n", pFrInfo->uiWidth, pFrInfo->uiHeight);
        if(m_signal==0){
            m_signal++;
            memcpy(m_pRTImgBuf, pImg, pFrInfo->uBytes);
            m_signal--;
        }
        //myprintf(m_pRTImgBuf);
        // myprintf(pImg);
    }
    else{
        printf("cameraisp fail\n");
    }
    // printf("***********************************************\n");
	return 0;
}

BYTE* getImage(){
    while(m_signal!=0){
        usleep(1000);
    }
    // FILE* fd = fopen("img.bin", "wb");
    // if(fd){
    //     printf("open img.bin success\n");
    //     fwrite(m_pRTImgBuf, 1, iRTImgLen, fd);
    //     fclose(fd);
    // }
    // else{
    //     printf("open img.bin fail\n");
    // }
    return m_pRTImgBuf;
}

void initCam(void* hWnd){
    openCam();
    tDSFrameInfo sFrInfo = {};
    // emDSCameraStatus status = CameraInitEx(m_sCameraName, &m_iCameraID);
    emDSCameraStatus status = CameraInit(SnapCallBack, m_sCameraName, (HWND)hWnd, &m_iCameraID);
    if (status != STATUS_OK){          
        printf("init camera fail\n");
        return;   
    }    
    tDSCameraCapability sDSCameraCap = {};
    CameraGetCapability(m_iCameraID, sDSCameraCap);
    for(int i=0;i<sDSCameraCap.iImageSizeDesc;i++){
        printf("W&H: %d, %d\n", sDSCameraCap.pImageSizeDesc[i].iWidth, sDSCameraCap.pImageSizeDesc[i].iHeight);
    }
    if(CameraSetImageSizeSel(m_iCameraID, 5, FALSE) != STATUS_OK){
        printf("set imgsizesel fail\n");
    }
    else{
        printf("set imgsizesel success\n");
    }

    BOOL bROI = FALSE; 
    INT iHOff = 0; 
    INT iVOff = 0; 
    INT iWidth = 0; 
    INT iHeight = 0; 
    status = CameraGetImageSize(m_iCameraID, &bROI, &iHOff, &iVOff, &iWidth, &iHeight, FALSE); 
    if (status != STATUS_OK){          
        printf("camera get imgsize fail\n");
        return;   
    }
    else{
        printf("bROI: %d, Offset: %d, %d, W&H: %d, %d\n", bROI, iHOff, iVOff, iWidth, iHeight);
    }

    iRTImgLen = iWidth*iHeight*3;
    m_pRTImgBuf = (BYTE*)malloc(iRTImgLen);

    int iResSel = 0;
    status = CameraGetImageSizeSel(m_iCameraID, &iResSel, FALSE);
    if (status != STATUS_OK){          
        printf("camera get imgsizesel fail\n");
        return;   
    }
    else{
        printf("ressel: %d\n", iResSel);
    }
    status = CameraPlay(m_iCameraID);   
    if (status != STATUS_OK){          
        printf("camera play fail\n");
        return;   
    }
    else{
        printf("camera play success\n");
    }

    m_pImgBuf = (BYTE*)malloc((iWidth+1)*(iHeight+1)*3);
    // if(CameraSetOnceWB(m_iCameraID) != STATUS_OK){
    //     printf("wb fail\n");
    // }
    // else{
    //     printf("wb success\n");
    // }
}

void pic(int iPicType){
    printf("pic bgn picType: %d\n", iPicType);
    trace();

    if (CameraCaptureFile(m_iCameraID, "E:\\test", iPicType, 90) != STATUS_OK){
    //if (CameraCaptureFile(m_iCameraID, NULL, iPicType, 90) != STATUS_OK){
        printf("capture file fail\n");
    }
    else{
        printf("capture file success\n");
    }
    trace();

    tDSFrameInfo sFrInfo = {};
    if(CameraGetImageData(m_iCameraID, m_pImgBuf, DATA_TYPE_RGB8, sFrInfo) != STATUS_OK){
        printf("get imgdata fail\n");
    }
    else{
        printf("get imgdata success\n");
    }
    trace();

    // if (CameraGetImageBuffer(m_iCameraID, DATA_TYPE_RGB8, &m_pImgBuf) != STATUS_OK){          
    //     printf("get imgbuf fail\n");
    // }    
    // else{
    //     printf("get imgbuf success\n");
    // }
    // trace();
    printf("pic end\n");
}

int main(int argc, char** argv){
    int picType = 8;
    if(argc>1){
        picType = atoi(argv[1]);
    }

    // initCamera();
    // for(int i=0;i<3;i++){
    //     pic(picType);
    //     myprintf();
    //     // usleep(1000*1000);
    //     // CameraReleaseImageBuffer(m_iCameraID, DATA_TYPE_RGB8, m_pImgBuf); 
    //     // m_pImgBuf = NULL;
    // }

    if(m_pImgBuf){
        free(m_pImgBuf);
    }
    return 0;
}

}