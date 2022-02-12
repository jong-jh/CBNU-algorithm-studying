#include <iostream>
#include <stack>
#include <string>

using namespace std;

void Printreverse(stack<char>& s);

int main() {
	ios_base::sync_with_stdio(false);

	stack<char> s;
	string str;
	bool tag = false;

	getline(cin, str);

	for (char ch : str) {
		if (ch == ' ') {
			Printreverse(s);
			cout << ch;
		}
		else if (ch == '<') {
			tag = true;
			Printreverse(s);
			cout << ch;
		}
		else if (ch == '>') {
			tag = false;
			cout << ch;
		}
		else if (tag) {
			cout << ch;
		}
		else {
			s.push(ch);
		}
	}
	Printreverse(s);

}

void Printreverse(stack<char>& s) {
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
}