//
// ArgumentParser.hpp for RTYPE - Server in /home/cugede/work/epitech/rendu/TEK3/CPP/rtype/server/include
//
// Made by Quentin Guerin
// Login <quentin.guerin@epitech.net>
//
// Started on  Tue Nov 29 11:07:46 2016 Quentin Guerin
// Last update Wed Nov 30 13:56:16 2016 Quentin Guerin
//

#pragma once

# include <map>
# include <string>
# include <vector>
# include <locale>
# include <iostream>
# include "exceptions/ArgumentParserException.hpp"

# define ISPAIR(x) (x % 2 == 0)

class ArgumentParser
{
public:
  ArgumentParser(int, char **, char ** = nullptr);
  ~ArgumentParser();

public:
  int const& getArgumentCount() const;
  std::vector<std::string> const& getArguments() const;
  std::map<std::string, std::string> const& getEnvironment() const;
  std::string const& getEnvironmentValue(std::string const&) const throw(ArgumentParserException);
  bool flagExists(bool, std::string const&, std::string const& = "") const throw(ArgumentParserException);
  std::string const& getValueForFlag(std::string const&, std::string const& = "") const throw(ArgumentParserException);

protected:
  void _checkFlags(std::string const&, std::string const& = "") const throw(ArgumentParserException);

protected:
  int _count;
  std::vector<std::string> _arguments;
  std::map<std::string, std::string> _environment;
  std::locale _locale;
};

std::ostream& operator<<(std::ostream&, ArgumentParser const&);
std::ostream& operator<<(std::ostream&, ArgumentParserException const&);