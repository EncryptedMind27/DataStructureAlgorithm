#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ROWS 5
#define COLS 5

int** generateHintMap(int**);
void displayMap(int**);

int main(void){

	srand(time(NULL));

	int** map = (int**)malloc(sizeof(int*)*ROWS);
	for(int i=0;i<ROWS;i++){
		map[i] = (int*)malloc(sizeof(int)*COLS);
		for(int j=0;j<COLS;j++) 
			map[i][j] = ((rand()%100)<70)? 0:1;
	}

	printf("Original Map: \n");
	displayMap(map);
	map = generateHintMap(map);
	printf("Hinted Map: \n");
	displayMap(map);

	for(int i=0;i<ROWS;i++){
		free(map[i]);
		map[i] = NULL;
	}
	free(map);
	map = NULL;

	return 0;
}

int** generateHintMap(int** map){
	int yAxis[] = {-1,-1,-1, 0, 0, 1, 1, 1};
	int xAxis[] = {-1, 0, 1,-1, 1,-1, 0, 1};

	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++){
			if(map[i][j] == 1){
				map[i][j] = -1;
			} else {
				int ctr = 0;
				for(int k=0;k<8;k++){
					int yPos = i + yAxis[k];
					int xPos = j + xAxis[k];

					if(yPos < ROWS && yPos >= 0 && xPos < COLS && xPos >= 0 && map[yPos][xPos] == 1)
						ctr++;
				}
				map[i][j] = ctr;
			}
		}
	}
	return map;
}

void displayMap(int** map){
	for(int i=0;i<ROWS;i++){
		for(int j=0;j<COLS;j++)
			printf("%2d ",map[i][j]);
		printf("\n");	
	}
	return;
}