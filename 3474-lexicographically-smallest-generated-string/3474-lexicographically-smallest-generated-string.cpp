class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();

        string word(n + m - 1, '?');
        vector<bool> fixed(n + m - 1, false);

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    if (word[i + j] == '?' || word[i + j] == str2[j]) {
                        word[i + j] = str2[j];
                        fixed[i + j] = true;
                    } else {
                        return "";
                    }
                }
            }
        }

        for (char &c : word) {
            if (c == '?') c = 'a';
        }

        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F') {
                bool match = true;

                for (int j = 0; j < m; j++) {
                    if (word[i + j] != str2[j]) {
                        match = false;
                        break;
                    }
                }

                if (match) {
                    bool fixedFlag = false;

                    for (int j = m - 1; j >= 0; j--) {
                        int pos = i + j;

                        if (fixed[pos]) continue;

                        for (char ch = 'a'; ch <= 'z'; ch++) {
                            if (ch != str2[j]) {
                                word[pos] = ch;
                                fixedFlag = true;
                                break;
                            }
                        }

                        if (fixedFlag) break;
                    }

                    if (!fixedFlag) return "";
                }
            }
        }

        return word;
    }
};