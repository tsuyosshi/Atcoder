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
string T;
vector<string> S;

signed main() {
    cin >> N >> T;
    int M = T.size();
    S.resize(N);
    for (int i = 0; i < N; ++i) cin >> S[i];
    vector<int> pfx(M + 1, 0), sfx(M + 1, 0);
    vector<int> C(M + 2, 0);
    for (int i = 0; i < N; ++i) {
        int k = 0;
        for (int j = 0; j < S[i].size(); ++j) if (k < T.size() && S[i][j] == T[k]) k++;
        pfx[k]++;
    }
    for (int i = 0; i < N; ++i) {
        int k = 0;
        for (int j = S[i].size() - 1; j >= 0; --j) if (k < T.size() && S[i][j] == T[M - k - 1]) k++;       
        sfx[k]++;
    }
    for (int i = 1; i <= M + 1; ++i) C[i] = C[i - 1] + sfx[i - 1];
    int ans = 0;
    for (int i = 0; i <= M; ++i) {
        ans += pfx[i] * (C[M + 1] - C[M - i]);
    }
    cout << ans << endl;
}                           