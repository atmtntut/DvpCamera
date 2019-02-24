/*---------------------------------------------------------------------------------*\ 
| ����:  ����������������ݳ��������ݳ������壬�������󷵻��롢״̬��ʶ���������ͣ� 
| ��Ȩ:  ��Ȩ���� 
\*---------------------------------------------------------------------------------*/ 
 
#ifndef _DSDEFINE_H_ 
#define _DSDEFINE_H_ 
#include <Windows.h> 
#include "DVP_ParamDef.h" 
 
 
 
/*---------------------------------------------------------------------------------*\ 
|                                  ���״̬���� 
\*---------------------------------------------------------------------------------*/ 
typedef enum 
{ 
    RUNMODE_PLAY   = 0, 
    RUNMODE_PAUSE  = 1, 
    RUNMODE_STOP   = 2, 
}emDSRunMode; 
 
 
/*---------------------------------------------------------------------------------*\ 
|                                    �����붨�� 
\*---------------------------------------------------------------------------------*/ 
typedef enum 
{ 
    STATUS_OK                     = 1,       // �����ɹ� 
    STATUS_IN_PROCESS             = 2,       // ����ͨ�� 
    STATUS_INTERNAL_ERROR         = -1,      // �ڲ����� 
    STATUS_NOT_SUPPORTED          = -2,      // ����ͷ��֧�ָù��� 
    STATUS_NOT_INITIALIZED        = -3,      // ��ʼ��δ��� 
    STATUS_PARAMETER_INVALID      = -4,      // ������Ч 
    STATUS_TIME_OUT               = -1000,   // ͨ�ų�ʱ���� 
    STATUS_IO_ERROR               = -1001,   // Ӳ��IO���� 
    STATUS_NO_DEVICE_FOUND        = -1100,   // û�з������ 
    STATUS_NO_LOGIC_DEVICE_FOUND  = -1101,   // δ�ҵ��߼��豸 
    STATUS_DEVICE_IS_OPENED       = -1102,   // ����ͷ�Ѿ��� 
    STATUS_MEMORY_NOT_ENOUGH      = -1200,   // û���㹻ϵͳ�ڴ� 
    STATUS_FILE_CREATE_FAILED     = -1300,   // �����ļ�ʧ�� 
    STATUS_FILE_INVALID           = -1301,   // �ļ���ʽ��Ч 
    STATUS_WRITE_PROTECTED        = -1400,   // д����������д 
    STATUS_GRAB_FRAME_ERROR       = -1600,   // ���ݲ�׽ʧ�� 
    STATUS_LOST_DATA              = -1601,   // ֡���ݲ��ֶ�ʧ�������� 
    STATUS_EOF_ERROR              = -1602    // δ���յ�֡������ 
}emDSCameraStatus; 
 
 
/*---------------------------------------------------------------------------------*\ 
|                                ͼ�������� 
\*---------------------------------------------------------------------------------*/ 
typedef enum 
{ 
    MIRROR_DIRECTION_HORIZONTAL  = 0, 
    MIRROR_DIRECTION_VERTICAL    = 1, 
}emDSMirrorDirection; 
 
 
/*---------------------------------------------------------------------------------*\ 
|                                   ���֡�ٶ��� 
\*---------------------------------------------------------------------------------*/ 
typedef enum 
{ 
    FRAME_SPEED_NORMAL, 
    FRAME_SPEED_HIGH, 
    FRAME_SPEED_SUPER, 
}emDSFrameSpeed; 
 
 
/*---------------------------------------------------------------------------------*\ 
|                                   ͼ���ļ��ĸ�ʽ 
\*---------------------------------------------------------------------------------*/ 
typedef enum 
{ 
    FILE_JPG  = 1, 
    FILE_BMP  = 2, 
    FILE_RAW  = 4, 
    FILE_PNG  = 8 
}emDSFileType; 
 
 
/*---------------------------------------------------------------------------------*\ 
|                                   ���ͼ���������� 
\*---------------------------------------------------------------------------------*/ 
typedef enum 
{ 
    // MONO ���� 
    DATA_TYPE_MONO1P         = 0, 
    DATA_TYPE_MONO2P         = 1, 
    DATA_TYPE_MONO4P         = 2, 
    DATA_TYPE_MONO8          = 3, 
    DATA_TYPE_MONO8S         = 4, 
    DATA_TYPE_MONO10         = 5, 
    DATA_TYPE_MONO10_PACKED  = 6, 
    DATA_TYPE_MONO12         = 7, 
    DATA_TYPE_MONO12_PACKED  = 8, 
    DATA_TYPE_MONO14         = 9, 
    DATA_TYPE_MONO16         = 10, 
 
    // BAYER �������� 
    DATA_TYPE_BAYGR8          = 11, 
    DATA_TYPE_BAYRG8          = 12, 
    DATA_TYPE_BAYGB8          = 13, 
    DATA_TYPE_BAYBG8          = 14, 
    DATA_TYPE_BAYGR10         = 15, 
    DATA_TYPE_BAYRG10         = 16, 
    DATA_TYPE_BAYGB10         = 17, 
    DATA_TYPE_BAYBG10         = 18, 
    DATA_TYPE_BAYGR12         = 19, 
    DATA_TYPE_BAYRG12         = 20, 
    DATA_TYPE_BAYGB12         = 21, 
    DATA_TYPE_BAYBG12         = 22, 
    DATA_TYPE_BAYGR10_PACKED  = 23, 
    DATA_TYPE_BAYRG10_PACKED  = 24, 
    DATA_TYPE_BAYGB10_PACKED  = 25, 
    DATA_TYPE_BAYBG10_PACKED  = 27, 
    DATA_TYPE_BAYGR12_PACKED  = 28, 
    DATA_TYPE_BAYRG12_PACKED  = 29, 
    DATA_TYPE_BAYGB12_PACKED  = 30, 
    DATA_TYPE_BAYBG12_PACKED  = 31, 
    DATA_TYPE_BAYGR16         = 32, 
    DATA_TYPE_BAYRG16         = 33, 
    DATA_TYPE_BAYGB16         = 34, 
    DATA_TYPE_BAYBG16         = 35, 
 
    // RGB �������� 
    DATA_TYPE_RGB8            = 36, 
    DATA_TYPE_BGR8            = 37, 
    DATA_TYPE_RGBA8           = 38, 
    DATA_TYPE_BGRA8           = 39, 
    DATA_TYPE_RGB10           = 40, 
    DATA_TYPE_BGR10           = 41, 
    DATA_TYPE_RGB12           = 42, 
    DATA_TYPE_BGR12           = 43, 
    DATA_TYPE_RGB16           = 44, 
    DATA_TYPE_RGB10V1_PACKED  = 45, 
    DATA_TYPE_RGB10P32        = 46, 
    DATA_TYPE_RGB12V1_PACKED  = 47, 
    DATA_TYPE_RGB565P         = 48, 
    DATA_TYPE_BGR565P         = 49, 
 
    // YUV YCbCr 
    DATA_TYPE_YUV411_8_UYYVYY          = 50, 
    DATA_TYPE_YUV422_8_UYVY            = 51, 
    DATA_TYPE_YUV422_8                 = 52, 
    DATA_TYPE_YUV8_UYV                 = 53, 
    DATA_TYPE_YCBCR8_CBYCR             = 54, 
    DATA_TYPE_YCBCR422_8               = 55, 
    DATA_TYPE_YCBCR422_8_CBYCRY        = 56, 
    DATA_TYPE_YCBCR411_8_CBYYCRYY      = 57, 
    DATA_TYPE_YCBCR601_8_CBYCR         = 58, 
    DATA_TYPE_YCBCR601_422_8           = 59, 
    DATA_TYPE_YCBCR601_422_8_CBYCRY    = 60, 
    DATA_TYPE_YCBCR601_411_8_CBYYCRYY  = 61, 
    DATA_TYPE_YCBCR709_8_CBYCR         = 62, 
    DATA_TYPE_YCBCR709_422_8           = 63, 
    DATA_TYPE_YCBCR709_422_8_CBYCRY    = 64, 
    DATA_TYPE_YCBCR709_411_8_CBYYCRYY  = 65, 
 
    // planar 
    DATA_TYPE_RGB8_PLANAR   = 80, 
    DATA_TYPE_RGB10_PLANAR  = 81, 
    DATA_TYPE_RGB12_PLANAR  = 82, 
    DATA_TYPE_RGB16_PLANAR  = 83 
}emDSDataType; 
 
 
/*---------------------------------------------------------------------------------*\ 
|                                   �ƹ�Ƶ�� 
\*---------------------------------------------------------------------------------*/ 
typedef enum 
{ 
    LIGHT_FREQUENCY_50HZ  = 0, 
    LIGHT_FREQUENCY_60HZ  = 1, 
}emDSLightFrequency; 
 
 
/*---------------------------------------------------------------------------------*\ 
|                               ͼ�񴫸�������ģʽ 
\*---------------------------------------------------------------------------------*/ 
typedef enum 
{ 
    SUBSAMPLE_MODE_BIN   = 0, 
    SUBSAMPLE_MODE_SKIP  = 1, 
}emDSSubsampleMode; 
 
 
/*---------------------------------------------------------------------------------*\ 
|                               ����������ñ������ 
\*---------------------------------------------------------------------------------*/ 
typedef enum 
{ 
    PARAMETER_TEAM_A        = 0, 
    PARAMETER_TEAM_B        = 1, 
    PARAMETER_TEAM_C        = 2, 
    PARAMETER_TEAM_D        = 3, 
    PARAMETER_TEAM_LAST     = 254, 
    PARAMETER_TEAM_DEFAULT  = 255 
}emDSParameterTeam; 
 
/*---------------------------------------------------------------------------------*\ 
|                               ���Ӳ��������ʽ 
\*---------------------------------------------------------------------------------*/ 
typedef enum 
{ 
	PULSE_LEVEL_HIGH = 0, 
	PULSE_LEVEL_LOW = 1, 
	PULSE_EDGE_RISE = 2, 
	PULSE_EDGE_DOWN = 3, 
}emDSPulseStyle; 
 
/*---------------------------------------------------------------------------------*\ 
|                                 ������ݻص����� 
\*---------------------------------------------------------------------------------*/ 
typedef int (CALLBACK* DS_SNAP_PROC)(INT iCamID, BYTE *pImageBuffer, tDSFrameInfo *psFrInfo); 
 
#endif 
