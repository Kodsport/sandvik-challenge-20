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
    int N, M;
    cin >> N >> M;
    vi S(N), T(N);
    rep(i,0,N) cin >> S[i] >> T[i];
    vector<pii> G(M);
    rep(i,0,M) cin >> G[i].first >> G[i].second;
    vector<double> P(N);
    P[0] = 1;
    double ans = 0;
    rep(d,1,N+1) {
        vector<double> NP(N);
        trav(ed, G) {
            int to = ed.second;
            double pl = ((d + 1) - S[to]) / double(T[to] - S[to]);
            if (to == N - 1) 
                pl = (d - S[to]) / double(T[to] - S[to]);
            pl = max(min(1.0, pl), 0.0);
            NP[to] = max(P[ed.first] * (1 - pl), NP[to]);
        }
        P = NP;
        ans = max(P.back(), ans);
    }
    cout << setprecision(10) << fixed << ans << endl;
}
