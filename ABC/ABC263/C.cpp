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

int N, M;
vector<vector<int>> seqs;

bool comp(vector<int> &A, vector<int> &B) {
    for (int i = 0; i < A.size(); ++i) {
        if (A[i] < B[i]) return true;
        if (A[i] > B[i]) return false;
    }
    return false;
}

void make_sequences(int n, int m, vector<int> &p) {
    if (n == N) {
        seqs.push_back(p);
        return ;
    }
    for (int i = m + 1; i <= M; ++i) {
        p.push_back(i);
        make_sequences(n + 1, i, p);
        p.pop_back();
    }
}

signed main(){
    cin >> N >> M;
    auto p = vector<int>();
    make_sequences(0, 0, p);
    sort(seqs.begin(), seqs.end(), comp);
    for (auto p : seqs) {
        for (auto v : p) cout << v << " ";
        cout << endl;
    }
}