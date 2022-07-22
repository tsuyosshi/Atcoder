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

bool is_prime[200005];
vector<int> prime;

void sieve(int n) {
    for(int i = 0; i <= n; ++i) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= n; ++i) {
        if(is_prime[i]) {
            prime.push_back(i);
            for(int j = 2 * i; j <= n; j += i) is_prime[j] = false;
        }
    }
}

// O(Qlogx_i)
vector<PI> prime_factor(int x){
    vector<PI> res; // first=素数, second=指数
    for(int p = 2; p * p <= x; p++) {
        int k = 0;
        while(x % p == 0) {
            k++;
            x /= p;
        }
        if(k != 0) res.push_back(PI(p, k));
    }
    if(x != 1) res.push_back(PI(x, 1));
    return res;
}

int N;

signed main(){
    cin >> N;
    int ans = 0;
    for (int i = 1; i <= N; ++i) {
        int j = 1;
        auto ps = prime_factor(i);
        for (auto p : ps) {
            if (p.second % 2 == 0) continue;
            j *= p.first;
        }
        if (j > N) continue;
        ans += sqrt(N / j);
    }
    cout << ans << endl;
}