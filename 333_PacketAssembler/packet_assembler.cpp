#include <iostream>
#include <string>
#include <regex>
#include <map>
#include "Message.cpp"

using namespace std;

int main()
{
    map<int, Message> messages;

    smatch matches;
    regex input_regex("^(\\d+)\\s+(\\d+)\\s+(\\d+)\\s+(.*)\\r?$");

    int messageId, packetId, numPackets;
    string line, packet;
    while (getline(cin, line))
    {
        if (regex_match(line, matches, input_regex))
        {
            messageId = stoi(matches[1].str());
            packetId = stoi(matches[2].str());
            numPackets = stoi(matches[3].str());
            packet = matches[4];

            Message m;
            if (messages.count(messageId) == 0)
            {
                m = Message(messageId, numPackets);
                messages.insert(pair<int, Message>(messageId, m));
            }
            else
            {
                m = messages[messageId];
            }

            bool done = m.AddPacket(packetId, line);
            if (done)
            {
                m.PrintMessage();
                messages.erase(messageId);
            }
            else
            {
                messages[messageId] = m;
            }
        }
    }

    return 0;
}