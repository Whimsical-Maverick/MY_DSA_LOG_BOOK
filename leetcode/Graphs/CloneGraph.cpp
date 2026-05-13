/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/


class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        if(node==NULL)return NULL;
        queue<Node*>q;
        Node*node1 = new Node(node->val);
        unordered_map<Node*,Node*>mp;
        mp[node] = node1;
        q.push(node);
        unordered_set<int>visited;
        while(!q.empty())
        {
            auto temp = q.front();
            q.pop();
            for(auto ele : temp->neighbors)
            {
               if(mp.find(ele)==mp.end())
               {
                  Node*temp1 = new Node(ele->val);
                  mp[ele]=temp1;
                  q.push(ele);
               }
               mp[temp]->neighbors.push_back(mp[ele]);
            }
        }
        return mp[node];
    }
};