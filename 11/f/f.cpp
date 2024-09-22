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

ll gcd(ll a, ll b) {
	return (b ? gcd(b, a % b) : a);
}

struct Fraction {
	ll num, den = 1;
	Fraction (ll a = 0, ll b = 1) {
		num = a;
		den = b;
	}
	void fun() {
		ll g = gcd(abs(num), abs(den));
		num /= g;
		den /= g;
		if (den < 0) {
			num = -num;
			den = -den;
		}
	}
	void print() const {
		if (num == 0) cout << 0 << ln;
		if (num / den != 0) {
			cout << num / den;
		}
		if (abs(num) % den != 0) {
			if (num / den != 0) cout << " ";
			else if (num < 0) cout << "-";
			cout << abs(num) % den << "/" << den << ln;
		}
	}
};

Fraction operator+(const Fraction& a, const Fraction& b) {
	Fraction res;
	res.num = a.num;
	res.den = a.den;
	res.den *= b.den;
	res.num *= b.den;
	res.num += a.den * b.num;
	res.fun();
	return res;
}
Fraction operator-(const Fraction& a) {
	auto res = Fraction(-a.num, a.den);
	return res;
}
Fraction operator-(const Fraction& a, const Fraction& b) {
	auto res = a + (-b);
	return res;
}
Fraction operator*(const Fraction& a, const Fraction& b) {
	auto res = Fraction(a.num * b.num, a.den * b.den);
	res.fun();
	return res;
}
Fraction operator/(const Fraction& a, const Fraction& b) {
	auto res = Fraction(a.num * b.den, a.den * b.num);
	res.fun();
	return res;
}


void solve() {
	string s;
	ll x = 0, y = 0;
	Fraction a, b;
	string op = "";
	while(cin >> s) {
		if (s == "+" || s == "-" || s == "*" || s == "/") {
			op = s;
		} else if (op == "") {
			auto g = s.find('/');
			if (g == string::npos) {
				a.num = stoll(s);
			} else {
				ll num = 0;
				ll den = 0;
				fi(0, g - 1) {
					num = num * 10 + (s[i] - '0');
				}
				fi(g + 1, sz(s) - 1) {
					den = den * 10 + (s[i] - '0');
				}
				a.num *= den;
				a.num += (a.num >= 0 ? num : -num);
				a.den = den;
			}
		} else {
			auto g = s.find('/');
			if (g == string::npos) {
				b.num = stoll(s);
			} else {
				ll num = 0;
				ll den = 0;
				fi(0, g - 1) {
					num = num * 10 + (s[i] - '0');
				}
				fi(g + 1, sz(s) - 1) {
					den = den * 10 + (s[i] - '0');
				}
				b.num *= den;
				b.num += (b.num >= 0 ? num : -num);
				b.den = den;
			}
		}
		dbg(s);
		dbg(mp(a.num, a.den));
		dbg(op);
		dbg(mp(b.num, b.den));
	}
	a.fun();
	b.fun();
	Fraction ans;
	if (op == "+") ans = a + b;
	else if (op == "-") ans = a - b;
	else if (op == "*") ans = a * b;
	else if (op == "/") ans = a / b;
	dbg(mp(a.num, a.den));
	dbg(op);
	dbg(mp(b.num, b.den));
	dbg(mp(ans.num, ans.den));
	ans.print();
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

	

    solve();

	auto TIME = ld(clock() - START) / CLOCKS_PER_SEC;
	dbg(TIME);
}