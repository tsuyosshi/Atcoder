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

int H, W;
vector<string> S;

void bfs(int sy, int sx, vector<vector<bool>> &visited){
    queue<PI> que;
    que.push(PI(sy, sx));
    visited[sy][sx] = true;
    while (que.size() > 0) {
        auto v = que.front();
        que.pop();
        for (int i = 0; i < 8; ++i) {
            int ny = v.first + ddy[i], nx = v.second + ddx[i];
            if (ny < 0 || ny >= H || nx < 0 || nx >= W || S[ny][nx] == '.' || visited[ny][nx]) continue;
            que.push(PI(ny, nx));
            visited[ny][nx] = true;
        }  
    }
}

signed main() {
    cin >> H >> W;
    S.resize(H);
    for (int i = 0; i < H; ++i) cin >> S[i];
    int ans = 0;
    vector<vector<bool>> visited(H, vector<bool>(W, false));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (visited[i][j] || S[i][j] == '.') continue;
            // cout << i << " " << j << endl;
            bfs(i, j, visited);
            ans++;
        }
    }
    cout << ans << endl;
}                           