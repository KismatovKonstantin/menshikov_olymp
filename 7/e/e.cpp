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
pii A, B;
vector<vector<vector<pii>>> e;
vvll color;

void bfs() {
	queue<pii> qu;
    qu.push(A);
    color[A.first][A.second] = 1;

    while(sz(qu)) {
        auto p = qu.front();
        int x = p.first;
        int y = p.second;
        qu.pop();
        for(auto& p2 : e[x][y]) {
            int x_2 = p2.first;
            int y_2 = p2.second;
            if(color[x_2][y_2]) continue;
            color[x_2][y_2] = color[x][y] + 1;
            qu.push({x_2, y_2});
        }
    }
}
bool f = false;
void dfs(int x, int y) {
    if(mp(x, y) == A) f = true;
    if(f) return;
    mtr[x][y] = '+';
    for(auto& p2 : e[x][y]) {
        int x_2 = p2.first;
        int y_2 = p2.second;
        if(color[x_2][y_2] == color[x][y] - 1) {
            dfs(x_2, y_2);
        }
    }
}

void solve() {
	color = vvll(n + 1, vll(n + 1));
    bfs();
    if(color[B.first][B.second] == 0) {
        cout << "N" << ln;
        return;
    }
    dfs(B.first, B.second);
    
    cout << "Y" << ln;
    fi(1, n) {
        fj(1, n) {
            cout << mtr[i][j];
        }
        cout << ln;
    }
}

vi dx{-1, 0, 1, 0};
vi dy{0, 1, 0, -1};
bool is_valid(int x, int y) {
	bool f1 = (1 <= x && x <= n);
	bool f2 = (1 <= y && y <= n);
    bool f3 = false;
    if(f1 && f2) {
	    f3 = (mtr[x][y] != 'O');
    }
	return f1 && f2 && f3;
}

void init() {
	e = vector<vector<vector<pii>>>(n + 1, vector<vector<pii>>(n + 1));
	fi(1, n) {
		fj(1, n) {
			if(!is_valid(i, j)) continue;
			fo(0, 3) {
				int i_2 = i + dx[o];
				int j_2 = j + dy[o];
				if(is_valid(i_2, j_2)) {
					e[i][j].pb({i_2, j_2});
				}
			}
		}
	}
}

#define FILE "lines2"
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
	mtr = vvc(n + 1, vc(n + 1));
	fi(1, n) {
		fj(1, n) {
			scanf(" %1c", &mtr[i][j]);
			if(mtr[i][j] == '@') A = {i, j};
			else if(mtr[i][j] == 'X') B = {i, j};
		}
	}
	init();
    solve();

	auto END = clock();
	dbg(END - START);
}