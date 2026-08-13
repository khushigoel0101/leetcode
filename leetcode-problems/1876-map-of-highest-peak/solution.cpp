class Solution {
public:
    typedef pair<int,int> P;
    vector<vector<int>> direction {{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> height(m, vector<int>(n, -1));
        queue<P>q;
        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(isWater[i][j]==1){
                    height[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int s = q.size();
            while(s--){
                P curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;

                for(auto dir: direction){
                    int new_i = i+dir[0];
                    int new_j = j+dir[1];

                    if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && height[new_i][new_j]==-1){
                        height[new_i][new_j] = height[i][j] + 1;
                        q.push({new_i,new_j});
                    }
                }
            }
        }
        return height;
    }
};
