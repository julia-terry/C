#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//  Declaring a new struct to store patient data
struct patient {
    int age;
    char name[20];
    float balance;
};

//function to display the contents of patient_list
void display(patient arr[]){
    
    for(int k=0; k < 5; k++){
        
        cout <<"Age: " <<arr[k].age <<"       " <<"Name: " << arr[k].name <<"       " << "Balance Due $: " << arr[k].balance <<endl;
    }
}


/*function that returns a -1 if the first patient's age is less than the second,
returns 0 if the ages are equal, and returns 1 if second patient's age is less 
than the first patient's age
*/

//reference used: http://www.anyexample.com/programming/c/qsort__sorting_array_of_strings__integers_and_structs.xml
int compAge(const void *a, const void *b){
    struct patient *x = (struct patient *)a;
    struct patient *y = (struct patient *)b;
    
    if(x->age < y->age){
        return -1;
    }
    else if(x->age == y->age){
        return 0;
    }
    else{
        return 1;
    }
}

/*function that returns a -1 if the first patient's balance is less than the second,
returns 0 if the balances are equal, and returns 1 if second patient's balance is less 
than the first patient's age
*/
int compBalance(const void *a, const void *b){
    struct patient *x = (struct patient *)a;
    struct patient *y = (struct patient *)b;
    
    if(x->balance < y->balance){
        return -1;
    }
    else if(x->balance == y->balance){
        return 0;
    }
    else{
        return 1;
    }
}

/*function that returns a -1 if the first patient's name goes before the second,
returns 0 if the names are equal, and returns 1 if second patient's name goes 
before the first patient's name using the strncmp function
*/

//found help via: https://www.tutorialspoint.com/c_standard_library/c_function_strncmp.htm
int compName(const void *a, const void *b){
    struct patient *x = (struct patient *)a;
    struct patient *y = (struct patient *)b;
    
    if(strncmp(x->name, y->name, 2) < 0){
        return -1;
    }
    else if(strncmp(x->name, y->name, 2) == 0){
        return 0;
    }
    else{
        return 1;
    }
}

//  The main program
int main()
{
    int total_patients = 5;
    
    //  Storing some test data
    struct patient patient_list[5] = {
        {25, "Juan Valdez   ", 1250},
        {15, "James Morris  ", 2100},
        {32, "Tyra Banks    ", 750},
        {62, "Maria O'Donell", 375},
        {53, "Pablo Picasso ", 615}
    };
    
    //display array before sorting
    cout << "Patient List: " << endl;
    display(patient_list);
    cout << endl;
    
    //call the qsort function to sort the array by patient age
    // found help via: https://stackoverflow.com/questions/36235718/c-qsort-array-of-nested-structs
    cout << "Sorting..." << endl;
    qsort(patient_list, 5, sizeof(patient), compAge);
    cout << "Patient List - Sorted by Age: " << endl;
    display(patient_list);
    cout << endl;
    
    //call the qsort function to sort the array by patient balance
    cout << "Sorting..." << endl;
    qsort(patient_list, 5, sizeof(patient), compBalance);
    cout << "Patient List - Sorted by Balance Due: " << endl;
    display(patient_list);
    cout << endl;
    
    //call the qsort function to sort the array by patient name
    cout << "Sorting..." << endl;
    qsort(patient_list, 5, sizeof(patient), compName);
    cout << "Patient List - Sorted by Name: " << endl;
    display(patient_list);
    cout << endl;
    
    return 0;
}
