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
	if (*max_element(all(cnts)) > R*C / 2) {
		cout << "impossible" << endl;
	} else {
		sort(all(S));
		reverse(all(S));
		rep(offset,0,2) {
			rep(i,0,R) {
				rep(j,0,C/2) {

					int tj = (j*2 + (offset + i%2)%2);
					bool p1 = S[0].first,
						 p2 = S[1].first;
					rep(k,0,4) {
						int ni = i + dx[k];
						int nj = tj + dy[k];
						if (ni >= 0 && nj >= 0 && ni < R && nj < C) {
							if (S[0].second == G[ni][nj]) p1 = false;
							if (S[1].second == G[ni][nj]) p2 = false;
						}
					}
					int w = p1 ? 0 : (p2 ? 1 : 2);
					if (!S[w].first) break;
					S[w].first--;
					G[i][tj] = S[w].second;
				}
			}
		}
		trav(it, G) cout << it << endl;
		rep(i,0,R) rep(j,0,C) {
			cnts[G[i][j]-'A']--;
			rep(k,0,4) {
				int ni = i + dx[k];
				int nj = j + dy[k];
				if (ni >= 0 && nj >= 0 && ni < R && nj < C) {
					if (G[i][j] == G[ni][nj]) assert(false);
					if (G[i][j] < 'A' || G[i][j] > 'C') assert(false);
				}
			}
		}
		trav(it, cnts) assert(it == 0);
	}
}

signed main() {
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int R, C;
	cin >> R >> C;
	vi cnts(3);
	rep(i,0,3) cin >> cnts[i];
	sol(R, C, cnts);
}
