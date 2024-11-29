#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include <iostream>

class Channel {
private:
    int bw;  
    bool isBusy;     

public:
    Channel(int bandwidth);

    bool sniffChannel();       
    void occupyChannel();      
    void releaseChannel();     
    int getBandwidth() const; 
};

#endif
