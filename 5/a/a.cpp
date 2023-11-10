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

ll l, r;
vb color;

vector<pii> v{
	{220, 284},
	{1184, 1210},
	{2620, 2924},
	{5020, 5564},
	{6232, 6368},
	{10744, 10856},
	{12285, 14595},
	{17296, 18416},
	{63020, 76084},
	{66928, 66992},
	{67095, 71145},
	{69615, 87633},
	{79750, 88730},
	{100485, 124155},
	{122265, 139815},
	{122368, 123152},
	{141664, 153176},
	{142310, 168730},
	{171856, 176336},
	{176272, 180848},
	{185368, 203432},
	{196724, 202444},
	{280540, 365084},
	{308620, 389924},
	{319550, 430402},
	{356408, 399592},
	{437456, 455344},
	{469028, 486178},
	{503056, 514736},
	{522405, 525915},
	{600392, 669688},
	{609928, 686072},
	{624184, 691256},
	{635624, 712216},
	{643336, 652664},
	{667964, 783556},
	{726104, 796696},
	{802725, 863835},
	{879712, 901424},
	{898216, 980984}

};

ll fun(ll x) {
	ll res = 1;
	for(ll i = 2; i * i <= x; i++) {
		if(x % i) continue;
		res += i;
		res += x / i;
	}
	return res;
}

void solve1() {
	vector<pll> ans;
	fi(l, r) {
		if(color[i]) continue;
		ll x = fun(i);
		if(x == i) continue;
		if(l <= x && x <= r) {
			ll y = fun(x);
			if(y == i) {
				color[i] = 1;
				color[x] = 1;
				ans.pb(mp(i, x));
			}
		}
	}
	if(sz(ans) == 0) {
		cout << "Absent" << ln;
		return;
	}
	fz(ans) {
		cout << "{" << z.first << ", " << z.second << "}," << ln;
	}
}
void solve2() {
	bool f = false;
	fz(v) {
		if(z.first >= l && z.first <= r && z.second >= l && z.second <= r) {
			f = true;
			cout << z.first << " " << z.second << ln;
		}
	}
	if(!f) cout << "Absent" << ln;
}


#define FILE "friendly"
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

	cin >> l >> r;
	color = vb(r + 1);

    solve2();

	auto END = clock();
	dbg(END - START);
}