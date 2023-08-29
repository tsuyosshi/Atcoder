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
    vector<int> X(N), Y(N), Z(N);
    vector<int> V(N), W(N);
    int S = 0, T = 0;
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i] >> Z[i];
        V[i] = (Y[i] > X[i]) ? Z[i] : -INF;
        W[i] = (Y[i] > X[i]) ? (Y[i]-X[i])/2+1 : INF;
        S += Z[i];
        if (X[i] > Y[i]) T += Z[i];
    }
    vector<vector<int>> dp(N+1, vector<int>(S+5, INF));
    dp[0][T] = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < S; ++j) {
            if (j + V[i] <= S && j + V[i] >= 0) chmin(dp[i+1][j+V[i]], dp[i][j]+W[i]);
            chmin(dp[i+1][j], dp[i][j]);
        }
    }
    int ans = INF;
    for (int j = S/2+1; j <= S; ++j) chmin(ans, dp[N][j]);
    cout << ans << endl;
}  