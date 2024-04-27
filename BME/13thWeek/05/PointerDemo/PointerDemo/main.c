#include <stdio.h>

int main(int argc, char* argv[])
{
	// Pointers of simple variables
	int variable = 19;
	int* pointerVariable = &variable; // a pointer variable that points to the memory adress where variable is stored

	// The simple value of pointerVariable is a hexadeicam (%x or %X) memory adress
	// The * operator has two meanings: 
	// - When a variable is declared int* means that the created variable is pointer variable that points to an integer variable
	// - When * is used before an already existing pointer (e.g., *pointerVariable), the * operator gives the value of the memory adress of what the pointer points to (dereferencing)
	printf("variable = %d, memory adress: %X, value in the memory adress = %d\n", variable, pointerVariable, *pointerVariable);

	// Pointers and arrays

	int array[10]; // Static array (with static size): we allocate memory for an array with 1...n elements (fixed n)
	// Load the array elements with the elements indices
	for (int i = 0; i < 10; i++)
	{
		array[i] = i;
	}
	// In C programming an array is actually a pointer that points to the memory adress of the 0th element (indexing starts with 0).
	// Therefore, in contrast to Matlab, the size of the array cannot be directly defined from the array variable, since it is only a
	// a memory adress (pointer variable). If you work with arrays, the array size or the number of array elements shall be stored in
	// a separate variable. 
	int* pointerOfElement0 = &array[0]; // The memory adress of the 0th (first) array element
	int* pointerOfElement0OtherForm = array; // The array actually stores the memory adress of the 0th array element
	
	// The elements of an array can be reached as: array[element index] (e.g., the second element array[1] because indexing starts with 0)
	// Since the elements of the array are stored into neighboring memory adresses, the array elements can be reached by dereferencing
	// the pointer defined as pointer of the 0 element + requested index (*(pointerOfElement0 + index)).
	// Furthermore, there is no need for pointerOfElement0, since the array describes the memory adress of the element 0 itself.
	// pointerOfElement0 = array = &array[0]
	for (int i = 0; i < 10; i++)
	{
		printf("array[%d] = %d, *(pointerOfElement0 + %d) = %d, *(array + %d) = %d\n", i, array[i], i, *(pointerOfElement0 + i), i, *(array + i));
	}
	return 0;
}