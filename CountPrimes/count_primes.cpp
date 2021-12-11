#include <chrono>
#include <iostream>
#include <limits>
#include <vector>

int count_primes(int n) {
	if (n < 3) {
		return 0;
	}

	int count = 0;

	std::vector<char> numbers(n, true);
	numbers[0] = false;
	numbers[1] = false;

	for (int i = 2; i < n; ++i) {
		if (!numbers[i]) {
			continue;
		}

		double s = static_cast<double>(i) * i;

		for (double j = s; j < n; j += i) {
			numbers[j] = false;
		}

		++count;

	}

	return count;
}

int main() {
	std::numeric_limits<int> limits;
	auto ts = std::chrono::steady_clock::now();
	std::cout << count_primes(limits.max())
	          << " Time in ms: "
	          << std::chrono::duration_cast<std::chrono::milliseconds>((std::chrono::steady_clock::now() - ts)).count()
	<< std::endl;
	return 0;
}
