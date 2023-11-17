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
	int base = 10000;
	int len = 4;
	vi num = {1, 0};
	int operator[](int x) const {
		return num[x];
	}
	int& operator[](int x) {
		if(x > num[0]) {
			num.resize(x + 1, 0);
			num[0] = x;
		}
		return num[x];
	}
};
Long operator*(const Long& a, const Long& b) {
	Long res;
	fi(1, a[0]) {
		if(a[i] == 0) continue;
		fj(1, b[0]) {
			if(a[i] * b[j] == 0) continue;
			int x = i + j - 1;
			res[x] += a[i] * b[j];
			while(x > 1 && res[x - 1] / res.base) {
				res[x] += res[x - 1] / res.base;
				res[x - 1] %= res.base;
			}
		}
		while(res[res[0]] / res.base) {
			int g = res[0];
			res[g + 1] += res[g] / res.base;
			res[g] %= res.base;
		}
	}
	return res;
}

Long str_to_Long(string s) {
	Long res;
	int x = 1;
	int n = sz(s);
	for(int i = n - 1; i >= 0; i -= res.len) {
		int val = 0;
		for(int j = max(0, i - res.len + 1); j <= i; j++) {
			val = val * 10 + (s[j] - '0');
		}
		res[x] = val;
		x++;
	}
	return res;
}

void print(const Long& a) {
	printf("%d", a[a[0]]);
	fdi(a[0] - 1, 1) {
		printf("%04d", a[i]);
	}
	printf("\n");
}

Long a, b;

void solve() {
	Long ans;
	ans = a * b;
	print(ans);
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

	string s1, s2;
	cin >> s1 >> s2;

	a = str_to_Long(s1);
	b = str_to_Long(s2);

	if(a.num[0] < b.num[0]) swap(a, b);

    solve();

	auto END = clock();
	dbg(END - START);
}