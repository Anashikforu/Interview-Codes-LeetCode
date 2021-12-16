#include <iostream>
#include <vector>
using namespace std;

int main() {
    int flag = 1, x = 9,p;
    
        vector<int> nums ;
        int cop = x;
        
        while(cop > 9){
            p = cop%10;
            nums.push_back(p);
            cop = cop/10;
        }
        nums.push_back(cop);
        
        
        int size = nums.size() - 1;
        int count = 0;
        
        while(size > count ){
            if(nums[size] != nums[count]){
                flag = 0;
            }
            size--;
            count++;
        }
        
        cout<<flag<<endl;

    return 0;
}