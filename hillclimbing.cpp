#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    vector<vector<int>> state;
    int heuristic;
};

vector<vector<int>> goal = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};

bool is_goal(const vector<vector<int>>& state) {
    return state == goal;
}

int misplaced_tiles(const vector<vector<int>>& state) {
    int count = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (state[i][j] != 0 && state[i][j] != goal[i][j])
                count++;
    return count;
}

pair<int, int> find_blank(const vector<vector<int>>& state) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (state[i][j] == 0)
                return make_pair(i, j);
    return make_pair(-1, -1);
}

vector<vector<vector<int>>> generate_moves(vector<vector<int>> state) {
    vector<vector<vector<int>>> moves;
    pair<int, int> blank = find_blank(state);
    int x = blank.first, y = blank.second;

    if (x > 0) { swap(state[x][y], state[x-1][y]); moves.push_back(state); swap(state[x][y], state[x-1][y]); }
    if (x < 2) { swap(state[x][y], state[x+1][y]); moves.push_back(state); swap(state[x][y], state[x+1][y]); }
    if (y > 0) { swap(state[x][y], state[x][y-1]); moves.push_back(state); swap(state[x][y], state[x][y-1]); }
    if (y < 2) { swap(state[x][y], state[x][y+1]); moves.push_back(state); swap(state[x][y], state[x][y+1]); }

    return moves;
}

void hill_climbing(vector<vector<int>> start) {
    vector<vector<int>> current = start;
    int current_h = misplaced_tiles(current);

    cout << "--- Hill Climbing ---\n";
    while (true) {
        cout << "Current heuristic: " << current_h << "\n";
        for (auto &row : current) {
            for (int val : row) cout << val << " ";
            cout << "\n";
        }
        cout << "---\n";

        if (is_goal(current)) {
            cout << "Goal reached!\n";
            return;
        }

        vector<vector<vector<int>>> neighbors = generate_moves(current);
        vector<vector<int>> best_neighbor = current;
        int best_h = current_h;

        for (auto &n : neighbors) {
            int h = misplaced_tiles(n);
            if (h < best_h) {  // strictly better
                best_h = h;
                best_neighbor = n;
            }
        }

        if (best_h >= current_h) {
            cout << "Reached local optimum. No better neighbor found.\n";
            return;
        }

        current = best_neighbor;
        current_h = best_h;
    }
}

int main() {
    vector<vector<int>> start(3, vector<int>(3));
    cout << "Enter puzzle (0 for blank):\n";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            cin >> start[i][j];

    hill_climbing(start);
}
