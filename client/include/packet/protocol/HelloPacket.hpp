//
// HelloPacket.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/include/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

#include "packet/protocol/IProtocol.hpp"

#define RTYPE_VERSION 0.1f

class HelloPacket : public IProtocol
{
public:
	HelloPacket();
	~HelloPacket();

public:
	bool process(IManager &, PacketDeserializer &);
};