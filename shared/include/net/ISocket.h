//
// ISocket.h for rtype in /home/blazer/Epitech/Rendu/rtype/server/includes
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

# include <cstdlib>
# include <cstdint>

class ISocket
{
public:
  virtual ~ISocket() {}

public:
  virtual int64_t recv(void *, uint64_t, int) = 0;
  virtual int64_t send(const void *, uint64_t, int) = 0;
};