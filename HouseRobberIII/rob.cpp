#include <algorithm>

// Task conditions
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct House {
	House(int r, int nr) : rob(r), notRob(nr) {};
	int rob{ 0 };
	int notRob{ 0 };
};

House Walk(TreeNode* root) {
	if (!root) {
		return House(0, 0);
	}

	auto lhouse = Walk(root->left);
	auto rhouse = Walk(root->right);

	return House(root->val + lhouse.notRob + rhouse.notRob,
	             std::max(lhouse.rob, lhouse.notRob) + std::max(rhouse.rob, rhouse.notRob));
}

int Rob(TreeNode* root) {
	auto house = Walk(root);
	return std::max(house.rob, house.notRob);
}

