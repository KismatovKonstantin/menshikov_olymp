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
	ll base = 10;
	ll len = 1;
	vll num = {1, 0};
};

ostream& operator<<(ostream& os, Long a) {
	os << a.base << ln;
	os << a.num;
	return os;
}

Long operator+(const Long&, const Long&);
Long operator*(const Long&, const ll&);
pair<Long, int> operator/(const Long&, const ll&);
Long read(int);
Long str_to_Long(string, int);
void print(const Long&);

Long to10(const Long& a) {
	Long res;
	int n = a.num[0];
	Long pow;
	pow.num[1] = 1;
	fi(1, n) {
		res = res + pow * a.num[i];
		pow = pow * a.base;
	}
	return res;
}
Long from10(const Long& a, int base) {
	Long res;
	res.base = base;
	res.num = vll(1);
	Long d = a;
	d.base = 10;
	int m;
	while(1) {
		auto g = d / base;
		d = g.first;
		m = g.second;
		res.num.pb(m);
		res.num[0]++;
		if(d.num == vll{1, 0}) break;
	}
	return res;
}

ll A, B;
string s;

void solve() {
	Long a = str_to_Long(s, A);
	Long a10 = to10(a);
	dbg(a10);
	Long b = from10(a10, B);
	print(b);
}


#define FILE "scale"
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

	cin >> A >> B;
	cin >> s;

    solve();

	auto END = clock();
	dbg(END - START);
}

Long operator+(const Long& a, const Long& b) {
	Long res;
	res.base = a.base;
	res.num = vll(1);
	int n = a.num[0];
	int m = b.num[0];
	int w = max(n, m);
	fi(1, w) {
		int x = (i <= n ? a.num[i] : 0);
		int y = (i <= m ? b.num[i] : 0);
		int val = x + y;
		res.num.pb(val);
		if(i > 1) {
			res.num[i] += res.num[i - 1] / res.base;
			res.num[i - 1] %= res.base;
		}
		res.num[0]++;
	}
	while(res.num[w] / res.base) {
		res.num.pb(res.num[w] / res.base);
		res.num[w] %= res.base;
		res.num[0]++;
		w++;
	}
	return res;
}
Long operator*(const Long& a, const ll& b) {
	dbg(a);
	dbg(b);
	Long res;
	res.base = a.base;
	res.num = vll(1);
	int n = a.num[0];
	fi(1, n) {
		int val = a.num[i] * b;
		res.num.pb(val);
		if(i > 1) {
			res.num[i] += res.num[i - 1] / res.base;
			res.num[i - 1] %= res.base;
		}
		res.num[0]++;
	}
	while(res.num[n] / res.base) {
		res.num.pb(res.num[n] / res.base);
		res.num[n] %= res.base;
		res.num[0]++;
		n++;
	}
	return res;
}
pair<Long, int> operator/(const Long& a, const ll& b) {
	Long res1;
	int res2;
	res1.base = a.base;
	res1.num = vll(1);
	int n = a.num[0];

	int d = 0, m = 0;
	fdi(n, 1) {
		int val = a.num[i] + m * res1.base;
		d = val / b;
		m = val % b;
		if(res1.num[0] == 0 && d == 0) continue;
		res1.num.pb(d);
		res1.num[0]++;
	}
	if(res1.num[0] == 0) {
		res1.num = {1, 0};
	} else {
		reverse(Allf(res1.num));
	}
	res2 = m;
	return mp(res1, res2);
}

Long read(int base) {
	Long res;
	res.base = base;
	res.num = vll(1);

	string s;
	cin >> s;

	int n = sz(s);
	fdi(n - 1, 0) {
		ll next = 0;
		if('0' <= s[i] && s[i] <= '9') next += (s[i] - '0');
		else next += (s[i] - 'A');

		res.num.pb(next);
		res.num[0]++;
	}
	return res;
}

Long str_to_Long(string num, int base) {
	Long res;
	res.base = base;
	res.num = vll(1);

	int n = sz(num);
	fdi(n - 1, 0) {
		ll next = 0;
		if('0' <= num[i] && num[i] <= '9') next += (num[i] - '0');
		else next += (num[i] - 'A') + 10;

		res.num.pb(next);
		res.num[0]++;
	}
	return res;
}

void print(const Long& a) {
	int n = a.num[0];
	char dig;
	fdi(n, 1) {
		if(0 <= a.num[i] && a.num[i] <= 9) dig = '0' + a.num[i];
		else dig = 'A' + (a.num[i] - 10);

		printf("%c", dig);
	}
	printf(ln);
}