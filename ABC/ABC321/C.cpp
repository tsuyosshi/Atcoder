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

int K;

signed main() {
    cin >> K;
    vector<int> numbers;
    for (int bit = 0; bit < (1<<10); ++bit) {
        string s;
        for (int i = 9; i >= 0; --i) if (bit & (1<<i)) s.push_back('0'+i);
        if (!s.empty()) {
            int num = stoll(s);
            numbers.push_back(num);
        }
    }
    sort(numbers.begin(), numbers.end());
    cout << numbers[K] << endl;
}  