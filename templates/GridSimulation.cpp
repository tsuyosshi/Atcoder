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

vector<string> rot90(int n, vector<string> &P) {
    auto res = P;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res[i][j] = P[j][n-i-1];
        }
    }
    return res;
}

vector<string> fill_grid(int n, int x, int y, vector<string> &grid, vector<string> &P) {
    auto res = grid;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (y + i >= 0 && y + i < n && x + j >= 0 && x + j < n) {
                if (P[i][j] == '#') res[y+i][x+j] = P[i][j];
            }
        }
    }
    return res;
}

bool in(int n, int x, int y) {
    return (y >= 0 && y < n && x >= 0 && x < n);
}

bool fillable(int n, int x, int y, vector<string> &grid, vector<string> &P) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (in(n, x+j, y+i) && grid[y+i][x+j] == '#' && P[i][j] == '#') {
               return false;
            } else if (!in(n, x+j, y+i) && P[i][j] == '#') { 
                return false;
            }
        }
    }
    return true;
}

bool same(int n, vector<string> &X, vector<string> &Y) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (X[i][j] != Y[i][j]) return false;
        }
    }
    return true;
}

// https://atcoder.jp/contests/abc322/submissions/46131711 参照

signed main() {
}  