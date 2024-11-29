#include <iostream>
#include <limits>
#include "WiFi4_communication.hpp"
#include "WiFi5_communication.hpp"
#include "WiFi6_communication.hpp"

void displayMenu()
{
    std::cout << "*************************************\n";
    std::cout << "   WiFi Communication Simulator\n";
    std::cout << "*************************************\n";
    std::cout << "Select a Communication Type:\n";
    std::cout << "p. WiFi 4 (CSMA/CA)\n";
    std::cout << "q. WiFi 5 (MU-MIMO)\n";
    std::cout << "r. WiFi 6 (OFDMA)\n";
    std::cout << "s. Exit\n";
    std::cout << "*************************************\n";
    std::cout << "Your Choice: ";
}

// Validated integer input
int getValidatedInput(const std::string &prompt, int min = 0, int max = std::numeric_limits<int>::max())
{
    int value;
    while (true)
    {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail() || value < min || value > max)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number between " << min << " and " << max << ".\n";
        }
        else
        {
            break;
        }
    }
    return value;
}

// Character input validation
char getValidatedCharInput() {
    char choice;
    while (true) {
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please try again.\n";
            displayMenu();
            continue;
        }

        // Convert to lowercase to handle both upper and lower case
        choice = std::tolower(choice);

        // Check if the input is one of the valid choices
        if (choice == 'p' || choice == 'q' || choice == 'r' || choice == 's') {
            return choice;
        }

        std::cout << "Invalid choice. Please select p, q, r, or s.\n";
        displayMenu();
    }
}

int main()
{
    char choice;

    while (true)
    {
        displayMenu();
        choice = getValidatedCharInput();

        if (choice == 's')
        {
            std::cout << "[Exit] Thank you for using the WiFi Simulator. Goodbye!\n";
            break;
        }

        int numUsers = getValidatedInput("Enter the number of users: ", 1); 
        int bandwidth = 20; 

        switch (choice)
        {
        case 'p':
            std::cout << "[Start] Initializing WiFi 4 Simulation...\n\n";
            try
            {
                WiFi4Communication WiFi4Communication(numUsers, bandwidth);
                WiFi4Communication.runSimulation();
            }
            catch (const std::exception &e)
            {
                std::cerr << "[Error] WiFi 4 Simulation failed: " << e.what() << "\n";
            }
            break;

        case 'q':
            std::cout << "[Start] Initializing WiFi 5 Simulation...\n";
            try
            {
                WiFi5Communication WiFi5Communication(numUsers, bandwidth);
                WiFi5Communication.runSimulation();
            }
            catch (const std::exception &e)
            {
                std::cerr << "[Error] WiFi 5 Simulation failed: " << e.what() << "\n";
            }
            break;

        case 'r':
            std::cout << "[Start] Initializing WiFi 6 Simulation...\n";
            try
            {
                WiFi6Communication WiFi6Communication(numUsers, bandwidth);
                WiFi6Communication.runSimulation();
            }
            catch (const std::exception &e)
            {
                std::cerr << "[Error] WiFi 6 Simulation failed: " << e.what() << "\n";
            }
            break;

        default:
            std::cerr << "[Critical Error] Unexpected input.\n";
        }

        std::cout << "*************************************\n\n";
    }

    return 0;
}