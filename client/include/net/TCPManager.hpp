//
// TCPManager.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/include
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

#include "net/IManager.hpp"
#include "net/TCPClientSocket.hpp"

class TCPManager : public IManager
{
public:
	TCPManager();
	~TCPManager();

public:
	bool connect(const std::string &, uint16_t);
	void disconnect();
	void write();
	void read();

public:
	bool isRunning() const;

public:
	TCPClientSocket &getSocket();
	RingBuffer &getInput();
	RingBuffer &getOutput();

private:
	bool _running;
	TCPClientSocket _socket;
	RingBuffer _input;
	RingBuffer _output;
};