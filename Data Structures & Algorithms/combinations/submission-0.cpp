class Solution {
public:
   vector<vector<int>> res;
   void bt(int start,int n,int k,vector<int> &path){
    if(path.size() == k){
        res.push_back(path);
        return;
    }
    for(int i =start;i<=n;i++){
        path.push_back(i);
        bt(i+1,n,k,path);
        path.pop_back();
    }
   }
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        bt(1,n,k,path);
        return res;
    }
};