//here we will decide correct number of coins
#include <iostream>
#include <cassert>

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

int get_change_DynamicProgrammng(int monies){
	//coins: 1, 3, 4


	int numOfCoinsForMoney[monies + 1]; //the min number of coins for each value

	numOfCoinsForMoney[0] = 0; //0 value has a min num of coins of 0

	int change_array[3] = {1, 3, 4};
	int numOfCoins = 0; //keep track of current number of coins

	for(int monies_i = 1; monies_i<monies + 1; ++monies_i){
		numOfCoinsForMoney[monies_i] = 999999; //just a large number, to get the first min number for this value. 

		for(int change_index = 0; change_index < 3; ++change_index){ //for each type of coin (only 3)

			if(change_array[change_index] <= monies_i){ //make sure you can use this coin
				numOfCoins = numOfCoinsForMoney[monies_i - change_array[change_index]] + 1;
			
				if(numOfCoins < numOfCoinsForMoney[monies_i]){ //since we gotta check each coin, (remember the first time around, it compares it to 999999)
					numOfCoinsForMoney[monies_i] = numOfCoins;
				}
			}
		}
	}

	return numOfCoinsForMoney[monies];
}

void test_solution() {
    for (int n = 0; n < 10*10; ++n){
    	assert(get_change_DynamicProgrammng(n) == get_change(n));
        std::cout<<"Passed for: "<<n<<"\n";
    }
}


int main() {
	int m;
	std::cin >> m;
	//test_solution();
	std::cout << get_change_DynamicProgrammng(m) << '\n';
}
