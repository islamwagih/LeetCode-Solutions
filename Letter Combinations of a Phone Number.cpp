class Solution
{
    int n;
    vector<string> ans;
    vector<char> graph[10];
    string digits;
    void dfs(int i, string num)
    {
        if(i >= n)
        {
            if(num.size() > 0) ans.push_back(num);
            return;
        }
        for(char digit:graph[digits[i] - '0'])
        {
            dfs(i+1, num+digit);
        }
    }
public:
    vector<string> letterCombinations(string digits)
    {
        this->ans.clear();
        this-> n = digits.size();
        this->digits = digits;
        char currChar = 'a';
        for(int i=2;i<=9;i++)
        {
            switch(i)
            {
                case 9:
                { 
                    while(currChar <= 'z')
                    {
                        graph[9].push_back(currChar++);
                    }
                    break;
                }
                case 7:
                {
                    while(currChar <= 's')
                    {
                        graph[7].push_back(currChar++);
                    }
                    break;
                }
                default:
                {
                    for(int j=0;j<3;j++)
                    {
                        graph[i].push_back(currChar++);
                    }
                }
            }
        }
        dfs(0, "");
        return ans;
    }
};
