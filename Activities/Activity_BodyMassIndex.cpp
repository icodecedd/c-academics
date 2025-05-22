#include <stdio.h>   
#define p printf     
#define s scanf     

int main() // Added return type for main function
{
	float bmi = 0, weight, height;

	// Prompt user for input
	p("Body Mass Index:\n");
	p("\nWeight in kg: ");
	s("%f", &weight); 
	p("\nHeight in m: ");
	s("%f", &height); 

	// Calculate BMI
	bmi = weight / (height * height);

	// Display BMI result
	p("Your BMI is: %.2f", bmi);

	// Determine BMI category and provide remarks
	if (bmi <= 18.5) {
		p("\nRemarks: Underweight");
		p("\nMust do: You need to gain weight");
	} else if (bmi <= 24.9) {
		p("\nRemarks: Normal");
		p("\nMust do: Keep it up");
	} else if (bmi <= 29.9) {
		p("\nRemarks: Overweight");
		p("\nMust do: You need to lose weight");
	} else if (bmi <= 34.9) {
		p("\nRemarks: Obese Class 1");
		p("\nMust do: You need to lose weight");
	} else if (bmi <= 39.9) {
		p("\nRemarks: Obese Class 2");
		p("\nMust do: You need to lose weight");
	} else {
		p("\nRemarks: Morbid Obesity");
		p("\nMust do: You need to lose weight");
	}

	return 0; // Return 0 to indicate successful execution
}
