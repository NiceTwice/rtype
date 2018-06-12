//
// PacketIdentifier.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/client/include
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#pragma once

class PacketIdentifier
{
public:
  typedef enum Id : uint16_t
  {
	HELLO_PACKET = 0,
    MAP_PACKET = 1,
    PORT_PACKET = 2,
    READY_PACKET = 3,
    ENTITY_PACKET = 4,
    SPAWN_PACKET = 5,
    ENDGAME_PACKET = 6
  } Id;
};