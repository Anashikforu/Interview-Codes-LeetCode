/*
Author: Md Ashik Khan
Problem: Number od Iceland
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void chceked(vector<vector<char>>& grid,int i,int j){
    if(!(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]=='1')){
        return;
    }

    int m = grid.size();
    int n = grid[0].size();

    grid[i][j] = '2';
    if(i<m-1){
        chceked(grid,i+1,j);
    }
    if(i>0){
        chceked(grid,i-1,j);
    }
    if(j<n-1){
        chceked(grid,i,j+1);
    }
    if(j>0){
        chceked(grid,i,j-1);
    }
}

int numIslands(vector<vector<char>>& grid) {
    vector<vector<char>> visited = grid;
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(grid[i][j] == '1'){
                chceked(grid,i,j);
                count++;
            }
        }
    }

    return count;
}

    

int main(){
    vector<vector<char>> iceland = 
    {
        {'1','1','0','0','0'}, 
        {'1','1','0','0','0'}, 
        {'0','0','1','0','0'}, 
        {'0','0','0','1','1'}
    };
    int nmbr = numIslands(iceland);
    cout<<nmbr<<endl;
    return 0;
}
 