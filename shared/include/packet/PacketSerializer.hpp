//
// PacketSerializer.hpp for cpp_babel in /home/vasseu_g/rendu/cpp_babel/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Oct 12 11:51:55 2016 Adrien Vasseur
// Last update Thu Nov 10 14:00:30 2016 Adrien Vasseur
//

#pragma once

#include <cstdint>
#include <string>
#include "game/Vector2f.hpp"


class PacketSerializer
{
public:
  PacketSerializer();
  ~PacketSerializer();

  unsigned char *pack(std::uint16_t, std::uint64_t &);

  PacketSerializer &operator<<(const PacketSerializer &);
  PacketSerializer &operator<<(std::string &);
  PacketSerializer &operator<<(std::uint64_t);
  PacketSerializer &operator<<(std::uint32_t);
  PacketSerializer &operator<<(std::uint16_t);
  PacketSerializer &operator<<(std::uint8_t);
  PacketSerializer &operator<<(std::int64_t);
  PacketSerializer &operator<<(std::int32_t);
  PacketSerializer &operator<<(std::int16_t);
  PacketSerializer &operator<<(std::int8_t);
  PacketSerializer &operator<<(bool);
  PacketSerializer &operator<<(float);
  PacketSerializer &operator<<(double);
  PacketSerializer &operator<<(Vector2f);

  unsigned char *getBuffer() const;
  std::uint64_t getSize() const;
  std::uint64_t getPos() const;

private:
  void expandBuffer();
  void write(const void *, std::uint64_t);

  unsigned char *_bytearray;
  std::uint64_t _size;
  std::uint64_t _pos;
};
