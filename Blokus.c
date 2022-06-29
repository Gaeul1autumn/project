#include <stdio.h>
# include <stdlib.h>
# include <time.h>

void Show_board();
void Set_block();
void Select_block(int rand);
void rotate();
int Win_or_Lose();
int k=1;//순서정하기 변수
char board[11][21]={
   {' ',' ',' ','1',' ','2',' ','3',' ','4',' ','5',' ','6',' ','7',' ','8',' ','9',' '}, //(2,3)
   {' ',' ',' ','_',' ','_',' ','_',' ','_',' ','_',' ','_',' ','_',' ','_',' ','_',' '},
   {'1',' ','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|'},
   {'2',' ','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|'},
   {'3',' ','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|'},
   {'4',' ','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|'},
   {'5',' ','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|'},
   {'6',' ','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|'},
   {'7',' ','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|'},
   {'8',' ','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|'},
   {'9',' ','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|','_','|'}
};
char block_frame[4][7]={
      {' ','_',' ','_',' ','_',' '},
      {'|','_','|','_','|','_','|'},
      {'|','_','|','_','|','_','|'},
      {'|','_','|','_','|','_','|'}
};

int main(){
   int r;
   srand((unsigned int)time(NULL));
   while(1){
      Show_board();
      r=rand()%14;
      Select_block(r);
      if(Win_or_Lose()==1)
         break;
      Set_block();
      k++;
   }
   return 0;
}

void Set_block(){
   int r,c,i,j,l,w,wrong=0;// r,c 좌표 변수 / i,j,l,w 배열접근 변수 / wrong 놓을 수 없을 경우
   do{
      wrong=0;
      printf("Put your block (r c) or Rotate (0): ");
      scanf("%d",&r);
      if(r==0){
         do{
            printf("\n");
            rotate();
            printf("Put your block (r c) or Rotate (0): ");
            scanf("%d",&r);
         }while(r==0);
         scanf("%d",&c);
      }
      else
         scanf("%d",&c);
      
      for(i=1;i<4;i++){
         for(j=1;j<=5;j+=2){
            if((i+r<=10 && 2*c+j<=19) && (block_frame[i][j]!='_' && board[i+r][2*c+j]!='_')){
               wrong++;
               if(k%2!=0){
                  printf("P1 is not able to put the block into (%d,%d).\n\n",r,c);
                  printf("P1's block:\n");
                  for(l=0;l<4;l++){
                     for(w=0;w<7;w++)
                        printf("%c",block_frame[l][w]);
                     printf("\n");   
                  }
                  printf("\n");
               }
               else{
                  printf("P2 is not able to put the block into (%d,%d).\n\n",r,c);
                  printf("P2's block:\n");
                  for(l=0;l<4;l++){
                     for(w=0;w<7;w++)
                        printf("%c",block_frame[l][w]);
                     printf("\n");   
                  }
                  printf("\n");
               }
               break;
            }
            else if(block_frame[i][j]!='_'&&(i+r>10||2*c+j>19)){
               wrong++;
               if(k%2!=0){
                  printf("P1 is not able to put the block into (%d,%d).\n\n",r,c);
                  printf("P1's block:\n");
                   for(l=0; l<4; l++){
                     for(w=0; w<7; w++)
                        printf("%c",block_frame[l][w]);
                     printf("\n");
                  }
                  printf("\n");
               }
               else{
                  printf("P2 is not able to put the block into (%d,%d).\n\n",r,c);
                  printf("P2's block:\n");
                  for(l=0;l<4;l++){
                     for(w=0;w<7;w++)
                        printf("%c",block_frame[l][w]);
                     printf("\n");
                  }
                  printf("\n");     
               }
               break;
            }
         }
         if(wrong>0)
            break;
      }
   }while(wrong!=0);

   for(i=1;i<4;i++)
      for(j=1;j<=5;j+=2)
         if(block_frame[i][j]!='_')
            board[i+r][2*c+j]=block_frame[i][j];
   printf("\n");
}
int Win_or_Lose(){
   int i,j,l,w,y=0,n=0,u=1;//i,j,l,w,u 배열접근 변수 / n 블럭놓을 수 없는 카운팅 변수 /y 전체 반복 변수
   char temp[3][3];
   while(y<4){
      for(i=2;i<11;i++)//보드판배열 이동
         for(j=3;j<20;j+=2){
            for(l=1;l<4;l++)//블럭배열 이동
               for(w=1;w<=5;w+=2){
                  if((l+i-1>10||w+j-1>19)&&block_frame[l][w]!='_'){
                     n++;
                     l=10;//for문 2개 동시에 탈출 하기 위해서
                     break;
                  }
                  else if((block_frame[l][w]!='_' && board[i+l-1][j+w-1]!='_') && (l+i-1<=10 && w+j-1<=19)){
                     n++;
                     l=10;
                     break;
                  }
               }
         }
      for(i=0;i<3;i++){//회전
         for(j=0;j<3;j++){
            temp[2-j][i]=block_frame[i+1][u];
            u+=2;
         }
         u=1;
      }
      u=1;
      for(i=0;i<3;i++){
         for(j=0;j<3;j++){
            block_frame[i+1][u]=temp[i][j];
            u+=2;
         }
         u=1;
      }
      u=1;
      y++;
   }
   if(n==81*4){
      if(k%2!=0){
         printf("P1 fails to put the block. P2 wins! \n");
         return 1;
      }
      else{
         printf("P2 fails to put the block. P1 wins! \n");
         return 1;
      }
   }
   else
      return 0;
 
}

void Show_board(){//게임판 출력
   int i,j;
   for(i=0;i<11;i++){
      for(j=0;j<21;j++)
         printf("%c",board[i][j]);  
      printf("\n");
   }
   printf("\n");
}

void Select_block(int rand){
   static int block[14][3][3]={//14개 블록 1=블록 0=공백
   {{1,1,1},{0,0,0},{0,0,0}},
   {{1,1,1},{1,0,0},{0,0,0}},
   {{1,1,1},{0,0,1},{0,0,0}},
   {{1,1,1},{0,1,0},{0,0,0}},
   {{0,1,1},{1,1,0},{0,0,0}},
   {{1,1,0},{0,1,1},{0,0,0}},
   {{1,1,0},{1,1,0},{0,0,0}},
   {{1,0,0},{1,1,0},{1,1,0}},
   {{0,1,1},{1,1,0},{1,0,0}},
   {{1,1,0},{0,1,1},{0,1,0}},
   {{0,1,1},{1,1,0},{0,1,0}},
   {{0,0,1},{1,1,1},{1,0,0}},
   {{1,0,0},{1,1,1},{0,0,1}},
   {{0,1,0},{1,1,1},{0,1,0}}
};
   int l=1,w=0,i,j;
   for(i=0;i<3;i++){
      for(j=0;j<3;j++){
         if(block[rand][i][j]==1){
            if(k%2!=0)
               block_frame[i+1][l]='O';
            else if(k%2==0)
               block_frame[i+1][l]='@';
         }
         else
            block_frame[i+1][l]='_';

         l+=2;
      }
      l=1;
   }

   if(k%2!=0)
      printf("P1's block:\n");
   else
      printf("P2's block:\n");
  
   for(w=0;w<4;w++){
      for(l=0;l<7;l++)
         printf("%c",block_frame[w][l]);
      printf("\n");
   }
   printf("\n");
      
}
void rotate(){
   int i,j,l=1,w;
   char temp[3][3];
   for(i=0;i<3;i++){
      for(j=0;j<3;j++){
         temp[2-j][i]=block_frame[i+1][l];
         l+=2;
      }
      l=1;
   }
   l=1;
   for(i=0;i<3;i++){
      for(j=0;j<3;j++){
         block_frame[i+1][l]=temp[i][j];
         l+=2;
      }
      l=1;
   }
   
   if(k%2!=0)
      printf("P1's block:\n");
   else
      printf("P2's block:\n");
  
   for(w=0;w<4;w++){
      for(l=0;l<7;l++)
         printf("%c",block_frame[w][l]);
      printf("\n");
   }
   printf("\n");
}