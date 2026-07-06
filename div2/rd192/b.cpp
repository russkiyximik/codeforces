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

        // track prefixes
        vector<int> left_pref(nums.size(), -1);
        nums[0] == 1 ? left_pref[0]=1 : left_pref[0]=-1;
        for ( int i = 1; i < nums.size(); i++ ) {
            if (nums[i]==1) left_pref[i] = left_pref[i-1]+1;
            else left_pref[i] = left_pref[i-1]-1;
        }
        // valid split 1->2 occurs every time we hit 0
    
        vector<int> mid_pref(nums.size(), -1);
        nums[0] != 3 ? mid_pref[0]=1 : mid_pref[0]=-1;
        for ( int i = 1; i < nums.size(); i++ ) {
            if (nums[i]!=3) mid_pref[i] = mid_pref[i-1]+1;
            else mid_pref[i] = mid_pref[i-1]-1;
        }

        for ( int i = 0; i < nums.size() - 2; i++ ) {
            if (left_pref[i]<0) continue;
            int start = mid_pref[i]; // subtract this from mid_pref[j]
            // O(n^2)
            for ( int j = i+1; j < nums.size() - 1; j++ ) {
                if (mid_pref[j]-start < 0) continue;
                cout << "YES\n";
                goto skip;
            }
        }
        cout << "NO\n";
        skip: continue;
    }

    return 0;
}