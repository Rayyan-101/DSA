class Solution {
  public:
    int query(int x, int lx, int rx, int l, int r, vector<int> &seg) {
        if(lx >= r || rx <= l) return 0;
        if(lx >= l && rx <= r) return seg[x];
        int m = (lx + rx) / 2;
        return query(2 * x + 1, lx, m, l, r, seg) + query(2 * x + 2, m, rx, l, r, seg);
    }
    void update(int x, int lx, int rx, int idx, int val, vector<int> &seg) {
        if(rx - lx == 1) {
            seg[x] += val;
            return;
        }
        int m = (lx + rx) / 2;
        if(idx < m) update(2 * x + 1, lx, m, idx, val, seg);
        else update(2 * x + 2, m, rx, idx, val, seg);
        seg[x] = (seg[2 * x + 1] + seg[2 * x + 2]);
    }
  public:
    int countSubstring(string &s) {
        // Code Here
        int n = s.length(), ans = 0;
        vector<int> seg(8 * n, 0);
        update(0, 0, 2 * n, n, 1, seg);
        for(int i = 0, x = 0; i < n; i++) {
            x += ((s[i] == '0') ? -1 : 1);
            ans += query(0, 0, 2 * n, 0, x + n, seg);
            update(0, 0, 2 * n, x + n, 1, seg);
        }
        return ans;
    }
};
