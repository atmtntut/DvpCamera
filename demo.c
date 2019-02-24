#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>
#include "DVP_CamAPI.h"
#include "DVP_Define.h"
#include "DVP_Paramdef.h"
int m_iCameraID = 0;
char m_sCameraName[NAME_LEN_MAX] = {};
unsigned char* m_pImgBuf = NULL;
char* m_sTimeBuf[128] = {};

void trace(){    
    struct timeval tv;    
    gettimeofday(&tv,NULL);
    printf("[%d.%03d]\n", tv.tv_sec, tv.tv_usec / 1000);    
}    

void getCamera()
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
	BYTE* pBmp24 = CameraISP(iCamID,pImageBuffer, pFrInfo);
    if(pBmp24){
        printf("cameraisp success\n");
    }
    else{
        printf("cameraisp fail\n");
    }
	
	return 0;
}

void initCamera(){
    tDSFrameInfo sFrInfo = {};
    emDSCameraStatus status = CameraInitEx(m_sCameraName, &m_iCameraID);
    // emDSCameraStatus status = CameraInit(SnapCallBack, m_sCameraName, NULL, &m_iCameraID);
    if (status != STATUS_OK){          
        printf("init camera fail\n");
        return;   
    }    
    tDSCameraCapability sDSCameraCap = {};
    CameraGetCapability(m_iCameraID, sDSCameraCap);
    printf("%d, %d\n", sDSCameraCap.pImageSizeDesc[0].iWidth, sDSCameraCap.pImageSizeDesc[0].iHeight);


    BOOL bROI = FALSE; 
    INT iHOff = 0; 
    INT iVOff = 0; 
    INT iWidth = 0; 
    INT iHeight = 0; 
    status = CameraGetImageSize(m_iCameraID, &bROI, &iHOff, &iVOff, &iWidth, &iHeight, TRUE); 
    if (status != STATUS_OK){          
        printf("camera get imgsize fail\n");
        return;   
    }
    printf("bROI: %d, Offset: %d, %d, W&H: %d, %d\n", bROI, iHOff, iVOff, iWidth, iHeight);
    int iResSel = 0;
    status = CameraGetImageSizeSel(m_iCameraID, &iResSel, TRUE);
    if (status != STATUS_OK){          
        printf("camera get imgsizesel fail\n");
        return;   
    }
    printf("ressel: %d\n", iResSel);
    status = CameraPlay(m_iCameraID);   
    if (status != STATUS_OK){          
        printf("camera play fail\n");
        return;   
    }
    else{
        printf("camera play success\n");
    }
    // if(CameraSetImageSizeSel(m_iCameraID, 0, FALSE) != STATUS_OK){
    //     printf("set imgsizesel fail\n");
    // }
    // else{
    //     printf("set imgsizesel success\n");
    // }

    m_pImgBuf = (BYTE*)malloc((iWidth+1)*(iHeight+1)*3);
}

void pic(int iPicType){
    if(CameraSetOnceWB(m_iCameraID) != STATUS_OK){
        printf("wb fail\n");
    }
    else{
        printf("wb success\n");
    }
    trace();
    printf("picType: %d", iPicType);

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
}

void myprintf(){
    if(m_pImgBuf == NULL)return;
    for(int i=0;i<30;i++){
        if(i%15 == 0){
            printf("\n");
        }
        printf("%02x ", *(m_pImgBuf+i));
    }
    printf("\n");
}

int main(int argc, char** argv){
    int picType = 8;
    if(argc>1){
        picType = atoi(argv[1]);
    }

    getCamera();
    initCamera();
    pic(picType);
    myprintf();
    usleep(1000*1000);
    pic(picType);
    myprintf();

    if(m_pImgBuf){
        free(m_pImgBuf);
    }
    return 0;
}
