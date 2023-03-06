class Solution
{
    bool ok(int i, vector<int>& arr, int k)
    {
        return arr[i] - (i+1) < k;
    }
public:
    int findKthPositive(vector<int>& arr, int k)
    {
        int low = 0, high = arr.size() - 1;
        while(low <= high)
        {
            int mid = low+(high-low+1)/2;
            if(ok(mid, arr, k))
            {
                low = mid+1;
            }else
            {
                high = mid-1;
            }
        }
        return low+k;
    }
};
