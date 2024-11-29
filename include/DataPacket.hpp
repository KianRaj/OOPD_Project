#ifndef DATAPACKET_HPP
#define DATAPACKET_HPP

#include <iostream>

class DataPacket {
private:
    int size;                
    double TT;  

public:
    DataPacket(int size = 1);  

    int getSize() const;
    double getTT() const;
    void setTT(double time);

};

#endif


