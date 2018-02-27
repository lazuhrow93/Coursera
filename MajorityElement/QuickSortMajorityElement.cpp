#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int partition(vector<int> &a, int left, int right){

  //you comparison element
  int pivot = a[left]; //pivot
  int j = left;

  for (int i = left+1; i <=right; ++i){
    
    if(a[i] <= pivot){ //if this element is less than the pivot, 
      j = j + 1; //make space for the less than array

      //swap i and j
      iter_swap(a.begin() + j, a.begin() + i);
    }
  }

  iter_swap(a.begin() + left, a.begin() + j);
  return j;
}

void quickSort(vector<int> &a, int l, int r){
  
  if(l >= r) return;

  int mid = partition(a, l ,r);

  quickSort(a, l, mid-1);
  quickSort(a, mid+1, r);

}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }

  quickSort(a, 0, a.size()-1);

  for(int x = 0; x<a.size(); x++){
    std::cout<<"Sorted Array: "<<a[x]<<", ";
  }
}
