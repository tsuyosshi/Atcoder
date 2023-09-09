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

int N, M;

void dfs(int v, int remain, int &res, vector<vector<int>> &T, vector<int> &insurance) {
    if (remain != 0 || insurance[v] != 0) res++;
    for (auto u: T[v]) {
        dfs(u, max(remain-1, insurance[v]), res, T, insurance);
    }
}

signed main() {
    cin >> N >> M;
    vector<vector<int>> T(N);
    for (int i = 1; i < N; ++i) {
        int p;
        cin >> p;
        p--;
        T[p].push_back(i);
    }
    vector<int> insurance(N, 0);
    for (int i = 0; i < M; ++i) {
        int x, y;
        cin >> x >> y;
        x--;
        chmax(insurance[x], y);
    }
    int res = 0;
    dfs(0, 0, res, T, insurance);
    cout << res << endl;
}  