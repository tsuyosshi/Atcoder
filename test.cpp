#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> A;

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    priority_queue<int> pq;
    for (auto a : A) {
        cout << (a & 1) << endl;
    }
}