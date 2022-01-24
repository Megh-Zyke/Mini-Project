#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CANDIDATE1 "Person_1"
#define CANDIDATE2 "Person_2"
#define CANDIDATE3 "Person_3"
#define CANDIDATE4 "Person_4"

FILE *file1;
FILE *file2;
FILE *file3;
int votesCount1=0, votesCount2=0, votesCount3=0, votesCount4=0, spoiledtvotes=0;
int i;

struct name{
    char fn[150];
    char ln[150];
    int a;
};
struct name st[100000];
int x=0;

void end()
{
    file1 = fopen("Voters_list.txt","a");
    int k;
    fprintf(file1,"******People who have loged into the election page******\n");
    for(k=0;k<x;k++)
    {
        fprintf(file1,"%d.[[%s %s]]\n",k+1,st[k].fn,st[k].ln);
    }
    fclose(file1);
    file3 = fopen("count","a");
    fprintf(file3,"*****count of votes*****\n");
    fprintf(file3,"[[%s:%d]]\n[[%s:%d]]\n[[%s:%d]]\n[[%s:%d]]\n[[Rigged:%d]]\n",CANDIDATE1,votesCount1,CANDIDATE2,votesCount2,CANDIDATE3,votesCount3,CANDIDATE4,votesCount4,spoiledtvotes);
    fclose(file3);
}
void login()
{   
    file1 = fopen("Voters_list.txt","w");
    printf("<<GOOD MORNING>>\n\n");
    printf("Entry number : %d \n\n\n\n",x+1);
    printf("Please enter your first Name : \n");
    scanf("%s",&st[x].fn);
    printf("Please enter your last Name : \n");
    scanf("%s",&st[x].ln); 
    label1:printf("Please enter your 5 digit ID  : \n");
    int* ptr;
    ptr = (int*)malloc(5* sizeof(int));
    scanf("%d",ptr);
    st[x].a=*ptr;
    if(st[x].a<=10000 || st[x].a>=99999){
        printf("\nPlease re-enter your 5 digit ID :\n");
        goto label1;
    }
    label : 
    printf("Press 1 to enter : \n");
    scanf("%d",&i);
    switch(i)
    {
        case(1):
                printf("You have now entered the Election Page\n");
                break;
        default:
                printf("Please Enter 1\n\n");
                goto label;
                break;
    }
    x++;
    
}

void vote()
{   int n;
     printf("\tThe Candidates are listed below.\n\t\t1.%s\n\t\t2.%s\n\t\t3.%s\n\t\t4.%s\n\n",CANDIDATE1,CANDIDATE2,CANDIDATE3,CANDIDATE4);
     label :printf("Please select your Candidate for whom you want to cast your vote : \n");
     scanf("%d",&n);
     switch(n)
     {
         case(1):
            votesCount1++;
            printf("You have casted your vote to <<%s>>\n",CANDIDATE1);
            printf("ThankYou\n Redirecting you to the home page\n\n");
            main();
            break;
         case(2):
            votesCount2++;
            printf("You have casted your vote to <<%s>>\n",CANDIDATE2);
            printf("ThankYou\n Redirecting you to the home page\n\n");
            main();
            break;
         case(3):
            votesCount3++;
            printf("You have casted your vote to <<%s>>\n",CANDIDATE3);
            printf("ThankYou\n Redirecting you to the home page\n\n");
            main();
            break;
         case(4):
            votesCount4++;
            printf("You have casted your vote to <<%s>>\n",CANDIDATE4);
            printf("ThankYou\n Redirecting you to the home page\n\n");
            main();
            break;
         default:
            printf("You have given a wrong input.\nRigged Vote\n");
            spoiledtvotes++;
            main();
            break;
     }
    
}

int voter()
{   
    int n,m;
    printf("<<WELCOME>>\nYou have come to the voters page.\n\n");
    label :
    printf("\t1.View Candidates\n\t2.Cast your Vote\n\t3.View your Details\n\t4.End Session\n");
    printf("Please enter your choice below : \n");
    scanf("%d",&n);
    switch(n)
    {
        case(1):
            printf("\tThe Candidates are listed below.\n\t\t1.%s\n\t\t2.%s\n\t\t3.%s\n\t\t4.%s\n\n",CANDIDATE1,CANDIDATE2,CANDIDATE3,CANDIDATE4);
            goto label;
            break;
        case(2):
            vote();
            break;
        case(3):
            printf("Name : %s %s\n",st[x-1].fn,st[x-1].ln);
            
            printf("\nUser ID : %d",st[x-1].a);
            
            printf("\n\n");
            goto label;
            break;
        case(4):
            printf("\tAre you sure you want to end the session?\n1.Yes\n2.No\n\n");
            label2:
                scanf("%d",&m);
                switch(m)
                {
                    case(1):
                        printf("\t\t\t<<Thank You for Visiting>>\n\n");
                        main();
                        break;
                    case(2):
                        goto label;
                    default:
                        printf("\t\t\tYou have entered a wrong credential.\nSession Corrupted\n\n\n");
                        main();
                }
                break;
        default:
             printf("\tYou have entered a wrong credential.\nSession Corrupted\n\n\n");
             end();
    
             break;
    }
    
    return 0;
}


int elec_counc(){int n;
    printf("<<WELCOME>>\nYou have come to the Counils page\n\n");
    printf("\t1.View total number of voters voted\n\t2.View leading Candidate\n\t3.Declare the Winner\n\t4.Go to home page\n ");
    label: 
    printf("Please choose your option : ");
    scanf("%d",&n);
    switch(n)
    {
        case(1):
            printf("total number of votes : %d\n",x);
            goto label;
            break;
        
        case(2):
            printf("Leading Candidate :");
            if( (votesCount1 >votesCount2  && votesCount1 > votesCount3 && votesCount1 > votesCount4))
            printf("<<%s>>\n",CANDIDATE1);
            else if( (votesCount2 >votesCount1  && votesCount2 > votesCount3 && votesCount2 > votesCount4))
            printf("<<%s>>\n",CANDIDATE2);
            else if( (votesCount3 >votesCount1  && votesCount3 > votesCount2 && votesCount3 > votesCount4))
            printf("<<%s>>\n",CANDIDATE3);
            else if( (votesCount4 >votesCount1  && votesCount4 > votesCount2 && votesCount4 > votesCount3))
            printf("<<%s>>\n",CANDIDATE4);    
            goto label;
            break;
       
        case(3):
            printf("Winner is :");
            if( (votesCount1 >votesCount2  && votesCount1 > votesCount3 && votesCount1 > votesCount4))
            {
                printf("<<%s>>\n",CANDIDATE1);
                file2 = fopen("Votes_list.txt","a");
                fprintf(file2,"Winner : <<%s>>\nVotes:<<%d>>",CANDIDATE1,votesCount1);
                fclose(file2);
                
            }
            else if( (votesCount2 >votesCount1  && votesCount2 > votesCount3 && votesCount2 > votesCount4))
            {   
                printf("<<%s>>\n",CANDIDATE2);
                file2 = fopen("Votes_list.txt","a");
                fprintf(file2,"Winner : <<%s>>\nVotes:<<%d>>",CANDIDATE2,votesCount2);
                fclose(file2);
                
            }
            else if( (votesCount3 >votesCount1  && votesCount3 > votesCount2 && votesCount3 > votesCount4))
            {
                    printf("<<%s>>\n",CANDIDATE3);
                    file2 = fopen("Votes_list.txt","a");
                    fprintf(file2,"Winner : <<%s>>\nVotes:<<%d>>",CANDIDATE3,votesCount3);
                    fclose(file2);
                
            }
            else if( (votesCount4 >votesCount1  && votesCount4 > votesCount2 && votesCount4 > votesCount3))
            {   
                printf("<<%s>>\n",CANDIDATE4);      
                file2 = fopen("Votes_list.txt","a");
                fprintf(file2,"Winner : <<%s>>\nVotes:<<%d>>",CANDIDATE4,votesCount4);
                fclose(file2);
                
            }
                end();
            break;
        
        case(4):
                main();
                break;
        
        default:
            printf("Please enter a valid unput;");
            goto label;
            break;
    }
    return 0;
}


int main()
{   file1 = fopen("Voters_list.txt","w");
    file2 = fopen("Votes_list.txt","w");
    file3 = fopen("count","w");
    fclose(file1);
    fclose(file2);
    fclose(file3);
    login();
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############                Election 2022                      ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    int (*func_ptr[])() = {voter,elec_counc};
    printf("GOOD DAY\n\n1.A Voter\n2.Election Council\n");
    int n,i=0;
    enter:
    printf("\nPlease enter your choice : \n");
    scanf("%d",&n);
    switch(n)
    {
        case(1):
            (*func_ptr[0])();
            break;
        case(2):
            (*func_ptr[1])();
            break;
        default:
            printf("You have entered an invalid entry.\nPlease try again:\n");
            i+=1;
            while(i<3){goto enter;}
            printf("You have entered the wrong input 3 times.\nSession dismissed.\n");
            break;
    }
    return 0;
}
