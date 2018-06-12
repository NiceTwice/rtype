//
// RingBuffer.cpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/src/net
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Tue Dec 13 13:14:00 2016 Quentin Guerin
// Last update Tue Dec 13 13:14:02 2016 Quentin Guerin
//

#include <string.h>
#include <iostream>
#include "net/RingBuffer.hpp"

RingBuffer::RingBuffer(void): m_pos(0)
{
}

RingBuffer::~RingBuffer(void)
{
  while (this->m_data.size() > 0) {
    this->m_data.erase(this->m_data.begin());
  }
}

void RingBuffer::insert(const char *data, uint64_t size)
{
  // std::cout << "[RINGBUFFER] Adding " << size << " bytes: `" << std::string(data, size) << "`" << std::endl;
  this->m_data.push_back(std::string(data, size));
  delete[] data;
}

void RingBuffer::insert(std::string const& buffer)
{
  // std::cout << "[RINGBUFFER] Adding " << buffer.size() << " bytes: `" << buffer << "`" << std::endl;
  this->m_data.push_back(buffer);
}

void RingBuffer::_retrieveConsuming(uint64_t& size, char *buffer)
{
  uint64_t i = 0;

  while (i < size) {
    std::string front = this->m_data.front();

    if (this->m_pos >= front.length()) {
      this->m_data.pop_front();
      this->m_pos = 0;
      if (this->m_data.size() > 0)
	front = this->m_data.front();
      else
	break;
    }
    buffer[i] = front[this->m_pos];
    this->m_pos++;
    i++;
  }
  size = i;
}

void RingBuffer::_retrieveNotConsuming(uint64_t& size, char *buffer)
{
  uint64_t i = 0;
  uint64_t pos = this->m_pos;
  std::list<std::string>::const_iterator it;

  it = this->m_data.begin();
  while (i < size) {
    std::string actual = *it;

    if (pos >= actual.length()) {
      pos = 0;
      if (++it == this->m_data.end())
	break;
      else
	actual = *it;
    }
    buffer[i] = actual[pos];
    pos++;
    i++;
  }
  size = i;
}

const char *RingBuffer::retrieve(uint64_t& size, bool consume)
{
  char *buffer = nullptr;

  if (this->m_data.size() <= 0) {
    size = 0;
    return (nullptr);
  }
  try {
    buffer = new char[size * sizeof(char)];
  }
  catch (std::exception const& e) {
    std::cerr << "[ERROR] " << e.what() << std::endl;
    size = 0;
    return (nullptr);
  }
  memset(buffer, 0, size * sizeof(char));
  if (consume == true)
    this->_retrieveConsuming(size, buffer);
  else
    this->_retrieveNotConsuming(size, buffer);
  return (buffer);
}

const char *RingBuffer::retrieveOneLine(uint64_t& size, bool consume)
{
  char *buffer = nullptr;

  if (this->m_data.size() <= 0)
    return (nullptr);
  size = this->m_data.front().length();
  try {
    buffer = new char[size * sizeof(char)];
  }
  catch (std::exception const& e) {
    std::cerr << "[ERROR] " << e.what() << std::endl;
    return (nullptr);
  }
  memcpy(buffer, this->m_data.front().c_str(), size);
  if (consume == true)
    this->m_data.pop_front();
  // std::cerr << "[RINGBUFFER] Retrieving " << size << " bytes: `" << std::string(buffer, size) << "`" << std::endl;
  return (buffer);
}

bool RingBuffer::hasData(void) const
{
  return (this->m_data.size() > 0);
}