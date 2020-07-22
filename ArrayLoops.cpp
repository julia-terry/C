#include <iostream>
using namespace std;

/*
method which accepts 10 integers from user, prints the numbers in reverse order,
and prints the numbers lowest to highest
*/
int main(){
    
    int myArray[10];
    int temp;
    
    cout << "Please enter ten integers: " << endl;
    
    for(int i=0; i < 10; i++){
        cin>>myArray[i];
    }
    
    cout << "Here is your array backwards: " <<endl;
    
    for(int m=9; m >= 0; m--){
        cout<<" "<<myArray[m];
    }
    
    //bubble sort 
    for(int k=1; k < 10; k++)
	{
		for(int l=0; l < (10-k); l++)
			if(myArray[l]>myArray[l+1])
			{
				temp=myArray[l];
				myArray[l]=myArray[l+1];
				myArray[l+1]=temp;
			}
	}
    
    cout <<endl <<"Here is your assorted array: " <<endl;

    for(int j=0; j < 10; j++){
        cout<<" "<<myArray[j];
    }
    
    cout<<endl;
    
    return 0;
    
}
