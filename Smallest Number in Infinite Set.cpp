class SmallestInfiniteSet
{
    int top;
    set<int> pq;
public:
    SmallestInfiniteSet():top(1){}
    int popSmallest()
    {
        int smallest;
        if(pq.empty() || (*pq.begin()) > top)
        {
            smallest = top++;
        }else
        {
            smallest = *pq.begin();
            pq.erase(smallest);
        }
        return smallest;
    }
    
    void addBack(int num)
    {
        if(num >= top) return;
        pq.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
