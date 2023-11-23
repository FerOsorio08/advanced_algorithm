#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

// Definición de la estructura para representar un nodo en el laberinto
struct Node {
    int x, y, distance, cost;

    // Constructor
    Node(int x, int y, int distance, int cost)
        : x(x), y(y), distance(distance), cost(cost) {}

    // Sobrecarga del operador de comparación para la cola de prioridad
    bool operator>(const Node &other) const {
        return cost > other.cost;
    }
};

// Función para verificar si un punto (x, y) está dentro del laberinto
bool isValid(int x, int y, int N) {
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// Función para encontrar el camino utilizando el algoritmo A*
string findPath(vector<vector<int> > &maze, int N) {
    // Direcciones posibles (arriba, abajo, izquierda, derecha)
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    
    // Inicialización del punto de inicio y destino
    Node start(0, 0, 0, 0);
    Node destination(N-1, N-1, 0, 0);

    // Creación de la matriz de visitados e inicialización con valores falsos
    vector<vector<bool> > visited(N, vector<bool>(N, false));

    // Creación de la cola de prioridad para almacenar los nodos a explorar
    priority_queue<Node, vector<Node>, greater<Node> > pq;

    // Inicialización del punto de inicio en la cola de prioridad
    pq.push(start);

    // Bucle principal del algoritmo A*
    while (!pq.empty()) {
        // Obtención del nodo actual
        Node current = pq.top();
        pq.pop();

        int x = current.x;
        int y = current.y;

        // Marcamos el nodo actual como visitado
        visited[x][y] = true;

        // Verificamos si hemos llegado al destino
        if (x == destination.x && y == destination.y) {
            return to_string(current.distance);
        }

        // Exploramos los vecinos
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            // Verificamos si el vecino es válido y no ha sido visitado
            if (isValid(newX, newY, N) && maze[newX][newY] == 1 && !visited[newX][newY]) {
                // Calculamos la distancia y el costo para el vecino
                int newDistance = current.distance + 1;
                int newCost = newDistance + abs(newX - destination.x) + abs(newY - destination.y);

                // Creamos el nodo del vecino y lo añadimos a la cola de prioridad
                pq.push(Node(newX, newY, newDistance, newCost));
            }
        }
    }

    // Si llegamos aquí, no se encontró un camino válido
    return "No se encontró un camino";
}

int main() {
    // Tamaño del laberinto
    int N;
    cout << "Ingrese el tamaño del laberinto (N): ";
    cin >> N;

    // Inicialización del laberinto
    vector<vector<int> > maze(N, vector<int>(N, 0));

    // Ingreso de los valores del laberinto
    cout << "Ingrese el laberinto (0 para bloqueado, 1 para libre):\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> maze[i][j];
        }
    }

    // Encontrar el camino utilizando el algoritmo A*
    string path = findPath(maze, N);

    // Imprimir el resultado
    cout << "El camino más corto es: " << path << endl;

    return 0;
}
