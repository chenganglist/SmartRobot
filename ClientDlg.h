
// ClientDlg.h : 头文件
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
// 构造
public:
	ClientDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CLIENT_DLG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	POINT Old;

public:
	//****************摄像头控制**************************//
	//注意设置主机永不睡眠与自动锁定
	CStatic m_picture;
	LONG LoginID;//设备ID
	LONG lRealHandle;//请绑定：视频流播放与录像句柄

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
	//录像实际只需一个空的回调
	afx_msg void OnBnClickedBtnStartRecord();
	afx_msg void OnBTNStartPalyVideo();
	//播视频是在回调中播放
	afx_msg void OnBTNStopPlay();
	afx_msg void OnBnClickedBtnSnap();

	CComboBox m_PanComb;
	CComboBox m_TiltComb;
	afx_msg void OnBnClickedBntLook();//打开录像路径

	//*********重要的消息响应函数与回调函数**************//
	static LONG __stdcall RealDataCallBackFuncDevi(LONG lRealHandle,DWORD dwDataType,BYTE *pBuffer,DWORD dwBufSize,LPFRAME_EXTDATA  pExtData);

	//*********重要的消息响应函数与回调函数**************//
	//****************摄像头控制**********************//


public:
	CString Command;
	//*****************电机控制******************//
	BOOL MotorStatus;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CComboBox m_RateSel;
	afx_msg void OnCbnSelchangeCbMotorSpeed();
	afx_msg void OnBnClickedMoveForward();
	afx_msg void OnBnClickedBackWard();
	afx_msg void OnBnClickedStopMotor();

//*****************电机控制******************//


	afx_msg void OnBnClickedSnapFromServer();
	afx_msg void OnBnClickedAutoScan();
	afx_msg void OnBnClickedStopAuto();
	afx_msg void OnBnClickedBtnLook1080p();

	afx_msg void OnBnClickedBtnRank0();
	

	afx_msg void OnBnFulScreen();

	//状态栏
	CStatusBarCtrl m_StatusBar;
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);


};
