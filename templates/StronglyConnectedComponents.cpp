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

struct StronglyConnectedComponents {
    int n;
    vector<vector<int>> G;
    vector<vector<int>> revG;
    vector<int> order, component, component_size;
    vector<bool> used;

    StronglyConnectedComponents(vector<vector<int>> &_G) {
        n = _G.size();
        G = _G;
        revG.resize(n);
        component.assign(n, -1);
        used.assign(n, false);
        for (int v = 0; v < n; ++v) {
            for (auto u: G[v]) revG[u].push_back(v);
        }
        for (int v = 0; v < n; ++v) {
            if (!used[v]) dfs(v);
        }
        reverse(order.begin(), order.end());
        int k = 0;
        for (auto v: order) {
            if (component[v] == -1) {
                rev_dfs(v, k);
                k++;
            }
        }
        component_size.assign(k, 0);
        for (int v = 0; v < n; ++v) component_size[component[v]]++;
    }

    void dfs(int v) {
        used[v] = true;
        for (auto u: G[v]) {
            if (!used[u]) dfs(u);
        }
        order.push_back(v);
    }

    void rev_dfs(int v, int k) {
        component[v] = k;
        for(auto u: revG[v]) {
            if (component[u] == -1) rev_dfs(u, k); 
        }
    }

    bool same(int x, int y) {
        return component[x] == component[y];
    }

    int size() {
        return component_size.size();
    }

};

signed main() {
}