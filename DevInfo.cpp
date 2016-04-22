#include "stdafx.h"
#include "Client.h"
#include "DevInfo.h"


CDevInfo::CDevInfo(IPC_ENTRY *pEntry)
{
	memcpy(&m_IPCEntry, pEntry, sizeof(IPC_ENTRY));
	pDevceIP = NULL;
	iUserID = 0;
	lPlayerID = 0;
	lRealHandle = 0;

	iOpenAudio = 0;

	pAVParam = NULL;
	lInputStreamHandle = 0;
	lInputRecordHandle = 0;

	hRealPlayWnd = NULL; 
	bAutoReconnect = TRUE;
	iAlive = 0; 
	iLoginStatus = 0;

	bSubStream = TRUE;
	bDVSDevice = FALSE;

	iOpenStream = 0;
	bTCPConnect = 1;

	isNVR = 0;
	iNVRChannelNums = 0;
	isGetRecord = 0;
	memset(szNVRCHStatus, 0, sizeof(szNVRCHStatus));
	memset(szNVRRecord, 0, sizeof(szNVRRecord));

}


CDevInfo::~CDevInfo()
{
	SAFE_FREE(pAVParam);
	SAFE_FREE(pDevceIP);

	iUserID = 0;
	lPlayerID = 0;
	lRealHandle = 0;
	iOpenAudio = 0;
	lInputStreamHandle = 0;
	hRealPlayWnd = NULL; 
	bAutoReconnect = TRUE;
	iAlive = 0; 
	iLoginStatus = 0;
	bSubStream = TRUE;
	bDVSDevice = FALSE;
	
}


void CDevInfo::ReInit()
{
	SAFE_FREE(pAVParam);
	SAFE_FREE(pDevceIP);

	iUserID = 0;
	lPlayerID = 0;
	lRealHandle = 0;
	iOpenAudio = 0;

	lInputStreamHandle = 0;

	hRealPlayWnd = NULL; 
	bAutoReconnect = TRUE;
	iAlive = 0; 
	iLoginStatus = 0;
	bSubStream = TRUE;
	bDVSDevice = FALSE;

}




