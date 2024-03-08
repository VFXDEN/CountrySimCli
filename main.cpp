#include <unistd.h>
#include <iostream>
int h1 = 1000;
int h2 = 1000;
int pwr1 = 20;
int pwr2 = 20;
int pwrM1 = 0;
int pwrM2 = 0;
int dmg1 = 0;
int dmg2 = 0;
int fight = 0;
int day = 1;
std::string first = "first";
std::string second = "Second";
int main() {
    //Name selection
    std::cout << "Name for first country: ";
    std::cin >> first;
    std::cout << "Name for second country: ";
    std::cin >> second;
    //Health selection
    std::cout << "Base Health for " << first << " (Recomended 1000): ";
    std::cin >> h1;
    std::cout << "Base Health for " << second << " (Recomended 1000): ";
    std::cin >> h2;
    //Power selection
    std::cout << "Base Power for " <<first << " (Recomended 20): ";
    std::cin >> pwr1;
    std::cout << "Base Power for " <<second << " (Recomended 20): ";
    std::cin >> pwr2;
    //Begining stats and start to simulation
    std::cout << "Starting Stats\n";
    std::cout << "Health of " << first << " " << h1 << "      ";
    std::cout << "Health of " << second << " " << h2 << "\n";
    std::cout << "Base Power of " << first << " " << pwr1 << "      ";
    std::cout << "Base Power of " << second << " " << pwr2 << "\n\n";
    sleep(3);
    std::cout << "Simulation Starts In ";
    sleep(1);
    std::cout << "3  ";
    sleep(1);
    std::cout << "2  ";
    sleep(1);
    std::cout << "1  ";
    sleep(1);
    //The simulation itself
    while (h1 > -1000 and h2 > -1000) {
        fight = rand() % 2 + 0;
        if (fight < 1) {
            std::cout << "Day " << day << " will be: " << "Peace\n";
            //calculations
            day = day + 1;
            pwrM1 = rand() % 6 + 0;
            pwrM2 = rand() % 6 + 0;
            pwr1 = pwr1 + pwrM1;
            pwr2 = pwr2 + pwrM2;
            //report
            std::cout << "Health of " << first << " " << h1 << "      ";
            std::cout << "Health of " << second << " " << h2 << "\n";
            std::cout << "Base Power of " << first << " " << pwr1 << "      ";
            std::cout << "Base Power of " << second << " " << pwr2 << "\n\n";
            //Win/Loss Check
            if (h1 < 1) {
                std::cout << "Team " << second << " Won On Day " << day << std::endl;
                return 0;
            } else if(h2 < 1) {
                std::cout << "Team " << first << " Won On Day " << day << std::endl;
                return 0;
            } else if(h1 < 1 and h2 < 1) {
                std::cout << "It Was A Draw On Day " << day << std::endl;
                return 0;
            }
            
        } else {
            std::cout << "Day " << day << " will be: " << "War\n";
            //calculations
            day = day + 1;
            pwrM1 = rand() % 3 + 0;
            pwrM2 = rand() % 3 + 0;
            dmg1 = pwr1 * pwrM1;
            dmg2 = pwr2 * pwrM2;
            h1 = h1 - dmg2;
            h2 = h2 - dmg1;
            if (h1 < 0) {
                h1 = 0;
            } else if(h2 < 0){
                h2 = 0;
            }
            //Report
            std::cout << "Health of " << first << " " << h1 << "      ";
            std::cout << "Health of " << second << " " << h2 << "\n";
            std::cout << "Base Power of " << first << " " << pwr1 << "      ";
            std::cout << "Base Power of " << second << " " << pwr2 << "\n\n";
            //Win/Loss Check
            if (h1 < 1) {
                std::cout << "Team " << second << " Won On Day " << day << std::endl;
                return 0;
            } else if(h2 < 1) {
                std::cout << "Team " << first << " Won On Day " << day << std::endl;
                return 0;
            } else if(h1 < 1 and h2 < 1) {
                std::cout << "It Was A Draw On Day " << day << std::endl;
                return 0;
            }
        }
        
        sleep(1);
    }
}
