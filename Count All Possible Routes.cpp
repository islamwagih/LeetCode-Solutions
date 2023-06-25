class Solution
{
    int finish;
    vector<int> locs;
    vector<vector<int>> dp;
    const int mod = 1e9+7;

    int count(int currCity, int remFuel)
    {
        if(remFuel < 0) return 0;

        int& memo = dp[currCity][remFuel];
        if(memo != -1) return memo;

        int cnt = currCity == finish ? 1:0;
        for(int nextCity = 0; nextCity < locs.size(); nextCity++)
        {
            if(nextCity != currCity)
            {
                int fuelCost = abs(locs[currCity] - locs[nextCity]);
                cnt = (cnt%mod + count(nextCity, remFuel - fuelCost)%mod)%mod;
            }
        }
    
        return memo = cnt;
    }
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        this->finish = finish;
        this->locs = locations;
        this->dp = vector<vector<int>>(locations.size(), vector<int>(fuel+1, -1));
        return count(start, fuel);        
    }
};
