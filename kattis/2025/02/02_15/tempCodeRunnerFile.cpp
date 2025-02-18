    cout << "Subgraph:\n";
    for (auto [a, b]: subgraph) {
     cout << a << " " << b << "\n";
    }

    cout << dist_hit << "\n";
    for (int i = 0; i <= V; i++) {
     cout << i << ": ";
     for (int x: ancestors[i]) {
         cout << x << " ";
     }
     cout << "\n";
    }