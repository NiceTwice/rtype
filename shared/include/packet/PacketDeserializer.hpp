//
// PacketDeserializer.hpp for cpp_babel in /home/vasseu_g/rendu/cpp_babel/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Oct 12 14:00:50 2016 Adrien Vasseur
// Last update Wed Nov  9 19:15:00 2016 Adrien Vasseur
//

#pragma once

#include <string>
#include <iostream>
#include "game/Vector2f.hpp"

class PacketDeserializer
{
public:
  PacketDeserializer();
  ~PacketDeserializer();

  std::uint16_t parseLenghtSize(const unsigned char *);
  std::uint64_t parseContentSize(const unsigned char *);
  std::uint16_t unpack(const unsigned char *);

  PacketDeserializer &operator>>(std::string &);
  PacketDeserializer &operator>>(std::uint64_t &);
  PacketDeserializer &operator>>(std::uint32_t &);
  PacketDeserializer &operator>>(std::uint16_t &);
  PacketDeserializer &operator>>(std::uint8_t &);
  PacketDeserializer &operator>>(std::int64_t &);
  PacketDeserializer &operator>>(std::int32_t &);
  PacketDeserializer &operator>>(std::int16_t &);
  PacketDeserializer &operator>>(std::int8_t &);
  PacketDeserializer &operator>>(bool &);
  PacketDeserializer &operator>>(double &);
  PacketDeserializer &operator>>(float &);
  PacketDeserializer &operator>>(Vector2f &);
  std::string toString() const;

  std::uint16_t getPacketId() const;
  std::uint64_t getPacketSize() const;

private:
  void read(void *, std::uint64_t);

  const unsigned char *_bytearray;
  std::uint64_t _size;
  std::uint64_t _pos;
  std::uint16_t _packetId;
};

std::ostream& operator<<(std::ostream&, PacketDeserializer const&);