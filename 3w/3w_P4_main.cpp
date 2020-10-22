#include"Postfix.h"

int main() {

	Postfix P;
	int n;
	string expon;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> expon;
		cout << P.calPostfix(expon) << endl;
	}

	return 0;
}
