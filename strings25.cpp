class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for (char c : word)
            freq[c - 'a']++;

        // we need to store values as pairs char, frequency of character
        vector<pair<char, int>> arr;

        for (int i = 0; i < 26; i++)
            arr.push_back({i + 'a', freq[i]});

        // now we sort in non-increasing order as we will put the maximum
        // occuring character in the first most position available on the keypad

        sort(arr.begin(), arr.end(), [](const auto& a, auto& b) {
            return a.second > b.second;
        });

        int res = 0, n = arr.size();

        for (int i = 0; i < n; i++)
            res += arr[i].second * (i/8 + 1);
        
        return res;
    }
};
