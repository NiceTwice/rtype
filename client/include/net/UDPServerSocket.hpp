//
// UDPServerSocket.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/include
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

#include <SFML/Network.hpp>
#include "net/IServerSocket.hpp"

class UDPServerSocket : public IServerSocket
{
public:
	UDPServerSocket();
	UDPServerSocket(const std::string &, uint16_t);
	~UDPServerSocket();

public:
	bool bind();
	bool listen();
	int64_t recv(void *, uint64_t, int = 0);
	int64_t send(const void *, uint64_t, int = 0);

public:
	void setBlocking(bool);
	
public:
	sf::Socket &getSocket();
	void setIp(const std::string &);
	const std::string getIp() const;
	void setPort(uint16_t);
	uint16_t getPort() const;

private:
	sf::UdpSocket _socket;
	sf::IpAddress _ip;
	uint16_t _port;
};