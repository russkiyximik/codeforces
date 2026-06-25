#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;
        // Let's try to solve w 2 pointers.
        string bitstr; cin >> bitstr;
        bool ans{1};

        for (int i = 0; i < n; i++) {
            if (bitstr[i] == '0') continue;

            int j = i + k;
            if (j >= n) {ans=0; break;}
            bitstr[i] = '0';
            bitstr[j] = ((bitstr[j] - '0') ^ 1) + '0'; // flip
        }

        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}