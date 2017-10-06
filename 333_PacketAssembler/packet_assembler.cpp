#include <iostream>
#include <string>
#include <regex>
#include <map>
#include <memory>
#include "Message.cpp"

using namespace std;

int main()
{
    map<int, shared_ptr<Message>> messages;

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

            shared_ptr<Message> m;
            if (messages.count(messageId) == 0)
            {
                m = make_shared<Message>(messageId, numPackets);
                messages.insert(pair<int, shared_ptr<Message>>(messageId, m));
            }
            else
            {
                m = messages[messageId];
            }

            bool done = m->AddPacket(packetId, line);
            if (done)
            {
                m->PrintMessage();
                messages.erase(messageId);
            }
        }
    }

    return 0;
}