#include "modules/decoder.hpp"

#include <cctype>
#include <cstddef>
#include <string>

std::string decodeHelper(const std::string &s, int &i) {
    // i - текущая позиция в строке s
	std::string result;
	int k = 0;

	while (static_cast<size_t>(i) < s.size()) {
		char ch = s[i];

		if (std::isdigit(ch)) {
			// накапливаем число
			k = k * 10 + (ch - '0');
			++i;
		} else if (ch == '[') {
			// рекурсивный вызов для содержимого скобок
			++i;
			std::string inner = decodeHelper(s, i);
			// повторяем inner k раз
            for (; k > 0; --k) {
				result += inner;
            }
			k = 0; // сбрасываем после использования
		} else if (ch == ']') {
			// конец текущего рекурсивного блока
			++i;
			return result;
		} else {
			// обычный символ
			result += ch;
			++i;
		}
	}

	return result;
}

std::string decodeString(const std::string &s) {
	int i = 0;
	return decodeHelper(s, i);
}
