#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

int LongestUniqSymbolSubstring(const std::string& s) {
	std::vector<std::pair<bool, int>> substring(1 << sizeof(char) * 8, { false, 0 });
	int last_index = 0;
	int len = 0;
	int max_len = 0;

	for (int i = 0; i < s.size(); ++i) {
		char c = s[i];

		auto [exist, index] = substring[c];
		substring[c] = { true, i };

		if (exist && index >= last_index) {
			max_len = max_len < len ? len : max_len;
			len = i - index;
			last_index = index;
			continue;
		}

		++len;
	}

	return std::max(max_len, len);
}

void Test(const std::string& s, int expected) {
	std::cout << "String:  |" << s << "|\n"
	          << "Actual:   " << LongestUniqSymbolSubstring(s) << "\n"
	          << "Expected: " << expected << "\n"
	<< std::endl;
}

int main() {
	Test("arabcadeb", 5);
	Test("arabcadreb", 6);
	Test("abcabcbb", 3);
	Test(" ", 1);
	Test("aab", 2);
	return 0;
}
