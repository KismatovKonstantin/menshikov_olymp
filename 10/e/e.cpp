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

struct Point {
	int x, y, z;
};

int n;
vector<vvc> a;

vi dx{0, 0, 0, 0, -1, 1};
vi dy{-1, 0, 1, 0, 0, 0};
vi dz{0, 1, 0, -1, 0, 0};

#define y0 y9999

int x0, y0, z0;

bool inside(int x, int y, int z) {
	bool f1 = (1 <= x && x <= n);
	bool f2 = (1 <= y && y <= n);
	bool f3 = (1 <= z && z <= n);
	return f1 && f2 && f3;
}

int bfs() {
	vector<vvi> color(n + 1, vvi(n + 1, vi(n + 1, -1)));
	color[x0][y0][z0] = 0;
	queue<Point> qu;
	qu.push(Point{x0, y0, z0});
	while(sz(qu)) {
		auto [x, y, z] = qu.front();
		if(x == 1) return color[x][y][z];
		qu.pop();
		fw(0, 5) {
			int x2 = x + dx[w];
			int y2 = y + dy[w];
			int z2 = z + dz[w];
			if(!inside(x2, y2, z2)) continue;
			if(color[x2][y2][z2] != -1) continue;
			if(a[x2][y2][z2] != '.') continue;
			color[x2][y2][z2] = color[x][y][z] + 1;
			qu.push(Point{x2, y2, z2});
		}
	}
	
}

void solve() {
	int ans = bfs();
	cout << ans << ln;
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
	a = vector<vvc>(n + 1, vvc(n + 1, vc(n + 1)));
	fi(1, n) {
		fj(1, n) {
			fo(1, n) {
				cin >> a[i][j][o];
				if(a[i][j][o] == 'S') {
					x0 = i;
					y0 = j;
					z0 = o;
				}
			}
		}
	}

    solve();

	auto TIME = ld(clock() - START) / CLOCKS_PER_SEC;
	dbg(TIME);
}