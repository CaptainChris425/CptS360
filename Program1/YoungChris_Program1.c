#include <stdio.h>
#include <stdlib.h>

int *F;

int main(int argc,char *argv[],char *env[])
{
	printf("Main starting...\n");
	int a,b,c;
	printf("&argc=%x argv=%x env=%x\n", &argc,argv,env);
	printf("&a=%8x &b=%8x &c=%8x\n",&a,&b,&c);
	printf("%d\n",argc);
	for(int i = 0; i < argc; i++){
		printf("%s",argv[i]);	
	}
	printf("\n");
	a=1;b=2;c=3;
	A(a,b);
	printf("Out of main...\n");
}	

int A(int x,int y){
	int d,e,f;
	printf("A starting...\n");
	printf("&d=%8x &e=%8x &f=%8x\n",&d,&e,&f);
	d=4;e=5;f=6;
	B(d,e);
	printf("Out of A...\n");
}

int B(int x, int y){
	int g,h,i;
	printf("B starting...\n");
	printf("&g=%8x &h=%8x &i=%8x\n",&g,&h,&i);
	g=7;h=8;i=9;
	C(g,h);
	printf("Out of B...\n");

}

int C(int x,int y){
	int u,v,w,i,*p;
	printf("C starting...\n");
	printf("&u=%8x &v=%8x &w=%8x,&i=%8x,&p=%8x\n",&u,&v,&w,&i,p);
	u=10;v=11;w=12;i=13;
}
