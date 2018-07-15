#include <bits/stdc++.h>
using namespace std;

#define times(n, i)      uptil(0, n, i)
#define rtimes(n, i)     downto((n) - 1, 0, i)
#define upto(f, t, i)    for(auto i##0_to = (t), i = decltype(t)(f); i <= i##0_to; i++)
#define uptil(f, t, i)   for(auto i##0_to = (t), i = decltype(t)(f); i <  i##0_to; i++)
#define downto(f, t, i)  for(auto i##0_to = decltype(f)(t), i = (f); i >= i##0_to; i--)
#define downtil(f, t, i) for(auto i##0_to = decltype(f)(t), i = (f); i >  i##0_to; i--)
/** types **/
	using LD = long double;
	#define double LD
	#define long long long
	#define LL long
	#define int long
	template<class T> using vec = vector<T>;
	using VB = vec<bool>;	using WB = vec<VB>;
	using VC = vec<char>;	using WC = vec<VC>;
	using VI = vec<int>;	using WI = vec<VI>;
	using VD = vec<double>;	using WD = vec<VD>;
	using VS = vec<string>;	using WS = vec<VS>;
	using PI = pair<int, int>;	using VPI = vec<PI>; using WPI = vec<VPI>;
	using MI = map<int, int>;	using VMI = vec<MI>;

bool debug;
#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 2
#define _LIBCPP_DEBUG2 2
#define ln << '\n'
#define tb << '\t'
#define sp << ' '
#define DD(x) if(debug) cerr << #x << " = " << (x) << ", "
#define DDD(x) if(debug) cerr << #x << " = " << (x) ln
#define db dd
#define dbg ddd

void settings();
void solve();

signed main(signed argc, char *argv[]) {
	#ifdef EBUG
		debug = true;
	#elif defined(ONLINE_JUDGE)
		debug = false;
	#else
		debug = argc >= 2;
	#endif
	if(!debug) {
		cin.tie(0);
		ios::sync_with_stdio(0);
	}
	cout << fixed << setprecision(20);
	cerr << fixed << setprecision(20);

	settings();
	solve();

	return 0;
}

/******************************* basic library ********************************/
/** structure **/
	template<class T> struct Graph { bool directed = false; int nv = -1; int ne = -1; vec<map<int,T>> e;
		Graph<T> rev() { if(not directed) return *this; Graph<T> g = *this; for(auto& ei : g.e) ei.clear(); times(nv, i) for(auto& p : e[i]) g.e[p.first][i] = p.second; return g; }
	};
	using GraphI = Graph<int>;
/** IO **/
	template<class T> inline istream& operator>>(istream& s, vec<T>& v) { for(auto&& p : v) s >> p; return s; }
	int INPUT_GRAPH_index_sub = 1, INPUT_GRAPH_cost = 0; bool INPUT_GRAPH_allow_empty = false;
	template<class T> inline istream& operator>>(istream& s, Graph<T>& g) {
		const int sub = INPUT_GRAPH_index_sub, cost = INPUT_GRAPH_cost, emptyp = INPUT_GRAPH_allow_empty;
		if(g.nv + emptyp <= 0 and g.ne + emptyp <= 0) { s >> g.nv >> g.ne; } g.e = VMI(g.nv);
		times(g.ne, i) { int x, y; T d = cost; s >> x >> y; if(!d) s >> d; g.e[x - sub][y - sub] = d; if(not g.directed) g.e[y - sub][x - sub] = d; } return s;
	}
	template<class T, class S> inline ostream& operator<<(ostream&, const pair<T, S>&);
	template<class T>          inline ostream& operator<<(ostream&, const vec<T>&);
	template<class T, class S> inline ostream& operator<<(ostream&, const map<T, S>&);
	template<class T> inline ostream& operator<<(ostream&, const Graph<T>&);
	#define DEFINE_ITER_OUTPUT(s, x, sep) { int i = 0; for(const auto& x##0_elem : x) { if(i++) s << sep; s << x##0_elem; } return s; }
	template<class T, class S> inline ostream& operator<<(ostream& s, const pair<T, S>& p) { return s << "(" << p.first << "," << p.second << ")"; }
	template<class T>          inline ostream& operator<<(ostream& s, const vec<T>& v) DEFINE_ITER_OUTPUT(s, v, ' ')
	template<class T, class S> inline ostream& operator<<(ostream& s, const map<T, S>& m) DEFINE_ITER_OUTPUT(s, m, ' ')
	template<class T>          inline ostream& operator<<(ostream& s, const vec<vec<T>>& w) DEFINE_ITER_OUTPUT(s, w, '\n')
	template<class T, class S> inline ostream& operator<<(ostream& s, const vec<map<T, S>>& vm) DEFINE_ITER_OUTPUT(s, vm, '\n')
	template<class T> inline ostream& operator<<(ostream& s, const Graph<T>& g) { return s << "Graph(nv:" << g.nv << " ne:" << g.ne << " e:[" ln << g.e ln << "])"; }
	inline void RD() {}
	template<class T, class...S> inline T& RD(T& t, S&... s) { cin >> t; RD(s...); return t; } /* returns first side */
	template<class T, class...S> inline vec<T>& RD(vec<T>& t, vec<S>&... s) { times(t.size(), i) { RD(t[i], s[i]...); } return t; }
	#define RR(typ, ...) typ __VA_ARGS__; RD(__VA_ARGS__)
	template<class T, class...A> inline T READ(A... a) { T t(a...); cin >> t; return t; }
	template<class T> inline void dddf(const T& t) { if(debug) cerr << t ln; }
	template<class T, class...U> inline void dddf(const T& t, const U&... u) { if(debug) { cerr << t << ", "; dddf(u...); }}
	#define ddd(...) if(debug) { cerr << #__VA_ARGS__ << " = "; dddf(__VA_ARGS__); }
/** container **/
	#define all(v) begin(v), end(v)
	template<class T> inline T max(const pair<T, T>& p) { return max(p.first, p.second); }
	template<class T> inline T min(const pair<T, T>& p) { return min(p.first, p.second); }
	template<class T> inline T max(const vec<T>& v) { return *max_element(all(v)); }
	template<class T> inline T min(const vec<T>& v) { return *min_element(all(v)); }
	template<class T> inline T sum(const vec<T>& v) { T s = v.empty() ? 0 : v[0]; uptil(1, v.size(), i) s += v[i]; return s; }
	template<class T> inline T sum(const vec<T>& v, int mod) { T s = v.empty() ? 0 : v[0]; uptil(1, v.size(), i) (s += v[i]) %= mod; return s; }
	template<class T, class U> inline T dig(const U& d, const T& t) { return t; }
	template<class T, class U, class...I> inline U dig(const U& d, const T& t, int i, I... j) {
		return 0 <= i && i < t.size() ? dig(d, t[i], j...) : d; }
	#define firstItrSTValGE lower_bound
	#define firstItrSTValGT upper_bound
/** other **/
	template<class T> inline signed SIZE(const T& t) { return t.size(); }
	#define size SIZE
	#define MP make_pair
	#define MT make_tuple
	#define PB push_back
	#define b_max(x, y) x = max(x, y)
	#define b_min(x, y) x = min(x, y)
	#define uniqSort(v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }
	inline LD AC(LD d) { return d ? d : 0; }
[[maybe_unused]] constexpr long INF = 1LL << 60;
[[maybe_unused]] constexpr long MOD = 1000000007; // 1000000009; // 998244353;

/****************************** optional library ******************************/

/************************************ main ************************************/

void settings() {
	// INPUT_GRAPH_index_sub = 0;		// uncomment if input index is 0-based
	// INPUT_GRAPH_allow_empty = true;	// uncomment to allow empty graph
	// INPUT_GRAPH_cost = 1;			// uncomment if all input costs are 1
}

void solve() {

}
