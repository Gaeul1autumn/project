//사목 게임
#include <stdio.h>

void Show_board();
int Enter_column_num();
int Win_or_lose_check();
int Tie_check();
int Full_check(int column_num);
void Draw_mark(int column_num);
int For_initialization();
int column1_row=6,column2_row=6,column3_row=6,column4_row=6,column5_row=6,
            column6_row=6,column7_row=6,column8_row=6;
int i=1; //순서 정하기 변수
char board[7][33]={//2 6 10 14 18 22 26 30
        {' ',' ','1',' ',' ',' ','2',' ',' ',' ','3',' ',' ',' ','4',' ',' ',' ','5',' ',' ',' ','6',' ',' ',' ','7',' ',' ',' ','8',' ',' '},
        {'|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|'},
        {'|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|'},
        {'|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|'},
        {'|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|'},
        {'|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|'},
        {'|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|','_','_','_','|'}  
    };

int main(void){
    while(1){// 초기화 반복
        if(For_initialization()==0)
            break;
    }
    Show_board();// 초기화 끝나고 보드판 보여주기
    if(Tie_check()==1)// 초기화 x마크로 인한 무승부 판정
            return 0;
    while(1){
        Draw_mark(Enter_column_num());
        Show_board();
        if(Win_or_lose_check()==1){
            printf("P1 wins!");
            return 0;
        }
        else if(Win_or_lose_check()==2){
            printf("P2 wins!");
            return 0;
        }
        else if(Tie_check()==1)
            return 0;
        i++;
    }
    return 0;
}

int For_initialization(){
    int column_num;
    printf("For initialization, add block: ");
    scanf("%d",&column_num);
    if(column_num==0){
        printf("Game started.\n\n");
        return 0;
    }
    if(Full_check(column_num)==1){
        do{
            printf("For initialization, add block: ");
            scanf("%d",&column_num);
            if(column_num==0){
                printf("Game started.\n\n");
                return 0;
            }
        }while(Full_check(column_num)==1);
    }

    if(Full_check(column_num)==0){
        switch(column_num){

                case 1: board[column1_row--][2]='X';
                        break;
                case 2: board[column2_row--][6]='X';
                        break;
                case 3: board[column3_row--][10]='X';
                        break;
                case 4: board[column4_row--][14]='X';
                        break;
                case 5: board[column5_row--][18]='X';
                        break;
                case 6: board[column6_row--][22]='X';
                        break;
                case 7: board[column7_row--][26]='X';
                        break;
                case 8: board[column8_row--][30]='X';
                
            }
    }
}
int Win_or_lose_check(){//승패판정
    int j,k,p1win=0,p2win=0;
    for(j=1;j<7;j++){//가로 승패판정 
        for(k=2;k<19;k+=4){
            if((board[j][k]=='O')&&(board[j][k+4]=='O')&&(board[j][k+8]=='O')&&(board[j][k+12]=='O')){
                p1win++;
                break;}
            else if((board[j][k]=='@')&&(board[j][k+4]=='@')&&(board[j][k+8]=='@')&&(board[j][k+12]=='@')){
                p2win++;
                break;}
        }
        if(p1win==1){
            //printf("P1 wins!"); main함수에서 출력하는 걸로 변경 
            return 1;}
        else if(p2win==1){
            //printf("P2 wins!");
            return 2;}
    }
    for(k=2;k<31;k+=4){//세로승패판정
        for(j=1;j<4;j++){
            if((board[j][k]=='O')&&(board[j+1][k]=='O')&&(board[j+2][k]=='O')&&(board[j+3][k]=='O')){
                p1win++;
                break;
            }
            else if((board[j][k]=='@')&&(board[j+1][k]=='@')&&(board[j+2][k]=='@')&&(board[j+3][k]=='@')){
                p2win++;
                break;
            }
        }
        if(p1win==1){
            //printf("P1 wins!");
            return 1;}
        else if(p2win==1){
            //printf("P2 wins!");
            return 2;}
    }
    for(j=1;j<4;j++){//대각선 승패판정\이 방향
        for(k=2;k<19;k+=4){
            if((board[j][k]=='O')&&(board[j+1][k+4]=='O')&&(board[j+2][k+8]=='O')&&(board[j+3][k+12]=='O')){
                p1win++;
                break;}
            else if((board[j][k]=='@')&&(board[j+1][k+4]=='@')&&(board[j+2][k+8]=='@')&&(board[j+3][k+12]=='@')){
                p2win++;
                break;}
        }
        if(p1win==1){
            //printf("P1 wins!"); main함수에서 출력하는 걸로 변경 
            return 1;}
        else if(p2win==1){
            //printf("P2 wins!");
            return 2;}
    }
    for(j=6;j>3;j--){//대각선 승패판정  /방향
        for(k=2;k<19;k+=4){
            if((board[j][k]=='O')&&(board[j-1][k+4]=='O')&&(board[j-2][k+8]=='O')&&(board[j-3][k+12]=='O')){
                p1win++;
                break;}
            else if((board[j][k]=='@')&&(board[j-1][k+4]=='@')&&(board[j-2][k+8]=='@')&&(board[j-3][k+12]=='@')){
                p2win++;
                break;}
        }
        if(p1win==1){
            //printf("P1 wins!"); main함수에서 출력하는 걸로 변경 
            return 1;}
        else if(p2win==1){
            //printf("P2 wins!");
            return 2;}
    }
    if(p1win==0 && p2win==0)
        return 0;

}

int Tie_check(){
    int j,k,p1win,p2win;
    char temp[7][33];
    for(j=0;j<7;j++)//보드 상태 저장
        for(k=0;k<33;k++)
            temp[j][k]=board[j][k];
  
    for(j=1;j<7;j++) 
        for(k=2;k<31;k+=4)
            if(board[j][k]=='_')
                board[j][k]='O';

    p1win=Win_or_lose_check();

    for(j=1;j<7;j++)//보드 복구
        for(k=2;k<31;k+=4)
            board[j][k]=temp[j][k];

    for(j=1;j<7;j++) 
        for(k=2;k<31;k+=4)
            if(board[j][k]=='_')
                board[j][k]='@';

    p2win=Win_or_lose_check();

    for(j=1;j<7;j++)//보드 원상복구
        for(k=2;k<31;k+=4)
            board[j][k]=temp[j][k];

    if(p1win!=1 && p2win!=2){
        printf("Game ended in a draw.");
        return 1;
    }
    else //누구 하나는 이길 수 있을 때
        return 0;
}
    
int Enter_column_num(){  //콜룸넘버 입력하기
    int column_num;
    printf("P1's marker is O, P2's marker is @\n");
    if(i%2!=0)
        printf("P1's turn, Enter the column number: ");
    else if(i%2==0)
        printf("P2's turn, Enter the column number: ");
    scanf("%d",&column_num);
    return column_num;
}

int Full_check(int column_num){
    switch(column_num){
        case 1: if(board[1][2]!='_'){
                    printf("ERROR: The column is full.\n");
                    return 1;}
                else return 0;
                break;
        case 2: if(board[1][6]!='_'){
                    printf("ERROR: The column is full.\n");
                    return 1;}
                else return 0;
                break;
        case 3: if(board[1][10]!='_'){
                    printf("ERROR: The column is full.\n");
                    return 1;}
                else return 0;
                break;
        case 4: if(board[1][14]!='_'){
                    printf("ERROR: The column is full.\n");
                    return 1;}
                else return 0;
                break;
        case 5: if(board[1][18]!='_'){
                    printf("ERROR: The column is full.\n");
                    return 1;}
                else return 0;
                break;
        case 6: if(board[1][22]!='_'){
                    printf("ERROR: The column is full.\n");
                    return 1;}
                else return 0;
                break;
        case 7: if(board[1][26]!='_'){
                    printf("ERROR: The column is full.\n");
                    return 1;}
                else return 0;
                break;
        case 8: if(board[1][30]!='_'){
                    printf("ERROR: The column is full.\n");
                    return 1;}
                else return 0;
    }

}

void Draw_mark(int column_num){//마크 그리기
    
    if(Full_check(column_num)==1){ // 꽉 찼는지 확인 
        do{
            if(i%2!=0)
                printf("P1's turn, Enter the column number: ");
            else if(i%2==0)
                printf("P2's turn, Enter the column number: ");
            scanf("%d",&column_num);
        }while(Full_check(column_num)==1);//꽉 차지 않은 세로줄 번호 고를 때까지 반복
    }

    if(Full_check(column_num)==0){
        if(i%2!=0){
            switch(column_num){

                case 1: board[column1_row--][2]='O';
                        break;
                case 2: board[column2_row--][6]='O';
                        break;
                case 3: board[column3_row--][10]='O';
                        break;
                case 4: board[column4_row--][14]='O';
                        break;
                case 5: board[column5_row--][18]='O';
                        break;
                case 6: board[column6_row--][22]='O';
                        break;
                case 7: board[column7_row--][26]='O';
                        break;
                case 8: board[column8_row--][30]='O';
                
            }

        }

        if(i%2==0){
            switch(column_num){

                case 1: board[column1_row--][2]='@';
                        break;
                case 2: board[column2_row--][6]='@';
                        break;
                case 3: board[column3_row--][10]='@';
                        break;
                case 4: board[column4_row--][14]='@';
                        break;
                case 5: board[column5_row--][18]='@';
                        break;
                case 6: board[column6_row--][22]='@';
                        break;
                case 7: board[column7_row--][26]='@';
                        break;
                case 8: board[column8_row--][30]='@';
                
            }
        }
    }
    printf("\n");
}

void Show_board(){

    int j,k;

    for(k=0;k<7;k++){
        for(j=0; j<33; j++)
            printf("%c",board[k][j]);

        printf("\n");
    }
}