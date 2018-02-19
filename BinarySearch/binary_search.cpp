#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

int64_t binary_search(const vector<int64_t> &a, int64_t x) {
  int64_t left = 0, right = (int64_t)a.size(); 
  //Write your Code here
  int64_t pivot = 0;
  pivot = pivot + (right-left)/2;

  if(x < a[0] || x > a[right-1]){
    //std::cout<<x<<" is not in range\n"<<a[0]<<":"<<a[right-1];
    return -1; //since sorted, you can check right away if its not in the array
  }

  while(true){
    
    if(x == a[pivot]){
      return pivot;
    }
    else if(left > right){ //if left == right, that means we search the sorted array accordingly, and still didnt find the answer.
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
  int64_t n;
  std::cin >> n;
  vector<int64_t> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int64_t m;
  std::cin >> m;
  vector<int64_t> b(m);
  
  
  for (int64_t i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  
  for (int64_t i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
