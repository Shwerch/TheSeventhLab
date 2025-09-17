#include "modules/expression_solver.hpp"

#include <iostream>

bool calculate(const std::vector<int> &numbers, size_t index, int summa,
			   int last_term, int S, std::string expr) {
	if (index == numbers.size()) {
		if (summa == S) {
			std::cout << expr << " = " << S << std::endl;
			return true;
		}
		return false;
	}

	int next = numbers.at(index);

	if (calculate(numbers, index + 1, summa + next, next, S,
				  expr + " + " + std::to_string(next)))
		return true;

	if (calculate(numbers, index + 1, summa - last_term + last_term * next,
				  last_term * next, S, expr + " * " + std::to_string(next)))
		return true;

	return false;
}

bool expressionCanFormTarget(const std::vector<int> &numbers, int S) {
	if (numbers.empty())
		return false;

	return calculate(numbers, 1, numbers[0], numbers[0], S,
					 std::to_string(numbers[0]));
}
