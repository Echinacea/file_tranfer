
#include "packet.h"
using namespace std;
#define buffer_size 1024*1024
#define server_ip "140.125.33.210"
#define tcp_port 1234
void tcp_transfer_file(void)
{

	string confirm;
	char *message;
	message=(char*)malloc(sizeof(char)*buffer_size);
 
    //�}�l Winsock-DLL
    int r;
    WSAData wsaData;
    WORD DLLVersion;
    DLLVersion = MAKEWORD(2,1);
    r = WSAStartup(DLLVersion, &wsaData);
    //�ŧi�� socket �ϥΪ� sockadder_in ���c
    SOCKADDR_IN addr;
    int addlen = sizeof(addr);
 
    //�]�w socket
    SOCKET sConnect;
 
    //AF_INET: internet-family
    //SOCKET_STREAM: connection-oriented socket
    sConnect = socket(AF_INET, SOCK_STREAM, NULL);
 
    //�]�w addr ���
    addr.sin_addr.s_addr = inet_addr(server_ip);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(tcp_port);
    cout << "connect to server?[Y] or [N]" << endl;
	
	cin>>confirm;
	while(1)
	{
			if(confirm == "n")
			{
				exit(1);
			}else
			{

				if(confirm == "y")
				{
					
					connect(sConnect, (SOCKADDR*)&addr, sizeof(addr));
					//���� server �ݪ��T��
					ZeroMemory(message, 777835);
					while(1)
					{
					r = recv(sConnect, message,buffer_size, 0);
					//cout<<"size:"<<r<<endl;
					cout<<message<<endl;

					static int file_name=0;
					file_name++;
					char file_convert[10];
					//========================================
					sprintf(file_convert, "%d.jpg", file_name);
					//========================================
					output_file(file_convert,message,r);
					
					}
					//============================================
					
					
					
					//============================================

				}

			}
			
	}
}
void output_file(char*file_name,char*file_data,long int write_value)
{
	fstream file;
	cout<<"output";
	file.open(file_name,ios::out|ios::binary);
	file.write(file_data,write_value);
	file.close();
}
