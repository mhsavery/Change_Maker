#include <iostream>
using namespace std;

//Function to calculate the minimum number of coins used
int makeChange(int amount, int denominations[], int size, int a[], int b[]){  
    
	a[0] = 0;
	//Calculates the total number of coins
	for(int x = 1; x <= amount; x++) {
		a[x] = 1000;
		
		for(int y = 0; y < size; y++) {
	    		if(x >= denominations[y] && 1 + a[x-denominations[y]] < a[x] ) {
				a[x] = 1 + a[x-denominations[y]];
				b[x] = y;
	    		}
		}
	}
	return a[amount];
}
    	        
int main(){

	//Array of coin values
	int denominations[] = {1, 5, 10, 25};
  	int amount = 0;

	cout << "Input amount of money: " << endl;
	cin >> amount;

	int size = sizeof(denominations)/sizeof(denominations[0]);
	int *a = new int[amount+1];
	int *b = new int[amount+1];
	
	//Answer variable used to call the change function
	int answer = makeChange(amount, denominations, size, a, b);
	
	cout << "Minimum # of coins = " << answer << endl;
	cout << "Types of coins used: " ;

    //Finds the types of coins used
	while(amount){
		cout << denominations[b[amount]] << " ";
		amount = amount - denominations[b[amount]];
	}
        return 0;
}
