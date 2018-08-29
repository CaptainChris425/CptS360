#include <stdio.h>
#include <stdlib.h>
int *FP;

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
	printu(10);
	printf("\n");
	
	printd(-10);
	printf("\n");
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
	FP = (int *)getebp();
	while(*FP != 0){
		printf("FP = %8x     *FP = %8x\n",FP,*FP);
		FP = (int*)*FP;
	}
	/*
	char pause;
	scanf("%s",pause);
	p = (int *)&p;
	//TODO: MAKE SURE THIS IS PRINTING CORRECTLY,
	//CURRENTLY: Does not ever print out the variables
	//looking for it to print out 13,12,11,10
	
	while (p != FP){
		printf("p=%8x     *p=%8x\n",p,*p);
		p++;
	}
	*/
	//END TODO
}


typedef unsigned int u32;
char *ctable = "0123456789ABCDEF";

int rpu(u32 x, int base){
	char c;
	if (x){
		c = ctable[x % base];
		rpu(x/base, base);
		putchar(c);
	}
}

int printu(u32 x)
{
	(x==0)? putchar('0') : rpu(x,10);
	putchar(' ');
}

int printd(int x)
{
	if (x<0){putchar('-');rpu(x*-1,10);}
	else{(x==0)? putchar('0') : rpu(x,10);}

}

int printx(u32 x){
	//TODO: PRINT 0x AND THEN THE HEZK of the NUMBAS
	//ok
	print("0x");

	
}
