#include <iostream>
#include <queue>
#include <array>

int main() {
    std::queue<char> q;
    std::array<int, 26> charCount = {0};
    std::string expression;
    char firstNonRepeating = '\0';

    std::cout << "Enter the expression: ";
    std::cin >> expression;

    for (char ch : expression) {
        q.push(ch);
        charCount[ch - 'a']++;

        while (!q.empty() && charCount[q.front() - 'a'] > 1) {
            q.pop();
        }

        if (!q.empty()) {
            firstNonRepeating = q.front();
        }
    }

    if (firstNonRepeating != '\0') {
        std::cout << "The first non-repeating character is: " << firstNonRepeating << std::endl;
    } else {
        std::cout << "There is no non-repeating character in the input." << std::endl;
    }

    return 0;
}
