class BrowserHistory
{
    stack<string> currWebPage, backTrace;
    string home;
public:
    BrowserHistory(string homepage)
    {
        currWebPage.push(homepage);
        this->home = homepage;
    }

    void visit(string url)
    {
        currWebPage.push(url);
        while(backTrace.size() > 0) backTrace.pop();
    }

    string back(int steps)
    {
        while(steps-- && currWebPage.size() > 1)
        {
            backTrace.push(currWebPage.top());
            currWebPage.pop();   
        }
        string top = currWebPage.top();
        return top;
    }
    
    string forward(int steps)
    {
        while(steps-- && backTrace.size())
        {
            currWebPage.push(backTrace.top());
            backTrace.pop();
        }
        string top = currWebPage.top();
        return top;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
