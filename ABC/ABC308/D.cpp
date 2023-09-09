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
map<char, int> mp = {{'s', 0}, {'n', 1}, {'u', 2}, {'k', 3}, {'e', 4}};

bool bfs(int sx, int sy, vector<string> &field){
    queue<PI> que;
    vector<vector<int>> dist(H, vector<int>(W, INF));
    if (mp.find(field[sy][sx]) != end(mp)) que.emplace(sx, sy), dist[sy][sx] = 0;
    while (que.size() > 0) {
        auto v = que.front();
        que.pop();
        int x = v.first, y = v.second;
        char c = field[y][x];
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= W || ny < 0 || ny >= H || dist[ny][nx] != INF) continue;
            char nc = field[ny][nx];
            if (mp.find(nc) != end(mp) && mp[nc] == (mp[c]+1)%5) {
                que.emplace(nx, ny);
                dist[ny][nx] = dist[y][x] + 1;
            }
        }
    }
    if (dist[H-1][W-1] != INF) {
        return true;
    } else {
        return false;
    }
}

signed main() {
    cin >> H >> W;
    vector<string> field(H);
    for (int i = 0; i < H; ++i) cin >> field[i];
    if (bfs(0, 0, field)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}  