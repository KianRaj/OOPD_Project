#ifndef WIFI4_COMMUNICATION_HPP
#define WIFI4_COMMUNICATION_HPP

#include "simulation.hpp"
#include <vector>

class WiFi4Communication : public Simulation {
public:
    WiFi4Communication(int numUsers, int bw);

    // Function declarations
    double calculateThroughput();
    double calculateAverageLatency();  
    double calculateMaxLatency();      

    void runSimulation();

private:
    std::vector<double> latencies;
    std::vector<double> timestamps;
};

#endif // WIFI4_COMMUNICATION_HPP
