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

const int mod = 998244353;

int modPow(int a,int n) {
    if(n == 0) return 1;
    if(n == 1)return a % mod;
    if (n%2 == 1) return(a * modPow(a, n-1)) % mod;
    int t = modPow(a, n/2);
    return (t * t) % mod;
}

int Q;

signed main() {
    cin >> Q;
    deque<int> deq;
    deq.push_back(1);
    int m = 1;
    while(Q--) {
        int q;
        cin >> q;
        if (q == 1) { 
            int x;
            cin >> x;
            m = (10*m + x) % mod;
            deq.push_back(x);
        } 
        else if (q == 2) {
            m -= deq.front() * modPow(10, deq.size()-1);
            m = (m%mod+ mod) % mod;
            deq.pop_front();
        } 
        else if (q == 3) {
            cout << m << endl;
        }
    }
}