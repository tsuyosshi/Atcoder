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

int get_right_obj(int row, int col, vector<vector<int>> &obj_row) {
    auto itr = upper_bound(obj_row[row].begin(), obj_row[row].end(), col);
    if (itr == end(obj_row[row])) return -1;
    return *itr;
}

int get_left_obj(int row, int col, vector<vector<int>> &obj_row) {
    auto itr = lower_bound(obj_row[row].begin(), obj_row[row].end(), col);
    if (itr == begin(obj_row[row])) return -1;
    itr--;
    if (*itr >= col) return -1;
    return *itr;
}

int get_bottom_obj(int row, int col, vector<vector<int>> &obj_col) {
    auto itr = upper_bound(obj_col[col].begin(), obj_col[col].end(), row);
    if (itr == end(obj_col[col])) return -1;
    return *itr;
}

int get_top_obj(int row, int col, vector<vector<int>> &obj_col) {
    auto itr = lower_bound(obj_col[col].begin(), obj_col[col].end(), row);
    if (itr == begin(obj_col[col])) return -1;
    itr--;
    if (*itr >= row) return -1;
    return *itr;
}

bool is_obj(int row, int col, vector<string> &F) {
    return (F[row][col] != '.' && F[row][col] != 'S' && F[row][col] != 'G');
}

bool is_valid_move(int row, int col, vector<string> &F, vector<vector<int>> &obj_row, vector<vector<int>> &obj_col) {
    if (is_obj(row, col, F)) return false;
    int col_right = get_right_obj(row, col, obj_row);
    int col_left = get_left_obj(row, col, obj_row);
    int row_top = get_top_obj(row, col, obj_col);
    int row_bottom = get_bottom_obj(row, col, obj_col);
    if (col_right != -1 && F[row][col_right] == '<') return false;
    if (col_left != -1 && F[row][col_left] == '>') return false;
    if (row_top != -1 && F[row_top][col] == 'v') return false;
    if (row_bottom != -1 && F[row_bottom][col] == '^') return false;
    return true;
}

int bfs(PI s, PI t, vector<string> &F, vector<vector<int>> &obj_row, vector<vector<int>> &obj_col) {
    vector<vector<int>> dist(H, vector<int>(W, INF));
    queue<PI> que;
    que.push(s);
    dist[s.first][s.second] = 0;
    while (que.size() > 0) {
        auto v = que.front();
        que.pop();
        int row = v.first, col = v.second;
        if (PI(row, col) == t) break;
        for (int i = 0; i < 4; ++i) {
            int nrow = row + dy[i], ncol = col + dx[i];
            if (nrow < 0 || nrow >= H || ncol < 0 || ncol >= W) continue;
            if (!is_valid_move(nrow, ncol, F, obj_row, obj_col)) continue;
            if (dist[nrow][ncol] == INF) {
                que.push(PI(nrow, ncol));
                dist[nrow][ncol] = dist[row][col] + 1;
            }
        }
    }
    return dist[t.first][t.second];
}

signed main() {
    cin >> H >> W;
    vector<string> F(H);
    vector<vector<int>> obj_row(H), obj_col(W);
    PI s, t;
    for (int i = 0; i < H; ++i) cin >> F[i];
    for (int row = 0; row < H; ++row) for (int col = 0; col < W; ++col) {
        if (is_obj(row, col, F)) obj_row[row].push_back(col), obj_col[col].push_back(row);
        if (F[row][col] == 'S') s = PI(row, col);
        if (F[row][col] == 'G') t = PI(row, col);
    }
    for (int row = 0; row < H; ++row) sort(obj_row[row].begin(), obj_row[row].end());
    for (int col = 0; col < W; ++col) sort(obj_col[col].begin(), obj_col[col].end());
    int ans = bfs(s, t, F, obj_row, obj_col);
    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

}  