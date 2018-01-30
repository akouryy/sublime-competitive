// https://beta.atcoder.jp/contests/arc090/submissions/2040978
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
#define dd(x) if(debug) cerr << #x << " = " << (x) << ", "
#define ddd(x) if(debug) cerr << #x << " = " << (x) ln
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
/** container **/
	#define all(v) begin(v), end(v)
	template<class T> inline T max(const pair<T, T>& p) { return max(p.first, p.second); }
	template<class T> inline T min(const pair<T, T>& p) { return min(p.first, p.second); }
	template<class T> inline T max(const vec<T>& v) { return *max_element(all(v)); }
	template<class T> inline T min(const vec<T>& v) { return *min_element(all(v)); }
/** other **/
constexpr long INF = 1LL << 60;
constexpr long MOD = 1000000007; // 998244353;
	#define b_max(x, y) x = max(x, y)
	#define b_min(x, y) x = min(x, y)
	inline int b_mod(int& x, int y = MOD) { x %= y; if(x < 0) x += y; return x; }
	inline LD AC(LD d) { return d ? d : 0; }

/****************************** optional library ******************************/
/* <sr.g.tpsort> */
	// VERIFIED: abc021c
	template<class T> VI tpsort(const Graph<T>& g) {
		VI tp; VB visited(g.nv);
		times(g.nv, i) tpsort_dfs(g, i, tp, visited);
		reverse(all(tp));
		return tp;
	}
	template<class T> void tpsort_dfs(const Graph<T>& g, int i, VI& tp, VB& visited) {
		if(visited[i]) return;
		visited[i] = true;
		for(const auto& p : g.e[i]) tpsort_dfs(g, p.first, tp, visited);
		tp.push_back(i);
	}
/* </sr.g.tpsort> */

/************************************ main ************************************/

void settings() {
	// INPUT_GRAPH_index_sub = 0;		// uncomment if input index is 0-based
	// INPUT_GRAPH_allow_empty = true;	// uncomment to allow empty graph
	// INPUT_GRAPH_no_cost = 1;			// uncomment if all input costs are 1
}
// https://beta.atcoder.jp/contests/arc090/submissions/2040978
void solve() {
	GraphI G; int S, T; cin >> G.nv >> G.ne >> S >> T >> G; --S; --T;
	vec<int> costs_s(G.nv, INF);
	vec<int> costs_t(G.nv, INF);
	auto dag_s = G; dag_s.directed = true; for(auto& ei : dag_s.e) ei.clear();
	auto dag_t = G; dag_t.directed = true; for(auto& ei : dag_t.e) ei.clear();
	{/* <sr.g.ddag> */
		/* <sr.g.djk> */
			// VERIFIED: abc021c
			priority_queue<pair<int, int>> pq;
			pq.push({-0 /* minus init-cost */, S /* start */});
			while(!pq.empty()) {
				int i, c; tie(c, i) = pq.top(); pq.pop(); c = -c;
				if(costs_s[i] > c) {
					costs_s[i] = c;
					for(const auto& p : G.e[i]) { /* p: {index, cost} */
						int j = p.first, d = c + p.second;
						if(costs_s[j] > d) pq.push({-d, j});
					}
				}
			}
		/* </sr.g.djk> */
		// dijkstra-dag VERIFIED: abc021c
		times(dag_s.nv, i) for(auto& p : G.e[i]) {
			int j = p.first; if(costs_s[j] - costs_s[i] == p.second) dag_s.e[i][j] = p.second;
		}
	}/* </sr.g.ddag> */
	{/* <sr.g.ddag> */
		/* <sr.g.djk> */
			// VERIFIED: abc021c
			priority_queue<pair<int, int>> pq;
			pq.push({-0 /* minus init-cost */, T /* start */});
			while(!pq.empty()) {
				int i, c; tie(c, i) = pq.top(); pq.pop(); c = -c;
				if(costs_t[i] > c) {
					costs_t[i] = c;
					for(const auto& p : G.e[i]) { /* p: {index, cost} */
						int j = p.first, d = c + p.second;
						if(costs_t[j] > d) pq.push({-d, j});
					}
				}
			}
		/* </sr.g.djk> */
		// dijkstra-dag VERIFIED: abc021c
		times(dag_t.nv, i) for(auto& p : G.e[i]) {
			int j = p.first; if(costs_t[j] - costs_t[i] == p.second) dag_t.e[i][j] = p.second;
		}
	}/* </sr.g.ddag> */

	ddd(costs_s); ddd(costs_t);
	ddd(dag_s); ddd(dag_t);
	auto rdag_s = dag_s.rev(), rdag_t = dag_t.rev();
	ddd(rdag_s); ddd(rdag_t);
	ddd(tpsort(dag_s)); ddd(tpsort(dag_t));
	VI num_s(G.nv), num_t(G.nv); num_s[S] = num_t[T] = 1;
	for(int i : tpsort(dag_s)) for(auto& p : rdag_s.e[i]) b_mod(num_s[i] += num_s[p.first]);
	for(int i : tpsort(dag_t)) for(auto& p : rdag_t.e[i]) b_mod(num_t[i] += num_t[p.first]);
	int ans = num_s[T] * num_s[T] % MOD, c = costs_s[T];
	ddd(num_s); ddd(num_t); ddd(ans);
	times(G.nv, i) {
		if(costs_s[i] * 2 == c && costs_t[i] * 2 == c) b_mod(ans -= num_s[i] * num_t[i] % MOD * num_s[i] % MOD * num_t[i]);
	}
	times(G.nv, i) for(auto& p : dag_s.e[i]) {
		int j = p.first;
		if(costs_s[i] * 2 < c && costs_t[j] * 2 < c && costs_s[i] + costs_t[j] + p.second == c)
			b_mod(ans -= num_s[i] * num_t[j] % MOD * num_s[i] % MOD * num_t[j]);
	}
	cout << ans ln;
}
