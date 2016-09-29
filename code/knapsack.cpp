#include <vector>
#include <algorithm>

using namespace std;
// Input:
//
// items: pairs of weight, value
// W: knapsack capacity
//
// Returns: M[i][j], the maximum value for weight j using only the first i elements.
vector<vector<unsigned int>> knapsack(const vector<pair<unsigned int, unsigned int>>& items, const unsigned int W)
{
	vector<vector<unsigned int>> m(items.size(), vector<unsigned int>(W + 1, 0));

	for (unsigned int i = 1; i <= items.size(); i++) {
		const auto& item = items[i - 1];
		for (unsigned int j = 0; j <= W; j++) {
			if (item.first > j) {
				// Cannot use it yet, maximum stays
				m[i][j] = m[i - 1][j];
			} else {
				// Use it if it is better
				m[i][j] = max(m[i - 1][j], m[i - 1][j - item.first] + item.second);
			}
		}
	}

	return m;
}

// Return: M[j] the maximum value that can be acquired with capacity j
vector<unsigned int> knapsack2(const vector<pair<unsigned int, unsigned int>>& items, const unsigned int W)
{
	vector<unsigned int> m1(items.size()), m2(items.size());

	for (unsigned int i = 1; i <= items.size(); i++) {
		const auto& item = items[i - 1];
		const auto& mprev = i % 2 ? m1 : m2;
		auto& mcur = i % 2 ? m2 : m1;

		for (unsigned int j = 0; j <= W; j++) {
			if (item.first > j) {
				// Cannot use it yet, maximum stays
				mcur[j] = mprev[j];
			} else {
				// Use it if it is better
				mcur[j] = max(mprev[j], mprev[j - item.first] + item.second);
			}
		}
	}

	return items.size() % 2 ? m1 : m2;
}
