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

int N;

signed main() {
    cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; ++i) cin >> S[i];
    vector<vector<int>> row_o(N), col_o(N);
    for (int row = 0; row < N; ++row) for (int col = 0; col < N; ++col) if (S[row][col] == 'o') row_o[row].push_back(col);
    for (int col = 0; col < N; ++col) for (int row = 0; row < N; ++row) if (S[row][col] == 'o') col_o[col].push_back(row);

    int ans = 0;
    for (int row = 0; row < N; ++row) {
        if (row_o[row].size() < 2) continue;
        for (int i = 0; i < row_o[row].size(); ++i) {
            int col = row_o[row][i];
            auto itr = upper_bound(col_o[col].begin(), col_o[col].end(), row);
            if (itr != end(col_o[col])) {
                int k = itr - col_o[col].begin();
                ans += i * (col_o[col].size() - k);
                ans += (row_o[row].size() - i - 1) * (col_o[col].size() - k);
            }
            itr = lower_bound(col_o[col].begin(), col_o[col].end(), row);
            if (itr != begin(col_o[col])) {
                itr--;
                int k = itr - col_o[col].begin();
                ans += i * (k + 1);
                ans += (row_o[row].size() - i - 1) * (k + 1);
            }
        }
    }
    cout << ans << endl;
}                           