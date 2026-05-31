#include <bits/stdc++.h>
using namespace std;

// TODO: REWRITE USING GREEDY ONCE I LEARN GREEDY

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, x, s;
        cin >> n >> x >> s;
        vector<string> tables(x);
        
        string mystr;
        cin >> mystr;
        int i = 0;
        int ans = 0;
        for (char c : mystr) {
            if (c == 'I') {
                while (i < x) {
                    if (tables[i] == "") {
                        tables[i] += c;
                        ans++;
                        break;
                    }
                    i++;
                }
            }
            else if (c == 'E') {
                while (i < x) {
                    if (!tables[i].empty() && tables[i].size() < s) {
                        tables[i] += c;
                        ans++;
                        break;
                    }
                    i++;
                }
            }
            else {
                while (i < x) {
                    if (tables[i].size() < s) {
                        tables[i] += c;
                        ans++;
                        break;
                    }
                    i++;
                }
            }

            i=0;
        }

        cout << ans << endl;
    }

    return 0;
}