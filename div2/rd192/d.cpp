#include <bits/stdc++.h>

using namespace std;

void update(int& x, int y) {
    if ( x < y ) x = y;
}

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<int> pa (n + 1, 0), pb (m + 1, 0); // prefix arrays

    pa[0] = 0, pb[0] = 0;
    for ( int i = 1; i <= n; i++ ) {
        pa[i] = (pa[i-1] + a[i-1] - '0') % 10;
    }
    for ( int i = 1; i <= m; i++ ) {
        pb[i] = (pb[i-1] + b[i-1] - '0') % 10;
    }
    // if we can make these prefix sums equal, 
    // we can make the strings equal

    n++; m++;
    // first and last elements of pref arrays are const
    if (pa.back() != pb.back()) {
        cout << -1 << '\n';
        return;
    }

    // find LCS (longest common subsequence)
    vector<vector<int>> dp (n + 1, vector<int> (m + 1));
    for ( int i = 0; i <= n; i++ ) {
        for ( int j = 0; j <= m; j++ ) {
            if (i < n) update(dp[i+1][j], dp[i][j]);
            if (j < m) update(dp[i][j+1], dp[i][j]);
            if (i < n && j < m && pa[i] == pb[j]) {
                update(dp[i+1][j+1], dp[i][j] + 1);
            }
        }
    }
    // - 1 to remove the pa[0] == pb[0] == 0 match
    cout << dp[n][m] - 1 << '\n';
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