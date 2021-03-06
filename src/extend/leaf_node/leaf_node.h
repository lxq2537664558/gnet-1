#pragma once

#include "../commom/pre_header.h"
#include "../commom/net/client_session.h"

namespace gnet {

class leaf_node
{
public:
	leaf_node();
	leaf_node(const char* ip,uint32 port, uint32 timeout);
	~leaf_node();

	void set_gateway_addr(const char* ip, uint32 port, uint32 timeout);
	void start();
	void stop();
	void set_net_msg_handler(std::function<void(data_packet*)>& handler);
	void set_session_state_change_handler(std::function<void(bool)>& handler);
	std::shared_ptr<client_session>& get_session();
	void set_do_heart_beat(bool is_do);
private:
	std::string m_gateway_ip;
	uint32 	m_gateway_port;
	std::shared_ptr<client_session> m_client_session_sp;
};

};