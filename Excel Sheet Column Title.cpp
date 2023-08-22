class Solution 
{
public:
    string convertToTitle(int columnNumber)
    {
        string title = "";
        while(columnNumber)
        {
            columnNumber -= 1;
            title += columnNumber%26 + 'A';
            columnNumber /= 26;
        }
        reverse(title.begin(), title.end());
        return title;
    }
};
