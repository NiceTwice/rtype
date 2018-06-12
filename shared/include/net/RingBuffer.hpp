//
// RingBuffer.hpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/include/net/ringBuffer
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Tue Dec 13 11:57:22 2016 Quentin Guerin
// Last update Tue Dec 13 11:57:22 2016 Quentin Guerin
//

#pragma once

# include <cstdlib>
# include <string>
# include <list>

class RingBuffer
{
public:
  RingBuffer();
  ~RingBuffer();

public:
  void insert(const char *, uint64_t);
  void insert(std::string const&);
  const char *retrieve(uint64_t&, bool = true);
  const char *retrieveOneLine(uint64_t&, bool = true);
  bool hasData(void) const;

private:
  void _retrieveConsuming(uint64_t&, char *);
  void _retrieveNotConsuming(uint64_t&, char *);

private:
  uint64_t m_pos;
  std::list<std::string> m_data;
};