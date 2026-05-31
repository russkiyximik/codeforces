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
        vector<long long> hts(n);
        long long sum = 0;
        long long carry = 0;

        for (int i = 0; i < n; i++) {
            long long num;
            cin >> num;
            if (carry) {num += carry; sum -= carry; carry = 0;}
            hts[i] = num;
            sum += num;

            // Base case
            if (i == 0) {cout << num << ' '; continue;}

            if (num < sum / (i+1)) {
                for (int j = 0; j <= i; j++) {
                    hts[j] = sum / (i+1);
                }
            }

            else if (num > sum / (i + 1)) {
                hts[i] = hts[i-1];
                carry = num - hts[i];
            }

            cout << hts[i] << " ";
        }
        cout << endl;
    }

    return 0;
}