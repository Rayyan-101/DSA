#include <bits/stdc++.h>
using namespace std;

void fillNeighbors(queue<string>& que, string& curr, unordered_set<string>& dead) {
    for (int i = 0; i < 4; i++) {
        char ch = curr[i];

        char dec = (ch == '0' ? '9' : ch - 1);
        char inc = (ch == '9' ? '0' : ch + 1);

        // Decrease
        curr[i] = dec;
        if (!dead.count(curr)) {
            dead.insert(curr);
            que.push(curr);
        }

        // Increase
        curr[i] = inc;
        if (!dead.count(curr)) {
            dead.insert(curr);
            que.push(curr);
        }

        curr[i] = ch;  // Restore state
    }
}

int openLock(vector<string>& deadends, string target) {
    unordered_set<string> dead(begin(deadends), end(deadends));

    string start = "0000";
    if (dead.count(start)) return -1;

    queue<string> que;
    que.push(start);
    dead.insert(start);

    int level = 0;

    while (!que.empty()) {
        int n = que.size();

        while (n--) {
            string curr = que.front();
            que.pop();

            if (curr == target)
                return level;

            fillNeighbors(que, curr, dead);
        }
        level++;
    }

    return -1;
}

int main() {
    int d;
    cin >> d;

    vector<string> deadends(d);
    for (int i = 0; i < d; i++) cin >> deadends[i];

    string target;
    cin >> target;

    cout << openLock(deadends, target) << "\n";

    return 0;
}
