#include<iostream>
#include<vector>
using namespace std;

//bruteforce - O(n^2)
class Solution {
public :
    vector<int> twoSum(vector<int>& nums,int target){
        int n=nums.size();
        for(int i=0;i<n-1;n++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};

//Using hash table O(n)
class Solution1{
public :
    vector<int> twoSum(vector<int>& nums,int target)
    {
        unordered_map<int,int> mp;
        vector<int> res;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])==mp.end())
                mp[nums[i]] = i;
            if(mp.find(target - nums[i])!=mp.end() && i!=mp[target-nums[i]])
            {
                res.push_back(i);
                res.push_back(mp[targets-num[i]]);
                break;
            }
        }
        return res;
    }
};

