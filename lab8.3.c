#include <stdio.h>
#include<stdlib.h>
#include <time.h>
int array[1000000];

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void printArr(int a[], int n){  
	int i;  
	for (i = 0; i < n; i++){
		printf("%d ", a[i]);  
	}  
}

int main()
{
	printf("Bubble Sort\n");
	struct timeval t0;
	struct timeval t1;
	float elapsed;

	long size;
	printf("Enter number of Elements:");
	scanf("%ld",&size);
	int array[size];
	
	int num=size;
	int i,j,x,y,temp;
	srand( (unsigned) time(NULL) * getpid());
	if(array != NULL){
		for(j = 0; j < num; j++){
			array[j] = rand()%100;
		}
	}
	printf("Array before sorting:\n");
	printArr(array,num);				
	gettimeofday(&t0, NULL);
	for(x = 0; x < num - 1; x++){       
		for(y = 0; y < num - x - 1; y++){          
			if(array[y] > array[y + 1]){               
				temp = array[y];
				array[y] = array[y + 1];
				array[y + 1] = temp;
			}
		}
	}
	gettimeofday(&t1, NULL);
	elapsed = timedifference_msec(t0, t1);
	printf("\nArray after sorting:\n");
	printArr(array,num);
	printf("\n\nBubble Sort Code executed in %f milliseconds.\n", elapsed);
}
