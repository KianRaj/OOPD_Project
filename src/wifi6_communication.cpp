#include "wifi6_communication.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include<iomanip>


WiFi6Communication::WiFi6Communication(int numUsers, int bw)
    : Simulation(numUsers, bw), subChannelWidth(4),dataRate(133.33) {}


double WiFi6Communication::calculateThroughput() {
    if (latencies.empty()) {
        std::cerr << "Error: No latencies recorded.\n";
        return 0.0;
    }

    // Debugging: Print out all timestamps and latencies
    std::cout << "Debug - Timestamps: ";
    for (const auto& ts : timestamps) {
        std::cout << ts << " ";
    }
    std::cout << "\nDebug - Latencies: ";
    for (const auto& lat : latencies) {
        std::cout << lat << " ";
    }
    std::cout << std::endl;

    // Total data in bits (8192 bits per timestamp, assuming each represents 1 KB)
    double totalData = latencies.size() * 8192.0;

    // Ensure a minimum time difference to prevent division by zero
    double totalTime = std::max(timestamps.back() / 1000.0, 0.001);

    // Return throughput in Mbps (Mega-bits per second)
    double throughput = (totalData / totalTime) / 1e6;

    std::cout << "Debug - Total Data: " << totalData << " bits\n";
    std::cout << "Debug - Total Time: " << totalTime << " seconds\n";
    std::cout << "Debug - Calculated Throughput: " << throughput << " Mbps\n";

    return throughput;
}

void WiFi6Communication::runSimulation() {
    std::cout << " WiFi 6 Simulation OFDMA...\n";

    int userInputSubChannelWidth;
    std::cout << "Enter sub-channel width (2 MHz, 4 MHz, or 10 MHz): ";
    std::cin >> userInputSubChannelWidth;

    if (userInputSubChannelWidth != 2 && userInputSubChannelWidth != 4 && userInputSubChannelWidth != 10)
    {
        throw std::invalid_argument("Invalid sub-channel width! Only 2, 4, or 10 MHz are allowed.");
    }
    subChannelWidth = userInputSubChannelWidth;

    int numSubChannels = bw / subChannelWidth;
    double dataRatePerSubChannel = (dataRate * subChannelWidth) / 20.0;
    double transmissionTime = (8192.0 / (dataRatePerSubChannel * 1e6)) * 1000.0;

    if (dataRatePerSubChannel <= 0)
    {
        std::cerr << "Error: Data rate per sub-channel is invalid. Exiting simulation.\n";
        return;
    }

    std::cout << "Total Bandwidth: " << bw << " MHz\n";
    std::cout << "Sub-channel Width: " << subChannelWidth << " MHz\n";
    std::cout << "Number of Sub-channels: " << numSubChannels << "\n";
    std::cout << "Transmission Time per Packet: " << std::fixed << std::setprecision(4) << transmissionTime << " ms\n\n";

    latencies.clear();
    timestamps.clear();

    int remainingUsers = numUsers;
    double currentTime = 0.0;

    while (remainingUsers > 0)
    {
        std::cout << "--- Starting Frame at " << currentTime << " ms ---\n";

        int usersThisFrame = std::min(numSubChannels, remainingUsers);
        for (int i = 0; i < usersThisFrame; ++i)
        {
            int user = numUsers - remainingUsers + i;
            double latency = currentTime + transmissionTime;

            // Debugging: Print latency for each user
            std::cout << "User " << user << " transmits at " << std::fixed << std::setprecision(4) << latency << " ms.\n";

            timestamps.push_back(latency);
            latencies.push_back(latency);
        }

        remainingUsers -= usersThisFrame;
        currentTime += 5.0; // Move to the next frame (frame duration is 5 ms)

        // Debugging: Print the timestamps after every frame
        std::cout << "Timestamps after this frame: ";
        for (const double& ts : timestamps) {
            std::cout << ts << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "\nSimulation Results:\n";
    std::cout << "Throughput: " << calculateThroughput() << " Mbps\n";
    //std::cout << "Average Latency: " << calculateAverageLatency() << " ms\n";
    //std::cout << "Max Latency: " << calculateMaxLatency() << " ms\n";
    std::cout << "Average Latency: " << calculateAverageLatency() << " ms\n";
    std::cout << "Max Latency: " << calculateMaxLatency() << " ms\n";
}
