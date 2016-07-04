#pragma once
#include<iostream>
#include<pthread.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<error.h>
#include<string>
#include<unistd.h>
#include<stdlib.h>
#include "comm.h"
#include<vector>


#define DEFAULT_IP "127.0.0.1"
#define DEFAULT_PORT 8080
using namespace std;

typedef struct user_data
{
	string _user_ip;
	short _user_port;
}u_data,*pu_data;

class udp_server
{
	public:
		//构造函数
		udp_server(string ip=DEFAULT_IP,short port=DEFAULT_PORT);

		//析构函数
		~udp_server();
		//初始化服务器
		void server_init();
		//接收消息
		bool recv_msg();
		//发送消息
		bool send_msg();
		//广播消息
		bool boradcast_msg();
	private:
		std::vector<u_data> _boradcast_list;//广播消息存储容器
		
		u_data _now_data;//结构体
		int _sock;//sock
		string _msg;//当前接收消息
		//short _port;//端口
		//string _ip//IP地址
};

