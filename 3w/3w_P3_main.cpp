#include"Postfix.h"

int main() {

	Postfix P;
	int n;
	string expon;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> expon;
		P.setPostfix(expon);
		P.getPostfix();
		cout << endl;
		P.clear();
	}

	return 0;
}
