#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

struct Bound {
	int64_t left_m;
	int64_t right_m;
};

Bound partition3(vector<int64_t> &a, int64_t l, int64_t r){
	int64_t x = a[l];
	int64_t j = l;
	int64_t equal_elements_length = 0;

  	for (int64_t i = l + 1; i <= r; i++) {
    	if (a[i] < x) {
	      	j++;
	      	swap(a[i], a[j]);

	      	if(equal_elements_length > 0) swap(a[j+equal_elements_length], a[i]);
	      		
	

	      	
    	}
    	else if(a[i] == x){

    		++equal_elements_length;
    		swap(a[i], a[j + equal_elements_length]);

    	}
  	}
  	swap(a[l], a[j]);

  	Bound result = {j, j+equal_elements_length};
  	return result;
}

int64_t partition2(vector<int64_t> &a, int64_t l, int64_t r) {
  	int64_t x = a[l];
  	int64_t j = l;
  	for (int64_t i = l + 1; i <= r; i++) {
   		if (a[i] <= x) {
      		j++;
      		swap(a[i], a[j]);
    	}
  	}
	swap(a[l], a[j]);
	return j;
}

void randomized_quick_sort(vector<int64_t> &a, int64_t l, int64_t r) {
	if (l >= r) {
    	return;
  	}

	int64_t k = l + rand() % (r - l + 1);
	swap(a[l], a[k]);

	/*
	for(int64_t v = l; v<=r; ++v){
		std::cout<<a[v]<<", ";
	}

	std::cout<<"\n";
	*/	
	
	Bound set_m = partition3(a, l, r);

	randomized_quick_sort(a, l, set_m.left_m - 1);
	randomized_quick_sort(a, set_m.right_m + 1, r);

	/*
	int m = partition2(a, l, r);

	randomized_quick_sort(a, l, m - 1);
	randomized_quick_sort(a, m + 1, r);
	*/
}

int main() {
  int n;
	std::cin >> n;
	vector<int64_t> a(n);
  	for (size_t i = 0; i < a.size(); ++i) {
    	std::cin >> a[i];
  	}
  	randomized_quick_sort(a, 0, a.size() - 1);
  	for (size_t i = 0; i < a.size(); ++i) {
    	std::cout << a[i] << ' ';
  	}
}
