#include <stdio.h>
#include <math.h>
int main(){
	int x,i,j[7] = {100,50,20,10,5,2,1};
	scanf("%d",&x);
	printf("%d\n",x);
	for (i=0;i<7;i++){
		printf("%d nota(s) de R$ %d,00\n",x/j[i],j[i]);
		x = x%j[i];
	}
	return 0;
}
