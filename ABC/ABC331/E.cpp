#include<iostream>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;

#define int long long
#define ALL(x) (x).begin(),(x).end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))

typedef pair<int, int> PI;
typedef pair<int, pair<int, int> > PII;
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

int N, M, L;

signed main() {
    cin >> N >> M >> L;
    vector<int> A(N), B(M), C(L), D(L);
    vector<PI> X, Y;
    vector<vector<int> > I(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        X.emplace_back(A[i], i);
    }
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
        Y.emplace_back(B[i], i);
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    for (int i = 0; i < L; ++i) {
        int c, d;
        cin >> c >> d;
        c--, d--;
        C[i] = lower_bound(X.begin(), X.end(), PI(A[c], c)) - X.begin();
        D[i] = lower_bound(Y.begin(), Y.end(), PI(B[d], d)) - Y.begin();
        // cout << I.size() << endl;
        // cout << C[i] << " " << D[i] << endl;
        I[C[i]].push_back(D[i]);
    }
    for (int i = 0; i < N; ++i) sort(I[i].begin(), I[i].end());
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (I[i].size() == 0) {
            chmax(ans, X[i].first + Y[M - 1].first);
        } else {
            for (int j = 0; j < I[i].size(); ++j) {
                if (j == 0 && I[i][j] != 0) {
                    int id = I[i][j] - 1;
                    chmax(ans, X[i].first + Y[id].first);
                }
                if (j != 0 && I[i][j - 1] != I[i][j] - 1) {
                    int id = I[i][j] - 1;
                    chmax(ans, X[i].first + Y[id].first);
                }
                if (j == I[i].size() - 1 && I[i][j] != M - 1) {
                    chmax(ans, X[i].first + Y[M - 1].first);
                }
                if (j != I[i].size() - 1 && I[i][j + 1] != I[i][j] + 1) {
                    int id = I[i][j] + 1;
                    chmax(ans, X[i].first + Y[id].first);
                }
            }
        }
    }
    cout << ans << endl;
}                           