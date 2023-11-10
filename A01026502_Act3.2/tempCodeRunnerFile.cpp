  vector<Edge> edges = ReadFile("try.txt");
    int n = 0;
    for (const auto& edge : edges) {
        n = max(n, max(edge.start, edge.end) + 1);
    }
    int m = edges.size();
    cout << "Número de nodos: " << n << endl;
    vector<vector<int> > matrizAdyacencia = construirMatrizAdyacencia(n, edges);

    return 0;
}