#include<iostream>
using namespace std;
class Graph
{
    int v;
    vector<vector<int>>adj;
    public:
    Graph(int ver)
    {
        v=ver;
        adj.resize(v);
    }
    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs_rec(int start)
    {
        vector<bool>visited(v,false);
        dfs(start,visited,0);

    }
    void dfs(int start,vector<bool>&visited,int level)
    {
        visited[start]=true;
        cout<<"node: "<<start<<" level:"<<level;
        for(auto &neigh:adj[start])
        {
            if(!visited[neigh])
            {
                visited[neigh]=true;
                dfs(neigh,visited,level+1);
            }


        }
    }
    void bfs_rec(int start)
    {
        vector<bool>visited(v,false);

        queue<pair<int,int>>que;
        visited[start]=true;
        que.push({start,0});
        cout<<"\nRecursive bfs traversal";
        bfs(que,visited);
        cout<<endl;

    }
    void bfs(queue<pair<int,int>>&que,vector<bool>&visited)
    {
        if (que.empty())
        return; 
            auto [n,l]=que.front();
            que.pop();
            cout<<"node: "<<n<<"level: "<<l;
            for(auto &neigh:adj[n])
            {
                if(!visited[neigh])
                {
                    que.push({neigh,l+1});
                    visited[neigh]=true;
                   
                }
            }
             bfs(que,visited);
        
    }

};
int main()
{
    int V;
    cout<<"\nEnter no of vertices";
    cin>>V;
    Graph g(V);
    for(int i=0;i<V-1;i++)
    {
        int u,v;
        cout<<"\nenter edges";
        cin>>u>>v;
        g.addEdge(u,v);
        


    }
    int s;
        cout<<"\nenter source node";
        cin>>s;
        g.dfs_rec(s);
        g.bfs_rec(s);

    return 0;
}