class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates)
    {
        long long cost = 0;
        priority_queue<int, vector<int>, greater<int>> head, tail;
        if(2*candidates >= costs.size())
        {
            for(int cost:costs) head.push(cost);
            while(k--)
            {
                cost += head.top(); head.pop();
            }
        }else
        {
            int left, right;
            for(left=0; left<candidates; left++)
            {
                head.push(costs[left]);
            }

            for(right=costs.size()-1; right >= costs.size()-candidates; right--)
            {
                tail.push(costs[right]);
            }

            while(k--)
            {
                if(tail.empty() || (head.size() && head.top() <= tail.top()))
                {
                    cost += head.top(); head.pop();
                    if(left <= right) head.push(costs[left++]);
                }else
                {
                    cost += tail.top(); tail.pop();
                    if(left <= right) tail.push(costs[right--]);
                }  
            }
        }

        return cost;
        
    }
};
