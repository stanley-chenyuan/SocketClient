#include "StdAfx.h"
#include "SocketClientCode.h"


CSocketClientCode::CSocketClientCode(void)
{
}


CSocketClientCode::~CSocketClientCode(void)
{
}

int CSocketClientCode::InitializationSocket( int number1,int number2 )
{
	//初始化套结字动态库
	if (WSAStartup(MAKEWORD(number1,number2), &m_wsd) != 0)
	{
		cout << "WSAStartup failed!" << endl;
		return -1;
	}

}

int CSocketClientCode::CreateSocket( string SeverIp,int SeverPort )
{
	//创建套接字
	m_sHost = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);	
	if(INVALID_SOCKET == m_sHost)
	{
		cout << "socket failed!" << endl;
		WSACleanup();//释放套接字资源    

		return  -1;
	}
	//设置服务器地址

	m_servAddr.sin_family =AF_INET;
	m_servAddr.sin_addr.s_addr = inet_addr(SeverIp.c_str());
	m_servAddr.sin_port = htons((short)SeverPort);
	int	nServAddlen  = sizeof(m_servAddr);

}

int CSocketClientCode::ConnectServer()
{
	//连接服务器
	m_nretVal=connect(m_sHost,(LPSOCKADDR)&m_servAddr, sizeof(m_servAddr));	
	if(SOCKET_ERROR == m_nretVal)
	{
		cout << "连接服务器失败!" << endl;	 
		closesocket(m_sHost);	//关闭套接字
		WSACleanup();		//释放套接字资源
		return -1;
	}

}

int CSocketClientCode::ClientSend( char *Receivetest )
{
	m_nretVal = send(m_sHost, Receivetest, strlen(Receivetest), 0);
	//while(1){
	//ZeroMemory(m_cbufRecv,BUF_SIZE);
	if (SOCKET_ERROR == m_nretVal)
	{
		cout << "send failed!" << endl;
		closesocket(m_sHost);	//关闭套接字
		WSACleanup();		//释放套接字资源
		return -1;
	}
	//RecvLine(sHost, bufRecv);
	//	}
}

void CALLBACK CSocketClientCode::TimeProc( UINT uID,UINT uMsg,DWORD dwUser,DWORD dw1,DWORD dw2 )
{
	ZeroMemory(m_cbufRecv,BUF_SIZE);
	m_nretVal=recv(m_sHost, m_cbufRecv,BUF_SIZE , 0);		// 接收服务器端的数据， 只接收5个字符
	if (SOCKET_ERROR == m_nretVal)
	{
		//cout << "send failed!" << endl;
		//closesocket(sHost);	//关闭套接字
		//WSACleanup();		//释放套接字资源
	}else{
		MessageBoxA(0,m_cbufRecv,0,0);
	}
}
