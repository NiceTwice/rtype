//
// IClientSocket.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/includes
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

#include "net/ISocket.h"

class IClientSocket : public ISocket
{
public:
	virtual bool connect(void) = 0;
};