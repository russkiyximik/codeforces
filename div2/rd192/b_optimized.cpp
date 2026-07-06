#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int len; cin >> len;
        vector<int> nums;

        while (len--) {
            int cur; cin >> cur;
            nums.push_back(cur);
        }
        int n = nums.size();

        // track prefixes
        vector<int> left_pref(n, -1);
        nums[0] == 1 ? left_pref[0]=1 : left_pref[0]=-1;
        for ( int i = 1; i < n; i++ ) {
            if (nums[i]==1) left_pref[i] = left_pref[i-1]+1;
            else left_pref[i] = left_pref[i-1]-1;
        }
        // valid split 1->2 occurs every time we hit 0
    
        // valid split 2->3 occurs every time we hit 0
        vector<int> mid_pref(n, -1);
        nums[0] != 3 ? mid_pref[0]=1 : mid_pref[0]=-1;
        for ( int i = 1; i < n; i++ ) {
            if (nums[i]!=3) mid_pref[i] = mid_pref[i-1]+1;
            else mid_pref[i] = mid_pref[i-1]-1;
        }

        // tracks suffix max of mid_pref
        vector<int> suf_max(n, -1);
        suf_max[n-2] = mid_pref[n-2]; // we don't care about n-1 since we can't split 2->3 there
        // so we set to -1 so the program doesn't think it's a valid split
        for ( int i = n-3; i >= 0; i-- ) {
            suf_max[i] = max(mid_pref[i], suf_max[i+1]);
        }

        for ( int i = 0; i < n - 2; i++ ) {
            if (left_pref[i]<0) continue;
            // If at some j>i we have mid_pref[j] >= mid_pref[i] then we can split
            if (suf_max[i+1] >= mid_pref[i]) {
                cout << "YES\n";
                goto skip;
            }
        }
        cout << "NO\n";
        skip: continue;
    }

    return 0;
}