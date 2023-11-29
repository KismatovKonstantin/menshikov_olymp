#define _CRT_SECURE_NO_WARNINGS
#define ln '\n'
#define All(x) (x).begin(), (x).end()
#define Allr(x) (x).rbegin(), (x).rend()
#define Allf(x) x.begin() + 1, x.end()

#define fi(a, b) for (auto i = (a); i <= (b); i++)
#define fj(a, b) for (auto j = (a); j <= (b); j++)
#define fo(a, b) for (auto o = (a); o <= (b); o++)
#define fq(a, b) for (auto q = (a); q <= (b); q++)
#define fe(a, b) for (auto e = (a); e <= (b); e++)
#define fw(a, b) for (auto w = (a); w <= (b); w++)

#define fdi(a, b) for (auto i = (a); i >= (b); i--)
#define fdj(a, b) for (auto j = (a); j >= (b); j--)
#define fdo(a, b) for (auto o = (a); o >= (b); o--)
#define fdq(a, b) for (auto q = (a); q >= (b); q--)
#define fde(a, b) for (auto e = (a); e >= (b); e--)
#define fdw(a, b) for (auto w = (a); w >= (b); w--)

#define fx(A) for (auto &x : (A))
#define fy(A) for (auto &y : (A))
#define fz(A) for (auto &z : (A))

#define pb push_back
#define mp make_pair
#define ins insert
#define sz(x) (int)x.size()

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

#ifdef _DEBUG
#define LOCAL
#endif

mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());

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
	fi(0, sz(v) - 1) {
		os << v[i] << " ";
	}
	return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector<vector<T>> v) {
	os << ln;
	fi(0, sz(v) - 1) {
		os << v[i] << ln;
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

struct Point {
	ll x, y;
	bool operator<(const Point& b) const {
		return mp(x, y) < mp(b.x, b.y);
	}
	bool operator==(const Point& b) const {
		return mp(x, y) == mp(b.x, b.y);
	}
};
ostream& operator<<(ostream& os, Point p) {
	os << mp(p.x, p.y);
	return os;
}
Point to_vec(const Point& a, const Point& b) {
	return Point{b.x - a.x, b.y - a.y};
}
ll cross(const Point& a, const Point& b) {
	return a.x * b.y - a.y * b.x;
}
ld dist(const Point& a, const Point& b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

const ld eps = 1e-9;

ll n;
vector<Point> v;

Point A, B;

void solve() {
	A = v[1];
	B = v[n];

	vector<Point> up;
	vector<Point> down;
	up.pb(A);
	down.pb(A);

	fi(2, n) {
		ll g = cross(to_vec(A, B), to_vec(A, v[i]));
		if (g >= 0) {
			int w = sz(up) - 1;
			while(sz(up) >= 2 && cross(to_vec(up[w - 1], up[w]), to_vec(up[w], v[i])) >= 0) {
				up.pop_back();
				w--;
			}
			up.pb(v[i]);
		}
		if (g <= 0) {
			dbg(v[i]);
			int w = sz(down) - 1;
			while(sz(down) >= 2 && cross(to_vec(down[w - 1], down[w]), to_vec(down[w], v[i])) <= 0) {
				down.pop_back();
				w--;
			}
			down.pb(v[i]);
		}
	}
	dbg(up);
	dbg(down);
	ld ans = 0;
	fi(1, sz(up) - 1) {
		ans += dist(up[i], up[i - 1]);
	}
	fi(1, sz(down) - 1) {
		ans += dist(down[i], down[i - 1]);
	}
	cout << fixed;
	cout.precision(1);
	cout << ans << ln;
}


#define FILE "conhull"
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
	v = vector<Point>(n + 1);
	fi(1, n) {
		ll x, y;
		cin >> x >> y;
		v[i] = Point{x, y};
	}
	sort(Allf(v));

    solve();

	auto TIME = (ld)(clock() - START) / CLOCKS_PER_SEC;
	dbg(TIME);
}