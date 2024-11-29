#include "Simulation.hpp"
#include "DataPacket.hpp"

Simulation::Simulation(int numUsers, int bw)
    : numUsers(numUsers), bw(bw) {}



/*
double Simulation::calculateThroughput() {
    if (timestamps.empty())
        return 0.0;

    double totalData = timestamps.size()*1.0;  // Total data in bits (1 KB per timestamp)
    double totalTime = timestamps.back() ;  // Convert ms to seconds

    return (totalTime * 8.0) / (totalTime/1000.0); // Throughput in Mbps
}*/
double Simulation::calculateThroughput() {
    if (timestamps.empty()) {
        std::cout << "Error: Timestamps are empty!" << std::endl;
        return 0.0;
    }

    // Debugging: Print timestamps to ensure they are populated
    std::cout << "Timestamps (in ms): ";
    for (double ts : timestamps) {
        std::cout << ts << " ";
    }
    std::cout << std::endl;

    // Total data in bits (8192 bits per timestamp, assuming each represents 1 KB)
    double totalData = timestamps.size() * 8192.0;

    // Total time in seconds (convert from ms to s)
    double totalTime = timestamps.back() / 1000.0;

    // Debugging: Print totalTime before calculation
    std::cout << "Total Time (in seconds): " << totalTime << std::endl;

    // Check for invalid totalTime
    if (totalTime <= 0) {
        std::cout << "Error: Total time is invalid (<= 0). Returning 0 throughput." << std::endl;
        return 0.0;
    }

    // Return throughput in Mbps (Mega-bits per second)
    return (totalData / totalTime) / 1e6;  
}



double Simulation::calculateAverageLatency() {
    if (latencies.empty())
        return 0.0;
    double totalLatency = std::accumulate(latencies.begin(), latencies.end(), 0.0);
    return totalLatency / latencies.size();
}



double Simulation::calculateMaxLatency() {
    if (latencies.empty())
        return 0.0;

    
    return *std::max_element(latencies.begin(),latencies.end());
}

