//
// HelloPacket.hpp for rtype in /home/blazer/Epitech/Rendu/rtype/server/include/packet
//
// Made by Tom CZAYKA
// Login        <tom.czayka@epitech.eu>
//
// Started on   mer. oct.       19 12:49:58 2016 tom.czayka
// Last update  mer. oct.       19 12:49:58 2016 tom.czayka
//

#include "ACore.hpp"
#include "packet/protocol/HelloPacket.hpp"
#include "packet/protocol/ReadyPacket.hpp"
#include "packet/PacketSender.hpp"
#include "packet/protocol/PacketIdentifier.hpp"

HelloPacket::HelloPacket()
{
}

HelloPacket::~HelloPacket()
{
}

bool HelloPacket::process(const NetworkCommunicationType type, Converter *client, PacketDeserializer &packet)
{
  PacketSerializer serializer;

  if (packet.getPacketSize() == 0) {
    serializer << static_cast<float>(ACore::version);
    PacketSender::set(type, client, PacketIdentifier::HELLO_PACKET, serializer);
    if (client->getPlayer().getWorld() != nullptr)
      ReadyPacket::broadcast(*(client->getPlayer().getWorld()));
    return (true);
  }
  else
    return (false);
}