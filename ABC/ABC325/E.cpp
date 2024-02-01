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

int N;
int A, B, C;

int dijkstra(int s, vector<vector<PI>> &G) {
    int n = G.size();
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    vector<vector<int>> dist(n, vector<int>(2, INF));
    dist[s][0] = dist[s][1] = 0;
    pq.push(PII(dist[s][0], PI(s, 0)));
    pq.push(PII(dist[s][1], PI(s, 1)));
    while (pq.size() > 0) {
        auto p = pq.top();
        pq.pop();
        int v = p.second.first, f = p.second.second;
        if (dist[v][f] < p.first) continue;
        for (auto e: G[v]) {
            int u = e.first, c1 = A * e.second, c2 = B * e.second + C;
            if (f == 0 && dist[u][0] > dist[v][f] + c1) {
                dist[u][0] = dist[v][f] + c1;
                pq.push(PII(dist[u][0], PI(u, 0)));
            }
            if (dist[u][1] > dist[v][f] + c2) {
                dist[u][1] = dist[v][f] + c2;
                pq.push(PII(dist[u][1], PI(u, 1)));
            }
        }
    }
    return min(dist[n-1][0], dist[n-1][1]);
}

signed main() {
    cin >> N >> A >> B >> C;
    vector<vector<PI>> D(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int d;
            cin >> d;
            if (i == j) continue;
            D[i].push_back(PI(j, d));
            D[j].push_back(PI(i, d));
        }
    }
    cout << dijkstra(0, D) << endl;
}                           