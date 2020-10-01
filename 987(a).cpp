
void solve(TreeNode * root, map<int,vector<pair<int,int>>>&mp , int hd, int depth){    
    if(root==NULL){
        return ;
    }
    mp[hd].push_back({depth,root->val});
    solve(root->left , mp,hd-1,depth+1);
    solve(root->right,mp,hd+1,depth+1);     
}


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>A;
        if(root==NULL){
            return A;
        }
        
        map<int,vector<pair<int,int>>>mp;
        solve(root,mp,0,0);
        
        for(auto it=mp.begin();it!=mp.end();it++){
            sort(it->second.begin(),it->second.end());
            vector<int>B;
            for(int i=0;i<it->second.size();i++){
                B.push_back(it->second[i].second);
            }
            
            A.push_back(B);
                     
        }
         
    return A;    
        
    }
};