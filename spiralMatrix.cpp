/*
Author: Md Ashik Khan
Problem: Spiral Matrix
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> spiralArr = {};
    if(matrix.size() == 0){
        return spiralArr;
    }
    int row = matrix.size();
    int col = matrix[0].size();
    int num = row+col -1 ;
    if(row == 1){
        num = 1;
    }
    if(row == 2 && col > 1){
        num = 3;
    }
    if(row == 3 && col > 1){
        num = 5;
    }
    if(col == 1){
        num = 2;
    }
    if(col == 2 && row > 1){
        num = 4;
    }
    int x=0,y=0,step=0;

    for(int i =0; i<num; i++){
        step = i/4;
        if(i%4 == 0){
            x=step;
            y=step;
            while ( x >= 0 && y < col - step)
            {
                spiralArr.push_back(matrix[x][y++]);
            }
        }
        if(i%4 == 1){
            y=y-1;
            x=x+1;
            while (x < row - step  && y >= 0 )
            {
                spiralArr.push_back(matrix[x++][y]);
            }
        }
        if(i%4 == 2){
            x=x-1;
            y=y-1;
            while (x <= row && y >= 0 + step  )
            {
                spiralArr.push_back(matrix[x][y--]);
            }
        }
        if(i%4 == 3){
            x=x-1;
            y=y+1;
            while (x > 0 + step && y >= 0 )
            {
                spiralArr.push_back(matrix[x--][y]);
            }
        }
        
    }

    return spiralArr;
}
 
int main(){
    vector<vector<int>> nums= {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15}};
    vector<int> spiralArr;
    spiralArr = spiralOrder(nums);

    cout<<"Spiral Array:"<<endl;
    for(int i=0; i<spiralArr.size(); i++){
        cout<<spiralArr[i]<<endl;
    }
}
