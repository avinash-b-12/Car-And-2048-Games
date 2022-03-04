#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include "car.h"
#include "2048.h"
int main(){
        L:
        int gd = DETECT, gm;
        initgraph(&gd, &gm,"");
        int x;
        outtextxy(20,50,"Which game do you want to play");
        outtextxy(20,70,"1. 2048");
        outtextxy(20,90,"2. Car Race");
        x=getch();
        cleardevice();
       if(x=='1')
            meth_2048();
       else if(x=='2')
            meth_car();
        else{
            outtextxy(100,100,"Wrong Input Re-enter Choice");
            delay(3000);
            goto L;
        }
        cleardevice();
        outtextxy(20,100,"Do you want to play again.");
        outtextxy(20,120,"Enter Y (or) y for Yes.");
        outtextxy(20,140,"Enter N (or) n for No.");
        char dec;
        A:
        dec=getch();
        if(dec=='y' || dec=='Y' ){
            goto L;
        }
        else if(dec=='n' || dec=='N')
            exit(0);
        else
            goto A;
        getch();
        closegraph();
        return 0;
}
