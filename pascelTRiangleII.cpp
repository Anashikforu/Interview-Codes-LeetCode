/*
Author: Md Ashik Khan
Problem: Pascal's Triangle
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> getRow(int rowIndex) {
    vector<vector<int>> pasTri;
    int passValue = 1;
    for(int i=0; i<=rowIndex; i++){
        pasTri.push_back({});
        for(int j=0; j<=i; j++){
            if(i > 1 && j>0 && j<i){
                passValue = pasTri[i-1][j-1]+pasTri[i-1][j];
            }
            pasTri[i].push_back(passValue);
            passValue = 1 ;
        }
    }
    return pasTri[rowIndex];
}
 
int main(){
    int num = 4;
    vector<int> row;
    row = getRow(num);

    cout<<"Pascal Triangle Row:"<<endl;
    for(auto i: row){
        cout<<i<<endl;
    }
}
