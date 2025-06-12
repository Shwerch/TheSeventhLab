#include "modules/decoder.hpp"

#include <stack>
#include <cctype>

std::string decodeString(const std::string& s) {
    std::stack<int> counts;
    std::stack<std::string> resultStack;
    std::string current;
    int k = 0;

    for (char ch : s) {
        if (std::isdigit(ch)) {
            k = k * 10 + (ch - '0');
        } else if (ch == '[') {
            counts.push(k);
            resultStack.push(current);
            current.clear();
            k = 0;
        } else if (ch == ']') {
            std::string temp = current;
            current = resultStack.top();
            resultStack.pop();
            int repeat = counts.top();
            counts.pop();
            while (repeat--) {
                current += temp;
            }
        } else {
            current += ch;
        }
    }

    return current;
}