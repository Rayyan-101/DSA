#include <bits/stdc++.h>
using namespace std;

void FloydWarshall(vector<vector<long long>> &adjMatrix, 
                   vector<char>& original, 
                   vector<char>& changed, 
                   vector<int>& cost) 
{
    // Update direct conversion costs
    for(int i = 0; i < original.size(); i++) {
        int s = original[i] - 'a';
        int t = changed[i] - 'a';

        adjMatrix[s][t] = min(adjMatrix[s][t], (long long)cost[i]);
    }

    // Apply Floyd–Warshall
    for (int k = 0; k < 26; ++k) {
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                if (adjMatrix[i][k] == LLONG_MAX || adjMatrix[k][j] == LLONG_MAX)
                    continue;
                adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]); 
            }
        }
    }
}

long long minimumCost(string source, string target, 
                      vector<char>& original,
                      vector<char>& changed, 
                      vector<int>& cost) 
{
    vector<vector<long long>> adjMatrix(26, vector<long long>(26, LLONG_MAX));

    // Zero cost to convert a letter to itself
    for(int i = 0; i < 26; i++) 
        adjMatrix[i][i] = 0;

    FloydWarshall(adjMatrix, original, changed, cost);

    long long ans = 0;

    for(int i = 0; i < source.length(); i++) {
        if(source[i] == target[i]) continue;

        long long best = adjMatrix[source[i] - 'a'][target[i] - 'a'];

        if(best == LLONG_MAX) return -1;  // Not possible

        ans += best;
    }

    return ans;
}

// ------------------ MAIN FUNCTION ---------------------

int main() {
    string source, target;
    int n;

    cout << "Enter source string: ";
    cin >> source;

    cout << "Enter target string: ";
    cin >> target;

    cout << "Enter number of conversions: ";
    cin >> n;

    vector<char> original(n), changed(n);
    vector<int> cost(n);

    cout << "Enter conversions (original changed cost):\n";
    for(int i = 0; i < n; i++) {
        cin >> original[i] >> changed[i] >> cost[i];
    }

    long long result = minimumCost(source, target, original, changed, cost);

    cout << "Minimum Cost = " << result << endl;

    return 0;
}
