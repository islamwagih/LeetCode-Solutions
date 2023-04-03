class Solution
{
public:
    vector<int> successfulPairs(vector<int>& spells, 
                                vector<int>& potions, 
                                long long success)
    {
        int maxSpell = *max_element(spells.begin(), spells.end());
        vector<int> spellEff(maxSpell+1, 0);
        int sf = spellEff.size();
        for(int potion:potions)
        {
            long long spellFrom = ceil(success/(double)potion);
            if(spellFrom < (long long) sf)
            {  
                spellEff[(int)spellFrom]++;
            }
        }
        for(int i=1;i<sf;i++)
        {
            spellEff[i] += spellEff[i-1];
        }
        int n = spells.size();
        vector<int> pairs(n);
        for(int i=0;i<n;i++)
        {
            pairs[i] = spellEff[spells[i]];
        }
        return pairs;
    }
};
