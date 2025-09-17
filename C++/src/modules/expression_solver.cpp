#include "modules/expression_solver.hpp"

#include <iostream>

bool dfs_all(const std::vector<int> &nums, size_t index, int current_value, int last_term, int target,
			 std::string expr) {
	if (index == nums.size()) {
		if (current_value == target) {
			std::cout << expr << " = " << target << std::endl;
			return true;
		}
		return false;
	}

	int next = nums[index];

	// Пробуем сложение: новое слагаемое начинается
	if (dfs_all(nums, index + 1,
				current_value + next, // добавляем в сумму
				next,				  // новое последнее слагаемое
				target, expr + " + " + std::to_string(next)))
		return true;

	// Пробуем умножение: корректируем последнее слагаемое
	if (dfs_all(nums, index + 1,
				current_value - last_term + last_term * next, // пересчитываем сумму с учётом умножения
				last_term * next,							  // новое последнее слагаемое
				target, expr + " * " + std::to_string(next)))
		return true;

	return false;
}

bool expressionCanFormTarget(const std::vector<int> &numbers, int target) {
	if (numbers.empty())
		return false;

	return dfs_all(numbers, 1, numbers[0], numbers[0], target, std::to_string(numbers[0]));
}
