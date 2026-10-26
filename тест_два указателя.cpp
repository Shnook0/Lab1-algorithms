#include <vector>
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

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
	// 1. Создаем a2 (размер 10^8, нечетные числа)
	vector<int> a2;
	a2.reserve(100000000);
	for (int i = 0; i < 100000000; ++i) {
		a2.push_back(2 * i + 1); 
	}
	
	// Массив размеров для a1
	vector<int> sizes = {10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
	
	for (int size : sizes) {
		// 2. Создаем a1 заданного размера (четные числа, чтобы не было совпадений)
		vector<int> a1;
		a1.reserve(size);
		for (int i = 0; i < size; ++i) {
			a1.push_back(2 * i + 2); // 2, 4, 6, 8...
		}
		
		// 3. Определяем количество итераций
		int iterations = 10000;
		if (size > 10000) iterations = 100;
		if (size >= 1000000) iterations = 2;
		
		// Переменная для сохранения результата
		volatile bool result = false;
		
		// 4. Замеряем время
		auto start_time = high_resolution_clock::now();
		
		for (int k = 0; k < iterations; ++k) {
			result = two_poinrets(a1, a2);
		}
		
		auto end_time = high_resolution_clock::now();
		
		// 5. Считаем среднее время
		double total_time_ms = duration_cast<microseconds>(end_time - start_time).count() / 1000.0;
		double avg_time = total_time_ms / iterations;
		
		cout << "Размер a1: " << size << "\t Итераций: " << iterations 
		<< "\t Среднее время: " << avg_time << " мс" << endl;
	}
	
	return 0;
}
