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

struct Poly {
	int n = 0;
	vector<int> c = { 0 };
	int operator[](int x) const {
		if (x > n) return 0;
		return c[x];
	}
	int& operator[](int x)  {
		if (x > n) {
			c.resize(x + 1, 0);
			n = x;
		}
		return c[x];
	}
};
Poly operator+(const Poly& a, const Poly& b) {
	Poly res;
	fi(0, a.n) res[i] += a[i];
	fi(0, b.n) res[i] += b[i];
	return res;
}
Poly operator*(const Poly& a, int x) {
	Poly res;
	fi(0, a.n) {
		res[i] = a[i] * x;
	}
	return res;
}
Poly operator*(const Poly& a, string s) {
	Poly res;
	fdi(a.n, 0) res[i + 1] = a[i];
	return res;
}

int n;
vector<string> v;

Poly solve(int L, int R) {
	int L_ = L, R_ = R;
	Poly res;
	while(L <= R) {
		if (v[L] == "BEGIN") { 
			L++; R--;
		} else if (v[L] == "LOOP") {
			int q = 1;
			int r;
			fi(L + 2, R) {
				if (v[i] == "LOOP") q++;
				if (v[i] == "END") q--;
				if (q == 0) {
					r = i - 1;
					break;
				}
			}
			if (v[L + 1] == "n") {
				res = res + (solve(L + 2, r) * "n");
			} else {
				res = res + (solve(L + 2, r) * stoi(v[L + 1]));
			}
			L = r + 2;
		} else if (v[L] == "OP") {
			res[0] += stoi(v[L + 1]);
			L += 2;
		} else L++;
	}
	dbg(mp(L_, R_));
	dbg(res.c);
	return res;
}

vector<string> read() {
	vector<string> res;
	string s;
	int q = 0;
	while(cin >> s) {
		res.pb(s);
		if (s == "BEGIN" || s == "LOOP") q++;
		if (s == "END") q--;
		if (q == 0) break;
	}
	return res;
}

void print_ans(int num, const Poly& ans) {
	cout << "Program #" << num << ln;
	cout << "Runtime = ";
	bool zero = true;
	bool first = true;
	fdi(ans.n, 0) {
		if (ans[i] == 0) continue;
		zero = false;
		if (!first) cout << "+";
		first = false;
		if (i == 0) cout << ans[i];
		else if (ans[i] > 1) cout << ans[i] << "*n";
		else cout << "n";
		if (i > 1) cout << "^" << i;
	}
	if (zero) cout << 0;
	cout << ln;
	cout << ln;
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
	fi(1, n) {
		v = read();
		dbg(sz(v));
		dbg(v);
		auto ans = solve(0, sz(v) - 1);
		print_ans(i, ans);
	}

	auto TIME = ld(clock() - START) / CLOCKS_PER_SEC;
	dbg(TIME);
}