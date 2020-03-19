#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define Min(...) min({__VA_ARGS__})
#define Max(...) max({__VA_ARGS__})
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
static inline ll sgn(ll x) { return (x>0)-(x<0); }
static inline bool vowel(char c) { c = (char)tolower(c); return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'y'; }
static inline vi rvi(int N) { vi res(N); rep(i,0,N) cin >> res[i]; return res; }
static inline int ri() { int N; cin >> N; return N; }
static inline void pvi(const vi& r) { trav(it,r) cout << it << " "; cout << endl; }
template<class S, class T> static inline void smax(S& s, const T& t) { if (t > s) s = t; }
template<class S, class T> static inline void smin(S& s, const T& t) { if (t < s) s = t; }
template<class S> static inline void in(S& s) { cin >> s; }
template<class S> static inline void ut(const S& s) { cout << s << " "; }
static inline void nl() { cout << endl; }

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

void sol(int R, int C, vi cnts) {
	vector<string> G(R, string(C, ' '));
	vector<pair<int, char>> S(3);
	rep(i,0,3) {
		S[i].first = cnts[i];
		S[i].second = 'A' + i;
	}
	sort(all(S));
	swap(S[1], S[2]);
	if (S[0].first > R*C / 2) {
		cout << "impossible" << endl;
	} else {
		int at = 0;
		rep(offset,0,2) {
			rep(i,0,R) {
				rep(j,0,C/2) {
					if (S[at].first == 0) ++at;
					S[at].first--;
					G[i][j*2 + (offset + i%2)%2] = S[at].second;
				}
			}
		}
		trav(it, G) cout << it << endl;
		rep(i,0,R) rep(j,0,C) {
			rep(k,0,4) {
				int ni = i + dx[k];
				int nj = j + dy[k];
				if (ni >= 0 && nj >= 0 && ni < R && nj < C) {
					// if (G[i][j] == G[ni][nj]) assert(false);
				}
			}
		}
	}
}

signed main() {
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	if (1) {
	int R, C;
	cin >> R >> C;
	vi cnts(3);
	rep(i,0,3) cin >> cnts[i];
	sol(R, C, cnts);
	return 0;
	}
	srand(time(NULL));
	rep(it,0,1000) {
		int R = (rand()%5 + 1) * 2;
		int C = (rand()%5 + 1) * 2;
		vi cnts(3);
		int cur = R * C;
		rep(k,0,2) {
			cnts[k] = rand() % (cur + 1);
			cur -= cnts[k];
		}
		cnts[2] = cur;
		assert(accumulate(all(cnts), 0) == R * C);
		sol(R, C, cnts);
	}
}
