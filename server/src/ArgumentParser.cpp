//
// ArgumentParser.cpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/src
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Tue Nov 29 11:07:46 2016 Quentin Guerin
// Last update Thu Dec 01 15:25:44 2016 Quentin Guerin
//

#include "ArgumentParser.hpp"

ArgumentParser::ArgumentParser(int count, char **arguments, char **environment): _count(count)
{
  int i;
  unsigned long pos;

  for (i = 1; i < count; i++) {
    this->_arguments.emplace_back(arguments[i]);
  }

  for (i = 0; environment != nullptr && environment[i] != nullptr; i++) {
    std::string environmentLine(environment[i]);

    if ((pos = environmentLine.find('=')) != std::string::npos)
      this->_environment[environmentLine.substr(0, pos)] = environmentLine.substr(pos + 1, std::string::npos);
  }
}

ArgumentParser::~ArgumentParser(void)
{
  this->_arguments.clear();
  this->_environment.clear();
}

int const& ArgumentParser::getArgumentCount(void) const
{
  return (this->_count);
}

std::vector<std::string> const& ArgumentParser::getArguments(void) const
{
  return (this->_arguments);
}

std::map<std::string, std::string> const& ArgumentParser::getEnvironment(void) const
{
  return (this->_environment);
}

std::string const& ArgumentParser::getEnvironmentValue(std::string const& key) const throw(ArgumentParserException)
{
  try {
    return (this->_environment.at(key));
  }
  catch (std::exception const& e) {
    throw ArgumentParserException(e.what());
  }
}

void ArgumentParser::_checkFlags(std::string const& flag,
				 std::string const& shortflag) const throw(ArgumentParserException)
{
  if (shortflag.length() > 0 &&
      (shortflag.length() != 2 ||
       shortflag[0] != '-' ||
       std::isalpha(shortflag[1], this->_locale) == false))
    throw ArgumentParserException("Invalid shortflag");
  else if (flag.length() < 3 || flag.substr(0, 2) != "--") {
    throw ArgumentParserException("Invalid flag");
  }
}

bool ArgumentParser::flagExists(bool valued, std::string const& flag,
				std::string const& shortflag) const throw(ArgumentParserException)
{
  std::vector<std::string>::const_iterator it;

  this->_checkFlags(flag, shortflag);
  for (it = this->_arguments.begin(); it != this->_arguments.end(); ++it) {
    if ((*it) == flag || (shortflag.length() == 2 && (*it) == shortflag)) {
      if (valued == true && it + 1 == this->_arguments.end())
	throw ArgumentParserException("No value for flag");
      return (true);
    }
  }
  return (false);
}

std::string const& ArgumentParser::getValueForFlag(std::string const& flag,
						   std::string const& shortflag) const throw(ArgumentParserException)
{
  std::vector<std::string>::const_iterator it;

  if (this->flagExists(true, flag, shortflag) == true) {
    for (it = this->_arguments.begin(); it != this->_arguments.end(); ++it) {
      if ((*it) == flag || (shortflag.length() == 2 && (*it) == shortflag)) {
	return (*(it + 1));
      }
    }
  }
  throw ArgumentParserException("Flag not found");
}

std::ostream& operator<<(std::ostream& os, ArgumentParser const& ap)
{
  std::vector<std::string>::const_iterator it;
  std::vector<std::string> const& arguments = ap.getArguments();

  os << "ArgumentParser: { count: " << ap.getArgumentCount() << ", arguments: [";
  for (it = arguments.begin(); it != arguments.end(); ++it) {
    os << "\"" << *it << "\"";
    if (it + 1 != arguments.end())
      os << ", ";
  }
  os << "] }";
  return (os);
}

std::ostream& operator<<(std::ostream& os, ArgumentParserException const& e)
{
  os << "Exception ArgumentParserException: \"" << e.what() << "\"";
  return (os);
}