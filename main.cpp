#include <unistd.h>
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <random>

int h1 = 1000; // Base Health for Country 1
int hL1 = 500; // Land Health for Country 1
int hA1 = 500; // Air Health for Country 1
int hN1 = 500; // Navy Health for Country 1
int h2 = 1000; // Base Health for Country 2
int hL2 = 500; // Land Health for Country 2
int hA2 = 500; // Air Health for Country 2
int hN2 = 500; // Navy Health for Country 2
int pwrL1 = 5; //Land Power for Country 1
int pwrA1 = 5; //Air Power for Country 1
int pwrN1 = 5; //Navy Power for Country 1
int pwrL2 = 5; //Land Power for Country 2
int pwrA2 = 5; //Air Power for Country 2
int pwrN2 = 5; //Navy Power for Country 2
int aP1 = 0; // Advancement Points for Country 1
int aP2 = 0; // Advancement Points for Country 2
std::string aL = "Land"; //Advancment location
int tAP = 0; // Temporary alocated points
int fight = 0;
int randadvance;
int day = 1;
int timeBetween = 0;
int type1 = 0;
int type2 = 0;
std::string start = "y";
std::string first = "firstTeam";
std::string second = "secondTeam";
std::string getRandomCountry(const std::vector<std::string>& countries) {
    int random_index = std::rand() % countries.size();
    return countries[random_index];
}
int main(int argc, char* argv[]) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::vector<std::string> countries = {
        "Alvernia", "Corinthia", "Estoria", "Nordica", "Valdoria",
        "Arboria", "Galvania", "Lysandria", "Polaris", "Veridian",
        "Ardonia", "Havena", "Marland", "Paradisio", "Vestoria",
        "Aurelia", "Istoria", "Miraclia", "Soleil", "Zephyria",
        "Landia", "Stanistan", "Terranova", "Sylvania", "Arcadia",
        "Utopistan", "Floraland", "Verdistan", "Valoria", "Astoria",
        "Cascadia", "Novaria", "Aldoria", "Gallador", "Lyonesia",
        "Pacifico", "Verdantis", "Helvetia", "Marinia", "Palmira",
        "Vespera", "Islandia", "Meridian", "Soloria", "Zephyrland",
        "Auroria", "Irenia", "Solaris", "Zylandia"
    };
    int random_index = std::rand() % countries.size();
    std::string random_country = getRandomCountry(countries);
    second = random_country;
        //Name selection
        std::cout << "Name for your country: \n";
        std::cin >> first;
        std::cout << "You will be fighting "<< second << ".\n\n";
        std::cout << "Start?(y or n): ";
        std::cin >> start;
        if(start == "n"){
            return 0;
        }
        system("clear");
        //The simulation itself
        while (h1 > -1000 and h2 > -1000) {
            fight = rand() % 2 + 0;
            if (fight < 1) {
                std::cout << "Day " << day << " will be: " << "Peace\n\n";
                aP1 = rand() % 6 + 1;
                aP2 = rand() % 6 + 1;
                randadvance = rand() % 4 + 0;
                if (randadvance == 0) {
                    pwrA2 += aP2;
                    aP2 = 0;
                    std::cout << second << " is now at " << pwrA2 << " air power.\n";
                } else if (randadvance == 1) {
                    pwrN2 += aP2;
                    aP2 = 0;
                    std::cout << second << " is now at " << pwrN2 << " navy power.\n";
                } else if (randadvance == 2) {
                    pwrL2 += aP2;
                    aP2 = 0;
                    std::cout << second << " is now at " << pwrL2 << " land power.\n";
                } else if (randadvance == 1) {
                    aP2 *= 50;
                    h2 += aP2;
                    aP2 = 0;
                    std::cout << second << " is now at " << pwrN2 << " base health.\n";
                }
                std::cout << "You have gathered " << aP1 << " Advancement points\n";
                while (aP1 > 0) {
                    std::cout << aP1 <<" Advancement points remaining. What would you like to advance? \nYou can advance, Air, Navy, Land, Health. (Choose one):";
                    std::cin >> aL;
                    if(aL == "LAND" or aL == "Land" or aL == "land" or aL == "L" or aL == "l"){
                        if (hL1 > 0) {
                            std::cout << "How many points should be alocated?: ";
                            std::cin >> tAP;
                            if (aP1 >= tAP) {
                                pwrL1 += tAP;
                                pwrA1 -= tAP;
                                std::cout << tAP <<"\nPoints have been added, bringing total land power to " << pwrL1 << ".\n\n";
                            } else {
                                std::cout << "\nNot enough points\n\n";
                            }
                        } else {
                            std::cout << "\nLand offence has been destroyed, choose a different area to advance.\n\n";
                        }
                    } else if (aL == "AIR" or aL == "Air" or aL == "air" or aL == "A" or aL == "a"){
                        if (hL1 > 0) {
                            std::cout << "How many points should be alocated?: ";
                            std::cin >> tAP;
                            if (aP1 >= tAP) {
                                aP1 -= tAP;
                                pwrA1 += tAP;
                                std::cout << tAP <<"\nPoints have been added, bringing total air power to " << pwrA1 << ".\n\n";
                            } else {
                                std::cout << "\nNot enough points\n\n";
                            }
                        } else {
                            std::cout << "\nAir offence has been destroyed, choose a different area to advance.\n\n";
                        }
                    } else if (aL == "NAVY" or aL == "Navy" or aL == "navy" or aL == "N" or aL == "n"){
                        if (hL1 > 0) {
                            std::cout << "How many points should be alocated?: ";
                            std::cin >> tAP;
                            if (aP1 >= tAP) {
                                aP1 -= tAP;
                                pwrN1 += tAP;
                                std::cout << tAP <<"\nPoints have been added, bringing total navy power to " << pwrN1 << ".\n\n";
                            } else {
                                std::cout << "\nNot enough points\n\n";
                            }
                        } else {
                            std::cout << "\nNavy offence has been destroyed, choose a different area to advance.\n\n";
                        }
                    } else if (aL == "HEALTH" or aL == "Health" or aL == "health" or aL == "H" or aL == "h"){
                        std::cout << "How many points should be alocated?: ";
                        std::cin >> tAP;
                        if (aP1 >= tAP) {
                            aP1 -= tAP;
                            tAP = tAP * 50;
                            h1 += tAP;
                            std::cout << tAP <<"\nHealth points have been added, bringing total base health to " << h1 << ".\n\n";
                        } else {
                            std::cout << "\nNot enough points\n\n";
                        }
                    } else {
                        std::cout << "NOT AN OPTION\n";
                        std::cout << "TRY AGAIN";
                    }
                }
            } else {
                std::cout << "Day " << day << " will be: " << "War\n";
                //Air Attack
                if(hA1 > 0){
                    if (hA2 > 0) {
                        hA2 -= pwrA1;
                        if (hA2 < 0) {
                            hA2 = 0;
                        }
                        std::cout << first << " did " << pwrA1 << " to " << second << "'s air defence. " << second << "'s air defense is now at " << hA2 << ".\n";
                    } else {
                        h1 -= pwrA1;
                        std::cout << first << " did " << pwrA1 << " to " << second << "'s base health. " << second << "'s base health is now at " << h2 << ".\n]";
                    }
                } else {}
                if(hA2 > 0){
                    if (hA1 > 0) {
                        hA1 -= pwrA2;
                        if (hA1 < 0) {
                            hA1 = 0;
                        }
                        std::cout << second << " did " << pwrA2 << " to " << first << "'s air defence. " << first << "'s air defense is now at " << hA1 << ".\n\n";
                    } else {
                        h1 -= pwrA1;
                        std::cout << second << " did " << pwrA2 << " to " << first << "'s base health. " << first << "'s base health is now at " << h1 << ".\n\n";
                    }
                } else {}
                //Land Attack
                if(hL2 > 0){
                    if (hL1 > 0) {
                        hL1 -= pwrL2;
                        if (hL1 < 0) {
                            hL1 = 0;
                        }
                        std::cout << second << " did " << pwrL2 << " to " << first << "'s land defence. " << first << "'s land defense is now at " << hL1 << ".\n";
                    } else {
                        h1 -= pwrA1;
                        std::cout << second << " did " << pwrL2 << " to " << first << "'s base health. " << first << "'s base health is now at " << h1 << ".\n";
                    }
                } else {}
                if(hL1 > 0){
                    if (hL2 > 0) {
                        hL2 -= pwrL1;
                        if (hL2 < 0) {
                            hL2 = 0;
                        }
                        std::cout << first << " did " << pwrL1 << " to " << second << "'s land defence. " << second << "'s land defense is now at " << hL2 << ".\n\n";
                    } else {
                        h1 -= pwrA1;
                        std::cout << first << " did " << pwrL1 << " to " << second << "'s base health. " << second << "'s base health is now at " << h2 << ".\n\n";
                    }
                } else {}
                // Navy Attack
                if(hN1 > 0){
                    if (hN2 > 0) {
                        hN2 -= pwrN1;
                        if (hN2 < 0) {
                            hN2 = 0;
                        }
                        std::cout << first << " did " << pwrN1 << " to " << second << "'s navy defence. " << second << "'s navy defense is now at " << hN2 << ".\n";
                    } else {
                        h1 -= pwrA1;
                        std::cout << first << " did " << pwrN1 << " to " << second << "'s base health. " << second << "'s base health is now at " << h2 << ".\n";
                    }
                } else {}
                if(hN2 > 0){
                    if (hN1 > 0) {
                        hN1 -= pwrN2;
                        if (hN1 < 0) {
                            hN1 = 0;
                        }
                        std::cout << second << " did " << pwrN2 << " to " << first << "'s navy defence. " << first << "'s navy defense is now at " << hN1 << ".\n\n";
                    } else {
                        h1 -= pwrA1;
                        std::cout << second << " did " << pwrN2 << " to " << first << "'s base health. " << first << "'s base health is now at " << h1 << ".\n\n";
                    }
                } else {}
                //Win/Loss Check
                if (h1 < 1) {
                    h1 = 0;
                    std::cout << "Team " << second << " Won On Day " << day << std::endl;
                    return 0;
                } else if(h2 < 1) {
                    h2 = 0;
                    std::cout << "Team " << first << " Won On Day " << day << std::endl;
                    return 0;
                } else if(h1 < 1 and h2 < 1) {
                    std::cout << "It Was A Draw On Day " << day << std::endl;
                    return 0;
                }
            }
                day += 1;
                std::cin.ignore();
                char input = std::cin.get();
                system("clear");
                
            }
        }
