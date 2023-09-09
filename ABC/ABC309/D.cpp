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

int N1, N2, M;

vector<int> bfs(int s, vector<vector<int>> &E){
    int n = E.size();
    queue<int> que;
    vector<int> dist(n, INF);
    que.push(s);
    dist[s] = 0;
    while (que.size() > 0) {
        int v = que.front();
        que.pop();
        for (auto u: E[v]) {
            if (dist[u] != INF) continue;
            que.push(u);
            dist[u] = dist[v] + 1;
        }  
    }
    return dist;
}

signed main() {
    cin >> N1 >> N2 >> M;
    vector<vector<int>> E1(N1), E2(N2);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        if (u <= N1) {
            u--, v--;
            E1[u].push_back(v);
            E1[v].push_back(u);
        } else {
            u -= N1, v -= N1;
            u--, v--;
            E2[u].push_back(v);
            E2[v].push_back(u);
        }
    }
    auto dist1 = bfs(0, E1);
    auto dist2 = bfs(N2-1, E2);
    int ma1 = -INF, ma2 = -INF;
    for (int i = 0; i < N1; ++i) if (dist1[i] != INF) chmax(ma1, dist1[i]);
    for (int i = 0; i < N2; ++i) if (dist2[i] != INF) chmax(ma2, dist2[i]);
    cout << ma1 + ma2 + 1 << endl;
}  