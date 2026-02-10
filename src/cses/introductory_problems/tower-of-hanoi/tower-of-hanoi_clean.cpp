#include <vector>
#include <iostream>
using namespace std;

class Towers {
    vector<vector<int>> game_state; // holds current amount of disks on each of 3 towers (towers: 0, 1, 2)
    vector<pair<int, int>> moves; // holds moves from .first to .second
    int total_disks;

    void solve_rec(int n, int from, int to, int aux) {
        if (n == 0) {
            return;
        }
        solve_rec(n - 1, from, aux, to);
        make_move(from, to);
        solve_rec(n - 1, aux, to, from);
    }
    // Takes the highest disks from a tower (from) and places onto a tower (to)
    void make_move(int from, int to) {
        int disk = game_state[from].back();
        game_state[to].emplace_back(disk);

        moves.emplace_back(from, to);
    }

public:
    explicit Towers(int disks) : game_state(3), total_disks(disks) {
        moves.clear();
        for (int i = disks; i > 0; i--) {
            game_state[0].emplace_back(i);
        }
    }

    void solve() {
        solve_rec(total_disks, 0, 2, 1);
        cout << moves.size() << endl;
        for (auto &move : moves) {
            cout << move.first + 1 << " " << move.second + 1 << endl;
        }
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    Towers towers(n);
    towers.solve();
    return 0;
}
