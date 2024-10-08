/*
	Discord: powder7854
	https://www.facebook.com/hai290605
	https://codeforces.com/profile/Etohari
	https://oj.vnoi.info/user/powder
*/
#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"

//@Etohari
using namespace std;
using namespace __gnu_pbds;

template < class T, class G > bool minimum(T& a, const G b) { return b < a ? a = b, 1 : 0; }
template < class T, class G > bool maximum(T& a, const G b) { return a < b ? a = b, 1 : 0; }

template < class T > using heap_min = priority_queue < T, vector < T >, greater < T > >;
template < class T > using heap_max = priority_queue < T, vector < T >, less < T > >;
template < class T > using ordered_set = tree < T, null_type, less < T >, rb_tree_tag, tree_order_statistics_node_update >;
template < class T > using ordered_multiset = tree < T, null_type, less_equal < T >, rb_tree_tag, tree_order_statistics_node_update >;

#define my_wife "Thu"
#define bit(mask,i) ((mask>>i)&1)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define uniquev(v) sort(all(v)), (v).resize(unique(all(v)) - (v).begin())
#define __lcm(a,b) ((int64_t)(a) / __gcd((a), (b)) * (b))
#define rand(l, r) uniform_int_distribution < int64_t > (l, r)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

constexpr int32_t MOD = 1e9 + 7;
constexpr int32_t MAXN = 1e6 + 10;
constexpr int32_t MAXM = 1e6 + 10; 
constexpr int32_t INF32 = 0x3f3f3f3f;
constexpr int64_t INF64 = INF32;

constexpr int16_t DR[] = { };
constexpr int16_t DC[] = { };

#define int int64_t

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);

	int n, m, l, s, t;
	cin >> n >> m >> l >> s >> t;

	vector < int > edge;
	vector < int > u(m + 1), v(m + 1), w(m + 1);
	for (int i = 1; i <= m; i ++) {
		cin >> u[i] >> v[i] >> w[i];
		if (w[i] == 0) edge.emplace_back(i);
	}
	
	auto check = [&](int x) {
		for (auto& i : edge) {
			w[i] = min(x, INF64) + 1;
			x -= w[i] - 1;
		}

		vector < vector < pair < int, int > > > adj(n + 1);
		for (int i = 1; i <= m; i ++) {
			adj[u[i]].emplace_back(v[i], w[i]);
			adj[v[i]].emplace_back(u[i], w[i]);
		}

		vector < int > dist(n + 1, INF64);
		heap_min < pair < int, int > > qe;
		dist[s] = 0;
		qe.emplace(0, s);
		while (!qe.empty()) {
			auto [du, u] = qe.top();
			qe.pop();
			if (du != dist[u]) continue;
			for (auto [v, w] : adj[u]) {
				if (minimum(dist[v], du + w)) {
					qe.emplace(dist[v], v);
				}
			}
		}
		return dist[t];
	};

	int64_t bot = -1, top = INF64 * INF64;
	if (check(bot + 1) > l || check(top) < l) {
		cout << "NO";
		return 0;
	}

	cout << "YES\n";
	while (bot + 1 < top) {
		int64_t mid = bot + top >> 1;
		if (check(mid) >= l) {
			top = mid;
		}else {
			bot = mid;
		}
	}

	check(top);

	for (int i = 1; i <= m; i ++) {
		cout << u[i] << " " << v[i] << " " << w[i] << "\n";
	}

	return (0 ^ 0);
}

/* Cho tới khi nào ? */