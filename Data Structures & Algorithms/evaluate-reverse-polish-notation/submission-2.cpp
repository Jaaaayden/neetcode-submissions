class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // bro why didn't they just say reverse polish notation was postfix...
        stack<int> stk;
        
        // we want to push every token we see until it's an op

        int c1;
        int c2;
        for (string token : tokens)
        {
            if (token.size() == 1 && !isdigit(token[0])) {
                int c1 = stk.top(); stk.pop();
                int c2 = stk.top(); stk.pop();
                
                switch (token[0]) {
                    case '+': stk.push(c2 + c1); break;
                    case '-': stk.push(c2 - c1); break;
                    case '*': stk.push(c2 * c1); break;
                    case '/': stk.push(c2 / c1); break;
                }
            } else {
                stk.push(stoi(token));
            }
        }

        return stk.top();
    }
};
