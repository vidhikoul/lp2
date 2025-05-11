#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <climits>
using namespace std;

class Graph {
public:
    vector<vector<pair<int, int>>> adj;
    int v;
    Graph(int ver) {
        v = ver;
        adj.resize(v);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void display() {
        cout << "\nAdjacency list:\n";
        for (int i = 0; i < v; i++) {
            cout << "Node " << i << ": ";
            for (auto& a : adj[i]) {
                cout << "(" << a.first << ", wt=" << a.second << ") ";
            }
            cout << endl;
        }
    }

    void dijkstra(int start) {
        typedef pair<int, int> p;
        priority_queue<p, vector<p>, greater<p>> pq;
        vector<int> dist(v, INT_MAX);
        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [d, n] = pq.top();
            pq.pop();

            for (auto& [neigh, wt] : adj[n]) {
                if ((dist[n] + wt) < dist[neigh]) {
                    dist[neigh] = dist[n] + wt;
                    pq.push({dist[neigh], neigh});
                }
            }
        }

        cout << "\nShortest distances from node " << start << ":\n";
        for (int i = 0; i < v; i++) {
            cout << "To node " << i << ": ";
            if (dist[i] == INT_MAX) {
                cout << "Not reachable";
            } else {
                cout << dist[i];
            }
            cout << endl;
        }
    }

    void prims(int start) {
        typedef tuple<int, int, int> t;  // (weight, node, parent)
        vector<bool> inmst(v, false);
        priority_queue<t, vector<t>, greater<t>> que;
        int total_weight = 0;
        que.push({0, start, -1});

        cout << "\nEdges in MST:\n";
        while (!que.empty()) {
            auto [wt, node, parent] = que.top();
            que.pop();

            if (inmst[node])
                continue;

            inmst[node] = true;
            total_weight += wt;
            if (parent != -1) {
                cout << parent << " - " << node << " (weight=" << wt << ")\n";
            }

            for (auto& [neigh, wt] : adj[node]) {
                if (!inmst[neigh]) {
                    que.push({wt, neigh, node});
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
        case 4: {
            int source;
            cout << "Enter source vertex: ";
            cin >> source;
            g.prims(source);
            break;
        }
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}




// Great question, Emily! Let’s break it down **clearly and crisply** — because Prim's and Dijkstra's algorithms **look similar** (both use a priority queue and greedy approach), but their **purpose and behavior are different**.

// | **Feature**             | **Prim's Algorithm**                                        | **Dijkstra's Algorithm**                                                           |
// | ----------------------- | ----------------------------------------------------------- | ---------------------------------------------------------------------------------- |
// | **Goal**                | Find **Minimum Spanning Tree (MST)**                        | Find **Shortest Path** from a source to all nodes                                  |
// | **What it computes?**   | A **tree** that connects all vertices with min total weight | **Shortest distance** from source to every other vertex                            |
// | **Applicable to**       | **Undirected weighted graphs**                              | **Directed or undirected weighted graphs** (no negative weights)                   |
// | **Edge criteria**       | **Choose smallest edge** connecting tree to new node        | **Choose smallest total distance** to a node                                       |
// | **Output**              | Set of edges forming MST (spanning all nodes, no cycles)    | Array of shortest distances from source                                            |
// | **When is node added?** | When it gets connected to MST (cheapest edge)               | When shortest distance to node is finalized                                        |
// | **Cycle allowed?**      | **NO** — MST is **acyclic**                                 | **YES** — Paths can revisit nodes (but distances don't improve after finalization) |
// | **Initialization**      | Start from **any node**                                     | Start from **given source node**                                                   |
// | **Example use**         | Designing **network cables**, **electrical grids**          | **GPS**, **routing**, **maps**                                                     |
// | **Algorithm core idea** | Grow MST by choosing **minimum weight edge**                | Relax edges to get **minimum path cost**                                           |

// ---

// ### 🎯 **In short**

// * **Prim's** builds a **network that touches every node**, with minimal cost → it's about **covering**.
// * **Dijkstra's** finds the **fastest route from A to B** → it's about **reaching** efficiently.

// ---

// ### ⚡️ **Analogy**

// * **Prim's**: "I want to lay cables to connect all houses **with least total wire length**."
// * **Dijkstra's**: "I want to travel from my house to every other house **in the shortest time**."

// ---

// If you want, I can also show a **visual example of both on the same graph** to make it 100% clear.
// Would you like that? ✏️📈














// Excellent — that’s exactly the smart preparation, Emily!
// Here’s your **Viva Questions + Answers** neatly organized so you can revise quickly 👇

// ---

// ## 📋 **Basic Questions (with Answers)**

// | **Question**                                      | **Answer**                                                                                                                                                         |
// | ------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
// | What is the objective of Dijkstra’s algorithm?    | To find the shortest path from a single source node to all other nodes in a weighted graph (with non-negative weights).                                            |
// | What is the objective of Prim’s algorithm?        | To find a Minimum Spanning Tree (MST) — a subset of edges that connects all vertices with minimum total weight and no cycles.                                      |
// | What is a Minimum Spanning Tree (MST)?            | A spanning tree of a connected graph with the least possible total edge weight and no cycles.                                                                      |
// | Can Dijkstra’s algorithm handle negative weights? | No, it doesn't work correctly with negative weights. It assumes that once a node's shortest distance is finalized, it won't improve — negative edges violate this. |
// | Does Prim’s algorithm work on directed graphs?    | No, Prim’s algorithm is designed for **undirected graphs**.                                                                                                        |
// | Time complexities of Prim’s and Dijkstra’s?       | Both are **O(E log V)** with priority queue (Min-Heap + Adjacency list).                                                                                           |
// | What data structures are used in both?            | Priority queue (Min-Heap), Arrays (`dist[]` or `inMST[]`), and Adjacency List for graph.                                                                           |
// | Can both algorithms generate the same output?     | Yes, if the graph is fully connected and weights align — Prim’s MST and Dijkstra’s SPT can look similar, but they solve **different problems**.                    |
// | What is the greedy strategy in both?              | Always choose the next node with the **minimum cost/weight** locally (shortest distance or smallest edge).                                                         |
// | Shortest path tree vs MST?                        | SPT minimizes distance **from a source** to all nodes. MST minimizes **total edge weight** to connect all nodes — no source.                                       |

// ---

// ## ⚙️ **Conceptual Questions (with Answers)**

// | **Question**                                      | **Answer**                                                                                                                         |
// | ------------------------------------------------- | ---------------------------------------------------------------------------------------------------------------------------------- |
// | How does Dijkstra update distances?               | By **relaxing edges** — if `dist[u] + wt < dist[v]`, update `dist[v]`.                                                             |
// | How does Prim prevent cycles?                     | By only adding edges to **nodes not in MST yet** (`inMST[]` array).                                                                |
// | If graph is disconnected in Prim?                 | The MST is not possible (only works for **connected graphs**).                                                                     |
// | Can Prim start from any vertex?                   | Yes — the MST will be the same total weight (though edge structure may differ).                                                    |
// | Negative weights in Dijkstra?                     | It fails because distances can be wrongly finalized. Use **Bellman-Ford** instead.                                                 |
// | Why use priority queue?                           | To **quickly select** node with **smallest distance/weight** in O(log V) time.                                                     |
// | Difference between Prim and Kruskal?              | Prim: grows MST from one node, **works well with dense graphs**. Kruskal: sorts edges globally, **works well with sparse graphs**. |
// | Output format of Dijkstra vs Prim?                | Dijkstra: **distances** from source to all nodes. Prim: **edges of MST** and total weight.                                         |
// | Why visited/inMST\[] used?                        | To prevent **revisiting** already processed nodes.                                                                                 |
// | Once Dijkstra finalizes distance — can it change? | No — once finalized (popped from PQ), it remains optimal.                                                                          |

// ---

// ## 💻 **Program-specific Questions (with Answers)**

// | **Question**                                       | **Answer**                                                                               |
// | -------------------------------------------------- | ---------------------------------------------------------------------------------------- |
// | Graph representation?                              | **Adjacency list** with `vector<vector<pair<int, int>>>`.                                |
// | Why use priority queue?                            | For **efficient min selection** — next node with min distance/weight.                    |
// | What happens without visited\[]?                   | Nodes can be revisited unnecessarily → wrong or inefficient result.                      |
// | Significance of parent\[] in Prim?                 | To **track MST edges** (for printing MST tree).                                          |
// | How are you displaying output?                     | **Adjacency list** and print **distances / MST edges** clearly.                          |
// | Changes to handle dense graph?                     | Use **Adjacency Matrix** + Prim’s with O(V²) time.                                       |
// | Role of `pair<int,int>` or `tuple<int,int,int>`?   | Store (weight, node), or (weight, node, parent) cleanly in PQ.                           |
// | Modify Dijkstra for specific 2-node shortest path? | Stop when target node is **popped** from PQ — early exit.                                |
// | Role of `priority_queue<pair<int, int>, …>`?       | Min-heap where **pair\<dist, node>** — always processes **minimum distance node first**. |
// | Worst case time complexity (your program)?         | **O(E log V)** (Adjacency list + Min-Heap).                                              |

// ---

// ## 🌟 **Bonus / Higher-Level Answers**

// | **Question**                              | **Answer**                                                                                                         |
// | ----------------------------------------- | ------------------------------------------------------------------------------------------------------------------ |
// | Fibonacci heap in Dijkstra/Prim?          | Reduces time complexity to **O(E + V log V)** — but complex to implement.                                          |
// | Single-source vs All-pairs shortest path? | Dijkstra: **single-source**. For all-pairs → use **Floyd-Warshall** or **Johnson’s algorithm**.                    |
// | Handle negative weights in Dijkstra?      | Use **Bellman-Ford algorithm** (handles negative weights, slower).                                                 |
// | Sparse graph → Prim or Kruskal?           | **Kruskal** — fewer edges → faster sorting.                                                                        |
// | Real-life applications?                   | Dijkstra: **Google Maps**, network routing. Prim: **Electrical grids**, **Network design**, **Telecommunication**. |

// ---

// ## ✅ **Final Tip for Your Viva**

// Whenever possible, **mention time complexities** and **data structures used** — that impresses examiners the most!
// And always emphasize:

// > **Dijkstra = Shortest path**, **Prim = Minimum spanning tree**

// ---

// Would you like **a 1-page cheat sheet** PDF for quick revision too? (I can prepare that) 📄
