// 2023.09.21

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#define WIN32_LEAN_AND_MEAN
#include<WinSock2.h>
#include<Windows.h>
#include<stdio.h>

//#pragma comment(lib, "ws2_32.lib") 或在VS中项目-属性-链接器-输入-附加


int main()
{
	// 启动windows socket 2.x环境
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	WSAStartup(ver, &dat);

	//---------------Socket TCP客户端---------------------------
	// 1. 建立一个socket
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, 0);
	if (_sock == INVALID_SOCKET)
	{
		printf("error: 建立socket失败！\n");
	}
	else
	{
		printf("建立socket成功...\n");
	}

	// 2. 连接服务器connect
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567);
	_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	int connect_ret = connect(_sock, (sockaddr*) & _sin, sizeof(sockaddr_in));
	if (connect_ret == SOCKET_ERROR)
	{
		printf("connet error: 连接失败...\n");
	}
	else
	{
		printf("连接成功...\n");
	}
	
	// 3. 接收服务器信息recv
	char recvBuf[256] = {};
	int nlen = recv(_sock, recvBuf, 256, 0);
	if (nlen > 0)
	{
		printf("接收到的数据： %s\n", recvBuf);
	}

	
	// 4. 关闭socket closesocket
	closesocket(_sock);
	//---------------------------------------------------------

	// 清除windows socket环境
	WSACleanup();

	getchar();
	return 0;
}