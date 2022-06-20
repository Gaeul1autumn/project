#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand((unsigned)time(0));
    unsigned int r_int = rand()*rand();
    unsigned int key = r_int % 1001;
    
    int n1=0;

    for(int i=0; i<10 ;i++)//10번의 입력기회
    {
        int answer;
        printf("Put your guess: ");
        scanf("%d",&answer);

        if(answer>key){//입력값이 키보다 큼
            if(answer-key<=10)//close
                printf("Lucky! the key is close to %d\n",answer);
            printf("The key is lower than %d\n",answer);  
        }

        if(answer<key){//입력값이 키보다 작음
            if(key-answer<=10)
                printf("Lucky! the key is close to %d\n",answer);
            printf("The key is higher than %d\n",answer);
        }
    
        if(answer==key){//10번 안에 맞춤
            if(i==0){//one shot+min/max
                printf("Feeling lucky! the key was %d.\n",key);
                n1++;
                if((key==0)||(key==1000)){//one shot 인데 min/max 충족 확인
                    printf("You got the extreme number! the key was %d.\n",key);
                    break;
                }
                break;
            }
            if((key==0)||(key==1000)){//min/max
                printf("You got the extreme number! the key was %d.\n",key);
                n1++;
                break;
            }
            printf("Player won! the key was %d.\n",key);//min/max도 아니고 one shot도 아니고 그냥 답맞춤
            n1++;
            break;
        }
    }

    if(n1==0)
        printf("Computer won! the key was %d.",key);//10번안에 답 못맞춤 

    return 0;
}