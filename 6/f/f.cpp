#define _CRT_SECURE_NO_WARNINGS
#define ln '\n'
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

int n;
vvc mtr;
vvi color;

bool is_valid(int x, int y) {
	bool f1 = (1 <= x && x <= n);
	bool f2 = (1 <= y && y <= n);
	return f1 && f2;
}
bool paint(int x, int y) {
	if(is_valid(x, y)) {
		bool f = (color[x][y] == 1);
		return f;
	}
	return false;
}

vi dx{-1, 0, 1, 0};
vi dy{0, 1, 0, -1};

void dfs(int x, int y) {
	if(mtr[x][y] != '.') return;
	if(color[x][y]) return;
	color[x][y] = 1;
	fo(0, 3) {
		dfs(x + dx[o], y + dy[o]);
	}
}

void solve() {
	color = vvi(n + 2, vi(n + 2));
	dfs(1, 1);
	dfs(n, n);

	ll ans = 0;
	fi(0, n + 1) {
		fj(0, n + 1) {
			if(mtr[i][j] != '#') continue;
			fo(0, 3) {
				if(paint(i + dx[o], j + dy[o])) ans += 9;
			}
		}
	}
	cout << ans << ln;
}


#define FILE "paintlab"
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
	#else
		freopen(FILE".in", "r", stdin);
        freopen(FILE".out", "w", stdout);
    #endif

	auto START = clock();

	cin >> n;
	mtr = vvc(n + 2, vc(n + 2, '#'));
	fi(1, n) {
		fj(1, n) {
			cin >> mtr[i][j];
		}
	}
	mtr[0][0] = '@';
	mtr[0][1] = '@';
	mtr[1][0] = '@';
	mtr[n + 1][n + 1] = '@';
	mtr[n][n + 1] = '@';
	mtr[n + 1][n] = '@';

    solve();

	auto END = clock();
	dbg(END - START);
}