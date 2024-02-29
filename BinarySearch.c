#include <stdio.h>

int crearArreglo(int n);
void imprimir(int *array, int n);
void insertionSort(int *array, int n);
int binarySearch(int *array, int n, int x);

int main(void) {
  int n, x, found;
  int *ptro;
  ptro = n;
  
  int *array;
  printf("¿De que tamaño quieres tu arreglo?\n");
  scanf("%d", &n);
  array = crearArreglo(n);
  
  insertionSort(array, n);
  puts("tu arreglo es:\n");
  imprimir(array, n);
  puts("\n");
  
  puts("¿Qué numero de tu arreglo quieres  buscar?\n");
  scanf("%d", &x);
  found = binarySearch(array,  n,  x);
  printf("encontrado en %d: \n", found); 
  
  free(array);
  return 0;
}


  int crearArreglo(int n){
	int *array = (int*)malloc(n*sizeof(int));
	if (array == NULL) {
    	printf("No hay espacio suficiente. \n");
	} else {
    	for (int i=0; i<n; i++) {  
        	array[i] = random() % 100;
   	 }
	}
	return array;
}

void imprimir(int *array, int n) {
	for (size_t i = 0; i < n; i++) {
    	printf("%d ", array[i]);
	}
}

void insertionSort(int *array, int n) {
    for (int i = 1; i < n; i++) {
   	 int mov = i;
   	 int insert = array[i];
    while (mov > 0 && array[mov - 1] > insert) {

   	 array[mov] = array[mov - 1];
   	 --mov;
    }
    array[mov] = insert;
	}
}


int binarySearch(int *array, int n, int x){
  int ini=0, fin=n-1, mit;
  while(ini <= fin){
    mit = (ini + fin)/2;
    if( x == array[mit]){
      return mit;
    }
    else if (x < array[mit]){
      fin = mit -1;
    }
    else{
      ini = mit +1;
    }
  }
  return -1;
}
