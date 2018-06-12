//
// UDPManager.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/include
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

#include "net/IManager.hpp"
#include "net/UDPClientSocket.hpp"
#include "net/UDPServerSocket.hpp"

class UDPManager : public IManager
{
public:
	UDPManager();
	~UDPManager();

public:
	bool connectClient(const std::string &, uint16_t);
	uint16_t runServer(const std::string &);
	void disconnect();
	void write();
	void read();

public:
	bool isServerRunning() const;
	bool isClientRunning() const;
	
public:
	const UDPClientSocket &getClientSocket() const;
	UDPServerSocket &getServerSocket();
	RingBuffer &getInput();
	RingBuffer &getOutput();

private:
	bool _clientRunning;
	bool _serverRunning;
	UDPClientSocket _clientSocket;
	UDPServerSocket _serverSocket;
	RingBuffer _input;
	RingBuffer _output;
};