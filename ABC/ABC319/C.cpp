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

signed main() {
    vector<vector<int>> C(3, vector<int>(3));
    for (int i = 0; i < 3; ++i) for (int j = 0; j < 3; ++j) cin >> C[i][j];
    vector<int> P = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int cnt = 0;
    int all = 0;
    do {
        // 縦を確認
        bool ok = true;
        vector<vector<int>> tate(3), yoko(3), naname(2);
        for (int i = 0; i < P.size(); ++i) {
            int y = P[i] / 3, x = P[i] % 3;
            tate[x].push_back(C[y][x]);
            yoko[y].push_back(C[y][x]);
            if (x == y) naname[0].push_back(C[y][x]);
            if (x == 2 - y) naname[1].push_back(C[y][x]);
        }
        // 確認
        for (int i = 0; i < 3; ++i) {
            if (tate[i][0] == tate[i][1] && tate[i][0] != tate[i][2]) ok = false;
            if (yoko[i][0] == yoko[i][1] && yoko[i][0] != yoko[i][2]) ok = false;
        }
        if (naname[0][0] == naname[0][1] && naname[0][0] != naname[0][2]) ok = false;
        if (naname[1][0] == naname[1][1] && naname[1][0] != naname[1][2]) ok = false;
        if (ok) {
            cnt++;
        }
        all++;
    } while (next_permutation(P.begin(), P.end()));
    double p = (double) cnt / all;
    printf("%.20f", p);
}  