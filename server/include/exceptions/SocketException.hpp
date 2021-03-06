//
// SocketException.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/server/include/exceptions
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma		once

#include 	<string>

class SocketException : public std::exception
{
public:
  SocketException(std::string const &what) throw() : _what(what) {}
  ~SocketException() throw() {}

  virtual const char *what() const throw() {
    return (this->_what.c_str());
  }

private:
  const std::string _what;
};