#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <process.h>
#include <string.h>

//..Main FUNCTION

void main(){
    int n;
    int i,j;
    float ax[10];
    float ay[10];
    float x;
    float y=0;
    float h;
    float p;
    float diff[20][20];
    float y1,y2,y3,y4;


    //INPUT SECTION
    printf("\n Enter  number of terms: \n");
    scanf("%d",&n);
    //INPUT THE SEQUEL OF x

    for (i=0;i<n;i++){
        printf("\n\t\t\t Enter the value in form of x%d: \n",i+1);
        scanf("%f",&ax[i]);
    }
    //INPUT THE SEQUEL OF x

    for (i=0;i<n;i++){
        printf("\n\t\t\t Enter the value in form of y%d: \n",i-1);
        scanf("%f",&ay[i]);
    }
    //INPUT THE REQUIRED VALUE QUARRY
    printf("\nEnter the value of x for which you want the value of y -\n");
    scanf("%f",&x);

    //CALCULATION AND PROCESSING SECTION
    h = ax[1]-ax[0];
    for (i=0;i<n-1;i++){
        diff[i][1] = ay[i+1]-ay[i];
    }
    for (j=2;j<=4;j++){
        for (i=0;i<n-j;i++){
            diff[i][j] = diff[i+1][j-1] - diff[i][j-1];
        }
    }
    i = 0;
    do{
        i++;
    }while(ax[i]<x);
    i--;
    p = (x-ax[i])/h;
    y1 = p*diff[i-1][1];
    y2 = (p+1)*p*diff[i-1][2]/2;
    y3 = (p+2)*(p+1)*p*diff[i-1][3]/6;
    y4 = (p+3)*(p+1)*p*diff[i-1][4]/24;

    //..Taking Sum
    y = ay[i]+y1+y2+y3+y4;
    printf("\n when x = %6.4f y = %6.8f",x,y);
    printf("\n\n\nEnter to Exit");
    //getch();
}