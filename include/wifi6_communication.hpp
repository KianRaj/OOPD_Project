#ifndef WIFI6_COMMUNICATION_HPP
#define WIFI6_COMMUNICATION_HPP

#include "Simulation.hpp"
#include <vector>
#include <algorithm>
#include <numeric>

class WiFi6Communication : public Simulation {
public:
    WiFi6Communication(int numUsers, int bandwidth);
    
    double calculateThroughput();
    void runSimulation() override;

    // Template methods for latency calculations
    template <typename LatencyContainer>
    static double calculateAverageLatency(const LatencyContainer& latencies) {
        if (latencies.empty())
            return 0.0;

        double totalLatency = std::accumulate(latencies.begin(), latencies.end(), 0.0);
        return totalLatency / latencies.size();
    }

    template <typename LatencyContainer>
    static double calculateMaxLatency(const LatencyContainer& latencies) {
        if (latencies.empty())
            return 0.0;

        return *std::max_element(latencies.begin(), latencies.end());
    }

    // Non-template methods that use the template methods with the class's latencies
    double calculateAverageLatency() {
        return calculateAverageLatency(latencies);
    }

    double calculateMaxLatency() {
        return calculateMaxLatency(latencies);
    }

private:
    int subChannelWidth;
    double dataRate;
};

#endif // WIFI6_COMMUNICATION_HPP
