#include <vector>
#include <iostream>
using namespace std;
bool two_poinrets(vector<int>& a1,const vector<int>& a2){
	int a1len = a1.size();
	int a2len = a2.size();
	int i=0;
	int j=0;
	while (i<a1len and j<a2len){
		if (a1[i]==a2[j]) return true;
		else if (a1[i]<a2[j]) i++; 
		else if (a1[i]>a2[j]) j++;
	}
	return false;
}
int main() {
	bool all_passed = true; // Флаг, что все тесты пройдены
	
	vector<int> arr1 = {1, 2, 3}; 
	vector<int> arr2 = {0, 2, 4}; 
	cout << "Тест 1 (есть общий элемент 2): "; 
	if (two_poinrets(arr1, arr2) == true){
		cout << "Всё верно" << endl;
	} else {
		cout << "Ошибка!" << endl;
		all_passed = false; // Если ошибка, меняем флаг
	}
	
	vector<int> arr3 = {10, 20, 30};
	vector<int> arr4 = {15, 25, 35};
	cout << "Тест 2 (нет общих элементов): "; 
	if (two_poinrets(arr3, arr4) == false){
		cout << "Всё верно" << endl;
	} else {
		cout << "Ошибка!" << endl;
		all_passed = false;
	}
	
	vector<int> arr5 = {100, 200, 300}; 
	vector<int> arr6 = {150, 200, 250}; 
	cout << "Тест 3 (есть общий элемент 200): "; 
	if (two_poinrets(arr5, arr6) == true){
		cout << "Всё верно" << endl;
	} else {
		cout << "Ошибка!" << endl;
		all_passed = false;
	}
	
	// Вывод итоговой оценки
	if (all_passed) {
		cout << "ИТОГ: Алгоритм работает отлично!" << endl;
	} else {
		cout << "ИТОГ: В алгоритме есть ошибки." << endl;
	}
	
	return 0;
}
