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

void puts_yn(bool flag) { if (flag) { puts("Yes"); } else { puts("No"); }  }

int D;
int ans = INF;

signed main() {
    cin >> D;
    for (int x = 0; x <= 2000000; ++x) {
        int remain = x*x - D;
        if (remain < 0) {
            for (int i = -10; i <= 10; ++i) {
                int y0 = floor(sqrt(-remain));
                int y = y0 + i;
                if (y < 0) continue;
                int z = remain + y*y;
                chmin(ans, abs(z));
            }
        } else {
            chmin(ans, remain+1);
        }
    }
    cout << ans << endl;
}                           