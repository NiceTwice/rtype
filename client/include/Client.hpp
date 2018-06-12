//
// Client.hpp for rtype in /home/lanquemar/rendu/rtype/client/include/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 11:09:05 2016 Adrien Vasseur
// Last update Thu Dec  1 14:56:17 2016 Adrien Vasseur
//

#pragma		once

#include	<string>

class		Client
{
public:
  Client();
  ~Client();

  bool		exec();
  bool		initNetwork(const std::string &, uint16_t);
};
