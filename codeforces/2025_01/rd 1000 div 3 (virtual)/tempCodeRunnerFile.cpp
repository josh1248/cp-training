    int mver = 0, mval = 0;
    for (int i = 0; i < v + 1; i++) {
        if (graph[i].size() > mval) {
            mver = i;
            mval = graph[i].size(); 
        }
    }


    for (int i: graph[mver]) {
        graph[i].erase(mver);
    }
    graph[mver].clear();

    mver = 0, mval = 0;
    for (int i = 0; i < v + 1; i++) {
        if (graph[i].size() > mval) {
            mver = i;
            mval = graph[i].size(); 
        }
    }
    for (int i: graph[mver]) {
        graph[i].erase(mver);
    }
    graph[mver].clear();
