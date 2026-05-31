#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> frnds;

        while (n--) {
            long long x;
            cin >> x;
            frnds.push_back(x);
        }

        std::sort(frnds.begin(), frnds.end());
        int mid = frnds.size()/2;
        int ans = 0;

        for (int i = 0; i < mid; i++) {
            int j = frnds.size() - 1 - i;
            if (frnds[i] != frnds[mid] || frnds[j] != frnds[mid]) {
                frnds[i] = frnds[mid]; 
                frnds[j] = frnds[mid];
                ans++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}