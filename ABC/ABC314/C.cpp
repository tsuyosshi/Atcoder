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
    int N, M;
    string S;
    cin >> N >> M;
    cin >> S;
    vector<int> C(N);
    vector<string> X(M);
    vector<vector<int>> Y(M);
    for (int i = 0; i < N; ++i) {
        cin >> C[i];
        C[i]--;
        X[C[i]].push_back(S[i]);
        Y[C[i]].push_back(i);
    }
    string ans = S;
    for (int i = 0; i < M; ++i) {
        int K = X[i].size();
        string s1 = X[i], s2 = X[i];
        for (int j = 0; j < K; ++j) s1[j] = s2[(j-1+K)%K];
        for (int j = 0; j < K; ++j) ans[Y[i][j]] = s1[j];
    }
    cout << ans << endl;
}  