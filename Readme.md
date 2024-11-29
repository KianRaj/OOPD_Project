# WiFi Communication Simulation Project

This project simulates and compares the performance of WiFi communications across **WiFi 4 (802.11n)**, **WiFi 5 (802.11ac)**, and **WiFi 6 (802.11ax)** technologies under varying user scenarios. The aim is to understand the impact of different communication methods on **throughput**, **latency**, and the overall performance in multi-user environments. The simulation includes the modeling of the communication channels, user interactions, and access points, along with the relevant calculations for throughput, average latency, and maximum latency.

## **1. WiFi 4 Communication (802.11n)**

WiFi 4, or **802.11n**, operates using a **Carrier Sense Multiple Access with Collision Avoidance (CSMA/CA)** mechanism. The communication process involves:

- **Sniffing the channel** to check if the channel is free.
- If the channel is **clear**, the access point transmits data.
- If the channel is **busy**, the transmission is **deferred** for a random amount of time, subject to a **backoff limit**.

### Key Simulation Features:
- **Single Access Point (AP)** and **Multiple Users**: Simulates communication scenarios for **1 user**, **10 users**, and **100 users** connected to a single access point.
- **Throughput Calculation**: Measures the throughput, which is the rate at which data is successfully transmitted over the network.
- **Latency**: Calculates both **average latency** and **maximum latency** for each transmission.

### Parameters:
- **Bandwidth**: 20 MHz.
- **Modulation**: 256-QAM.
- **Coding Rate**: 5/6.
- **Packet Size**: 1 KB.
- **No consideration for time wastage** (DIFS, CIFS, etc.).

### Simulation Goals:
- Simulate how the number of users affects throughput and latency.
- Provide insights into the efficiency of **CSMA/CA** in a crowded environment.

---

## **2. WiFi 5 Communication (802.11ac)**

WiFi 5, or **802.11ac**, introduces the concept of **Multi-User MIMO (MU-MIMO)**, which enables parallel communication from the access point to multiple users simultaneously. However, parallel communication requires some setup:

- **Initial Broadcast**: The AP sends a **single broadcast packet** to all users.
- **Channel State Information (CSI)**: Each user sends **200-byte** CSI packets back to the AP.
- After this setup, the users can transmit in parallel for a total of **15 ms**.

### Key Simulation Features:
- **Round-Robin Scheduling**: After the initial setup, the users communicate in parallel using round-robin scheduling.
- **Throughput, Average Latency, and Maximum Latency**: Measured under different user scenarios (1, 10, 100 users).
- **Parallel Communication**: Users can communicate in parallel during a 15 ms window.

### Parameters:
- **Bandwidth**: 20 MHz.
- **Modulation**: 256-QAM.
- **Coding Rate**: 5/6.
- **Packet Size**: 1 KB.
- **Round-Robin Scheduling**: The simulation assumes equal time slots for each user.

### Simulation Goals:
- Investigate how **multi-user MIMO** improves throughput by allowing parallel communication.
- Compare performance with **WiFi 4** under varying numbers of users.

---

## **3. WiFi 6 Communication (802.11ax)**

WiFi 6, or **802.11ax**, introduces **Orthogonal Frequency Division Multiple Access (OFDMA)**, which further subdivides the **20 MHz channel** into smaller **sub-channels** (2 MHz, 4 MHz, or 10 MHz). This allows even more parallelism, as each user can communicate on a different sub-channel for a fixed duration (5 ms).

### Key Simulation Features:
- **OFDMA (Orthogonal Frequency Division Multiple Access)**: Each 20 MHz channel is divided into smaller sub-channels, improving spectral efficiency.
- **Round-Robin Scheduling**: Users are assigned sub-channels using round-robin scheduling, ensuring fair access to the channel.
- **Throughput, Average Latency, and Maximum Latency**: Calculated for various configurations (1, 10, 100 users).
- **Dynamic Sub-Channel Allocation**: Users are assigned sub-channels (2 MHz, 4 MHz, or 10 MHz) for 5 ms periods.

### Parameters:
- **Bandwidth**: 20 MHz (divided into 2 MHz, 4 MHz, or 10 MHz sub-channels).
- **Modulation**: 1024-QAM (higher than WiFi 4 and 5 for better efficiency).
- **Coding Rate**: 5/6.
- **Packet Size**: 1 KB.
- **Sub-Channel Widths**: 2 MHz, 4 MHz, or 10 MHz.

### Simulation Goals:
- Demonstrate the benefits of **OFDMA** in reducing congestion and improving throughput.
- Compare the performance of **WiFi 6** against **WiFi 4** and **WiFi 5** for different user scenarios.

---

## **Project Features:**

- **Class Structure**: Models the **access point (AP)**, **users**, **data packets**, and **frequency channels**.
- **Data Structures**: Efficiently handles large amounts of data, ensuring scalability for simulations involving many users.
- **Simulation Methods**: Implements **CSMA/CA**, **MU-MIMO**, and **OFDMA** transmission schemes for WiFi 4, WiFi 5, and WiFi 6, respectively.
- **Performance Metrics**:
  - **Throughput**: Measures how much data can be transmitted successfully over time.
  - **Average Latency**: The average time it takes for a packet to travel from the source to the destination.
  - **Maximum Latency**: The longest time it takes for a packet to be transmitted.

---

## **How to Build and Run:**

1. **Clone the Repository**: 
   ```bash
   git clone https://github.com/KianRaj/OOPD_Project
   cd wifi-simulation
