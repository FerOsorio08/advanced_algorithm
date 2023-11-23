#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

struct Node {
    int x, y, distance, cost;
    string path; // Added to store the path

    Node(int x, int y, int distance, int cost, string path)
        : x(x), y(y), distance(distance), cost(cost), path(path) {}

    bool operator>(const Node &other) const {
        return cost > other.cost;
    }
};

bool isValid(int x, int y, int N) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

string findPath(vector<vector<int> > &maze, int N) {
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    Node start(0, 0, 0, 0, ""); // Updated to include the path
    Node destination(N-1, N-1, 0, 0, "");

    vector<vector<bool> > visited(N, vector<bool>(N, false));

    priority_queue<Node, vector<Node>, greater<Node> > pq;
    pq.push(start);

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        int x = current.x;
        int y = current.y;

        visited[x][y] = true;

        if (x == destination.x && y == destination.y) {
            return current.path;
        }

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValid(newX, newY, N) && maze[newX][newY] == 1 && !visited[newX][newY]) {
                int newDistance = current.distance + 1;
                int newCost = newDistance + abs(newX - destination.x) + abs(newY - destination.y);

                // Updated to include the direction in the path
                string newPath = current.path;
                switch (i) {
                    case 0: newPath += "U"; break;
                    case 1: newPath += "D"; break;
                    case 2: newPath += "L"; break;
                    case 3: newPath += "R"; break;
                }

                pq.push(Node(newX, newY, newDistance, newCost, newPath));
            }
        }
    }

    return "No se encontró un camino";
}

int main() {
    int N;
    cout << "Ingrese el tamaño del laberinto (N): ";
    cin >> N;

    vector<vector<int> > maze(N, vector<int>(N, 0));

    cout << "Ingrese el laberinto (0 para bloqueado, 1 para libre):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
        }
    }

    string path = findPath(maze, N);

    if (path != "No se encontró un camino") {
        cout << "El camino más corto es: " << path << endl;
    } else {
        cout << "No se encontró un camino" << endl;
    }

    return 0;
}
