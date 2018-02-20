#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int partition(vector<int> &a, int left, int right){

  //you comparison element
  int pivot = a[left]; //pivot
  int j = left;

  for (int i = left+1; i < right; ++i){
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
  int mid = 0;

  if(l >= r) return;

  mid = partition(a, l ,r);

  quickSort(a, l, mid-1);
  quickSort(a, mid+1, r);
  

}

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1; //only 1 element, no majority
  if (left + 1 == right) return a[left]; //if theyre only two elements, return arbitrary one 

  /* we want to sort first, and then we can just iterate through the numbers
     to find the majority element */
  quickSort(a, left, right); //O(nlogn)

  //iterate through array to find a majority
  int current_interest = 0;
  int majority_test = 0; //count of specific number
  int majority_value = a.size()/2;

  //by the time we get here, we know there are at least two elements. 
  current_interest = a[0];  

  //now that its sorted, iterate and find if there is a majority 
  for(int i = 0; i<a.size(); ++i){
    if(a[i] == current_interest){
      ++majority_test;
    }
    else{
      current_interest = a[i];
      majority_test = 1;
    }

    if(majority_test > majority_value) return 1;
  }

  return -1;

 
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
