#include "DataPacket.hpp"
#include <iostream>
#include <iomanip>  // Ensure this header is included

DataPacket::DataPacket(int size):size(size),TT(0.0){}

int DataPacket::getSize() const {
    return size;
}

double DataPacket::getTT() const {
    return TT;
}