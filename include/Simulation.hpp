#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include <vector>
#include <algorithm>
#include <numeric>

class Simulation {
public:
    Simulation(int numUsers, int bandwidth);

    virtual double calculateThroughput();  // Virtual method to calculate throughput
    double calculateAverageLatency();//virtual
    double calculateMaxLatency();//virtual
    virtual void runSimulation() = 0;
    double calculateThroughput(int totalpackets,double totalTime);  

protected:
    int numUsers;
    int bandwidth;
    std::vector<double> latencies;
    std::vector<int> timestamps;
};

#endif // SIMULATION_HPP





