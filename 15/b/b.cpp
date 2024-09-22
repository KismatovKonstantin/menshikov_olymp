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

const ld eps = 1e-6;

ld v, b, m;

ld MH;
ld fun(ld x) {
	ld AB = sqrt(v*v + (x+MH)*(x+MH));
	ld BC = sqrt(v*v + (x-MH)*(x-MH));
	ld y = MH + x*(BC - AB) / (AB + BC);
	dbg(MH);
	dbg(y);
	return sqrt(y*y + v*v);
}

void solve() {
	if (abs(v - b) < eps && abs(b - m) < eps) {
		cout << 0 << ln;
		return;
	}
	if (abs(v - b) < eps || abs(v - m) < eps || abs(m - b) < eps) {
		cout << -1 << ln;
		return;
	}

	MH = sqrt(m*m - v*v);
	ld L = -1e18, R = 1e18;
	while(1) {
		ld x = (L + R) / 2;
		ld res = fun(x);
		dbg(x);
		dbg(res);
		dbg(mp(L, R));
		if (abs(res - b) < eps || abs(L - R) < eps) break;
		else if (res < b) L = x;
		else R = x;
	}
	cout << fixed;
	cout.precision(3);
	cout << abs(v * L) << ln;
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

	cin >> v >> b >> m;

	auto _v = min(v, b);
	_v = min(_v, m);

	auto _m = max(v, b);
	_m = max(_m, m);

	auto _b = v + b + m - _v - _m;

	v = _v;
	b = _b;
	m = _m;

	dbg(vector<ld>({v, b, m}));

    solve();

	auto TIME = ld(clock() - START) / CLOCKS_PER_SEC;
	dbg(TIME);
}