#define _CRT_SECURE_NO_WARNINGS
#define ln "\n"
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

struct Long {
	ll base = (ll)1e4;
	ll len = 4;
	vll num = {1, 0};
};
Long operator+(const Long& a, const Long& b) {
	Long res;
	res.num = vll(1);

	int n = a.num[0];
	int m = b.num[0];
	int w = max(n, m);
	ll x, y, sum;
	fi(1, w) {
		x = (i <= n ? a.num[i] : 0);
		y = (i <= m ? b.num[i] : 0);
		sum = x + y;
		res.num.pb(sum);
		res.num[0]++;
		if(i > 1) {
			res.num[i] += res.num[i - 1] / res.base;
			res.num[i - 1] %= res.base;
		}
	}
	while(res.num[w] / res.base) {
		res.num.pb(res.num[w] / res.base);
		res.num[w] %= res.base;
		res.num[0]++;
		w++;
	}
	return res;
}
void print(const Long& a) {
	int n = a.num[0];
	printf("%lld", a.num[n]);
	fdi(n - 1, 1) {
		printf("%04lld", a.num[i]);
	}
	printf(ln);
}

int n;
string s;

vector<Long> d;

Long fun(int x) {
	if(d[x].num != vll{1, 0}) return d[x];
	d[x] = fun(x - 1);
	ll v = (s[x - 1] - '0') * 10 + (s[x] - '0');
	if(10 <= v && v <= 33) d[x] = d[x] + fun(x - 2);
	return d[x];
}

void solve() {
	d = vector<Long>(n + 1, Long{});
	d[0].num = vll{1, 1};
	d[1].num = vll{1, 1};
	Long ans = fun(n);
	print(ans);
}


#define FILE "message"
int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
	#else
		freopen(FILE".in", "r", stdin);
        freopen(FILE".out", "w", stdout);
    #endif

	auto START = clock();

	cin >> s;
	s = "#" + s;
	n = sz(s) - 1;

    solve();

	auto END = clock();
	dbg(END - START);
}