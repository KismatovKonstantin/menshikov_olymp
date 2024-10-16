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
	vector<int> c;
	Poly() {
		c.resize(21, 0);
	}
};
pair<int, int> parse(char* s) {
	int coef, p;
	char tmp[100];
	tmp[0] = 0;
	if (sscanf(s, "%dx^%d", &coef, &p) == 2) {
		return {coef, p};
	} else if (sscanf(s, "%d%[x]", &coef, tmp) == 2) {
		return {coef, 1};
	} else if (sscanf(s, "%d", &coef) == 1) {
		return {coef, 0};
	} else if (sscanf(s, "x^%d", &p) == 1) {
		return {1, p};
	} else if (sscanf(s, "%[x]", tmp) == 1) {
		return {1, 1};
	}	
	
}
void read(Poly& a) {
	char tmp[100];
	char s[100];
	char sign = '+';

	if (scanf("%[+-]", tmp) == 1) {
		sign = tmp[0];
		dbg(sign);
	}

	while(scanf("%[^+-\n]%[+-]", s, tmp) > 0) {
		string g = s;
		dbg(g);
		auto [coef, p] = parse(s);
		dbg(mp(coef, p));
		a.c[p] += (sign == '+' ? coef : -coef);
		sign = tmp[0];
	}
	scanf("\n");
}
void print(const Poly& a) {
	bool fl = false;
	fdi(20, 1) {
		if (a.c[i] == 0) continue;

		if (a.c[i] > 0 && fl) printf("+");

		if (a.c[i] == -1) printf("-");
		else if (a.c[i] != 1) printf("%d", a.c[i]);
		printf("x");
		if (i > 1) {
			printf("^%d", i);
		}

		fl = true;
	}
	if (a.c[0] > 0 && fl) printf("+");
	if (a.c[0] != 0 || !fl) printf("%d", a.c[0]);
	printf("\n");
}
Poly operator* (const Poly& a, const Poly& b) {
	Poly res;
	fi(0, 10) {
		fj(0, 10) {
			res.c[i + j] += a.c[i] * b.c[j];
		}
	}
	return res;
}

Poly a, b, c;

void solve() {
	c = a * b;
	print(c);
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

	read(a);
	read(b);

    solve();

	auto TIME = ld(clock() - START) / CLOCKS_PER_SEC;
	dbg(TIME);
}