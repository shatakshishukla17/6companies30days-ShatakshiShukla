class Solution {
public:
    void dijkstra(char& source, unordered_map<char, vector<pair<char, int>>>& adj, vector<vector<long long>>&costMat){
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>>pq;
        pq.push({0,source});
        while(!pq.empty()){
            int d=pq.top().first;
            char adjNode=pq.top().second;
            pq.pop();
            for(auto &it:adj[adjNode]){
                char adjNode=it.first;
                int cost=it.second;
                if(costMat[source-'a'][adjNode-'a']>d+cost){
                    costMat[source-'a'][adjNode-'a']=d+cost;
                    pq.push({d+cost, adjNode});
                }
            }
        }
        return ;
    }
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char, int>>>adj;
        for(int i=0;i<original.size();i++){
            adj[original[i]].push_back({changed[i], cost[i]});
        }
        vector<vector<long long>>costMat(26, vector<long long>(26, INT_MAX));
        for(int i=0;i<source.length();i++){
            char ch=source[i];
            dijkstra(ch, adj, costMat);
        }
        long long ans=0;
        for(int i=0;i<source.length();i++){
            if(source[i]==target[i]){
                continue;
            }
            if(costMat[source[i]-'a'][target[i]-'a']==INT_MAX){
                return -1;
            }
            ans+=costMat[source[i]-'a'][target[i]-'a'];
        }
        return ans;
    }
};
