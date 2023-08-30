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

void dfs(int v, int prev, int &res, vector<vector<int>> &A, deque<int> &history, vector<bool> &seen, vector<bool> &finished) {
    seen[v] = true;
    history.push_back(v);
    for (auto u: A[v]) {
        if (u == prev) continue;
        if (finished[u]) continue;
        if (seen[u] && !finished[u]) {
            res = u;
            return;
        }
        dfs(u, v, res, A, history, seen, finished);
    }
    finished[v] = true;
    history.pop_back();
}

vector<int> cycle_detection(vector<vector<int>> &A) {
    int n = A.size();
    vector<bool> seen(n, false), finished(n, false);
    for (int i = 0; i < n; ++i) {
        if (seen[i] && finished[i]) continue;
        deque<int> history;
        int v = -1;
        dfs(i, -1, v, A, history, seen, finished);
        if (v != -1) {
            vector<int> cycle;
            while (!history.empty()) {
                int c = history.back();
                cycle.push_back(c);
                history.pop_back();
                if (c == v) break;
            }
            reverse(cycle.begin(), cycle.end());
            return cycle;
        }
    }
    return vector<int>();
}

int N, M;

signed main() {
    cin >> N >> M;
    vector<vector<int>> E(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        E[a].push_back(b);
        E[b].push_back(a);
    }
    for (int i = 0; i < N; ++i) {
        if (E[i].size() > 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    auto ans = cycle_detection(E);
    if (ans.size() > 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
}  