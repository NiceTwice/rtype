//
// ResImageLoader.hpp for rtype in /home/lanquemar/rendu/rtype/client/include/gui/res/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Thu Dec  1 15:38:55 2016 Adrien Vasseur
// Last update Fri Dec  9 13:54:48 2016 Adrien Vasseur
//

#pragma		once

#include	<string>
#include	"gui/sfml/SFMLWindow.hpp"
#include	"pool/ITask.hpp"

class		ResImageLoader : public ITask
{
public:
  ResImageLoader(const std::string &, const std::string &, unsigned int, unsigned int);
  ~ResImageLoader();

  void		process();

private:
  std::string	_name;
  std::string	_filename;
  unsigned int	_width;
  unsigned int	_height;
};
