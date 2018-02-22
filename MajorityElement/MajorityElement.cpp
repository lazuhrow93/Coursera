#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;
unsigned int count(const vector<int> &a, int left, int right, int element)
{
  unsigned int count = 0;
  for (unsigned int i = left; i <= right; i++)
  {
    if (a[i] == element)
    {
      count++;
    }
  }
  return count;
}
int get_majority_element(vector<int> &a, int left, int right) {
  if (left > right) return -1; //no elements
  if (left == right) return a[left]; //only two element 

  //int sizeOfarray = right-left;

  /*
  if(sizeOfarray == 2){
    if(a[left] == a[right-1]) return a[left]; //if theyre the same, majority element so far
    else return -1;
  }
  else if(sizeOfarray == 1){
    return a[left];
  }
  */

  /*
  std::cout<<"First half: ";
  for(int j = left; j<(left+right)/2; ++j){
    std::cout<<a[j]<<", ";
  }
  std::cout<<"Second half: ";
  for(int k = (left+right)/2; k <= right; k++){
    std::cout<<a[k]<<", ";
  }
  
  std::cout<<"\n";
  */

  int mid = (left+right)/2;

  int leftCount = get_majority_element(a, left, mid);
  int rightCount = get_majority_element(a, mid+1, right);

  if (leftCount == -1 && rightCount != -1)
  {
    unsigned int num = count(a, left, right, rightCount);
    if (num > (right - left + 1) / 2)
    {
      return rightCount;
    }
    else
    {
      return -1;
    }

  }
  else if (rightCount == -1 && leftCount != -1)
  {
    unsigned int num = count(a, left, right, leftCount);
    if (num > (right - left + 1) / 2)
    {
      return leftCount;
    }
    else
    {
      return -1;
    }
  }
  else if (leftCount != -1 && rightCount != -1)
  {
    unsigned int leftNum = count(a, left, right, leftCount);
    unsigned int rightNum = count(a, left, right, rightCount);
    if (leftNum > (right - left + 1) / 2)
    {
      return leftCount;
    }
    else if (rightNum > (right - left + 1) / 2)
    {
      return rightCount;
    }
    else
    {
      return -1;
    }
  }
  else
  {
    return -1;
  }

  /*
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
  */
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }

  //std::random_shuffle(a.begin(), a.end());

  /*
  for(int b = 0; b<a.size(); b++){
    std::cout<<a[b]<<",";
  }
  */

  std::cout<< (get_majority_element(a, 0, a.size()-1) != -1) << '\n';
}
