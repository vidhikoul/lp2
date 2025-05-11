#include<iostream>
using namespace std;
class Node
{
    public:
    int x,y,g,h;
    Node* parent;
    Node(int x,int y,int g,int h,Node* parent)
    {
        this->x=x;
        this->y=y;
        this->g=g;
        this->h=h;
        this->parent=parent;

    }
    int const f() const{
        return g+h;
    }
    bool operator>(const Node& other)const
    {
        return f()>other.f();
    }
};
bool isvalid(int x,int y,int m,int n,vector<vector<int>>&grid)
{
    return (x>=0 && x<m && y>=0 &&y<n && grid[x][y]==0);
}
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
int heuristicdistance(int x1,int x2,int y1,int y2)
{
    return (abs(x1-x2)+abs(y1-y2));
}
void reconstructpath(Node* end)
{
    vector<pair<int,int>>path;
    while(end)
    {
        path.push_back({end->x,end->y});
        end=end->parent;

    }
    reverse(path.begin(),path.end());
    cout<<"Path is:";
    for(auto & p:path)
    {
        cout<<"("<<p.first<<","<<p.second<<")";

    }
}
struct CompareNodes
{
    bool operator()(Node *a, Node *b)
    {
        return a->f() > b->f();
    }
};
void aisearch(vector<vector<int>>grid,pair<int,int>start,pair<int,int>goal)
{
    int m=grid.size();
    int n=grid[0].size();
    priority_queue<Node*,vector<Node*>,CompareNodes>pq;
    vector<vector<bool>>visited(m,vector<bool>(n,false));
    pq.push(new Node(start.first,start.second,0,heuristicdistance(start.first,start.second,goal.first,goal.second),nullptr));

    while(!pq.empty())
    {
        Node* curr=pq.top();
        pq.pop();
        if(visited[curr->x][curr->y])
        {
            continue;
        }
        visited[curr->x][curr->y]=true;
        if(curr->x==goal.first && curr->y==goal.second)
        {
            cout<<"\nReached to goal with fn: ";
            curr->f();
            cout<<"\nPath is:";
            reconstructpath(curr);
            return;

        }
        for(int d=0;d<4;d++)
        {
            int nx=curr->x+dx[d];
            int ny=curr->y+dy[d];
            if(isvalid(nx,ny,m,n,grid))
            {
                int newg=curr->g+1;
                int newh=curr->h+heuristicdistance(nx,ny,goal.first,goal.second);
                pq.push(new Node(nx,ny,newg,newh,curr));
            }

        }

    }
    cout << "No path found." << endl;
}

int main() {
    int m, n;
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> grid(m, vector<int>(n));
    cout << "Enter grid values (0 for free, 1 for obstacle):" << endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    pair<int, int> start, goal;
    cout << "Enter start coordinates (x y): ";
    cin >> start.first >> start.second;
    cout << "Enter goal coordinates (x y): ";
    cin >> goal.first >> goal.second;

    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Display Grid\n";
        cout << "2. Run A* Search\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Grid:\n";
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    cout << grid[i][j] << " ";
                }
                cout << endl;
            }
            break;

        case 2:
            aisearch(grid, start, goal);
            break;

        case 3:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 3);

    return 0;
}