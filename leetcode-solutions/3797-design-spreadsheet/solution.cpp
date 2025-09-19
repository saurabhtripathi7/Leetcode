class Spreadsheet {
public:
    vector<vector<int>>sheet;

    Spreadsheet(int rows) {
        sheet.assign(rows,vector<int>(26,0));
    }
    
    void setCell(string cell, int value) {
        int row = stoi(cell.substr(1)) - 1;
        int col = cell[0] - 'A';
        sheet[row][col] = value;
    }
    
    void resetCell(string cell) {
        int row = stoi(cell.substr(1)) - 1;
        int col = cell[0] - 'A';
        sheet[row][col] = 0;
    }
    int solve(string s){
        if(isdigit(s[0])){
            return stoi(s);
        }

        int row = stoi(s.substr(1)) - 1;
        int col = s[0] - 'A';
        return sheet[row][col];
    }
    int getValue(string formula) {
        string s = formula.substr(1);
        int plusIdx = s.find('+');

        string left = s.substr(0,plusIdx);
        string right = s.substr(plusIdx+1);

        return solve(left) + solve(right);
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
