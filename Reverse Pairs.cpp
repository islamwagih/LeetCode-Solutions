#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<long long, null_type,less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update>
 
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        ordered_set st;
        int pairs = 0, n = nums.size();
        for(long long i:nums)
        {
            pairs += st.order_of_key(-2*i);
            st.insert(-i);
        }
        return pairs;
    }
};
