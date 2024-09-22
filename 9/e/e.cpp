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

const int inf = 1'000'000'000;

struct Point {
	int x, y;
	int val;
};

int n;
vvi matr;
vvi ans;
vvi d;

vi dx{-1, 0, 1, 0};
vi dy{0, 1, 0, -1};

bool valid(int x, int y) {
	bool f1 = (1 <= x && x <= n);
	bool f2 = (1 <= y && y <= n);
	return f1 && f2;
}

void bfs() {
	queue<Point> qu;
	vvi color = vvi(n + 1, vi(n + 1));
	vvi par = vvi(n + 1, vi(n + 1));
	fi(1, n) {
		fj(1, n) {
			if(matr[i][j] == 0) continue;
			qu.push({i, j, matr[i][j]});
			color[i][j] = i * n + j;
			d[i][j] = 0;
			ans[i][j] = matr[i][j];
		}
	}
	while(sz(qu)) {
		auto [x, y, val] = qu.front();
		qu.pop();
		if(color[x][y] != -1) {
			ans[x][y] = val;
		}
		fo(0, 3) {
			int x2 = x + dx[o];
			int y2 = y + dy[o];
			if(!valid(x2, y2)) continue;
			if(d[x2][y2] >= d[x][y] + 1) {
				d[x2][y2] = d[x][y] + 1;
				if (color[x2][y2] && color[x2][y2] != color[x][y]) {
					color[x2][y2] = -1;	
				} else if (!color[x2][y2]) {
					color[x2][y2] = color[x][y];
					qu.push({x2, y2, val});
				}
			}
		}
	}
}	

void solve() {
	bfs();
	fi(1, n) {
		fj(1, n) {
			cout << ans[i][j] << ' ';
		}
		cout << ln;
	}
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
	matr = vvi(n + 1, vi(n + 1));
	ans = vvi(n + 1, vi(n + 1));
	d = vvi(n + 1, vi(n + 1, inf));
	fi(1, n) {
		fj(1, n) {
			cin >> matr[i][j];
		}
	}

    solve();

	auto TIME = ld(clock() - START) / CLOCKS_PER_SEC;
	dbg(TIME);
}