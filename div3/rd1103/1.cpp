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
        int height_max = -1;
        int height_min = (1U << 31) - 1;

        while (n--) {
            int num;
            cin >> num;
            if (num > height_max) height_max = num;
            if (num < height_min) height_min = num;
        }

        cout << height_max - height_min + 1 << endl; // max height must be increased by 1
    }
    return 0;
}