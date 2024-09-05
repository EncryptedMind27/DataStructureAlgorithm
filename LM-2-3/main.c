#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double computeMedian(double*,int); 

int main(){
	int length;
	printf("Length: ");
	scanf("%d",&length);

	double* data = (double*)malloc(sizeof(double)*length);
	for(int i=0;i<length;i++)
		scanf("%lf",&data[i]);
	printf("Median: %.2f",computeMedian(data,length));
	free(data);
	data = NULL;

	return 0;
}

double computeMedian(double* data, int length){
	// Selection Sort
    for(int i=0;i<length-1;i++){
        int max = i;
        for(int j=0;j<length-1-i;j++)  
            if(data[max]<data[j])
                max = j;
        int temp = data[length-1-i];
            data[length-1-i] = data[max];
            data[max] = temp;
    }

    for(int i=0;i<length;i++)
        printf("%.0f, ",data[i]);
    
    printf("\n");cd
	if(length%2==0){
		return((data[(length/2)-1]+data[length/2])/2);
	} else {
		return(data[length/2]);
	}
}