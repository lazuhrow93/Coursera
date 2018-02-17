#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size(); 
  //vector<int> newVector1;
  int pivot = (right-left)/2;
  bool found = false;


  while(!found){
  	
  	if(pivot < 0 || pivot > a.size()){ //if its out of range, 
  		return - 1;
  	}
  	else if(x == a[pivot]){
  		return pivot;
  	}
  	else if(x < a[pivot]){
  		right = pivot-1;
  	}
  	else{
  		left = pivot + 1;
  	}
  }
  

  /*
  if(right == 0){
  	return -1;
  }
  else if(a[pivot] == x){
  	return pivot;
  }
  else if(x > a[pivot]){

  	for(int i = pivot + 1; i < right; i++) newVector1.push_back(a[i]);

  	if(binary_search(newVector1, x) == -1) return -1;
  	else return pivot + binary_search(newVector1 ,x) + 1;
 
  }
  else{

  	for(int i = left; i < pivot; i++) newVector1.push_back(a[i]); 

  	return binary_search(newVector1, x);
  }
  */


  //write your code here
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  /*
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << linear_search(a, b[i]) << ' ';
  }
	*/
  //std::cout <<"\n";

  for (int i = 0; i < m; ++i){
  	std::cout << binary_search(a, b[i]) << ' ';
  }

}

