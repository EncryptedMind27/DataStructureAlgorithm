#include <stdlib.h>
#include <stdio.h>

int main(){
	char* arr1 = (char*)malloc(sizeof(char)*5);
	int* v1 = (int*)malloc(sizeof(int));
	float* arr2 = (float*)malloc(sizeof(float)*3);

	arr1[] = {'a','e','g','i','s'};
	v1 = 100;
	arr2[] = {1.2f,3.5f,7.7f};

	char* a;
	int* b;
	float* c;
	void** y,**z;
	void ***x;

	a = &arr1;
	y = &a;
	x = &y;

	for(int i=0;i<5;i++){
		printf("%c ", (**void)x);
		printf("%c ", );
		printf("%c ", );
	}
	return 0;
}