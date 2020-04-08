class Solution {
public:

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // find root
        vector<int> find_root(n,0);
        int root = -1;
        for (int i = 0; i < n; i++){
            if(leftChild[i] != -1) find_root[leftChild[i]] = 1;
        }
        for (int i = 0; i < n; i++){
            if(rightChild[i] != -1) find_root[rightChild[i]] = 1;
        }
        for (int i = 0; i < n; i++){
            if(find_root[i] == 0){
                root = i;
                break;
            }
        }
        if(root == -1)
            return false;

        queue<int> q;
        unordered_set<int> m;
        int cnt = 0;
        q.push(root);
        while(!q.empty()){
            if(m.count(q.front()))
                return false;
            m.insert(q.front());
            if(leftChild[q.front()] != -1) q.push(leftChild[q.front()]);
            if(rightChild[q.front()] != -1) q.push(rightChild[q.front()]);
            q.pop();
            cnt++;
        }
        if(cnt == n)
            return true;
        else
            return false;
    }
};