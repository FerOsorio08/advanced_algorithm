//Fernanda Osorio
//A01026502
//09 de noviembre del 2023
//Este archivo header contiene las funciones necesarias para el algoritmo de dijkstra
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <limits>
#ifndef Dijkstra_H
#define Dijkstra_H

using namespace std;

//Declaraciones de funciones

//Funciones para dijkstra
// Function to perform Dijkstra's algorithm
//Comlejidad = O(E+VlogV), donde E es el numero de aristas y V el numero de vertices
pair<vector<int>, vector<int> > dijkstra(const vector<vector<int> >& graph, int source) {
    int n = graph.size();
    //distancia para guardar la distancia mas corta
    vector<int> distance(n, numeric_limits<int>::max());
    //previo para guardar el camino mas corto
    vector<int> previous(n, NULL);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > priorityQ;
    
    //para cada nodo en el grafo si el nodo es diferente del nodo fuente se agrega a la cola de prioridad
    for (int i = 0; i < n; ++i) {
        if (i != source) {
            priorityQ.push(make_pair(distance[i], i));
        }
    }
    distance[source] = 0;

    //Cola de prioridad con el nodo fuente
    
    priorityQ.push(make_pair(0, source));

    //mientras la cola de prioridad no este vacia
    while (!priorityQ.empty()) {
        int u = priorityQ.top().second;
        //se saca el nodo con la menor distancia
        priorityQ.pop();

        for (int v = 0; v < n; ++v) {
            //si el nodo v es diferente del nodo u y la distancia entre u y v es diferente de -1
            if (graph[u][v] != -1) {
                //entonces la distancia temporal es la distancia de u mas la distancia entre u y v
                int tempDistance = distance[u] + graph[u][v];
                if (tempDistance < distance[v]) {
                    distance[v] = tempDistance;
                    previous[v] = u;
                    //se agrega a la cola de prioridad
                    priorityQ.push(make_pair(distance[v], v));
                }
            }
        }
    }

    return make_pair(distance, previous);
}

#endif