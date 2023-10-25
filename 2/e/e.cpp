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
	vll num = {1, 0};
};
Long operator+(Long a, ll b) {
	int n = a.num[0];
	a.num[1] += b;
	fi(1, n) {
		if(a.num[i] / a.base == 0) break;
		if(i == n) {
			a.num.pb(a.num[i] / a.base);
			a.num[0]++;
			n++;
		} else {
			a.num[i + 1] += a.num[i] / a.base;
		}
		a.num[i] %= a.base;
	}
	return a;
}
Long operator+(Long& a, Long& b) {
	int n = a.num[0];
	int m = b.num[0];
	Long res;
	fi(1, max(n, m)) {
		ll val1 = (i <= n ? a.num[i] : 0);
		ll val2 = (i <= m ? b.num[i] : 0);
		ll sum = val1 + val2;
		if(i > res.num[0]) {
			res.num.pb(sum);
			res.num[0]++;
		} else {
			res.num[i] += sum;
		}
		if(res.num[i] / res.base) {
			res.num.pb(res.num[i] / res.base);
			res.num[0]++;
			res.num[i] %= res.base;
		}
	}
	return res;
}

void printLong(Long& a) {
	auto n = a.num[0];
	printf("%lld", a.num[n]);
	fdi(n - 1, 1) {
		printf("%04lld", a.num[i]);
	}
	printf(ln);
}
Long readLong() {
	Long res;
	string s;
	cin >> s;
	s = "000" + s;
	dbg(s);
	int n = sz(s);
	int i = n - 1;
	int q = 0;
	while(i >= 3) {
		ll next = 0;
		fj(i - 3, i) {
			next = next * 10 + (s[j] - '0');
		}
		q++;
		if(q == 1) {
			res.num[1] = next;
		} else {
			res.num.pb(next);
			res.num[0]++;
		}
		i -= 4;
	}
	return res;
}

Long a, b;

void solve() {
	Long ans = a + b;
	printLong(ans);
}


#define FILE ""
int main()
{
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
	#else
		// freopen(FILE".in", "r", stdin);
        // freopen(FILE".out", "w", stdout);
    #endif

	auto START = clock();

	a = readLong();
	b = readLong();

    solve();

	auto END = clock();
	dbg(END - START);
}