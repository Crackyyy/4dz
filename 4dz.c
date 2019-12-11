#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char *argv[])
{
        FILE *file;
    file= fopen("grafic.dot", "w");
    if (file == NULL){
        printf("Error");
        exit(0);
    }
    fprintf (file,"graph test{\n");
	
    int *p;
	int a;
    int N,b,i,j;
    printf("Vvedite col-vo vershin grafa: ");
    scanf ("%d", &N);
    p = malloc((N)*sizeof(int));
	for (int i=0;i<N;i++) {
		p[i]=0;
	}
	for (int i=0;i<N;i++) {
		for (int j=i+1;j<N;j++) {
			printf("%d -- %d?",j,i);
			scanf("%d",&a);
			if (a == 1) {
				p[i]++;
				p[j]++;
			}
		}
	}
	for (i=0;i<N;i++) {
		fputc(i+'0',file);
		fputc(';',file);
	}
		fputc('\n',file);
    int A[N][N];
    for (i=0; i<N;i++){
            for (j=0;j<i;j++){
				printf("%d -- %d?",i,j);
                scanf ("%d",&A[N][N]);
                getchar();
                if (A[N][N] > 0){
                    fprintf(file,"%d--%d\n",i,j);
                }
                if (A[N][N]<0){
                    fprintf(file,"%d--%d\n",j,i);
                }
            }
            puts("\n");
    }
    fprintf(file,"}");
    fclose(file);

    system("PAUSE");
    
    int *v = malloc((N)*sizeof(int));
    for (int i=0;i<N;i++)
		v[i]=i;
	
    qsortRecursive(p,N, v);
    
    for (int i = N-1; i>=0; i--) {
        printf("Vershina %d imeet stepen %d\n",v[i] , p[i]);
    }
  
    return 0;
}