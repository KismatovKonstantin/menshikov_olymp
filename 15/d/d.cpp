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
	fi(0, sz(v) - 1) {
		os << v[i] << " ";
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
	int x, y;
	bool operator<(const Point& b) const {
		return mp(x, y) < mp(b.x, b.y);
	}
	bool operator==(const Point& b) const {
		return x == b.x && y == b.y;
	}
};
ostream& operator<<(ostream& os, Point p) {
	os << mp(p.x, p.y);
	return os;
}

Point to_vec(const Point& a, const Point& b) {
	return Point{b.x - a.x, b.y - a.y};
}

int cross(const Point& a, const Point& b) {
	return a.x * b.y - a.y * b.x;
}
int sqr(int x) {
	return x * x;
}
ld dist(const Point& a, const Point& b) {
	return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

const ld eps = 1e-9;
const ld pi = acos(-1);

int N, L;
vector<Point> a;

void solve() {
	auto A = a[1];
	auto B = a[N];

	vector<Point> up, down;
	up.pb(A);
	down.pb(A);

	fi(2, N) {
		ll val = cross(to_vec(A, B), to_vec(A, a[i]));
		if (val >= 0) {
			dbg(a[i]);
			int M = sz(up) - 1;
			while(sz(up) > 1 && cross(to_vec(up[M - 1], up[M]), to_vec(up[M], a[i])) >= 0) {
				up.pop_back();
				M--;
			}
			up.pb(a[i]);
		}
		if (val <= 0) {
			dbg(a[i])
			int M = sz(down) - 1;
			while(sz(down) > 1 && cross(to_vec(down[M - 1], down[M]), to_vec(down[M], a[i])) <= 0) {
				down.pop_back();
				M--;
			}
			down.pb(a[i]);
		}
	}

	dbg(up);
	dbg(down);

	ld res = 0;
	fi(1, sz(up) - 1) {
		res += dist(up[i - 1], up[i]);
		dbg(res);
	}
	fi(1, sz(down) - 1) {
		res += dist(down[i - 1], down[i]);
		dbg(res);
	}
	res += 2 * pi * L;
	dbg(res);

	int ans = round(res);
	cout << ans << ln;

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

	cin >> N >> L;
	a = vector<Point> (N + 1);
	fi(1, N) {
		int x, y;
		cin >> x >> y;
		a[i] = Point{x, y};
	}
	sort(Allf(a));

    solve();

	auto TIME = ld(clock() - START) / CLOCKS_PER_SEC;
	dbg(TIME);
}