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
	fz(v) {
		os << fixed;
		os.width(2);
		os << z << " ";
	}
	return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector<vector<T>> v) {
	os << ln;
	fz(v) {
		os << z << ln;
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

int w, h;
vvc matr;
map<int, int> t1;
map<int, int> t2;

vi dx{-1, 0, 1, 0, -1, -1, 1, 1};
vi dy{0, 1, 0, -1, -1, 1, -1, 1};

bool inside(int x, int y) {
	bool f1 = (0 <= x && x <= h + 1);
	bool f2 = (0 <= y && y <= w + 1);
	return f1 && f2;
}

vvi color;
void dfs1(int x, int y, int q) {
	if(color[x][y]) return;
	color[x][y] = q;
	t1[q]++;
	fo(0, 3) {
		int x2 = x + dx[o];
		int y2 = y + dy[o];
		if(!inside(x2, y2)) continue;
		if(matr[x2][y2] != '*') continue;
		dfs1(x2, y2, q);
	}
}
void dfs2(int x, int y, int q) {
	if(color[x][y]) return;
	color[x][y] = q;
	fo(0, 3) {
		int x2 = x + dx[o];
		int y2 = y + dy[o];
		if(!inside(x2, y2)) continue;
		dfs2(x2, y2, q);
	}
	fo(4, 7) {
		int x2 = x + dx[o];
		int y2 = y + dy[o];
		if(!inside(x2, y2)) continue;
		if(color[x2][y] != color[x][y2] || color[x2][y] < 0) {
			dfs2(x2, y2, q);
		}
	}
}

void solve() {
	dbg(matr);
	color = vvi(h + 2, vi(w + 2));
	int q = 1;
	fi(1, h) {
		fj(1, w) {
			if(color[i][j]) continue;
			if(matr[i][j] != '*') continue;
			dfs1(i, j, q++);
		}
	}
	dfs2(0, 0, -1'000'000'000);
	dbg(color);

	fi(1, h) {
		fj(1, w) {
			if(color[i][j] == 0 && color[i - 1][j] == color[i][j - 1] && color[i - 1][j] > 0) {
				t2[color[i - 1][j]]++;
				dfs2(i, j, -color[i - 1][j]);
			}
		}
	}

	q = 0;
	fz(t2) {
		q = max(q, z.second);
	}
	int ans = 1'000'000'000;
	fz(t2) {
		if(z.second == q) {
			ans = min(ans, t1[z.first]);
		}
	}
	cout << (ans == 1'000'000'000 ? 0 : ans) << ln;
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

	cin >> w >> h;
	matr = vvc(h + 2, vc(w + 2, '.'));
	fi(1, h) {
		fj(1, w) {
			cin >> matr[i][j];
		}
	}

    solve();

	auto TIME = ld(clock() - START) / CLOCKS_PER_SEC;
	dbg(TIME);
}