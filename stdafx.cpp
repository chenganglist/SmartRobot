
// stdafx.cpp : 只包括标准包含文件的源文件
// Client.pch 将作为预编译头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

//获取时间
CString GetTime(void)
{
	CTime tm;
	CString str;
	tm=CTime::GetCurrentTime();
	str.Format("%d-%d-%d %d:%d:%d",tm.GetYear(),tm.GetMonth(),tm.GetDay(),
		tm.GetHour(),tm.GetMinute(),tm.GetSecond());
	return str;
}
