#include <stdio.h>
#include <math.h>
int main(){
	int h;
	scanf("%d",&h);
	printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n",h/365,(h%365)/30,(h%365)%30);
	return 0;
}
