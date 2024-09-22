#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <cstdarg>
#include <cassert>
#include <ctime>
#include <tuple>
#include <unordered_set>
#include <unordered_map>
#include <random>
#include <chrono>

using namespace std;

#define ln '\n'
#define pb push_back
#define mp make_pair
#define ins insert
#define sz(x) (int)x.size()

#define All(x) (x).begin(), (x).end()
#define Allf(x) x.begin() + 1, x.end()
#define Alld(x) (x).rbegin(), (x).rend()

#define fi(a, b) for (auto i = (a); i <= (b); i++)
#define fj(a, b) for (auto j = (a); j <= (b); j++)
#define fo(a, b) for (auto o = (a); o <= (b); o++)
#define fw(a, b) for (auto w = (a); w <= (b); w++)

#define fdi(a, b) for (auto i = (a); i >= (b); i--)
#define fdj(a, b) for (auto j = (a); j >= (b); j--)
#define fdo(a, b) for (auto o = (a); o >= (b); o--)
#define fdw(a, b) for (auto w = (a); w >= (b); w--)

#define fx(A) for (auto &x : (A))
#define fy(A) for (auto &y : (A))
#define fz(A) for (auto &z : (A))

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ld> vd;
typedef vector<char> vc;
typedef vector<string> vs;

typedef vector<vb> vvb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vc> vvc;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

template<typename A, typename B>
ostream& operator<<(ostream& os, pair<A, B> p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}
 
template<typename T>
ostream& operator<<(ostream& os, vector<T> v) {
	fz(v) {
		os << z << " ";
	}
	return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector<vector<T>> v) {
	os << ln;
	fz(v) {
		os << z << ln;
	}
	return os;
}
 
template<typename T>
ostream& operator<<(ostream& os, set<T> t) {
	for (auto z : t) {
		os << z << " ";
	}
	return os;
}
 
template<typename T1, typename T2>
ostream& operator<<(ostream& os, map<T1, T2> t) {
	cerr << endl;
	for (auto z : t) {
		os << "\t" << z.first << " -> " << z.second << endl;
	}
	return os;
}
 
#ifdef LOCAL
#define dbg(x) {cerr << __LINE__ << "\t" << #x << ": " << (x) << endl;}
#else
#define dbg(x) {}
#endif
 
#ifdef LOCAL
#define ass(x) if (!(x)) { cerr << __LINE__ << "\tassertion failed: " << #x << endl, abort(); }
#else
#define ass(x) assert(x)
#endif

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

struct Rect {
	int x1, y1;
	int x2, y2;
};
struct Event {
	int val;
	int type;
	bool operator<(const Event& g) const {
		return mp(val, type) < mp(g.val, g.type);
	}
};
ostream& operator<<(ostream& os, Event x) {
	os << "{ " << x.val << ", " << x.type << " }";
	return os;
}

int n;
vector<Rect> v;
vvi e;
int CNT;
map<int, vector<Event>> X;
map<int, vector<Event>> Y;
set<pii> nodes;

void solve() {
	ll V = sz(nodes), E = 0;

	fz(X) {
		sort(All(z.second));
		int Q = 0;
		int q = 0;
		int prev = -1'000'000;
		fx(z.second) {
			if (x.val != prev) Q++;
			if (x.type == 1) q++;
			else if (x.type == 2) q--;
			if (q == 0) {
				E += Q - 1;
				Q = 0;
			}
			prev = x.val;
		}
		dbg(ln);
		dbg(mp(z.first, E));
		dbg(z.second);
	}
	fz(Y) {
		sort(All(z.second));
		int Q = 0;
		int q = 0;
		int prev = -1'000'000;
		fx(z.second) {
			if(x.val != prev) Q++;
			if(x.type == 1) q++;
			else if(x.type == 2) q--;
			if(q == 0) {
				E += Q - 1;
				Q = 0;
			}
			prev = x.val;
		}
		// dbg(mp(z, E));
	}
	dbg(CNT);
	dbg(E);
	dbg(V);
	ll ans = E + CNT + 1 - V;
	cout << ans << ln;
}

void init2() {
	fi(1, n) {
		fj(1, n) {
			if(i == j) continue;
			bool f1 = (v[i].y1 < v[j].y1 && v[j].y1 < v[i].y2);
			bool f2 = (v[i].y1 < v[j].y2 && v[j].y2 < v[i].y2);
			bool f3 = (v[j].x1 < v[i].x1 && v[i].x1 < v[j].x2);
			bool f4 = (v[j].x1 < v[i].x2 && v[i].x2 < v[j].x2);
			if(f1 && f3) {
				int x = v[i].x1;
				int y = v[j].y1;
				X[y].pb(Event{x, 0});
				Y[x].pb(Event{y, 0});
				nodes.ins({x, y});
			}
			if(f2 && f3) {
				int x = v[i].x1;
				int y = v[j].y2;
				X[y].pb(Event{x, 0});
				Y[x].pb(Event{y, 0});
				nodes.ins({x, y});
			}
			if(f1 && f4) {
				int x = v[i].x2;
				int y = v[j].y1;
				X[y].pb(Event{x});
				Y[x].pb(Event{y});
				nodes.ins({x, y});
			}
			if(f2 && f4) {
				int x = v[i].x2;
				int y = v[j].y2;
				X[y].pb(Event{x});
				Y[x].pb(Event{y});
				nodes.ins({x, y});
			}
		}
	}
	fz(X) {
		dbg(mp(z.first, sz(z.second)));
	}
	fz(Y) {
		dbg(mp(z.first, sz(z.second)));
	}
}

vi color;
void dfs(int x) {
	if(color[x]) return;
	color[x] = 1;
	fy(e[x]) {
		dfs(y);
	}
}

Rect get(const Rect& r, int id) {
	if (id == 1) return {r.x1, r.y1, r.x1, r.y2};
	if (id == 2) return {r.x1, r.y2, r.x2, r.y2};
	if (id == 3) return {r.x2, r.y1, r.x2, r.y2};
	if (id == 4) return {r.x1, r.y1, r.x2, r.y1};
}
bool intersect(const Rect& r1, const Rect& r2) {
	return max(r1.x1, r2.x1) <= min(r1.x2, r2.x2) && max(r1.y1, r2.y1) <= min(r1.y2, r2.y2);
}
void init1() {
	e = vvi(n + 1);
	fi(1, n) {
		fj(i + 1, n) {
			int q = 0;
			for(int r1 = 1; r1 <= 4; r1++) {
				for(int r2 = 1; r2 <= 4; r2++) {
					if(intersect(get(v[i], r1), get(v[j], r2))) {
						q++;
						break;
					}
				}
				if(q) break;
			}
			if(q) {
				e[i].pb(j);
				e[j].pb(i);
			}
		}
	}
	color = vi(n + 1, 0);
	fi(1, n) {
		if(!color[i]) {
			CNT++;
			dfs(i);
		}
	}
}

#define FILE ""
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
	#else
		// freopen(FILE".in", "r", stdin);
        // freopen(FILE".out", "w", stdout);
    #endif

	auto START = clock();

	cin >> n;
	v = vector<Rect>(n + 1);
	fi(1, n) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if(x1 > x2) swap(x1, x2);
		if(y1 > y2) swap(y1, y2);
		v[i] = Rect{x1, y1, x2, y2};

		nodes.ins({x1, y1});
		nodes.ins({x1, y2});
		nodes.ins({x2, y1});
		nodes.ins({x2, y2});

		X[y1].pb(Event{x1, 1});
        X[y1].pb(Event{x2, 2});
        X[y2].pb(Event{x1, 1});
        X[y2].pb(Event{x2, 2});
 
        Y[x1].pb(Event{y1, 1});
        Y[x1].pb(Event{y2, 2});
        Y[x2].pb(Event{y1, 1});
        Y[x2].pb(Event{y2, 2});
	}
	init1();
	init2();
	solve();


	auto TIME = ld(clock() - START) / CLOCKS_PER_SEC;
	dbg(TIME);
}