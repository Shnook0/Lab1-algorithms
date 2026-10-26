#include <vector>
#include <chrono>
# include <iostream>

using namespace std;
using namespace std::chrono;

// бинарный поиск обычный:
int binpoisk(const vector<int>& array,int find){
	int r=(int)array.size()-1;
	if (r==-1) return -1;
	int l=0;
	int pivot=(int)array.size()/2;
	while(l!=r){
		if (array[pivot]<find){
			l=pivot+1;
			pivot=(r+l)/2;
		}
		else{
			r=pivot;
			pivot=(r+l)/2;
		}
		
		
		
	}
	if (array[l]==find) return l;
	else return -1;
}
//решение задачи бин поиском
bool bisearch(const vector<int>& a1, const vector<int>& a2){
	int a1len=a1.size();
	int b=0;
	for (int i =0;i<a1len;i++){
		b=binpoisk(a2,a1[i]);
		if (b!=-1) return true;
		
	}
	return false;
	
}
// ==========================================

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
		
		// 3. Определяем количество итераций (1000 для маленьких, меньше для больших)
		int iterations = 10000;
		if (size > 10000) iterations = 10;
		if (size >= 1000000) iterations = 2; // Для 1 млн+ 2 итерации
		
		// Переменная для сохранения результата (чтобы компилятор не удалил вызов)
		volatile bool result = false;
		
		// 4. Замеряем время
		auto start_time = high_resolution_clock::now();
		
		for (int k = 0; k < iterations; ++k) {
			result = bisearch(a1, a2);
		}
		
		auto end_time = high_resolution_clock::now();
		
		// 5. Считаем среднее время
		// Переводим в миллисекунды (duration_cast<microseconds> / 1000.0)
		double total_time_ms = duration_cast<microseconds>(end_time - start_time).count() / 1000.0;
		double avg_time = total_time_ms / iterations;
		
		cout << "Размер a1: " << size << "\t Итераций: " << iterations 
		<< "\t Среднее время: " << avg_time << " мс" << endl;
	}
	
	return 0;
}
