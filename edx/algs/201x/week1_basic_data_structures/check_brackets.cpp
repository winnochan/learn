#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    int wrong_position = 0;
    std::stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket, write your code here
            opening_brackets_stack.push(Bracket(next, position + 1));
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket, write your code here
            if (opening_brackets_stack.empty()) {
                wrong_position = position + 1;
                break;
            }

            Bracket bracket = opening_brackets_stack.top();
            opening_brackets_stack.pop();
            if (!bracket.Matchc(next)) {
                wrong_position = position + 1;
                break;
            }
        }
    }

    // Printing answer, write your code here
    if (wrong_position) {
        std::cout << wrong_position << std::endl;
    } else if (!opening_brackets_stack.empty()) {
        std::cout << opening_brackets_stack.top().position << std::endl;
    } else {
        std::cout << "Success" << std::endl;
    }

    return 0;
}
