class Solution
{
public:
    string removeStars(string s)
    {
        string build = "";
        for(char c:s)
        {
            if(c == '*')
            {
                build.pop_back();
                continue;
            }
            build += c;
        }
        return build;
    }
};
