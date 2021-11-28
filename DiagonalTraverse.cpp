/*
Author: Md Ashik Khan
Problem: Diagonal Traverse
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    vector<int> diagonal = {};
    if(mat.size() == 0){
        return diagonal;
    }
    int row = mat.size();
    int col = mat[0].size();

    int num = row+col-1,x,y;

    for(int i =0; i<num; i++){
        if(i%2 == 0){
            if(i<row){
                x=i;
                y=0;
            }else{
                x=row-1;
                y=i-row+1;
            }
            while(x >= 0 && y < col ){
                diagonal.push_back(mat[x--][y++]);
            }
        }else{
            if(i<col){
                x=0;
                y=i;
            }else{
                x=i-col+1;
                y=col-1;
            }
            while(x < row && y >= 0 ){
                diagonal.push_back(mat[x++][y--]);
            }
        }
    }
    return diagonal;
}
 
int main(){
    vector<vector<int>> nums= {{1,2},{3,4}};
    vector<int> largest;
    largest = findDiagonalOrder(nums);

    cout<<"largest Index in an Array:"<<endl;
    for(int i=0; i<largest.size(); i++){
        cout<<largest[i]<<endl;
    }
}
