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

int modPow(int a, int n) {
    if (n == 0) return 1;
    if (n == 1) return a % mod;
    if (n % 2 == 1) return (a * modPow(a, n - 1)) % mod;
    int t = modPow(a, n / 2);
    return (t * t) % mod;
}

int fact[500005];
int fact_inv[500005];

class Comb {
public:
    Comb(int N){
        fact[0] = 1;
        fact_inv[0] = 1;
        for(int i = 1; i <= N; ++i) {
            fact[i] = fact[i - 1] * i % mod;
            fact_inv[i] = modPow(fact[i], mod - 2);
        }
    }

    int comb(int n, int r){
        return (((fact[n] * fact_inv[r]) % mod) * fact_inv[n - r]) % mod;
    }

    int perm(int n, int k){
        return (fact[n] * fact_inv[n - k]) % mod;
    }
};

signed main() {

}