#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int arr[], int i, int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}

int partition(int arr[], int begin, int end){
	int pivot = (arr[begin]+arr[end])/2;
	int i = begin, j=end;
	while(i<=j)
		if(arr[i]<pivot) i++;
		else if(arr[j]>pivot) j--;
		else{
			swap(arr,i,j);
			if(++i<=j) j--;
		}
		return j;
}

void quicksort(int arr[], int begin, int end){
	if(begin>=end) return;
	int p=partition(arr,begin,end);
	quicksort(arr,begin,p);
	quicksort(arr,p+1,end);
}

int* NumGen(int range, int* retArr){
	srand(time(NULL));
	for(int i=0;i<range;i++)
		retArr[i]=(rand() % 10001);
	return retArr; 
}

int main(void){
	FILE* fptr2;
	fptr2=fopen("data.txt","w");
	fprintf(fptr2,"");
	fclose(fptr2);
	
	for(int i=0;i<100000;i+=1000){
		int range;
		range=i;
		
		//Input Array Declaration
		int roll[range];
		NumGen(range, roll);
		
		//Writing the Input Array to a file
		FILE* fptr;
		fptr=fopen("input.txt","w");
		for(int i=0;i<range;i++)
		fprintf(fptr,"%d ",roll[i]);
		fprintf(fptr,"\n");
		fclose(fptr);
		
		//Executing Quicksort
		clock_t start,end;
		start=clock();
		int len=sizeof roll/sizeof *roll;
		quicksort(roll,0,len-1);
		end=clock();
		double time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds 
		
		//Appending output to file
		fptr=fopen("input.txt","a");
		for(int i=0;i<range;i++)
		fprintf(fptr,"%d ",roll[i]);
		fclose(fptr);
		
		//Logging time
			FILE* fptr2;
			fptr2=fopen("data.txt","a");
			fprintf(fptr2,"%d %lf\n",range,time_taken);
			fclose(fptr2);
	}
	
	system("gnuplot -e \"set terminal png; set output 'plot.png'; plot 'data.txt' with lines\"");
}
