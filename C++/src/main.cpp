#include "input.hpp"
#include "main_menu.hpp"
#include "output.hpp"

#include "modules/decoder.hpp"
#include "modules/expression_solver.hpp"
#include "modules/koch_curve.hpp"
#include <vector>

int main() {
	while (true) {
		printMainMenu();
		int value = getValue<int>("Введите раздел программы");
		MainMenu element;
		try {
			element = convertIntToMainMenu(value);
		} catch (...) {
			continue;
		}
		std::string message;
		std::vector<int> enteredNumbers;
		bool canFormtarget;
		switch (element) {
		case MainMenu::KOCH_CURVE:
			drawKochCurve(getValue<int>("Введите n"));
			break;
		case MainMenu::DECODE:
			message = getLine("Введите строку");
			message = decodeString(message);
			printString(message);
			break;
		case MainMenu::EXPRESSION_SOLVER:
			enteredNumbers = getVector<int>("Введите числа через пробел");
			canFormtarget = expressionCanFormTarget(enteredNumbers, getValue<int>("Введите число S"));
			printString("Числа" + std::string(((canFormtarget) ? " " : " не ")) +
						"могут быть соединены с помощью + и * для получения числа S");
			break;
		case MainMenu::EXIT:
			return 0;
		}
	}
	return 0;
}