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

int N, M;
vector<int> X;

signed main() {
    cin >> N >> M;
    X.resize(M);
    for (int i = 0; i < M; ++i) {
        cin >> X[i];
        X[i]--;
    }
    vector<int> V(N + 1, 0);
    for (int j = 0; j < M - 1; ++j) {
        if (X[j] <= X[j + 1]) {
            int d1 = X[j] -  X[j + 1] + N;
            V[X[j]] += d1;
            V[X[j + 1]] -= d1;

            int d2 = X[j + 1] - X[j];
            V[X[j + 1]] += d2;
            V[0] += d2;
            V[X[j]] -= d2;
        } else {
            int d1 = X[j] - X[j + 1];
            V[X[j]] += d1;
            V[0] += d1;
            V[X[j + 1]] -= d1;

            int d2 = X[j + 1] - X[j] + N;
            V[X[j + 1]] += d2;
            V[X[j]] -= d2;
        }
    }
    int ans = INF;
    for (int i = 0; i < N; ++i) {
        chmin(ans, V[i]);
        V[i + 1] += V[i];
    }
    cout << ans << endl;
}                       