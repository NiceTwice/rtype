//
// IManager.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/includes
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

#include "net/RingBuffer.hpp"

class IManager
{
public:
	virtual void write() = 0;
	virtual void read() = 0;

public:
	virtual RingBuffer &getInput() = 0;
	virtual RingBuffer &getOutput() = 0;
};