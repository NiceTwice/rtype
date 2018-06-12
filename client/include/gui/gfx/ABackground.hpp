//
// ABackground.hpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Wed Dec 28 09:55:34 2016 Adrien Vasseur
// Last update Wed Dec 28 09:55:34 2016 Adrien Vasseur
//

#pragma   once

#include  <cstdint>
#include  "gui/IView.hpp"

class     ABackground : public IView
{
public:
  ABackground();
  ~ABackground();

  void    setOffset(std::int64_t);
  void    setWidth(std::uint32_t);

protected:
  std::int64_t      _offset;
  std::uint64_t     _width;
};