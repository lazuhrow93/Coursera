#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size(); 
  //Write your Code here
  int pivot = 0;
  pivot = pivot + (right-left)/2;

  if(x < a[0] || x > a[right-1]){
    //std::cout<<x<<" is not in range\n"<<a[0]<<":"<<a[right-1];
    return -1; //since sorted, you can check right away if its not in the array
  }

  while(true){
    
    if(x == a[pivot]){
      return pivot;
    }
    else if(left >= right){ //if left == right, that means we search the sorted array accordingly, and still didnt find the answer.
      return -1;
    }
    else if(x > a[pivot]){
      left = pivot+1;
      pivot = left + ((right-left)/2);

    }
    else{//if x < a[pivot]
      right = pivot-1;
      pivot = left + ((right - left)/2);
    }

  }
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
  
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
