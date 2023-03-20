class Solution
{
    bool canBePlanted(int i, int n, vector<int>& flowers)
    {
        if(flowers[i] == 1) return false;
        if(i == 0) return flowers[i] == 0 && (n > 1 ? flowers[i+1] != 1 : 1);
        if(i == n-1) return flowers[i] == 0 && (n > 1 ? flowers[i-1] != 1 : 1);
        return flowers[i-1] == 0 && flowers[i+1] == 0;
    }
public:
    bool canPlaceFlowers(vector<int>& flowers, int n)
    {
        int total = 0, sz = flowers.size();
        for(int i=0;i<sz;i++)
        {
            if(canBePlanted(i, sz, flowers))
            {
                flowers[i] = 1;
                total++;
            }
        }
        return total >= n;
    }
};
