class Solution {
public:
std::string toBinary(int n)
{
    std::string r;
    while(n!=0) {r=(n%2==0 ?"0":"1")+r; n/=2;}
    return r;
}
    int minBitFlips(int start, int goal) {
        string x = toBinary(start^goal);
        int steps =0;
        for(int i =0;i<x.length();i++){
            if(x[i]!='0'){
                steps++;
            }
        }
        return steps;
    }
};
