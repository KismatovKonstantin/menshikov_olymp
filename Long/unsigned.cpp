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

#define ln "\n"
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
	fx(v) {
		os << x << " ";
	}
	return os;
}

template<typename T>
ostream& operator<<(ostream& os, vector<vector<T>> v) {
	os << ln;
	fx(v) {
		os << x << ln;
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
 
template<typename A, typename B>
ostream& operator<<(ostream& os, map<A, B> t) {
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

struct Long {
    int base = 10000;
    int len = 4;
    vi num = {1, 0};
    int operator[](int x) const {
        if (x > num[0]) return 0;
        return num[x];
    }
    int& operator[](int x) {
        if (x > num[0]) {
            num.resize(x + 1, 0);
            num[0] = x;
        }
        return num[x];
    }
};
Long operator+(const Long& A, const Long& B) {
    Long res;

    int n = max(A[0], B[0]);
    fi(1, n) {
        res[i] = A[i] + B[i];
        if (i > 1) {
            res[i] += res[i - 1] / res.base;
            res[i - 1] %= res.base;
        }
    }
    while(res[res[0]] >= res.base) {
        int m = res[0];
        res[m + 1] = res[m] / res.base;
        res[m] %= res.base;
    }
    return res;
}
Long operator*(const Long& A, const Long& B) {
    Long res;

    fi(1, A[0]) {
        if (A[i] == 0) continue;
        fj(1, B[0]) {
            if (A[i] * B[i] == 0) continue;
            int x = i + j - 1;
            res[x] += A[i] * B[j];
            while(x > 1 && res[x - 1] >= res.base) {
                res[x] += res[x - 1] / res.base;
                res[x - 1] %= res.base;
            }
        }
        while(res[res[0]] >= res.base) {
            int m = res[0];
            res[m + 1] += res[m] / res.base;
            res[m] %= res.base;
        }
    }
    return res;
}
pair<Long, int> operator/(const Long& A, const int B) {
    Long res;
    int x = 1;
    int d = 0, m = 0;
    fdi(A[0], 1) {
        int val = m * res.base + A[i];
        d = val / B;
        m = val % B;
        if (x == 1 && d == 0) continue;
        res[x] = d;
        x++;
    }
    reverse(Allf(res.num));
    return mp(res, m);
}

void print(const Long& A) {
    printf("%d", A[A[0]]);
    fdi(A[0] - 1, 1) {
        printf("%04d", A[i]);
    }
    printf(ln);
}

Long str_to_Long(const string& s) {
    int n = sz(s);
    Long res;
    int x = 1;
    for(int i = n - 1; i >= 0; i -= 4) {
        int val = 0;
        for(int j = max(0, i - 3); j <= i; i++) {
            val = val * 10 + (s[j] - '0');
        }
        res[x] = val;
        x++;
    }
    return res;
}
Long int_to_Long(int num) {
    Long res;
    int x = 1;
    while(num) {
        int val = num % res.base;
        num /= res.base;
        res[x] = val;
        x++;
    }
    return res;
}

void solve() {

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

	

    solve();

	auto TIME = ld(clock() - START) / CLOCKS_PER_SEC;
	dbg(TIME);
}