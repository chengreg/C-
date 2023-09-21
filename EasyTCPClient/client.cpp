// 2023.09.21

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#define WIN32_LEAN_AND_MEAN
#include<WinSock2.h>
#include<Windows.h>
#include<stdio.h>

//#pragma comment(lib, "ws2_32.lib") ����VS����Ŀ-����-������-����-����


int main()
{
	// ����windows socket 2.x����
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	WSAStartup(ver, &dat);

	//---------------Socket TCP�ͻ���---------------------------
	// 1. ����һ��socket
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, 0);
	if (_sock == INVALID_SOCKET)
	{
		printf("error: ����socketʧ�ܣ�\n");
	}
	else
	{
		printf("����socket�ɹ�...\n");
	}

	// 2. ���ӷ�����connect
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;
	_sin.sin_port = htons(4567);
	_sin.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	int connect_ret = connect(_sock, (sockaddr*) & _sin, sizeof(sockaddr_in));
	if (connect_ret == SOCKET_ERROR)
	{
		printf("connet error: ����ʧ��...\n");
	}
	else
	{
		printf("���ӳɹ�...\n");
	}
	
	// 3. ���շ�������Ϣrecv
	char recvBuf[256] = {};
	int nlen = recv(_sock, recvBuf, 256, 0);
	if (nlen > 0)
	{
		printf("���յ������ݣ� %s\n", recvBuf);
	}

	
	// 4. �ر�socket closesocket
	closesocket(_sock);
	//---------------------------------------------------------

	// ���windows socket����
	WSACleanup();

	getchar();
	return 0;
}