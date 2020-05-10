#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

double random_number() {
	double number[12], sum=0;
	srand(clock());
	for(int i=0; i<12; ++i) {
		number[i] = (rand()%10);
		sum += number[i];
	}
	return sum/10;
}

int main() {
	int trails;
	srand(time(0));
	printf("\nEnter number of trails: ");
	scanf("%d", &trails);
	int events[10] = {0};
	
	
	for(int i=0; i<trails; i++) {
		events[(int)random_number()]++;
	}
	
	printf("\nThe distribution of the outcomes: \n");
	for(int i=0; i<10; i++) {
		printf("%d - %d: %d\n", i*10, i*10+10, events[i]); 
	}
	
	return 0;
}

