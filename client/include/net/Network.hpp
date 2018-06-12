//
// Network.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/include
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

#include <string>
#include "thread/AStdThread.hpp"
#include "net/TCPManager.hpp"
#include "net/UDPManager.hpp"

class Network : public AStdThread
{
public:
	static Network &getInstance();

public:
	Network();
	~Network();
	Network(const Network&) {}
	Network &operator=(const Network&) {}

public:
	bool init();
	void destroy();
	void onError(const std::string &);
	bool tcpConnect(const std::string &, uint16_t);
	uint16_t udpListen(const std::string &);
	bool udpConnect(const std::string &, uint16_t);
	void run();
	void ready(bool);

public:
	const std::string &getServerIp();

private:
	void write(IManager &);
	void read(IManager &);

private:
	static Network _instance;
	std::string _serverIp;
	TCPManager _tcpManager;
	UDPManager _udpManager;
};