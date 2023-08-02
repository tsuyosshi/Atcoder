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

int N, M, K;
vector<vector<PI>> E;
vector<int> S;

int dijkstra(int s){
    vector<vector<int>> d(N, vector<int>(2, INF));
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    d[s][0] = 0;
    pq.push(PII(0, PI(s, 0)));
    while (pq.size() > 0) {
        PII p = pq.top();
        pq.pop();
        int v = p.second.first;
        int b = p.second.second;
        if (d[v][b] < p.first) continue;
        for (auto e: E[v]) {
            int u = e.first, a = e.second;
            if ((a+b) % 2 != 1) {
                continue;
            }
            if(d[u][b] > d[v][b] + 1){
                d[u][b] = d[v][b] + 1;
                pq.push(PII(d[u][b], PI(u, b)));
            }
        }
        if (S[v] == 1) {
            if(d[v][!b] > d[v][b]){
                d[v][!b] = d[v][b];
                pq.push(PII(d[v][!b], PI(v, !b)));
            }
        }
    }
    return min(d[N-1][0], d[N-1][1]);
}

signed main() {
    cin >> N >> M >> K;
    E = vector<vector<PI>>(N);
    S = vector<int>(N, 0);
    for (int i = 0; i < M; ++i) {
        int u, v, a;
        cin >> u >> v >> a;
        u--, v--;
        E[u].push_back(PI(v, a));
        E[v].push_back(PI(u, a));
    }
    for (int i = 0; i < K; ++i) {
        int s;
        cin >> s;
        s--;
        S[s] = 1;
    }
    auto res = dijkstra(0);
    if (res != INF) {
        cout << res << endl;
    } else {
        cout << -1 << endl;
    }
}