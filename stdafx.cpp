
// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// Client.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

//��ȡʱ��
CString GetTime(void)
{
	CTime tm;
	CString str;
	tm=CTime::GetCurrentTime();
	str.Format("%d-%d-%d %d:%d:%d",tm.GetYear(),tm.GetMonth(),tm.GetDay(),
		tm.GetHour(),tm.GetMinute(),tm.GetSecond());
	return str;
}
