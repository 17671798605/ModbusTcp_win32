#include "M_Client.h"  
#include<Windows.h>
#include<iostream>
#include <conio.h>


VOID CALLBACK TimerProc(HWND hwnd,UINT uMsg,UINT idEvent,DWORD dwTime)
{
	std::cout << "H" << std::endl;
	
}


int main()
{
	std::cout << "��ȡ%MW0�����ݣ���Esc���˳�" << std::endl;
	int connect_error;
	M_Client client("192.168.1.223", 502, 1);
	printf("Waiting to connection\n");
	connect_error = client.Connect();
	unsigned char buf[12];
	buf[0] = 0;
	buf[1] = 0;
	buf[2] = 0;
	buf[3] = 0;
	buf[4] = 0;
	buf[5] = 6;
	buf[6] = 1;//�ӻ�ID  
	buf[7] = 3;//�������  
	buf[8] = 0;
	buf[9] = 0;
	buf[10] = 0;
	buf[11] = 2;
	bool end1 = true;
	while (end1)
	{
		if (connect_error == 0)
		{
			client.SendMsg((char*)buf, 12);
			client.RecvMsg();
			Sleep(4);
			if (GetAsyncKeyState(VK_ESCAPE))
			{
				end1 = false;
			}
		}
	}
		

	
	system("pause");
	client.Close();
	return 0;
}