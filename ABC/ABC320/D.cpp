#include <bits/stdc++.h>

using namespace std;

#define int long long
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

typedef pair<int, int> PI;
typedef pair<int, pair<int, int>> PII;
static const int INF = 1010000000000000017LL;
static const double eps = 1e-12;
static const double pi = 3.14159265358979323846;
static const int dx[4] = {1, -1, 0, 0};
static const int dy[4] = {0, 0, 1, -1};
static const int ddx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
static const int ddy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

template<class T> inline bool chmin(T& a, T b) { if(a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if(a < b) { a = b; return true; } return false; }

struct edge {
    int to;
    PI dir;
    edge (int _to, PI _dir) : to(_to), dir(_dir) {}
};

PI add(const PI &x, const PI &y) {
    return PI(x.first+y.first, x.second+y.second);
}

int N, M;

signed main() {
    cin >> N >> M;
    vector<vector<edge>> G(N);
    for (int i = 0; i < M; ++i) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        a--, b--;
        G[a].push_back(edge(b, PI(x, y)));
        G[b].push_back(edge(a, PI(-x, -y)));
    }
    vector<PI> P(N);
    vector<bool> visited(N, false);
    queue<int> que;
    que.push(0);
    P[0] = PI(0, 0);
    visited[0] = true;
    while (que.size() > 0) {
        int v = que.front();
        que.pop();
        for (auto e: G[v]) {
            int u = e.to;
            if (!visited[u]) {
                P[u] = add(P[v], e.dir);
                que.push(u);
                visited[u] = true;
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        if (visited[i]) {
            cout << P[i].first << " " << P[i].second << endl;
        } else {
            cout << "undecidable" << endl;
        }
    }
}  