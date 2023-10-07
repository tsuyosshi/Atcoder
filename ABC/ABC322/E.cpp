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

int N, K, P;

signed main() {
    cin >> N >> K >> P;
    vector<vector<int>> A(N, vector<int>(K));
    vector<int> C(N);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
        for (int j = 0; j < K; ++j) {
            cin >> A[i][j];
        }
    }
    vector<map<vector<int>, int>> dp(N+1);
    dp[0][vector<int>(K, 0)] = 0;
    for (int i = 0; i < N; ++i) {
        for (auto [key, val]: dp[i]) {
            auto nkey = key;
            for (int j = 0; j < K; ++j) nkey[j] = min(P, nkey[j]+A[i][j]);
            if (dp[i+1].find(key) == end(dp[i+1])) {
                dp[i+1][key] = dp[i][key];
            } else {
                chmin(dp[i+1][key], dp[i][key]);
            }
            if (dp[i+1].find(nkey) == end(dp[i+1])) {
                dp[i+1][nkey] = dp[i][key]+C[i];
            } else {
                chmin(dp[i+1][nkey], dp[i][key]+C[i]);
            }
        }
    }
    if (dp[N].find(vector<int>(K, P)) != end(dp[N])) {
        cout << dp[N][vector<int>(K, P)] << endl;
    } else {
        cout << -1 << endl;
    }
}