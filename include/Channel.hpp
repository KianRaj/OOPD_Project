#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <iostream>

class Channel {
private:
    int bandwidth;   // Channel bandwidth
    bool isBusy;     // Channel state (busy or free)

public:
    // Constructor
    Channel(int bandwidth);

    // Methods to manage the channel
    bool sniffChannel();       // Check if the channel is available
    void occupyChannel();      // Occupy the channel
    void releaseChannel();     // Release the channel
    int getBandwidth() const;  // Get the channel's bandwidth
};

#endif
