//https://leetcode.com/problems/combination-sum/
//Difficulty Level: Medium
//Tags: Array, Backtracking
//since we have to print all, and not just count or max or min, we won't use DP but backtracking

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        
        //Note that we don't have duplicates in the array, else we had to delete the duplicates here bcoz 
        //we can already take each element multiple times, so duplicate elements don't make a difference
        
        int index = candidates.size()-1;
        while(index >=0 && candidates[index] > target)
        {
            index--;
        }
        
        vector<int> v;
        vector<vector<int>> res;  //stores result
        backtrack(candidates, target, 0, index, v, res);
        return res;
    }
    
    void backtrack(vector<int> candidates, int target, int curr_sum, int index, vector<int> v, vector<vector<int>>& res)
    {
        if(curr_sum == target)     //if the sum of elements of v add up to target, push v to result vector
        {
            res.push_back(v);
            return;
        }
        
        //check all the elements <= target - curr_sum
        for(int i=index; i>=0; i--)
        {
            curr_sum += candidates[i];
            
            if(curr_sum > target)    //don't include the element if sum is exceeding the target
            {
                curr_sum -= candidates[i];
                continue;
            }
            v.push_back(candidates[i]);
            
            //backtrack to find rest of the elements of v
            //note that we have passed 'i' and not 'i+1' since we could include the same element any no. of times
            backtrack(candidates, target, curr_sum, i, v, res);   
            
            curr_sum -= candidates[i];
            v.pop_back();
        }
    }
};