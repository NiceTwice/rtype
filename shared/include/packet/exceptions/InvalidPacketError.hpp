//
// InvalidPacketError.hpp for cpp_babel in /home/lanquemar/rendu/cpp_babel/Shared/include/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Fri Nov 11 12:33:25 2016 Adrien Vasseur
// Last update Fri Nov 11 12:37:24 2016 Adrien Vasseur
//

#pragma		once

#include	<exception>
#include	<string>

class		InvalidPacketError : public std::exception
{
public:
  InvalidPacketError(const std::string &err) : _err(err) {}
  ~InvalidPacketError() throw() {}

  const char	*what() const throw() { return (this->_err.c_str()); }

private:
  std::string	_err;
};
