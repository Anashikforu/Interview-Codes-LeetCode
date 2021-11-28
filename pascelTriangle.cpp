/*
Author: Md Ashik Khan
Problem: Pascal's Triangle
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> pasTriangle;
    int pasVal = 1;

    for(int i=0; i<numRows; i++){
        pasTriangle.push_back({});
        for(int j=0; j<=i; j++){
            if(i > 1 && j!=0 && j != i){
                pasVal = pasTriangle[i-1][j-1]+pasTriangle[i-1][j];
            }
            pasTriangle[i].push_back(pasVal);
            pasVal = 1;
        }
    }

    return pasTriangle;
}
 
int main(){
    int num = 1;
    vector<vector<int>> pasTriangle;
    pasTriangle = generate(num);

    cout<<"Pascal Triangle:"<<endl;
    for(int i=0; i<pasTriangle.size(); i++){
        for(int j=0; j<pasTriangle[i].size(); j++){
            cout<<pasTriangle[i][j]<<" ";
        }
        cout<<endl;
    }
}
