#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	cin.exceptions(cin.failbit);
	int N, P;
	cin >> N >> P;
	ll maxt = 0;
	ll sumt = 0;
	rep(i,0,N) {
		ll t;
		cin >> t;
		maxt = max(maxt, t);
		sumt += t;
	}
	cout << sumt + (P-1) * maxt << endl;
	exit(0);
}
