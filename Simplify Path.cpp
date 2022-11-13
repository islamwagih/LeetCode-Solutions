class Solution {
public:
    string simplifyPath(string path)
    {
        stack<string> shortPath;
        int pathSize = path.size();
        int i = 0;
        while(i < pathSize)
        {
            if(path[i] == '/')
            {
                i++;
                continue; 
            }
            string token = "";
            while(i < pathSize && path[i] != '/') { token += path[i++]; }
            if(token == ".") { continue; }
            else if(token == "..") { if(shortPath.size()) { shortPath.pop(); } }
            else { shortPath.push(token); }
        }
        if(shortPath.size() == 0) return "/";
        string ans = "";
        while(shortPath.size()) 
        {
            ans = "/" + shortPath.top() + ans;
            shortPath.pop();
        }
        return ans;
    }
};
