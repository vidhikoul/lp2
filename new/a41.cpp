#include<iostream>
#include<unordered_set>
using namespace std;

void solve(vector<string>&board,int row,unordered_set <int>& cols,unordered_set <int>& diags,unordered_set <int>& antidiags,int n,vector<vector<string> >&result)
{
    if(row==n)
    {
        result.push_back(board);
        return;

    }
    for(int col=0;col<n;col++)
    {
        int diag=row-col;
        int antidiag=row+col;
        if(cols.count(col)||diags.count(diag)||antidiags.count(antidiag))
        {
            continue;
        }
        board[row][col]='Q';
        cols.insert(col);
        diags.insert(diag);
        antidiags.insert(antidiag);

        solve(board,row+1,cols,diags,antidiags,n,result);

        board[row][col]='.';
        cols.erase(col);
        diags.erase(diag);
        antidiags.erase(antidiag);




    }

}
int main()
{
    int n;
    cout<<"\nEnter no of queens:";
    cin>>n;
    vector<vector<string> >result;
    vector<string>board(n,string(n,'.'));
    unordered_set <int> cols,diag,antidiag;
    solve(board,0,cols,diag,antidiag,n,result);
    for (int i = 0; i < result.size(); i++) 
    {
        cout << "\nSolution " << i + 1 << ":" << endl;
        for (int j = 0; j < n; j++) 
        {
            cout << result[i][j] << endl;
        }
    }


}