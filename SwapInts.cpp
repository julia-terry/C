#include <iostream>
using namespace std;

//swaps the values of two integers that it is given access to via pointer parameters
void swapInts(int *n1, int *n2){
    int newNum1 = *n1;
    int newNum2 = *n2;
    *n1 = newNum2;
    *n2 = newNum1;
}

/*
main function that asks the user for two integer values, stores them in 
variables num1 and num2, calls the swap function to swap the values of num1 & 
num2, and then prints the resultant (swapped) values of the same variables num1 
and num2
*/

int main(){
    int num1;
    int num2;
    
    cout << "Please enter two integers you want swapped: " << endl;
    cin >> num1;
    cin >> num2;
    swapInts(&num1, &num2);
    cout << "New number 1 = " << num1 << endl;
    cout << "New number 2 = " << num2;
}
