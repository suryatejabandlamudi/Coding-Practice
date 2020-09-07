class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        int level = 0;
        
        unordered_map<int, vector<pair<int,int>>> mp;
        
        for (auto x: flights)
        {
            mp[x[0]].emplace_back(x[1],x[2]);
        }
        int ans = INT_MAX;
        queue<pair<int,int>> q;
        q.push({src,0});
        
        while(!q.empty())
        {
            int n = q.size();
            
            for(int i=0; i<n; i++)
            {
                auto curr = q.front();
                q.pop();
                
                if(curr.first == dst)
                {
                    ans = min(ans, curr.second);
                }
                
                for(auto x:mp[curr.first])
                {
                    if(curr.second + x.second <= ans)
                    {
                        q.push({x.first, curr.second + x.second});
                    }
                }
                    
            }
            if(level++ > K)
                break;
        }
        
        return ans == INT_MAX ? -1: ans;
    }
};