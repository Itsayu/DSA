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
    Node* cloneGraph(Node* node) {
        
        //stores the address of the nodes created
        if(node==NULL)
            return NULL;
        vector<Node*> created(101,NULL);
        buildGraph(node,created);
        return created[node->val];
    }
    void buildGraph(Node* node,vector<Node*>& created)
    {
        
        //create the node
        Node* x;
        if(created[node->val]==NULL){
             x=new Node(node->val);
            created[node->val]=x;
        }
        else
            x=created[node->val];
        
        for(auto adj:node->neighbors)
        {
            //if node is not created yet create it
            if(created[adj->val]==NULL)
            {
                Node* n = new Node(adj->val);
                
                created[adj->val]=n;
				//add the created node to the neighbors
                x->neighbors.push_back(n);
                buildGraph(adj,created);
            }
            else{
                x->neighbors.push_back(created[adj->val]);
            }
        }
    }
};