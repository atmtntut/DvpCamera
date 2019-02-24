/*------------------------------------------------------------------------*\ 
| ����:  ������������õ������ݽṹ 
| ��Ȩ:  ��Ȩ����                                                      
\*------------------------------------------------------------------------*/ 
 
#ifndef _DEV_PARAM_DEF 
#define _DEV_PARAM_DEF 
 
#define NAME_LEN_MAX    64 
#define DESCR_LEN_MAX   32 
 
 
/*------------------------------------------------------------------------*\ 
|                             ����ͷӲ����Ϣ 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    UINT  uVendorID;                         // ���̱�� 
    char  acVendorName[NAME_LEN_MAX];        // �������� 
    char  acProductSeries[NAME_LEN_MAX];     // ��Ʒϵ�� 
    char  acProductName[NAME_LEN_MAX];       // ��Ʒ���� 
    char  acFriendlyName[NAME_LEN_MAX];      // ��Ʒ�ǳƣ���������ͬϵ�еĶ����Ʒ 
    char  acDevFileName[NAME_LEN_MAX];       // �߼������ļ����� 
    char  acFileName[NAME_LEN_MAX];          // �ں������߼��豸�� 
    char  acFirmwareVersion[NAME_LEN_MAX];   // ��Ʒ�̼��汾 
    char  acSensorType[NAME_LEN_MAX];        // ͼ�񴫸������� 
    char  acPortType[NAME_LEN_MAX];          // �ӿ����� 
} tDSCameraDevInfo; 
 
 
/*------------------------------------------------------------------------*\ 
|                             ͼ�񴫸�����Ϣ 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    UINT  uSensorType;    // ���������� 
    UINT  uSensorCount;   // ���������� 
    BOOL  bMono;          // ������ɫ�����ͣ��ڰ׻��ɫ�� 
    UINT  uPixForm;       // �������������з�ʽ����RGRG��GRGR�� 
    INT   iFieldCount;    // ������ɨ�跽ʽ��1Ϊ����ɨ�裬����1��Ϊ��Ӧ�����ĸ���ɨ�� 
} tDSSensorInfo; 
 
 
/*------------------------------------------------------------------------*\ 
|                             ֡������Ϣ 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    UINT    uiMediaType;       // ͼ���������ͣ��ο���DVP_Define.h��ͷ�ļ���ö�����͡�emDSDataType����ֵ 
    UINT    uBytes;            // ͼ�������ֽ��� 
    UINT    uiHeight;          // ͼ��߶� 
    UINT    uiWidth;           // ͼ����� 
    UINT    uHOff;             // ͼ��ˮƽƫ���� 
    UINT    uVOff;             // ͼ��ֱƫ���� 
    BOOL    bHFlip;            // �����Ƿ�ˮƽ��ת 
    BOOL    bVFlip;            // �����Ƿ�ֱ��ת 
    BOOL    bTriggered;        // �����Ƿ�Ϊ����֡ 
    BOOL    bTimeStampValid;   // ����ʱ�����Ч 
    BOOL    bExpTimeValid;     // �����ع�ʱ����Ч 
	UINT	uFrameID;		   // ֡ID�ţ�һ������£�ÿ֡��1 
    UINT64  uiTimeStamp;       // ʱ�������λ���ɾ����豸ȷ�� 
    UINT64  uiExpTime;         // �ع�ʱ�䣬��λ���ɾ����豸ȷ�� 
} tDSFrameInfo; 
 
 
/*------------------------------------------------------------------------*\ 
|                            ROI�����ṹ 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    INT  iWidth;     // ROI���� 
    INT  iHeight;    // ROI�߶� 
    INT  iHOffset;   // ROIˮƽƫ���� 
    INT  iVOffset;   // ROI��ֱƫ���� 
} tDSROISize; 
 
 
/*------------------------------------------------------------------------*\ 
|                            ͼ��ߴ�ṹ 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    INT   iIndex;                         // ͼ��ߴ������ţ�ֵ��0��ʼ 
    char  acDescription[DESCR_LEN_MAX];   // ͼ��ߴ��������� 
    BOOL  bIsBIN;                         // �Ƿ�ΪBINģʽ��ͼ��ߴ� 
    BOOL  bIsSkip;                        // �Ƿ�ΪSKIPģʽ��ͼ��ߴ� 
    BOOL  bIsZoom;                        // �Ƿ�Ϊ���ŵ�ͼ��ߴ� 
    INT	  iResolutionMode;                // �ֱ���ģʽ��ֵΪtDSResolutionMode��iIndex��Ա 
    INT   iWidth;                         // ͼ����� 
    INT   iHeight;                        // ͼ��߶� 
    INT	  iHOffset;                       // ͼ��ֱƫ���� 
    INT   iVOffset;                       // ͼ��ˮƽƫ���� 
} tDSImageSize; 
 
 
/*------------------------------------------------------------------------*\ 
|                            ��Ƶ�ߴ緶Χ 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    INT   iHeightMax;       // ͼ��߶����ֵ 
    INT   iHeightMin;       // ͼ��߶���Сֵ 
    INT   iHeightDefault;   // ͼ��߶�Ĭ��ֵ 
    INT   iWidthMax;        // ͼ��������ֵ 
    INT   iWidthMin;        // ͼ�������Сֵ 
    INT   iWidthDefault;    // ͼ�����Ĭ��ֵ 
    BOOL  bRoi;             // �Ƿ�֧��ROIģʽ��TRUE:֧�֣�FALSE:��֧�� 
} tDSImageSizeRange; 
 
 
/*------------------------------------------------------------------------*\ 
|                               ֡����Ϣ 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    INT   iIndex;                         // ֡�������ţ�ֵ��0��ʼ 
    char  acDescription[DESCR_LEN_MAX];   // ֡���������� 
} tDSFrameSpeed; 
 
 
/*------------------------------------------------------------------------*\ 
|                             �ع�ʱ����Ϣ 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    INT     iIndex;                         // �ع�ʱ�������ţ�ֵ��0��ʼ 
    char    acDescription[DESCR_LEN_MAX];   // �ع�ʱ���������� 
    UINT64  uiTargetMin;                    // ��С�Զ��ع�Ŀ��ֵ 
    UINT64  uiTargetMax;                    // ����Զ��ع�Ŀ��ֵ 
    UINT64  uiTargetDefault;                // Ĭ���Զ��ع�Ŀ��ֵ 
    float   fAnalogGainMin;                 // ��С�ع����� 
    float   fAnalogGainMax;                 // ����ع����� 
    float   fAnalogGainDefault;             // Ĭ������ 
    float   fAnalogGainStep;                // ������ڵĲ���ֵ(��С��λ)  
    UINT64  uiExposureTimeMin;              // ��С�ع�ʱ�� 
    UINT64  uiExposureTimeMax;              // ����ع�ʱ�� 
    UINT64  uiExposureTimeDefault;          // Ĭ���ع�ʱ�� 
    UINT64  uiExposureTimeStep;             // �ع�ʱ����ڵĲ���ֵ����С��λ�� 
} tDSExposure; 
 
 
/*------------------------------------------------------------------------*\ 
|                                �ع���� 
\*------------------------------------------------------------------------*/ 
typedef struct  
{ 
    BOOL    bAutoEnable;         // �Ƿ��Զ��ع� 
    UINT64  iAutoExposureTarget;   // �Զ��ع�Ŀ��ֵ 
    float   fAnalogGain;         // �ع����� 
    UINT64  iExposureTime;         // �ع�ʱ�� 
} tDSExposureParam; 
 
 
/*------------------------------------------------------------------------*\ 
|                               ����ģʽ��Ϣ 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    INT   iIndex;                         // ����ģʽ�����ţ�ֵ��0��ʼ 
    char  acDescription[DESCR_LEN_MAX];   // ����ģʽ���������� 
} tDSTrigger; 
 
 
/*------------------------------------------------------------------------*\ 
|                               ֡����ͳ����Ϣ 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    INT  iCap;     // �������ȡ��֡�� 
    INT  iTotal;   // �����������֡�����������ȡ��֡�� �� �����ʧ��֡�� ֮�ͣ� 
    INT  iLost;    // �����ʧ��֡�� 
} tDSFrameCount; 
 
 
/*------------------------------------------------------------------------*\ 
|                               ͼ���������� 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    INT   iIndex;                         // ͼ���������������ţ�ֵ��0��ʼ 
    char  acDescription[DESCR_LEN_MAX];   // ͼ���������͵��������� 
    INT   iMediaType;                     // ͼ���������ͣ��ο���DVP_Define.h��ͷ�ļ���ö�����͡�emDSDataType����ֵ 
} tDSMediaType; 
 
 
/*------------------------------------------------------------------------*\ 
|                                �ֱ���ģʽ 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    INT   iIndex;                         // �ֱ���ģʽ�����ţ�ֵ��0��ʼ 
    char  acDescription[DESCR_LEN_MAX];   // �ֱ���ģʽ���������� 
    BOOL  bBin;                           // �Ƿ�ΪBINģʽ 
    BOOL  bSkip;                          // �Ƿ�ΪSKIPģʽ 
    BOOL  bZoom;                          // �Ƿ�Ϊ����ģʽ 
    INT   iWidthMax;                      // ��ģʽ��ͼ��������ֵ 
    INT   iHeightMax;                     // ��ģʽ��ͼ��߶����ֵ 
    INT   iHSampling;                     // ˮƽ����ģʽ����ֵ�����ս����ɾ����豸���� 
    INT   iVSampling;                     // ��ֱ����ģʽ����ֵ�����ս����ɾ����豸���� 
    INT   iReadOut;                       // ��ȡģʽ����ֵ�����ս����ɾ����豸���� 
} tDSResolutionMode; 
 
 
/*------------------------------------------------------------------------*\ 
|                              ͼ��٤����ֵ��Χ 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    INT  iMin;       // ͼ��٤����Сֵ 
    INT  iMax;       // ͼ��٤�����ֵ 
    INT  iDefault;   // ͼ��٤��Ĭ��ֵ 
} tDSGammaRange; 
 
 
/*------------------------------------------------------------------------*\ 
|                             ͼ��Աȶ���ֵ��Χ 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    INT  iMin;       // ͼ��Աȶ���Сֵ 
    INT  iMax;       // ͼ��Աȶ����ֵ 
    INT  iDefault;   // ͼ��Աȶ�Ĭ��ֵ 
} tDSContrastRange; 
 
 
/*------------------------------------------------------------------------*\ 
|                              RGBͨ�����淶Χ 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    float  fRGainMin;       // ��ͨ��������Сֵ 
    float  fRGainMax;       // ��ͨ���������ֵ 
    float  fRGainDefault;   // ��ͨ������Ĭ��ֵ 
    float  fGGainMin;       // ��ͨ��������Сֵ 
    float  fGGainMax;       // ��ͨ���������ֵ 
    float  fGGainDefault;   // ��ͨ������Ĭ��ֵ 
    float  fBGainMin;       // ��ͨ��������Сֵ 
    float  fBGainMax;       // ��ͨ���������ֵ 
    float  fBGainDefault;   // ��ͨ������Ĭ��ֵ 
} tDSRgbGainRange; 
 
 
/*------------------------------------------------------------------------*\ 
|                            ɫ�ʱ��Ͷ���ֵ��Χ 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    INT  iMin;       // ɫ�ʱ��Ͷ���Сֵ 
    INT  iMax;       // ɫ�ʱ��Ͷ����ֵ 
    INT  iDefault;   // ɫ�ʱ��Ͷ�Ĭ��ֵ 
} tDSSaturationRange; 
 
 
/*------------------------------------------------------------------------*\ 
|                             ͼ�������ֵ��Χ 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    INT  iMin;       // ͼ�������Сֵ 
    INT  iMax;       // ͼ��������ֵ 
    INT  iDefault;   // ͼ�����Ĭ��ֵ 
} tDSSharpnessRange; 
 
 
/*------------------------------------------------------------------------*\ 
|                            ͼ����Ŀ��ֵ��Χ 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    INT  iMin;       // ͼ������Сֵ 
    INT  iMax;       // ͼ�������ֵ 
    INT  iDefault;   // ͼ����Ĭ��ֵ 
} tDSNoiseReductionRange; 
 
 
/*------------------------------------------------------------------------*\ 
|                      �������ݷְ����ȣ�ǧ��������� 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    INT   iIndex;                         // ���ݷְ����������ţ�ֵ��0��ʼ 
    char  acDescription[DESCR_LEN_MAX];   // ���ݷְ����ȵ��������� 
} tDSPackLength; 
 
 
/*------------------------------------------------------------------------*\ 
|                         ʱ�����Ϣ��ǧ��������� 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    INT   iIndex;                         // ʱ��������ţ�ֵ��0��ʼ 
    char  acDescription[DESCR_LEN_MAX];   // ʱ������������� 
} tDSTimeStamp; 
 
 
/*------------------------------------------------------------------------*\ 
|                             ��ɫ������������ 
\*------------------------------------------------------------------------*/ 
typedef struct   
{ 
    INT   iIndex;                         // ��ɫ���������ţ�ֵ��0��ʼ 
    char  acDescription[DESCR_LEN_MAX];   // ��ɫ������������� 
}tDSRgbMatrixType; 
 
 
/*------------------------------------------------------------------------*\ 
|                             �߼����ý�����Ϣ 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    BOOL  bPage;                          // �����ڶ�Ӧ�����ý��棬ֵΪTRUE������ΪFALSE 
    char  acDescription[DESCR_LEN_MAX];   // �߼����ý������������ 
} tDSPropertyPageInfo; 
 
 
/*------------------------------------------------------------------------*\ 
|                  ����ģʽ������Ϊ���ֿ��ܵ�ģʽ����ѡһ 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    INT   iIndex; 
    char  acModeName[DESCR_LEN_MAX]; 
} tDSModeDesc; 
 
 
/*------------------------------------------------------------------------*\ 
|                ���忪��������Ϊ���ֿ��ܵ�ѡ�������ر� 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    INT   iIndex; 
    char  acSwitchName[DESCR_LEN_MAX]; 
    BOOL  bDefault; 
} tDSSwitchDesc; 
 
 
/*------------------------------------------------------------------------*\ 
|                  ����༭ֵ���������޸���ֵ��һЩ���� 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    INT   iIndex; 
    char  acValueName[DESCR_LEN_MAX]; 
    INT   iDefault; 
} tDSValueDesc; 
 
 
/*------------------------------------------------------------------------*\ 
|                       ��������ĸ�����Ϣ�Ͳ������ԡ� 
\*------------------------------------------------------------------------*/ 
typedef struct 
{ 
    tDSSensorInfo  sSensorInfo;   // ͼ�񴫸�����Ϣ 
 
    /* ��������޶���Χ��Ĭ��ֵ */ 
    tDSImageSizeRange       sImageSizeRange;        // ͼ��ߴ���޶���Χ��Ĭ��ֵ 
    tDSRgbGainRange         sRgbGainRange;          // RGB������޶���Χ��Ĭ��ֵ 
    tDSSaturationRange      sSaturationRange;       // ɫ�ʱ��Ͷȵ��޶���Χ��Ĭ��ֵ 
    tDSGammaRange           sGammaRange;            // ͼ��٤����޶���Χ��Ĭ��ֵ 
    tDSContrastRange        sContrastRange;         // ͼ��Աȶȵ��޶���Χ��Ĭ��ֵ 
    tDSSharpnessRange       sSharpnessRange;        // ͼ����ȵ��޶���Χ��Ĭ��ֵ 
    tDSNoiseReductionRange  sNoiseReductionRange;   // ͼ���������޶���Χ��Ĭ��ֵ 
 
    /* ��ѡ��ѡ���Ĭ��ѡ�� */ 
    tDSExposure  *pExposureDesc;   // �ع⹦�� 
    INT        iExposureDesc;      // �ع⹦�ܵ���Ŀ 
    INT        iExposureDefault;   // �ع⹦��Ĭ��������ţ� 
 
    tDSTrigger  *pTriggerDesc;     // �������� 
    INT         iTriggerDesc;      // �������ܵ���Ŀ 
    INT         iTriggerDefault;   // ��������Ĭ��������ţ� 
 
    tDSImageSize  *pImageSizeDesc;     // ͼ��ߴ� 
    INT           iImageSizeDesc;      // ͼ��ߴ����Ŀ 
    INT           iImageSizeDefault;   // ͼ��ߴ��Ĭ��������ţ� 
 
    tDSMediaType  *pMediaTypeDesc;     // ��������ͼ���������� 
    INT           iMediaTypdeDesc;     // ͼ���������͵���Ŀ 
    INT           iMediaTypeDefault;   // ͼ���������͵�Ĭ��������ţ� 
 
    tDSResolutionMode  *pResolutionModeDesc;     // �ֱ���ģʽ 
    INT                iResolutionModeDesc;      // �ֱ���ģʽ����Ŀ 
    INT                iResolutionModeDefault;   // �ֱ���ģʽ��Ĭ��������ţ� 
 
    tDSFrameSpeed  *pFrameSpeedDesc;     // ֡�� 
    INT            iFrameSpeedDesc;      // ֡�ٵ���Ŀ 
    INT            iFrameSpeedDefault;   // ֡�ٵ�Ĭ��������ţ� 
 
    tDSTimeStamp  *pTimeStampDesc;     // ʱ�����ǧ��������� 
    INT           iTimeStampDesc;      // ʱ�������Ŀ 
    INT           iTimeStampDefault;   // ʱ�����Ĭ��������ţ� 
 
    tDSPackLength  *pPackLenDesc;     // ���ݰ����� 
    INT            iPackLenDesc;      // ���ݰ����ȵ���Ŀ 
    INT            iPackLenDefault;   // ���ݰ����ȵ�Ĭ��������ţ� 
 
    tDSRgbMatrixType  *pRgbMatrixDesc;     // ��ɫ������ 
    INT               iRgbMaxtrixDesc;     // ��ɫ�����ܵ���Ŀ 
    INT               iRgbMatrixDefault;   // ��ɫ�����ܵ�Ĭ��������ţ� 
 
    BOOL  bRomForSave;   // �豸�Ƿ�֧�ֲ����浵 
 
    /* ģʽѡ���Ĭ��ģʽ */ 
    tDSModeDesc  *pModeDesc;     // ģʽ 
    INT          iModeDesc;      // ģʽ����Ŀ 
    INT          iModeDefault;   // ģʽ��Ĭ��������ţ� 
 
    /* ����ѡ��ͼ���Ĭ��ֵ */ 
    tDSSwitchDesc  *pSwitchDesc;   // ����ѡ�� 
    INT            iSwitchDesc;    // ����ѡ�����Ŀ 
 
    /* ��ֵ���� */ 
    tDSValueDesc  *pValueDesc;   // ��ֵ���� 
    INT           iValueDesc;    // ��ֵ��������Ŀ 
} tDSCameraCapability; 
 
#endif 
