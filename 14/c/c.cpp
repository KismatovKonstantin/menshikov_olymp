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

const int inf = 1'000'000'000;

string s;
int n;
vvi d;
vector<vs> ans;

int fun(int l, int r) {
	if (d[l][r] != inf) return d[l][r];
	if (l > r) {
		d[l][r] = 0;
		ans[l][r] = "";
		return d[l][r];
	}
	if (l == r) {
		d[l][r] = 1;
		ans[l][r] = s[l];
		return d[l][r];
	}

	fi(l, r) {
		if (d[l][i] + d[i + 1][r] < d[l][r]) {
			d[l][r] = d[l][i] + d[i + 1][r];
			ans[l][r] = ans[l][i] + ans[i + 1][r];
		}
	}
	fi(1, r - l + 1) {
		if ((r - l + 1) % i != 0) continue;
		bool f = true;
		fj(l + i, r) {
			if (s[j] != s[(j - l) % i + l]) {
				f = false;
				break;
			}
		}
		if (f) {
			string res = to_string((r - l + 1) / i) + "(" + ans[l][l + i - 1] + ")";

			if (sz(res) < d[l][r]) {
				d[l][r] = sz(res);
				ans[l][r] = res;
			}
		}
	}
	return d[l][r];
}

void solve() {
	fw(0, n - 1) {
		fi(1, n - w) {
			fun(i, i + w);
		}
	}
	cout << ans[1][n] << ln;
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
	n = sz(s);
	s = "#" + s;
	d = vvi(n + 2, vi(n + 2, inf));
	ans = vector<vs>(n + 2, vs(n + 2, ""));

    solve();

	auto TIME = ld(clock() - START) / CLOCKS_PER_SEC;
	dbg(TIME);
}