#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for ( int i = 0; i < n; i++ ) cin >> a[i];

    vector<int> lens;
    int cur = 1;
    for (int i = 1; i < n; i++) 
        if (a[i] != a[i - 1]) 
        {
            lens.push_back(cur);
            cur = 1;
        } 
        else cur++;
    lens.push_back(cur);
    sort(lens.begin(), lens.end());

    int m = (int)lens.size();
    int d = 0;

    int ans{};
    int i{};
    while ( i < m ) {
        int len = lens[i];
        int x = len - 1; // handles duplicates (see j)
        int q = m - i;
        int curLen = n - d - x * q;
        if (curLen <= k && (k - curLen) % q == 0) 
            ans++;
        
        int j = i;
        // efficiently handle blocks of duplicate length
        while ( j < m && lens[j] == len ) j++;
        d += (j - i) * lens[i];
        i = j;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for ( int i = 0; i < t; i++ ) {
        solve();
    }
    return 0;
}