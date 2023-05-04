class Solution {
public:
    string predictPartyVictory(string senate)
    {
        queue<int> rque, dque;
        for(int i=0;i<senate.size();i++)
        {
            if(senate[i] == 'D') dque.push(i);
            else rque.push(i);
        }

        while(rque.size() && dque.size())
        {
            int rind = rque.front(); rque.pop();
            int dind = dque.front(); dque.pop();
            if(rind < dind) rque.push(rind + senate.size());
            else dque.push(dind + senate.size());
        }

        return rque.empty() ? "Dire":"Radiant";
        
    }
};
