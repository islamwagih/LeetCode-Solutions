class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2)
    {
        unordered_map<int, int> mp;
        for(int i=0;i<nums1.size();i++)
        {
            mp[nums1[i]] = i+1;
        }

        stack<int> monStack;
        vector<int> ans(nums1.size(), -1);

        for(int i=0;i<nums2.size();i++)
        {
            while(monStack.size() && monStack.top() < nums2[i])
            {
                ans[mp[monStack.top()]-1] = nums2[i];
                monStack.pop();
            }
            if(mp.find(nums2[i]) != mp.end()) monStack.push(nums2[i]);
        }

        return ans;
    }
};
