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

int node[600005];
int n;

class SegmentTree{
public:
    SegmentTree(int n_){
        n=1;
        while(n<n_)n*=2;
        for(int i=0;i<2*n-1;i++)node[i]=INF;
    }
    void update(int a,int x){
        a+=n-1;
        node[a]=x;
        while(a>0){
            a=(a-1)/2;
            node[a]=min(node[2*a+1],node[2*a+2]);
        }
    }
    int query(int a,int b,int k=0,int l=0,int r=n){
        if(b<=l||r<=a)return INF;
        if(a<=l&&r<=b)return node[k];
        int vl=query(a,b,2*k+1,l,(l+r)/2);
        int vr=query(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
};


int N;
int L, R;

signed main(){
    cin >> N >> L >> R;
    vector<int> A(N + 1);
    vector<int> S(N + 1, 0);
    for (int i = 1; i <= N; ++i) cin >> A[i];
    for (int i = 1; i <= N; ++i) S[i] = S[i - 1] + A[i];
    SegmentTree seg(N + 1);
    for (int i = 0; i <= N; ++i) seg.update(i, S[N - i] + i * R);
    int ans = INF;
    for (int x = 0; x <= N; ++x) {
        int Y = seg.query(0, N - x + 1);
        chmin(ans, x * L - S[x] + Y);
    }
    cout << ans << endl;
}
