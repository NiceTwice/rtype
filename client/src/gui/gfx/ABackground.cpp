//
// ABackground.cpp for rtype in /home/lanquemar/rendu/rtype
//
// Made by Adrien Vasseur
// Login   <adrien.vasseur@epitech.eu>
//
// Started on  Wed Dec 28 09:56:36 2016 Adrien Vasseur
// Last update Wed Dec 28 09:56:36 2016 Adrien Vasseur
//

#include    "gui/gfx/ABackground.hpp"

ABackground::ABackground()
{
  this->_offset = 0;
  this->_width = 0;
}

ABackground::~ABackground()
{

}

void        ABackground::setOffset(std::int64_t offset)
{
  this->_offset = offset;
}

void        ABackground::setWidth(std::uint32_t width)
{
  this->_width = width;
}