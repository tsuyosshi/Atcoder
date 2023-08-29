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

int row_deletable(int row, int w, vector<vector<int>> &row_num) {
    for (int a = 0; a < 26; ++a) {
        if (row_num[row][a] == w && row_num[row][a] >= 2) return a; 
    }
    return -1;
}

int col_deletable(int col, int h, vector<vector<int>> &col_num) {
    for (int a = 0; a < 26; ++a) {
        if (col_num[col][a] == h && col_num[col][a] >= 2) return a; 
    }
    return -1;
}

int H, W;
vector<string> C;
vector<vector<int>> row_num, col_num;
set<int> deleted_row, deleted_col;

signed main() {
    cin >> H >> W;
    row_num = vector<vector<int>>(H, vector<int>(26, 0));
    col_num = vector<vector<int>>(W, vector<int>(26, 0));
    for (int i = 0; i < H; ++i) {
        string s;
        cin >> s;
        C.push_back(s);
    }
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            row_num[i][C[i][j]-'a']++;
            col_num[j][C[i][j]-'a']++;
        }
    }
    int h = H, w = W;
    for (int i = 0; i < H + W; ++i) {
        vector<int> cols, rows;
        vector<int> c_row(26, 0), c_col(26, 0);
        int cnt_h = 0, cnt_w = 0;
        for (int row = 0; row < H; ++row) {
            if (deleted_row.find(row) != end(deleted_row)) continue;
            int a = row_deletable(row, w, row_num);
            if (a != -1) {
                cnt_h++;
                c_row[a]++;
                rows.push_back(row);
            }
        }
        for (int col = 0; col < W; ++col) {
            if (deleted_col.find(col) != end(deleted_col)) continue;
            int a = col_deletable(col, h, col_num);
            if (a != -1) {
                cnt_w++;
                c_col[a]++;
                cols.push_back(col);
            }
        }
        for (int col = 0; col < W; ++col) {
            if (deleted_col.find(col) != end(deleted_col)) continue;
            for (int a = 0; a < 26; ++a) {
                col_num[col][a] -= c_row[a];
            }
        }
        for (int row = 0; row < H; ++row) {
            if (deleted_row.find(row) != end(deleted_row)) continue;
            for (int a = 0; a < 26; ++a) {
                row_num[row][a] -= c_col[a];
            }
        }
        for (auto row: rows) deleted_row.insert(row);
        for (auto col: cols) deleted_col.insert(col);
        h -= cnt_h;
        w -= cnt_w;
    }
    int ans = 0; 
    for (int col = 0; col < W; ++col) {
        for (int a = 0; a < 26; ++a) {
            if (deleted_col.find(col) != end(deleted_col)) continue;
            ans += col_num[col][a];
        }
    }
    cout << ans << endl;
}   