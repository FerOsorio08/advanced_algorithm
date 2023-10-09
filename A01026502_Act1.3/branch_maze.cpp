#include <iostream>
#include <vector>

using namespace std;

const int N = 5; // Size of the maze, adjust as needed

// Function to check if a cell is a valid move
bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

// Function to solve the rat in a maze problem using branch and bound
bool solveMazeUtil(int maze[N][N], int x, int y, vector<vector<int> >& sol) {
    // If the rat has reached the destination
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    // Check if x, y is a valid move
    if (isSafe(maze, x, y)) {
        // Mark this cell as part of the solution path
        sol[x][y] = 1;

        // Move right
        if (solveMazeUtil(maze, x + 1, y, sol))
            return true;

        // Move down
        if (solveMazeUtil(maze, x, y + 1, sol))
            return true;

        // If neither right nor down leads to the solution, backtrack
        sol[x][y] = 0;
        return false;
    }

    return false;
}

// Wrapper function to solve the rat in a maze problem
void solveMaze(int maze[N][N]) {
    vector<vector<int> > sol(N, vector<int>(N, 0)); // Initialize a solution matrix

    if (!solveMazeUtil(maze, 0, 0, sol))
        cout << "No solution exists" << endl;
    else {
        cout << "Solution Path:" << endl;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << sol[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int maze[N][N] = {
        {1, 0, 0, 0, 1},
        {1, 1, 0, 1, 1},
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}
    };

    solveMaze(maze);

    return 0;
}
