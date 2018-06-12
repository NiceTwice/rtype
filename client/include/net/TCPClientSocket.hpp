//
// TCPClientSocket.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/include
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

#include <SFML/Network.hpp>
#include "net/IClientSocket.hpp"

class TCPClientSocket : public IClientSocket
{
public:
	TCPClientSocket();
	TCPClientSocket(const std::string &, uint16_t);
	~TCPClientSocket();

public:
	bool connect();
	void disconnect();
	int64_t recv(void *, uint64_t, int = 0);
	int64_t send(const void *, uint64_t, int = 0);

public:
	void setBlocking(bool);
	
public:
	sf::Socket &getSocket();
	void setIp(const std::string &);
	const std::string &getIp() const;
	void setPort(uint16_t);
	uint16_t getPort() const;

private:
	sf::TcpSocket _socket;
	std::string _ip;
	uint16_t _port;
};