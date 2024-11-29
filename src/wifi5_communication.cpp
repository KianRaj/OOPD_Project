#include "wifi5_communication.hpp"
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iomanip>
#include <numeric>

WiFi5Communication::WiFi5Communication(int numUsers, int bw)
    : Simulation(numUsers, bw) {}

void WiFi5Communication::runSimulation() {
    std::cout << "WiFi 5 Simulation MU-MIMO\n";

    double nrnd;//nrnd
    std::cout << "Enter number of pkt per user: ";
    std::cin >> nrnd;

   

    double broadcastTime = 0.0614;
    double csiTime = 0.012;
    double timeSlot = 15.0;
    double currentTime = 0.0;
    double  packetTT= 0.0614;

    int totalpackets = numUsers * nrnd;
    int sentpacket = 0;

    std::vector<int> packetsRemaining(numUsers,nrnd);

    while (sentpacket < totalpackets)
    {
        // Step 1: Broadcast a packet
        currentTime += broadcastTime;

        // Step 2: Collect CSI packets sequentially from each user
        for (int i = 0; i < numUsers; ++i)
        {
            currentTime += csiTime;
        }

        // Step 3: Start parallel transmission for the time slot
        double slotStart = currentTime;
        for (int i = 0; i < numUsers; ++i)
        {
            while (packetsRemaining[i] > 0)
            {
                double transmissionEndTime = currentTime + packetTT;

                // If the transmission exceeds the time slot, break
                if (transmissionEndTime > slotStart + timeSlot)
                {
                    break;
                }

                // Send the packet
                packetsRemaining[i]--;
                sentpacket++;
                currentTime = transmissionEndTime;
                latencies.push_back(currentTime);  // Record latency
                timestamps.push_back(currentTime); // Record timestamp
            }
        }
    }

    // Display simulation results
    std::cout << "Simulation Complete:\n";
    std::cout << "Throughput: " << calculateThroughput(totalpackets, currentTime) << " Mbps\n"; // S
    std::cout << "Average Latency: " << calculateAverageLatency() << " ms\n";                   // A
    std::cout << "Max Latency: " << calculateMaxLatency() << " ms\n";                           // H
}

double WiFi5Communication::calculateThroughput(int totalpackets, double totalTime)
{
    if (totalTime <= 0.0)
    {
        return 0.0;
    }
    double totalData = totalpackets * 8.0; 
    return totalData / (totalTime / 1.0);  
}

double WiFi5Communication::calculateAverageLatency()
{
    if (latencies.empty())
    {
        return 0.0;
    }
    double totalLatency = std::accumulate(latencies.begin(), latencies.end(), 0.0);
    return totalLatency / latencies.size();
}

double WiFi5Communication::calculateMaxLatency()
{
    if (latencies.empty())
    {
        return 0.0;
    }
    return *std::max_element(latencies.begin(), latencies.end());
}


    