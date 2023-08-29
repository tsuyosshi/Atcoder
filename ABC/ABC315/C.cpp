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
vector<int> F, S;
vector<vector<int>> X;
vector<PI> Y;

signed main() {
    cin >> N;
    F = vector<int>(N);
    S = vector<int>(N);
    X = vector<vector<int>>(N);
    Y = vector<PI>(N, PI(-INF, -INF));
    for (int i = 0; i < N; ++i) {
        cin >> F[i] >> S[i];
        F[i]--;
        X[F[i]].push_back(S[i]);
        chmax(Y[F[i]], PI(S[i], F[i]));
    }
    for (int i = 0; i < N; ++i) sort(X[i].begin(), X[i].end());
    sort(Y.begin(), Y.end());
    PI ma1 , ma2;
    ma1 = Y[Y.size()-1];
    ma2 = Y[Y.size()-2];
    int ans = -INF;
    for (int i = 0; i < N; ++i) {
        int n = X[i].size();
        if (n > 1) {
            chmax(ans, X[i][n - 1] + X[i][n - 2]/2);
        }
        if (n > 0) {
            if (i != ma1.second) {
                chmax(ans, X[i][n - 1] + ma1.first);
            }
            else if (i != ma2.second) {
                chmax(ans, X[i][n - 1] + ma2.first);
            }
        }
    }
    cout << ans << endl;
}   