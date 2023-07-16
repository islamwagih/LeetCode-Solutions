class Solution
{
    int n;
    vector<vector<string>> people;
    map<string, int> mp;
    vector<int> ans;
    vector<vector<int>> dp;
    int getDecimalWithNBits(int bits)
    {
       return (1 << bits) - 1;
    }

    bool checkIthBit(int num, int pos)
    {
        return (num>>pos) & 1;
    }

    void flipIthBit(int& num, int pos)
    {
        num ^= (1 << pos);
    }

    int getSkillIndex(string& s)
    {
        return mp[s] - 1;
    }

    int minNum(int i, int mask)
    {
        if(mask == 0) return 0;
        if(i == n) return 1e9;
        if(dp[mask][i] != -1) return dp[mask][i];
        int op1 = minNum(i+1, mask);
        int newMask = mask;
        for(string& skill:people[i])
        {
            int ind = getSkillIndex(skill);
            if(checkIthBit(newMask, ind))
            {
                flipIthBit(newMask, ind);
            }
        }
        int op2 = 1+minNum(i+1, newMask);
        return dp[mask][i] = min(op1, op2);
    }

    void getAnswer(int i, int mask)
    {
        if(mask == 0) return;
        if(i == n) return;
        int op1 = minNum(i+1, mask);
        int newMask = mask;
        for(string& skill:people[i])
        {
            int ind = getSkillIndex(skill);
            if(checkIthBit(newMask, ind))
            {
                flipIthBit(newMask, ind);
            }
        }
        int op2 = 1+minNum(i+1, newMask);
        if(op1 < op2)
        {
            getAnswer(i+1, mask);
        }else
        {
            ans.push_back(i);
            getAnswer(i+1, newMask);
        }
    }

public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) 
    {
        this->ans.clear();
        this->people = people;
        this->n = people.size();
        this->mp.clear();
        int cnt = 1;
        for(string& skill:req_skills)
        {
            mp[skill] = cnt++;
        }
        int mask = getDecimalWithNBits(cnt-1);
        this->dp = vector<vector<int>>(mask+1, vector<int>(n+1, -1));
        int number = minNum(0, mask);
        getAnswer(0, mask);
        return this->ans;
    }
};
