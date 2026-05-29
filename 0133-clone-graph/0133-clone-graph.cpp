class Solution {
private:
    // Hash map to store the original node as the key and the cloned node as the value
    unordered_map<Node*, Node*> visited;

public:
    Node* cloneGraph(Node* node) {
        // Base case: if the graph is empty
        if (!node) {
            return nullptr;
        }

        // If the node has already been cloned, return the cloned reference from the map
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // Create a clone for the current node
        Node* cloneNode = new Node(node->val);
        
        // Add it to the map BEFORE iterating through its neighbors to avoid infinite recursion
        visited[node] = cloneNode;

        // Iterate through the neighbors of the original node
        for (Node* neighbor : node->neighbors) {
            // Recursively clone each neighbor and add it to the cloned node's neighbor list
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return cloneNode;
    }
};