#include <iostream>
#include <limits>
#include <string>

int MyAtoi(const std::string& s) {
	size_t first = 0;
	size_t last = s.size();
	unsigned int limit = std::numeric_limits<int>().max();
	uint64_t nb = 0;
	char sign = 1;

	while (first != last) {
		if (s[first] != ' ') {
			break;
		}
		++first;
	}

	if (first != last && s[first] == '-') {
		sign = -1;
		limit += 1;
		++first;
	} else if (first != last && s[first] == '+') {
		++first;
	}

	while (first != last && s[first] >= '0' && s[first] <= '9') {
		nb = 10 * nb + (uint64_t(s[first]) - '0');

		if (nb >= limit) {
			return limit * sign;
		}

		++first;
	}

	return nb * sign;
}

void Test(const std::string& s, int64_t expected) {
	std::cout << "Input:    " << s << "\n"
	          << "Expected: " << expected << "\n"
	          << "Actual:   " << MyAtoi(s) << "\n"
	<< std::endl;
}

int main() {
	Test("      123", 123);
	Test("      -123", -123);
	Test("2147483647", 2147483647);
	Test("-2147483648", -2147483648);
	Test("2147483650", 2147483647);
	Test("-2147483650", -2147483648);
	return 0;
}
