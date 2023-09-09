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

int N;

signed main() {
    cin >> N;
    vector<vector<int>> D(N, vector<int>(N));
    for (int i = 0; i < N-1; ++i) {
        for (int j = i+1; j < N; ++j) {
            cin >> D[i][j];
        }
    }
    int ans = 0;
    vector<int> dp(20000005, 0);
    for (int i = 0; i < (1<<N); ++i) {
        for (int u = 0; u < N-1; ++u) {
            for (int v = u+1; v < N; ++v) {
                if ((i&(1<<u)) || (i&(1<<v))) continue;
                chmax(dp[i+(1<<u)+(1<<v)], dp[i]+D[u][v]);
            }
        }
    }
    for (int i = 0; i < (1<<N); ++i) chmax(ans, dp[i]);
    cout << ans << endl;
}  