#ifndef _CAMAPI_H_ 
#define _CAMAPI_H_ 
#include "DVP_Define.H" 
#define DLL_EXPORT
#ifdef DLL_EXPORT
#define DS_API extern "C" __declspec(dllexport)
#else
#define DS_API extern "C" __declspec(dllimport)
#endif
DS_API emDSCameraStatus CameraGetDevList(tDSCameraDevInfo *pDSCameraList, INT *piNums); 
DS_API emDSCameraStatus CameraInit(DS_SNAP_PROC pCallbackFunction,  
                                         LPCSTR lpszFriendlyName, 
                                           HWND hWndDisplay, 
                                            INT *piCameraID); 
DS_API emDSCameraStatus CameraInitEx(LPCSTR lpszFriendlyName, INT *piCameraID); 
DS_API emDSCameraStatus CameraGetCapability(INT iCameraID, tDSCameraCapability &sDSCameraCap); 
DS_API emDSCameraStatus CameraUnInit(INT iCameraID); 
DS_API emDSCameraStatus CameraPlay(INT iCameraID); 
DS_API emDSCameraStatus CameraPause(INT iCameraID); 
DS_API emDSCameraStatus CameraStop(INT iCameraID); 
DS_API emDSCameraStatus CameraPowerUp(INT iCameraID); 
DS_API emDSCameraStatus CameraPowerDown(INT iCameraID); 
DS_API BYTE* CameraISP(INT iCameraID, BYTE *pbyRAW, tDSFrameInfo *psFrInfo); 
DS_API emDSCameraStatus CameraDisplayRGB24(INT iCameraID, BYTE *pbyRGB24, tDSFrameInfo *psFrInfo); 
DS_API emDSCameraStatus CameraDisplayROISel(INT iCameraID, tDSROISize sROISize); 
DS_API emDSCameraStatus CameraSetDisplaySize(INT iCameraID,  
                                             INT iWidth,  
                                             INT iHeight); 
DS_API emDSCameraStatus CameraStartRecordVideo(INT iCameraID, LPCSTR lpszFileName); 
DS_API emDSCameraStatus CameraStopRecordVideo(INT iCameraID); 
DS_API emDSCameraStatus CameraSetRecordFileSize(INT iCameraID, INT iFileSize); 
DS_API emDSCameraStatus CameraGetRecordFileSize(INT iCameraID, INT *piFileSize); 
DS_API emDSCameraStatus CameraSetRecordAVIQuality(INT iCameraID, INT iQuality); 
DS_API emDSCameraStatus CameraGetRecordAVIQuality(INT iCameraID, INT *piQuality); 
DS_API emDSCameraStatus CameraSetRecordEncoder(INT iCameraID, INT iCodeType); 
DS_API emDSCameraStatus CameraGetRecordEncoder(INT iCameraID, INT *piCodeType); 
DS_API emDSCameraStatus CameraGetRecordRate(INT iCameraID, float *pfRate); 
DS_API emDSCameraStatus CameraRecordFrame(INT iCameraID, BYTE *pbyRGB, tDSFrameInfo *psFrInfo); 
DS_API emDSCameraStatus CameraGetImageBuffer(INT iCameraID, emDSDataType emDataType, BYTE **pbyBuffer); 
DS_API emDSCameraStatus CameraReleaseImageBuffer(INT iCameraID, emDSDataType emDataType, BYTE *pbyBuffer); 
DS_API emDSCameraStatus CameraGetFrameCount(INT iCameraID, tDSFrameCount *psFrameCount); 
DS_API emDSCameraStatus CameraCaptureFile(INT iCameraID, LPCSTR lpszFileName, BYTE byFileType, BYTE byQuality); 
DS_API emDSCameraStatus CameraSaveBMPFile(INT iCameraID, LPCSTR lpszFileName, BYTE *pbyRGB24, tDSFrameInfo *psFrInfo); 
DS_API emDSCameraStatus CameraGetImageData(INT iCameraID,  
                                          BYTE *pbyImageBuffer, 
                                  emDSDataType emDataType, 
                                  tDSFrameInfo &sFrInfo); 
DS_API emDSCameraStatus CameraSaveCurrentImage(INT iCameraID,  
                                            LPCSTR lpszFileName, 
                                              BYTE *pbyImageBuffer, 
                                      tDSFrameInfo *psFrInfo, 
                                              BYTE byFileType,  
                                              BYTE byQuality); 
DS_API emDSCameraStatus CameraSetMirror(INT iCameraID, emDSMirrorDirection emDir, BOOL bEnable); 
DS_API emDSCameraStatus CameraGetMirror(INT iCameraID, emDSMirrorDirection emDir, BOOL *pbEnable); 
DS_API emDSCameraStatus CameraSetMonochrome(INT iCameraID, BOOL bEnable); 
DS_API emDSCameraStatus CameraGetMonochrome(INT iCameraID, BOOL *pbEnable); 
DS_API emDSCameraStatus CameraSetInverse(INT iCameraID, BOOL bEnable); 
DS_API emDSCameraStatus CameraGetInverse(INT iCameraID, BOOL *pbEnable); 
DS_API emDSCameraStatus CameraSetAeState(INT iCameraID, BOOL bState); 
DS_API emDSCameraStatus CameraGetAeState(INT iCameraID, BOOL *pbAeState); 
DS_API emDSCameraStatus CameraSetAeTarget(INT iCameraID, BYTE byAeTarget); 
DS_API emDSCameraStatus CameraGetAeTarget(INT iCameraID, BYTE *pbyAeTarget); 
DS_API emDSCameraStatus CameraSetAEWindow(INT iCameraID,  
                                          INT iHOff,  
                                          INT iVOff,  
                                          INT iWidth,  
                                          INT iHeight); 
DS_API emDSCameraStatus CameraSetExposureTime(INT iCameraID, UINT64 uExposureTime); 
DS_API emDSCameraStatus CameraGetExposureTime(INT iCameraID,  
                                           UINT64 *puExposureTime, 
                                           UINT64 *puExpTimeMax,  
                                           UINT64 *puExpTimeMin); 
DS_API emDSCameraStatus CameraSetAnalogGain(INT iCameraID, float fAnalogGain); 
DS_API emDSCameraStatus CameraGetAnalogGain(INT iCameraID, float *pfAnalogGain); 
DS_API emDSCameraStatus CameraSetDeadPixelCorrectionState(INT iCameraID, BOOL bEnable); 
DS_API emDSCameraStatus CameraGetDeadPixelCorrectionState(INT iCameraID, BOOL *pbEnable); 
DS_API emDSCameraStatus CameraCreateDefectCorrectionInfo(INT iCameraID); 
DS_API emDSCameraStatus CameraSetEdgeEnhance(INT iCameraID, BOOL bEnable); 
DS_API emDSCameraStatus CameraGetEdgeEnhance(INT iCameraID, BOOL *pbEnable); 
DS_API emDSCameraStatus CameraSetEdgeGain(INT iCameraID, BYTE byEdgeGain); 
DS_API emDSCameraStatus CameraGetEdgeGain(INT iCameraID, BYTE *pbyEdgeGain); 
DS_API emDSCameraStatus CameraSetNoiseReductionState(INT iCameraID, BOOL bReduction); 
DS_API emDSCameraStatus CameraGetNoiseReductionState(INT iCameraID, BOOL *pbReduction); 
DS_API emDSCameraStatus CameraSetNoiseReductionGain(INT iCameraID, INT iReduction); 
DS_API emDSCameraStatus CameraGetNoiseReductionGain(INT iCameraID, INT *piReduction); 
DS_API emDSCameraStatus CameraSetOnceWB(INT iCameraID); 
DS_API emDSCameraStatus CameraSetAWBState(INT iCameraID, BOOL bAWBState); 
DS_API emDSCameraStatus CameraGetAWBState(INT iCameraID, BOOL *pbAWBState); 
DS_API emDSCameraStatus CameraSetWBWindow(INT iCameraID,  
                                          INT iHOff,  
                                          INT iVOff,  
                                          INT iWidth,  
                                          INT iHeight); 
DS_API emDSCameraStatus CameraSetGain(INT iCameraID,  
                                    float fRGain,  
                                    float fGGain,  
                                    float fBGain); 
DS_API emDSCameraStatus CameraGetGain(INT iCameraID,  
                                    float *pfRGain,  
                                    float *pfGGain,  
                                    float *pfBGain); 
DS_API emDSCameraStatus CameraSetColorEnhancement(INT iCameraID, BOOL bEnable); 
DS_API emDSCameraStatus CameraGetColorEnhancement(INT iCameraID, BOOL *pbEnable); 
DS_API emDSCameraStatus CameraSetSaturation(INT iCameraID, BYTE bySaturation); 
DS_API emDSCameraStatus CameraGetSaturation(INT iCameraID, BYTE *pbySaturation); 
DS_API emDSCameraStatus CameraSetGamma(INT iCameraID, BYTE byGamma); 
DS_API emDSCameraStatus CameraGetGamma(INT iCameraID, BYTE *pbyGamma); 
DS_API emDSCameraStatus CameraSetContrast(INT iCameraID, BYTE byContrast); 
DS_API emDSCameraStatus CameraGetContrast(INT iCameraID, BYTE *pbyContrast); 
DS_API emDSCameraStatus CameraSetFrameSpeed(INT iCameraID, emDSFrameSpeed emFrameSpeed); 
DS_API emDSCameraStatus CameraGetFrameSpeed(INT iCameraID, emDSFrameSpeed *pemFrameSpeed); 
DS_API emDSCameraStatus CameraSetAntiFlick(INT iCameraID, BOOL bEnable); 
DS_API emDSCameraStatus CameraGetAntiFlick(INT iCameraID, BOOL *pbEnable); 
DS_API emDSCameraStatus CameraSetLightFrequency(INT iCameraID, emDSLightFrequency emFrequency); 
DS_API emDSCameraStatus CameraGetLightFrequency(INT iCameraID, emDSLightFrequency *pemFrequency); 
DS_API emDSCameraStatus CameraSetImageSizeSel(INT iCameraID, INT iSel, BOOL bCapture = FALSE); 
DS_API emDSCameraStatus CameraGetImageSizeSel(INT iCameraID, INT *piSel, BOOL bCapture = FALSE); 
DS_API  emDSCameraStatus CameraSetImageSize(INT iCameraID, 
                                           BOOL bReserve, 
                                            INT iHOff, 
                                            INT iVOff, 
                                            INT iWidth, 
                                            INT iHeight,  
                                           BOOL bCapture = FALSE); 
DS_API emDSCameraStatus CameraGetImageSize(INT iCameraID,  
                                          BOOL *pbROI, 
                                           INT *piHOff, 
                                           INT *piVOff, 
                                           INT *piWidth, 
                                           INT *piHeight, 
                                          BOOL bCapture = FALSE); 
DS_API emDSCameraStatus CameraSetTransPackLen(INT iCameraID, INT iPack); 
DS_API emDSCameraStatus CameraGetTransPackLen(INT iCameraID, INT *piPack); 
DS_API emDSCameraStatus CameraSetTimeStampUnit(INT iCameraID, INT iUnit); 
DS_API emDSCameraStatus CameraGetTimeStampUnit(INT iCameraID, INT *piUnit); 
DS_API emDSCameraStatus CameraSaveParameter(INT iCameraID, emDSParameterTeam emTeam); 
DS_API emDSCameraStatus CameraReadParameter(INT iCameraID, emDSParameterTeam emTeam); 
DS_API emDSCameraStatus CameraGetCurrentParameterTeam(INT iCameraID, emDSParameterTeam *pemTeam); 
DS_API emDSCameraStatus CameraLoadDefaultParameter(INT iCameraID); 
DS_API emDSCameraStatus CameraSaveParameterToIni(INT iCameraID); 
DS_API emDSCameraStatus CameraLoadParameterFromIni(INT iCameraID); 
DS_API emDSCameraStatus CameraBlackLevelOnce(INT iCameraID); 
DS_API emDSCameraStatus CameraSetBlackLevel(INT iCameraID, 
                                           BOOL bBlackLevel, 
                                            INT iLevelForR, 
                                            INT iLevelForG, 
                                            INT iLevelForB, 
                                            INT iMaxValue=4095); 
DS_API emDSCameraStatus CameraGetBlackLevel(INT iCameraID, 
                                           BOOL *pbBlackLevel, 
                                            INT *piLevelForR, 
                                            INT *piLevelForG, 
                                            INT *piLevelForB); 
DS_API emDSCameraStatus CameraSetMediaType(INT iCameraID, emDSDataType emMediaType); 
DS_API emDSCameraStatus CameraGetMediaType(INT iCameraID, emDSDataType *pemMediaType); 
DS_API emDSCameraStatus CameraSetMediaTypeSel(INT iCameraID, INT iSel); 
DS_API emDSCameraStatus CameraGetMediaTypeSel(INT iCameraID, INT *piSel); 
DS_API emDSCameraStatus CameraSetRgbMatrixSel(INT iCameraID, INT iSel); 
DS_API emDSCameraStatus CameraGetRgbMatrixSel(INT iCameraID, INT *piSel); 
DS_API emDSCameraStatus CameraGetColorMatrix(INT iCameraID, INT iSel, float fMatrix[3][3]); 
DS_API emDSCameraStatus CameraSaveColorMatrix(INT iCameraID, INT iSel, float fMatrix[3][3]); 
DS_API emDSCameraStatus CameraAddColorMatrixConfig(INT iCameraID, LPCSTR lpszGroupName, float fMatrix[3][3]); 
DS_API emDSCameraStatus CameraApplyColorMatrix(INT iCameraID, LPCSTR lpszGroupName, float fMatrix[3][3]); 
DS_API emDSCameraStatus CameraSetTriggerMode(INT iCameraID, INT iSnapMode); 
DS_API emDSCameraStatus CameraGetTriggerMode(INT iCameraID, INT *piSnapMode); 
DS_API emDSCameraStatus CameraTrigger(INT iCameraID); 
DS_API emDSCameraStatus CameraSetTriggerPulse(INT iCameraID,  
											  INT iPulseStyle, 
											 UINT uPulseWidth, 
											 UINT uDelay, 
											 UINT uFilterWidth); 
DS_API emDSCameraStatus CameraGetTriggerPulse(INT iCameraID,  
	                                          INT *piPulseStyle, 
											 UINT *puPulseWidth, 
											 UINT *puDelay, 
											 UINT *puFilterWidth); 
DS_API emDSCameraStatus CameraSetStrobePulse(INT iCameraID, INT iPulseStyle,UINT uPulseWidth,UINT uDelay); 
DS_API emDSCameraStatus CameraGetStrobePulse(INT iCameraID, INT *piPulseStyle,UINT *puPulseWidth,UINT *puDelay); 
DS_API emDSCameraStatus CameraSetExposureSelForTrig(INT iCameraID, INT iSel); 
DS_API emDSCameraStatus CameraGetExposureSelForTrig(INT iCameraID, INT *piSel); 
DS_API emDSCameraStatus CameraSetTriggerCount(INT iCameraID, BYTE byCount); 
DS_API emDSCameraStatus CameraSetResolutionModeSelForTrig(INT iCameraID, INT iSel); 
DS_API emDSCameraStatus CameraGetResolutionModeSelForTrig(INT iCameraID, INT *piSel); 
DS_API emDSCameraStatus CameraSetImageSizeSelForTrig(INT iCameraID, INT iSel); 
DS_API emDSCameraStatus CameraGetImageSizeSelForTrig(INT iCameraID, INT *piSel); 
DS_API emDSCameraStatus CameraSetExpTimeForTrig(INT iCameraID, UINT64 uExpTime); 
DS_API emDSCameraStatus CameraGetExpTimeForTrig(INT iCameraID,  
                                             UINT64 *puExpTime, 
                                             UINT64 *puExpTimeMax, 
                                             UINT64 *puExpTimeMin); 
DS_API emDSCameraStatus CameraSetAnalogGainForTrig(INT iCameraID, float fGain); 
DS_API emDSCameraStatus CameraGetAnalogGainForTrig(INT iCameraID, float *pfGain); 
DS_API emDSCameraStatus CameraSetImageSizeForTrig(INT iCameraID,  
                                                 BOOL bROI, 
                                                  INT iHOff, 
                                                  INT iVOff, 
                                                  INT iWidth, 
                                                  INT iHeight); 
DS_API emDSCameraStatus CameraGetImageSizeForTrig(INT iCameraID,  
                                                 BOOL *pbROI, 
                                                  INT *piHOff, 
                                                  INT *piVOff, 
                                                  INT *piWidth, 
                                                  INT *piHeight); 
DS_API emDSCameraStatus CameraWriteSN(INT iCameraID, INT iLevel, BYTE *pbySN, INT iSize, INT *piWritten); 
DS_API emDSCameraStatus CameraReadSN(INT iCameraID, INT iLevel, BYTE *pbySN, INT iSize, INT *piReaded); 
DS_API emDSCameraStatus CameraGetPropertyPageInfo(INT iCameraID, tDSPropertyPageInfo *psPageInfo, BYTE byType); 
DS_API emDSCameraStatus CameraShowSettingPage(INT iCameraID, HWND hwndDisplay, BYTE byType); 
DS_API emDSCameraStatus CameraControl(INT iCameraID,  
                                    DWORD dwCtrlCode, 
                                    DWORD dwParam, 
                                   LPVOID lpData); 
DS_API emDSCameraStatus CameraGetSDKVersion(DWORD adwVersion[4]); 
#endif
