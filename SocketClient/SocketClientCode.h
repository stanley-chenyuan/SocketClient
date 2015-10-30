#pragma once
#include "stdafx.h"
#include "winsock2.h"
#include <iostream>
#include<windows.h>
#include <Mmsystem.h>
#include <string>
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "ws2_32.lib")
using namespace std;
#define   BUF_SIZE 256
class CSocketClientCode
{
public:
	CSocketClientCode(void);
	~CSocketClientCode(void);
	BOOL	RecvLine(SOCKET s, char* buf);	//读取一行数据
	WSADATA			m_wsd;			//WSADATA变量
	SOCKET			m_sHost;			//服务器套接字
	SOCKADDR_IN		m_servAddr;		//服务器地址
	char			m_cbuf[BUF_SIZE];	//接收数据缓冲区
	char			m_cbufRecv[BUF_SIZE];
	int				m_nretVal;			//返回值

	void CALLBACK TimeProc(UINT uID,UINT uMsg,DWORD dwUser,DWORD dw1,DWORD dw2); //接受消息的回调函数
	int InitializationSocket(int number1,int number2);							 //初始化套接字
	int CreateSocket(string SeverIp,int SeverPort);							//建立套接字
	int ConnectServer();													   //连接套接字
	int ClientSend(char *Receivetest);														  //发送消息
};

