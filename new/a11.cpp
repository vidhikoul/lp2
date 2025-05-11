#include<iostream>
using namespace std;
class Graph
{
    vector<vector<int>>adj;
    int v;
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
    
        cout<<"\nRecursive dfs with levels";
        dfs_helper(start,visited,0);
        cout<<"\n";
    }
    void dfs_helper(int node,vector<bool>&visited,int level)
    {
        visited[node]=true;
        cout<<"Node: "<<node<<" Level: "<<level;
        for(auto &neigh:adj[node])
        {
            if(!visited[neigh])
            {
                dfs_helper(neigh,visited,level+1);

            }
        }


    }
    void dfs_nonrec(int start)
    {
        stack<pair<int,int>>stk;//node,level
        vector<bool>visited(v,false);
        stk.push({start,0});
        cout<<"\nNon recursive dfs with level: ";
        while(!stk.empty())
        {
            auto [node,level]=stk.top();
            stk.pop();

            if(!visited[node])
            {
                visited[node]=true;
                cout<<"Node: "<<node<<" Level:"<<level;
                for(auto it=adj[node].rbegin();it!=adj[node].rend();it++)
                {
                    if(!visited[*it])
                    {
                        stk.push({*it,level+1});
                    }
                }

            }
        }
    }
    void bfs_nonrec(int start)
    {
        vector<bool>visited(v,false);
        queue<pair<int,int>>que;
        visited[start]=true;
        que.push({start,0});
        while(!que.empty())
        {
            auto[node,level]=que.front();
            que.pop();
            cout<<"Node: "<<node<<" Level:"<<level;
            for(auto &neigh:adj[node])
            {
                if(!visited[neigh])
                {
                    visited[neigh]=true;
                    que.push({neigh,level+1});

                }
            }
        }
        cout<<endl;
    }
    void bfs_rec(int start)
    {
        vector<bool>visited(v,false);
        queue<pair<int,int>>que;
        visited[start]=true;
        que.push({start,0});
        cout<<"\nRecursive bfs traversal";
        bfs_rec_helper(que,visited);
        cout<<endl;

    }
    void bfs_rec_helper(queue<pair<int,int>>&que,vector<bool>&visited)
    {
        auto [node,level]=que.front();
        que.pop();
        cout<<"Node: "<<node<<" Level:"<<level;
        for(auto& neigh:adj[node])
        {
            if(!visited[neigh])
            {
                visited[neigh]=true;
                que.push({neigh,level+1});
            }
        }
         bfs_rec_helper(que,visited);


    }



};
int main()
{
    return 0;
}