#pragma comment(lib, "Ws2_32.lib")
#include <WinSock2.h>
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>

void tcp_transfer_file(void);

void output_file(char*file_name,char*file_data,long int write_value);