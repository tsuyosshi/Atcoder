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

int N, D, P;

signed main() {
    cin >> N >> D >> P;
    vector<int> F(N);
    for (int i = 0; i < N; ++i) cin >> F[i];
    sort(F.begin(), F.end());
    vector<int> S(N+5, 0);
    for (int i = 1; i <= N; ++i) S[i] = S[i-1] + F[i-1];
    int ans = INF;
    for (int i = 0; i <= 2*N; ++i) {
        // D * i 枚パスを買う
        if (D * i >= N) {
            chmin(ans, P*i);
        } else {
            chmin(ans, P*i+S[N-D*i]);
        }
    }
    chmin(ans, S[N]);
    cout << ans << endl;
}