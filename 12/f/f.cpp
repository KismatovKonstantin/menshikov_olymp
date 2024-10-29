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

bool is_cap(char c) {
	return ('A' <= c && c <= 'Z');
}
bool is_small(char c) {
	return ('a' <= c && c <= 'z');
}
bool is_digit(char c) {
	return ('0' <= c && c <= '9');
}


string base;
map<string, int> Q;
int n;
map<string, int> q;
string s;

map<string, int> rec(int L, int R) {
	dbg(mp(L, R));
	map<string, int> res;
	if (L > R) return res;
	int num = 1;
	int l = L, r = R;
	dbg(s);
	dbg(s[l]);
	if(is_digit(s[l])) {
		int x = 0;
		while(is_digit(s[l])) {
			x = x * 10 + (s[l] - '0');
			l++;
		}
		num = x;
		res = rec(l, r);
		fz(res) {
			z.second *= num;
		}
	} else {
		while(l <= r) {
			if (s[l] == '(') {
				int k = 0;
				map<string, int> tmp;
				fi(l, r) {
					if (s[i] == '(') k++;
					else if (s[i] == ')') k--;

					if (k == 0) {
						tmp = rec(l + 1, i - 1);
						l = i + 1;
						break;
					}
				}
				if (is_digit(s[l])) {
					int x = 0;
					while(l <= r && is_digit(s[l])) {
						x = x * 10 + (s[l] - '0');
						l++;
					}
					fz(tmp) z.second *= x;
				}
				fz(tmp) {
					res[z.first] += z.second;
				}
			} else {
				string el = "";
				if (is_cap(s[l])) el += s[l++];
				if (is_small(s[l])) el += s[l++];
				dbg(el);
				num = 1;
				if (is_digit(s[l])) {
					int x = 0;
					while(l <= r && is_digit(s[l])) {
						x = x * 10 + (s[l] - '0');
						l++;
					}
					num = x;
				}
				dbg(num);
				res[el] += num;
			}
		}
	}
	dbg(res);
	return res;
}

void parse() {
	int L = 0, R = 0;
	fi(0, sz(s) - 1) {
		if (s[i] == '+') {
			R = i - 1;
			auto res = rec(L, R);
			fz(res) {
				q[z.first] += z.second;
			}
			L = i + 1;
		}
	}
	auto res = rec(L, sz(s) - 1);
	fz(res) {
		q[z.first] += z.second;
	}
}


void solve() {
	q.clear();
	parse();
	dbg(s);
	dbg(q);
	if (q == Q) {
		cout << base << "==" << s << ln;
	} else {
		cout << base << "!=" << s << ln;
	}
}

void init() {
	parse();
	Q = q;
	base = s;
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

	cin >> s;
	init();

	cin >> n;
	fi(1, n) {
		cin >> s;
    	solve();
	}


	auto TIME = ld(clock() - START) / CLOCKS_PER_SEC;
	dbg(TIME);
}