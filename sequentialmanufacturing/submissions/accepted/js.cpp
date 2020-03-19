#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
    ll N, M;
    cin >> N >> M;
    ll ts = 0, mt = 0;
    rep(i,0,N) {
        ll t;
        cin >> t;
        ts += t;
        mt = max(t, mt);
    }
    cout << ts + (M - 1) * mt << endl;
}
