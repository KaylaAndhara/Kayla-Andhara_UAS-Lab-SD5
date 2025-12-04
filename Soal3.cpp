#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculateDepth(int employee_index, const vector<int>& managers, vector<int>& depth) {
    if (depth[employee_index] != 0) {
        return depth[employee_index];
    }

    int manager_id = managers[employee_index];
    
    if (manager_id == -1) {
        depth[employee_index] = 1;
        return 1;
    }

    int manager_index = manager_id - 1;
    int current_depth = 1 + calculateDepth(manager_index, managers, depth);
    
    depth[employee_index] = current_depth;
    
    return current_depth;
}

void solve_party_problem() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return;

    vector<int> managers(N);
    for (int i = 0; i < N; ++i) {
        if (!(cin >> managers[i])) return;
    }

    vector<int> depth(N, 0);
    int max_groups = 0;

    // Hitung kedalaman maksimum
    for (int i = 0; i < N; ++i) {
        int current_depth = calculateDepth(i, managers, depth);
        max_groups = max(max_groups, current_depth);
    }

    // Output
    cout << max_groups << endl;
}

int main() {
    solve_party_problem();
    return 0;
}
