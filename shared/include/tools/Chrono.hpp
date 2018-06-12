//
// Chrono.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Thu Dec 29 22:13:55 2016 Adrien Vasseur
// Last update Thu Dec 29 22:13:55 2016 Adrien Vasseur
//

#pragma   once

#include  <cstdint>

class     Chrono
{
public:
  static  std::uint64_t   getCurrentTime();
  static  std::uint64_t   getDiffTime(std::uint64_t);
};