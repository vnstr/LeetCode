#include <iostream>
#include <string>

std::string LongestPalindrome(const std::string& s) {
	int max_len = 0;
	int start = 0;

	for (int i = 0; i < s.size(); ++i) {
		int first = i;
		int last = first + 1;

		while (last < s.size()) {
			if (s[first] != s[last]) {
				break;
			}
			++last;
		}

		while (first > 0 && last < s.size()) {
			if (s[first - 1] != s[last]) {
				break;
			}
			--first;
			++last;
		}

		int len = last - first;

		if (len > max_len) {
			max_len = len;
			start = first;
		}
	}

	return {s.cbegin() + start, s.cbegin() + start + max_len};
}

void Test(const std::string& s, const std::string& expected) {
	std::cout << "Input:    " << s << "\n"
	          << "Expected: " << expected << "\n"
	          << "Actual:   " << LongestPalindrome(s) << "\n"
	<< std::endl;
}

int main() {
	Test("babad", "bab");
	Test("cbbd", "bb");
	Test("daaaab", "aaaa");
	Test("daaaaab", "aaaaa");
	return 0;
}
