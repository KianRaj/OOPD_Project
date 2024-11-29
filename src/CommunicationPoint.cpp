#include "CommunicationPoint.hpp"
#include "DataPacket.hpp"  // Include DataPacket instead of Packet
#include <iostream>
#include <algorithm>
#include <random>  // For modern random number generation

// Constructor for CommunicationPoint
CommunicationPoint::CommunicationPoint(int numUsers, int bw) 
    : users(), channel(bw), numUsers(numUsers) {
    // Pre-populate users using STL
    users.reserve(numUsers);
    for (int i = 0; i < numUsers; ++i) {
        users.emplace_back(User(i));  // Ensure User(i) constructor exists
    }
}

// Add a user to the CommunicationPoint
void CommunicationPoint::addUser(const User& user) {
    users.push_back(user);
    std::cout << "Added User " << user.getUserId() << " to the Access Point.\n";
}

// Sniff the channel (returns whether the channel is available)
bool CommunicationPoint::sniffChannel() {
    return channel.sniffChannel();
}

// Occupy the channel (assume this function is already in Channel)
void CommunicationPoint::occupyChannel() {
    channel.occupyChannel();
}

// Release the channel (assume this function is already in Channel)
void CommunicationPoint::releaseChannel() {
    channel.releaseChannel();
}

// Get the bandwidth of the channel
int CommunicationPoint::getBandwidth() const {
    return channel.getBandwidth();
}

// Manage communication for all users
void CommunicationPoint::manageCommunication() {
    // Create random number generator for backoff time
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10);  // Backoff time between 1 and 10 ms

    std::for_each(users.begin(), users.end(), [this, &dis, &gen](User& user) {
        bool success = false;
        while (!success) {
            if (this->channel.sniffChannel()) {
                this->channel.occupyChannel();
                DataPacket packet = user.generatePacket();  // Use DataPacket instead of Packet
                std::cout << "[Info] User " << user.getUserId() 
                          << " transmitted a packet of size " 
                          << packet.getSize() << " KB.\n";
                user.incrementPacketsSent();  // Assuming this function exists in User
                success = true;
                this->channel.releaseChannel();
            } else {
                // Using modern random facilities for backoff
                int backoffTime = dis(gen);
                std::cout << "[Warning] User " << user.getUserId() 
                          << " backs off for " << backoffTime << " ms.\n";
            }
        }
    });
}

