#include <iostream>
#include <limits>

int Reverse(int x) {
	constexpr std::numeric_limits<int> limits;
	
	if (x == limits.min()) {
		return 0;
	}

	constexpr int kMaxFirst = limits.max() % 10;
	constexpr int kMaxPenultimate = limits.max() / 10;

	int sign = 1;
	int reverse = 0;

	if (x < 0) {
		sign = -1;
		x = -x;
	}

	while (x > 0) {
		int n = x % 10;

		if (reverse > kMaxPenultimate
		    || (reverse == kMaxPenultimate && n > kMaxFirst)) {
			return 0;
		}

		reverse = reverse * 10 + n;
		x /= 10;
	}

	return sign * reverse;
}

void Test(int x, int expected) {
	std::cout << "Input:    " << x << "\n"
	          << "Actually: " << Reverse(x) << "\n"
	          << "Expected: " << expected << "\n"
	<< std::endl;
}

int main() {
	std::numeric_limits<int> limits;

	Test(123, 321);
	Test(-123, -321);
	Test(limits.max(), 0);

	return 0;
}