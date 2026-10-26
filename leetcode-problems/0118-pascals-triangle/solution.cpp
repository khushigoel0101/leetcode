class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        if (numRows == 1) return {{1}};
        
        vector<vector<int>> prevRows = generate(numRows - 1);
        vector<int> newRow(numRows, 1);
        //first and last el of each row is already 1
        for (int i = 1; i < numRows - 1; i++) {
            //prevRows.back() is the entire prev row
            newRow[i] = prevRows.back()[i - 1] + prevRows.back()[i];
        }
        
        prevRows.push_back(newRow);
        return prevRows;
    }
};
/*
if(numRows == 0) return {};
if(numRows == 1) return {{1}};
vector<vector<int>> prevrows = generate(numRows - 1);//assume we have a pascal triangle already
vector<int>newRow(numRows, 1);//create the nth row
for(int i = 1; i<numRows-1; i++){
newrow[i] = prevrow.back()[i-1] + prevrow.back()[i]; //we fill the nth row from indx 1 to n-2
}
prevrows.push_back(newrow);
ret prevrows;

*/
