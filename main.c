#include <conio.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define boyut 20
#define width 40


int snaketailx[100],snaketaily[100];
int snaketaillen;
int gameover,key,score;
int x,y,fruitx,fruity;

void setup() {
    gameover = 0;
    x = boyut/2;
    y = width/2;
    fruitx = rand() % width;
    fruity = rand() % boyut;
    while (fruitx==0)
        fruitx=rand()%width;
    while (fruity==0)
        fruity=rand()%width;
    score = 0;

}

void ciz() {
    system("cls");
    for (int i = 0; i<boyut; i++) {
        for (int j = 0; j<=width; j++) {
            if (j==0 || j ==width)
                printf("#");
                if (i==y && j==x)
                    printf("O");
            else if (i== fruity && j==fruitx)
                printf("*");
            else {
                int prtail = 0;
                for (int k =0; k<snaketaillen; k++) {
                    if (snaketailx[k]==j && snaketaily[k]==i) {
                        printf("o");
                        prtail=1;
                    }
                }
                if (!prtail)
                    printf(" ");
            }
        }
        printf("\n");
    }
    for (int i =0; i<width+2; i++)
        printf("-");
    printf("\n");

    printf("Score = %d",score);
    printf("\n");
    printf("Hareket etmek icim W,A,S,D kullaniniz.\n");
    printf("Oyundan cikmak icin X e basiniz.");

}

void input() {
    if (kbhit()) {
        switch (tolower(getch())) {
            case 'a':
                if (key!=2)
                    key = 1;
            break;
            case 'd':
                if (key!=1)
                    key = 2;
            break;
            case 'w':
                if (key!=4)
                    key = 3;
            break;
            case 's':
                if (key!=3)
                    key = 4;
            break;
            case 'x':
                gameover = 1;
            break;
        }
    }
}

void logic() {
int prev = snaketailx[0];
    int prevy = snaketaily[0];
    int prev2x,prev2y;
    snaketailx[0] = x;
    snaketaily[0] = y;
    for ( int i = 1; i<snaketaillen; i++) {
        prev2x = snaketailx[i];
        prev2y = snaketaily[i];
        snaketailx[i]=prev2x;
        snaketaily[i]=prev2y;
    }
    switch (key) {
        case 1:
            x--;
        break;
        case 2:
            x++;
        break;
        case 3:
            y--;
        break;
        case 4:
            y++;
        default:
            break;
    }
    if (x<0 || x>=width || y<0 || y>=boyut)
        gameover = 1;
    for (int i =0; i<snaketaillen; i++) {
        if (snaketailx[i] == x && snaketaily[i] == y)
            gameover = 1;
        }
        if (x==fruitx && y==fruity) {
            fruitx = rand() % width;
            fruity = rand() % boyut;
            while (fruitx==0)
                fruitx = rand() % width;
            while (fruity == 0)
            fruity = rand() % boyut;
            score += 10;
            snaketaillen++;
        }
    }
    void main(){
        setup();
        while (!gameover) {
            ciz();
            input();
            logic();
            Sleep(33);
        }
    }


