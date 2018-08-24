

         CS360 LAB Assignment #1
             DUE: 8-31-2018         

================  Part 1 ========================================

Given the following t.c and ts.s files
Under Linux, use    gcc -m32 t.c ts.s  to generate an a.out
Run a.out as        a.out one two three > outfile
DO the requirements 1 to 5 as specified below.

# ts.s file:
       .global getebp
getebp:
        movl %ebp, %eax
        ret


/************* t.c file ********************/
#include <stdio.h>
#include <stdlib.h>

int *FP;

int main(int argc, char *argv[ ], char *env[ ])
{
  int a,b,c;
  printf("enter main\n");
  
  printf("&argc=%x argv=%x env=%x\n", &argc, argv, env);
  printf("&a=%8x &b=%8x &c=%8x\n", &a, &b, &c);

(1). Write C code to print values of argc and argv[] entries

  a=1; b=2; c=3;
  A(a,b);
  printf("exit main\n");
}

int A(int x, int y)
{
  int d,e,f;
  printf("enter A\n");
  // PRINT ADDRESS OF d, e, f
  d=4; e=5; f=6;
  B(d,e);
  printf("exit A\n");
}

int B(int x, int y)
{
  int g,h,i;
  printf("enter B\n");
  // PRINT ADDRESS OF g,h,i
  g=7; h=8; i=9;
  C(g,h);
  printf("exit B\n");
}

int C(int x, int y)
{
  int u, v, w, i, *p;

  printf("enter C\n");
  // PRINT ADDRESS OF u,v,w,i,p;
  u=10; v=11; w=12; i=13;

  FP = (int *)getebp();

(2). Write C code to print the stack frame link list.


 p = (int *)&p;

(3). Print the stack contents from p to the frame of main()
     YOU MAY JUST PRINT 128 entries of the stack contents.

(4). On a hard copy of the print out, identify the stack contents
     as LOCAL VARIABLES, PARAMETERS, stack frame pointer of each function.
}




======================= Part 2 ========================================

Given: putchar(char c) of Linux, which prints a char.

2-1. Write YOUR own prints(char *s) fucntion to print a string.

Given: The following printu() function prints an unsigned integer.

typedef unsigned int u32;

char *ctable = "0123456789ABCDEF";
int  BASE = 10; 

int rpu(u32 x)
{  
    char c;
    if (x){
       c = ctable[x % BASE];
       rpu(x / BASE);
       putchar(c);
    }
}

int printu(u32 x)
{
   (x==0)? putchar('0') : rpu(x);
   putchar(' ');
}

2-2. Write YOUR ONW fucntions 

 int  printd(int x) which prints an integer (x may be negative!!!)
 int  printx(u32 x) which prints x in HEX   (start with 0x )
 int  printo(u32 x) which prints x in Octal (start with 0  )

3. REQUIREMENTS:
====================================================================
   Write YOUR own myprintf(char *fmt, ...) function to print 
         char                      by %c
         string                    by %s
         unsigned integer          by %u
         integer                   by %d
         unsigned integer in OCT   by %o
         unsigned integer in HEX   by %x
   Ignore field width and precision, just print the items as specified.

2-2. In the int main(int argc, char *argv[ ], char *env[ ]) function, 
     use YOUR myprintf() to print
              argc value
              argv strings
              env  strings
 
    myprintf("cha=%c string=%s      dec=%d hex=%x oct=%o neg=%d\n", 
	       'A', "this is a test", 100,    100,   100,  -100);

/********************** HELP INFO **************************/
NOTE: This assignment is for 32-bit GCC, which passes parameters on stack.
      Use  
               gcc -m32 t.c

      to compile your C source files.

int myprintf(char *fmt, ...)      // C compiler requires the 3 DOTs
{
   Assume the call is myprintf(fmt, a,b,c,d);
   Upon entry, the following diagram shows the stack contents.
 
                char *cp -> "...%c ..%s ..%u .. %d\n"
   HIGH               |                                              LOW 
 --------------------------- --|------------------------------------------
   | d | c | b | a | fmt |retPC| ebp | locals
 ----------------|----------------|---------------------------------------
                 |                | 
            int *ip            CPU.ebp
  
     1. Let char *cp point at the format string

     2. Let int *ip  point at the first item to be printed on stack:

  *************** ALGORITHM ****************
   Use cp to scan the format string:
       spit out each char that's NOT %
       for each \n, spit out an extra \r

   Upon seeing a %: get next char, which must be one of 'c','s','u','d', 'o','x'
   Then call YOUR

        putchar(*ip) for 'c';
        prints(*ip)  for 's';
        printu(*ip)  for 'u';
        printd(*ip)  for 'd';
        printo(*ip)  for 'o';
        printx(*ip)  for 'x';

   Advance ip to point to the next item on stack.

After implementing your myprintf() function, write C program to test your 
myprintf() function first. Then use it in the assignment.
=========================================================================










