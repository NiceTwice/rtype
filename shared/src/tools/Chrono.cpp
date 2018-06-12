//
// Chrono.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Thu Dec 29 22:15:02 2016 Adrien Vasseur
// Last update Thu Dec 29 22:15:02 2016 Adrien Vasseur
//

#include    <chrono>
#include    "tools/Chrono.hpp"

std::uint64_t Chrono::getCurrentTime()
{
  std::chrono::steady_clock::time_point	now = std::chrono::steady_clock::now();
  return ((std::uint64_t) std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count());
}

std::uint64_t Chrono::getDiffTime(std::uint64_t last)
{
  return (Chrono::getCurrentTime() - last);
}