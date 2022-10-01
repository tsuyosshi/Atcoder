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

signed main(){
    int H1, W1;
    int H2, W2;
    cin >> H1 >> W1;
    vector<vector<int>> A(H1, vector<int>(W1));
    for (int i = 0; i < H1; ++i) {
        for (int j = 0; j < W1; ++j) {
            cin >> A[i][j];
        }
    }
    cin >> H2 >> W2;
    vector<vector<int>> B(H2, vector<int>(W2));
    for (int i = 0; i < H2; ++i) {
        for (int j = 0; j < W2; ++j) {
            cin >> B[i][j];
        }
    }

    for (int bi = 0; bi < (1 << H1); ++bi) {
        if (__builtin_popcount(bi) != H1 - H2) continue;
        for (int bj = 0; bj < (1 << W1); ++bj) {
            if (__builtin_popcount(bj) != W1 - W2) continue;
            vector<vector<int>> A_re;
            for (int row = 0; row < H1; ++row) {
                vector<int> R;
                for (int col = 0; col < W1; ++col) {
                    if ((bi & (1 << row)) || (bj & (1 << col))) continue;
                    R.push_back(A[row][col]);
                }
                if (R.size() > 0) A_re.push_back(R);
            }
            if (A_re.size() == 0) continue;
            if (A_re.size() != H2 || A_re[0].size() != W2) continue;
            bool ok = true;
            for (int row = 0; row < H2; ++row) {
                for (int col = 0; col < W2; ++col) {
                    if (A_re[row][col] != B[row][col]) {
                        ok = false;
                    }
                }
            }
            if (ok) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}