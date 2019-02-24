// cameraDlg.cpp : implementation file   
//   
   
#include "stdafx.h"   
#include "camera.h"   
#include "cameraDlg.h"   
#include <shlwapi.h>   
// #include "..\DVP_CamAPI\DVP_CamAPI.h"   
// #include "..\\DVP_SDK\\DVP_Define.h"   
// #include "..\\DVP_SDK\\DVP_Paramdef.h"   
   
#ifdef _DEBUG   
#define new DEBUG_NEW   
#undef THIS_FILE   
static char THIS_FILE[] = __FILE__;   
#endif   
   
BOOL m_bRecode = FALSE;   
CString m_sPicPath, m_sVideoPath;   
BYTE m_FileIndex;   
   
long filesize;   
int iFrameCount = 0;   
   
BITMAPINFO     m_InInfo,m_OutInfo; //λͼ��ʽ   
   
INT CALLBACK SnapCallBack(INT iCamID,   
                          BYTE *pImageBuffer,   
                          tDSFrameInfo *pFrInfo)   
{   
    //TRACE("%ld\n",pFrInfo->uiTimeStamp);   
    BYTE* pBmp24 = CameraISP(iCamID,pImageBuffer, pFrInfo);   
    CameraDisplayRGB24(iCamID,pBmp24, pFrInfo);    
    if (m_bRecode)   
    {          
        CameraRecordFrame(iCamID, pBmp24, pFrInfo);        
    }   
       
    return 0;   
}   
   
// CAboutDlg dialog used for App About   
class CAboutDlg : public CDialog   
{   
public:   
    CAboutDlg();   
    enum { IDD = IDD_ABOUTBOX };   
    protected:   
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support   
protected:   
    DECLARE_MESSAGE_MAP()   
};   
   
CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)   
{   
}   
   
void CAboutDlg::DoDataExchange(CDataExchange* pDX)   
{   
    CDialog::DoDataExchange(pDX);   
}   
   
BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)   
END_MESSAGE_MAP()   
   
// CCameraDlg dialog   
CCameraDlg::CCameraDlg(CWnd* pParent /*=NULL*/)   
    : CDialog(CCameraDlg::IDD, pParent)   
{   
    m_eRunmode = RUNMODE_STOP;   
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);   
}   
   
void CCameraDlg::DoDataExchange(CDataExchange* pDX)   
{   
    CDialog::DoDataExchange(pDX);   
    DDX_Control(pDX, IDC_STATIC1, m_picturebox);   
    DDX_Control(pDX, IIDC_ResolutionList, m_resolutionlist);   
    DDX_Control(pDX, IDC_CameraList, m_cameralist);   
}   
   
BEGIN_MESSAGE_MAP(CCameraDlg, CDialog)   
    ON_WM_SYSCOMMAND()   
    ON_WM_PAINT()   
    ON_WM_QUERYDRAGICON()   
    ON_BN_CLICKED(IDC_BnClickedProbe, OnBnClickedProbe)   
    ON_BN_CLICKED(IDC_BnClickedPlay, OnBnClickedPlay)   
    ON_BN_CLICKED(IDC_BnClickedStop, OnBnClickedStop)   
    ON_BN_CLICKED(IDC_BnClickedSetup, OnBnClickedSetup)   
    ON_BN_CLICKED(IDC_BnClickedSnap, OnBnClickedSnap)   
    ON_BN_CLICKED(IDC_BnClickedRecord, OnBnClickedRecord)   
    ON_CBN_EDITCHANGE(IIDC_ResolutionList, OnEditchangeResolutionList)   
    ON_CBN_EDITCHANGE(IDC_CameraList, OnEditchangeCameraList)   
END_MESSAGE_MAP()   
   
// CCameraDlg message handlers   
BOOL CCameraDlg::OnInitDialog()   
{   
    CDialog::OnInitDialog();   
    ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);   
    ASSERT(IDM_ABOUTBOX < 0xF000);   
    CMenu* pSysMenu = GetSystemMenu(FALSE);   
    if (pSysMenu != NULL)   
    {   
        CString strAboutMenu;   
        strAboutMenu.LoadString(IDS_ABOUTBOX);   
        if (!strAboutMenu.IsEmpty())   
        {   
            pSysMenu->AppendMenu(MF_SEPARATOR);   
            pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);   
        }   
    }   
   
    // Set the icon for this dialog.  The framework does this automatically   
    //  when the application's main window is not a dialog   
    SetIcon(m_hIcon, TRUE);         // Set big icon   
    SetIcon(m_hIcon, FALSE);        // Set small icon   
    // TODO: Add extra initialization here   
    return TRUE;  // return TRUE  unless you set the focus to a control   
}   
   
void CCameraDlg::OnSysCommand(UINT nID, LPARAM lParam)   
{   
    if ((nID & 0xFFF0) == IDM_ABOUTBOX)   
    {   
        CAboutDlg dlgAbout;   
        dlgAbout.DoModal();   
    }   
    else   
    {   
        CDialog::OnSysCommand(nID, lParam);   
    }   
}   
   
// If you add a minimize button to your dialog, you will need the code below   
//  to draw the icon.  For MFC applications using the document/view model,   
//  this is automatically done for you by the framework.   
   
void CCameraDlg::OnPaint()    
{   
    if (IsIconic())   
    {   
        CPaintDC dc(this); // device context for painting   
        SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);   
        // Center icon in client rectangle   
        int cxIcon = GetSystemMetrics(SM_CXICON);   
        int cyIcon = GetSystemMetrics(SM_CYICON);   
        CRect rect;   
        GetClientRect(&rect);   
        int x = (rect.Width() - cxIcon + 1) / 2;   
        int y = (rect.Height() - cyIcon + 1) / 2;   
   
        // Draw the icon   
        dc.DrawIcon(x, y, m_hIcon);   
    }   
    else   
    {   
        CDialog::OnPaint();   
    }   
}   
   
// The system calls this to obtain the cursor to display while the user drags   
//  the minimized window.   
HCURSOR CCameraDlg::OnQueryDragIcon()   
{   
    return (HCURSOR) m_hIcon;   
}   
   
void CCameraDlg::OnBnClickedProbe()    
{   
    // TODO: Add your control notification handler code here   
    tDSCameraDevInfo DSCameraList[5];   
    int m_iNum = 0;   
    CameraStop(m_iCameraID);   
    CameraUnInit(m_iCameraID);   
    m_eRunmode = RUNMODE_STOP;   
    CameraGetDevList(DSCameraList, &m_iNum);   
    if (m_iNum < 1)   
    {      
        GetDlgItem(IDC_BnClickedStop)->EnableWindow(FALSE);   
        GetDlgItem(IDC_BnClickedPlay)->EnableWindow(FALSE);   
        GetDlgItem(IDC_BnClickedSetup)->EnableWindow(FALSE);   
        GetDlgItem(IDC_BnClickedSnap)->EnableWindow(FALSE);   
        GetDlgItem(IDC_BnClickedRecord)->EnableWindow(FALSE);   
        AfxMessageBox("δ���������");           
        return;   
    }    
    else   
    {   
        m_cameralist.ResetContent();   
           
        for (int i=0; i<m_iNum; i++)   
        {   
            m_cameralist.InsertString(i, DSCameraList[i].acFriendlyName);   
        }                  
    }   
    m_cameralist.SetCurSel(0);   
    if (m_eRunmode == RUNMODE_STOP)   
    {   
        OnBnClickedPlay();   
    }      
}   
   
void CCameraDlg::OnBnClickedPlay()    
{   
    // TODO: Add your control notification handler code here   
    m_cameralist.GetLBText(m_cameralist.GetCurSel(), m_sCameraName);   
    if (m_eRunmode == RUNMODE_PLAY)   
    {   
        return;   
    }   
    emDSCameraStatus status = CameraInit(SnapCallBack, m_sCameraName, m_picturebox.GetSafeHwnd(), &m_iCameraID);   
    if (status != STATUS_OK)   
    {          
        AfxMessageBox("�����ʼ��ʧ�ܣ�");   
        return;   
    }    
    InitControls();   
    UpdateDisplayWindow();     
    CameraSetDisplaySize(m_iCameraID, 2592, 1944);   
    CameraPlay(m_iCameraID);   
        GetDlgItem(IDC_BnClickedStop)->EnableWindow(FALSE);   
        GetDlgItem(IDC_BnClickedPlay)->EnableWindow(FALSE);   
        GetDlgItem(IDC_BnClickedSetup)->EnableWindow(FALSE);   
        GetDlgItem(IDC_BnClickedSnap)->EnableWindow(FALSE);   
        GetDlgItem(IDC_BnClickedRecord)->EnableWindow(FALSE);   
    m_eRunmode = RUNMODE_PLAY;   
}   
   
void CCameraDlg::OnBnClickedStop()    
{   
    // TODO: Add your control notification handler code here   
    CameraStop(m_iCameraID);   
    CameraUnInit(m_iCameraID);   
    m_eRunmode = RUNMODE_STOP;   
    GetDlgItem(IDC_BnClickedStop)->EnableWindow(FALSE);   
    GetDlgItem(IDC_BnClickedPlay)->EnableWindow(TRUE);   
}   
   
void CCameraDlg::OnBnClickedSetup()    
{   
}   
   
void CCameraDlg::OnBnClickedSnap()    
{   
    // TODO: Add your control notification handler code here   
    if (m_FileIndex == 0)   
        return;    
    if (!PathIsDirectory(m_sPicPath))   
    {   
        CreateDirectory(m_sPicPath, NULL);   
    }   
    CTime time = CTime::GetCurrentTime();   
    CString sfilename ;    
    sfilename.Format("%sImage_%02d%02d%02d%02d%02d", m_sPicPath, time.GetMonth(), time.GetDay(),    
        time.GetHour(), time.GetMinute(), time.GetSecond());   
    UpdateData(TRUE);   
    CameraSetImageSizeSel(m_iCameraID, m_iResSel, TRUE);   
    if (CameraCaptureFile(m_iCameraID, sfilename, m_FileIndex, 90) == STATUS_OK)   
    {   
        AfxMessageBox("���ճɹ�!");   
    }   
       
}   
   
void CCameraDlg::OnBnClickedRecord()    
{   
}   
   
void CCameraDlg::OnEditchangeResolutionList()    
{   
    // TODO: Add your control notification handler code here   
    UpdateData(TRUE);   
    tDSCameraCapability dsCapbility;   
    CameraGetCapability(m_iCameraID, dsCapbility);   
    CameraSetImageSizeSel(m_iCameraID, m_iResSel, FALSE);   
//  m_pSetupdlg->OnBnClickedSaveparam();   
    UpdateDisplayWindow();   
    CameraPlay(m_iCameraID);   
}   
   
void CCameraDlg::OnEditchangeCameraList()    
{   
    // TODO: Add your control notification handler code here   
    int pos = m_cameralist.GetCurSel();   
    CString tmpname;   
    m_cameralist.GetLBText(pos, tmpname);   
    if (m_sCameraName == tmpname)   
    {   
        return;   
    }   
    CameraStop(m_iCameraID);   
    CameraUnInit(m_iCameraID);   
    m_eRunmode = RUNMODE_STOP;   
    OnBnClickedPlay();   
}   
void CCameraDlg::InitControls()   
{   
    tDSCameraCapability dsCapbility;   
    //tDSImageSize sImageSize;   
    CameraGetCapability(m_iCameraID, dsCapbility);   
    m_resolutionlist.ResetContent();   
    for (int i = 0; i < 8;i++)   
    {   
        if (i >= dsCapbility.iImageSizeDesc)   
        {   
            break;   
        }   
        m_resolutionlist.InsertString(i, dsCapbility.pImageSizeDesc[i].acDescription);   
    }   
    CameraGetImageSizeSel(m_iCameraID,&m_iResSel,FALSE);   
       
    UpdateData(FALSE);   
}   
   
void CCameraDlg::UpdateDisplayWindow()   
{      
    int iFullScreen_cx, iFullScreen_cy;   
    int nWidth, nHeigth;   
    iFullScreen_cx = GetSystemMetrics(SM_CXSCREEN);   
    iFullScreen_cy = GetSystemMetrics(SM_CYSCREEN);   
    tDSCameraCapability dscapability;   
    CameraGetCapability(m_iCameraID, dscapability);   
    if (CameraGetImageSizeSel(m_iCameraID, &m_iResSel, FALSE) != STATUS_OK)   
    {   
        nWidth = 640;   
        nHeigth = 480;   
    }   
    else   
    {   
        nWidth = dscapability.pImageSizeDesc[m_iResSel].iWidth;   
        nHeigth = dscapability.pImageSizeDesc[m_iResSel].iHeight;;   
    }   
    if (nWidth > iFullScreen_cx)   
    {   
        nWidth = iFullScreen_cx;   
    }   
    if (nHeigth > iFullScreen_cy)   
    {   
        nHeigth = iFullScreen_cy ;   
    }   
    if (nWidth < 640)   
    {   
        nWidth = 640;   
    }   
    if (nHeigth < 480)   
    {   
        nHeigth = 480;   
    }   
    this->SetWindowPos(NULL, 0, 0, nWidth, nHeigth, SWP_NOZORDER);   
    GetDlgItem(IDC_STATIC1)->SetWindowPos(NULL, 0, 20, nWidth, nHeigth - 20, SWP_NOZORDER);   
    CRect rect;   
    ::GetClientRect(m_picturebox.GetSafeHwnd(),&rect);   
    CameraSetDisplaySize(m_iCameraID,rect.right-rect.left,rect.bottom - rect.top);   
}   
