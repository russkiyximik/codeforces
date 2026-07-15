#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; string s;
    cin >> n >> s;
    int max_len{}; int cur{};
    for ( int i = 0; i < n; i++ ) {
        if (s[i]=='#') cur++;
        else if (s[i]=='*') cur=0;
        max_len=max(max_len,cur);
    }
    cout << max_len/2 + max_len%2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
    return 0;
}