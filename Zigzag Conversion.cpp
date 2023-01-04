class Solution {
public:
    string convert(string s, int rows) {
        if(rows == 1) return s;
        string zigzag = "";
        int inc = (rows-1)*2;
        for(int r=0;r<rows;r++)
        {
            for(int i=r;i<s.size();i+=inc)
            {
                zigzag += s[i];
                if(r > 0 && r < rows-1 && i+inc-2*r < s.size())
                {
                    zigzag+=s[i+inc-2*r];
                }
            }
        }
        return zigzag;
    }
};
