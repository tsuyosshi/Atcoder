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

int modPow(int a,int n) {
    if(n==0)return 1;
    if(n==1)return a%mod;
    if (n%2==1)return(a*modPow(a,n-1))%mod;
    int t=modPow(a,n/2);
    return (t*t)%mod;
}

int N;

signed main(){
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 1; i <= N - 1; ++i) {
        cin >> A[i];
        B[i] = modPow(A[i], mod - 2);
    }
    vector<int> dp1(N + 1, 0);
    vector<int> dp2(N + 1, 0);
    vector<int> P(N + 1, 0);
    vector<int> S(N + 1, 0);
    dp1[1] = 1;
    P[1] = 1;
    dp2[1] = 0;
    S[1] = (dp2[1] + B[1] + 1) * dp1[1] % mod;
    for (int i = 2; i <= N; ++i) {
        dp1[i] = P[i - 1];
        dp1[i] %= mod;
        P[i] = P[i - 1] + dp1[i] * B[i];
        P[i] %= mod;
        dp2[i] += S[i - 1];
        dp2[i] %= mod;
        S[i] = S[i - 1] + (dp2[i] + B[i] + 1) * dp1[i];
        S[i] %= mod;
    }
    cout << dp2[N] << endl;
}