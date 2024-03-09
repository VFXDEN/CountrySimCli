#include <unistd.h>
#include <iostream>
#include <stdlib.h>

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
int timeBetween = 0;
int type1 = 0;
int type2 = 0;
std::string first = "firstTeam";
std::string second = "secondTeam";
int main(int argc, char* argv[]) {
    //Check for if debug is chosen
    if (argc < 2) {
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
        //Time between days
        std::cout << "Time Between Days (Recomended 1): ";
        std::cin >> timeBetween;
        //Begining stats and start to simulation
        std::cout << "\n\nStarting Stats\n";
        std::cout << "Health of " << first << " " << h1 << "      ";
        std::cout << "Health of " << second << " " << h2 << "\n";
        std::cout << "Base Power of " << first << " " << pwr1 << "      ";
        std::cout << "Base Power of " << second << " " << pwr2 << "\n\n";
        sleep(3);
        std::cout << "Simulation Starts In \n";
        sleep(1);
        std::cout << "3  \n";
        sleep(1);
        std::cout << "2  \n";
        sleep(1);
        std::cout << "1  \n";
        sleep(1);
    }
    
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
            std::cout << "Today " << first << " gains " << pwrM1 << " power, and is now at " << pwr1 << " base power\n";
            std::cout << second << " gains " << pwrM2 << " power, and is now at " << pwr2 << " base power\n";
            std::cout << "There is nothing else notible today. \n\n";
            
        } else {
            std::cout << "Day " << day << " will be: " << "War\n";
            //calculations
            day = day + 1;
            pwrM1 = rand() % 3 + 0;
            pwrM2 = rand() % 3 + 0;
            type1 = rand() % 3 + 0;
            type2 = rand() % 3 + 0;
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
            if (type1 == 2) {
                if (pwrM1 == 0) {
                    std::cout << first << "'s air strike on " << second << " was not successful. Keeping " << second << " at " << h2 << " health.\n";
                } else {
                    std::cout << first << "'s air strike on " << second << " was successful. Doing " << dmg1 <<" damage, and bringing " << second << " to " << h2 << " health.\n";
                }
            } else if (type1 == 1) {
                if (pwrM1 == 0) {
                    std::cout << first << "'s navy strike on " << second << " was not successful. Keeping " << second << " at " << h2 << " health.\n";
                } else {
                    std::cout << first << "'s navy strike on " << second << " was successful. Doing " << dmg1 <<" damage, and bringing " << second << " to " << h2 << " health.\n";
                }
            } else if (type1 == 0){
                if (pwrM1 == 0) {
                    std::cout << first << "'s land assault on " << second << " was not successful. Keeping " << second << " at " << h2 << " health.\n";
                } else {
                    std::cout << first << "'s land assault on " << second << " was successful. Doing " << dmg1 <<" damage, and bringing " << second << " to " << h2 << " health.\n";
                }
            }
            if (type2 == 2) {
                if (pwrM2 == 0) {
                    std::cout << second << "'s air strike on " << first << " was not successful. Keeping " << first << " at " << h1 << " health.\n\n";
                } else {
                    std::cout << second << "'s air strike on " << first << " was successful. Doing " << dmg2 <<" damage, and bringing " << first << " to " << h1 << " health.\n\n";
                }
            } else if (type2 == 1) {
                if (pwrM2 == 0) {
                    std::cout << second << "'s navy strike on " << first << " was not successful. Keeping " << first << " at " << h1 << " health.\n\n";
                } else {
                    std::cout << second << "'s navy strike on " << first << " was successful. Doing " << dmg2 <<" damage, and bringing " << first << " to " << h1 << " health.\n\n";
                }
            } else if (type2 == 0){
                if (pwrM2 == 0) {
                    std::cout << second << "'s land assault on " << first << " was not successful. Keeping " << first << " at " << h1 << " health.\n\n";
                } else {
                    std::cout << second << "'s land assault on " << first << " was successful. Doing " << dmg2 <<" damage, and bringing " << first << " to " << h1 << " health.\n\n";
                }
            }
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
        
        sleep(timeBetween);
    }
}
