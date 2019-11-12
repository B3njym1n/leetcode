/**
 * Given a string containing just the characters '(', ')', '{',
 * '}', '[', ']', determine if the input string is valid.
 * And inpout string is valid if:
 * 1. Open brackets must be closed by the same type of brackets.
 * 2. Open brackets must be closed in the correct order.
 * Note that an empty string is also considered valid
 */
/**
 * Example:
 * Input: "([)]"
 * Output: false
 * Input: "{[]}"
 * Output: true
 */
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
	bool isValid(string s) {
		stack<char> syms;
		if (s.length() == 0) return true;
		if (s.length() == 1) return false;

		for ( int i = 0; i < s.length(); i++) {
			char c = s[i];
			cout << c;
			if (c == '}' || c == ')' || c == ']') {
				if (syms.size() == 0) return false;
				if (c == '}' && syms.top() != '{') return false;
				if (c == ')' && syms.top() != '(') return false;
				if (c == '[' && syms.top() != ']') return false;
				syms.pop();
			}
			else {
				syms.push(c);
			}
		}
		cout << "reached end";
		if (syms.size() == 0) return true;
		return false;
	}
};

int main() {
	string s = "()()()()";	
	Solution slu;
	cout <<	slu.isValid(s) << endl;
    return 0;
}

