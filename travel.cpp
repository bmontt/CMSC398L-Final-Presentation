#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Counts the number of paths with total travel time exactly K
int countExactTimePaths(const vector<vector<int>>& travelTimes, int exactTime) {
    int numCities = travelTimes.size(); // Number of cities
    vector<int> cityOrder(numCities - 1); // Order of visiting cities, excluding City 1
    for (int i = 0; i < numCities - 1; i++) {
        cityOrder[i] = i + 1; // Initialize city order, starting from City 2
    }

    int pathCount = 0; // Number of valid paths
    do {
        int totalTime = travelTimes[0][cityOrder[0]]; // Time from City 1 to the first city in the order
        // Calculate total travel time for the current city order
        for (int i = 0; i < numCities - 2; i++) {
            totalTime += travelTimes[cityOrder[i]][cityOrder[i + 1]];
        }
        totalTime += travelTimes[cityOrder[numCities - 2]][0]; // Time to return to City 1

        if (totalTime == exactTime) {
            pathCount++; // Increment count if total time matches exactTime
        }
    } while (next_permutation(cityOrder.begin(), cityOrder.end())); // Generate next city order

    return pathCount;
}

int main() {
    // desynchronize I/O to make code faster
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numCities, targetTime;
    cin >> numCities >> targetTime;

    vector<vector<int>> travelTimes(numCities, vector<int>(numCities));
    // Reading the travel time matrix
    for (int i = 0; i < numCities; i++) {
        for (int j = 0; j < numCities; j++) {
            cin >> travelTimes[i][j];
        }
    }

    // Outputs the number of paths with total travel time exactly equal to targetTime
    cout << countExactTimePaths(travelTimes, targetTime) << "\n";

    return 0;
}
