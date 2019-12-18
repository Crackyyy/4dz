#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void qsortRecursive(int mas[], int size, int v[]) {
   
    int i = 0;
    int j = size - 1;
    int mid = mas[size / 2];

    do {
        
        while(mas[i] < mid) {
            i++;
        }
        while(mas[j] > mid) {
            j--;
        }

        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;
      
            tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            
            i++;
            j--;
        }
    } while (i <= j);

    if(j > 0) {
        
        qsortRecursive(mas, j + 1, v);
    }
    if (i < size) {
        
        qsortRecursive(&mas[i], size - i, &v[i]);
    }
}

int main() {
	int *p;
	int n;
	int a;
    printf("Enter the number of graph vertices: ");
    scanf("%d",&n);
	p = malloc((n)*sizeof(int));
	for (int i=0;i<n;i++) {
		p[i]=0;
	}
	for (int i=0;i<n;i++) {
		for (int j=i+1;j<n;j++) {
			printf("%d -- %d?",j,i);
			scanf("%d",&a);
			if (a == 1) {
				p[i]++;
				p[j]++;
			}
		}
	}
    int *v = malloc((n)*sizeof(int));
    for (int i=0;i<n;i++)
		v[i]=i;

	qsortRecursive(p,n,v);

	for (int i = n-1; i>=0; i--) {
        printf("Vershina %d imeet stepen %d\n",v[i] , p[i]);
    }
	return 0;
 }
	
	