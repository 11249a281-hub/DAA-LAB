#include<stdio.h>  

// Function to solve Tower of Hanoi using recursion
void towerOfHanoi(int n, char S, char D, char T){

    // Base condition: If only one disk, move it directly
    if(n == 1){
        printf("\n Move disk %d from %c to %c", n,S,D);
        return;
    }

    // Step 1: Move n-1 disks from source to auxiliary using destination
    towerOfHanoi(n-1, S, T, D);

    // Step 2: Move the nth disk from source to destination
    printf("\n Move disk %d from %c to %c", n, S, D);

    // Step 3: Move n-1 disks from auxiliary to destination using source
    towerOfHanoi(n-1, T, D, S );
}

int main(){

    int n;   // Variable to store number of disks

    // Ask the user to enter number of disks
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Call the Tower of Hanoi function
    // S = Source, D = Destination, T= Auxiliary
    towerOfHanoi(n, 'S', 'D', 'T');

    return 0;   
}
