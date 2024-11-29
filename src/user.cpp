#include "User.hpp" 
#include <iostream>
#include <random>

User::User(int id) : userId(id), packetsSent(0) {}

int User::getUserId() const {
    return userId;
}

DataPacket User::generatePacket() {
    std::cout<<"[move from] User "<<userId<<"new data packet generation";
    return DataPacket();  // Convert bytes to bits

    
}

int User::getPacketsSent() const {
    return packetsSent;
}

void User::incrementPacketsSent() {
    packetsSent++;  // Increment packets sent count
    std::cout << "[Info] User " << userId 
              << " incremented packets sent. Total: " 
              << packetsSent << "\n";
}
