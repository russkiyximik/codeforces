#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

ll s, t;

ll eval(string& S, int m) {
    ll T = 0, ans = 0;

    for (char c : S) {
        if (c == 'I') {
            if (T < t) {
                T++;
                ans++;
            }
        }
        else if (c == 'E') {
            if (ans < T * s) ans++;
        }
        else {
            if (m-->0) {
                if (T < t) {
                    T++;
                    ans++;
                }
            }
            else {
                if (ans < T * s) ans++;
            }
        }
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n >> t >> s;
        
        string S;
        cin >> S;

        int l = 0, r = 0;
        for (char c : S) if (c=='A') r++;

        ll ans = 0;
        for (int i = l; i <= r; i++) ans = max(ans, eval(S, i));

        cout << ans << endl;
    }

    return 0;
}