# include <iostream>
using namespace std;
#include <vector>
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
bool twobisect(vector<int>& a1,vector<int>& a2, int st1,int end1,int st2, int end2){
	if ((st1>end1) or(st2>end2)) {return false;}
	int pivot=(st1 + end1)/2;
	int target=bisect(a2,a1[pivot],st2,end2);
	if (a2[target]==a1[pivot]){
		return true;
	}
	else{
		return (twobisect(a1,a2,st1,pivot-1,st2,target)) or 
		(twobisect(a1,a2,pivot+1,end1,target,end2));
	}
}


