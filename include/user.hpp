#pragma once

#include "DataPacket.hpp"

class User {
public:
    explicit User(int id);

    int getUserId() const;
    DataPacket generatePacket();
    int getPacketsSent() const;
    void incrementPacketsSent();

private:
    int userId;
    int packetsSent;
};