#include "Postfix.h"
#include<string>


//후위 표기 계산식
int Postfix::calPostfix(string exp) {
	//계산하는 함수
	//수식을 exp로 입력받음
	string postfix = exp; // 이건 왜?
	int n = postfix.size(); //입력받은 문자열의 사이즈
	char testch; //문자열로 입력받은 수식을 한문자씩 떼어내서 읽음

	for (int i = 0; i < n; i++) {
		testch = exp.at(i);
		if (isNum(testch)) {
			int temp = testch - '0';
			LStacks->push(temp);
		}
		else {
			LStacks->push(calculate(testch));
		}
	}

	return LStacks->pop();
}

int Postfix::calculate(char op, int num1, int num2) {

	int cal = 0;

	num2 = LStacks->pop();
	num1 = LStacks->pop();

	switch (op) {
	case '+':
		cal = num1 + num2;
		break;
	case '-':
		cal = num1 - num2;
		break;
	case '*':
		cal = num1 * num2;
		break;
	case '/':
		cal = num1 / num2;
		break;
	default:
		break;
	}

	return cal;
}

bool Postfix::isOper(char item) {
	if (item == '+' || item == '-' || item == '*' || item == '/') {
		return true;
	}
	else return false;
}

bool Postfix::isNum(char item) {
	if (item >= 48 && item < 58)
		return true;
	return false;
}

//괄호 표현식도 필요해
void Postfix::oper(char testch) {
	char temp;
	if (!(Stacks->empty())) {
		temp = Stacks->top().at(0);
	}
	else
		temp = '*';

	if (testch == '*' || testch == '/') {
		while (!(Stacks->empty()) && (temp == '*' || temp == '/')) {
			temp = Stacks->pop().at(0);
			if (temp == '(' || temp == '+' || temp == '-') {
				Stacks->push(temp);
				break;
			}

			Str.push_back(temp);
		}
	}
	else if (testch == '+' || testch == '-') {
		while (!(Stacks->empty()) && (temp == '*' || temp == '/'|| temp == '+' || temp == '-')) {
			temp = Stacks->pop().at(0);
			if (temp == '(') {
				Stacks->push('(');
				break;
			}
			Str.push_back(temp);
		}
	}
	Stacks->push(testch);
}

void Postfix::setPostfix(string exp) {
	char temp = '0';
	int str_size = exp.size();
	char testch;

	for (int i = 0; i < str_size; i++) {
		testch = exp.at(i);
		if (isNum(testch)) {
			//숫자일 경우 string으로 뒤에 바로 연결
			Str.push_back(testch);
		}
		else {
			//숫자가 아닐 경우
			if (testch == '(') {
				Stacks->push(testch);
			}
			else if (testch == ')') {
				while (!(Stacks->empty()) && (temp != '(')) {
					temp = Stacks->pop().at(0);
					if (temp == '(')
						break;
					Str.push_back(temp);
				}
				
			}
			else {
				oper(testch);
			}

		}
	}

	while (!Stacks->empty()) {
		temp = Stacks->pop().at(0);
		if (temp == '(')
			continue;
		Str.push_back(temp);
	}

}

void Postfix::getPostfix() {
	cout << Str;
}

void Postfix::clear() {
	Str = "";
}
