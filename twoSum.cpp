class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int, int> sum;
        vector<int> output;
        for(int i=0; i<nums.size(); i++)
        {
            int rest = target - nums[i];
            if(sum.find(rest)!=sum.end() && sum.find(rest)->second !=i){
                output.push_back(sum.find(rest)->second);
                output.push_back(i);
            }
            sum.insert(pair<int,int>(nums[i],i));
        }
        return output;
    }
};
