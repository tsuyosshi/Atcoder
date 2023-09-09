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

int N, T, M;
vector<vector<int>> A;

bool valid_team(int a, int t, vector<vector<int>> &A, vector<vector<int>> &X) {
    bool ok = true;
    for (int i = 0; i < X[t].size(); ++i) {
        int x = X[t][i];
        if (A[a][x] == 1) {
            return false;
        }
    }
    return true;
} 

void dfs(int n, int t, int &res, vector<vector<int>> &A, vector<vector<int>> &X) {
    if (n == N) {
        bool ok = true;
        for (int i = 0; i < T; ++i) if (X[i].size() == 0) ok = false;
        if (ok) res++;
        return;
    }

    // いままでのチームのいずれかに入れる
    for (int i = 0; i < t; ++i) {
        if (!valid_team(n, i, A, X)) continue;
        X[i].push_back(n);
        dfs(n+1, t, res, A, X);
        X[i].pop_back();
    }

    // 新しいチームに入れる
    if (t < T && valid_team(n, t, A, X)) {
        X[t].push_back(n);
        dfs(n+1, t+1, res, A, X);
        X[t].pop_back();
    }
}

signed main() {
    cin >> N >> T >> M;
    vector<vector<int>> A(N, vector<int>(N, 0));
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        A[a][b] = A[b][a] = 1;
    }
    vector<vector<int>> X(T);
    int res = 0;
    dfs(0, 0, res, A, X);
    cout << res << endl;
}  