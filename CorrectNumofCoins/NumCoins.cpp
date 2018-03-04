//here we will decide correct number of coins
#include <iostream>

int get_change(int m) {

	if(m == 0){
		return 0;
	}

	int minimumCoins = 999999;
	int numCoins = 0;
	int change_array[3] = {1, 3, 4};

	for(int i = 0; i<3; ++i){
		if(m >= change_array[i]){
			numCoins = get_change(m - change_array[i]);
			if(numCoins + 1 < minimumCoins) minimumCoins = numCoins + 1;
		}
	}

	
	//write your code here
	return minimumCoins;
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}
