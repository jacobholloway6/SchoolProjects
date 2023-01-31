/**
 * Start of a driver file to test orgtree.cpp
 * CS 210 Fall 2022
 * @author Mitchell Shapiro <mshapiro6805@sdsu.edu>
 * @date Nov 2022
 */

#include "connectedcities.h"

#include <string>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/**
 * THIS DRIVER FILE IS ONLY A START!
 * IT IS CRITICAL THAT YOU ADD YOUR
 * OWN TEST CASES. MOST CASES ARE
 * HIDDEN ON GRADESCOPE.
 */

/**
 * Print whether the given test case passed or failed
 * @param didPass - The test condition (true to pass, false to fail)
 * @param message - Description of what is being tested
 */
void asserts(bool didPass, string message) {
    if (didPass) {
        cout << "Passed: " << message << endl;
    } else {
        cout << "FAILED: " << message << endl;
        // Halts execution, comment out to
        // continue testing other parts
		// If you do comment this out, ignore the
		// "All test cases passed!" printout
        exit(EXIT_FAILURE);
    }
}

//TODO
int main(int argc, char **argv) {
    
    // Begin Testing
    // A few sample testing code are provided below  
    
    /* Construct a graph for testing
        *    SD ---> DL <--------         
        *    ^                   |
        *    |                   |
        *    OD <--- JL <--------|--
        *                        |  |
        *    BV <---             |  |
        *    --->  LA ---> BU    |  |
        *          ^             |  |
        *          |             |  |
        *  SJ ---> SK ---> IV ---|  |
        *                           |
        *  <---------------         |
        *  SF ---> HT ---> NH ------|
        * */

    vector<string> cities_1 {"SD", "LA", "SK", "IV", "JL", "SF", 
                             "DL", "HT", "OD", "NH", "BV", "SJ", "BU"};
                        
    
    vector<pair<string, string>> trainRoutes;

    trainRoutes.emplace_back("JL", "OD");
    trainRoutes.emplace_back("OD", "SD");
    
    trainRoutes.emplace_back("SD", "DL");
    trainRoutes.emplace_back("BV", "LA");
    
    trainRoutes.emplace_back("LA", "BV");
    trainRoutes.emplace_back("LA", "BU");
    
    trainRoutes.emplace_back("SK", "IV");
    trainRoutes.emplace_back("SK", "LA");
    
    trainRoutes.emplace_back("SJ", "SK");
    trainRoutes.emplace_back("IV", "DL");
    
    trainRoutes.emplace_back("SF", "HT");
    trainRoutes.emplace_back("HT", "NH");
    
    trainRoutes.emplace_back("NH", "SF");
    trainRoutes.emplace_back("NH", "JL");

    //

    vector<CityNode> cities = ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_1, trainRoutes);

    // cities returned from the above call are sorted according to 
    // the ascending order of the city names and 
    // the descending order of the size of reachableCities starting from those cities
    
    asserts(cities.at(0).getCity() == "HT", "First city should be HT");
    //Reachable cities from HT are [HT, NH, SF, JL, OD, SD, DL]
    asserts(cities.at(0).getReachableCities().size() == 7, "Train starting from city HT can reach 7 cities"); 
    
    asserts(cities.at(1).getCity() == "NH", "Second city should be NH");
    //Reachable cities from NH are [NH, SF, HT, JL, OD, SD, DL]
    asserts(cities.at(1).getReachableCities().size() == 7, "Train starting from city NH can reach 7 cities");
    
    asserts(cities.at(2).getCity() == "SF", "Third city should be SF");
    //Reachable cities from SF are [SF, HT, NH, JL, OD, SD, DL]
    asserts(cities.at(2).getReachableCities().size() == 7, "Train starting from city SF can reach 7 cities");
    
    asserts(cities.at(3).getCity() == "SJ", "Fourth city should be SJ");
    //Reachable cities from SJ are [SJ, SK, IV, DL, LA, BV, BU]
    asserts(cities.at(3).getReachableCities().size() == 7, "Train starting from city SJ can reach 7 cities");

    asserts(cities.at(4).getCity() == "SK", "Fifth city should be SK");
    //Reachable cities from SK are [SK, IV, DL, LA, BV, BU]
    asserts(cities.at(4).getReachableCities().size() == 6, "Train starting from city SK can reach 6 cities");
    
    asserts(cities.at(5).getCity() == "JL", "Sixth city should be JL");
    //Reachable cities from JL are [JL, OD, SD, DL]
    asserts(cities.at(5).getReachableCities().size() == 4, "Train starting from city JL can reach 4 cities");
    
    asserts(cities.at(6).getCity() == "BV", "Seventh city should be BV");
    //Reachable cities from BV are [BV, LA, BU]
    asserts(cities.at(6).getReachableCities().size() == 3, "Train starting from city BV can reach 3 cities");
        
    asserts(cities.at(7).getCity() == "LA", "Eighth city should be LA");
    //Reachable cities from LA are [LA, BV, BU]
    asserts(cities.at(7).getReachableCities().size() == 3, "Train starting from city LA can reach 3 cities");

    asserts(cities.at(8).getCity() == "OD", "Ninth city should be OD");
    //Reachable cities from OD are [OD, SD, DL]
    asserts(cities.at(8).getReachableCities().size() == 3, "Train starting from city OD can reach 3 cities");

    asserts(cities.at(11).getCity() == "BU", "Twelfth city should be BU");
    //Reachable cities from BU are [BU]
    asserts(cities.at(11).getReachableCities().size() == 1, "Train starting from city BU can reach 1 city");

    cout << "\nGiven test cases have passed\n" << endl;

    //Below are my implemented Test Cases:

    vector<string> cities_2 {"ZX", "WV", "NY", "FL"}; 

    vector<pair<string, string>> trainRoutesTwo; 

    trainRoutesTwo.emplace_back("WV","FL");
    trainRoutesTwo.emplace_back("NY","ZX");
    trainRoutesTwo.emplace_back("WV","ZX");
    trainRoutesTwo.emplace_back("FL","NY");


    vector<CityNode> secondCities = ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_2, trainRoutesTwo);

    cout << "\n\nBELOW ARE CUSTOM TEST CASES\n\n" << endl;

    cout << "First Test\n" << endl;
    
    asserts(secondCities.at(0).getCity() == "WV", "First city should be WV");
    asserts(secondCities.at(0).getReachableCities().size() == 4, "Train starting from city WV can reach 4 cities\n");

    asserts(secondCities.at(1).getCity() == "FL", "Second city should be FL");
    asserts(secondCities.at(1).getReachableCities().size() == 3, "Train starting from city FL can reach 3 cities\n");

    asserts(secondCities.at(2).getCity() == "NY", "Third city should be NY");
    asserts(secondCities.at(2).getReachableCities().size() == 2, "Train starting from city WV can reach 2 cities\n");

    asserts(secondCities.at(3).getCity() == "ZX", "Fourth city should be ZX");
    asserts(secondCities.at(3).getReachableCities().size() == 1, "Train starting from city WV can reach 1 city\n");

    vector<string> cities_3 {"DF"}; 

    vector<pair<string, string>> trainRoutesThree; 

    trainRoutes.emplace_back("DZ","BG");

    vector<CityNode> thirdCities = ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_3, trainRoutesThree);
    
    
    cout << "\nSecond Test\n" << endl;

    asserts(thirdCities.at(0).getCity() == "DF", "First city should be DF");
    asserts(thirdCities.at(0).getReachableCities().size() == 1, "Train starting from city DF can reach 1 city");


    vector<string> cities_4 {"AS", "DH", "SQ", "LO", "OP", "ER", 
                             "QW", "HJ", "BN", "RR", "BR", "PL", 
                             "IO","SD", "LA", "SK", "IV", "JL", "SF", 
                             "DL", "HT", "OD", "NH", "BV", "SJ", "BU"};

    vector<pair<string, string>> trainRoutesFour;

    trainRoutesFour.emplace_back("JL", "OD");
    trainRoutesFour.emplace_back("OD", "SD");
    trainRoutesFour.emplace_back("SD", "DL");
    trainRoutesFour.emplace_back("BV", "LA");
    trainRoutesFour.emplace_back("LA", "BV");
    trainRoutesFour.emplace_back("LA", "BU");
    trainRoutesFour.emplace_back("SK", "IV");
    trainRoutesFour.emplace_back("SK", "LA");
    trainRoutesFour.emplace_back("SJ", "SK");
    trainRoutesFour.emplace_back("IV", "DL");    
    trainRoutesFour.emplace_back("SF", "HT");
    trainRoutesFour.emplace_back("HT", "NH");
    trainRoutesFour.emplace_back("NH", "SF");
    trainRoutesFour.emplace_back("NH", "JL");
    trainRoutesFour.emplace_back("AS", "BR");
    trainRoutesFour.emplace_back("ER", "RR");
    trainRoutesFour.emplace_back("SD", "AS");
    trainRoutesFour.emplace_back("PL", "BN");
    trainRoutesFour.emplace_back("NH", "QW");
    trainRoutesFour.emplace_back("LA", "IV");

    vector<CityNode> FourthCities = ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(cities_4, trainRoutesFour);
    
    cout << "\nThird Test\n" << endl;
    
    asserts(FourthCities.at(0).getCity() == "SF", "First city should be SF");
    asserts(FourthCities.at(0).getReachableCities().size() == 10, "Train starting from city SF can reach 10 cities\n");

    asserts(FourthCities.at(3).getCity() == "SJ", "Fourth city should be SJ");
    asserts(FourthCities.at(3).getReachableCities().size() == 7, "Train starting from city SJ can reach 7 cities\n");

    asserts(FourthCities.at(4).getCity() == "SK", "Fifth city should be SK");
    asserts(FourthCities.at(4).getReachableCities().size() == 6, "Train starting from city SK can reach 6 cities\n");

    asserts(FourthCities.at(8).getCity() == "LA", "Ninth city should be LA");
    asserts(FourthCities.at(8).getReachableCities().size() == 5, "Train starting from city SF can reach 5 cities\n");

    asserts(FourthCities.at(12).getCity() == "IV", "Twelfth city should be IV");
    asserts(FourthCities.at(12).getReachableCities().size() == 2, "Train starting from city IV can reach 2 cities\n");

    asserts(FourthCities.at(25).getCity() == "BN", "Twenty-sixth city should be BN");
    asserts(FourthCities.at(25).getReachableCities().size() == 1, "Train starting from city BN can reach 1 city\n");



    // IMPORTANT:
    // TODO: write your own testing code similar to above as part of the coding required for assignment 4
    
    // IMPORTANT: You should construct at least one different city graph similar to the one above
    //
    // Also make sure to construct graphs for testing the edge cases, 
    // such as empty graph (NO node), one node graph, two nodes graph, etc.

    cout << endl << "All test cases passed!\n" << endl;

    // Return EXIT_SUCCESS exit code
    exit(EXIT_SUCCESS);
}