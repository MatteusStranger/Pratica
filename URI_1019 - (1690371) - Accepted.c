#include <stdio.h>
#include <math.h>
int main(){
	int h;
	scanf("%d",&h);
	printf("%d:%d:%d\n",h/3600,(h%3600)/60,(h%3600)%60);
	return 0;
}
