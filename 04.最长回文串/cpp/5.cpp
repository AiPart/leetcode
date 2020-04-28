class Solution {
public:
    string longestPalindrome(string s) {
        auto expandAroundCenter = [&](string& s, int left, int right) {
            while (left >=0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            // (right-1) - (left+1) + 1 => right - left - 1
            return right - left - 1; 
        };
        int start = 0, max_len = 0;
        for (int i = 0; i < s.length(); ++i) {
            int len1 = expandAroundCenter(s, i, i);
            int len2 = expandAroundCenter(s, i, i+1);
            int len = max(len1, len2);
            if (len > max_len) {
                start = i - (len - 1)/2;
                max_len = len;
            }
        }
        return s.substr(start, max_len);
    }
};
