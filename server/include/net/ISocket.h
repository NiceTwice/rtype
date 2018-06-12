//
// ISocket.h for rtype in /home/blazer/Epitech/Rendu/rtype/server/includes
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update Thu Dec 22 14:10:38 2016 Quentin Guerin
//

#pragma once

# include <cstdlib>

# include "net/ANetClient.hpp"

class ISocket
{
public:
  virtual ~ISocket() {}

public:
  virtual bool init(void) = 0;
  virtual bool run(void) = 0;
  virtual bool stop(void) = 0;

  virtual int64_t recv(void *, uint64_t, int) = 0;
  virtual int64_t send(const void *, uint64_t, int) = 0;
};
