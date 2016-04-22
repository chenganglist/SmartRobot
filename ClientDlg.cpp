
// ClientDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Client.h"
#include "ClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

char* IPCamera = "192.168.2.123";
const LPCTSTR address = "192.168.2.150";
//"192.168.2.150";
//"127.0.0.1";
DWORD WINAPI SendThreadProc(LPVOID lpParameter)
{
	ClientDlg* pDlg = (ClientDlg*)lpParameter;

	if (pDlg->Command=="速度控制")
	{
		int Rate = pDlg->m_RateSel.GetCurSel();
		CSocket pVideoSocket;			
		pVideoSocket.Create();
		BOOL res = pVideoSocket.Connect(address, 6000);

		if (res)
		{
			char* ch = new char;
			sprintf_s(ch,2,"%d",Rate);
			pVideoSocket.Send(ch,3,0);//发送数据
		}
		else
		{
			AfxMessageBox("速度命令发送失败!");
		}

		return 0;//减少判断次数
	}

	if (pDlg->Command == "摄像头")
	{
		CSocket pVideoSocket;			
		pVideoSocket.Create();
		BOOL res = pVideoSocket.Connect(address, 6000);

		if (res)
		{
			pVideoSocket.Send("摄像头",strlen("摄像头")+1,0);//发送数据
		}
		else
		{
			AfxMessageBox("摄像头命令发送失败!");
		}
		return 0;
	}
	

	if (pDlg->Command == "空档")
	{
		int Rate = 0;
		CSocket pVideoSocket;			
		pVideoSocket.Create();
		BOOL res = pVideoSocket.Connect(address, 6000);
		if (res)
		{
			char* ch = new char;
			sprintf_s(ch,2,"%d",Rate);
			pVideoSocket.Send(ch,3,0);//发送数据
			pDlg->m_RateSel.SetCurSel(0);
		}
		else
		{
			AfxMessageBox("空档命令发送失败!");
		}
	    return 0;
	}

	if (pDlg->Command=="前进")
	{
		CSocket pVideoSocket;			
		pVideoSocket.Create();
		BOOL res = pVideoSocket.Connect(address, 6000);

		if (res)
		{
			pVideoSocket.Send("正转",strlen("正转")+1,0);//发送数据
		}
		else
		{
			AfxMessageBox("前进命令发送失败!");
		}
		return 0;
	}

	if (pDlg->Command=="后退")
	{
		CSocket pVideoSocket;			
		pVideoSocket.Create();
		BOOL res = pVideoSocket.Connect(address, 6000);

		if (res)
		{
			pVideoSocket.Send("反转",strlen("反转")+1,0);//发送数据
		}
		else
		{
			AfxMessageBox("后退命令发送失败!");
		}
		return 0;
	}

	if (pDlg->Command=="停止")
	{

		CSocket pVideoSocket;			
		pVideoSocket.Create();
		BOOL res = pVideoSocket.Connect(address, 6000);

		if (res)
		{
			pVideoSocket.Send("刹车",strlen("刹车")+1,0);//发送数据
			pDlg->m_RateSel.SetCurSel(0);
		}
		else
		{
			AfxMessageBox("制动命令发送失败!");
		}
		return 0;
	}


	if (pDlg->Command=="自动扫描")
	{
		CSocket pVideoSocket;			
		pVideoSocket.Create();
		BOOL res = pVideoSocket.Connect(address, 6000);
		if (res)
		{
			pVideoSocket.Send("自动扫描",strlen("自动扫描")+1,0);//发送数据
		}
		else
		{
			AfxMessageBox("自动扫描命令发送失败!");
		}
		return 0;
	}


	if (pDlg->Command=="停止扫描")
	{
		CSocket pVideoSocket ;			
		pVideoSocket.Create();
		BOOL res = pVideoSocket.Connect(address, 6000);
		if (res)
		{
		   pVideoSocket.Send("停止扫描",strlen("停止扫描")+1,0);//发送数据
		}
		else
		{
		   AfxMessageBox("停止扫描命令发送失败!");
		}
	    return 0;
	}


	if (pDlg->Command=="远端抓图")
	{
		CSocket pVideoSocket;			
		pVideoSocket.Create();
		BOOL res = pVideoSocket.Connect(address, 6000);
		if (res)
		{
			pVideoSocket.Send("抓拍",strlen("抓拍")+1,0);//发送数据
		}
		else
		{
			AfxMessageBox("远端抓图命令发送失败!");
		}
		return 0;
	}
	

	return 0;
}



ClientDlg::ClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ClientDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	MotorStatus = TRUE;//正转
}


void ClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICTURE, m_picture);
	DDX_Control(pDX, IDC_CB_PANSPEED, m_PanComb);
	DDX_Control(pDX, IDC_CB_TILTSPEED, m_TiltComb);
	DDX_Control(pDX, IDC_CB_MOTORPEED, m_RateSel);
}


BEGIN_MESSAGE_MAP(ClientDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BTN_UP, &ClientDlg::OnBnClickedBtnUp)
	ON_BN_CLICKED(IDC_BTN_LEFT, &ClientDlg::OnBnClickedBtnLeft)
	ON_BN_CLICKED(IDC_BTN_RIGHT, &ClientDlg::OnClickedBtnRight)
	ON_BN_CLICKED(IDC_BTN_DOWN, &ClientDlg::OnClickedBtnDown)
	ON_BN_CLICKED(IDC_BTN_ZOOMIN, &ClientDlg::OnClickedBtnZoomin)
	ON_BN_CLICKED(IDC_BTN_ZOOMOUT, &ClientDlg::OnClickedBtnZoomout)
	ON_CBN_SELCHANGE(IDC_CB_PANSPEED, &ClientDlg::OnSelchangeCbPanspeed)
	ON_CBN_SELCHANGE(IDC_CB_TILTSPEED, &ClientDlg::OnSelchangeCbTiltspeed)
	ON_BN_CLICKED(IDC_BTN_STOPMOVE, &ClientDlg::OnBnClickedBtnStopmove)
	ON_BN_CLICKED(IDC_BTN_STOP_RECORD, &ClientDlg::OnBnClickedBtnStopRecord)
	ON_BN_CLICKED(IDC_BTN_START_RECORD, &ClientDlg::OnBnClickedBtnStartRecord)
	ON_BN_CLICKED(IDC_BTN_LINK, &ClientDlg::OnBTNStartPalyVideo)
	ON_BN_CLICKED(IDC_STOP_PLAY, &ClientDlg::OnBTNStopPlay)
	ON_BN_CLICKED(IDC_BTN_SNAP, &ClientDlg::OnBnClickedBtnSnap)
	ON_BN_CLICKED(IDC_BNT_LOOK, &ClientDlg::OnBnClickedBntLook)
    ON_WM_SIZE()
	ON_CBN_SELCHANGE(IDC_CB_MOTORPEED, &ClientDlg::OnCbnSelchangeCbMotorSpeed)
	ON_BN_CLICKED(IDC_MOTOR_FORWARD, &ClientDlg::OnBnClickedMoveForward)
	ON_BN_CLICKED(IDC_MOTOR_BACKWARD, &ClientDlg::OnBnClickedBackWard)
	ON_BN_CLICKED(IDC_MOTOR_STOP, &ClientDlg::OnBnClickedStopMotor)
	ON_BN_CLICKED(IDC_SNAP_FROM_SERVER, &ClientDlg::OnBnClickedSnapFromServer)
	ON_BN_CLICKED(IDC_AUTO_SCAN, &ClientDlg::OnBnClickedAutoScan)
	ON_BN_CLICKED(IDC_STOP_AUTO, &ClientDlg::OnBnClickedStopAuto)
	ON_BN_CLICKED(IDC_BTN_LOOK_1080P, &ClientDlg::OnBnClickedBtnLook1080p)
	ON_BN_CLICKED(IDC_BTN_RANK0, &ClientDlg::OnBnClickedBtnRank0)
	ON_BN_CLICKED(IDC_BUTTON3, &ClientDlg::OnBnFulScreen)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CClientDlg 消息处理程序

BOOL ClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标


	//状态栏
	m_StatusBar.Create(WS_CHILD|WS_VISIBLE|SBT_OWNERDRAW, 
		CRect(0,0,0,0), this, 0);
	int strPartDim[2]= {100, -1}; //分割数量
	m_StatusBar.SetParts(2, strPartDim);

	//设置状态栏文本
	m_StatusBar.SetText("系统时间", 0, 0);
	m_StatusBar.SetText(LPCSTR(GetTime()), 1, 0);
	SetTimer(1,1000,NULL);
	// TODO: 在此添加额外的初始化代码
	IP_NET_DVR_Init();//初始化开发包
	//读取厂商号，在调用所有函数之前要调用一次此函数。
	IP_NET_DVR_LoadVendorId();
	lRealHandle = 0;
	m_TiltComb.SetCurSel(4);
	m_tiltRate = 5;
	m_PanComb.SetCurSel(4);
	m_panRate = 5;
	m_RateSel.SetCurSel(0);


	//onsize大小随着对话框大小变化而变化
	CRect rect;     
	GetClientRect(&rect);     //取客户区大小   
	Old.x=rect.right-rect.left; 
	Old.y=rect.bottom-rect.top; 
	LoginID = 0;

	while (LoginID==0)
	{
		LoginID = IP_NET_DVR_Login(IPCamera,8091,"admin","123456",
			NULL);
	}
	IP_TPS_Stop(1);
	playDevi(m_picture.m_hWnd);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。
void ClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR ClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void ClientDlg::OnBnClickedBtnStopRecord()
{
	// TODO: 在此添加控件通知处理程序代码
	if (IP_NET_DVR_StopRecord(lRealHandle)==0)
	{
		MessageBox("录像已停止！");
	}

}


void ClientDlg::OnBnClickedBtnStartRecord()
{
	// TODO: 在此添加控件通知处理程序代码
	long RecordStatus = IP_NET_DVR_StartRecord(lRealHandle,
		"D:\\Record",1800,3600); //30分钟录一个文件，36个文件

	if (RecordStatus==0)
	{
		MessageBox("开始录像，录像保存在D:\\Record");

	}

}


void ClientDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	IP_NET_DVR_Cleanup();
	IP_NET_DVR_LogoutAll();
	IP_NET_DVR_StopAllRealPlay();
	IP_TPS_Stop(1);
	IP_NET_DVR_StopRecord(lRealHandle);
	KillTimer(1);

}


void ClientDlg::OnBnClickedBtnUp()
{
	// TODO: 在此添加控件通知处理程序代码
	Command = "摄像头";
	IP_NET_DVR_PTZControl(LoginID,TILT_UP,m_tiltRate,m_panRate);
	CreateThread(NULL, 0,SendThreadProc,this,0,NULL);

}


void ClientDlg::OnBnClickedBtnLeft()
{
	// TODO: 在此添加控件通知处理程序代码
	Command = "摄像头";
	IP_NET_DVR_PTZControl(LoginID,PAN_LEFT,m_tiltRate,m_panRate);
	CreateThread(NULL, 0,SendThreadProc,this,0,NULL);

}


void ClientDlg::OnClickedBtnRight()
{
	// TODO: 在此添加控件通知处理程序代码
	Command = "摄像头";
	IP_NET_DVR_PTZControl(LoginID,PAN_RIGHT,m_tiltRate,m_panRate);
	CreateThread(NULL, 0,SendThreadProc,this,0,NULL);

}


void ClientDlg::OnClickedBtnDown()
{
	// TODO: 在此添加控件通知处理程序代码
	Command = "摄像头";
	IP_NET_DVR_PTZControl(LoginID,TILT_DOWN,m_tiltRate,m_panRate);
	CreateThread(NULL, 0,SendThreadProc,this,0,NULL);

}


void ClientDlg::OnClickedBtnZoomin()
{
	// TODO: 在此添加控件通知处理程序代码
	Command = "摄像头";
	IP_NET_DVR_PTZControl(LoginID,ZOOM_IN_VALUE,m_tiltRate,m_panRate);
	int rate = m_tiltRate + m_panRate;
	Sleep(rate*40);
	IP_NET_DVR_PTZControl(LoginID,STOPACTION,0,0);
	CreateThread(NULL, 0,SendThreadProc,this,0,NULL);

}


void ClientDlg::OnClickedBtnZoomout()
{
	// TODO: 在此添加控件通知处理程序代码
	Command = "摄像头";
	IP_NET_DVR_PTZControl(LoginID,ZOOM_OUT_VALUE,m_tiltRate,m_panRate);
	int rate = m_tiltRate + m_panRate ;
	Sleep(rate*40);
	IP_NET_DVR_PTZControl(LoginID,STOPACTION,0,0);
	//倍率变小
	CreateThread(NULL, 0,SendThreadProc,this,0,NULL);

}

//水平速度
void ClientDlg::OnSelchangeCbPanspeed()
{
	// TODO: 在此添加控件通知处理程序代码
	Command = "摄像头";
	IP_NET_DVR_PTZControl(LoginID,STOPACTION,0,0);
	int Pan = m_PanComb.GetCurSel();
	m_panRate = Pan + 1;
	CreateThread(NULL, 0,SendThreadProc,this,0,NULL);

}

//上下扫描速度
void ClientDlg::OnSelchangeCbTiltspeed()
{
	// TODO: 在此添加控件通知处理程序代码
	Command = "摄像头";
	IP_NET_DVR_PTZControl(LoginID,STOPACTION,0,0);
	int tilt = m_TiltComb.GetCurSel();
	m_tiltRate = tilt + 1;
	CreateThread(NULL, 0,SendThreadProc,this,0,NULL);

}


void ClientDlg::OnBnClickedBtnStopmove()
{
	// TODO: 在此添加控件通知处理程序代码
	Command = "摄像头";
	IP_NET_DVR_PTZControl(LoginID,STOPACTION,0,0);
	CreateThread(NULL, 0,SendThreadProc,this,0,NULL);
	
	
}


//设备连接，视频播放
void ClientDlg::OnBTNStartPalyVideo()
{
	// TODO: 在此添加控件通知处理程序代码
	Command = "摄像头";
	LoginID = IP_NET_DVR_Login(IPCamera,8091,"admin","123456",
			NULL);
	IP_TPS_Stop(1);
	playDevi(m_picture.m_hWnd);
	CreateThread(NULL, 0,SendThreadProc,this,0,NULL);
	
}


///******************播放本地高清主码流*****************************//
long ClientDlg::playDevi(HWND hPlayWnd)
{

	IPC_ENTRY DevEntry = {0};

	CDevInfo* pDevInfo = new CDevInfo(&DevEntry);

	pDevInfo->hRealPlayWnd = hPlayWnd; 
	//为回调函数传入用户信息
	pDevInfo->lPlayerID = 1;

	USRE_VIDEOINFO* user = new USRE_VIDEOINFO;
	user->bIsTcp = 1; 
	user->nVideoChannle = 1;
	user->nVideoPort = 554;
	user->pUserData = (void*)pDevInfo;  
	//回调的最后一个参数-----用于向回调函数传入用户参数
	//回调函数必须提供一个固定类型的指针以供用户传入自己所设置的特定参数

	lRealHandle = IP_NET_DVR_RealPlayEx(LoginID ,IPCamera, 
		"admin", "123456", RealDataCallBackFuncDevi, user, NULL);

	pDevInfo->lRealHandle = lRealHandle;
	//回调函数播放句柄
	
	return 0;

}


LONG __stdcall ClientDlg::RealDataCallBackFuncDevi(LONG lRealHandle,
	DWORD dwDataType,BYTE *pBuffer,DWORD dwBufSize,LPFRAME_EXTDATA  pExtData)
{
	//传入用户数据
	CDevInfo *pDevInfo = (CDevInfo *)pExtData->pUserData;
	if (pDevInfo->lRealHandle <= 0)
	{
		return 0;
	}
	//TRACE(XXX);即在调试状态显示XXX的值
	if (dwDataType == 0)
	{
		
		if (pDevInfo->lPlayerID != 0 )
		{

			long lInputErr = IP_TPS_InputVideoData(pDevInfo->lPlayerID, pBuffer, dwBufSize, pExtData->bIsKey, pExtData->timestamp);

			if (lInputErr != 0) 
			{
				TRACE("IP_TPS_InputVideoData failed!!!!!\n");
			}

		}

	}
	else if(dwDataType==2)
	{
		STREAM_AV_PARAM *pavParam = (STREAM_AV_PARAM *)pBuffer;
	
		if (pavParam->bHaveVideo)
		{
			long lRet = IP_TPS_OpenStream(pDevInfo->lPlayerID, (BYTE *)&(pavParam->videoParam), sizeof(VIDEO_PARAM), 0, 40);

			if (lRet != 0)
			{
				TRACE("Video IP_TPS_OpenStream faild!!!\n"); 
				return 0;
			}
		}

		if (NULL == pDevInfo->pAVParam)
		{
			pDevInfo->pAVParam = (char *)malloc(dwBufSize);
			if (NULL == pDevInfo->pAVParam)
			{
				return -1;
			}
		}
		memcpy(pDevInfo->pAVParam, pavParam, sizeof(STREAM_AV_PARAM));

		if (pDevInfo->hRealPlayWnd != NULL)
		{

			int iRetPlay = IP_TPS_Play(pDevInfo->lPlayerID, pDevInfo->hRealPlayWnd);

		}
	}
	return 0;

}
//******************播放本地高清视频******************************//


void ClientDlg::OnBTNStopPlay()
{
	// TODO: 在此添加控件通知处理程序代码
	Command = "摄像头";
	IP_TPS_Stop(1);
	CreateThread(NULL, 0,SendThreadProc,this,0,NULL);
}


void ClientDlg::OnBnClickedBtnSnap()
{
	// TODO: 在此添加控件通知处理程序代码

	CTime tm;
	tm=CTime::GetCurrentTime();

	CString strFile;
	CString strPath = "D:\\Snap\\";
	CString Date;
	CreateDirectory(LPCSTR(strPath),NULL);

	Date.Format("%d-%d-%d",tm.GetYear(),tm.GetMonth(),tm.GetDay());
	strPath = strPath + Date;
	CreateDirectory(LPCSTR(strPath),NULL);
	strFile.Format("%s\\%d-%d-%d.jpg",
		strPath, tm.GetHour(), tm.GetMinute(), tm.GetSecond());

	IP_TPS_CatchPicByFileName(1, strFile.GetBuffer(), 1);//1JPG

}


void ClientDlg::OnBnClickedBntLook()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CString strPathSnap = "D:\\Snap";
	ShellExecute(this->GetSafeHwnd(),"open",strPathSnap,NULL,NULL,SW_SHOW);
	TRACE("Done");
}


void ClientDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	if(nType==SIZE_RESTORED||nType==SIZE_MAXIMIZED) 
	{ 
		float fsp[2]; 
		POINT Newp; //获取现在对话框的大小 
		CRect recta;     
		GetClientRect(&recta);     //取客户区大小   
		Newp.x=recta.right-recta.left; 
		Newp.y=recta.bottom-recta.top; 
		fsp[0]=(float)Newp.x/Old.x; 
		fsp[1]=(float)Newp.y/Old.y; 
		CRect Rect; 
		int woc; 
		CPoint OldTLPoint,TLPoint; //左上角 
		CPoint OldBRPoint,BRPoint; //右下角 
		HWND  hwndChild=::GetWindow(m_hWnd,GW_CHILD);  //列出所有控件   
		while(hwndChild)     
		{     
			woc=::GetDlgCtrlID(hwndChild);//取得ID 
			GetDlgItem(woc)->GetWindowRect(Rect);   
			ScreenToClient(Rect);   
			OldTLPoint = Rect.TopLeft();   
			TLPoint.x = long(OldTLPoint.x*fsp[0]);   
			TLPoint.y = long(OldTLPoint.y*fsp[1]);   
			OldBRPoint = Rect.BottomRight();   
			BRPoint.x = long(OldBRPoint.x *fsp[0]);   
			BRPoint.y = long(OldBRPoint.y *fsp[1]); 

			//对组合框控件进行特殊处理
		
			HWND hwnd1 = m_PanComb.GetSafeHwnd(); 
			HWND hwnd2 = m_TiltComb.GetSafeHwnd(); 
	        HWND hwnd3 = m_RateSel.GetSafeHwnd(); 
			// 取得控件的句柄
			if (hwndChild==hwnd1)
			{
				BRPoint.y = BRPoint.y+200;
			}
			// 取得控件的句柄
			if (hwndChild==hwnd2)
			{
				BRPoint.y = BRPoint.y+200;
			}
			if (hwndChild==hwnd3)
			{
				BRPoint.y = BRPoint.y+150;
			}
	
			Rect.SetRect(TLPoint,BRPoint);   
			GetDlgItem(woc)->MoveWindow(Rect,TRUE); 
			hwndChild=::GetWindow(hwndChild, GW_HWNDNEXT);     
		} 
		Old=Newp; 
		Invalidate();
	} 
}


BOOL ClientDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN   &&   pMsg->wParam == VK_RETURN)
	{
		return TRUE;
	}


	if (pMsg->message == WM_KEYDOWN   &&   pMsg->wParam == VK_ESCAPE)
	{
		return TRUE;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}



void ClientDlg::OnCbnSelchangeCbMotorSpeed()
{
	// TODO: 在此添加控件通知处理程序代码
	Command = "速度控制";
	CreateThread(NULL, 0,SendThreadProc,this,0,NULL);

}


void ClientDlg::OnBnClickedMoveForward()
{
	// TODO: 在此添加控件通知处理程序代码
	Command = "前进";
	CreateThread(NULL, 0,SendThreadProc,this,0,NULL);

}


void ClientDlg::OnBnClickedBackWard()
{
	// TODO: 在此添加控件通知处理程序代码
	Command = "后退";
	CreateThread(NULL, 0,SendThreadProc,this,0,NULL);

}


void ClientDlg::OnBnClickedStopMotor()
{
	// TODO: 在此添加控件通知处理程序代码
	Command = "停止";
	CreateThread(NULL, 0,SendThreadProc,this,0,NULL);

}



void ClientDlg::OnBnClickedSnapFromServer()
{
	// TODO: 在此添加控件通知处理程序代码
	Command = "远端抓图";
	CreateThread(NULL, 0,SendThreadProc,this,0,NULL);

}


void ClientDlg::OnBnClickedAutoScan()
{
	// TODO: 在此添加控件通知处理程序代码
	Command = "自动扫描";
	CreateThread(NULL, 0,SendThreadProc,this,0,NULL);

}


void ClientDlg::OnBnClickedStopAuto()
{
	// TODO: 在此添加控件通知处理程序代码
	Command = "停止扫描";
	CreateThread(NULL, 0,SendThreadProc,this,0,NULL);

}


void ClientDlg::OnBnClickedBtnLook1080p()
{
	// TODO: 在此添加控件通知处理程序代码
	Command = "摄像头";
	CString strPathSnap = "D:\\1080P";
	ShellExecute(this->GetSafeHwnd(),"open",strPathSnap,NULL,NULL,SW_SHOW);
	
}


void ClientDlg::OnBnClickedBtnRank0()
{
	// TODO: 在此添加控件通知处理程序代码
	Command = "空档";
	CreateThread(NULL, 0,SendThreadProc,this,0,NULL);

}


void ClientDlg::OnBnFulScreen()
{
	// TODO: 在此添加控件通知处理程序代码
	static bool IsFull;
	IsFull = !IsFull;
	IP_TPS_SetFullFillStatus(1,IsFull);

}


void ClientDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	m_StatusBar.SetText(LPCSTR(GetTime()), 1, 0);

	CDialogEx::OnTimer(nIDEvent);

}
