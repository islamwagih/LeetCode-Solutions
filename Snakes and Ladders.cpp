class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int n = board.size();
        vector<pair<int, int>> cells(n * n + 1);
        int label = 1;
        vector<int> columns(n);
        for(int i=0;i<n;i++) columns[i] = i;
        for (int row = n - 1; row >= 0; row--)
        {
            for (int& column : columns)
            {
                cells[label++] = {row, column};
            }
            reverse(columns.begin(), columns.end());
        }
        vector<int> dist(n * n + 1, -1);
        queue<int> q;
        dist[1] = 0;
        q.push(1);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            //cuur has numbers in range [curr+1, min(curr+n, n*n)] we will use the label
            //to get the actual row col in board
            for (int next = curr + 1; next <= min(curr + 6, n * n); next++)
            {
                int row = cells[next].first, col = cells[next].second;
                //if it has a ladder use it, else use label
                int dest = board[row][col] != -1 ? board[row][col] : next;
                if (dist[dest] == -1)
                {
                    dist[dest] = dist[curr] + 1;
                    q.push(dest);
                }
            }
        }
        return dist[n * n];
    }
};
