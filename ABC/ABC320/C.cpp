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

int M;
vector<string> S(3);

signed main() {
    cin >> M;
    for (int i = 0; i < 3; ++i) cin >> S[i];
    int ans = INF;
    vector<int> P = {0, 1, 2};
    do {
        string S1 = S[P[0]], S2 = S[P[1]], S3 = S[P[2]]; 
        for (int i = 0; i <= 100; ++i) {
            for (int j = 1; j <= 100; ++j) {
                for (int k = 1; k <= 100; ++k) {
                    char c1 = S1[i%M], c2 = S2[(i+j)%M], c3 = S3[(i+j+k)%M];
                    if (c1 == c2 && c1 == c3) {
                        chmin(ans, i+j+k);
                    }
                }
            }
        }
    } while (next_permutation(P.begin(), P.end()));
    if (ans != INF) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
}  