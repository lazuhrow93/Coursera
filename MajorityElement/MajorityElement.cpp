#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1; //no elements
  if (left + 1 == right) return a[left]; //only two element 

  int sizeOfarray = right-left;

  if(sizeOfarray == 2){
    if(a[left] == a[right-1]) return a[left]; //if theyre the same, majority element so far
    else return -1;
  }
  else if(sizeOfarray == 1){
    return a[left];
  }

  int test_elem1 = get_majority_element(a, left, (left+right)/2);
  int test_elem2 = get_majority_element(a, (left+right)/2, right);

  if(test_elem1 == -1 && test_elem2 >= 0){
    return test_elem2;
  }
  else if(test_elem2 == -1 && test_elem1 >= 0){
    return test_elem1;
  }
  else if(test_elem1 == test_elem2){
    return test_elem1;
  }
  else return -1;

}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }

  std::random_shuffle(a.begin(), a.end());

  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
