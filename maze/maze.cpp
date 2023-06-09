#include <fstream>
#include <vector>
#include <queue>
#include <iostream>
#include <cassert>
using namespace std;
#define mp make_pair
vector<vector<int>> maze {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},{-1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, -1, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, -1, -1},{-1, 0, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, -1, 0, 0, 0, -1},{-1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, 0, -1, 0, -1},{-1, 0, 0, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1},{-1, 0, 0, -1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -1},{-1, 0, 0, -1, 0, 0, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, 0, -1, -1, -1, -1, -1, 0, -1, -1, 0, -1, 0, 0, 0, 0, -1},{-1, 0, 0, -1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, -1},{-1, 0, 0, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, 0, -1},{-1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1},{-1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, -1},{-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, -1, 0, -1},{-1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, 0, 0, -1, -1, -1, -1, -1, -1, 0, -1},{-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, -1},{-1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, -1},{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};

vector<int> solution(1000, 0);
void print_sol(int pas) {
    ofstream f("solution.txt");
    int i;
    for(i = 0; i < pas; ++i) {
        switch(solution[i]) {
            case 0:
                f << "sus\n";
                break;
            case 1:
                f << "stanga\n";
                break;
            case 2:
                f << "jos\n";
                break;
            case 3:
                f << "dreapta\n";
                break;
        }
    }
    f.close();
    exit(1);
}
void show_matrix() {
    int i, j;
    for(i = 0; i < maze.size(); ++i) {
        for(j = 0; j < maze[0].size(); ++j) {
            if(maze[i][j] == -1) cout << "#";
            else if(maze[i][j] == 1) cout << "O";
            else cout << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}
void solve_maze(int x, int y, int pas) {
    //cout << x << " " << y << endl;
    if(maze[x][y] == -1) return;
    if(maze[x][y] == 1) return;
    if(y == 33 && x == 2) print_sol(pas);
    
    //show_matrix();

    maze[x][y] = 1;
    solution[pas] = 2;
    solve_maze(x + 1, y, pas + 1);

    solution[pas] = 3;
    solve_maze(x, y + 1, pas + 1);

    solution[pas] = 1;
    solve_maze(x, y - 1, pas + 1);

    solution[pas] = 0;
    solve_maze(x - 1, y, pas + 1);

    maze[x][y] = 0;

}

int main() {
    cout << maze[0].size() << endl;
    show_matrix();
    solve_maze(1, 1, 0);
    return 0;
}