class Solution {
public:
    bool isValid(string s) {
        stack<char> myStack;

        if(s.length()%2 != 0) {
            return false;
        }

        for(int i=0; i<s.length(); i++) {
            if(myStack.empty() != true) {
                switch(s[i]) {
                    case ')':
                        if(myStack.top() == '(') {
                            myStack.pop();
                            break;
                        } else {
                            return false;
                        }
                    case '}':
                        if(myStack.top() == '{') {
                            myStack.pop();
                            break;
                        } else {
                            return false;
                        }
                    case ']':
                        if(myStack.top() == '[') {
                            myStack.pop();
                            break;
                        } else {
                            return false;
                        }
                    case '(':
                        myStack.push(s[i]);
                        break;

                    case '{':
                        myStack.push(s[i]);
                        break;

                    case '[':
                        myStack.push(s[i]);
                        break;

                    default:
                        continue;
                }
            } else {
                myStack.push(s[i]);
            }
        }

        return myStack.empty();   
    }
};