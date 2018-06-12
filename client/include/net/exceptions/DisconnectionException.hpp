//
// DisconnectionException.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/include
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma		once

#include	<exception>
#include	<string>

class		DisconnectionException : public std::exception
{
public:
  DisconnectionException(const std::string &err) : _err(err) {}
  ~DisconnectionException() throw() {}

  const char	*what() const throw() { return (this->_err.c_str()); }

private:
  std::string	_err;
};
