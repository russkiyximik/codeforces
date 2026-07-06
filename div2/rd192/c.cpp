#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        unordered_map<int, int> freq;
        for ( int i = 0; i < n; i++ ) {
            int cur; cin >> cur; freq[cur]++;
        }

        // Loop from max frequency element to min and see
        // if we can construct an array of length k with 
        // the values in between
        // Ex: for frequencies a, b, c, we have
        // k == (a + x) + (b + x) + (c + x)   -->   (k - a - b - c) % 3 == 0
        // What if we subtract an element out? That's the point of the loop.

        vector<int> sizes;
        for ( auto& [key, val] : freq ) {
            sizes.push_back(val);
        }
        sort(sizes.begin(), sizes.end());

        long long total{};
        for ( int s : sizes ) total += s;
        int ans{};

        for ( int i = 0; i < sizes.size(); i++ ) {
            long long C = sizes.size() - i;
            long long dif = k - total;

            if ( dif % C == 0) {
                long long x = dif / C;
                // x cannot be greater than or equal to our smallest block
                if (sizes[i] + x >= 1) ans++;
            }
            total -= sizes[i]; // doesn't check total==0 obv    
        }

        cout << ans << '\n';     
    }

    return 0;
}