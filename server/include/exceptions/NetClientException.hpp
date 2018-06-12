//
// NetClientException.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/server/include/exceptions
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update Thu Dec 22 10:48:03 2016 Quentin Guerin
//

#pragma once

# include <string>

class NetClientException : public std::exception
{
public:
  NetClientException(std::string const &what) throw() : _what(what) {}
  ~NetClientException() throw() {}

  virtual const char *what() const throw() {
    return (this->_what.c_str());
  }

private:
  const std::string _what;
};
