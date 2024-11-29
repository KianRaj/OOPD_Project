// CommunicationPoint.hpp
#ifndef COMMUNICATION_POINT_HPP
#define COMMUNICATION_POINT_HPP

#include "User.hpp"
#include "Channel.hpp"
#include "DataPacket.hpp"
#include <vector>

class CommunicationPoint {
private:
    std::vector<User> users;
    Channel channel;
    int numUsers;

public:
    CommunicationPoint(int numUsers, int bandwidth);

    void addUser(const User& user);
    bool sniffChannel();
    void occupyChannel();
    void releaseChannel();
    int getBandwidth() const;
    void manageCommunication();
};

#endif
