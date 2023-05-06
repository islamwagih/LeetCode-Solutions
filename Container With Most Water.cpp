class Solution {
public:
    int maxArea(vector<int>& height)
    {
        int n = height.size();
        int left = 0, right = n-1;
        int ans = min(height[left], height[right])*(right - left);
        while(left < right)
        {
            if(height[left] < height[right]) left++;
            else right--;
            ans = max(ans,min(height[left], height[right])*(right - left));
        }
        return ans;
    }
};
