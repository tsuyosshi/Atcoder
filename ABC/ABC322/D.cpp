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

int N = 3, D = 4;
vector<vector<string>> P(N, vector<string>(D));

int cnt_all = 0;
bool ok = false;

void dfs(int n, vector<string> grid) {
    if (n == N) {
        vector<string> Y(D, "####");
        int cnt = 0;
        for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) if (grid[i][j] == '#') cnt++;
        if (same(D, grid, Y) && cnt == cnt_all) {
            ok= true;
        }
    } else {
        for (int y = -D; y < D; ++y) {
            for (int x =-D; x < D; ++x) {
                auto poly = P[n];
                for (int i = 0; i < 4; ++i) {
                    if (fillable(D, x, y, grid, poly)) {
                        auto tmp = fill_grid(D, x, y, grid, poly);
                        dfs(n+1, tmp);
                    }
                    poly = rot90(D, poly);
                }
            }
        }
    }
} 

signed main() {
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 4; ++j) cin >> P[i][j];
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 4; ++j) for (int k = 0; k < 4; ++k) if (P[i][j][k] == '#') cnt_all++;
    vector<string> tmp = vector<string>(4, "....");
    dfs(0, tmp);
    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}  