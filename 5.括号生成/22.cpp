class Solution {
public:
    void dfs(vector<string>& res, string str, int l, int r) {
        if (l < 0 || r < 0 || l > r) {
            return;
        }
        if (l == 0 && r == 0) {
            res.push_back(str);
        }
        dfs(res, str+"(", l-1, r);
        dfs(res, str+")", l, r-1);
    }
    
    vector<string> generateParenthesis(int n) {

        vector<string> res;
        dfs(res, "", n, n);
        return res;
    }
};
