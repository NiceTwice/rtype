//
// LoadManagerException.hpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/include/exceptions
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Tue Nov 29 11:07:46 2016 Quentin Guerin
// Last update Sat Dec 31 11:23:07 2016 Quentin Guerin
//

#pragma		once

#include 	<string>

class LoadManagerException : public std::exception
{
public:
  LoadManagerException(std::string const &what) throw() : _what(what) {}
  ~LoadManagerException() throw() {}

  virtual const char *what() const throw() {
    return (this->_what.c_str());
  }

private:
  const std::string _what;
};
