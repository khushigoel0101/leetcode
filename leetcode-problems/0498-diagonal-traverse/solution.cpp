class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
       map<int, vector<int>>dig;
       vector<int> res;
       for(int i =0; i<m; i++){
        for(int j =0; j<n; j++){
            dig[i+j].push_back(mat[i][j]);
        }
       }
       bool flip = true;
       for(auto &it: dig){
        if(flip){
            reverse(it.second.begin(), it.second.end());
        }
        for(int &num: it.second){
        res.push_back(num);
       }

         flip = !flip;
       }

       return res;
      
    }

};

