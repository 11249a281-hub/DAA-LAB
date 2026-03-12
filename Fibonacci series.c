#include<stdio.h>   

// Function to calculate Fibonacci number using recursion
int fib(int n){
    
    // Base case: if n is 0, return 0
    if(n == 0)
        return 0;
    
    // Base case: if n is 1, return 1
    if(n == 1)
        return 1;
    
    // Recursive case: Fibonacci number is sum of previous two numbers
    return fib(n-1) + fib(n-2);
}

int main(){
    int n;  // Variable to store the input value
    
    // Ask the user to enter a value
    printf("Enter the value of n:");
    
    // Read the integer input from the user
    scanf("%d", &n);

    // Check if the input is negative
    if(n < 0){
        printf("Invalid");   // Print error message for negative input
        return 0;            // Exit the program
    }

    // Call fib function and print the nth Fibonacci term
    printf("Fibonacci term is: %d", fib(n));

    return 0;  
}
