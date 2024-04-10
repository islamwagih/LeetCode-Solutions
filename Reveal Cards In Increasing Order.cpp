class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) 
    {
        sort(deck.begin(), deck.end());
        queue<int> indxs;
        int sz = deck.size();
        vector<int> result(sz);
        for(int i=0;i<sz;i++) indxs.push(i);
        int k = 0;
        while(indxs.size())
        {
            int insert = indxs.front(); indxs.pop();
            if(indxs.size())
            {
                int skip = indxs.front(); indxs.pop();
                indxs.push(skip);
            }
            result[insert] = deck[k++]; 
        }
        return result;    
    }
};
