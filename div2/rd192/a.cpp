#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int k; cin >> k;
        int num_2{};
        bool is_three{};
        int cur;
        while (k--) {
            cin >> cur;
            if (cur==2) num_2++;
            if (cur>=3) is_three=1;
        }

        if (num_2>=2 || is_three) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}