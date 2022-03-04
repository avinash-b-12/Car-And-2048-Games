#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
int base_x=125,base_y=50,sxy=100;
int i,j,k,mallow=1,score=0;
typedef struct{
    char name[100];
    int scr;
}Read;
void initialize_global(){
    score=0;
    mallow=1;
    i=0;
    j=0;
    k=0;
}
void print_grid(){
    rectangle(125,50,525,450);
    setfillstyle(SOLID_FILL,LIGHTGRAY);
    floodfill(150,300,WHITE);
    line(225,50,225,450);
    line(325,50,325,450);
    line(425,50,425,450);
    line(125,150,525,150);
    line(125,250,525,250);
    line(125,350,525,350);
}
void fill_grid(int A[][4]){
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(A[i][j]==2){
                setfillstyle(SOLID_FILL,YELLOW);
                floodfill(base_x+sxy*j+50,base_y+sxy*i+50,WHITE);
                outtextxy(base_x+sxy*j+45,base_y+sxy*i+50,"2");
            }
            else if(A[i][j]==4){
                setfillstyle(SOLID_FILL,LIGHTRED);
                floodfill(base_x+sxy*j+50,base_y+sxy*i+50,WHITE);
                outtextxy(base_x+sxy*j+45,base_y+sxy*i+50,"4");
            }
            else if(A[i][j]==8){
                setfillstyle(SOLID_FILL,RED);
                floodfill(base_x+sxy*j+50,base_y+sxy*i+50,WHITE);
                outtextxy(base_x+sxy*j+45,base_y+sxy*i+50,"8");
            }
            else if(A[i][j]==16){
                    setfillstyle(SOLID_FILL,LIGHTCYAN);
                    floodfill(base_x+sxy*j+50,base_y+sxy*i+50,WHITE);
                    outtextxy(base_x+sxy*j+43,base_y+sxy*i+50,"16");
            }
            else if(A[i][j]==32){
                setfillstyle(SOLID_FILL,BLUE);
                floodfill(base_x+sxy*j+50,base_y+sxy*i+50,WHITE);
                outtextxy(base_x+sxy*j+43,base_y+sxy*i+50,"32");
            }
            else if(A[i][j]==64){
                setfillstyle(SOLID_FILL,LIGHTMAGENTA);
                floodfill(base_x+sxy*j+50,base_y+sxy*i+50,WHITE);
                outtextxy(base_x+sxy*j+43,base_y+sxy*i+50,"64");
            }
            else if(A[i][j]==128){
                setfillstyle(SOLID_FILL,BROWN);
                floodfill(base_x+sxy*j+50,base_y+sxy*i+50,WHITE);
                outtextxy(base_x+sxy*j+38,base_y+sxy*i+50,"128");
            }
            else if(A[i][j]==256){
                setfillstyle(SOLID_FILL,GREEN);
                floodfill(base_x+sxy*j+50,base_y+sxy*i+50,WHITE);
                outtextxy(base_x+sxy*j+38,base_y+sxy*i+50,"256");
            }
            else if(A[i][j]==512){
                setfillstyle(SOLID_FILL,WHITE);
                floodfill(base_x+sxy*j+50,base_y+sxy*i+50,WHITE);
                outtextxy(base_x+sxy*j+38,base_y+sxy*i+50,"512");
            }
            else if(A[i][j]==1024){
                setfillstyle(SOLID_FILL,LIGHTGREEN);
                floodfill(base_x+sxy*j+50,base_y+sxy*i+50,WHITE);
                outtextxy(base_x+sxy*j+35,base_y+sxy*i+50,"1028");
            }
            else if(A[i][j]==2048){
                setfillstyle(SOLID_FILL,MAGENTA);
                floodfill(base_x+sxy*j+50,base_y+sxy*i+50,WHITE);
                outtextxy(base_x+sxy*j+35,base_y+sxy*i+50,"2048");
            }
            else if(A[i][j]==4096){
                setfillstyle(SOLID_FILL,DARKGRAY);
                floodfill(base_x+sxy*j+50,base_y+sxy*i+50,WHITE);
                outtextxy(base_x+sxy*j+35,base_y+sxy*i+50,"4096");
            }
            else
                continue;
        }
    }
}
int gameover(int A[][4]){
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(A[i][j]==0){
                return 0;
            }
        }
    }
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(i==0){
                    if(j==0){
                        if(A[i][j]==A[i+1][j] || A[i][j]==A[i][j+1]){
                            return 0;
                        }
                    }
                    else if(j==3){
                        if(A[i][j]==A[i][j-1] || A[i][j]==A[i+1][j]){
                            return 0;
                        }
                    }
                    else{
                        if(A[i][j]==A[i][j-1] || A[i][j]==A[i][j+1] || A[i][j]==A[i+1][j]){
                                return 0;
                        }
                    }
                }
                else if(i==3){
                    if(j==0){
                        if(A[i][j]==A[i-1][j] || A[i][j]==A[i][j+1]){
                            return 0;
                        }
                    }
                    else if(j==3){
                        if(A[i][j]==A[i][j-1] || A[i][j]==A[i-1][j]){
                            return 0;
                        }
                    }
                    else{
                        if(A[i][j]==A[i][j+1] || A[i][j]==A[i][j-1] || A[i][j]==A[i-1][j]){
                            return 0;
                        }
                    }
                }
                else if(j==0){
                    if(i==0){
                        if(A[i][j]==A[i][j+1] || A[i][j]==A[i+1][j]){
                            return 0;
                        }
                    }
                    else if(i==3){
                        if(A[i][j]==A[i][j+1] || A[i][j]==A[i-1][j]){
                            return 0;
                        }
                    }
                    else {
                        if(A[i][j]==A[i-1][j] || A[i][j]==A[i+1][j] || A[i][j]==A[i][j+1]){
                            return 0;
                        }
                    }
                }
                else if(j==3){
                    if(i==0){
                        if(A[i][j]==A[i+1][j] || A[i][j]==A[i][j-1]){
                            return 0;
                        }
                    }
                    else if(i==3){
                        if(A[i][j]==A[i][j-1] || A[i][j]==A[i-1][j]){
                            return 0;
                        }
                    }
                    else{
                        if(A[i][j]==A[i-1][j] || A[i][j]==A[i+1][j] || A[i][j]==A[i][j-1]){
                            return 0;
                        }
                    }
                }
                else{
                    if(A[i][j]==A[i][j+1] || A[i][j]==A[i][j-1] || A[i][j]==A[i-1][j] || A[i][j]==A[i+1][j]){
                        return 0;
                    }
                }
            }
        }
    return 1;
}
void move_left(int A[][4]){
    int init[4][4];
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            init[i][j]=A[i][j];
        }
    }
    for(i=0;i<4;i++){
        for(j=1;j<4;j++){
            for(k=j;k>0;k--){
                if(A[i][k-1]==0){
                    A[i][k-1]=A[i][k];
                    A[i][k]=0;
                }
                else if(A[i][k-1]==A[i][k]){
                    A[i][k-1]+=A[i][k];
                    A[i][k]=0;
                    score+=10;
                    break;
                }
            }
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(A[i][j]!=init[i][j]){
                mallow=1;
                break;
            }
        }
    }
}
void move_right(int A[][4]){
    int init[4][4];
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            init[i][j]=A[i][j];
        }
    }
    for(i=0;i<4;i++){
        for(j=3;j>=0;j--){
            for(k=j;k<3;k++){
                if(A[i][k+1]==0){
                    A[i][k+1]=A[i][k];
                    A[i][k]=0;
                }
                else if(A[i][k+1]==A[i][k]){
                    A[i][k+1]+=A[i][k];
                    A[i][k]=0;
                    score+=10;
                    break;
                }
            }
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(A[i][j]!=init[i][j]){
                mallow=1;
                break;
            }
        }
    }
}
void move_up(int A[][4]){
    int init[4][4];
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            init[i][j]=A[i][j];
        }
    }
    for(j=0;j<4;j++){
        for(i=1;i<4;i++){
            for(k=i;k>0;k--){
                if(A[k-1][j]==0){
                    A[k-1][j]=A[k][j];
                    A[k][j]=0;
                }
                else if(A[k-1][j]==A[k][j]){
                    A[k-1][j]+=A[k][j];
                    A[k][j]=0;
                    score+=10;
                    break;
                }
            }
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(A[i][j]!=init[i][j]){
                mallow=1;
                break;
            }
        }
    }
}
void move_down(int A[][4]){
    int init[4][4];
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            init[i][j]=A[i][j];
        }
    }
    for(j=0;j<4;j++){
        for(i=2;i>=0;i--){
            for(k=i;k<3;k++){
                if(A[k+1][j]==0){
                    A[k+1][j]=A[k][j];
                    A[k][j]=0;
                }
                else if(A[k][j]==A[k+1][j]){
                    A[k+1][j]+=A[k][j];
                    A[k][j]=0;
                    score+=10;
                    break;
                }
            }
        }
    }
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(A[i][j]!=init[i][j]){
                mallow=1;
                break;
            }
        }
    }
}
int main(){
    L:
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode,"");
    int print=0;
    outtextxy(0,print,"Welcome to 2048 game.");
    print+=20;
    print+=20;

    outtextxy(0,print,"Here are some rules and regulations.");
    print+=20;

    outtextxy(0,print,"Follow the rules and have a happy gaming");
    print+=20;

    outtextxy(0,print,"1. The game starts by displaying an initial 4x4 board.");
    print+=20;

    outtextxy(0,print,"2. A single tile will be placed at a random position on the board");
    print+=20;

    outtextxy(0,print,"3. Use the following controls to make moves in the game.");
    print+=20;

    outtextxy(0,print,"4. A- Left    S- Down     D - Right     W- Up");
    print+=20;

    outtextxy(0,print,"5. The tiles will slide in the given direction to the end of the other end");
    print+=20;

    outtextxy(0,print,"   as far as there is space available.");
    print+=20;

    outtextxy(0,print,"6. If 2 tiles with same value touch each other when you perform");
    print+=20;

    outtextxy(0,print,"   the move these tiles merge together to give a single tile containing");
    print+=20;

    outtextxy(0,print,"   the sum of the previous combining tiles.");
    print+=20;

    outtextxy(0,print,"7. On every successful move you will get an additional tile with value-2 to");
    print+=20;

    outtextxy(0,print,"   the board in a random unoccupied place. This is how you get new tiles.");
    print+=20;

    outtextxy(0,print,"8. Now keep merging tiles until there is no possble combinations on the board");
    print+=20;

    outtextxy(0,print,"   and also there is no space left. At this point the game is over.");
    print+=20;

    outtextxy(0,print,"9. Each tiles combination will get you 10 points added to your score.");
    print+=20;

    outtextxy(0,print,"10. You will get a beep sound once the game is over and your score is displayed.");
    print+=20;

    outtextxy(0,print,"11. Try to beat the previous highscores so that your name too gets added to the highscores list");
    print+=40;

    outtextxy(0,print,"GOOD LUCK!!!!");
    print+=40;

    outtextxy(0,print,"Press any key to continue :\n");
    getch();
    cleardevice();

    initialize_global();
    print_grid();
    int A[][4]={{0},{0},{0},{0}};
    srand(time(0));
    int randi=rand()%4,randj=rand()%4;
    int given_x[16],given_y[16],p=0,q=0;
    char ch,c;
    int cnt=0,flag=0;
    int checkx[16],checky[16];
    while(cnt!=16){

        A[randi][randj]=2;
        fill_grid(A);
        ch=getch();
        cleardevice();
        print_grid();
        if(ch=='w' || ch=='W'){
            move_up(A);
        }
        else if(ch=='a' || ch=='A'){
            move_left(A);
        }
        else if(ch=='d' || ch=='D'){
            move_right(A);
        }
        else if(ch=='s' || ch=='S'){
            move_down(A);
        }
        fill_grid(A);
        char str[10];
        sprintf(str,"%d",score);
        outtextxy(10,20,"Score : ");
        outtextxy(60,20,str);
        if(mallow){
                Beep(1000,50);
        while(cnt!=16){
                cnt=0;
            randi=rand()%4;
            randj=rand()%4;
            for(i=0;i<16;i++){
                if(randi==checkx[i] && randj==checky[i]){
                    continue;
                }
                else{
                        flag=1;
                        break;
                }
            }
            if(flag){
                if(A[randi][randj]!=0){
                    checkx[i]=randi;
                    checky[i]=randj;
                    cnt++;
                    continue;
                }
                else{
                    break;
                }
            }
            }
        }
        sprintf(str,"%d",randi);
        outtextxy(300,10,"Randi : ");
        outtextxy(370,10,str);
        sprintf(str,"%d",randj);
        outtextxy(300,30,"Randj : ");
        outtextxy(370,30,str);
        sprintf(str,"%d",mallow);
        outtextxy(200,20,"Mallow : ");
        outtextxy(260,20,str);
            if(gameover(A)){
                delay(100);
                cleardevice();
                outtextxy(100,100,"Gameover.");
                Beep(5000,3000);
                outtextxy(100,150,"Score :");
                sprintf(str,"%d",score);
                outtextxy(150,150,str);
                Read a[5];
                FILE *fp=fopen("Highscore_2048.txt","r");
                for(i=0;i<5;i++){
                    fscanf(fp,"%s%d",a[i].name,&a[i].scr);
                    }
                for(i=0;i<5;i++){
                        if(score>=a[i].scr){
                            outtextxy(100,200,"New Highscore!!!");
                            delay(2000);
                            outtextxy(100,240,"Enter your name.");
                            char inputbuf[100]={'\n'},c;
                            int input_pos=0,the_end=0;
                            do{
                            cleardevice();
                            outtextxy(100,200,"New Highscore!!!");
                            outtextxy(100,240,"Enter your name.");
                            outtextxy(100,100,"Gameover.");
                            outtextxy(100,150,"Score :");
                            sprintf(str,"%d",score);
                            outtextxy(150,150,str);
                            outtextxy(100,260,inputbuf);
                            c=getch();
                            switch(c){
                            case 8:
                                if(input_pos){
                                        input_pos--;
                                        inputbuf[input_pos]='\n';
                                }
                            break;
                            case 13:
                                the_end=1;
                                break;
                            case 27:
                                inputbuf[0]=0;
                                the_end=1;
                                break;
                            case ' ':
                                the_end=1;
                                break;
                            default:
                                if(input_pos<99 && c>=' ' && c<='~'){
                                    inputbuf[input_pos]=c;
                                    input_pos++;
                                    inputbuf[input_pos]=0;
                                }
                            }
                        }while(!the_end);
                        char temp[100];
                        strcpy(temp,a[i].name);
                        strcpy(a[i].name,"");
                        strcpy(a[i].name,inputbuf);
                        int tmp=a[i].scr;
                        a[i].scr=score;
                        for(j=i+1;j<5;j++){
                            char t[100];
                            int ts;
                            ts=a[j].scr;
                            strcpy(t,a[j].name);
                            a[j].scr=tmp;
                            strcpy(a[j].name,temp);
                            tmp=ts;
                            strcpy(temp,t);
                        }
                        cleardevice();
                        outtextxy(125,100,"HIGH SCORES");
                        int z;
                        for(z=0;z<5;z++){
                            char str[100];
                            char number[10];
                            sprintf(number,"%d",z+1);
                            strcat(number,".");
                            outtextxy(30,150+20*z,number);
                            sprintf(str,"%d",a[z].scr);
                            outtextxy(50,150+20*z,a[z].name);
                            outtextxy(250,150+20*z,str);
                        }
                        fclose(fp);
                        fp=fopen("Highscore_2048.txt","w");
                        for(z=0;z<5;z++){
                            fprintf(fp,"%s\t%d\n",a[z].name,a[z].scr);
                        }
                        fclose(fp);
                        break;
                    }
            }
                delay(3000);
                cleardevice();
                outtextxy(100,200,"Do you want to play another 2048 game.");
                outtextxy(100,220,"Enter Y (or) y for Yes.");
                outtextxy(100,240,"Enter N (or) n for No.");
                delay(1000);
                c=getch();
                while(!(c=='Y' || c=='y' || c=='N' || c=='n')){
                    c=getch();
                }
               if(c=='Y' || c=='y'){
                    delay(0);
                    outtextxy(100,300,"Starting....");
                    delay(3000);
                    goto L;
               }
               else{
                    outtextxy(100,300,"Ending....");
                    delay(1000);
                    exit(0);
               }
            }
            mallow=0;
            A[randi][randj]=2;
    }
    getch();
    closegraph();
    M:
        printf("Score : %d",score);
    return 0;
}

