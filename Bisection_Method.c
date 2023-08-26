// PROGRAM TO IMPLEMENT BISECTION METHOD


//.....HEADER FILES TO BE USED

#include <stdio.h>
#include <math.h>
#include <conio.h>
#include <process.h>
#include <string.h>

//.....DEFINING THE FUNCTIONS (f(x)) HERE
#define F(x)   (x)*log10(x)-1.2
#define EPS 0.00000005

//.....FUNCTION PROTOTYPE DECLARATION
void Bisect();

//.....Global Function Declaration

int count=1,n;
float root = 1;

//..... MAIN FUNCTION

void main(){
    printf("\n Solution by Bisection Method\n");
    printf("\n Equation is ");
    printf("\n\t\t\t x*log(x)-1.2 = 0\n\n");
    printf("Enter the number of iterations: \n");
    scanf("%d",&n);
    Bisect();
    getch();
}

//.....FUNCTION DECLARATION
void Bisect()
{
    float x0,x1,x2;
    float f0,f1,f2;
    int i = 0;
    // Finding an approx. ROOT of given function, having a POSITIVE value
    for (x2 = 1; ;x2++)
    {
        f2 = F(x2);
        if (f2>0)
        {
            break;
        }
    }
    /*Finding an approximate Root of Given Equation having  -ve values */
    for (x1=x2-1;;x2--)
    {
        f1 = F(x1);
        if (f1<0)
        {
            break;
        }
    }
//..... PRINTING THE RESULTS
    printf("\t\t----------------------------------------------------------------------------------");
    printf("\n\t\t ITERATIONS\t\t                ROOTS\n");
    printf("\t\t----------------------------------------------------------------------------------");
    for (; count <= n; count++)
    {
        x0 = (x1+x2)/2.0;
        f0 = F(x0);
        if (f0==0)
        {
            root = x0;
        }
        if (f0*f1<0)
        {
            x2 = x0;
        }
        else
        {
            x1 = x0;
            f1 = f0;
        }
        printf("\n\t\t ITERATIONS %d",count);
        printf("\t    :\t    %f",x0);
        if (fabs((x1-x2)/x1)<EPS)
        {
            printf("\n\t\t-----------------------------------------------------------------------");
            printf("\n\t\t                  Root = %f",x0);
            printf("\n\t\t------------------------------------------------------------------------");
            getch();
        }
    }
    printf("\n\t\t\t-----------------------------------------------------------------");
    printf("\n\t\t\t ROOT = %7.4f",x0);
    printf("\n\t\t\t ITERATIONS = %d\n",count-1);
    printf("\n\t\t\t-----------------------------------------------------------------");
    getch();
}

