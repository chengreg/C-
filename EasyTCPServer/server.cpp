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

	/*----------------Socket TCP�����-------------------------*/
	//1. ����һ��socket
	SOCKET _sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//2. bind�����ڽ��տͻ������ӵ�����˿�
	sockaddr_in _sin = {};
	_sin.sin_family = AF_INET;	//IPV4
	_sin.sin_port = htons(4567); // �˿ں�
	_sin.sin_addr.S_un.S_addr = INADDR_ANY; //IP��ָ��д����= inet_addr("127.0.0.1")

	if (bind(_sock, (sockaddr*)&_sin, sizeof(_sin)) == SOCKET_ERROR)
	{
		printf("bind error: ������˿�ʧ��\n");
	}
	else
	{
		printf("������˿ڳɹ�...\n");
	}
	
	//3. listen��������˿�
	if (listen(_sock, 5) == SOCKET_ERROR)
	{
		printf("bind error: ��������˿�ʧ��\n");
	}
	else
	{
		printf("��������˿ڳɹ�...\n");
	}
	
	//4. accept�ȴ����տͻ�������
	sockaddr_in clientAddr = {};
	int nAddrLen = sizeof(sockaddr_in);
	SOCKET _clientSock = INVALID_SOCKET;

	char msgBuf[] = "Hello, I'm Server.";

	while (true)
	{
		_clientSock = accept(_sock, (sockaddr*)&clientAddr, &nAddrLen);
		if (_clientSock == INVALID_SOCKET)
		{
			printf("appect error: ��Ч�ͻ���socket...\n");
		}

		printf("�¿ͻ��˼��룺IP = %s \n", inet_ntoa(clientAddr.sin_addr));

		//5. send��ͻ��˷���һ������
		send(_clientSock, msgBuf, strlen(msgBuf) + 1, 0);
	}

	
	//6. �ر�socket closesocket
	closesocket(_sock);

	/*---------------------------------------------------------- */

	// ���windows socket����
	WSACleanup();

	return 0;
}