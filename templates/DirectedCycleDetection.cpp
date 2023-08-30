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

void dfs(int v, int &res, vector<vector<int>> &A, deque<int> &history, vector<bool> &seen, vector<bool> &finished) {
    seen[v] = true;
    history.push_back(v);
    for (auto u: A[v]) {
        if (finished[u]) continue;
        if (seen[u] && !finished[u]) {
            res = u;
            return;
        }
        dfs(u, res, A, history, seen, finished);
        if (res != -1) return;
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
        dfs(i, v, A, history, seen, finished);
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

int N;

signed main() {
    cin >> N;
    vector<vector<int>> A(N);
    for (int i = 0; i < N; ++i) {
        int v;
        cin >> v;
        v--;
        A[i].push_back(v);
    }
    auto ans = cycle_detection(A);
    cout << ans.size() << endl;
    for (auto v: ans) cout << v + 1 << " ";
    cout << endl;
}  