#include <algorithm>
#include <iostream>
#include <vector>

void Print(const std::vector<int>& v) {
	std::cout << "[ ";
	for (auto& i : v) {
		std::cout << i << " ";
	}
	std::cout << "]";
}

double FindMedianSortedArrays(const std::vector<int>& nums1,
                              const std::vector<int>& nums2) {
	if (nums1.size() == 0 && nums2.size() == 0) {
		return 0;
	}

	std::vector<int> merged(nums1.size() + nums2.size());

	std::merge(nums1.cbegin(), nums1.cend(), nums2.cbegin(), nums2.cend(),
	                                                         merged.begin());
	const size_t size = merged.size();

	if (size == 1) {
		return merged.front();
	}

	if (size % 2 == 1) {
		return merged[size / 2];
	}

	return static_cast<double>(merged[size / 2 - 1] + merged[size / 2]) / 2;
}

void Test(const std::vector<int>& nums1,
          const std::vector<int>& nums2,
          double expected) {
	std::cout << "Input:    ";
	Print(nums1);
	std::cout << " ";
	Print(nums2);
	std::cout << "\n"
	          << "Expected: " << expected << "\n"
	          << "Actual:   " << FindMedianSortedArrays(nums1, nums2) << "\n"
	<< std::endl;
}

int main() {
	Test({1, 2}, {3, 4}, 2.5);
	Test({ 1, 3 }, { 2, 7 }, 2.5);
	return 0;
}
