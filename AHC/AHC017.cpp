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

// vector<vector<int>> warshall_floyd(vector<vector<PI>> &G) {
//     int n = G.size();
//     vector<vector<int>> dist(n, vector<int>(n, INF));
//     for (int i = 0; i < n; ++i) {
//         for (auto e : G[i]) {
//             dist[i][e.first] = e.second;
//         }
//     }
//     for (int k = 0; k < n; k++) {       
//         for (int i = 0; i < n; i++) {    
//             for (int j = 0; j < n; j++) {
//                 dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//             }
//         }
//     }
//     return dist;
// }

// struct State{

//     int eval;

//     State(){
//     }

//     State changeState() {
//         random_device rd;
//         mt19937 mt(rd());
//         uniform_int_distribution<uint32_t> get_rnd(0, );
//     }
// };

// State init_state() {
// }

// double tempareture(double t0, int loop, int cnt, int paramA = 1, int paramB = 4) {
//     double progress = (cnt + 0.5) / loop;
//     double remain = 1.0 - progress;
//     double t = t0 * pow(remain, paramA) * exp(-progress * paramB);
//     return t;
// }
 
// State simulated_annealing(double t0, int MAX_LOOP = 100000, const uint32_t MAX_RAND = mt19937::max()) {
//     State state = init_state();
//     random_device rd;
//     mt19937 mt(rd());
//     uniform_int_distribution<uint32_t> get_rnd(0, MAX_RAND - 1);
//     for (int loop = 0; loop < MAX_LOOP; ++loop) {
//         auto new_state = state.changeState();
//         int pre_eval = state.eval;
//         int new_eval = new_state.eval;
//         double temp = tempareture(t0, MAX_LOOP, loop);
//         double p = exp((double) (new_eval - pre_eval) / temp);
//         double q = (double) ((double) get_rnd(mt) / (double) MAX_RAND);
//         if (min(p, 1.0) > q) {
//             state = new_state;
//         }
//     }
//     return state;
// }

signed main(){
}