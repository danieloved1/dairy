#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define N 1024
 struct Meeting
{
int date[3];  

float beginhour;

float endhour;

char subject [64];

};
int checkdate(int d,int m,int y)//בדיקת תאריך
{
    if ((m==1)&&(d<=31)||(m==3)&&(d<=31)||(m==5)&&(d<=31)||(m==7)&&(d<=31)||(m==8)&&(d<=31)||(m==10)&&(d<=31)||(m==12)&&(d<=31))
    return 1;
    
    if((m==2)&&(d<=29))
    return 1;
    
    if((m==4)&&(d<=30)||(m==6)&&(d<=30)||(m==9)&&(d<=30)||(m==11)&&(d<=30))
    return 1;
    
    else 
    return 0;
   
}
struct Meeting createmeeting(struct Meeting NM)
{
    
    do
    {
    printf("press day \n");
     scanf("%d",&NM.date[0]);
     printf("press month \n");
     scanf("%d",&NM.date[1]);
     printf("press year \n");
     scanf("%d",&NM.date[2]);
    }
    while(checkdate(NM.date[0],NM.date[1],NM.date[2])==0);
     int fractional_part_in_integer;
     int num;
    do
    {    
      printf("press beginhour in 24 hour clock in 15 min jump between 8.15 to 18.45\n" );
      scanf("%f",&NM.beginhour);
      num=(int)NM.beginhour;
      float fractional = round(NM.beginhour*100)/100 - num;
      fractional_part_in_integer = (int)(fractional*100);
      }
      while(fractional_part_in_integer%15!=0||NM.beginhour<=8||NM.beginhour>19);
     do 
      {
      printf("press endhour in 24 hour clock in 15 min jump between 8.30 to 19.15  \n" );
      scanf("%f",&NM.endhour);
      num=(int)NM.endhour;
      float fractional = round(NM.endhour*100)/100 - num;
      fractional_part_in_integer = (int)(fractional*100);
      }
      while((fractional_part_in_integer%15!=0)||(NM.endhour<NM.beginhour)||(NM.endhour<8.15)||(NM.endhour>19));
      
       printf("write a subject \n");
       scanf("%s",NM.subject);
    
    return NM;
    
}
int checkmeetingexcise(struct Meeting NM,struct Meeting dairy[],int place)
{
    for(int i=0;i<=place;i++)
    {
        if ((NM.date[0]==dairy[i].date[0])&&(NM.date[1]==dairy[i].date[1])&&(NM.date[2]==dairy[i].date[2])&&(NM.beginhour==dairy[i].beginhour))
        {
        return 0;
        }
        
        
        
    }
    return 1;
    
}
int insertmeeting(struct Meeting NM,int place,struct Meeting dairy[])//בודק לאן להכניס במערך
{
    int i,save;
    for(i=0;i<=place;i++)
    {
        if(dairy[i].date[2]>NM.date[2])
        save=i;
        if(dairy[i].date[2]==NM.date[2])
        {
        if(dairy[i].date[1]>NM.date[1])
          save=i;
        }
        if(dairy[i].date[2]==NM.date[2])
        {
        if(dairy[i].date[1]==NM.date[1])
        if(dairy[i].date[0]>NM.date[0])
        save=i;
        }
        if(dairy[i].date[2]==NM.date[2])
        {
        if(dairy[i].date[1]==NM.date[1])
        if(dairy[i].date[0]==NM.date[0])
        if(dairy[i].beginhour>NM.beginhour)
        save=i;
        }
        
    }
    return save;
    
}
int deletemeeting(struct Meeting arr [],int place,int d,int m,int y,float bhour)
{
    for (int i=0;i<place;i++)
    {
        if ((arr[i].date[0]==d)&&(arr[i].date[1]==m)&&(arr[i].date[2]==y)&&(arr[i].beginhour==bhour))
        return i;
    }
}

int main()
{
   char choose;
   int place=0,flag;
   struct Meeting arrmeeting[N];
   do
   {
       printf("to create Meeting press c \n");
       printf("to delete Meeting press d \n");
       printf("to save  press s \n");
       printf("to load press l \n");
       printf("to print a day press p \n");
       printf("to print a week press w \n");
       printf("to find a Meetings press f \n");
       printf("to quit  press q \n");
       scanf("%c",&choose);
     
   switch (choose)
   {
   case 'c':
   {
   struct Meeting NM=createmeeting(NM);
   flag=checkmeetingexcise(NM,arrmeeting,place);
   if(place!=1024)
   {
       if (flag==1)
       {
    if (place==0)
   {
       arrmeeting[place].date[0]=NM.date[0];
          arrmeeting[place].date[1]=NM.date[1];
          arrmeeting[place].date[2]=NM.date[2];
          arrmeeting[place].beginhour=NM.beginhour;
          arrmeeting[place].endhour=NM.endhour;
          strcpy(arrmeeting[place].subject,NM.subject);
          place++;
       
   }
   else
   {
       int j=insertmeeting(NM,place,arrmeeting);
       
          for(int i=place-1;i>=j;i--)
          {
          arrmeeting[i+1].date[0]=arrmeeting[i].date[0];
          arrmeeting[i+1].date[1]=arrmeeting[i].date[1];
          arrmeeting[i+1].date[2]=arrmeeting[i].date[2];
          arrmeeting[i+1].beginhour=arrmeeting[i].beginhour;
          arrmeeting[i+1].endhour=arrmeeting[i].endhour;
          strcpy(arrmeeting[i+1].subject,arrmeeting[i].subject);
          }
          arrmeeting[j].date[0]=NM.date[0];
          arrmeeting[j].date[1]=NM.date[1];
          arrmeeting[j].date[2]=NM.date[2];
          arrmeeting[j].beginhour=NM.beginhour;
           strcpy(arrmeeting[j].subject,NM.subject);
           place++;
   }
   }
    else
    printf("the meeting catch \n");
   }
   else
   printf("the dairy full");
    break;
   }
   case 'd':
   {
       int day1,month1,year1;
       float bhour;
       printf("press day \n");
       scanf("%d",&day1);
       printf("press month \n");
       scanf("%d",&month1);
       printf("press year \n");
       scanf("%d",&year1);
       printf("choose the beginhour of the meet \n ");
       scanf("%f",&bhour);
       int del=deletemeeting(arrmeeting,place,day1,month1,year1,bhour);
       memmove(&arrmeeting[del],&arrmeeting[del+1],(place - del) * sizeof(struct Meeting));
       place=place-1;
       
       break;
   }
   case 's':
   {
    FILE* fps=fopen("Meeting.bin","wb");
    for(int i=0;i<place;i++)
    {
    fwrite(&arrmeeting[i],sizeof(struct Meeting),1,fps);
    }
    fclose (fps);

     break;  
     
   }
   case 'l':
   {
       FILE* fpr=fopen("Meeting.bin","rb");
       for(int i=0;fread(&arrmeeting[i],sizeof(struct Meeting),1,fpr);i++)
       place++;
       fclose(fpr);
       
       break;
       
   }
   case 'p':
   {
        FILE* fpd=fopen("printday.txt","w+");
        int d,m,y;
     struct nm;
       printf("press day");
       scanf("press a day: %d",&d);
       scanf("press a month: %d",&m);
       scanf("press a month: %d",&y);
     for(int i=0;i<=place;i++)
     {
         if(arrmeeting[i].date[0]==d&&arrmeeting[i].date[1]==m&&arrmeeting[i].date[2]==y)
         {
            
         fprintf(fpd,"hour: %f -",arrmeeting[i].beginhour);
         fprintf(fpd," %f ",arrmeeting[i].endhour);
         fprintf(fpd," subject:%s \n",arrmeeting[i].subject);
         }
     }
     fclose(fpd);
     break;
   }
   case 'w':
   {
       int d,m,y;
       printf("press date \n");
       printf("press a day:");
       scanf("%d",&d);
       printf("press a month:");
       scanf("%d",&m);
        printf("press a year:");
       scanf("%d",&y);
       FILE *fpw=fopen("printweek.txt","w+");
       for(int i=0;i<7;i++)
       {
       fprintf(fpw,"|| %d",d);
       fprintf(fpw,"/%d",m);
       fprintf(fpw,"/%d ||",y);
       for(int j=0;j<=place;j++)
       {
          if(arrmeeting[j].date[0]==d&&arrmeeting[j].date[1]==m&&arrmeeting[j].date[2]==y) 
          {
          fprintf(fpw,"%f-",arrmeeting[j].beginhour);
          fprintf(fpw," %f ",arrmeeting[j].endhour); 
          fprintf(fpw,"subject:%s ||",arrmeeting[j].subject);
          }
         
       }
       fprintf(fpw,"\n");
       d++;
       int months [] ={31,29,31,30,31,30,31,31,30,31,30,31};
            if (m==12)
             {
             if(d>months[m-1])
             {
                 d=1;
                 m=1;
                 y++;
             }
             }
             if(d>months[m-1])
             {
                 d=1;
                 m++;
             }
       
       }
       
       
       
       break;
       
   }
   case 'q':
   {
     FILE* fps=fopen("Meeting.bin","wb");
     for(int i=0;i<place;i++)
    fwrite(&arrmeeting[i],sizeof(struct Meeting),1,fps);
    fclose (fps);
    printf("bye bye");
    break;
   }
   case 'f':
   {
       int d,m,y,bh,eh;
       printf("press a day ");
       scanf("%d",&d);
       printf("press a month ");
       scanf("%d",&m);
       printf("press a year ");
       scanf("%d",&y);
       printf("press a begin hour ");
       scanf("%d",&bh);
       printf("press a end hour ");
       scanf("%d",&eh);
       for (int i=0;i<=place;i++)
       {
           if(arrmeeting[i].date[0]==d&&arrmeeting[i].date[1]==m&&arrmeeting[i].date[2]==y&&arrmeeting[i].beginhour>=bh&&arrmeeting[i].endhour<=eh)
           {
            printf("date: %d/%d/%d \n",arrmeeting[i].date[0],arrmeeting[i].date[1],arrmeeting[i].date[2]);
            printf("hour %f -  ",arrmeeting[i].beginhour);
             printf("%f \n",arrmeeting[i].endhour); 
            printf("subject:");
            puts(arrmeeting[i].subject);
           }
           
       }
       break;
       
       
   }
   
   }
   }while (choose!='q');
   for(int i=0;i<=place;i++)
  printf("%d%d%d%f \n",arrmeeting[i].date[0],arrmeeting[i].date[1],arrmeeting[i].date[2],arrmeeting[i].beginhour);
    
}
       
    



























