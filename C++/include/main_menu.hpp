#pragma once

#include <stdexcept>
#include <string_view>

enum class MainMenu {
	KOCH_CURVE,
    DECODE,
    EXPRESSION_SOLVER,
    EXIT,
};

constexpr int mainMenuElements = static_cast<int>(MainMenu::EXIT) + 1;

constexpr std::string_view getElementSescription(MainMenu element) {
    switch (element) {
        case MainMenu::KOCH_CURVE:
        return "Кривая Коха";
        case MainMenu::DECODE:
        return "Декодирование строки";
        case MainMenu::EXPRESSION_SOLVER:
        return "Соединение двузначных чисел знаками + и *";
        case MainMenu::EXIT:
        return "Выход из программы";
        default:
        throw std::runtime_error("Как ты это сделал");
    }
}

MainMenu convertIntToMainMenu(int element);

void printMainMenu();