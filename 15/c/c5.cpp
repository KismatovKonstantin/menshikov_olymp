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


int n, k;
string lok;
map<string, int> cnt;
ll ans = 0;

map<vi, ll> d;

ll rec(int AA, int BB, int AB, int BA, int R) {

	if (d.count({AA, BB, AB, BA, R})) {
		return d[{AA, BB, AB, BA, R}];
	}

	ll s1 = 0, s2 = 0;
	if (R == 0) {
		if (AA > 0) s1 = rec(AA - 1, BB, AB, BA, 0);
		if (BA > 0) s2 = rec(AA, BB, AB, BA - 1, 1);
	} else {
		if (BB > 0) s1 = rec(AA, BB - 1, AB, BA, 1);
		if (AB > 0) s2 = rec(AA, BB, AB - 1, BA, 0);
	}
	if (AA + BB + AB + BA == k && R == (lok[0] == 'B')) {
		ans += s1 + s2;
	}
	return d[{AA, BB, AB, BA, R}] = s1 + s2;
}

void solve() {
	rec(cnt["AA"], cnt["BB"], cnt["AB"], cnt["BA"], 0);
	rec(cnt["AA"], cnt["BB"], cnt["AB"], cnt["BA"], 1);
    dbg(d);
	if (ans > 0) {
		cout << "YES" << ln;
        cout << ans << ln;
	} else {
		cout << "NO" << ln;
	}
}

void init() {
	int r = (lok[1] == 'B');
	if (r == 0) {
		d[{0, 0, 0, 0, 0}] = 1;
		d[{0, 0, 0, 0, 1}] = 0;
	} else {
		d[{0, 0, 0, 0, 0}] = 0;
		d[{0, 0, 0, 0, 1}] = 1;
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

	cin >> n >> k;
	cin >> lok;
	string s;
	fi(1, n) {
		cin >> s;
		cnt[s]++;
	}
	init();
    solve();

	auto TIME = ld(clock() - START) / CLOCKS_PER_SEC;
	dbg(TIME);
}