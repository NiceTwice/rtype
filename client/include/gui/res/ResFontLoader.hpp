//
// ResFontLoader.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Sun Jan 01 18:25:15 2017 Adrien Vasseur
// Last update Sun Jan 01 18:25:15 2017 Adrien Vasseur
//

#pragma   once

#include  <string>
#include  "pool/ITask.hpp"

class     ResFontLoader : public ITask
{
public:
  ResFontLoader(const std::string &, const std::string &);
  ~ResFontLoader();

  void    process();

private:
  std::string   _filename;
  std::string   _name;
};