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
	os << ln;
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

int n;
vi a;
vi b;

ll Q = 0;

void QSort(int left,  int right) {
	int key = a[(left + right) / 2];
	int i = left;
	int j = right;
	while(i <= j) {
		Q++;
		while(a[i] < key) {
			i++;
			Q++;
		}
		Q++;
		while(key < a[j]) {
			j--;
			Q++;
		}
		if(i <= j) {
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if(left < j) {
		QSort(left, j);
	}
	if(i < right) {
		QSort(i, right);
	}
}

map<int, set<vi>> t;

void solve() {
	ll m = 0;
	vi ans;
	do{
		Q = 0;
		a = b;
		QSort(1, n);
		t[Q].ins(b);
		if(Q > m) {
			m = Q;
			ans = b;
		}
	}while(next_permutation(Allf(b)));

	dbg((*t.rbegin()).first);
	dbg((*t.rbegin()).second);
	fi(1, n) {
		cout << ans[i] << " ";
	}
}



void solve2() {
	vll ans(n + 1);
	int l = 1, r = n;
	int cur = 1;
	while(l <= r) {
		dbg(b);
		int h = (l + r) / 2;
		if(cur == n - 1) {
			ans[b[h]] = n;
			ans[b[h + 1]] = n - 1;
			break;
		}
		ans[b[h]] = cur++;
		swap(b[l], b[h]);
		l++;
		dbg(ans);
		dbg(b);
	}
	fi(1, n) {
		cout << ans[i] << " ";
	}
	dbg(b);
	dbg(ans);
}

void print() {
	solve();
	exit(0);
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
	b = vi(n + 1);
	fi(1, n) {
		b[i] = i;
	}

	// print();
	if (n <= 7) solve();
    else solve2();

	auto TIME = ld(clock() - START) / CLOCKS_PER_SEC;
	dbg(TIME);
}