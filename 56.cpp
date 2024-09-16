class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<int>arr(2);
        vector<vector<int>>ans;
        if(intervals.size()==0) return ans;
        sort(intervals.begin(),intervals.end());
        arr[0]=intervals[0][0];arr[1]=intervals[0][1];
        for(int i=1;i<intervals.size();i++)
        {   if(arr[1]>=intervals[i][0])
                arr[1]=max(intervals[i][1],arr[1]);
            else
            {   ans.push_back({arr[0],arr[1]});
                arr[0]=intervals[i][0];
                arr[1]=intervals[i][1];  
            }
        }
        ans.push_back({arr[0],arr[1]});
        return ans;
    }
};