#include "connectedcities.h"
#include <map>

using namespace std;

/**
*
* I the undersigned promise that the submitted assignment is my own work. While I was 
*  free to discuss ideas with others, the work contained is my own. I recognize that 
*  should this not be the case; I will be subject to penalties as outlined in the course 
*  syllabus. 
*   Name: Jacob Holloway
*   Red ID: 827294826
*
*
**/


/**
 * <p>
 * Part A 
 * ---------------------------------------------------------------------------------------
 * For each city in a city list, find the list of reachable cities starting from the city 
 * following the train routes, and sort the cities in the descending order based on the 
 * number of their reachable cities.  
 * 
 * Required specifications - 
 *
 * Given a list of cities, and a list of one-way train routes from one city to another:
 *
 * 1) Create a graph with each node in the graph as an instance of the CityNode class,
 *    the graph can use any STL collection by your choice.
 *
 * 2) Populate the direct routes information to each CityNode's directRoutedCities collection.
 *    This is like an adjacency list graph representation.
 *
 * 3) For each city node in the graph, use Depth First Search algorithm to find all reachable 
 *    cities starting from the city following the train routes and store those reachable cities to 
 *    the CityNode's reachableCities collection. 
 *
 *    IMPORTANT: The reachable cities must include the starting city itself.  
 *
 *    Note: The train route can go from the starting city and stop at several cities 
 *          before reaching the destination city, all cities including the starting city and 
 *          the destination city along the path would be counted as reachable cities from 
 *          the city where the train starts.
 *
 * 4) Sort the cities in the descending order based on the number of their reachable cities,
 *    so that after sorting, starting from the first city in the sorted order, the train can 
 *    reach the greatest number of destination cities following the given one-way routes. 
 *
 * 5) You must use a RECURSIVE algorithm to implement the Depth First Search part to find
 *    all reachable cities from a starting city given the train routes, using an iterative 
 *    approach would result in a 30% penalty to your assignment 4 grade.  
 *
 * 6) You may add necessary helper functions as needed. Follow the comments for hints.
 * 
 * Assumptions - 
 * 1) Each city is represented by a unique two-letter code like "SD", "LA", 
 *    "SF", "SJ", "NY", etc.
 * 2) Each one-way train route is represented by a pair of city codes; for example, 
 *    route {"SD", "LA"} means train can drive one-way from San Diego (SD) to 
 *    Los Angeles (LA). 
 *
 * <p>
 * Part B
 * ---------------------------------------------------------------------------------------
 * Show the upper bound of the time complexity of this function would be O(c^2 + c * r) 
 * where:
 * c is the number of cities
 * r is the number of direct routes between cities
 * 
 * ---------------------------------------------------------------------------------------
 * @param  cities  a list of cities with each city identified by a two letter code
 * @param  routes  pairs of one-way train routes with each one-way train route represented 
 *                 by a pair of city codes; for example, route {"SD", "LA"} means train 
 *                 can go one-way from San Diego (SD) to Los Angeles (LA).
 *
 *                 NOTE: examples of routes are { {"SD", "LA"},
 *                                                {"LA", "SJ"},
 *                                                {"SJ", "SF"}
 *                                              }   
 *                       refer to driver.cpp for more examples.  
 *
 * @return       A list of CityNode in the descending order based on the number of their 
 *               reachable cities following the train routes
 
* @see         
*/

 

void depthFirstSearch(unordered_map<string, CityNode>& cityGraph, unordered_set<string>& visited, string currentCity, vector<string>& reachableCities) 
{
    if (cityGraph.find(currentCity) == cityGraph.end()) //if starting city is not in the map then it will explore it.
    {
        cout << currentCity << " is not in graph" << endl;
        return;
    }
    CityNode& toExplore = cityGraph.at(currentCity);
   
    if (visited.count(currentCity) == 0) //if there is nothing in vistied then add the current city to the visited list.
    { 
        // add currentCity to visited set
        visited.insert(currentCity);
        reachableCities.push_back(currentCity); // add the city to the list of reachable cities.

        // Get the direct routed cities of the current city in a vector
        // This avoids calling the getDirectRoutedCities() function multiple times
        const vector<string>& directRoutedCities = toExplore.getDirectRoutedCities();
        for (auto reachableCity : directRoutedCities) // recursive call on the reachable cities.
        {
            depthFirstSearch(cityGraph, visited, reachableCity, reachableCities);
        }
    }
    return;
}




bool sizeCityCompare(CityNode first, CityNode second){
  return (first.getReachableCities().size() > second.getReachableCities().size());
}

bool alphabetCompare(CityNode first, CityNode second){
  return (first.getCity().compare(second.getCity()) < 0);
}



vector<CityNode> ConnectedCities::citiesSortedByNumOf_Its_ReachableCities_byTrain(vector<string> cities, vector<pair<string, string>> trainRoutes) {
    // Use a map instead of an unordered_map to store the CityNode objects
    map<string,CityNode> routes;
    

    // Create a CityNode object for each city
    for (auto city : cities) {
        routes.emplace(city, CityNode(city));
    }

    // Create an adjacency list to represent the train routes
    unordered_map<string, vector<string>> adjList;
    for (auto route : trainRoutes) {
        // Add the train route to the adjacency list
        adjList[route.first].push_back(route.second);
        adjList[route.second].push_back(route.first); // add the reverse route as well
    }

    // Use an iterative DFS to find the reachable cities for each CityNode
    for (auto& route : routes) {
        // Use a set to store the reachable cities
        unordered_set<string> visitedCities;
        // Use a stack to store the cities to visit
        stack<string> citiesToVisit;

        // Get the city and CityNode object from the current route
        string city = route.first;
        CityNode& node = route.second;

        // Start the DFS at the current city
        citiesToVisit.push(city);
        while (!citiesToVisit.empty()) {
            // Get the next city to visit
            string currentCity = citiesToVisit.top();
            citiesToVisit.pop();

            // Skip the city if it has already been visited
            if (visitedCities.count(currentCity) > 0) {
                continue;
            }

            // Add the city to the set of visited cities
            visitedCities.insert(currentCity);

            // Add the city's neighbors to the stack of cities to visit
            for (auto neighbor : adjList[currentCity]) {
                citiesToVisit.push(neighbor);
            }
        }

        // Set the reachable cities for the current CityNode
        node.setReachableCities(vector<string>(visitedCities.begin(), visitedCities.end()));
    }

    // Create a vector of CityNode objects and sort it by the number of reachable cities
    vector<CityNode> cityStuff;
for (auto& route : routes) {
    cityStuff.push_back(route.second);
}

    sort(cityStuff.begin(), cityStuff.end(), sizeCityCompare);

    return cityStuff;
}


















// Write your implementation here.
    
  // Follow the steps in the specification above to implement. 

  // You may want to implement each step in the above specification in 
  // a separate function.

  // Think what would be a good data structure to store the City Graph.
  // Each node/vertice represents a city and each has an adjacent list of cities
  // that can be reached directly from the city.
  // You can use a STL collection to store
  // the graph of city nodes, so that given a city code,
  // you can find the corresponding CityNode object instantaneously.
  // Think Which data structure would give you the best lookup ability
  // by using a key. 

  // Hint for DFS:
  // You may want to use a separate function to implement the 
  // recursive Depth-First-Search algorithm for finding all reachable cities
  // starting from a city using its direct routes to other cities, and their
  // connected cities, and so on and so forth until all cities along
  // reachable paths are traversed.

  // Use the general approach described in zyBook 20.6 Graphs: Depth-first search
  // Follow what Figure 20.6.1 presents

  // A suggested separate recursive function for the DFS part could be:
  // void depthFirstSearchReachableCities(
  //      cityGraph, // a collection of a STL collection type  
  //      string startingCity, 
  //      vector<string> &reachableCities, // list of cities to add reachable cities along the recursive call  
  //      set<string> &visitedCities); // list of cities to track if a city is already visited along DFS search
  // what would be the base condition? --> the startingCity is already visited

  // Hint for sorting: descending order of number of reachable cities and 
  //                   ascending alphabetical order of the city code as the tiebreaker
  // you can leverage the std::sort()
  // one way to do the two-level of sorting here is to first sort the list 
  // by City code in ascending order, 
  // then sort by number of reachable cities in descending order. 


// vector<CityNode>() here is a placeholder, you need to change it to 
// whichever the vector your logic comes up with and return


