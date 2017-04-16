//Description
//Clone an undirected graph.Each node in the graph contains a label and a list of its neighbors.
//
//
//OJ's undirected graph serialization:
//Nodes are labeled uniquely.
//
//We use # as a separator for each node, and, as a separator for node label and each neighbor of the node.
//As an example, consider the serialized graph{ 0,1,2#1,2#2,2 }.
//
//The graph has a total of three nodes, and therefore contains three parts as separated by #.
//
//First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
//Second node is labeled as 1. Connect node 1 to node 2.
//Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self - cycle.
//Visually, the graph looks like the following :
//
//1
/// \
/// \
//0 -- - 2
/// \
//\_ /

//Solution:
//Solution 1:
//we can add a unorder_map to solve this problem recursively
//if this node we didn't deal,we just deal with it recursively and push into hash map
//otherwise,return it in hash map
//noticeable we should push itself other than the native node into hashmap

#include<vector>
#include<unordered_map>
using namespace std;


 struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
 };

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (!node)
			return NULL;

		if (list.find(node->label) != list.end()) {
			return list.find(node->label)->second;
		}

		UndirectedGraphNode *root = new UndirectedGraphNode(node->label);
		list.insert(pair<int, UndirectedGraphNode*>(root->label, node));

		for (auto v:node->neighbors){
			root->neighbors.push_back(cloneGraph(v));
		}

		return root;
	}
private:
	unordered_map<int, UndirectedGraphNode*> list;
};