#pragma once

#include <stdio.h>  
#include <windows.h> 
#include <string>
#pragma comment(lib, "ws2_32.lib")

class M_Client
{
public:
	//Constructor  
	M_Client(const char* Addr, int Port, int Id);
	//����  
	int Connect();
	//����TCP��  
	int SendMsg(const char* msg, int len);
	//����TCP��
	int M_Client::RecvMsg();
	//�ر�  
	void Close();
	//����modbus��  
	void Modbus_sender_single(int Ref, int addr, int value);

private:
	SOCKET m_sock;
	int port;
	const char* address;
	int id;
};

