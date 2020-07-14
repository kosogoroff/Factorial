#include <iostream>
#include <sstream>
#include <vector>
#define base 1000000000
using namespace std;
void writelong(vector<int> vec) {
	// длинное число хранится в векторе целых 32-разрядных чисел, каждое число
	// хранит 9 разрядов длинного числа - т.е. 9-разрядное число (до 12!)
	// хранится в одном целом числе, 18-разрядное число - в двух и т.д.
	// Число хранится , начиная с младших разрядов: в первом целом числе хранятся
	//младшие разряды, во втором - более старшие и т.д. Поэтому выводится обратным циклом
	printf("%d", vec.empty() ? 0 : vec.back());
	for (int i = (int)vec.size() - 2; i >= 0; --i)
		printf("%09d", vec[i]);
}
vector<int> smult(vector<int> a, int b) {
	// умножает длинное число на короткое
	int carry = 0;     // флаг переполнения/перенос
	for (int i = 0; i < a.size() || carry; ++i) {
		if (i == a.size())
			a.push_back(0);
		long long cur = carry + a[i] * 1ll * b;
		a[i] = int(cur % base);
		carry = int(cur / base);
	}
	while (a.size() > 1 && a.back() == 0)
		a.pop_back();
	return a;
}
int main() {
	int b;
	cin >> b;
	vector<int> a(1, 1);
	for (int i = 1; i <= b; i++)
		a = smult(a, i);
	writelong(a);
	cout << endl;
	return 0;
}