class Solution {
public:
    int largestRectangleArea(vector<int>& A) {
         int n=A.size();
    stack<int>s;
    vector<int>nsr;
    for(int i=n-1;i>=0;i--)
    {
        if(s.empty())
        {
            nsr.push_back(n);
        }
        else if(A[s.top()]<A[i])
        {
            nsr.push_back(s.top());
        }
        else if(A[s.top()]>=A[i])
        {
            while(!s.empty()&&A[s.top()]>=A[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                nsr.push_back(n);
            }
            else
            nsr.push_back(s.top());
        }
        s.push(i);
    }
    reverse(nsr.begin(),nsr.end());
    stack<int>ss;
    vector<int>nsl;
    for(int i=0;i<n;i++)
    {
        if(ss.empty())
        {
            nsl.push_back(-1);            
        }
        else if(A[ss.top()]<A[i])
        {
            nsl.push_back(ss.top());
        }
        else if(A[ss.top()]>=A[i])
        {
            while(!ss.empty()&&A[ss.top()]>=A[i])
            ss.pop();
            if(ss.empty())
            {
                nsl.push_back(-1);
            }
            else
            nsl.push_back(ss.top());
        }
        ss.push(i);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,(nsr[i]-nsl[i]-1)*A[i]);
    }
    return ans;  n=A.size();
    stack<int>s;
    vector<int>nsr;
    for(int i=n-1;i>=0;i--)
    {
        if(s.empty())
        {
            nsr.push_back(n);
        }
        else if(A[s.top()]<A[i])
        {
            nsr.push_back(s.top());
        }
        else if(A[s.top()]>=A[i])
        {
            while(!s.empty()&&A[s.top()]>=A[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                nsr.push_back(n);
            }
            else
            nsr.push_back(s.top());
        }
        s.push(i);
    }
    reverse(nsr.begin(),nsr.end());
    stack<int>ss;
    vector<int>nsl;
    for(int i=0;i<n;i++)
    {
        if(ss.empty())
        {
            nsl.push_back(-1);            
        }
        else if(A[ss.top()]<A[i])
        {
            nsl.push_back(ss.top());
        }
        else if(A[ss.top()]>=A[i])
        {
            while(!ss.empty()&&A[ss.top()]>=A[i])
            ss.pop();
            if(ss.empty())
            {
                nsl.push_back(-1);
            }
            else
            nsl.push_back(ss.top());
        }
        ss.push(i);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=max(ans,(nsr[i]-nsl[i]-1)*A[i]);
    }
    return ans;
    }
};
