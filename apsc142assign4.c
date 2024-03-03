#include <stdio.h>
#include <math.h>
//Declare function to calculate a regular Riemann Sum.
//The parameters are the upper boundary,lower boundary and number of intervals
float calcRiemannS(float lowerB, float upperB, int intervals);
//Declare function to calculate factorial values.
//The parameter is the factorial number
int calcFactorial(int num);
//Declare function to calculate the Taylor Series approximation.
//The parameters are the lower boundary and number of terms
float approxTaylor(float lowerB, int terms);
//Declare function to calculate the Taylor Series Riemann Sum
//The parameters are the lower boundary, upper boundary, and intervals
float taylorSeriesRiemann(float lowerB, float upperB, int intervals);

//Main function
int main() {
    //Initialize variable for lower boundary of Riemann Sum
    float lowerBound = 0;
    //Initialize variable for upper boundary of Riemann Sum
    float upperBound = 0;
    //Declare variable for error in Riemann Sums
    float error;
    //Prompt user to input the upper and lower boundary of the Riemann Sum and store the values
    printf("Enter the bounds to compute the Riemann Sum:");
    scanf("%f %f", &lowerBound, &upperBound);
    /*Print the Riemann Sum using 5,25,and 100 intervals by calling calcRiemannS function*/
    printf("Riemann Sum with 5 intervals: %.2f\n", calcRiemannS(lowerBound,upperBound,5));
    printf("Riemann Sum with 25 intervals: %.2f\n", calcRiemannS(lowerBound,upperBound,25));
    printf("Riemann Sum with 100 intervals: %.2f\n", calcRiemannS(lowerBound,upperBound,100));
    printf("-----------------------------------------------------------------------\n");
    /*Print the Taylor Series Approximation at x = 3,5,and 10 terms by calling approxTaylor function*/
    printf("Taylor Series Approximation at x = %.2f with 3 terms: %.2f\n",lowerBound,approxTaylor(lowerBound,3));
    printf("Taylor Series Approximation at x = %.2f with 5 terms: %.2f\n",lowerBound,approxTaylor(lowerBound,5));
    printf("Taylor Series Approximation at x = %.2f with 10 terms: %.2f\n",lowerBound,approxTaylor(lowerBound,10));
    printf("-----------------------------------------------------------------------\n");
    /*Print the Taylor Series Riemann Sum with 5,25 and 100 intervals by calling the taylorSeriesRiemann function*/
    printf("Taylor Series Riemann Sum with 5 intervals: %.2f\n",taylorSeriesRiemann(lowerBound,upperBound,5 ));
    printf("Taylor Series Riemann Sum with 25 intervals: %.2f\n",taylorSeriesRiemann(lowerBound,upperBound,25));
    printf("Taylor Series Riemann Sum with 100 intervals: %.2f\n",taylorSeriesRiemann(lowerBound,upperBound,100 ));
    printf("-----------------------------------------------------------------------\n");
    /*Loop from 5 to 100 to obtain the intervals at 5,25,100 */
    for (int i = 5; i <=100; i++){
        if (i==5||i==25||i==100) {
            //Calculate the error in the Riemann Sums by subtracting
            // the Actual Riemann Sum from the the Taylor Series Riemann Sum,
            // then dividing the results by the Actual Riemann Sum and multiplying
            // it by 100 to convert to percentage
            error = 100 * ((taylorSeriesRiemann(lowerBound, upperBound, i)- calcRiemannS(lowerBound, upperBound, i) ) /
                           calcRiemannS(lowerBound, upperBound, i));
            printf("Error in Riemann Sums with %d intervals: %.2f%%\n", i, error);
        }
    }
    return 0;
}

/*Create function to calculate the Riemann Sum that's a representation of the actual function*/
float calcRiemannS(float lowerB, float upperB, int intervals) {
    //Initialize variable to calculate the sum
    float sum = 0;
    //Loop to obtain the area of the rectangles at every interval value
    for (int i = 0; i < intervals; i++) {
        //Calculate the change in x between every interval
        float deltaX = (upperB - lowerB) / (float)intervals;
        //Calculate the current x value starting from the lower boundary
        float currX = lowerB + (deltaX * (float)i);
        //Compute the y value at the current x value
        float fValue = expf(currX * currX);
        //Calculate the area of the rectangle with the given x and y value
        float area = fValue * deltaX;
        //Add the area of each small rectangle to obtain the entire area.
        sum += area;
    }
    //Return the sum
    return sum;
}

/*Create recursive function to calculate factorials*/
int calcFactorial(int num) {
    //Check if the factorial number is 1, then return 1
    if (num <= 1)
        return 1;
    //If the factorial number is not 1, multiply num by the factorial of num-1 and return it;
    else {
        return num * calcFactorial(num - 1);
    }
}
/*Create the Taylor Series Approximation function*/
float approxTaylor (float lowerB, int terms){
    //Initialize the approximation variable;
    float approx = 0;
    /*Loop through all terms,call the calcFactorial function to be the denominator, and sum the series */
    for (int i = 0; i< terms ;i++){
        approx += powf(lowerB*lowerB,i)/ calcFactorial(i);
    }
    return approx;
}
/*Create the Taylor Series Riemann Sum function*/
float taylorSeriesRiemann(float lowerB, float upperB, int intervals){
    //Initialize variable to calculate the sum
    float sum = 0;
    //Calculate the change in x between every interval
    float deltaX = (upperB - lowerB) / (float)intervals;
    //Loop to obtain the area of the rectangles at every interval value
    for (int i = 0; i < intervals; i++) {
        //Calculate the current x value starting from the lower boundary
        float currX = lowerB + (deltaX * (float)i);
        //Compute the y value at the current x value
        float fValue = approxTaylor(currX,10);
        //Calculate the area of the rectangle with the given x and y value
        float area = fValue * deltaX;
        //Add the area of each small rectangle to obtain the entire area.
        sum += area;
    }
    //Return the total sum
    return sum;
}



