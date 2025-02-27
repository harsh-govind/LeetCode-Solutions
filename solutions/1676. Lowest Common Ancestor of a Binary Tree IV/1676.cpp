class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*>& nodes) {
    unordered_set<TreeNode*> nodesSet{nodes.begin(), nodes.end()};
    return lca(root, nodesSet);
  }

 private:
  TreeNode* lca(TreeNode* root, unordered_set<TreeNode*>& nodesSet) {
    if (root == nullptr)
      return nullptr;
    if (nodesSet.count(root))
      return root;

    TreeNode* l = lca(root->left, nodesSet);
    TreeNode* r = lca(root->right, nodesSet);

    if (l && r)
      return root;
    return l ? l : r;
  }
};
