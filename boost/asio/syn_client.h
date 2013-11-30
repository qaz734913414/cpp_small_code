#pragma once
#include <iostream>
#include <boost/asio.hpp>

void runClient(){

	using namespace boost::asio;

	// ����asio�඼��Ҫio_service����
	io_service iosev;
	// socket����
	ip::tcp::socket socket(iosev);
	// ���Ӷ˵㣬����ʹ���˱������ӣ������޸�IP��ַ����Զ������
	ip::tcp::endpoint ep(ip::address_v4::from_string("127.0.0.1"), 1000);
	// ���ӷ�����
	boost::system::error_code ec;
	socket.connect(ep,ec);
	// ���������ӡ������Ϣ
	if(ec)
	{
		std::cout << boost::system::system_error(ec).what() << std::endl;
		return ;
	}
	// ��������
	char buf[100];
	size_t len=socket.read_some(buffer(buf), ec);
	std::cout.write(buf, len);
}