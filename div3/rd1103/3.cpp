#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int a, b, x; 
        cin >> a >> b >> x;
        int ans{};

        while (a != b) {
            // Let's have b consistently be the bigger number
            if (b < a) swap(a, b);
            // we always need to consider (abs distance):
            // a - (b / x)
            // b - (a / x)
            // b - a
            // (b / x) - (a / x)
            // every division is one move.

            int b_div = a - (b / x) + 1;
            int a_div = b - (a / x) + 1;
            int dist = b - a;
            int div_dist = (b / x) - (a / x) + 2;
            
            if (min({b_div, a_div, dist, div_dist}) == div_dist) {
                b /= x;
                a /= x;
                ans += 2;
            }
            else if (min({b_div, a_div, dist, div_dist}) == b_div) {
                b /= x;
                ans++;
            }
            else if (min({b_div, a_div, dist, div_dist}) == a_div) {
                a /= x;
                ans++;
            }
            else {
                a++;
                ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}