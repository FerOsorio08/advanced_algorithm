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
pair<vector<int>, vector<int> > dijkstra(const vector<vector<int> >& graph, int source) {
    int n = graph.size();
    vector<int> distance(n, numeric_limits<int>::max());
    vector<int> previous(n, NULL);
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    
    //for each node in graph if the node is different from the source node add it to the priority queue
    for (int i = 0; i < n; ++i) {
        if (i != source) {
            pq.push(make_pair(distance[i], i));
        }
    }
    distance[source] = 0;

    // Priority queue to store vertices and their distances
    
    pq.push(make_pair(0, source));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < n; ++v) {
            if (graph[u][v] != -1) {
                int tempDistance = distance[u] + graph[u][v];
                if (tempDistance < distance[v]) {
                    distance[v] = tempDistance;
                    previous[v] = u;
                    pq.push(make_pair(0, source));
                }
            }
        }
    }

    return make_pair(distance, previous);
}

#endif