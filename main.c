#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
typedef struct{ //array of struct
char name[30];
int score;
}topten;
struct player{ //struct has scores
int color;
int steps;
int score;
}player1,player2;
struct time{
int minutes;
int seconds;
}time1;

int checkScan(int maxN,int *choice);
int checkBox(int x, int y,int c,int p, char a[][c]);
void scan(int a, int b);
void colour();
void green();
void red();
void yellow();
void reset();
void computer(int *index1, int *index2, int n, char a[][n], int play, int *box, int *i);
void Save(int choice,int n,char array[n][n],struct player player1,struct player player2,int play,int file,int rem);
void load(int *choice,int file,int*n,int*rem,int*play,int*steps,int*score,int*steps2,int*score2);
void load1(int file,int n,char a[n][n]);
void Redo(int x,int y,int c,char a[][c],int p);
void Undo(int x,int y,int c, char a[][c]);
void copyArray(int c,char a[][c],char a2[][c]);
int k=0;
void savec(int k);
void loadc(int *k);
void savet(int k,topten p[k]);
void loadt(int k,topten p[k]);
void sorting(int k, topten a[k]);
void printt(int k,topten a[k]);
int repet(char name[30],int score,int k,topten a[k]);
int comparison(char name[30],char name1[30]);

int main(){
  char temp[30];
    topten p[100];
    loadc(&k);
    loadt(k,p);
    int u1,rem,s;
    int choice1, choice2, choice3, n, i1, play1=1;
    char mlha[100];   char mlha2[100];char mlha3[100];
    player1.score=0;
    player1.steps=0;
    player2.score=0;
    player2.steps=0;
    time1.minutes=0;
    time1.seconds=0;
    char arr1[5][5];
    char arr11[5][5];
    char arr2[11][11];
    char arr22[11][11];
    int winner;


    //main menu
    menu:
colour();
    yellow();
    printf("\t\t\t\t\t<<<DOTS AND BOXES>>>\n");
    reset();

  printf("\t\t\t\t\t1-Start Game\n\t\t\t\t\t2-Load Game\n\t\t\t\t\t3-Top 10 Players\n\t\t\t\t\t4-Exit\n");
        while(1){
        choice1=404;
        scanf("%d", &choice1);
   if(choice1==404||choice1>4||choice1<1){
    fgets(mlha2,100,stdin);
      printf("invalid choose a valid choice\n");
      continue;}
    else break;
   }
system("cls");
if(choice1==1){ //mode
  printf("1-Human VS Human\n2-VS computer\n");
   while(1){
        choice2=404;
        scanf("%d", &choice2);
   if(choice2==404||choice2>2||choice2<1){
    fgets(mlha3,100,stdin);
      printf("invalid choose a valid choice\n");
      continue;}
    else {break;
   }
   }
   system("cls");
        //start menu,difficulty
    printf("1-Beginner\n2-Expert\n");
     while(1){
        choice3=404;
        scanf("%d", &choice3);
   if(choice3==404||choice3>2||choice3<1){
    fgets(mlha3,100,stdin);
      printf("invalid choose a valid choice\n");
      continue;}
    else {break;
   }
     }
system("cls");
if(choice3==1){
    n=5; //size of array
    i1=12; //max moves
    rem=i1;
    for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        if(i%2==0){
            if(j%2==0){
                arr1[i][j]=46;
            }else{
            arr1[i][j]=32;
            }
        }else{
        arr1[i][j]=32;
        }
    }
}
}else if(choice3==2){
    n=11;
    i1=60;
    rem=i1;
    for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        if(i%2==0){
            if(j%2==0){
                arr2[i][j]=46;
            }else{
            arr2[i][j]=32;
            }
        }else{
        arr2[i][j]=32;
        }
    }
}
}

}else if(choice1==2){//load
    int index;
            printf("file 10/11/12 ");
 while(1){
        index=404;
        scanf("%d", &index);
   if(index==404||index<10||index>12){
    fgets(mlha3,100,stdin);
      printf("invalid choose a valid choice\n");
      continue;}
    else {break;
   }
     }
    load(&choice2,index,&n,&rem,&play1,&player1.steps,&player1.score,&player2.steps,&player2.score);//get data
    if(n==5){
         load1(index,5,arr1);//load last grid in biginner mode
    }else if(n==11){
    load1(index,11,arr2);//load last grid in expert mode
    }


}
//top ten
else if(choice1==3){

            sorting(k,p);
            printt(k,p);

}//exit
else if(choice1==4){
printf("Thanks!");
return 0;
}

    int index1, index2;
int i=0, box;
//start human biginner,load human
if((choice1==1&&choice2==1&&choice3==1)||(choice1==2&&n==5&&choice2==1)){
colour();
reset();
Sleep(3);
time_t begin;
begin = time(NULL);

while (rem!=0){
    if(play1%2!=0){
    //player1
 yellow();
    printf("Enter index1 & index2:\n(press 30 to undo, 40 to redo, 50 to exit)");
    reset();
    //check char
    s=checkScan(n,&index1);
    //undo
if(s==0){
    checkScan(n,&index2);
}else if(s==1){
if (checkBox(index1, index2, n, box, arr1)!=0){
    player1.score--;
        Undo(index1,index2,n, arr11);
    player1.steps--;
}else{
player2.steps--;
        Undo(index1,index2,n, arr11);
play1--;
}
rem++;
    copyArray(n,arr11,arr1);

    system("cls");
    goto timeg;
}else if(s==2){//redo
Redo(index1,index2,n, arr1, box);
                    play1++;
                    rem--;
                    player1.steps++;
                    if(checkBox(index1, index2, n, box, arr1)!=0)
                    {
                        player1.score++;
                        play1--;
                    }

        system("cls");
           goto timeg;
}else if(s==3){ //save
    int index;
    printf("choose file number: (10/11/12)");
         while(1){
        index=404;
        scanf("%d", &index);
   if(index==404||index<10||index>12){
    fgets(mlha3,100,stdin);
      printf("invalid choose a valid choice\n");
      continue;}
    else {break;
   }
     }
            Save(choice2,n,arr1,player1,player2,play1,index,rem);
            goto menu;
                   system("cls");
}
    box=49;
        system("cls");
}
    else {
    //player2
 yellow();
    printf("Enter index1 & index2:\n(press 30 to undo, 40 to redo, 50 to exit)");
    reset();
    s=checkScan(n,&index1);
if(s==0){
    checkScan(n,&index2);
}else if(s==1){
if (checkBox(index1, index2, n, box, arr1)!=0){
    player2.score--;
        Undo(index1,index2,n, arr11);
    player2.steps--;
}else{
player1.steps--;
        Undo(index1,index2,n, arr11);
play1--;
}
rem++;
    copyArray(n,arr11,arr1);

    system("cls");
    goto timeg;
}else if(s==2){
Redo(index1,index2,n, arr1, box);
                    play1++;
                    rem--;
                    player2.steps++;
                    if(checkBox(index1, index2, n, box, arr1)!=0)
                    {
                        player2.score++;
                        play1--;
                    }

        system("cls");
           goto timeg;
}else if(s==3){
    int index;
    printf("choose file number: (10/11/12)");
         while(1){
        index=404;
        scanf("%d", &index);
   if(index==404||index<10||index>12){
    fgets(mlha3,100,stdin);
      printf("invalid choose a valid choice\n");
      continue;}
    else {break;
   }
     }
            Save(choice2,n,arr1,player1,player2,play1,index,rem);
            goto menu;
                   system("cls");
}
    box=50;
        system("cls");
}
//game
    if(isspace(arr1[index1][index2])){
     if((index1%2==0 && index2%2!=0)||(index1%2!=0 && index2%2==0)){
    arr1[index1][index2]=box;
   // i++;
    rem--;
    copyArray(n,arr1,arr11);
    if(play1%2!=0){
            player1.steps++;
    }else{
        player2.steps++;
    }
    if(checkBox(index1, index2, n, box, arr1)!=0){
            if(play1%2!=0){
                player1.score=player1.score+checkBox(index1, index2, n, box, arr1);
            }else{
            player2.score=player2.score+checkBox(index1, index2, n, box, arr1);
            }
    }else{
                play1++;
    }
 }else{
     green();
    printf("Not valid\n");
    reset();
 }
}else{
     green();
    printf("Not valid\n");
    reset();
}

timeg:
    printf("  ");
    for(int j=0; j<n; j++) //column numbers
    {
        printf("%d ",j);

    }
    printf("\n");
    for(int i=0; i<n; i++)
    {
        if(i<10)//row numbers
        {
            printf("%d ",i);
        }
        else
        {
            printf("%d",i);
        }
        for(int j=0; j<n; j++)//grid
        {
            if (arr1[i][j]==46 || arr1[i][j]==32)
            {
                printf("%c ",arr1[i][j]); //print points and spaces
            }
            else
            {
                if (arr1[i][j]==49)
                {
                    green();   //colour of player 1
                }
                else
                {
                    red();   //colour of player 2
                }
                if(i%2==0 && j%2!=0)
                {
                    printf("%c ",196);
                }
                else if(i%2!=0 && j%2==0)
                {
                    printf("%c ",124);
                }
                else if(i%2!=0 && j%2!=0)
                {
                    printf("%c ",arr1[i][j]);
                }
                reset();
            }
        }
        printf("\n");
    }
    printf("PLAYER1 STEPS=%d PLAYER2 STEPS=%d\n", player1.steps, player2.steps);
    printf("PLAYER1 SCORE=%d PLAYER2 SCORE=%d\n", player1.score, player2.score);
    printf("REMAINING LINES:%d\n",rem);
    time_t end;
end = time(NULL);
time_t time;
time=end-begin;
time1.minutes=time/60;
time1.seconds=time%60;
printf("%d minute\n%d second\n", time1.minutes, time1.seconds);
}
//end game
if(rem==0&&choice2==1){
printf("The Game Has Ended\n");
//if there is a winner
if((player1.score>player2.score)||(player2.score>player1.score)){
if(player1.score>player2.score){
        winner=player1.score;
        red();
    printf("CONGRATULATION,PLAYER 1 WINN!!\n");
    reset();

    }

else if(player2.score>player1.score){
    winner=player2.score;
     red();
    printf("CONGRATULATION,PLAYER 2 WINN!!\n");

    reset();}
    printf("ENTER WINNER NAME: \n");
    fflush(stdin);
            fgets(temp,30,stdin);
            int f=repet(temp,winner,k,p);
             if(f==0)

            {
                memcpy(p[k].name,temp,30);
                p[k].score=winner;
                k++;
            }
            savet(k,p);
            savec(k);


}
else if(player1.score==player2.score){
    red();
        printf("TIE :(\n");
    reset();
}
}
else if(rem==0&&choice2==2){
printf("The Game Has Ended\n");
if((player1.score>player2.score)||(player2.score>player1.score)){
if(player1.score>player2.score){
        winner=player1.score;
        red();
    printf("CONGRATULATION,PLAYER 1 WINN!!\n");
    reset();
    printf("ENTER WINNER NAME: \n");
fflush(stdin);
//check if it is already exists
            fgets(temp,30,stdin);
            int f=repet(temp,winner,k,p);
             if(f==0)

            {
                memcpy(p[k].name,temp,30);
                p[k].score=winner;
                k++;
            }

            savet(k,p);
            savec(k);
    }

}
else if(player2.score>player1.score){
    winner=player2.score;
     red();
    printf("computer win :(\n");

    reset();}

else if(player1.score==player2.score){
    red();
        printf("TIE :(\n");
    reset();


}
}
}
//start human expert
if((choice1==1&&choice2==1&&choice3==2)||(choice1==2&&n==11&&choice2==1)){
colour();
reset();
Sleep(3);
time_t begin;
begin = time(NULL);
while (rem!=0){
    if(play1%2!=0){
    //player1
 yellow();
    printf("Enter index1 & index2:\n(press 30 to undo, 40 to redo, 50 to exit)");
    reset();
    s=checkScan(n,&index1);
if(s==0){
    checkScan(n,&index2);
}else if(s==1){
    if (checkBox(index1, index2, n, box, arr2)!=0){
    player1.score--;
        Undo(index1,index2,n, arr22);
    player1.steps--;
}else{
player2.steps--;
        Undo(index1,index2,n, arr22);
play1--;
}
rem++;
   copyArray(n,arr22,arr2);

    system("cls");
    goto timeg1;
}else if(s==2){
        Redo(index1,index2,n, arr2,box);
                    play1++;
                    rem--;
                    player1.steps++;
                    if(checkBox(index1, index2, n, box, arr2)!=0)
                    {
                        player1.score++;
                        play1--;
                    }

        system("cls");
        goto timeg1;
}else if(s==3){
    int index;
    printf("choose file number: (10/11/12)");
         while(1){
        index=404;
        scanf("%d", &index);
   if(index==404||index<10||index>12){
    fgets(mlha3,100,stdin);
      printf("invalid choose a valid choice\n");
      continue;}
    else {break;
   }
     }
            Save(choice2,n,arr2,player1,player2,play1,index,rem);
            goto menu;
                   system("cls");
}
    box=49;
        system("cls");
}

    else {
    //player1
 yellow();
    printf("Enter index1 & index2:\n(press 30 to undo, 40 to redo, 50 to exit)");
    reset();
    s=checkScan(n,&index1);
if(s==0){
    checkScan(n,&index2);
}else if(s==1){
   if (checkBox(index1, index2, n, box, arr2)!=0){
    player2.score--;
        Undo(index1,index2,n, arr22);
    player2.steps--;
}else{
player1.steps--;
       Undo(index1,index2,n, arr22);
play1--;
}
rem++;
   copyArray(n,arr22,arr2);

    system("cls");
    goto timeg1;
}else if(s==2){
        Redo(index1,index2,n, arr2,box);
                    play1++;
                    rem--;
                    player2.steps++;
                    if(checkBox(index1, index2, n, box, arr2)!=0)
                    {
                        player2.score++;
                        play1--;
                    }
        system("cls");
        goto timeg1;
}else if(s==3){
    int index;
    printf("choose file number: (10/11/12)");
         while(1){
        index=404;
        scanf("%d", &index);
   if(index==404||index<10||index>12){
    fgets(mlha3,100,stdin);
      printf("invalid choose a valid choice\n");
      continue;}
    else {break;
   }
     }
            Save(choice2,n,arr2,player1,player2,play1,index,rem);
            goto menu;
                   system("cls");
}
    box=50;
        system("cls");
}

    if(isspace(arr2[index1][index2])){
     if((index1%2==0 && index2%2!=0)||(index1%2!=0 && index2%2==0)){
    arr2[index1][index2]=box;
    //i++;
    rem--;
    copyArray(n,arr2,arr22);
    if(play1%2!=0){
            player1.steps++;
    }else{
        player2.steps++;
    }
    if(checkBox(index1, index2, n, box, arr2)!=0){
            if(play1%2!=0){
                player1.score=player1.score+checkBox(index1, index2, n, box, arr2);
            }else{
            player2.score=player2.score+checkBox(index1, index2, n, box, arr2);
            }
    }else{
                play1++;
    }
 }else{
     green();
    printf("Not valid\n");
    reset();
 }
}else{
     green();
    printf("Not valid\n");
    reset();
}

timeg1:
    printf("  ");
    for(int j=0; j<n; j++) //column numbers
    {
        printf("%d ",j);

    }
    printf("\n");
    for(int i=0; i<n; i++)
    {
        if(i<10)//row numbers
        {
            printf("%d ",i);
        }
        else
        {
            printf("%d",i);
        }
        for(int j=0; j<n; j++)//grid
        {
            if (arr2[i][j]==46 || arr2[i][j]==32)
            {
                printf("%c ",arr2[i][j]); //print points and spaces
            }
            else
            {
                if (arr2[i][j]==49)
                {
                    green();   //colour of player 1
                }
                else
                {
                    red();   //colour of player 2
                }
                if(i%2==0 && j%2!=0)
                {
                    printf("%c ",196);
                }
                else if(i%2!=0 && j%2==0)
                {
                    printf("%c ",124);
                }
                else if(i%2!=0 && j%2!=0)
                {
                    printf("%c ",arr2[i][j]);
                }
                reset();
            }
        }
        printf("\n");
    }
    printf("PLAYER1 STEPS=%d PLAYER2 STEPS=%d\n", player1.steps, player2.steps);
    printf("PLAYER1 SCORE=%d PLAYER2 SCORE=%d\n", player1.score, player2.score);
    printf("REMAINING LINES:%d\n",rem);
    time_t end;
end = time(NULL);
time_t time;
time=end-begin;
time1.minutes=time/60;
time1.seconds=time%60;
printf("%d minutes\n%d second\n", time1.minutes, time1.seconds);
}

if(rem==0&&choice2==1){
printf("The Game Has Ended\n");
if((player1.score>player2.score)||(player2.score>player1.score)){
if(player1.score>player2.score){
        winner=player1.score;
        red();
    printf("CONGRATULATION,PLAYER 1 WINN!!\n");
    reset();

    }

else if(player2.score>player1.score){
    winner=player2.score;
     red();
    printf("CONGRATULATION,PLAYER 2 WINN!!\n");

    reset();}
    printf("ENTER WINNER NAME: \n");
    fflush(stdin);
            fgets(temp,30,stdin);
            int f=repet(temp,winner,k,p);
             if(f==0)

            {
                memcpy(p[k].name,temp,30);
                p[k].score=winner;
                k++;
            }
            savet(k,p);
            savec(k);


}
else if(player1.score==player2.score){
    red();
        printf("TIE :(\n");
    reset();
}
}
else if(rem==0&&choice2==2){
printf("The Game Has Ended\n");
if((player1.score>player2.score)||(player2.score>player1.score)){
if(player1.score>player2.score){
        winner=player1.score;
        red();
    printf("CONGRATULATION,PLAYER 1 WINN!!\n");
    reset();
    printf("ENTER WINNER NAME: \n");
fflush(stdin);
            fgets(temp,30,stdin);
            int f=repet(temp,winner,k,p);
             if(f==0)

            {
                memcpy(p[k].name,temp,30);
                p[k].score=winner;
                k++;
            }

            savet(k,p);
            savec(k);
    }

}
else if(player2.score>player1.score){
    winner=player2.score;
     red();
    printf("computer win :(\n");

    reset();}

else if(player1.score==player2.score){
    red();
        printf("TIE :(\n");
    reset();


}}}//start compu,biginner
if((choice1==1&&choice2==2&&choice3==1)||(choice1==2&&n==5&&choice2==2)){
colour();
reset();
Sleep(3);
time_t begin;
begin = time(NULL);
while (rem!=0){
if(play1%2!=0){
    //player1
 yellow();
    printf("Enter index1 & index2:\n(press 30 to undo, 40 to redo, 50 to exit)");
    reset();
    s=checkScan(n,&index1);
if(s==0){
    checkScan(n,&index2);
}else if(s==1){
if (checkBox(index1, index2, n, box, arr2)!=0){
    player1.score--;
        Undo(index1,index2,n, arr11);
    player1.steps--;
}else{
player2.steps--;
        Undo(index1,index2,n, arr11);
play1--;
}
rem++;
   copyArray(n,arr11,arr1);

    system("cls");
    goto timeg2;
}else if(s==2){
Redo(index1,index2,n, arr1,box);
                    play1++;
                    rem--;
                    player1.steps++;
                    if(checkBox(index1, index2, n, box, arr1)!=0)
                    {
                        player1.score++;
                        play1--;
                    }
        system("cls");
           goto timeg2;
}else if(s==3){
    int index;
    printf("choose file number: (10/11/12)");
         while(1){
        index=404;
        scanf("%d", &index);
   if(index==404||index<10||index>12){
    fgets(mlha3,100,stdin);
      printf("invalid choose a valid choice\n");
      continue;}
    else {break;
   }
     }
            Save(choice2,n,arr1,player1,player2,play1,index1,rem);
            goto menu;
                   system("cls");
}
    box=49;
        system("cls");
}else{
    while(1){
    index1=(rand()%n);
index2=(rand()%n);
    box=50;
        if(isspace(arr1[index1][index2])){
     if(index1%2==0 && index2%2!=0){
    break;
 }else if(index1%2!=0 && index2%2==0){
    break;
 }else{
    continue;
 }
}else{
continue;
}
}
    box=50;
        system("cls");
}

    if(isspace(arr1[index1][index2])){
     if((index1%2==0 && index2%2!=0)||(index1%2!=0 && index2%2==0)){
    arr1[index1][index2]=box;
   // i++;
    rem--;
     copyArray(n,arr1,arr11);
    if(play1%2!=0){
            player1.steps++;
    }else{
        player2.steps++;
    }
    if(checkBox(index1, index2, n, box, arr1)!=0){
            if(play1%2!=0){
                player1.score=player1.score+checkBox(index1, index2, n, box, arr1);
            }else{
            player2.score=player2.score+checkBox(index1, index2, n, box, arr1);
            }
    }else{
                play1++;
    }
 }else{
     green();
    printf("Not valid\n");
    reset();
 }
}else{
     green();
    printf("Not valid\n");
    reset();
}

timeg2:
    printf("  ");
    for(int j=0; j<n; j++) //column numbers
    {
        printf("%d ",j);

    }
    printf("\n");
    for(int i=0; i<n; i++)
    {
        if(i<10)//row numbers
        {
            printf("%d ",i);
        }
        else
        {
            printf("%d",i);
        }
        for(int j=0; j<n; j++)//grid
        {
            if (arr1[i][j]==46 || arr1[i][j]==32)
            {
                printf("%c ",arr1[i][j]); //print points and spaces
            }
            else
            {
                if (arr1[i][j]==49)
                {
                    green();   //colour of player 1
                }
                else
                {
                    red();   //colour of player 2
                }
                if(i%2==0 && j%2!=0)
                {
                    printf("%c ",196);
                }
                else if(i%2!=0 && j%2==0)
                {
                    printf("%c ",124);
                }
                else if(i%2!=0 && j%2!=0)
                {
                    printf("%c ",arr1[i][j]);
                }
                reset();
            }
        }
        printf("\n");
    }
    printf("PLAYER1 STEPS=%d PLAYER2 STEPS=%d\n", player1.steps, player2.steps);
    printf("PLAYER1 SCORE=%d PLAYER2 SCORE=%d\n", player1.score, player2.score);
    printf("REMAINING LINES:%d\n",rem);
    time_t end;
end = time(NULL);
time_t time;
time=end-begin;
time1.minutes=time/60;
time1.seconds=time%60;
printf("%d minute\n%d second\n", time1.minutes, time1.seconds);
}

if(rem==0&&choice2==1){
printf("The Game Has Ended\n");
if((player1.score>player2.score)||(player2.score>player1.score)){
if(player1.score>player2.score){
        winner=player1.score;
        red();
    printf("CONGRATULATION,PLAYER 1 WINN!!\n");
    reset();

    }

else if(player2.score>player1.score){
    winner=player2.score;
     red();
    printf("CONGRATULATION,PLAYER 2 WINN!!\n");

    reset();}
    printf("ENTER WINNER NAME: \n");
    fflush(stdin);
            fgets(temp,30,stdin);
            int f=repet(temp,winner,k,p);
             if(f==0)

            {
                memcpy(p[k].name,temp,30);
                p[k].score=winner;
                k++;
            }
            savet(k,p);
            savec(k);


}
else if(player1.score==player2.score){
    red();
        printf("TIE :(\n");
    reset();
}
}
else if(rem==0&&choice2==2){
printf("The Game Has Ended\n");
if((player1.score>player2.score)||(player2.score>player1.score)){
if(player1.score>player2.score){
        winner=player1.score;
        red();
    printf("CONGRATULATION,PLAYER 1 WINN!!\n");
    reset();
    printf("ENTER WINNER NAME: \n");
fflush(stdin);
            fgets(temp,30,stdin);
            int f=repet(temp,winner,k,p);
             if(f==0)

            {
                memcpy(p[k].name,temp,30);
                p[k].score=winner;
                k++;
            }

            savet(k,p);
            savec(k);
    }

}
else if(player2.score>player1.score){
    winner=player2.score;
     red();
    printf("computer win :(\n");

    reset();}

else if(player1.score==player2.score){
    red();
        printf("TIE :(\n");
    reset();


}
}}
//stat,load, compu expert
if((choice1==1&&choice2==2&&choice3==2)||(choice1==2&&n==11&&choice2==2)){
colour();
reset();
Sleep(3);
time_t begin;
begin = time(NULL);
while (rem!=0){
if(play1%2!=0){
    //player1
         yellow();
    printf("Enter index1 & index2:\n(press 30 to undo, 40 to redo, 50 to exit)");
    reset();
    s=checkScan(n,&index1);
if(s==0){
    checkScan(n,&index2);
}else if(s==1){
if (checkBox(index1, index2, n, box, arr2)!=0){
    player1.score--;
            Undo(index1,index2,n, arr22);
    player1.steps--;
}else{
player2.steps--;
         Undo(index1,index2,n, arr22);
play1--;
}
rem++;
copyArray(n,arr22,arr2);

    system("cls");
    goto timeg3;
}else if(s==2){
 Redo(index1,index2,n, arr2,box);
                    play1++;
                    rem--;
                    player1.steps++;
                    if(checkBox(index1, index2, n, box, arr2)!=0)
                    {
                        player1.score++;
                        play1--;
                    }
        player2.steps--;
                    player1.steps++;
        system("cls");
           goto timeg3;
}else if(s==3){
    int index;
    printf("choose file number: (10/11/12)");
         while(1){
        index=404;
        scanf("%d", &index);
   if(index==404||index<10||index>12){
    fgets(mlha3,100,stdin);
      printf("invalid choose a valid choice\n");
      continue;}
    else {break;
   }
     }
            Save(choice2,n,arr2,player1,player2,play1,index1,rem);
            goto menu;
                   system("cls");
}
    box=49;
        system("cls");
}else{
    while(1){
    index1=(rand()%n);
index2=(rand()%n);
    box=50;
        if(isspace(arr2[index1][index2])){
     if(index1%2==0 && index2%2!=0){
    break;
 }else if(index1%2!=0 && index2%2==0){
    break;
 }else{
    continue;
 }
}else{
continue;
}
}
    box=50;
        system("cls");
}

    if(isspace(arr2[index1][index2])){
     if((index1%2==0 && index2%2!=0)||(index1%2!=0 && index2%2==0)){
    arr2[index1][index2]=box;
    i++;
    rem--;
    copyArray(n,arr2,arr22);
    if(play1%2!=0){
            player1.steps++;
    }else{
        player2.steps++;
    }
    if(checkBox(index1, index2, n, box, arr2)!=0){
            if(play1%2!=0){
                player1.score=player1.score+checkBox(index1, index2, n, box, arr2);
            }else{
            player2.score=player2.score+checkBox(index1, index2, n, box, arr2);
            }
    }else{
                play1++;
    }
 }else{
     green();
    printf("Not valid\n");
    reset();
 }
}else{
    green();
printf("Not valid\n");
reset();
}

timeg3:
    printf("  ");
    for(int j=0; j<n; j++) //column numbers
    {
        printf("%d ",j);

    }
    printf("\n");
    for(int i=0; i<n; i++)
    {
        if(i<10)//row numbers
        {
            printf("%d ",i);
        }
        else
        {
            printf("%d",i);
        }
        for(int j=0; j<n; j++)//grid
        {
            if (arr2[i][j]==46 || arr2[i][j]==32)
            {
                printf("%c ",arr2[i][j]); //print points and spaces
            }
            else
            {
                if (arr2[i][j]==49)
                {
                    green();   //colour of player 1
                }
                else
                {
                    red();   //colour of player 2
                }
                if(i%2==0 && j%2!=0)
                {
                    printf("%c ",196);
                }
                else if(i%2!=0 && j%2==0)
                {
                    printf("%c ",124);
                }
                else if(i%2!=0 && j%2!=0)
                {
                    printf("%c ",arr2[i][j]);
                }
                reset();
            }
        }
        printf("\n");
    }
    printf("PLAYER1 STEPS=%d PLAYER2 STEPS=%d\n", player1.steps, player2.steps);
    printf("PLAYER1 SCORE=%d PLAYER2 SCORE=%d\n", player1.score, player2.score);
    printf("REMAINING LINES:%d\n",rem);
    time_t end;
end = time(NULL);
time_t time;
time=end-begin;
time1.minutes=time/60;
time1.seconds=time%60;
printf("%d minute\n%d second\n", time1.minutes, time1.seconds);
}

if(rem==0&&choice2==1){
printf("The Game Has Ended\n");
if((player1.score>player2.score)||(player2.score>player1.score)){
if(player1.score>player2.score){
        winner=player1.score;
        red();
    printf("CONGRATULATION,PLAYER 1 WINN!!\n");
    reset();

    }

else if(player2.score>player1.score){
    winner=player2.score;
     red();
    printf("CONGRATULATION,PLAYER 2 WINN!!\n");

    reset();}
    printf("ENTER WINNER NAME: \n");
fflush(stdin);
            fgets(temp,30,stdin);
            int f=repet(temp,winner,k,p);
             if(f==0)

            {
                memcpy(p[k].name,temp,30);
                p[k].score=winner;
                k++;
            }

            savet(k,p);
            savec(k);


}
else if(player1.score==player2.score){
    red();
        printf("TIE :(\n");
    reset();
}
}
else if(rem==0&&choice2==2){
    printf("The Game Has Ended\n");
if((player1.score>player2.score)||(player2.score>player1.score)){
if(player1.score>player2.score){
        winner=player1.score;
        red();
    printf("CONGRATULATION,PLAYER 1 WINN!!\n");
    reset();
    printf("ENTER WINNER NAME: \n");
fflush(stdin);
            fgets(temp,30,stdin);
            int f=repet(temp,winner,k,p);
             if(f==0)

            {
                memcpy(p[k].name,temp,30);
                p[k].score=winner;
                k++;
            }

            savet(k,p);
            savec(k);
    }

}
else if(player2.score>player1.score){
    winner=player2.score;
     red();
    printf("computer win :(\n");

    reset();}

else if(player1.score==player2.score){
    red();
        printf("TIE :(\n");
    reset();


}
}}}
//check free places,check box borders,if a box is completed give the borders and the center of the box same index to change color
int  checkBox(int x, int y,int c,int p, char a[][c])
{
    int j=0;
    if(x==0)
    {
        if((a[x][y]!=32)&&(a[x+1][y-1]!=32)&&(a[x+2][y]!=32)&&(a[x+1][y+1]!=32))
        {
            a[x+1][y]=p;
            a[x][y]=p;
            a[x+1][y-1]=p;
            a[x+2][y]=p;
            a[x+1][y+1]=p;



            j++;
        }
    }
    else if(y==0)
    {
        if((a[x][y]!=32)&&(a[x-1][y+1]!=32)&&(a[x][y+2]!=32)&&(a[x+1][y+1]!=32))
        {
            a[x][y+1]=p;
            a[x][y]=p;
            a[x-1][y+1]=p;
            a[x][y+2]=p;
            a[x+1][y+1]=p;
            j++;
        }
    }
    else if(x==c-1)
    {
        if((a[x][y]!=32)&&(a[x-1][y-1]!=32)&&(a[x-2][y]!=32)&&(a[x-1][y+1]!=32))
        {
            a[x-1][y]=p;
            a[x][y]=p;
            a[x-1][y-1]=p;
            a[x-2][y]=p;
            a[x-1][y+1]=p;
            j++;
        }
    }
    else if(y==c-1)
    {
        if((a[x][y]!=32)&&(a[x-1][y-1]!=32)&&(a[x+1][y-1]!=32)&&(a[x][y-2]!=32))
        {
            a[x][y-1]=p;
            a[x][y]=p;
            a[x-1][y-1]=p;
            a[x+1][y-1]=p;
            a[x][y-2]=p;
            j++;
        }
    }

    else if((x%2!=0)&&(x!=0)&&(x!=c-1))
    {
        if((a[x][y]!=32)&&(a[x-1][y-1]!=32)&&(a[x][y-2]!=32)&&(a[x+1][y-1]!=32))
        {
            a[x][y-1]=p;
            a[x][y]=p;
            a[x-1][y-1]=p;
            a[x][y-2]=p;
            a[x+1][y-1]=p;
            j++;
        }
        if((a[x][y]!=32)&&(a[x-1][y+1]!=32)&&(a[x][y+2]!=32)&&(a[x+1][y+1]!=32))
        {
            a[x][y+1]=p;
            a[x][y]=p;
            a[x-1][y+1]=p;
            a[x][y+2]=p;
            a[x+1][y+1]=p;
            j++;
        }

    }
    else if((x%2==0)&&(x!=0)&&(x!=c-1))
    {
        if((a[x][y]!=32)&&(a[x-1][y-1]!=32)&&(a[x-2][y]!=32)&&(a[x-1][y+1]!=32))
        {
            a[x-1][y]=p;
            a[x][y]=p;
            a[x-1][y-1]=p;
            a[x-2][y]=p;
            a[x-1][y+1]=p;
            j++;
        }
        if((a[x][y]!=32)&&(a[x+1][y-1]!=32)&&(a[x+2][y]!=32)&&(a[x+1][y+1]!=32))
        {
            a[x+1][y]=p;
            a[x][y]=p;
            a[x+1][y-1]=p;
            a[x+2][y]=p;
            a[x+1][y+1]=p;
            j++;

        }
    }


    return j;

}
//define colors
void colour(){
red();
green();
reset();
system("cls");
}

void green(){
printf("\033[0;32m");
}

void red(){
printf("\033[0;31m");
}
void yellow(){
printf("\033[0;33m");
}

void reset(){
printf("\033[0m");
}

void computer(int *index1, int *index2, int n, char a[][n], int play, int *box, int *i){
    while(1){
    *index1=(rand()%n);
*index2=(rand()%n);
    *box=50;
        if(isspace(a[*index1][*index2])){
     if(*index1%2==0 && *index2%2!=0){
    break;
 }else if(*index1%2!=0 && *index2%2==0){
    break;
 }else{
    continue;
 }
}else{
continue;
}
}
}

void Save(int choice,int n,char array[n][n],struct player player1,struct player player2,int play,int file,int rem){
FILE*SAVE;
if(file==10){
    SAVE=fopen("savegame1.txt","w");}
   else if(file==11){
    SAVE=fopen("savegame2.txt","w");}
   else if(file==12){
    SAVE=fopen("savegame3.txt","w");}
    fprintf(SAVE,"%d\n",choice);
    fprintf(SAVE,"%d\n",n);
    fprintf(SAVE,"%d\n",play);
    fprintf(SAVE,"%d\n",player1.score);
    fprintf(SAVE,"%d\n",player2.score);
    fprintf(SAVE,"%d\n",player1.steps);
    fprintf(SAVE,"%d\n",player2.steps);
    fprintf(SAVE,"%d\n",rem);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fprintf(SAVE,"%d\n",array[i][j]);
        }
    }
    fclose(SAVE);
}

void load(int *choice,int file,int*n,int*rem,int*play,int*steps,int*score,int*steps2,int*score2){
    FILE*SAVE;
    if(file==10){
    SAVE=fopen("savegame1.txt","r");}
   else if(file==11){
    SAVE=fopen("savegame2.txt","r");}
   else if(file==12){
    SAVE=fopen("savegame3.txt","r");}
    fscanf(SAVE,"%d",choice);
    fscanf(SAVE,"%d",n);
    fscanf(SAVE,"%d",play);
    fscanf(SAVE,"%d",score);
    fscanf(SAVE,"%d",score2);
    fscanf(SAVE,"%d",steps);
    fscanf(SAVE,"%d",steps2);
    fscanf(SAVE,"%d",rem);
    fclose(SAVE);

}

void load1(int file,int n,char a[n][n]){
FILE*SAVE;
    if(file==10){
    SAVE=fopen("savegame1.txt","r");}
   else if(file==11){
    SAVE=fopen("savegame2.txt","r");}
   else if(file==12){
    SAVE=fopen("savegame3.txt","r");}
    int load;
    for(int i=0;i<8;i++){
        fscanf(SAVE,"%d",&load);
    }
    char s=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fscanf(SAVE,"%d",&s);
            a[i][j]=s;
        }
    }
}

void Redo(int x,int y,int c,char a[][c],int p){
        a[x][y]=p;
}

void Undo(int x,int y,int c, char a[][c]){
if(a[x][y]!=32){
    a[x][y]=32;
}
}

void copyArray(int c,char a[][c],char a2[][c]){
int i,j;
for(i=0;i<c;i++){
    for(j=0;j<c;j++){
        a2[i][j]=a[i][j];
    }
}
}

int checkScan(int maxN,int *choice)
{
    int x;
    char z[100];
    while(1){
if(maxN==5 ||  maxN==11){
         scanf("%d",&x);
        if(x<maxN ){
            *choice=x;
            return 0;
        }
        else if(x==30){ //undo
            return 1;
        }
        else if(x==40){ //redo
            return 2;
        }
        else if(x==50){ //save
            return 3;
        }
        else{
            fgets(z,100,stdin);
            red();
            printf("invalid\n");
            reset();
            continue;
        }
    }
    }
}
void sorting(int k, topten a[k]){
int i;
int j;
 topten temp;
for(i=0;i<k;i++){
    for(j=i+1;j<k;j++){
        if(a[i].score<a[j].score){
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
}

}
int comparison(char name[30],char name1[30] )
{

    for(int i=0; i<strlen(name); i++)
    {
        if(name1[i]==name[i])
        {
        }
        else
        {
            return 0;
        }

    }
    return 1;
}
int repet(char name[30],int score,int k,topten a[k]){
 int i;
    for(int i=0; i<strlen(name)-1; i++)
    {
        name[i]=tolower(name[i]);
    }

    for(int i=0; i<k; i++)
    {
        if(comparison(a[i].name,name)==1)
        {
            if(score>a[i].score)
            {
                a[i].score=score;
                return 1;
            }
            return 1;
        }
    }
    return 0;
}

void savec(int k){
FILE *c;
    c=fopen("savec.txt","w");
    fprintf(c,"%d\n",k);
    fclose(c);

}
void loadc(int *k){
  FILE *c;
    c=fopen("savec.txt","r");
    fscanf(c,"%d",k);

    fclose(c);
}

void savet(int k,topten p[k]){
FILE *c;
    c=fopen("top10.txt","w");
    for(int i=0;i<k;i++){
        fprintf(c,"%s\n",p[i].name);
        fprintf(c,"%d\n",p[i].score);
    }
    fclose(c);

}
void loadt(int k,topten p[k]){
 FILE *c;
      char name[30];
      int y;
    c=fopen("top10.txt","r");
    for(int i=0;i<k;i++){
        fscanf(c,"%s",name);
        fscanf(c,"%d",&y);
         memcpy(p[i].name,name,30);
         p[i].score=y;
    }
        fclose(c);
}
void printt(int k,topten a[k]){
printf("Name\t\t\t\tScore\n\n");
    reset();
    if(k<10)
    {
        for(int i=0; i<k; i++)
        {
            printf("%s\t\t\t\t%d\n",a[i].name,a[i].score);
        }
    }
    else
    {
        for(int i=0; i<10; i++)
        {
            printf("%s\t\t\t\t%d\n",a[i].name,a[i].score);
        }
    }
}
