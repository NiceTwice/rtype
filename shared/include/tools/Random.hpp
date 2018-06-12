//
// Random.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Thu Dec 15 15:31:58 2016 Adrien Vasseur
// Last update Thu Dec 15 15:31:58 2016 Adrien Vasseur
//

#pragma   once

#include "tools/Singleton.hpp"

class     Random : public Singleton<Random>
{
public:
  Random();
  ~Random();

  int         integer(int, int) const;
  static int  getNextInteger(int, int);
};