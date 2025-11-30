#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<string, vector<string>> adj;
    vector<string> route;
    int numTickets = 0;

    bool DFS(const string &fromAirport, vector<string>& temp) {
        temp.push_back(fromAirport);
        
        // If we have used all tickets (numTickets edges), path length = numTickets + 1
        if ((int)temp.size() == numTickets + 1) {
            route = temp;
            return true;
        }
        
        vector<string>& neighbors = adj[fromAirport];
        
        // Try neighbors in lexical order (already sorted)
        for (int i = 0; i < (int)neighbors.size(); i++) {
            string toAirport = neighbors[i];

            // Remove this ticket so we don't reuse it
            neighbors.erase(neighbors.begin() + i);

            if (DFS(toAirport, temp))
                return true;

            // Backtrack: restore ticket
            neighbors.insert(neighbors.begin() + i, toAirport);
        }

        temp.pop_back();
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        adj.clear();
        route.clear();

        numTickets = (int)tickets.size();
        
        for (auto &t : tickets) {
            string u = t[0];
            string v = t[1];
            adj[u].push_back(v);
        }
        
        // Sort adjacency lists to ensure lexicographically smallest route
        for (auto &edges : adj) {
            sort(edges.second.begin(), edges.second.end());
        }
        
        vector<string> temp;
        DFS("JFK", temp);
        return route;
    }
};

int main() {
    Solution sol;

    vector<vector<string>> tickets = {
        {"MUC","LHR"},
        {"JFK","MUC"},
        {"SFO","SJC"},
        {"LHR","SFO"}
    };

    vector<string> ans = sol.findItinerary(tickets);

    cout << "Itinerary: ";
    for (auto &s : ans) cout << s << " ";
    cout << endl;
    // Expected: JFK MUC LHR SFO SJC

    return 0;
}
