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

/* 右側の最も近いオブジェクトの列を取得 */
int get_right_obj(int row, int col, vector<vector<int>> &obj_row) {
    auto itr = upper_bound(obj_row[row].begin(), obj_row[row].end(), col);
    if (itr == end(obj_row[row])) return -1;
    return *itr;
}

/* 左側の最も近いオブジェクトの列を取得 */
int get_left_obj(int row, int col, vector<vector<int>> &obj_row) {
    auto itr = lower_bound(obj_row[row].begin(), obj_row[row].end(), col);
    if (itr == begin(obj_row[row])) return -1;
    itr--;
    if (*itr >= col) return -1;
    return *itr;
}

/* 下側の最も近いオブジェクトの行を取得 */
int get_bottom_obj(int row, int col, vector<vector<int>> &obj_col) {
    auto itr = upper_bound(obj_col[col].begin(), obj_col[col].end(), row);
    if (itr == end(obj_col[col])) return -1;
    return *itr;
}

/* 上側の最も近いオブジェクトの行を取得 */
int get_top_obj(int row, int col, vector<vector<int>> &obj_col) {
    auto itr = lower_bound(obj_col[col].begin(), obj_col[col].end(), row);
    if (itr == begin(obj_col[col])) return -1;
    itr--;
    if (*itr >= row) return -1;
    return *itr;
}

/* オブジェクトの判定 */
bool is_obj(int row, int col, vector<string> &F) {

}

/* (row, col) に侵入できるかどうかを判定 */
bool is_valid_move(int row, int col, vector<string> &F, vector<vector<int>> &obj_row, vector<vector<int>> &obj_col) {

}

/*
https://atcoder.jp/contests/abc317/tasks/abc317_e
を参考
*/

signed main() {

}  