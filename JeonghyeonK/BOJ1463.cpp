#include <iostream>

using namespace std;

int divide(int n) {
	if (n % 3 == 0) return 1 + divide(n / 3);
	else if (n % 2 == 0) return 1 + divide(n / 2);
	else if (n == 1) return 0;
	else return 1 + divide(n - 1);
}

int main() {

	int n;

	cin >> n;
	cout << divide(n) << endl;

	return 0;
}