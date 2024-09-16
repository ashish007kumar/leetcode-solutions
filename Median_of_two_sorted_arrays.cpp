class Solution {
public:
    double find(vector<int>& nums1, vector<int>& nums2)
    {
           int n = nums1.size(),m = nums2.size();
     
        int l = 0,h = n;
        while(l<=h)
        {
            int part1= (l+h)/2;
            int part2=(n+m+1)/2 - part1;
            
            int l1=(part1==0)? INT_MIN: nums1[part1-1];
            int r1= (part1==n)? INT_MAX: nums1[part1];
            int l2=(part2==0)? INT_MIN: nums2[part2-1];
            int r2= (part2==m)? INT_MAX: nums2[part2];
            
            if(l1<=r2 && l2<=r1)
            {
                if((n+m)%2)
                    return (double)max(l1,l2);
                else
                {
                    return (double)(max(l1,l2)+ min(r1,r2))/2.0;
                }
            }
            
            else if(l1>r2)
                h=part1-1;
            else
                l=part1+1;
        }
        return 0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        if(n>m)return find(nums2,nums1);
        else return find(nums1,nums2);
        
    }
    
};