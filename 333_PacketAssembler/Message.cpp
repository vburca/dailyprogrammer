#pragma once

#include <iostream>
#include "Message.h"

Message::Message() : id(0), n(0) {}

Message::Message(int messageId, int nPackets) : id(messageId), n(nPackets)
{
    this->packets.resize(nPackets);
}

Message::~Message() {}

bool Message::AddPacket(int packetId, string packet)
{
    this->packets[packetId] = packet;

    this->count += 1;
    if (this->count == this->n)
    {
        return true;
    }

    return false;
}

void Message::PrintMessage()
{
    for (string s : this->packets)
    {
        std::cout << s << endl;
    }
}