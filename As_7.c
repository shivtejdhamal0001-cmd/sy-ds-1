#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max 20
char stack[max];
int top=-1;
char ch;
int isp(char ch);
int icp(char ch);
void push(char ch);
char pop(void);
void inf_post(char inf[], char postf[]);
char pre_stack[max][max];
int pre_top = -1;
void post_pre(char postf[], char pre[]);
char inf_stack[max][max];
int inf_top=-1;
void post_inf(char postf[],char inf[]);
int main()
{
    char inf[max];
    char postf[max];
    char pre[max];
    // int inf_post()
    // char pre_exp[max];
    int choice;
do
{
    //    printf("1. Prefix to Infix\n");
        printf("2. Postfix to Prefix\n");
        // printf("3. Prefix to Postfix\n");
        printf("4. Infix to Postfix\n");
        // printf("5. Infix to Prefix\n");
        printf("6. Post to Infix\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
switch(choice)
    {   
        //  case 1:
        //     {
        //        scanf("%[^\n]",postf);
        //       post_inf();
        //    }
        case 2:
        {  printf("Enter Postfix EXP: ");
          scanf(" %[^\n]",postf); 
           printf("\n");
           post_pre(postf, pre);
            printf("Prefix Expression: %s\n", pre);
            break;
        }
        // case 3:
        // {scanf("%[^\n]",pref); 
        //     pre_post();
        // }
        case 4:
        { printf("Enter Infic EXP\n");
            scanf(" %[^\n]",inf); 
            printf("\n");
            inf_post(inf,postf);
             printf("Postfix Expression: %s\n", postf);
            break;
        }
        
        // case 5:
        // { scanf("%[^\n]",inf); //reversed 
        //     inf_pre();
        // }
        case 6:
        {printf("Enter Postfix EXP\n");
            scanf(" %[^\n]",postf); 
            printf("\n");

            post_inf(postf,inf);
            printf("Infix Expression: %s\n",inf);
           break;

        }
        default:
        {
            printf("Invalid choice\n");
            break;
        }
    }

}while(choice<=6);
}




int isp(char ch)
  {
    if(ch=='+'||ch=='-')
       {
        return 1;
       }
    if(ch=='*'||ch=='/')
    {
        return 2;

    }
    if(ch=='^')
    {
        return 3;
    }
    if(ch=='('||ch==')')
    {return 5;}
    else
    {
        return 0;
    }
  }


  int icp(char ch)
  {
    if(ch=='+'||ch=='-')
       {
        return 1;
       }
    if(ch=='*'||ch=='/')
    {
        return 2;

    }
    if(ch=='^')
    {
        return 4;
    }
    if(ch=='('||ch==')')
    {return 5;}
    else
    {
        return 0;
    }
  }

  void push(char ch) 
  {
      if (top < max - 1) 
    {
         stack[++top] = ch;
    }
  }



char pop() 
{
     if (top >= 0)
     {
        return stack[top--];
    }
    return '\0';
}


 void inf_post(char inf[],char postf[])
 {
    int i=0,k=0 ;
    top = -1;
    while(inf[i] != '\0')

    {

        if(isalnum(inf[i]))
        {
            postf[k]=inf[i];
            k=k+1;
           

        }
        else
        {
            if(inf[i]=='(')
            {
                push('(');
                i++;

            }
            else
            {
                if(inf[i]==')')
                {
                    while(top != -1 && stack[top] != '(')
              {
                  ch = pop();
                  postf[k] = ch;
                  k = k + 1;
              } 

              if(top != -1 && stack[top] == '(')
              {
                  pop();
              }

                }
                else
                {
                   while(top != -1 && isp(stack[top]) >= icp(inf[i]))
                    {
                        ch=pop();
                        postf[k]=ch;
                        k=k+1;

                    }
                    push(inf[i]);
                }
            }
        }i=i+1;

    }

     
while(top!=-1)

{
    ch=pop();
    postf[k]=ch;
    k=k+1;
}
postf[k] = '\0';

 }






 // post to infix 
 void post_pre(char postf[], char pre[])
{
    int l = strlen(postf);
    pre_top = -1;
    for(int i = 0; i < l; i++)
    {
        char x = postf[i];
        char x_str[2] = {x, '\0'};
        if(x != '+' && x != '-' && x != '*' && x != '/' && x != '^')
        {
            pre_top++;
            strcpy(pre_stack[pre_top], x_str);
        }

        else
        {
            char op1[max], op2[max], E1[max] = "";
             strcpy(op2, pre_stack[pre_top]);
             pre_top--;


            strcpy(op1, pre_stack[pre_top]);
             pre_top--;
             strcat(E1, x_str);
               strcat(E1, op1);
            strcat(E1, op2);
            pre_top++;
              strcpy(pre_stack[pre_top], E1);
        }
    }
    strcpy(pre, pre_stack[pre_top]);
}




// Post to infix


void post_inf(char postf[],char inf[])
{
    int i,l;
    char x;
    char x_str[2];
    char op1[max],op2[max],E1[max];

    l=strlen(postf);
    inf_top=-1;

    for(i=0;i<l;i++)
    { x=postf[i];
        x_str[0]=x;
        x_str[1]='\0';
        if(x!='+'&&x!='-'&&x!='*'&&x!='/'&&x!='^')
        {
            inf_top++;
             strcpy(inf_stack[inf_top],x_str);
        }

        else
        {
            strcpy(op2,inf_stack[inf_top]);
             inf_top--;
             strcpy(op1,inf_stack[inf_top]);
             inf_top--;
             E1[0]='\0';
            strcat(E1,"(");
            strcat(E1,op1);
             strcat(E1,x_str);
            strcat(E1,op2);
            strcat(E1,")");

             inf_top++;
              strcpy(inf_stack[inf_top],E1);
        }
    }
    strcpy(inf,inf_stack[inf_top]);
}
