#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        // doing this operation on [l, r] changes element-wise like +1, -1, +1, -1, ...
        // therefore the prefix sum for some ai will always either increase by 1 or remain the same
        // for the interval [ai, a(i+1)] the pref. sum of ai += 1, and pref. sum of a(i+1) does not change
        // [ai, ai] increments ai by 1
        // so every pref. sum can be independently modified relative to other sums.
        int n; cin >> n;
        vector<long long> a (n), b (n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) cin >> b[i];

        /*
        for(int i = 1; i < n; i++) a[i] += a[i - 1];
        for(int i = 1; i < n; i++) b[i] += b[i - 1];

        bool flag = 0;
        for ( int i = 0; i < n; i++ ) {
            if (a[i] > b[i]) {flag = 1;}
        }
        cout << (flag ? "NO" : "YES") << '\n';
        */

        for ( int i = n-1; i>0; i-- ) {
            if ( a[i] > b[i] ) a[i-1] += (a[i] - b[i]);
        }
        cout << ((a[0] > b[0]) ? "NO" : "YES") << '\n';
    }

    return 0;
}