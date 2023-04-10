class Solution {
    bool isOpen(char c)
    {
        return c == '(' || c == '{' || c == '[';
    }
    char reverse(char c)
    {
        switch(c)
        {
            case ']':return '[';
            case '}':return '{';
            case ')':return '(';
        }
        return '-1';
    }
public:
    bool isValid(string s)
    {
        stack<char> open;
        for(char c:s)
        {
            if(isOpen(c))
            {
                open.push(c);
            }else
            {
                if(open.empty() || reverse(c) != open.top()) return false;
                open.pop();
            }
        }
        return open.empty();
    }
};
