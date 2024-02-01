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

int N, Q;

signed main() {
    cin >> N >> Q;
    vector<string> P(N);
    vector<vector<int> > C(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i) cin >> P[i];
    for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) C[i][j] = (P[i][j] == 'W' ? 0 : 1); 

    vector<vector<int> > S(N + 1, vector<int>(N + 1, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            S[i][j + 1] = S[i][j] + C[i][j];
        }
    }

    while (Q--) {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        int sum = 0;
        for (int y = A % N; ; ++y) {
            if (y % N == C % N) break;
            cout << "y: " << y << endl;
            cout << S[y][N] << endl;
            cout << S[y][B % N] << endl;
            cout << S[y][D % N + 1] << endl;
            sum += S[y][N] - S[y][B % N] + S[y][D % N + 1];
            if (D - B > N) {
                int l = D - B - (N - B % N + D % N);
                sum += (l / N) * S[y][N];
            }
        }
        if (C - A > N) {
            int l = C - A - (N - A % N + C % N);
            sum *= (l / N);
        } 
        cout << sum << endl;
    }
}                           