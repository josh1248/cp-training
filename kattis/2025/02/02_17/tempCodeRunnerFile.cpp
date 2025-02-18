
    for (int i = 0; i < vertices; i++) {
        cout << i << ": ";
        for (int j: graph[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }