class Solution
{
    string order;
    bool isALessThanB(string& a, string& b)
    {
        int n = min(a.size(), b.size());
        for(int i=0;i<n;i++)
        {
            int aind = order.find(a[i]), bind = order.find(b[i]);
            if(bind != aind) return aind <= bind;
        }
        return a.size() <= b.size();
    }
public:
    bool isAlienSorted(vector<string>& words, string order)
    {
        this->order = order;
        int n = words.size();
        for(int i=0;i<n-1;i++)
        {
            if(!isALessThanB(words[i], words[i+1])) return false;
        }
        return true;
    }
};
