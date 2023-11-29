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
ostream& operator<<(ostream& os, vector<vector<T>> matr) {
	os << ln;
	fz(matr) {
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


int n;
vvc matr;
vvi color;

int xy_to_val(int x, int y) {
	return (x - 1) * n + y;
}
pii val_to_xy(int val) {
	int x = (val - 1) / n + 1;
	int y = (val - 1) % n + 1;
	return mp(x, y);
}

vi dx{-2, -1, 1, 2, 2, 1, -1, -2};
vi dy{1, 2, 2, 1, -1, -2, -2, -1};

bool is_valid(int x, int y) {
	bool f1 = (1 <= x && x <= n);
	bool f2 = (1 <= y && y <= n);
	return f1 && f2;
}

pii P1{0, 0}, P2{0, 0};

void bfs() {
	queue<pii> qu;
	qu.push(P1);

	while(sz(qu)) {
		int x = qu.front().first;
		int y = qu.front().second;
		qu.pop();

		fo(0, 7) {
			int x2 = x + dx[o];
			int y2 = y + dy[o];

			if(!is_valid(x2, y2)) continue;
			if(matr[x2][y2] == '#') continue;
			if(color[x2][y2]) continue;

			qu.push(mp(x2, y2));
			color[x2][y2] = xy_to_val(x, y);
		}
	}
}

void solve() {
	bfs();
	int x1 = P2.first;
	int y1 = P2.second;
	if(color[x1][y1] == 0) {
		cout << "Impossible" << ln;
		return;
	}
	dbg(color);
	while(1) {
		if(mp(x1, y1) == P1) break;
		auto p = val_to_xy(color[x1][y1]);
		int x2 = p.first;
		int y2 = p.second;
		dbg(p);
		matr[x2][y2] = '@';
		x1 = x2;
		y1 = y2;
	}

	fi(1, n) {
		fj(1, n) {
			cout << matr[i][j];
		}
		cout << ln;
	}
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

	cin >> n;
	matr = vvc(n + 1, vc(n + 1, '.'));
	color = vvi(n + 1, vi(n + 1, 0));
	fi(1, n) {
		fj(1, n) {
			scanf(" %1c ", &matr[i][j]);
			if(matr[i][j] == '@') {
				if(P1 == mp(0, 0)) P1 = mp(i, j);
				else P2 = mp(i, j);
			}
		}
	}

    solve();

	auto END = clock();
	dbg(END - START);
}