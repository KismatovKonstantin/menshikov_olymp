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
	ld x;
	ld y;
};

const ld Pi = acos(-1);

Point W1, W2;
ld R1, R2;

void print(const ld& x) {
	cout << fixed;
	cout.precision(2);
	cout << x << ln;
}

ld dist(const Point& a, const Point& b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
ld area(const ld& R) {
	return Pi * R * R;
}
ld sector_area(const ld& alpha, const ld& S) {
	return S * alpha / (2 * Pi);
}
ld triag_area(const ld& sin_alpha, const ld& a, const ld& b) {
	return a * b * sin_alpha / 2;
}

void solve() {
	ld d = dist(W1, W2);
	if (d >= R1 + R2) {
		print(0);
	} else if (d <= R1 - R2) {
		print(area(R2));
	} else if (d <= R2 - R1) {
		print(area(R1));
	} else {
		dbg(1);
		ld x1, x2;
		dbg(d);
		dbg(mp(R1, R2));

		x1 = (R1 * R1 + d * d - R2 * R2) / (2 * d);
		x2 = d - x1;
		ld y = sqrt(R1 * R1 - x1 * x1);
		dbg(mp(x1, x2));
		dbg(y);

		auto cos_alpha1 = x1/R1;
		auto cos_alpha2 = x2/R2;
		auto alpha1 = acos(cos_alpha1);
		auto alpha2 = acos(cos_alpha2);
		
		auto res1 = sector_area(alpha1, area(R1)) - triag_area(y/R1, x1, R1);
		auto res2 = sector_area(alpha2, area(R2)) - triag_area(y/R2, x2, R2);
		auto ans = (res1 + res2) * 2;
		print(ans);
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


	ld x1, y1;
	ld x2, y2;

	cin >> x1 >> y1 >> R1;
	W1 = {x1, y1};
	cin >> x2 >> y2 >> R2;
	W2 = {x2, y2};

    solve();

	auto TIME = ld(clock() - START) / CLOCKS_PER_SEC;
	dbg(TIME);
}