#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	/**
	 * Lexicographical permutations
	 */

	/**
	 * A given collection containing N elements can be reordered in
	 * several different ways(N! ways, accuratly)
	 */
	std::vector<int> v1 = { 1, 2, 3, 4, 5 };

	do
	{
		for (int n : v1) std::cout << n << ' ';
		std::cout << '\n';
	}
	while (std::next_permutation(begin(v1), end(v1)));
	return 0;
}
