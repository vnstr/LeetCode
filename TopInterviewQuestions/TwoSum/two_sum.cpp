#include <unordered_map>
#include <vector>

std::vector<int> TwoSum(std::vector<int>& nums, int target) {
	std::unordered_map<int, int> terms;

	for (int i = 0; i < nums.size(); ++i) {
		int x = nums[i];
		int y = target - x;

		if (terms.find(y) != terms.cend()) {
			return {terms[y], i};
		}

		terms[x] = i;
	}

	return {};
}

