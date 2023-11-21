#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Definición de un nodo en el laberinto
struct Node {
    int x, y, distance, heuristic;

    // Constructor
    Node(int _x, int _y, int _distance, int _heuristic)
        : x(_x), y(_y), distance(_distance), heuristic(_heuristic) {}

    // Comparador para la prioridad en la cola de prioridad (A* utiliza la suma de la distancia y la heurística)
    bool operator>(const Node& other) const {
        return (distance + heuristic) > (other.distance + other.heuristic);
    }
};

// Función para verificar si un movimiento es válido
bool isValid(int x, int y, int N, const vector<vector<int> >& maze, vector<vector<bool> >& visited) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1 && !visited[x][y]);
}

// Función para imprimir la ruta encontrada
void printPath(const vector<Node>& path) {
    for (const auto& node : path) {
        cout << "(" << node.x << "," << node.y << ") ";
    }
    cout << endl;
}

// Función principal para encontrar el camino utilizando A*
vector<Node> findPath(const vector<vector<int> >& maze, int N) {
    // Inicialización del punto de inicio y fin
    Node start(0, 0, 0, 0);
    Node destination(N - 1, N - 1, 0, 0);


    // Inicialización de la cola de prioridad para almacenar los nodos a explorar
    priority_queue<Node, vector<Node>, greater<Node> > pq;

    // Inicialización del laberinto visitado
    vector<vector<bool> > visited(N, vector<bool>(N, false));

    // Inicialización del vector de dirección
    vector<pair<int, int> > directions;
    directions.push_back(make_pair(-1, 0));
    directions.push_back(make_pair(0, -1));
    directions.push_back(make_pair(1, 0));
    directions.push_back(make_pair(0, 1));
        
    // Insertar el nodo de inicio en la cola de prioridad
    pq.push(start);

    while (!pq.empty()) {
        // Extraer el nodo de menor coste de la cola de prioridad
        Node current = pq.top();
        pq.pop();

        // Marcar el nodo como visitado
        visited[current.x][current.y] = true;

        // Verificar si hemos llegado al destino
        if (current.x == destination.x && current.y == destination.y) {
            // Reconstruir el camino desde el destino hasta el origen
            vector<Node> path;
            while (!(current.x == start.x && current.y == start.y)) {
                path.push_back(current);
                current = path.back();
            }
            path.push_back(start);
            reverse(path.begin(), path.end());
            return path;
        }

        // Explorar los movimientos posibles en las cuatro direcciones
        for (const auto& dir : directions) {
            int nextX = current.x + dir.first;
            int nextY = current.y + dir.second;

            // Verificar si el próximo movimiento es válido
            if (isValid(nextX, nextY, N, maze, visited)) {
                // Calcular la distancia y heurística para el próximo nodo
                int nextDistance = current.distance + 1;
                int nextHeuristic = abs(nextX - destination.x) + abs(nextY - destination.y);

                // Insertar el próximo nodo en la cola de prioridad
                pq.push(Node(nextX, nextY, nextDistance, nextHeuristic));

            }
        }
    }

    // Si llegamos aquí, no se encontró un camino
    cout << "No se encontró un camino." << endl;
    return vector<Node>();
}

int main() {
    // Definir el tamaño del laberinto (N)
    int N;
    cout << "Ingrese el tamaño del laberinto (N): ";
    cin >> N;

    // Definir el laberinto como una matriz
    vector<vector<int> > maze(N, vector<int>(N));

    // Ingresar los elementos de la matriz
    cout << "Ingrese los elementos del laberinto (0 o 1):" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> maze[i][j];
        }
    }
    cout << endl;
    cout << "Laberinto ingresado:" << endl;
    for (const auto& row : maze) {
        for (int cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }

    // Encontrar el camino utilizando A*
    vector<Node> path = findPath(maze, N);

    // Imprimir el camino encontrado
    cout << "Camino encontrado: ";
    printPath(path);

    return 0;
}
