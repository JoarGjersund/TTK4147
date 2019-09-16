#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "array.h"
int main(){

	Array a = array_new(3);
	
	for (int i=0; i<100000; i++){
	array_insertBack(&a, 1);
}
	return -1;
}
