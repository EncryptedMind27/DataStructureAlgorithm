#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void jaggedArr();
void lo2_2();
void typeCast();
void practice();

int main(){
	//jaggedArr();
	//lo2_2();	
	//typeCast();
	return 0;
}

void lo2_2(){
	int** arr = (int**)malloc(sizeof(int*)*5);
	for(int i=0;i<5;i++){
		arr[i] = (int*)malloc(sizeof(int)*(i+1));
		for(int j=0;j<i+1;j++){
			arr[i][j] = j;
		}
	}

	for(int i=0;i<5;i++){
		printf("[%d]: ",i);
		for(int j=0;j<(i+1);j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
}


void jaggedArr() {
    int** arr_spec = (int**)malloc(sizeof(int*) * 7);

    // Initialize row 0 with 9 elements
    arr_spec[0] = (int*)malloc(sizeof(int) * 9);
    int temp[] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
    for (int i = 0; i < 9; i++)
        arr_spec[0][i] = temp[i];

    // Initialize row 2 with 3 elements	
    arr_spec[2] = (int*)malloc(sizeof(int) * 3);
    for (int i = 0; i < 3; i++)
        arr_spec[2][i] = 30 * (i + 1);

    // Initialize row 3 with 2 elements
    arr_spec[3] = (int*)malloc(sizeof(int) * 2);
    for (int i = 0; i < 2; i++)
        arr_spec[3][i] = 100 * (i + 1);

    // Initialize row 5 with 2 elements
    arr_spec[5] = (int*)malloc(sizeof(int) * 2);
    arr_spec[5][0] = 77;
    arr_spec[5][1] = 777;

    // Initialize row 6 with 4 elements
    arr_spec[6] = (int*)malloc(sizeof(int) * 4);
    for (int i = 0; i < 4; i++)
        arr_spec[6][i] = 2 * (i + 1);

    // Print the elements of the jagged array
    int sizes[] = {9, 0, 3, 2, 0, 2, 4};  // Sizes of the rows
    for (int i = 0; i < 7; i++) {
        printf("[%d]: ", i);
        if (sizes[i] > 0) {
            for (int j = 0; j < sizes[i]; j++) {
                printf("%d ", arr_spec[i][j]);
            }
        } 
        printf("\n");
    }

    // Free allocated memory
    for (int i = 0; i < 7; i++) {
        if (sizes[i] > 0) {
            free(arr_spec[i]);
        }
    }
    free(arr_spec);

    return;
}

void typeCast(){
	float **c;
	void *e, *d, **f;


	float *arr1 = (float*)malloc(sizeof(float) * 6);
        for(int i = 0; i < 6; i++)
            arr1[i] = (i+1) * 1.1;
	c = &arr1;
	e = &c;
	f = &e;

 	for(int i = 0 ; i < 6; i++){
        printf("%.1f ,", arr1[i]);
        printf("%.1f ,", (*c)[i]);
        printf("%.1f ,", **(float**)e + i);
        printf("%.1f ,", (**(float**)(*f)) + i);
        printf("%.1f\n", (***(float***)f) + i);
        printf("\n");
    }
//(* ... n times ... *(data_type* ... m times ... *))(void_variable)
// n: Number of dereferences (asterisks) you perform outside the parentheses
// m: Number of pointer levels in the type you're casting to (inside the parentheses).
// data_type: The data type you want to refer to (e.g., float, int).
// void_variable: The void* (or pointer to void*) you are working with.
}

//(* ... n times ... *(data_type* ... m times ... *))(void_variable)
// n: Number of dereferences (asterisks) you perform outside the parentheses
// m: Number of pointer levels in the type you're casting to (inside the parentheses).
// data_type: The data type you want to refer to (e.g., float, int).
// void_variable: The void* (or pointer to void*) you are working with.

void practice(){


}