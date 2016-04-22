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
	/* �������� */
	long iUserID;				// 0ֵ  ��Ч;
	char *pDevceIP;				// �豸IP
	int iVideoChannle;			// DVSʱ��0,1,2,3,4 IPCʱ��0,1
	int iDevType;				// �豸���Ϳ�����0��1��0��ʾIPC��1��ʾDVS��
	int iLoginStatus;			// 0 δ�յ���½״̬��-1 ��½ʧ�ܣ�1 ��½�ɹ���
	int iOpenStream;			// 0 δ����ȡ��������-1 ȡ��ʧ�ܣ�1 ȡ���ɹ���

	BOOL bDVSDevice;			// �Ƿ���DVS
	int iAlive;					// ����״̬: 0 -- �����ߣ� 1 -- ���ߣ�-1 -- �豸�����У� 2 -- ʵʱ��Ƶ�У� -2 -- ʵʱ��Ƶ�쳣�Ͽ� 
	BOOL bAutoReconnect;		// �Զ�����
	BOOL bSubStream;			// �Ƿ�������������
	BOOL bTCPConnect;			// �Ƿ�TCP����
	/*ʵʱ����*/
	long lRealHandle;			// ȡ�����,0ֵ��Ч
	char *pAVParam;				// ʵʱ��ý�����
	long lPlayerID;				// ������ID 1 - 9999
	HWND hRealPlayWnd;			// Real play
	int iOpenAudio;				// ��Ƶ����

	/* ���������� */
	long lInputStreamHandle;	// ������¼��
	long lInputRecordHandle;	//¼����¼��

	int isNVR;					//�Ƿ�NVR�豸��0:����  1:NVR������  2:NVRͨ��
	int iNVRChannelNums;		//NVRͨ������
	char szNVRCHStatus[64];		//NVRͨ��״̬
	char szNVRRecord[MAX_NVR_RECORD_LEN];
	int isGetRecord;
	int iNVRCHannelIndex;		//NVRͨ��������
	
};

#endif