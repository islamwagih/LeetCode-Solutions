class Solution {
public:
    vector<int> findClosestElements(vector<int> arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int sz = arr.size();
        for(int i=0;i<sz;i++){
            pq.push({abs(arr[i]-x), i});
        }
        vector<int> vec;
        while(k--){
            vec.push_back(arr[pq.top().second]);
            pq.pop();
        }
        sort(vec.begin(), vec.end());
        return vec;
    }
};
