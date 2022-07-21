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

int N, Q, X;

signed main(){
    cin >> N >> Q >> X;
    vector<int> W(N);
    for (int i = 0; i < N; ++i) cin >> W[i];
    vector<int> sum(N, 0);
    sum[0] = W[0];
    for (int i = 1; i < N; ++i) sum[i] = sum[i - 1] + W[i]; 
    vector<int> K;
    vector<int> C(N, -1);
    int t = 0;
    int T;
    while (true) {
        C[t] = K.size();
        int pre_sum = (t == 0) ? 0 : sum[t - 1];
        int idx1 = lower_bound(sum.begin() + t, sum.end(), X + pre_sum) - sum.begin();
        if (idx1 == N) {
            int remain = X - (sum[N - 1] - pre_sum);
            int p = remain / sum[N - 1];
            remain -= p * sum[N - 1];
            if (remain == 0) {
                K.push_back(N - t + p * N);
                t = 0;
            }
            else {
                int idx2 = lower_bound(sum.begin(), sum.end(), remain) - sum.begin();
                K.push_back(N - t + p * N + idx2 + 1);
                t = (idx2 + 1) % N;
            }
        }
        else {
            K.push_back(idx1 - t + 1);
            t = (idx1 + 1) % N;
        }
        if (C[t] != -1) {
            T = C[t];
            break;
        }
    }
    while(Q--) {
        int ki;
        cin >> ki;
        ki--;
        if (ki < K.size()) {
            cout << K[ki] << endl;
        }
        else {
            ki -= T;
            cout << K[T + ki % (K.size() - T)] << endl;
        }
    }
}