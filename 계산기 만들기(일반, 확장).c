#include <stdio.h>

double Add (double n1,double n2);
double Multiplication(double n1,double n2);
double Subtraction(double n1,double n2);
double Divide(double n1,double n2);
double Remainder(int n1,int n2);


int main(void)
{
    int mode;
    printf("Enter the calculator mode (1:Normal, 2:Extended): ");
    scanf("%d",&mode);

    if(mode==1)//일반 연산
    {
        int a,b;
        char oper;
        printf("Put two integers: ");
        scanf("%d,%d",&a,&b);
        printf("Put the operator: ");
        scanf(" %c",&oper);
        
        switch(oper)
        {
        case '+':
            printf("The result is %.3f",Add(a,b));
            break;
        case '-':
            printf("The result is %.3f",Subtraction(a,b));
            break;
        case '*':
            printf("The result is %.3f",Multiplication(a,b));
            break;
        case '%':
            if(b!=0)
                printf("The result is %.3f",Remainder(a,b));
            else
                printf("Zero division error");
            break;
        case '/':
            if(b!=0)
                printf("The result is %.3f",Divide(a,b));
            else
                printf("Zero division error");
        }

    }
    else if(mode==2)//확장 연산
    {
        int a,b,c;
        double result;
        char oper1,oper2;

        printf("Put three integers: ");
        scanf("%d,%d,%d",&a,&b,&c);
        printf("Put two operators: ");
        getchar();
        scanf("%c, %c",&oper1,&oper2);


        switch(oper2)
        {
        case '+':
            result=Add(b,c);
            if(oper1=='+')
                printf("The result is %.3f",Add(a,result));
            else if(oper1=='-')
                printf("The result is %.3f",Subtraction(a,result));
            else if(oper1=='*'){
                result=Multiplication(a,b);
                printf("The result is %.3f",Add(result,c));
            }
            else if(oper1=='/'){
                    if(b!=0){
                        result=Divide(a,b);
                        printf("The result is %.3f",Add(result,c));
                    }
                    else
                        printf("Zero division error");
            }
            else{
                if(b!=0){
                    result=Remainder(a,b);
                    printf("The result is %.3f",Add(result,c));
                }
                else
                    printf("Zero division error");
            }
            break;

        case '-':
            result=Subtraction(b,c);
            if(oper1=='+')
                printf("The result is %.3f",Add(a,result));
            else if(oper1=='-')
                printf("The result is %.3f",Subtraction(a,result));
            else if(oper1=='*'){
                result=Multiplication(a,b);
                printf("The result is %.3f",Subtraction(result,c));
            }
            else if(oper1=='/'){
                    if(b!=0){
                        result=Divide(a,b);
                        printf("The result is %.3f",Subtraction(result,c));
                    }
                    else
                        printf("Zero division error");
            }
            else{
                if(b!=0){
                    result=Remainder(a,b);
                    printf("The result is %.3f",Subtraction(result,c));
                }
                else
                    printf("Zero division error");
            }
            break;
           
        case '*':
            result=Multiplication(b,c);
            if(oper1=='+')
                printf("The result is %.3f",Add(a,result));
            else if(oper1=='-')
                printf("The result is %.3f",Subtraction(a,result));
            else if(oper1=='*')
                printf("The result is %.3f",Multiplication(a,result));
            else if(oper1=='/'){
                    if(b!=0){
                        result=Divide(a,b);
                        printf("The result is %.3f",Multiplication(result,c));
                    }
                    else
                        printf("Zero division error");
            }
            else{
                if(b!=0){
                    result=Remainder(a,b);
                    printf("The result is %.3f",Multiplication(result,c));
                }
                else
                    printf("Zero division error");
            }
            break;

        case '%':
            if(oper1=='+'){//a+b%c
                if(c!=0){
                    result=Remainder(b,c);
                    printf("The result is %.3f",Add(a,result));
                }
                else
                    printf("Zero division error");
            }
            else if(oper1=='-'){
                if(c!=0){
                    result=Remainder(b,c);
                    printf("The result is %.3f",Subtraction(a,result));
                }
                else
                    printf("Zero division error");
            }
            else if(oper1=='*'){
                result=Multiplication(a,b);
                if(c!=0)
                    printf("The result is %.3f",Remainder(result,c));
                else
                    printf("Zero division error");
            }
            else if(oper1=='/'){
                    if((b!=0)&&(c!=0)){
                        result=Divide(a,b);
                        printf("The result is %.3f",Remainder(result,c));
                    }
                    else
                        printf("Zero division error");
            }
            else{
                 if((b!=0)&&(c!=0)){
                    result=Remainder(a,b);
                    printf("The result is %.3f",Remainder(result,c));
                }
                else
                    printf("Zero division error");
            }
            break;

        case '/':
           if(oper1=='+'){//a+b/c
                if(c!=0){
                    result=Divide(b,c);
                    printf("The result is %.3f",Add(a,result));
                }
                else
                    printf("Zero division error");
           }
            else if(oper1=='-'){//a-b/c
                if(c!=0){
                    result=Divide(b,c);
                    printf("The result is %.3f",Subtraction(a,result));
                }
                else
                    printf("Zero division error");
            }
            else if(oper1=='*'){//a*b/c
                result=Multiplication(a,b);
                if(c!=0)
                    printf("The result is %.3f",Divide(result,c));
                else
                    printf("Zero division error");
            }
            else if(oper1=='/'){//a/b/c
                    if((b!=0)&&(c!=0))
                        printf("The result is %.3f",Divide(Divide(a,b),c));
                    else
                        printf("Zero division error");
            }
            else{//a%b/c
                 if((b!=0)&&(c!=0)){
                        result=Remainder(a,b);
                        printf("The result is %.3f",Divide(result,c));
                    }
                    else
                        printf("Zero division error");
            }
        }
        
    }

    return 0;
}
//functions
double Add (double n1,double n2)
{
    return n1+n2;
}

double Subtraction(double n1,double n2)
{
    return n1-n2;
}

double Divide(double n1,double n2)
{
    return n1/n2;
}

double Remainder(int n1,int n2)
{
   return n1%n2;
}

double Multiplication(double n1,double n2)
{
    return n1*n2;
}


