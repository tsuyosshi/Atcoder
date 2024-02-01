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
int K;

signed main() {
    cin >> H >> W >> K;
    vector<string> S;
    string dummy = "";
    for (int i = 0; i < W + 2; ++i) dummy.push_back('x');
    S.push_back(dummy);
    for (int i = 0; i < H; ++i) {
        string s;
        cin >> s;
        s = "x" + s + "x";
        S.push_back(s); 
    }
    S.push_back(dummy);
    H += 2, W += 2;
    vector<vector<int>> row_x(H, vector<int>(W, 0)), col_x(W, vector<int>(H, 0));
    vector<vector<int>> row_dot(H, vector<int>(W, 0)), col_dot(W, vector<int>(H, 0));
    for (int i = 0; i < H; ++i) for (int j = 0; j < W; ++j) {
        int x = (S[i][j] == 'x') ? 1 : 0;
        int dot = (S[i][j] == '.') ? 1 : 0;
        if (j == 0) {
            row_x[i][j] = x;
            row_dot[i][j] = dot;
        } else {
            row_x[i][j] = row_x[i][j - 1] + x;
            row_dot[i][j] = row_dot[i][j - 1] + dot;
        }
    }
    for (int j = 0; j < W; ++j) for (int i = 0; i < H; ++i) {
        int x = (S[i][j] == 'x') ? 1 : 0;
        int dot = (S[i][j] == '.') ? 1 : 0;
        if (i == 0) {
            col_x[j][i] = x;
            col_dot[j][i] = dot;
        } else {
            col_x[j][i] = col_x[j][i - 1] + x;
            col_dot[j][i] = col_dot[j][i - 1] + dot;
        }
    }

    int ans = INF;
    for (int i = 1; i < H - 1; ++i) {
        for (int j = 1; j < W - 1; ++j) {
            if (S[i][j] == 'x') continue;
            if (j + K - 1 < W - 1) {
                int num_x = row_x[i][j + K - 1] - row_x[i][j - 1];
                if (num_x == 0) {
                    int num_dot = row_dot[i][j + K - 1] - row_dot[i][j - 1];
                    chmin(ans, num_dot);
                }
            }
            if (i + K - 1 < H - 1) {
                int num_x = col_x[j][i + K - 1] - col_x[j][i - 1];
                if (num_x == 0) {
                    int num_dot = col_dot[j][i + K - 1] - col_dot[j][i - 1];
                    chmin(ans, num_dot);
                }
            }
        }
    }

    if (ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}                       