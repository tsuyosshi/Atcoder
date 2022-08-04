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

template<typename T>
struct edge {
    int to;
    T cost;
    edge(int to, T cost) : to(to), cost(cost) {}
};

template<typename T>
class Dijkstra {

    int n, m;
    vector<edge<T>> E;
    vector<T> d;

    Dijkstra(int n, int m, vector<edge<T>> E, T def) : n(n), m(m), E(E) {
        d = vector<T>(N, def);
    }

    void run(int s, T init) {
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
        d[s] = init;
        pq.push(pair<T, int>(init, s));
        while (pq.size()) {
            pair<T, int> p = pq.top();
            pq.pop();
            int v = p.second;
            if(d[v] < p.first) continue;
            for(int i = 0; i < G[v].size(); ++i) {
                edge e=G[v][i];
                if(d[e.to]>d[v]+e.cost){
                    d[e.to]=d[v]+e.cost;
                    pq.push(PI(d[e.to],e.to));
                }
            }
        }
    }
};

signed main() {
}