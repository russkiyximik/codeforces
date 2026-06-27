#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;
        // distribute greedily
        long long total_popcount{};
        int p{}; // exponent
        while (1) {
            long long cur = k * (1 << p);
            if (n>=cur) {
                n -= cur;
                total_popcount += k;
                p++;
            }
            else {
                break;
            }
        }
        // all k slots are of value 2^p - 1, or (1 << p) - 1.
        // distribute current largest to as many slots as possible
        long long bit_val = (1LL << p);
        long long full_bits = n / bit_val; // calculates how many slots can afford bit 1<<p
        total_popcount += full_bits;

        cout << total_popcount << "\n"; // "\n" faster than endl
    }

    return 0;
}