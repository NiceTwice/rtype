//
// PortPacket.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/server/include/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include <iostream>
#include "packet/protocol/PortPacket.hpp"
#include "packet/PacketSender.hpp"
#include "packet/protocol/PacketIdentifier.hpp"

PortPacket::PortPacket()
{
}

PortPacket::~PortPacket()
{
}

bool PortPacket::process(const NetworkCommunicationType type, Converter *client, PacketDeserializer &packet)
{
  uint16_t port;
  PacketSerializer serializer;

  packet >> port;
  if (client->getClient()->hasUDP() == false)
  client->getClient()->resetSocketUDP();
  if (client->getClient()->buildUDP(client->getClient()->getSocketTCP()->getSocketAddress(), port) == false)
    return (false);
  client->getClient()->getSocketUDP()->findSocketAddress();
  serializer << static_cast<uint16_t>(client->getClient()->getSocketUDP()->getSocketAddress().getPort());
  PacketSender::set(type, client, PacketIdentifier::PORT_PACKET, serializer);
  return (true);
}