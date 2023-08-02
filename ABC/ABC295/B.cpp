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

int R, C;
vector<string> field;

signed main(){
    cin >> R >> C;
    for (int i = 0; i < R; ++i) {
        string row;
        cin >> row;
        field.push_back(row);
    }
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (field[i][j] == '#' || field[i][j] == '.') continue;
            for (int k = 0; k < R; ++k) {
                for (int l = 0; l < C; ++l) {
                    if (abs(i - k) + abs(j -l) <= field[i][j] - '0' && field[k][l] == '#') {
                        field[k][l] = '.';
                    }
                }
            }
            field[i][j] = '.';
        }
    }
    for (int i = 0; i < R; ++i) {
        cout << field[i] << endl;
    }
}