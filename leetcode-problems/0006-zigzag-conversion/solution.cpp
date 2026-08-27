class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string>rows(min((numRows), int(s.length())));
        int i = 0;
        bool d = false;
        for(char c: s){
            rows[i] += c;
            if(i==0 || i== numRows-1) d = !d;
            i += d? 1:-1;
        }
        string res = "";
        for(string row: rows){
            res += row;
        }
        return res;
    }
};
