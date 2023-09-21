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

	/*----------------Socket TCP服务端-------------------------*/
	//1. 建立一个socket
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//2. bind绑定用于接收客户端连接的网络端口
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;	//IPV4
	_sin.sin_port = htons(4567); // 端口号
	_sin.sin_addr.S_un.S_addr = INADDR_ANY; //IP，指定写法：= inet_addr("127.0.0.1")

	if (bind(_sock, (sockaddr*)&_sin, sizeof(_sin)) == SOCKET_ERROR)
	{
		printf("bind error: 绑定网络端口失败\n");
	}
	else
	{
		printf("绑定网络端口成功...\n");
	}
	
	//3. listen监听网络端口
	if (listen(_sock, 5) == SOCKET_ERROR)
	{
		printf("bind error: 监听网络端口失败\n");
	}
	else
	{
		printf("监听网络端口成功...\n");
	}
	
	//4. accept等待接收客户端连接
	sockaddr_in clientAddr = {};
	int nAddrLen = sizeof(sockaddr_in);
	SOCKET _clientSock = INVALID_SOCKET;

	char msgBuf[] = "Hello, I'm Server.";

	_clientSock = accept(_sock, (sockaddr*)&clientAddr, &nAddrLen);
	if (_clientSock == INVALID_SOCKET)
	{
		printf("appect error: 无效客户端socket...\n");
	}

	printf("新客户端加入：Socket = %d, IP = %s \n", (int)_clientSock, inet_ntoa(clientAddr.sin_addr));

	char _recvBuf[128] = {};
	while (true)
	{
		// 5. 接收客户端数据
		int nLen = recv(_clientSock, _recvBuf, 128, 0);
		if (nLen <= 0)
		{
			printf("客户端退出，任务结束\n");
			break;
		}

		printf("接收到客户端数据：%s \n", _recvBuf);

		// 6. 处理请求
		if (strcmp(_recvBuf, "getName") == 0)
		{
			char msgBuf[] = "小明";
			//7. send向客户端发送一条数据
			send(_clientSock, msgBuf, strlen(msgBuf) + 1, 0);
		}
		else if (strcmp(_recvBuf, "getAge") == 0)
		{
			char msgBuf[] = "80";
			//7. send向客户端发送一条数据
			send(_clientSock, msgBuf, strlen(msgBuf) + 1, 0);

		}
		else
		{
			char msgBuf[] = "???";
			//7. send向客户端发送一条数据
			send(_clientSock, msgBuf, strlen(msgBuf) + 1, 0);
		}


		
	}

	
	//8. 关闭socket closesocket
	closesocket(_sock);

	/*---------------------------------------------------------- */

	// 清除windows socket环境
	WSACleanup();

	return 0;
}