//
// INetClient.hpp for rtype in /home/lanquemar/rendu/rtype/shared/include/net/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 12:10:13 2016 Adrien Vasseur
// Last update Wed Nov 30 12:11:53 2016 Adrien Vasseur
//

#pragma once

# include <cstdlib>
# include <string>
# include <cstdint>

class INetClient
{
public:
  virtual ~INetClient() {}

  virtual bool connect(const std::string & = "", unsigned short const& = 0) = 0;
  virtual void disconnect(void) = 0;
};
