//
// Random.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Thu Dec 15 15:35:16 2016 Adrien Vasseur
// Last update Thu Dec 15 15:35:16 2016 Adrien Vasseur
//

#include    <cstdlib>
#include    <ctime>
#include    "tools/Random.hpp"

template<> Random*	Singleton<Random>::INSTANCE = new Random();

Random::Random()
{
  std::srand((unsigned int) std::time(NULL));
}

Random::~Random()
{

}

int     Random::integer(int a, int b) const
{
  if (a < b)
    return (std::rand() % (b - a) + a);
  return (0);
}

int     Random::getNextInteger(int a, int b)
{
  return (Random::getInstance().integer(a, b));
}