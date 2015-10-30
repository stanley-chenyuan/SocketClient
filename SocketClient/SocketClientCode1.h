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
	BOOL	RecvLine(SOCKET s, char* buf);	//��ȡһ������
	WSADATA			m_wsd;			//WSADATA����
	SOCKET			m_sHost;			//�������׽���
	SOCKADDR_IN		m_servAddr;		//��������ַ
	char			m_cbuf[BUF_SIZE];	//�������ݻ�����
	char			m_cbufRecv[BUF_SIZE];
	int				m_nretVal;			//����ֵ

	void CALLBACK TimeProc(UINT uID,UINT uMsg,DWORD dwUser,DWORD dw1,DWORD dw2); //������Ϣ�Ļص�����
	int InitializationSocket(int number1,int number2);							 //��ʼ���׽���
	int CreateSocket(string SeverIp,int SeverPort);							//�����׽���
	int ConnectServer();													   //�����׽���
	int ClientSend(char *Receivetest);														  //������Ϣ
};

