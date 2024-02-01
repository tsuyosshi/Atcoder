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

int modPow(int a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a % mod;
    if (n % 2 == 1) return (a * modPow(a, n - 1)) % mod;
    int t = modPow(a, n / 2);
    return (t * t) % mod;
}

int N;
vector<int> A;

signed main() {
    cin >> N;
    A.resize(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    int p = modPow(N, mod - 2);
    vector<int> dp(N + 1,  0);
    for (int i = 0; i < N; ++i) {
        dp[1] += A[i] * p;
        dp[1] %= mod;
    }
    for (int i = 2; i <= N; ++i) {
        dp[i] += dp[i - 1];
        int sum = 0;
        for (int y = 0; y < N; ++y) for (int x = 0; x < y; ++x) sum = (sum + A[x]) % mod;
        for (int j = 0; j < 2; ++j) sum = (sum * p) % mod;
        dp[i] += sum;
        dp[i] %= mod;
        cout << dp[i] << endl;
    }
    cout << dp[N] << endl;
}                           