#include "wifi4_communication.hpp"
#include <iostream>
#include <random>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric> // For accumulate

WiFi4Communication::WiFi4Communication(int numUsers, int bw)
    : Simulation(numUsers,bw) {}

double WiFi4Communication::calculateThroughput()
{
    if (timestamps.empty())
    {
        std::cerr << "Error: No timestamps recorded.\n";
        return 0.0;
    }

    double totalData = timestamps.size() * 8192.0; // Assuming 8192 bits per packet
    double totalTime = timestamps.back() / 1000.0; // Convert to seconds

    if (totalTime == 0.0)
    {
        std::cerr << "Error: totalTime is zero, unable to calculate throughput.\n";
        return 0.0;
    }

    return (totalData / totalTime) / 1e6; // Convert to Mbps (Million bits per second)
}

double WiFi4Communication::calculateAverageLatency()
{
    if (latencies.empty())
    {
        std::cerr << "Error: No latencies recorded.\n";
        return 0.0;
    }

    double totalLatency = std::accumulate(latencies.begin(), latencies.end(), 0.0);
    return totalLatency / latencies.size();
}

double WiFi4Communication::calculateMaxLatency()
{
    if (latencies.empty())
    {
        std::cerr << "Error: No latencies recorded.\n";
        return 0.0;
    }

    return *std::max_element(latencies.begin(), latencies.end());
}

void WiFi4Communication::runSimulation()
{
    std::cout << "Running WiFi4 CSMA/CA...\n";

    std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<> backoffDist(1.0, 10.0);

    double currentTime = 0.0;
    double transmissionTime = 0.0614; // Example fixed transmission time

    std::map<int, double> userBackoff;
    for (int i = 0; i < numUsers; ++i)
    {
        userBackoff[i] = (i == 0) ? 0.0 : backoffDist(rng); // User 0 starts with no backoff
    }

    latencies.clear();
    timestamps.clear();

    // Simulate until all users have finished their transmissions
    while (!userBackoff.empty())
    {
        // Find the user with the minimum backoff time
        auto minUser = std::min_element(userBackoff.begin(), userBackoff.end(),
                                        [](const auto &a, const auto &b)
                                        {
                                            return a.second < b.second;
                                        });

        currentTime = std::max(currentTime, minUser->second); // Ensure the time progresses
        std::cout << "User " << minUser->first << " started transmission at " << currentTime << " ms.\n";

        currentTime += transmissionTime;
        timestamps.push_back(currentTime);
        latencies.push_back(currentTime); // Recording latency for the user

        std::cout << "User " << minUser->first << " finished transmission at " << currentTime << " ms.\n";

        // Remove the user after successful transmission
        userBackoff.erase(minUser);
    }

    std::cout << "\nResults:\n";
    std::cout << "Throughput: " << calculateThroughput() << " Mbps\n";
    std::cout << "Average Latency: " << calculateAverageLatency() << " ms\n";
    std::cout << "Max Latency: " << calculateMaxLatency() << " ms\n";

    std::cout << "\nTransmission Timestamps:\n";
    for (size_t i = 0; i < timestamps.size(); ++i)
    {
        std::cout << "Packet " << i + 1 << ": " << timestamps[i] << " ms\n";
    }
}
