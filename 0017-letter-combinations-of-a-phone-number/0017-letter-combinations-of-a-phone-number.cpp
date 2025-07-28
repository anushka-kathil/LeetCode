class Solution {
public:
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.empty()) return ans;
        unordered_map<char,string> m = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
         backtrack(digits, 0, "", ans, m);
         return ans;        
    }

    void backtrack(string& digits, int idx, string comb, vector<string>& ans,  unordered_map<char,string> m ){
     if (idx == digits.length()) {
            ans.push_back(comb);
            return;
        }
        
        string letters = m.at(digits[idx]);
        for (char letter : letters) {
            backtrack(digits, idx + 1, comb + letter, ans, m);

   }
   }
};