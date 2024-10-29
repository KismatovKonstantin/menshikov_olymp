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

#define EXPR 1
#define TERM 2
#define FACTOR 3
#define CELL 4
#define NUM 5

struct Node {
	int type;
	int val;
	string s;
	Node* left = NULL;
	Node* right = NULL;
	Node() {}
	Node(int type) {
		this->type = type;
	}
};

int n;
string s;
map<string, Node*> t;
map<string, int> val;
int cur = 0;
int Q = 0;

int get_val(Node* node) {
	dbg(node->type);
	dbg(node->s);
	if (node == NULL) exit(0);
	Q++;
	if (Q > 10000) {
		cout << 1000000 << ln;
		exit(0);
	}
	if (node->left == NULL || node->right == NULL) {
		if (node->type == CELL) {
			if (val.count(node->s)) return val[node->s];
			if (t.count(node->s)) return val[node->s] = get_val(t[node->s]);
			return 0;
		}
		return node->val;
	}
	int left_val = get_val(node->left);
	int right_val = get_val(node->right);
	int res = 0;
	if (node->s == "+") res = left_val + right_val;
	else if (node->s == "-") res = left_val - right_val;
	else if (node->s == "*") res = left_val * right_val;
	else if (node->s == "/") {
		if (right_val == 0) return 0;
		res = left_val / right_val;
	}
	return res;
}

void solve() {
	if (t.count("A1")) cout << get_val(t["A1"]) << ln;
	else cout << 0 << ln;
}

void next() {
	cur++;
}
void skip() {
	while(s[cur] == ' ') cur++;
}

Node* expr();
Node* term();
Node* factor();
Node* cell();
Node* num();

Node* parse() {
	skip();
	return expr();
}

Node* expr() {
	Node* res = new Node(EXPR);
	Node* node = term();
	skip();
	if (s[cur] == '+') {
		next();
		skip();
		res->s = "+";
		res->left = node;
		res->right = expr();
	} else if (s[cur] == '-') {
		next();
		skip();
		res->s = "-";
		res->left = node;
		res->right = expr();
	} else {
		res = node;
	}
	return res;
}
Node* term() {
	Node* res = new Node(TERM);
	Node* node = factor();
	skip();
	if (s[cur] == '*') {
		next();
		skip();
		res->s = "*";
		res->left = node;
		res->right = term();
	} else if (s[cur] == '/') {
		next();
		skip();
		res->s = "/";
		res->left = node;
		res->right = term();
	} else {
		res = node;
	}
	return res;
}
Node* factor() {
	Node* res = new Node(FACTOR);
	skip();
	if (s[cur] == '(') {
		next();
		skip();
		res = expr();
		skip();
		assert(s[cur] == ')');
		next();
	} else if ('A' <= s[cur] && s[cur] <= 'Z') {
		res = cell();
	} else {
		res = num();
	}
	return res;
}
Node* cell() {
	Node* res = new Node(CELL);
	string g = "";
	g += s[cur];
	next();
	g += s[cur];
	next();

	res->s = g;
	res->val = 0;
	return res;
}
Node* num() {
	Node* res = new Node(NUM);
	int x = 0;
	while('0' <= s[cur] && s[cur] <= '9') {
		x *= 10;
		x += s[cur] - '0';
		next();
	}

	res->val = x;
	return res;
}

#define FILE ""
int main()
{
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
	#else
		// freopen(FILE".in", "r", stdin);
        // freopen(FILE".out", "w", stdout);
    #endif

	auto START = clock();

	cin >> n;
	fi(1, n) {
		char l[127], r[127];
		scanf(" %[A-Z0-9] = %[^\n]\n", l, r);
		s = r;
		dbg(mp(string(l), s));
		// if (n == 1 && string(l) == "A1" && string(r) == "2*2") {
		// 	cout << 4 << ln;
		// 	exit(0);
		// }
		cur = 0;
		t[l] = parse();
	}


	solve();

	auto TIME = ld(clock() - START) / CLOCKS_PER_SEC;
	dbg(TIME);
	
	return 0;
}