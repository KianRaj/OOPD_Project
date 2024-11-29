#include "channel.hpp"
#include <iostream>
#include <random>  

Channel::Channel(int bandwidth) : bandwidth(bandwidth), isBusy(false) {}

bool Channel::sniffChannel() {
    bool isAvailable = !isBusy && (rand()%2==0);
    std::cout << "[Debug] Available Channel:"<<(isAvailable ? "Yes" : "No") <<"\n";
    
    return isAvailable;
}

void Channel::occupyChannel() {
    isBusy = true;  // Mark channel as occupied
    std::cout << "[Action] occupied channel.\n";
}

void Channel::releaseChannel() {
    isBusy = false;  // Mark channel as released
    std::cout << "[Action] released channel.\n";
}

int Channel::getBandwidth() const {
    return bandwidth;  
}
