//
// ResSoundLoader.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Sat Dec 31 10:24:19 2016 Adrien Vasseur
// Last update Sat Dec 31 10:24:19 2016 Adrien Vasseur
//

#pragma   once

#include  <string>
#include  "pool/ITask.hpp"

class     ResSoundLoader : public ITask
{
public:
  ResSoundLoader(const std::string &, const std::string &);
  ~ResSoundLoader();

  void    process();

private:
  std::string _name;
  std::string _filename;
};