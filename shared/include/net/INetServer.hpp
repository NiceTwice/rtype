//
// INetServer.hpp for rtype in /home/lanquemar/rendu/rtype/shared/include/net/
//
// Made by Adrien Vasseur
// Login   <vasseu_g@epitech.eu>
//
// Started on  Wed Nov 30 12:08:18 2016 Adrien Vasseur
// Last update Tue Dec 27 09:52:43 2016 Corentin Descamps
//

#pragma		once

class		INetServer
{
public:
  virtual	~INetServer() {}

  virtual bool		bind(unsigned short, int) = 0;
  virtual bool		listen() = 0;
  virtual void		cancel() = 0;
};
