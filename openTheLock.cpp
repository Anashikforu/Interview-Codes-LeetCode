/*
Author: Md Ashik Khan
Problem: Open The Lock
*/

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std;


int openLock(vector<string>& deadends, string target) {
        set<string> deadlocks{deadends.begin(), deadends.end()};
        set<string> visited;
        queue<string> store;
        if (!deadlocks.count("0000")) {
            store.push("0000");
        }
        vector<int> dirs{-1, 1};
        int depth = 0;
        while (!store.empty()) {
            int count = store.size();
            for (int i = 0; i < count; ++ i) {
                string lock = store.front();
                store.pop();
                if (lock == target) {
                    return depth;
                }
                for (int j = 0; j < lock.size(); ++ j) {
                    for (auto dir : dirs) {
                    auto tlock = lock;
                    tlock[j] = (lock[j] - '0' + dir + 10) % 10 + '0';
                    if (!visited.count(tlock) && !deadlocks.count(tlock)) {
                        store.push(tlock);
                        visited.insert(tlock);
                    }
                    }
                }
            }
            ++ depth;
        }
        return -1;
    }
    

int main(){
    vector<string> deadends = {"0201","0101","0102","1212","2002"};
    string target = "0202";
    
    int nmbr = openLock(deadends,target);
    cout<<nmbr<<endl;
    return 0;
}
 