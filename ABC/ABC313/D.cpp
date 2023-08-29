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

int N, K;
vector<int> A;
vector<int> V;

signed main() {
    cin >> N >> K;
    A = vector<int>(N);
    V = vector<int>(K+1);
    int sum = 0;
    for (int i = 0; i < K+1; ++i) {
        cout << "? "; 
        for (int j = 0; j < K; ++j) {
            cout << (i+j)%(K+1) + 1 << " ";
        }
        cout << endl;
        cout.flush();

        cin >> V[i];
        if (V[i] == -1) {
            return 0;
        }
        sum ^= V[i];
    }
    for (int i = 0; i < K+1; ++i) {
        A[i] = sum^V[(i+1)%(K+1)];
    }
    sum = 0;
    for (int i = 0; i < K-1; ++i) sum ^= A[i];
    for (int i = K+1; i < N; ++i) {
        cout << "? "; 
        for (int j = 0; j < K-1; ++j) {
            cout << j + 1 << " ";
        }
        cout << i + 1 << endl;
        cout.flush();

        int v;
        cin >> v;
        A[i] = v^sum;
    }
    cout << "! ";
    for (auto a: A) cout << a << " ";
    cout << endl;
    cout.flush();
}