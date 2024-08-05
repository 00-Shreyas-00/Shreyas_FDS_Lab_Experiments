#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

// Function to remove punctuation and spaces, and convert to lowercase
string preprocessString(const string& str) {
    string result;
    for (char ch : str) {
        if (isalnum(ch)) {
            result += tolower(ch);
        }
    }
    return result;
}

// Function to reverse a string using a stack
string reverseString(const string& str) {
    stack<char> charStack;
    for (char ch : str) {
        charStack.push(ch);
    }

    string reversed;
    while (!charStack.empty()) {
        reversed += charStack.top();
        charStack.pop();
    }
    return reversed;
}

// Function to check if the string is a palindrome
bool isPalindrome(const string& str) {
    string cleanedStr = preprocessString(str);
    string reversedStr = reverseString(cleanedStr);
    return cleanedStr == reversedStr;
}

int main() {
    string input;

    cout << "Enter a string to check if it is a palindrome: ";
    getline(cin, input);

    string cleanedInput = preprocessString(input);
    string reversedInput = reverseString(cleanedInput);

    // 1. Print original string followed by reversed string
    cout << "Original string (cleaned): " << cleanedInput << endl;
    cout << "Reversed string: " << reversedInput << endl;

    // 2. Check whether the given string is a palindrome or not
    if (isPalindrome(input)) {
        cout << "The given string is a palindrome." << endl;
    } else {
        cout << "The given string is not a palindrome." << endl;
    }

    return 0;
}
