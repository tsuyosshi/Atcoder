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

int H, W;

signed main() {
    cin >> H >> W;
    vector<string> S(H);
    for (int i = 0; i < H; ++i) cin >> S[i];
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            if (S[y][x] == '.') {
                int cnt = 0;
                for (int i = 0; i < 4; ++i) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
                    if (S[ny][nx] == '#') cnt++;
                }
                if (cnt > 1) {
                    cout << y + 1 << " " << x + 1 << endl;
                    return 0;
                }
            } 
        }
    }
}  