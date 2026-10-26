# include <iostream>
using namespace std;
#include <vector>
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

