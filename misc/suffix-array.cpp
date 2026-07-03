#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    s += '$';

    // Step 1. Map char to ints
    vector<pair<char, int>> ch_to_idx;
    for ( int i = 0; i < s.size(); i++ ) ch_to_idx.push_back({s[i], i});
    sort(ch_to_idx.begin(), ch_to_idx.end()); // sorts lexicographically
    
    // build initial equivalency vector
    vector<int> idx_to_val(s.size()); // maps idx to its equivalency value
    int j{};
    idx_to_val[ch_to_idx[0].second] = j;
    for ( int i = 1; i < s.size(); i++ ) {
        if (ch_to_idx[i].first != ch_to_idx[i-1].first) {
            // different character
            j++;
        }
        idx_to_val[ch_to_idx[i].second] = j;
    }




    // Step 2: Increase intervals by powers of 2
    int k = 0;
    while ( (1 << k) < s.size() ) {
        vector<pair<pair<int, int>, int>> itv_to_idx;
        for ( int i = 0; i < s.size(); i++ ) {
            itv_to_idx.push_back( { { idx_to_val[i], idx_to_val[(i + (1<<k)) % s.size()]} , i} );
        }
        sort(itv_to_idx.begin(), itv_to_idx.end());

        int val{};
        idx_to_val[itv_to_idx[0].second] = val;
        for ( int i = 1; i < s.size(); i++ ) {
            // modify idx_to_val
            if (itv_to_idx[i-1].first != itv_to_idx[i].first) val++;
            idx_to_val[itv_to_idx[i].second] = val;
        }
        k++;

        if ((1<<k) >= s.size()) {
            for (auto& [itv, idx] : itv_to_idx) cout << idx << " ";
        }
    }


    return 0;
}