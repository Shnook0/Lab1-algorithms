#include <vector>
#include <iostream>
using namespace std;
int bisect(vector<int>& array,int find, int st,int end){
	int r=end;
	int l=st;
	if (l>r) return l;
	int pivot=(r+l)/2;
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
	return l;
}
bool exponential_search(vector<int>& a1,vector<int>& a2){
	int lena2=a2.size();
	int start=0;
	int d;
	int step=1;
	int added=step-1;
	for (auto i :a1){
		while (a2[start+added]<i and (start+added)<lena2){
			step=step*2;
			added=step-1;}
		if ((start+added)<lena2){
			d=bisect(a2,i,start,start+added);
			if (a2[d]==i){return true;}
			else{
				start=d;
				step=1;
				added=step-1;
			}
		}
		else{
			d=bisect(a2,i,start,lena2-1);
			if (a2[d]==i){return true;}
			else{
				start=d;
				step=1;
				added=step-1;
			}
		}
	}
	return false;
}

