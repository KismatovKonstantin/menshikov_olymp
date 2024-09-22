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
	ll x, y;
	Point(const ll& _x = 0, const ll& _y = 0) {
		x = _x; y = _y;
	}
};
ostream& operator<<(ostream& os, Point& A) {
	os << "(" << A.x << ", " << A.y << ")";
	return os;
}

struct Seg {
	Point A, B;
	Seg(const Point& _A = Point(), const Point& _B = Point()) {
		A = _A; B = _B;
	}
};
ostream& operator<<(ostream& os, Seg& AB) {
	os << AB.A << "->" << AB.B;
	return os;
}

int n;
vector<Point> a;
vector<Seg> b;

ll cross(const Point& A, const Point& B) {
	return (A.x * B.y - A.y * B.x);
}

ll gcd(ll a, ll b) {
	return (b ? gcd(b, a % b) : a);
}

ll fun(const Seg& g) {
	ll x = abs(g.B.x - g.A.x);
	ll y = abs(g.B.y - g.A.y);
	dbg(mp(x, y));
	return gcd(x, y);
}

void solve() {
	dbg(a);
	dbg(b);
	ll S = 0;
	fi(1, n) S += cross(a[i], a[i + 1]);
	S = abs(S);

	ll q = 0;
	fi(1, n) q += fun(b[i]);

	ll ans = (ld)S / 2 - (ld)q / 2 + 1;
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

	cin >> n;
	a = vector<Point>(n + 2);
	b = vector<Seg>(n + 1);
	fi(1, n) {
		ll x, y;
		cin >> x >> y;
		a[i] = Point(x, y);
	}
	a[n + 1] = a[1];
	fi(1, n) {
		b[i] = Seg(a[i], a[i + 1]);
	}

    solve();

	auto TIME = ld(clock() - START) / CLOCKS_PER_SEC;
	dbg(TIME);
}