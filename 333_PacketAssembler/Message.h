#pragma once

#include <string>
#include <vector>

using namespace std;

class Message
{
public:
    Message();
    Message(int messageId, int nPackets);
    ~Message();

    bool AddPacket(int packetId, string packet);
    void PrintMessage();

private:
    int id;
    int n;
    int count = 0;
    vector<string> packets;
};