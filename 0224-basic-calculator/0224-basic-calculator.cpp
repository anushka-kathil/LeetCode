class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<int> ops;
        int num = 0, sign = 1;
        nums.push(0);
        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else if (ch == '+' || ch == '-') {
                nums.top() += sign * num;
                num = 0;
                sign = (ch == '+') ? 1 : -1;
            } else if (ch == '(') {
                nums.push(0);
                ops.push(sign);
                sign = 1;
            } else if (ch == ')') {
                nums.top() += sign * num;
                num = nums.top();
                nums.pop();
                num *= ops.top();
                ops.pop();
                nums.top() += num;
                num = 0;
                sign = 1;
            }
        }

        if (num != 0)
            nums.top() += sign * num;

        return nums.top();
    }
};
