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

struct Point {
	ld x, y;
	bool operator<(const Point& b) const {
		return mp(x, y) < mp(b.x, b.y);
	}
};
ostream& operator<<(ostream& os, const Point& a) {
	os << mp(a.x, a.y);
	return os;
}
ld cross(const Point& a, const Point& b) {
	return a.x * b.y - b.x * a.y;
}
Point to_vec(const Point& a, const Point& b) {
	return Point{ b.x - a.x, b.y - a.y };
}


ld area(const vector<Point>& a) {
	int m = sz(a) - 1;

	dbg(a);

	Point A = a[1];
	Point B = a[m];
	vector<Point> up = {};
	vector<Point> down = { A };
	
	fi(1, m) {
		int g = cross(to_vec(A, B), to_vec(A, a[i]));
		if(g >= 0) {
			while(sz(up) >= 2 && cross(to_vec(end(up)[-2], end(up)[-1]), to_vec(end(up)[-2], a[i])) >= 0) {
				up.pop_back();
			}
			up.pb(a[i]);
		}
		if(g <= 0) {
			int w = sz(down) - 1;
			while(w >= 1 && cross(to_vec(down[w - 1], down[w]), to_vec(down[w], a[i])) <= 0) {
				down.pop_back();
				w--;
			}
			down.pb(a[i]);
		}
	}
	ld res = 0;
	up.pb(up[0]);
	fi(0, sz(up) - 2) {
		res -= cross(up[i], up[i + 1]);
	}
	dbg(up)
	dbg(down)
	dbg(res)
	down.pb(A);
	fi(0, sz(down) - 2) {
		res += cross(down[i], down[i + 1]);
	}
	dbg(res)
	return abs(res) / 2;
}

int n;
vi len;
vector<vector<Point>> v;
map<Point, vi> t;

vvi e;

void solve() {
	ld ans = 0;
	fi(1, n) {
		ans = max(ans, area(v[i]));
	}
	cout << fixed;
	cout.precision(2);
	cout << ans << ln;
}

vi color;

void dfs(int x) {
	if(color[x]) {
		return;
	}
	color[x] = 1;
	fy(e[x]) {
		dfs(y);
		fi(1, len[y]) {
			v[x].pb(v[y][i]);
			len[x]++;
		}
	}
}

void init() {
	e = vvi(n + 1);
	fi(1, n) {
		t[v[i][len[i]]].pb(i);
	}
	fi(1, n) {
		fj(2, len[i] - 1) {
			if(t.count(v[i][j])) {
				auto g = t[v[i][j]];
				fz(g) {
					if (z != i) e[i].pb(z);
				}
			}
		}
	}

	color = vi(n + 1);
	fi(1, n) {
		dfs(i);
		sort(Allf(v[i]));
	}
	dbg(v);
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

	len = vi(n + 1);
	v = vector<vector<Point>>(n + 1);
	fi(1, n) {
		cin >> len[i];
		v[i] = vector<Point>(len[i] + 1);
		fj(1, len[i]) {
			ld x, y;
			cin >> x >> y;
			v[i][j] = Point{x, y};
		}
	}
	init();
    solve();

	auto TIME = ld(clock() - START) / CLOCKS_PER_SEC;
	dbg(TIME);
}