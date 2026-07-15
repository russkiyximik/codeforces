#include <bits/stdc++.h>
using namespace std;

void solve() {
    typedef long long ll;
    ll n;
    cin >> n;
    vector<ll> books(n);
    for ( size_t i = 0uz; i < n; i++ ) {
        ll cur;
        cin >> cur;
        books[i] = cur;
    }
    for ( size_t i = 1uz; i < n; i++ ) {
        // move diff books from books[i-1] to books[i]
        ll diff = books[i-1] - i;
        books[i-1] -= diff;
        books[i] += diff;
        if ( books[i-1] >= books[i] ) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
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