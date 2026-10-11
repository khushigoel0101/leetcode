class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxdepth = 0; 
        for(char c: s){
            if(c==')'){
                depth--;
                continue;
            }
            if(c!='(') continue;
            depth++;
            if(depth>maxdepth)maxdepth= depth;
        }
        return maxdepth;
    }
};
