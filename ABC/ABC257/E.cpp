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
int C[10];

signed main() {
    cin >> N;
    int min_c = INF;
    int min_idx;
    for (int i = 1; i <= 9; ++i) {
        cin >> C[i];
        if (min_c > C[i]) {
            min_c = C[i];
            min_idx = i; 
        }
    }
    int digit_num = N / min_c;
    int sum = digit_num * min_c;
    string ans = "";
    for (int i = 0; i < digit_num; ++i) ans += to_string(min_idx);
    for (int i = 0; i < digit_num; ++i) {
        for (int j = 9; j >= 1; --j) {
            if (sum - min_c + C[j] <= N) {
                ans[i] = j + '0';
                sum = sum - min_c + C[j];
                break;
            }
        }
    }
    cout << ans << endl;
}