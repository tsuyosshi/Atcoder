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

int H_A, W_A, H_B, W_B, H_X, W_X;
vector<string> A, B, X;

void input(int &H, int &W, vector<string> &S) {
    cin >> H >> W;
    S.resize(H);
    for (int i = 0; i < H; ++i) cin >> S[i];
}

bool trimmable(vector<vector<int>> &S) {
    int cnt1 = 0;
    for (int i = 0; i < H_A; ++i) for (int j = 0; j < W_A; ++j) if (A[i][j] == '#') cnt1++;
    for (int i = 0; i < H_B; ++i) for (int j = 0; j < W_B; ++j) if (B[i][j] == '#') cnt1++;
    
    int cnt2 = 0;
    bool ok = true;
    for (int i = 0; i < H_X; ++i) {
        for (int j = 0; j < W_X; ++j) {
            char c = (S[i][j] > 0) ? '#' : '.';
            cnt2 += S[i][j];
            if (c != X[i][j]) ok = false;
        }
    }
    if (cnt1 != cnt2) ok = false;
    return ok;
}

vector<vector<int>> make_sheet(int y_A, int x_A, int y_B, int x_B) {
    vector<vector<int>> S(H_X, vector<int>(W_X, 0));
    int cnt1 = 0;
    // A を配置
    for (int i = 0; i < H_A; ++i) for (int j = 0; j < W_A; ++j) {
        int y = y_A + i, x = x_A + j;
        if (y >= 0 && y < H_X && x >= 0 && x < W_X && A[i][j] == '#') S[y][x]++;
    }
    // B を配置
    for (int i = 0; i < H_B; ++i) for (int j = 0; j < W_B; ++j) {
        int y = y_B + i, x = x_B + j;
        if (y >= 0 && y < H_X && x >= 0 && x < W_X && B[i][j] == '#') S[y][x]++;
    }
    return S;
}

bool check () {
    for (int y_A = -H_A; y_A < H_X; ++y_A) for (int x_A = -W_B; x_A < W_X; ++x_A) {
        for (int y_B = -H_B; y_B < H_X; ++y_B) for (int x_B = -W_B; x_B < W_X; ++x_B) {
            auto S = make_sheet(y_A, x_A, y_B, x_B);
            if (trimmable(S)) {
                return true;
            }
        }
    }
    return false;
}

signed main() {
    input(H_A, W_A, A);
    input(H_B, W_B, B);
    input(H_X, W_X, X);
    if (check()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}  