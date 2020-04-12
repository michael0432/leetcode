class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (int i = 0; i < stones.size(); i++)
            q.push(stones[i]);
        while(!q.empty()){
            if(q.size() == 1)
                return q.top();
            int s1, s2;
            s1 = q.top();
            q.pop();
            s2 = q.top();
            q.pop();
            if(s1 != s2)
                q.push(s1 - s2);
        }
        return 0;
    }
};