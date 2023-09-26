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
vector<int> X, Y;

signed main() {
    cin >> N;
    X.resize(N);
    Y.resize(N);
    for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];
    vector<vector<int>> dp(N+1, vector<int>(2, 0));
    if (X[0] == 0) {
        chmax(dp[0][0], Y[0]);
    } else {
        chmax(dp[0][1], Y[0]);
    }
    for (int i = 0; i < N-1; ++i) {
        for (int j = 0; j < 2; ++j) {
            chmax(dp[i+1][j], dp[i][j]);
            if (X[i+1] == 0) {
                chmax(dp[i+1][0], dp[i][j]+Y[i+1]);
            } else {
                if (j == 0) chmax(dp[i+1][1], dp[i][j]+Y[i+1]);
            }
        }
    }
    int ans = max(dp[N-1][0], dp[N-1][1]);
    cout << ans << endl;
}  