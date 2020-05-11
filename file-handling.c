#include <stdio.h>
#include <stdlib.h>

void read_data(FILE *ptr, int d[], int size) {
	int count = 0;
	while (fscanf(ptr, "%d", &d[count]) == 1 && count < size)
		(count)++;
}

double average(int d[], int size) {
	double sum = 0, avg;
	for (int i=0; i<size; i++) sum += d[i];
	avg = sum/size;
	return avg;
}

int maximum(int d[], int size) {
	int max = d[0];
	for(int i=1; i<size; i++) {
		if(d[i] > max) max = d[i];
	}
	return max;
}

int main (int argc, char *argv[])
{
	FILE *ifp, *ofp;
	
	if (argc != 3)
	{ 
		printf("Need executable, input, output\n");
		exit(1);
	}
	
	//Opening the file
	ifp = fopen(argv[1], "r+");
	ofp = fopen(argv[2], "w+");
	
	//Reading the first number into size
	int size;
	fscanf(ifp, "%d", &size);
	int d[size];
	
	//Reading data from the input
	read_data(ifp, d, size);
	
	//Printing the average of the numbers a double
	printf("\nAverage: %lf", average(d, size));
	
	//Printing the maximum value of the numbers as int
	printf("\nMaximum: %d\n", maximum(d, size));
	
	//Placing average and maximum in the output file
	fprintf(ofp, "%lf", average(d, size));
	fprintf(ofp, "%s", " ");
	fprintf(ofp, "%d", maximum(d, size));
	
	fclose(ifp);
	fclose(ofp);
}
