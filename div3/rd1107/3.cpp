#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int c{};
        int n; string s;
        cin >> n >> s;

        for ( size_t i = 1zu; i < n; i++ ) {
            if ( s[i] != s[i-1] ) c++;
        }

        cout << ((c == 1) ? 2 : 1) << '\n';
    }

    return 0;
}