//
// PacketSerializer.cpp for cpp_babel in /home/vasseu_g/rendu/cpp_babel/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Oct 12 11:51:39 2016 Adrien Vasseur
// Last update Fri Nov 11 12:51:04 2016 Adrien Vasseur
//

#include	<iostream>
#include	"packet/PacketSerializer.hpp"

PacketSerializer::PacketSerializer(): _bytearray(new unsigned char[1500]), _size(1500), _pos(0)
{
}

PacketSerializer::~PacketSerializer()
{
  delete [] this->_bytearray;
}

unsigned char		*PacketSerializer::pack(std::uint16_t packetId, std::uint64_t &totalSize)
{
  unsigned char		*packet;
  std::uint8_t		lengthSize;
  std::uint16_t		headerHigh;
  std::uint64_t		pos;
  std::uint64_t		tmpPos;

  lengthSize = 0;
  pos = 0;
  if (this->_pos > 65535)
    lengthSize = 3;
  else if (this->_pos > 255)
    lengthSize = 2;
  else if (this->_pos != 0)
    lengthSize = 1;
  totalSize = 2 + lengthSize + this->_pos;
  packet = new unsigned char [totalSize];
  headerHigh = (packetId << 2) | lengthSize;
  packet[pos++] = (unsigned char)(headerHigh & 0xFF);
  packet[pos++] = (unsigned char)((headerHigh >> 8) & 0xFF);
  for (tmpPos = 0; tmpPos < lengthSize; tmpPos++)
    packet[pos++] = (unsigned char)((this->_pos >> (tmpPos * 8)) & 0xFF);
  for (tmpPos = 0; tmpPos < this->_pos; tmpPos++)
    packet[pos++] = this->_bytearray[tmpPos];
  return (packet);
}

PacketSerializer	&PacketSerializer::operator<<(const PacketSerializer &packet)
{
  this->write(packet.getBuffer(), packet.getPos());
  return (*this);
}

PacketSerializer	&PacketSerializer::operator<<(std::string &data)
{
  std::uint64_t		stringSize;

  stringSize = data.size();
  this->write(&stringSize, 8);
  this->write(data.c_str(), data.size());
  return (*this);
}

PacketSerializer	&PacketSerializer::operator<<(std::uint64_t data)
{
  this->write(&data, 8);
  return (*this);
}

PacketSerializer  &PacketSerializer::operator<<(std::int64_t data)
{
  this->write(&data, 8);
  return (*this);
}

PacketSerializer  &PacketSerializer::operator<<(std::uint32_t data)
{
  this->write(&data, 4);
  return (*this);
}

PacketSerializer  &PacketSerializer::operator<<(std::int32_t data)
{
  this->write(&data, 4);
  return (*this);
}

PacketSerializer	&PacketSerializer::operator<<(std::uint16_t data)
{
  this->write(&data, 2);
  return (*this);
}

PacketSerializer  &PacketSerializer::operator<<(std::int16_t data)
{
  this->write(&data, 2);
  return (*this);
}

PacketSerializer	&PacketSerializer::operator<<(std::uint8_t data)
{
  this->write(&data, 1);
  return (*this);
}

PacketSerializer  &PacketSerializer::operator<<(std::int8_t data)
{
  this->write(&data, 1);
  return (*this);
}

PacketSerializer  &PacketSerializer::operator<<(bool data)
{
  this->write(&data, sizeof(bool));
  return (*this);
}

PacketSerializer  &PacketSerializer::operator<<(float data)
{
  this->write(&data, sizeof(float));
  return (*this);
}

PacketSerializer  &PacketSerializer::operator<<(double data)
{
  this->write(&data, sizeof(double));
  return (*this);
}

PacketSerializer &PacketSerializer::operator<<(Vector2f data)
{
  (*this) << data.getX() << data.getY();
  return (*this);
}

void			PacketSerializer::expandBuffer()
{
  unsigned char		*newbuff;
  unsigned int		i;

  this->_size *= 2;
  newbuff = new unsigned char[this->_size];
  for (i = 0; i < this->_pos; i++)
    newbuff[i] = this->_bytearray[i];
  delete [] this->_bytearray;
  this->_bytearray = newbuff;
}

void			PacketSerializer::write(const void *data, std::uint64_t size)
{
  std::uint64_t	i;

  while (this->_pos + size >= this->_size)
    this->expandBuffer();
  for (i = 0; i < size; i++)
    this->_bytearray[this->_pos++] = (unsigned char)(((const char *) data)[i]);
}

unsigned char	*PacketSerializer::getBuffer() const
{
  return (this->_bytearray);
}

std::uint64_t	PacketSerializer::getSize() const
{
  return (this->_size);
}

std::uint64_t	PacketSerializer::getPos() const
{
  return (this->_pos);
}
