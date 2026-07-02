#include <bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int x;
        cin >> x;
        
        int y = 1;
        while (x) {
            x /= 10;
            y *= 10;
        }
        cout << y + 1 << '\n';
    }
    return 0;
}