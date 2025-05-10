#include <stdio.h> // For input and output functions
#define p printf 

int highest(int x[]) {
	int high = x[0], y; // Initialize 'high' with the first element of the array
	
	for (y=0; y<=4; y++) {
		if (x[y] > high)
        	high = x[y];
	}
	return high; // Return the highest value found in the array
}
int lowest(int x[]) {
	int low = x[0], y; // Initialize 'low' with the first element of the array
	int low, y;
	
	for (y = 0; y<=4; y++) {
		if (x[y] < low)
        	low = x[y];
	}
	return low; // Return the lowest value found in the array
}

int main() {
	
	int x[5], y, high = 0, low = 0;
	
	for (y = 0; y<=4; y++) {
		p("Enter a Number for index %d - ", y); 
		scanf("%d", &x[y]);
	}

	high = highest(x);
	low = lowest(x);
	p("\nHighest number is %d", high);
	p("\nLowest number is %d", low);
	
	return 0;
}

