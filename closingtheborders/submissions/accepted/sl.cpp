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
	int N, M;
	cin >> N >> M;
	vi s(N), t(N);
	rep(i,0,N) cin >> s[i] >> t[i];
	vector<pii> ed;
	rep(i,0,M) {
		int a, b;
		cin >> a >> b;
		ed.emplace_back(a, b);
	}
	vector<double> prob(N), prob2(N);
	prob[0] = 1;
	double res = 0;
	rep(it,0,N) {
		prob2.assign(N, 0);
		trav(pa, ed) {
			int a = pa.first, b = pa.second;
			int day = it + 1;
			if (day >= t[a]) continue;
			double probGetOut = 1;
			if (day >= s[a]) {
				probGetOut = 1 - (day - s[a]) / (double)(t[a] - s[a]);
			}
			if (b == N-1) {
				// day++;
				if (day >= t[b]) continue;
				if (day >= s[b]) {
					probGetOut *= 1 - (day - s[b]) / (double)(t[b] - s[b]);
				}
			}
			prob2[b] = max(prob2[b], prob[a] * probGetOut);
		}
		prob = prob2;
		res = max(res, prob2[N-1]);
	}
	cout << setprecision(20) << fixed << res << endl;
	exit(0);
}
