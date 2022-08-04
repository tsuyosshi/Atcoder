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

const int mod = 998244353;
int N;

signed main(){
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    int ans = 0;
    for (int n = 1; n <= N; ++n) {
        // n個選んだ時の通り数を計算
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>>(n + 2, vector<int>(n, 0)));
        dp[0][0][0] = 1;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j <= n; ++j) {
                for (int k = 0; k < n; ++k) {
                    // A[i]を選ぶ
                    dp[i + 1][j + 1][(k + A[i])%n] += dp[i][j][k];
                    dp[i + 1][j + 1][(k + A[i])%n] %= mod;
                    // A[i]をスルー
                    dp[i + 1][j][k] += dp[i][j][k];
                    dp[i + 1][j][k] %= mod;
                }
            }
        }
        ans += dp[N][n][0];
        ans %= mod;
    }
    cout << ans << endl;
}