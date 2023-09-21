// 2023.09.21


#define WIN32_LEAN_AND_MEAN
#include<WinSock2.h>
#include<Windows.h>

//#pragma comment(lib, "ws2_32.lib") 或在VS中项目-属性-链接器-输入-附加


int main()
{
	// 启动windows socket 2.x环境
	WORD ver = MAKEWORD(2, 2);
	WSADATA dat;
	WSAStartup(ver, &dat);

	//---------------Socket TCP客户端---------------------------
	// 1. 建立一个socket
	// 2. 连接服务器connect
	// 3. 接收服务器信息recv
	// 4. 关闭socket closesocket
	//---------------------------------------------------------

	//----------------Socket TCP服务端--------------------------
	// 1. 建立一个socket
	// 2. bind绑定用于接收客户端连接的网络端口
	// 3. listen监听网络端口
	// 4. accept等待接收客户端连接
	// 5. send向客户端发送一条数据
	// 6. 关闭socket closesocket
	//---------------------------------------------------------

	// 清除windows socket环境
	WSACleanup();

	return 0;
}