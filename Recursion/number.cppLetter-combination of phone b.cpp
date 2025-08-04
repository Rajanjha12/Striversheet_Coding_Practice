class Solution {
public:
   void phoneComb(string  digits , int idx , string op , vector<string>& res , string mapping[]) {
        if (idx >= digits.length()) {
            res.push_back(op);
            return;
        }

        int idxPointsToNum = digits[idx] - '0';
        string val = mapping[idxPointsToNum];

        for (int i = 0; i < val.length(); i++) {
            op.push_back(val[i]);

            phoneComb(digits , idx + 1 , op , res , mapping);

            op.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string op = "";
        
        if (digits.length() == 0) {
            return res;
        }
        
        string mapping[10] = {"" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};

        phoneComb(digits , 0 , op , res , mapping);

        return res;
    }
};
