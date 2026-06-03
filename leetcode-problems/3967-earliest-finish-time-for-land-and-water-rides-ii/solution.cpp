class Solution {
    int solve(vector<int>& start1, vector<int>& duration1 , vector<int>&start2, vector<int>& duration2){
        int fin1 = INT_MAX;
        for(int i =0; i<start1.size(); i++){
            fin1 = min(fin1, start1[i] + duration1[i]);
        }

        int fin2 = INT_MAX;
        for(int i = 0; i<start2.size(); i++){
            fin2 = min(fin2,max(start2[i],fin1)+duration2[i]);
        }
        return fin2;
    }
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int l_w= solve( landStartTime,  landDuration,  waterStartTime,  waterDuration);
        int w_l = solve(  waterStartTime, waterDuration, landStartTime,  landDuration);
        return min(l_w, w_l);
    }
};
