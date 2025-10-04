#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int main(void) {
	int a = 1;
	int n,m,i;
	int *ptr = &a; // pointer to an int and type of pointer is defined depending 
				  // on the type of the object it points to
				  
	int **pptr = &ptr; // pointer to a pointer and you should include the address of 
					  // the pointer you are pointing to
					  
	printf("%p \n",ptr); //when printing out pointers we use %p
	printf("%d \n",*ptr);//to get the value that the pointer is pointing to we de-refernece it with *
	
	
	int arr[] = {1,2,3};
	int *ptr_array = arr; //pointer to array decays to a point to it's first element &a[0]
	printf("%d \n",*(ptr_array + 3)); // ptr_array + i points to arr[i] , same goes to arr + i
	
	// comparing and operations on pointers pointing to the same array and difference is just index comparison
	//not pointing to the same array gives UB
	
	char * ptr_str = "Hello world!"; // a pointer to string literal that is read only
									// this decays to ptr_str[0] = 'H'
	char * ptr_char_str = "Hello world"; // a pointer to array of chars 
	
	char * words[] = {
		"Hello",
		"World",
		"Weew"
	}; // array of char * (char pointers) to string literals 
	
	char (*ptr_to_arrchars)[5]; // pointer to an array of 5 chars
	
	int mat[n][m];
	printf("%p \n",&mat[i]); // pointer to the ith row 
	int (* mat_ptr)[m] = mat; // can use mat_ptr[i][j] normally
	int * mat_p = (int *) mat; // makes the matrix flat and thus you can access		
							   // from 0 to n*m-1
	char *cities[] {"el oued", "alger", "oran", "media"}; //same as words
	char **pcity = (char **)&cities; // casting is not necessary but better to have it and we can access 
									  // all of them using normal cities or pcity the same way
	
	
	
							   
							   
							
	return 0;
}
