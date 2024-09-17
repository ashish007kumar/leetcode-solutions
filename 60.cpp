class Solution {
public:
    string getPermutation(int n, int k) {
        string st(n,'0');
        int fact=1;
        for(int i=1;i<=n;i++){
            fact*=i;
            st[i-1]+=(i);
        }
        for(int i=0;i<n;i++){
            int block_num=fact/(n-i);
            fact/=(n-i);
            int first_index=i+(k-1)/(block_num);
            char c=st[first_index];
            k=k-(((k-1)/(block_num))*(block_num));
            for(int j=first_index;j>=i+1;j--){
                st[j]=st[j-1];
            }
            st[i]=c;
            cout<<st<<" "<<k<<" ";
        }
        return st;
    }
};