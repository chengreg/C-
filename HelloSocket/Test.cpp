// 2023.09.21


#define WIN32_LEAN_AND_MEAN
#include<WinSock2.h>
#include<Windows.h>

//#pragma comment(lib, "ws2_32.lib") ����VS����Ŀ-����-������-����-����


int main()
{
	// ����windows socket 2.x����
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	WSAStartup(ver, &dat);

	//---------------Socket TCP�ͻ���---------------------------
	// 1. ����һ��socket
	// 2. ���ӷ�����connect
	// 3. ���շ�������Ϣrecv
	// 4. �ر�socket closesocket
	//---------------------------------------------------------

	//----------------Socket TCP�����--------------------------
	// 1. ����һ��socket
	// 2. bind�����ڽ��տͻ������ӵ�����˿�
	// 3. listen��������˿�
	// 4. accept�ȴ����տͻ�������
	// 5. send��ͻ��˷���һ������
	// 6. �ر�socket closesocket
	//---------------------------------------------------------

	// ���windows socket����
	WSACleanup();

	return 0;
}