#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

class Graph {
    int v;
    vector<vector<pair<int, int>>> adj; // node, weight

public:
    Graph(int ver) {
        v = ver;
        adj.resize(v);
    }

    void addEdge(int u, int v, int wt) {
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    void display() {
        cout << "\nGraph adjacency list:\n";
        for (int i = 0; i < v; ++i) {
            cout << "Node " << i << ": ";
            for (auto &nbr : adj[i]) {
                cout << "(" << nbr.first << ", wt=" << nbr.second << ") ";
            }
            cout << endl;
        }
    }

    void dijkstra(int source) {
        vector<int> dist(v, INT_MAX);
        dist[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source});//dist,node

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            for (auto [neigh, wt] : adj[u]) {
                if (dist[u] + wt < dist[neigh]) {
                    dist[neigh] = dist[u] + wt;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        cout << "\nShortest distances from node " << source << ":\n";
        for (int i = 0; i < v; i++) {
            cout << "To node " << i << ": ";
            if (dist[i] == INT_MAX) {
                cout << "Unreachable\n";
            } else {
                cout << dist[i] << endl;
            }
        }
    }

    void primsMST() {
        typedef tuple<int, int, int> p; // weight, node, parent
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<bool> inMST(v, false);
        int total_weight = 0;

        pq.push({0, 0, -1}); // weight, node, parent

        cout << "\nEdges in MST (Prim's Algorithm):\n";
        while (!pq.empty()) {
            auto [wt, node, parent] = pq.top();
            pq.pop();

            if (inMST[node])
                continue;

            inMST[node] = true;
            total_weight += wt;

            if (parent != -1)
                cout << parent << " - " << node << " (weight " << wt << ")\n";

            for (auto &[neigh, edge_wt] : adj[node]) {
                if (!inMST[neigh]) {
                    pq.push({edge_wt, neigh, node});
                }
            }
        }

        cout << "Total weight of MST: " << total_weight << endl;
    }
};

int main() {
    int v;
    cout << "Enter number of vertices: ";
    cin >> v;
    Graph g(v);

    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Add Edge\n";
        cout << "2. Display Graph\n";
        cout << "3. Run Dijkstra's Algorithm\n";
        cout << "4. Run Prim's Algorithm (MST)\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int u, v2, wt;
            cout << "Enter edge (u v wt): ";
            cin >> u >> v2 >> wt;
            g.addEdge(u, v2, wt);
            break;
        }
        case 2:
            g.display();
            break;
        case 3: {
            int source;
            cout << "Enter source vertex: ";
            cin >> source;
            g.dijkstra(source);
            break;
        }
        case 4:
            g.primsMST();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
