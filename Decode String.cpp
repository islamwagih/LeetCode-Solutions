class Solution {
public:
    string decodeString(string s)
    {
        stack<char> stk;
        for(char& c:s) 
        {
            if(c == ']')
            {
                vector<char> subString;
                while(stk.top() != '[')
                {
                    subString.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();
                string strNum = "";
                while(stk.size() && stk.top() >= '0' && stk.top() <= '9')
                {
                    strNum += stk.top();
                    stk.pop();
                }
                reverse(strNum.begin(), strNum.end());
                int times = stoi(strNum), subStringSize = subString.size();
                for(int i=0;i<times;i++)
                {
                    for(int j=subStringSize-1;j>=0;j--) stk.push(subString[j]);
                }
            }else{
                stk.push(c);
            }
        }
        string ans = "";
        while(stk.size())
        {
            ans += stk.top();
            stk.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
