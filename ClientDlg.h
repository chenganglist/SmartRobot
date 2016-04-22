
// ClientDlg.h : ͷ�ļ�
#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "DllPlayer.h"
#include "NetSDKDLL.h"
#include "DevInfo.h"
#include <afxsock.h>
#include <Winsock2.h>

extern const LPCTSTR address;
class ClientDlg : public CDialogEx
{
// ����
public:
	ClientDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CLIENT_DLG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	POINT Old;

public:
	//****************����ͷ����**************************//
	//ע��������������˯�����Զ�����
	CStatic m_picture;
	LONG LoginID;//�豸ID
	LONG lRealHandle;//��󶨣���Ƶ��������¼����

	int m_tiltRate;
	int m_panRate;

	long  playDevi(HWND hPlayWnd);
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedBtnUp();
	afx_msg void OnBnClickedBtnLeft();
	afx_msg void OnClickedBtnRight();
	afx_msg void OnClickedBtnDown();
	afx_msg void OnClickedBtnZoomin();
	afx_msg void OnClickedBtnZoomout();
	afx_msg void OnSelchangeCbPanspeed();
	afx_msg void OnSelchangeCbTiltspeed();
	afx_msg void OnBnClickedBtnStopmove();
	afx_msg void OnBnClickedBtnStopRecord();
	//¼��ʵ��ֻ��һ���յĻص�
	afx_msg void OnBnClickedBtnStartRecord();
	afx_msg void OnBTNStartPalyVideo();
	//����Ƶ���ڻص��в���
	afx_msg void OnBTNStopPlay();
	afx_msg void OnBnClickedBtnSnap();

	CComboBox m_PanComb;
	CComboBox m_TiltComb;
	afx_msg void OnBnClickedBntLook();//��¼��·��

	//*********��Ҫ����Ϣ��Ӧ������ص�����**************//
	static LONG __stdcall RealDataCallBackFuncDevi(LONG lRealHandle,DWORD dwDataType,BYTE *pBuffer,DWORD dwBufSize,LPFRAME_EXTDATA  pExtData);

	//*********��Ҫ����Ϣ��Ӧ������ص�����**************//
	//****************����ͷ����**********************//


public:
	CString Command;
	//*****************�������******************//
	BOOL MotorStatus;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CComboBox m_RateSel;
	afx_msg void OnCbnSelchangeCbMotorSpeed();
	afx_msg void OnBnClickedMoveForward();
	afx_msg void OnBnClickedBackWard();
	afx_msg void OnBnClickedStopMotor();

//*****************�������******************//


	afx_msg void OnBnClickedSnapFromServer();
	afx_msg void OnBnClickedAutoScan();
	afx_msg void OnBnClickedStopAuto();
	afx_msg void OnBnClickedBtnLook1080p();

	afx_msg void OnBnClickedBtnRank0();
	

	afx_msg void OnBnFulScreen();

	//״̬��
	CStatusBarCtrl m_StatusBar;
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);


};
