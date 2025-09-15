#include "modules/expression_solver.hpp"

bool dfs_all(const std::vector<int>& nums, size_t index, int current_value, int target) {
	if (index == nums.size()) {
		return current_value == target;
	}

	int next = nums[index];

	// Пробуем сложение
	if (dfs_all(nums, index + 1, current_value + next, target))
		return true;

	// Пробуем умножение
	if (dfs_all(nums, index + 1, current_value * next, target))
		return true;

	return false;
}

bool expressionCanFormTarget(const std::vector<int>& numbers, int target) {
	if (numbers.empty())
		return false;
	return dfs_all(numbers, 1, numbers[0], target);
}
