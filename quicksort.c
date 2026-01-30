#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_POINTS 200

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

void moving_average(const double *in, double *out, int n, int window)
{
    int half=window/2;
    for(int i=0;i<n;i++) {
        double sum=0.0;
        int count=0;

        for(int j=i-half;j<=i+half;j++) 
            if(j>=0&&j<n) {
                sum+=in[j]; 
                count++;
            }
        out[i]=sum/count; 
    }
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
		
		//Executing Quicksort
		clock_t start,end;
		start=clock();
		int len=sizeof roll/sizeof *roll;
		quicksort(roll,0,len-1);
		end=clock();
		double time_taken = ((double)(end-start))/CLOCKS_PER_SEC; // in seconds 

		//Logging time
			FILE* fptr2;
			fptr2=fopen("data.txt","a");
			fprintf(fptr2,"%d %lf\n",range,time_taken);
			fclose(fptr2);
	}
	
	FILE *fp = fopen("data.txt", "r");
	double x[MAX_POINTS];
	double y[MAX_POINTS];
	int n = 0;
	while (n < MAX_POINTS && fscanf(fp, "%lf %lf", &x[n], &y[n]) == 2) {
		n++;
	}
	fclose(fp);
	
	
	double y_smooth[MAX_POINTS];
	moving_average(y, y_smooth, n, 7);
	
	
	FILE *out = fopen("smoothed.txt", "w");
	for (int i = 0; i < n; i++) {
		fprintf(out, "%lf %lf\n", x[i], y_smooth[i]);
	}
	fclose(out);
	
	system("gnuplot -e \"set terminal png; set output 'plot.png'; set xlabel 'Input Size'; set ylabel 'Time Taken'; plot 'smoothed.txt' with lines\"");
}