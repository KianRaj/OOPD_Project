#ifndef WIFI5_COMMUNICATION_HPP
#define WIFI5_COMMUNICATION_HPP

#include "Simulation.hpp"

class WiFi5Communication : public Simulation {
public:
    WiFi5Communication(int numUsers, int bandwidth);
    void runSimulation() override;
    double calculateThroughput(int totalpackets, double totalTime);
    double calculateAverageLatency();
    double calculateMaxLatency();
    
};

#endif // WIFI5_COMMUNICATION_HPP
