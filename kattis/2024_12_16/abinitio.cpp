#include <iostream>
#include <algorithm> // sort
#include <bits/stdc++.h>
#include <cstdio>
#include <map>
#include <numeric> // accumulate
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;

class Graph {
private:
    const ll hash_divisor = ll(10e9) + 7;
    int vertices;
    vector<vector<bool>> am;
    bool transposeflag;
    bool complementflag;

    bool read(int r, int c) {
        if (r == c) {
            return false;
        } 

        if (transposeflag) {
            swap(c, r);
        }
        
        if (complementflag) {
            return !am[r][c];
        } else {
            return am[r][c];
        }
    }

    void write(int r, int c, bool b) {
        if (r == c) {
            return;
        }

        if (transposeflag) {
            swap(r, c);
        }

        while (am.size() <= r) {
            am.push_back(vector<bool>());
        }

        while (am[r].size() <= c) {
            am[r].push_back(false);
        }

        if (complementflag) {
            am[r][c] = !b;
        } else {
            am[r][c] = b;
        }
    }

    void print_hash(int v) {
        ll acc = 0;
        ll c = 0;
        for (int i = vertices - 1; i >= 0; --i) {
            if (read(v, i)) {
                c++;
                // Horner's method
                acc *= 7;
                acc += i;
                acc %= hash_divisor;
            }
        }
        cout << c << " " << acc << "\n";
    }

public:
    Graph(int size) {
        vertices = 0;
        transposeflag = false;
        complementflag = false;
        for (int i = 0; i < size; ++i) {
            add_vertex();
        }
    }

    void add_vertex() {
        for (int i = 0; i < vertices + 1; ++i) {
            write(i, vertices, false);
            write(vertices, i, false);
        }
        vertices++;
    }

    void add_edge(int u, int v) {
        write(u, v, true);
    }

    void remove_edges(int v) {
        for (int i = 0; i < vertices; ++i) {
            write(i, v, false);
            write(v, i, false);
        }
    }

    void remove_edge(int u, int v) {
        write(u, v, false);
    }

    void transpose() {
        transposeflag = !transposeflag;
    }

    void complement() {
        complementflag = !complementflag;
    }

    void print() {
        cout << vertices << "\n";
        for (int i = 0; i < vertices; ++i) {
            print_hash(i);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e, q;
    cin >> v >> e >> q;

    Graph g(v);
    int t, a, b;
    for (int i = 0; i < e; ++i) {
        cin >> a >> b;
        g.add_edge(a, b);
    }

    for (int i = 0; i < q; ++i) {
        cin >> t;
        switch (t) {
            case 1:
                g.add_vertex();
                break;
            case 2:
                cin >> a >> b;
                g.add_edge(a, b);
                break;
            case 3:
                cin >> a;
                g.remove_edges(a);
                break;
            case 4:
                cin >> a >> b;
                g.remove_edge(a, b);
                break;
            case 5:
                g.transpose();
                break;
            case 6:
                g.complement();
                break;
        }
    }

    g.print();
}