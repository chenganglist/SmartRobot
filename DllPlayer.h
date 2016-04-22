// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� DLLPLAYER_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// DLLPLAYER_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
//#include "stdafx.h"
#ifndef		__DLLPLAYER_20110802_H
#define __DLLPLAYER_20110802_H


#ifdef DLLDECODER_EXPORTS	//ֻ��������
	#define DLLPLAYER_API
#else
	#ifdef DLLPLAYER_EXPORTS
		#define DLLPLAYER_API __declspec(dllexport)
	#else
		#ifdef DLLPLAYER_IS_LIB	//ʹ��lib�汾ʱ��ȫ��������������
			#define DLLPLAYER_API
			#pragma comment(lib, "cximage.lib")
			#pragma comment(lib, "Jpeg.lib")
			#pragma comment(lib, "dxguid.lib")
			#pragma comment(lib, "ddraw.lib")
			#pragma comment(lib, "dmoguids.lib")
			#pragma comment(lib, "strmiids.lib")
			//#pragma comment(lib, "avutil.lib")
			//#pragma comment(lib, "avcodec.lib")
			//#pragma comment(lib, "avcore.lib")
			//#pragma comment(lib, "libDllPlayer.lib") 
		#else
			#define DLLPLAYER_API  __declspec(dllimport)
			#pragma comment(lib, "DllPlayer.lib")
		#endif
	#endif
#endif


#define		NEEDADD_STREAM_FRAME_HEADER_FLAGHEAD		0

///���Ŷ���1������2ֹͣ��3�����4���ţ�5֡����6���㲥��
enum PLAYFILE_ACTION
{
	PLAYER_ACTION_PLAY=1,
	PLAYER_ACTION_STOP,
	PLAYER_ACTION_FAST,
	PLAYER_ACTION_SLOW,
	PLAYER_ACTION_FRAMESKIP,
	PLAYER_ACTION_SEEK,
	PLAYER_ACTION_PAUSE,
	PLAYER_ACTION_RESUME,
	PLAYER_ACTION_CAPIMG=10,
	PLAYER_ACTION_CHANGE_SOUND,
	PLAYER_ACTION_RECV_DECODEPARAM,
	PLAYER_ACTION_NOSKIPFRAME_FAST,
};

//��Ϣ��LIB��/�¼�(COM) ����
enum EventCode
{
	RECVDATATIMEOUT=1			//��ȡ��ʱ�����10���ڶ�û�����ݣ���ᷢ�ʹ���Ϣ
	,FOCUSCHANGE				//����������ı�ʱ����
	,STARTPLAY					//��ʼ����
	,ENTERWAITFORBUFFER			//���뻺��
	,SETUP_VIDEO_PARAM_OK		//SetupDecoder���سɹ�
	,SETUP_AUDIO_PARAM_OK		//SetupDecoder���سɹ�
	,SNAPSHORT_FINISH			//ץͼ����
	,BINDPORTERROR				//��˿�ʧ��
	,VSS_STOPPLAY				//����VSS�ļ�����
	,VSS_STARTPLAY				//��ʼ����
	,VSS_PLAYNEXT				//������һ���ļ�
	,VSS_SETUPERROR				//����setup����ʧ��
	,CREATE_THREAD_ERROR		//�����߳�ʧ��
	,LOC_STOPPLAY				//ֹͣ�����ļ�����
	,LOC_OPENFILEERROR			//�����ļ�����ʱ���ļ�ʧ��
	,LOC_PLAYERROR				//����ʧ���˳�
	,LOC_PAUSEPLAY				//��ͣ����
	,LOC_OPENFILE_ERROR			//�򿪱����ļ�ʧ��
	,RECV_RETUN_ERROR			//RTPRECV��ȡ���ݷ�������16���ֽ�
	,FIRSTPLAY					//��һ�β���
	,RECORDEND
	,CAPTUREPICEND
	,PLAYTIMECHANGE
};

enum PLAYDLL_ERROR_CODE
{
	ERR_PLY_AUDIOPARAM_ERROR=-999991,
	ERR_PLY_VIDEOPARAM_ERROR,
	ERR_PLY_VIDEOCHANNELID_ERROR,
	ERR_PLY_NOT_DECODER_MODE,
	ERR_PLY_DECODERTHREAD_NOTSTART,
	ERR_PLY_SOUND_OFF_SKIPBUFFER,
	ERR_PLY_NOAUDIOON_ERROR,
	ERR_PLAY_NOTPLAYMODE_ERROR,
	ERR_PLY_DISPLAY_OFF_ERROR,
	ERR_PLAY_FILETYPE_ERROR,
	ERR_PLAY_AVIFILE_ERROR,
	ERR_PLAY_NOTPLAYMODE,
	ERR_PLAY_CONTROL_PARAM_ERROR,
	ERR_PLAY_CONTROLTYPE_ERROR,
	ERR_PLAYER_ISPLAYING_FILE,
	ERR_PLAYER_OPENFILEERROR,
	ERR_PLAY_STOPPLAYFIRST,
	ERR_PLAY_BUFFER_ISFULL,
	ERR_PLAY_NOT_PLAYLOCFILE_MODE,
	ERR_PLAY_NOTFIND_VIDEO_ERROR,
	ERR_PLAY_NOTREPLAY_MODE_ERROR,
	ERR_PLAY_NOPLAYING_ERROR,
	ERR_PLAY_OUT_OFF_MEMORY,
	ERR_PLAY_INITDSOUND_FAIL,
	ERR_PLAY_PARAM_ERROR,
	ERR_POINTER_ISNULL,
};

typedef struct
{
	long nWidth;
	long nHeight;
	long nStamp;
	long nType;
	long nFrameRate;
	long bIsVideo;
	int  nLinseSize[4];
}FRAME_INFO; 


#define MAX_VIDEO_IN_BUFFER_SIZE		(2<<20)   //����ʱ���Ҫ2M�����ݣ��������ֵ����̫С 


typedef int (CALLBACK* fDecCallBackFunction)(long nPort,char * pBuf,long nSize,FRAME_INFO * pFrameInfo, void * pUser,long nReserved2);
typedef LONG(CALLBACK* fStatusEventCallBack)(long nPort,LONG nStateCode,char *pResponse,void *pUser);
typedef	long (CALLBACK* fDisplayFinishCallBack)(long lType/*=0x10000001*/, long lPara1/*==HDC*/, long lPara2/*==NULL*/);//add 20130217 play file by zfuwen


DLLPLAYER_API 	int 		__stdcall 		IP_TPS_Init();
DLLPLAYER_API 	int 		__stdcall 		IP_TPS_CloseAll();
DLLPLAYER_API 	int 		__stdcall 		IP_TPS_ReleaseAll();
DLLPLAYER_API 	int			__stdcall 		IP_TPS_OpenStream(LONG nPort,PBYTE pParam,DWORD pSize,int isAudioParam,DWORD nMaxBufFrameCount);
DLLPLAYER_API 	int 		__stdcall 		IP_TPS_Play(LONG nPort, HWND hWnd);
DLLPLAYER_API 	int 		__stdcall 		IP_TPS_PlayByArea(LONG nPort, HWND hWnd, RECT rcArea);
DLLPLAYER_API 	int 		__stdcall 		IP_TPS_PlaySound(LONG nPort);
DLLPLAYER_API 	int 		__stdcall 		IP_TPS_InputAudioData(LONG nPort,PBYTE pBuf,DWORD nSize,DWORD timestamp);
DLLPLAYER_API 	int 		__stdcall 		IP_TPS_InputVideoData(LONG nPort,PBYTE pBuf,DWORD nSize,int isKey,DWORD timestamp);
DLLPLAYER_API 	int 		__stdcall 		IP_TPS_CatchPic(LONG Port,char* sDirName);
DLLPLAYER_API 	int 		__stdcall 		IP_TPS_CatchPicByFileName(LONG nPort,char* sFileName,int isJpg);
DLLPLAYER_API 	int 		__stdcall 		IP_TPS_StopSound();
DLLPLAYER_API 	int 		__stdcall 		IP_TPS_Stop(LONG nPort);
DLLPLAYER_API 	int 		__stdcall 		IP_TPS_CloseStream(LONG nPort);
DLLPLAYER_API 	int 		__stdcall 		IP_TPS_DeleteStream(LONG nPort);
DLLPLAYER_API 	int			__stdcall		IP_TPS_SetDecCallBack(LONG nPort,fDecCallBackFunction func,void * pUser);
DLLPLAYER_API 	LONG 		__stdcall 		IP_TPS_GetVersion();
DLLPLAYER_API	LONG		__stdcall		IP_TPS_SetStatusEventCallBack(LONG nPort,fStatusEventCallBack func,void * pUser);
DLLPLAYER_API 	int			__stdcall		IP_TPS_SetBufferTick(LONG nPort,int nMaxSecond);//add 2013-03-21


DLLPLAYER_API	LONG		__stdcall		IP_TPS_RefreshSurface(LONG nPort);//redraw image  add 20130217 by zfuwen
DLLPLAYER_API	int			__stdcall		IP_TPS_SetVolume(LONG nPort,LONG nVolume);//add 20130217 play file by zfuwen
DLLPLAYER_API	int			__stdcall		IP_TPS_GetVolume(LONG nPort,LONG * pVolume);//add 20130217 play file by zfuwen
DLLPLAYER_API	int			__stdcall		IP_TPS_SetPlayDirection(LONG nPort,LONG nType);//add 20130217 play file by zfuwen
DLLPLAYER_API	int			__stdcall		IP_TPS_SetDisplayFinishCallBack(LONG nPort,fDisplayFinishCallBack fnCallBack);//add 20130217 play file by zfuwen


DLLPLAYER_API 	int 		__stdcall 		IP_TPS_PlaySoundShare(LONG nPort);//add 20130217 play file by zfuwen,play audio more than one stram
DLLPLAYER_API 	int 		__stdcall 		IP_TPS_StopSoundShare(LONG nPort);//add 20130217 play file by zfuwen,stop play one audio stream



#if !DLLDECODER_EXPORTS
DLLPLAYER_API	int			__stdcall		IP_TPS_PlayLocFile(LONG nPort,HWND hWnd,const char * filename,int fileType);
DLLPLAYER_API	int			__stdcall		IP_TPS_StopPlayLocFile(LONG nPort);
DLLPLAYER_API	int			__stdcall		IP_TPS_GetPlayTime(LONG nPort,int * time);//get now file play pos reutrn seconds.
DLLPLAYER_API	int			__stdcall		IP_TPS_GetFileTime(LONG nPort,int * time);//get now file all time,return seconds.
DLLPLAYER_API	int			__stdcall		IP_TPS_ControlPlay(LONG nPort,int nAction,int param);//control play 
DLLPLAYER_API	int			__stdcall		IP_TPS_OpenFile(LONG * nPort,char * filename);//add 20130217 test file is ok?
DLLPLAYER_API	int			__stdcall		IP_TPS_StartPlayFile(LONG nPort,HWND hWnd);//add 20130217 play file
DLLPLAYER_API	int			__stdcall		IP_TPS_SetFileEndMsgWnd(LONG nPort, long hWnd, long lMsg);//add 20130217 play file
DLLPLAYER_API	int			__stdcall		IP_TPS_SetPlayBackMode(LONG nPort,int bIsPlayBack); 
#endif

//������궯�����Դ���ע�ⲻҪ��˫���¼�
DLLPLAYER_API	int			__stdcall		IP_TPS_InputMouseEvent(LONG nPort,LONG nMsgType,WPARAM wp,LPARAM lp);
//������������
DLLPLAYER_API	int			__stdcall		IP_TPS_SetZoomRectOn(LONG nPort,LONG nType);
//ȡ��ǰ״̬���Ƿ����õ�������
DLLPLAYER_API	int			__stdcall		IP_TPS_GetZoomRectStatus(LONG nPort);
DLLPLAYER_API	int			__stdcall		IP_TPS_SetFullFillStatus(LONG nPort,int bIsFullFill);
DLLPLAYER_API	int			__stdcall		IP_TPS_GetFullFillStatus(LONG nPort);
//������Ƶ�Ƿ񲥷�
DLLPLAYER_API 	int 		__stdcall 		IP_TPS_SetVideoOn(LONG nPort,int bIsOn);
DLLPLAYER_API	int			__stdcall		IP_TPS_SwitchVideo(LONG from,LONG to);
DLLPLAYER_API	int			__stdcall		IP_TPS_SetContrast(LONG nPort,int nBrightness,int nContrast,int bIsEnable);

DLLPLAYER_API	int			__stdcall		IP_TPS_SetColor(LONG nPort, long lBrightness, long lContrast, long lSaturation, long lHue);//add 20130217 play file by zfuwen
DLLPLAYER_API	int			__stdcall		IP_TPS_GetColor(LONG nPort, long *plBrightness, long *plContrast, long *plSaturation, long *plHue);//add 20130217 play file by zfuwen


DLLPLAYER_API	int			__stdcall		IP_TPS_SetGamma(LONG nPort,int nGammaValue,int bIsEnable);//gamma 
DLLPLAYER_API	int			__stdcall		IP_TPS_GetBufferCount(LONG nPort,LONG * pRetCount);
DLLPLAYER_API	int			__stdcall		IP_TPS_ClearBuffer(LONG nPort);
DLLPLAYER_API	int			__stdcall		IP_TPS_BufferIsFull(LONG nPort,int bAutoPlayMaxFrame);//add by zfuwen 20130301
DLLPLAYER_API	int			__stdcall		IP_TPS_SetShowTitle(int nPort,char * TitleMsg, int x, int y , int bNeedShow);
DLLPLAYER_API	LONG		__stdcall		IP_TPS_SetLogToFile(DWORD bLogEnable,char *strLogDir,BOOL bAutoDel);

//lionel add @2012-10-15:����ƶ����澯��������
DLLPLAYER_API 	int 		__stdcall       IP_TPS_SetMotionDetectConfigOn(LONG nPort,LONG value);
DLLPLAYER_API 	int 		__stdcall       IP_TPS_SetMotionDetectConfig(LONG nPort,LONG xBlocks, LONG yBlocks, char *pConfigString);
DLLPLAYER_API 	int 		__stdcall       IP_TPS_GetMotionDetectConfigString(LONG nPort,char *pConfigString);



//������Ƶ���벥��
DLLPLAYER_API	int			__stdcall		IP_TPS_CreateAuidoStreamPlayer(LONG * plPort,int audiotype, int samplerate, int bitspersample, int channels);//add by zfuwen 20130221
DLLPLAYER_API	int			__stdcall		IP_TPS_InputAuidoStreamPlayer(LONG  lPort,char * pBuffer,int buflen);//add by zfuwen 20130221
DLLPLAYER_API	int			__stdcall		IP_TPS_DestroyAuidoStreamPlayer(LONG  lPort);//add by zfuwen 20130221



#endif
