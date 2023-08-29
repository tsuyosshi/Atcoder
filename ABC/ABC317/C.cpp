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

signed main() {
    cin >> N >> M;
    vector<vector<int>> E(N, vector<int>(N, -1));
    vector<int> P;
    for (int i = 0; i < N; ++i) P.push_back(i);
    for (int i = 0; i < M; ++i) {
        int a, b ,c;
        cin >> a >> b >> c;
        a--, b--;
        E[a][b] = c;
        E[b][a] = c;
    }
    int ans = -INF;
    do {
        bool is_valid = true;
        int dist = 0;
        for (int i = 0; i < N-1; ++i) {
            int u, v;
            u = P[i];
            v = P[i+1];
            if (E[u][v] == -1) break;
            dist += E[u][v];
        }
        chmax(ans, dist);
    } while (next_permutation(P.begin(), P.end()));
    cout << ans << endl;
}  