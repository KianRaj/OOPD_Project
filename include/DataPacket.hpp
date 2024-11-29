#ifndef DATAPACKET_HPP
#define DATAPACKET_HPP

#include <iostream>

class DataPacket {
private:
    int size;                 // Size of the packet in kilobytes
    double TT;  // Transmission time in milliseconds

public:
    // Constructor with size and data rate
    DataPacket(int size = 1);  // Constructor signature without default value

    // Getters (declarations only, no method body)
    int getSize() const;
    double getTT() const;
    void setTT(double time);

    // Setters (optional, uncomment if needed)
    // void setTransmissionTime(double time);
};

#endif


