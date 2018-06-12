//
// ArgumentParser.hpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/include/exceptions
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Tue Nov 29 11:07:46 2016 Quentin Guerin
// Last update Wed Nov 30 13:56:16 2016 Quentin Guerin
//

#pragma		once

#include 	<string>

class ArgumentParserException : public std::exception
{
public:
  ArgumentParserException(std::string const &what) throw() : _what(what) {}
  ~ArgumentParserException() throw() {}

  virtual const char *what() const throw() {
    return (this->_what.c_str());
  }

private:
  const std::string _what;
};