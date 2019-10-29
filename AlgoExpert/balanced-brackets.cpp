#include <stack>
#include <unordered_map>

using namespace std;

bool balancedBrackets(string str) {
  // Write your code here.
	stack<char> bStack;
	unordered_map<char, char> pairs;
	pairs[')'] = '(';
	pairs['}'] = '{';
	pairs[']'] = '[';
	for (int i = 0; i < str.size(); i++) {
		char c = str[i];
		if (c == '(' || c == '{' || c == '[') {
			bStack.push(c);
		} else if (c == ')' || c == '}' || c == ']') {
			if (bStack.empty()) return false;
			if (pairs[c] != bStack.top()) {
				return false;
			} else {
				bStack.pop();
			}
		}
	}
	return bStack.empty();
}
