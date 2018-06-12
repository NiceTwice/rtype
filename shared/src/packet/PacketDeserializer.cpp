//
// PacketDeserializer.cpp for cpp_babel in /home/vasseu_g/rendu/cpp_babel/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Oct 12 14:00:35 2016 Adrien Vasseur
// Last update Fri Nov 11 12:51:38 2016 Adrien Vasseur
//

#include <sstream>
#include "packet/PacketDeserializer.hpp"
#include "packet/exceptions/InvalidPacketError.hpp"

PacketDeserializer::PacketDeserializer(): _bytearray(nullptr), _size(0), _pos(0), _packetId(0)
{
}

PacketDeserializer::~PacketDeserializer()
{
}

std::uint16_t PacketDeserializer::parseLenghtSize(const unsigned char *packet)
{
  std::uint16_t headerHigh;

  headerHigh = packet[0];
  headerHigh |= (packet[1] << 8);
  return (headerHigh & 3);
}

std::uint64_t PacketDeserializer::parseContentSize(const unsigned char *packet)
{
  std::uint64_t i;
  std::uint64_t lengthSize;
  std::uint64_t contentSize;

  contentSize = 0;
  lengthSize = this->parseLenghtSize(packet);
  for (i = 0; i < lengthSize; i++)
    contentSize |= packet[i + 2] << (i * 8);
  return (contentSize);
}

std::uint16_t PacketDeserializer::unpack(const unsigned char *packet)
{
  std::uint8_t lengthSize;
  std::uint16_t headerHigh;
  std::uint64_t tmpPos;

  this->_pos = 0;
  this->_size = 0;
  this->_bytearray = packet;
  headerHigh = packet[this->_pos++];
  headerHigh |= (packet[this->_pos++] << 8);
  lengthSize = headerHigh & 3;
  this->_packetId = headerHigh >> 2;
  for (tmpPos = 0; tmpPos < lengthSize; tmpPos++)
    this->_size |= packet[this->_pos++] << (tmpPos * 8);
  this->_size += this->_pos;
  return (this->_packetId);
}

PacketDeserializer &PacketDeserializer::operator>>(std::string &data)
{
  std::uint64_t i;
  std::uint64_t size;
  std::uint8_t c;

  (*this) >> size;
  if (this->_pos + size > this->_size)
    throw InvalidPacketError("Malformed packet");
  data.resize(size);
  for (i = 0; i < size; i++)
    {
      (*this) >> c;
      data[i] = c;
    }
  return (*this);
}

PacketDeserializer &PacketDeserializer::operator>>(std::uint64_t &data)
{
  data = 0;
  this->read(&data, 8);
  return (*this);
}

PacketDeserializer &PacketDeserializer::operator>>(std::int64_t &data)
{
  data = 0;
  this->read(&data, 8);
  return (*this);
}

PacketDeserializer &PacketDeserializer::operator>>(std::uint32_t &data)
{
  data = 0;
  this->read(&data, 4);
  return (*this);
}

PacketDeserializer &PacketDeserializer::operator>>(std::int32_t &data)
{
  data = 0;
  this->read(&data, 4);
  return (*this);
}

PacketDeserializer &PacketDeserializer::operator>>(std::uint16_t &data)
{
  data = 0;
  this->read(&data, 2);
  return (*this);
}

PacketDeserializer &PacketDeserializer::operator>>(std::int16_t &data)
{
  data = 0;
  this->read(&data, 2);
  return (*this);
}

PacketDeserializer &PacketDeserializer::operator>>(std::uint8_t &data)
{
  data = 0;
  this->read(&data, 1);
  return (*this);
}

PacketDeserializer &PacketDeserializer::operator>>(std::int8_t &data)
{
  data = 0;
  this->read(&data, 1);
  return (*this);
}

PacketDeserializer &PacketDeserializer::operator>>(bool &data)
{
  data = 0;
  this->read(&data, sizeof(bool));
  return (*this);
}

PacketDeserializer &PacketDeserializer::operator>>(float &data)
{
  data = 0;
  this->read(&data, sizeof(float));
  return (*this);
}

PacketDeserializer &PacketDeserializer::operator>>(double &data)
{
  data = 0;
  this->read(&data, sizeof(double));
  return (*this);
}

PacketDeserializer &PacketDeserializer::operator>>(Vector2f &data)
{
  float x = 0;
  float y = 0;

  (*this) >> x >> y;
  data.setX(x);
  data.setY(y);
  return (*this);
}

void PacketDeserializer::read(void *data, std::uint64_t size)
{
  std::uint64_t i;

  if (this->_pos + size > this->_size) {
    throw InvalidPacketError("Malformed packet");
  }
  for (i = 0; i < size; i++)
    ((char *) data)[i] = this->_bytearray[this->_pos++];
}

std::uint16_t PacketDeserializer::getPacketId() const
{
  return (this->_packetId);
}

std::uint64_t PacketDeserializer::getPacketSize() const
{
  return (this->_size - this->_pos);
}

std::string PacketDeserializer::toString(void) const
{
  std::stringstream ss;

  ss << "PacketDeserializer { id: " << this->_packetId << ", size: " << this->_size - this->_pos;
  ss << ", data: " << (this->_bytearray == nullptr ?
		       "NULL" : std::string(reinterpret_cast<const char *>(this->_bytearray), this->_size)) << " }";
  return (ss.str());
}

std::ostream& operator<<(std::ostream& o, PacketDeserializer const& packetDeserializer)
{
  o << packetDeserializer.toString();
  return (o);
}