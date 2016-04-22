#ifndef _DEVINFO_H
#define _DEVINFO_H
#include "NetSDKDLL.h"

#define  MAX_MINUTES_OF_ONE_DAY 1440
#define  MAX_NVR_RECORD_LEN MAX_MINUTES_OF_ONE_DAY+256

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#endif    
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }
#endif    
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }
#endif

#ifndef SAFE_FREE
#define SAFE_FREE(p) { if(p) { free(p); (p)=NULL; } }
#endif 


class CDevInfo
{
public:
	CDevInfo(IPC_ENTRY *pEntry);

	~CDevInfo();
	
	void ReInit();

	IPC_ENTRY m_IPCEntry;
	/* 公共属性 */
	long iUserID;				// 0值  无效;
	char *pDevceIP;				// 设备IP
	int iVideoChannle;			// DVS时：0,1,2,3,4 IPC时：0,1
	int iDevType;				// 设备类型可以是0，1；0表示IPC，1表示DVS。
	int iLoginStatus;			// 0 未收到登陆状态，-1 登陆失败，1 登陆成功。
	int iOpenStream;			// 0 未进行取流操作，-1 取流失败，1 取流成功。

	BOOL bDVSDevice;			// 是否是DVS
	int iAlive;					// 在线状态: 0 -- 不在线， 1 -- 在线，-1 -- 设备重连中， 2 -- 实时视频中， -2 -- 实时视频异常断开 
	BOOL bAutoReconnect;		// 自动重连
	BOOL bSubStream;			// 是否是子码流连接
	BOOL bTCPConnect;			// 是否TCP连接
	/*实时播放*/
	long lRealHandle;			// 取流句柄,0值无效
	char *pAVParam;				// 实时流媒体参数
	long lPlayerID;				// 播放器ID 1 - 9999
	HWND hRealPlayWnd;			// Real play
	int iOpenAudio;				// 音频控制

	/* 输入流对象 */
	long lInputStreamHandle;	// 输入流录像
	long lInputRecordHandle;	//录像流录像

	int isNVR;					//是否NVR设备，0:不是  1:NVR服务器  2:NVR通道
	int iNVRChannelNums;		//NVR通道数量
	char szNVRCHStatus[64];		//NVR通道状态
	char szNVRRecord[MAX_NVR_RECORD_LEN];
	int isGetRecord;
	int iNVRCHannelIndex;		//NVR通道索引号
	
};

#endif