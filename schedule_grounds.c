#include<stdio.h>
#include<string.h>
#include<windows.h>
#define MAX_NO_OF_GAMES 5
#define MAX_NO_OF_RESERVED_DATES 3
#define MAX_NO_OF_AVAILABLE_DATES 3
#define MAX_NO_OF_GROUNDS 3
struct date_schedule{
      char availabledates[11];
      int time;
      int minutes;

};
struct date_reserved{
    char reserved_dates[11];

};
 typedef struct gameschedule{
    char gamename[50];
    float hourlyrate;
    struct date_schedule dates[MAX_NO_OF_AVAILABLE_DATES];
    struct date_reserved fixed_dates[MAX_NO_OF_RESERVED_DATES];
}gameschedule;
  typedef struct groundinfo{
    char groundname[50];
    char cityname[50];
    char statename[50];
    struct gameschedule games[MAX_NO_OF_GAMES];
 }groundinfo;
 void getfixturesincity(groundinfo ground[MAX_NO_OF_GROUNDS],char cityname[],char begindate[],char enddate[])
 { int count = 0;
    for(int i=0;i<MAX_NO_OF_GROUNDS;i++)
    { if(strcmp(ground[i].cityname,cityname)==0)
       {  for(int j=0;j< MAX_NO_OF_GAMES;j++)
         { for(int k=0;k<MAX_NO_OF_RESERVED_DATES;k++)
            {
               if(strcmp(ground[i].games[j].fixed_dates[k].reserved_dates,begindate)>=0&&strcmp(enddate,ground[i].games[j].fixed_dates[k].reserved_dates)>=0 && ground[i].games[j].fixed_dates[k].reserved_dates[0]!='0')
               { 
                 puts(ground[i].games[j].gamename);
                 printf("\t----");
                 puts(ground[i].games[j].fixed_dates[k].reserved_dates) ; 
                 count++;              
               }
            }
         }
       }
    }
    if(count == 0)
        printf("No Such Ground Available\n");
 }
 void isavailable( groundinfo temp_ground[MAX_NO_OF_GROUNDS],char gamename[],char date[],int hours,int minutes)
 {  int count=0;
    for(int i=0;i<MAX_NO_OF_GROUNDS;i++)
   { for(int j=0;j< MAX_NO_OF_GAMES;j++)
      { if(strcmp(temp_ground[i].games[j].gamename,gamename)==0)
         { for(int k=0;k<MAX_NO_OF_AVAILABLE_DATES;k++)
            {
               if(strcmp(temp_ground[i].games[j].dates[k].availabledates,date)==0)
               {
                  if(hours==temp_ground[i].games[j].dates[k].time)
                  {
                    if(minutes >= temp_ground[i].games[j].dates[k].minutes)
                    {
                        puts(temp_ground[i].groundname);
                        count++;
                    }
                  }
                  else if(hours >= temp_ground[i].games[j].dates[k].time)
                  {
                    puts(temp_ground[i].groundname);
                    count++;
                  }
               }
            }

         }

      }

   }
   if(count==0);
   {
    printf("There is no such ground available\n");
   }

 }
 void uniquesports(groundinfo ground[],char ground_name[],char city_name[])
 {  char gamelist[MAX_NO_OF_GAMES][50];
     for(int i=0;i<MAX_NO_OF_GROUNDS;i++)
     { if(strcmp(ground[i].groundname,ground_name)==0)
      { for(int j=0;j<MAX_NO_OF_GAMES;j++)
        {  strcpy(gamelist[j],ground[i].games[j].gamename);
        }
      }
     }
    //  for(int k=0;k<MAX_NO_OF_GAMES;k++)
    // {
    //   puts(gamelist[k]);
    // }
    
    for(int i=0;i<MAX_NO_OF_GROUNDS;i++)
     { if(strcmp(ground[i].cityname,city_name)==0&&strcmp(ground[i].groundname,ground_name)!=0)
       {
           for(int j=0;j<MAX_NO_OF_GAMES;j++)
           {
               for(int k=0;k<MAX_NO_OF_GAMES;k++)
               {
                   if(strcmp(ground[i].games[k].gamename,gamelist[j])==0)
                  { 
                       gamelist[j][0]='\0';
                       
                   }
               }
           }
       }
     }  
      for(int k=0;k<MAX_NO_OF_GAMES;k++)
    {
      if(gamelist[k][0]!='\0')
      {
          puts(gamelist[k]);
      }
    }
 }
 void clashofmatches(groundinfo ground[],char list_ground_name[MAX_NO_OF_GROUNDS][50],int noofgrounds,char dateofgame[],char game_name[])
 {  for(int i=0;i<noofgrounds;i++)
    {  
      for(int j=0;j<MAX_NO_OF_GROUNDS;j++)
       { if(strcmp(list_ground_name[i],ground[j].groundname)==0)
         {
             for(int k=0;k<MAX_NO_OF_GAMES;k++)
             {
                 if(strcmp(game_name,ground[j].games[k].gamename)==0)
                 {
                     for(int h=0;h<MAX_NO_OF_RESERVED_DATES;h++)
                     {
                         if(strcmp(dateofgame,ground[j].games[k].fixed_dates[h].reserved_dates)==0)
                         {
                             printf("There is a %s match, scheduled on %s in %s\n",game_name,dateofgame,ground[j].groundname);
                         }
                     }
                 }
             }
         }
        
       }
    } 
 }
 void givelistofgroundshavingatleastkmatches(groundinfo ground[],char gamelist[][50],char gamedate[],char nameofcity[],int k,int noofgames)
 { for(int i=0;i<MAX_NO_OF_GROUNDS;i++)
    {  int count=0;
      if(strcmp(ground[i].cityname,nameofcity)==0)
      {  
         for(int j=0;j<noofgames;j++)
         {
            for(int k=0;k<MAX_NO_OF_GAMES;k++)
            {
               if(strcmp(ground[i].games[k].gamename,gamelist[j])==0)
               {
                  for(int h=0;h<MAX_NO_OF_RESERVED_DATES;h++)
                  {
                     if(strcmp(ground[i].games[k].fixed_dates[h].reserved_dates,gamedate)==0)
                     {
                        count++;
                        // puts(ground[i].games[k].gamename);
                     }
                  }
               }
            }
         } 
         
        //  puts(ground[i].groundname);
        //  printf("%d\n",count);
         
         if(count>=k)
            // {  printf("%d",count);
            {
               puts(ground[i].groundname);
            }
      }
    }
 }
//   "swimming",
//   "atheltics",
//   "baseball",
//   "khokho",
//   "basketball",

  void outputdates(groundinfo ground[],char game_name[],char date[])
  
 {
    int count=0;
    for(int i=0;i<MAX_NO_OF_GROUNDS;i++)
    {
        int flag=0;
        for(int j=0;j<MAX_NO_OF_GAMES && flag==0;j++)
        {
            if(strcmp(ground[i].games[j].gamename,game_name)>0)
            {
                flag=1;
            }
            else if(strcmp(ground[i].games[j].gamename,game_name)==0)
            {
               int flag_1=0;
               for(int k=0;k<MAX_NO_OF_AVAILABLE_DATES && flag_1==0;k++)
               {
                 if(strcmp(ground[i].games[j].dates[k].availabledates,date)>0)
                 {
                    flag_1=1;
                 }
                 else if(strcmp(ground[i].games[j].dates[k].availabledates,date)==0)
                 {
                    printf("%s in the city %s\n",ground[i].groundname,ground[i].cityname);
                    count+=1;
                 }
               }
            }
         
        }
    }
    if(count==0)
    {
        printf("there is no such ground available on given date");
    }
 }

 void outputtime(groundinfo ground[],char game_name[],int hours,int minutes)
 {
    int count=0;
    for(int i=0;i<MAX_NO_OF_GROUNDS;i++)
    {
        int flag=0;
        for(int j=0;j<MAX_NO_OF_GAMES && flag==0;j++)
        {
          if(ground[i].games[j].gamename[0]!='\0')
          {
            if(strcmp(ground[i].games[j].gamename,game_name)>0)
            {
                flag=1;
            }
            else if(strcmp(ground[i].games[j].gamename,game_name)==0)
            {
               for(int k=0;k<MAX_NO_OF_AVAILABLE_DATES && ground[i].games[j].dates[k].availabledates[0]!='\0';k++)
               {
                 if(ground[i].games[j].dates[k].time==hours)
                 {
                    if(ground[i].games[j].dates[k].minutes<=minutes)
                    {
                        printf("%s on %s in %s city\n",ground[i].groundname,ground[i].games[j].dates[k].availabledates,ground[i].cityname);
                        count+=1;
                    }
                 }
                 else if(ground[i].games[j].dates[k].time<hours)
                 {
                     printf("%s on %s in %s city\n",ground[i].groundname,ground[i].games[j].dates[k].availabledates,ground[i].cityname);
                     count+=1;
                 }
               }
           }
          }
        }
    }
    if(count==0)
    {
        printf("there is no such ground available on given time\n");
    }
 }
  void SortOnPriceForAGame(groundinfo ground[],char game_name[],char date[],int hours,int minutes)
 {  
    typedef struct store
    {
        int rates;
        char groundname[100];
    } store;
    store temp[MAX_NO_OF_GROUNDS];
    for(int i=0;i<MAX_NO_OF_GROUNDS;i++)
    {
        temp[i].groundname[0]='\0';
        temp[i].rates=0;
    }
    int idx=0;
    for(int i=0;i<MAX_NO_OF_GROUNDS ;i++)
    {
        int flag=0;
        for(int j=0;j<MAX_NO_OF_GAMES && flag==0 && ground[i].games[j].gamename[0]!='\0';j++)
        {
            if(strcmp(ground[i].games[j].gamename,game_name)>0)
            {
                flag=1;
            }
            else if(strcmp(ground[i].games[j].gamename,game_name)==0)
            {
               int flag_1=0;
               for(int k=0;k<MAX_NO_OF_AVAILABLE_DATES && flag_1==0 && ground[i].games[j].dates[k].availabledates[0]!='\0';k++)
               {
                 if(strcmp(ground[i].games[j].dates[k].availabledates,date)>0)
                 {
                    flag_1=1;
                 }
                 else if(strcmp(ground[i].games[j].dates[k].availabledates,date)==0)
                   {
                       if(ground[i].games[j].dates[k].time==hours)
                       {
                          if(ground[i].games[j].dates[k].minutes>minutes)
                           {
                              flag_1=1;
                           }
                           else if(ground[i].games[j].dates[k].minutes<=minutes)
                           {
                            strcpy(temp[idx].groundname,ground[i].groundname);
                            temp[idx].rates=ground[i].games[j].hourlyrate;
                            int flag_2=0;
                            for(int l=idx;l>0 && flag_2==0;l--)
                            {
                                if(temp[l].rates>temp[l-1].rates)
                                {
                                    flag_2=1;
                                }
                                else if(temp[l].rates<temp[l-1].rates)
                                {
                                    store dup=temp[l];
                                    temp[l]=temp[l-1];
                                    temp[l-1]=dup;
                                }
                            }
                            idx=idx+1;
                           }
                       }
                       else if(ground[i].games[j].dates[k].time<hours)
                       {
                           strcpy(temp[idx].groundname,ground[i].groundname);
                            temp[idx].rates=ground[i].games[j].hourlyrate;
                            int flag_2=0;
                            for(int l=idx;l>0 && flag_2==0;l--)
                            {
                                if(temp[l].rates>temp[l-1].rates)
                                {
                                    flag_2=1;
                                }
                                else if(temp[l].rates<temp[l-1].rates)
                                {
                                    store dup=temp[l];
                                    temp[l]=temp[l-1];
                                    temp[l-1]=dup;
                                }
                            }
                            idx=idx+1;
                       }
                   }
               }
        
               
           }
        }
    }
    if(idx==0)
    {
        printf("there is no such ground available\n");
    }
    else
    {
        for(int i=0;i<idx;i++)
        {
            printf("%s with hourly rate %d\n",temp[i].groundname,temp[i].rates);
        }
    }
 }
void getFixuresSortedonDate(groundinfo temp_ground[MAX_NO_OF_GROUNDS])
 {
    typedef struct store
    {
        char dates[11];
        char groundname[100];
    } store;
    store temp[MAX_NO_OF_GROUNDS];
    for(int i=0;i<MAX_NO_OF_GROUNDS;i++)
    {
        temp[i].groundname[0]='\0';
        temp[i].dates[0]='\0';
    }
    for(int i=0;i<MAX_NO_OF_GROUNDS && temp_ground[i].groundname[0]!='\0';i++)
    {
        strcpy(temp[i].groundname,temp_ground[i].groundname);
        char d[11];
        strcpy(d,temp_ground[i].games[0].dates[0].availabledates);
        for(int j=1;j<MAX_NO_OF_GAMES && temp_ground[i].games[j].gamename[0]!='\0';j++)
        {
            if(strcmp(d,temp_ground[i].games[j].dates[0].availabledates)>0)
            {
                strcpy(d,temp_ground[i].games[j].dates[0].availabledates);
            }
        }
        strcpy(temp[i].dates,d);
    }
    int a=MAX_NO_OF_GROUNDS-1,flag=0;
    while(a>=0 && flag==0)
    {
        if(temp[a].groundname[0]!='\0')
        {
            flag=1;
        }
        a--;
    }
    a=a+1;
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<a-1-i;a++)
        {
            if(strcmp(temp[j].dates,temp[j+1].dates)>0)
            {
                store temp_1=temp[j];
                temp[j]=temp[j+1];
                temp[j+1]=temp_1;
            }
        }
    }
    for(int i=0;i<MAX_NO_OF_GROUNDS;i++)
    {
       printf("%s\n",temp[i].groundname);
    }
 }
  
 int main()
 {  gameschedule games[MAX_NO_OF_GAMES];
    groundinfo ground[MAX_NO_OF_GROUNDS];
    strcpy(ground[0].groundname,"dharmasala sports academy");
    strcpy(ground[0].cityname,"dharmasala");
    strcpy(ground[0].statename,"himachal pradesh");
    strcpy(ground[0].games[0].gamename,"cricket");
    ground[0].games[0].hourlyrate=1000;
    strcpy(ground[0].games[0].dates[0].availabledates,"2023-11-03");
    ground[0].games[0].dates[0].time=16;
    ground[0].games[0].dates[0].minutes=0;
    strcpy(ground[0].games[0].dates[1].availabledates,"2023-11-06");
    ground[0].games[0].dates[1].time=17;
    ground[0].games[0].dates[1].minutes=0;
    strcpy(ground[0].games[0].dates[2].availabledates,"2023-11-09");
    ground[0].games[0].dates[2].time=17;
    ground[0].games[0].dates[2].minutes=30;
       strcpy(ground[0].games[0].fixed_dates[0].reserved_dates,"2023-11-01");
        strcpy(ground[0].games[0].fixed_dates[1].reserved_dates,"2023-11-02");
        ground[0].games[0].fixed_dates[2].reserved_dates[0]='\0';

        strcpy(ground[0].games[1].gamename,"kabaddi");
    ground[0].games[1].hourlyrate=1500;
    strcpy(ground[0].games[1].dates[0].availabledates,"2023-11-01");
    ground[0].games[1].dates[0].time=18;
    ground[0].games[1].dates[0].minutes=0;
    strcpy(ground[0].games[1].dates[1].availabledates,"2023-11-06");
    ground[0].games[1].dates[1].time=19;
    ground[0].games[1].dates[1].minutes=0;
    strcpy(ground[0].games[1].dates[2].availabledates,"2023-11-08");
    ground[0].games[1].dates[2].time=18;
    ground[0].games[1].dates[2].minutes=30;
       strcpy(ground[0].games[1].fixed_dates[0].reserved_dates,"2023-10-30");
        strcpy(ground[0].games[1].fixed_dates[1].reserved_dates,"2023-11-05");
        strcpy(ground[0].games[1].fixed_dates[2].reserved_dates,"2023-11-07");

        
        strcpy(ground[0].games[2].gamename,"baseball");
    ground[0].games[2].hourlyrate=750;
    strcpy(ground[0].games[2].dates[0].availabledates,"2023-11-02");
    ground[0].games[2].dates[0].time=17;
    ground[0].games[2].dates[0].minutes=30;
    strcpy(ground[0].games[2].dates[1].availabledates,"2023-11-05");
    ground[0].games[2].dates[1].time=18;
    ground[0].games[2].dates[1].minutes=0;
    strcpy(ground[0].games[2].dates[2].availabledates,"2023-11-10");
    ground[0].games[2].dates[2].time=17;
    ground[0].games[2].dates[2].minutes=0;
       strcpy(ground[0].games[2].fixed_dates[0].reserved_dates,"2023-11-01");
        strcpy(ground[0].games[2].fixed_dates[1].reserved_dates,"2023-11-03");
        strcpy(ground[0].games[2].fixed_dates[2].reserved_dates,"2023-11-06");

         strcpy(ground[0].games[3].gamename,"rugby");
    ground[0].games[3].hourlyrate=250;
    strcpy(ground[0].games[3].dates[0].availabledates,"2023-11-01");
    ground[0].games[3].dates[0].time=17;
    ground[0].games[3].dates[0].minutes=0;
    strcpy(ground[0].games[3].dates[1].availabledates,"2023-11-03");
    ground[0].games[3].dates[1].time=19;
    ground[0].games[3].dates[1].minutes=0;
    strcpy(ground[0].games[3].dates[2].availabledates,"2023-11-05");
    ground[0].games[3].dates[2].time=18;
    ground[0].games[3].dates[2].minutes=0;
       strcpy(ground[0].games[3].fixed_dates[0].reserved_dates,"2023-11-02");
        ground[0].games[3].fixed_dates[1].reserved_dates[0]='\0';
        ground[0].games[3].fixed_dates[2].reserved_dates[0]='\0';

     strcpy(ground[0].games[4].gamename,"football");
    ground[0].games[4].hourlyrate=500;
    strcpy(ground[0].games[4].dates[0].availabledates,"2023-10-24");
    ground[0].games[4].dates[0].time=18;
    ground[0].games[4].dates[0].minutes=0;
    strcpy(ground[0].games[4].dates[1].availabledates,"2023-10-29");
    ground[0].games[4].dates[1].time=17;
    ground[0].games[4].dates[1].minutes=30;
    strcpy(ground[0].games[4].dates[2].availabledates,"2023-11-03");
    ground[0].games[4].dates[2].time=18;
    ground[0].games[4].dates[2].minutes=0;
       strcpy(ground[0].games[4].fixed_dates[0].reserved_dates,"2023-10-30");
       strcpy(ground[0].games[4].fixed_dates[1].reserved_dates,"2023-11-01");
       ground[0].games[4].fixed_dates[2].reserved_dates[0]='\0';
       
    strcpy(ground[1].groundname,"chepuk sports academy");
    strcpy(ground[1].cityname,"chennai");
    strcpy(ground[1].statename,"tamil nadu");
    strcpy(ground[1].games[0].gamename,"handball");
    ground[1].games[0].hourlyrate=1000;
    strcpy(ground[1].games[0].dates[0].availabledates,"2023-10-26");
    ground[1].games[0].dates[0].time=16;
    ground[1].games[0].dates[0].minutes=0;
    strcpy(ground[1].games[0].dates[1].availabledates,"2023-11-01");
    ground[1].games[0].dates[1].time=17;
    ground[1].games[0].dates[1].minutes=0;
    ground[1].games[0].dates[2].availabledates[0]='\0';
    ground[1].games[0].dates[2].time=0;
    ground[1].games[0].dates[2].minutes=0;
       strcpy(ground[1].games[0].fixed_dates[0].reserved_dates,"2023-11-03");
        ground[1].games[0].fixed_dates[1].reserved_dates[0]='\0';
         ground[1].games[0].fixed_dates[2].reserved_dates[0]='\0';

    strcpy(ground[1].games[1].gamename,"swimming");
    ground[1].games[1].hourlyrate=2000;
    strcpy(ground[1].games[1].dates[0].availabledates,"2023-10-30");
    ground[1].games[1].dates[0].time=17;
    ground[1].games[1].dates[0].minutes=0;
    strcpy(ground[1].games[1].dates[1].availabledates,"2023-11-01");
    ground[1].games[1].dates[1].time=17;
    ground[1].games[1].dates[1].minutes=30;
    ground[1].games[1].dates[2].availabledates[0]='\0';
    ground[1].games[1].dates[2].time=0;
    ground[1].games[1].dates[2].minutes=0;
       strcpy(ground[1].games[1].fixed_dates[0].reserved_dates,"2023-11-05");
       strcpy(ground[1].games[1].fixed_dates[1].reserved_dates,"2023-11-06");
        ground[1].games[1].fixed_dates[2].reserved_dates[0]='\0';  

    strcpy(ground[1].games[2].gamename,"khokho");
     ground[1].games[2].hourlyrate=2500;
     strcpy(ground[1].games[2].dates[0].availabledates,"2023-10-27");
     ground[1].games[2].dates[0].time=17;
     ground[1].games[2].dates[0].minutes=30;
     strcpy(ground[1].games[2].dates[1].availabledates,"2023-10-28");
     ground[1].games[2].dates[1].time=18;
     ground[1].games[2].dates[1].minutes=0;
     ground[1].games[2].dates[2].availabledates[0]='\0';
    ground[1].games[2].dates[2].time=0;
    ground[1].games[2].dates[2].minutes=0;
     strcpy(ground[1].games[2].fixed_dates[0].reserved_dates,"2023-10-25");
     ground[1].games[2].fixed_dates[1].reserved_dates[0]='\0';    
      ground[1].games[2].fixed_dates[2].reserved_dates[0]='\0';


    strcpy(ground[1].games[3].gamename,"cricket");
     ground[1].games[3].hourlyrate=500;
     strcpy(ground[1].games[3].dates[0].availabledates,"2023-10-28");
     ground[1].games[3].dates[0].time=17;
     ground[1].games[3].dates[0].minutes=0;
     strcpy(ground[1].games[3].dates[1].availabledates,"2023-11-03");
     ground[1].games[3].dates[1].time=16;
     ground[1].games[3].dates[1].minutes=0;
     ground[1].games[3].dates[2].availabledates[0]='\0';
    ground[1].games[3].dates[2].time=0;
    ground[1].games[3].dates[2].minutes=0;
     strcpy(ground[1].games[3].fixed_dates[0].reserved_dates,"2023-10-30");
     strcpy(ground[1].games[3].fixed_dates[0].reserved_dates,"2023-11-01");
        ground[1].games[3].fixed_dates[2].reserved_dates[0]='\0';

     ground[1].games[4].gamename[0]='\0';
     ground[1].games[4].hourlyrate=0;
     ground[1].games[4].dates[0].availabledates[0]='\0';
     ground[1].games[4].dates[0].time=0;
     ground[1].games[4].dates[0].minutes=0;
     ground[1].games[4].dates[1].availabledates[0]='\0';
     ground[1].games[4].dates[1].time=0;
     ground[1].games[4].dates[1].minutes=0;
     ground[1].games[4].dates[2].availabledates[0]='\0';
    ground[1].games[4].dates[2].time=0;
    ground[1].games[4].dates[2].minutes=0;
     ground[1].games[4].fixed_dates[0].reserved_dates[0]='\0';
     ground[1].games[4].fixed_dates[1].reserved_dates[0]='\0';    
      ground[1].games[4].fixed_dates[2].reserved_dates[0]='\0';

    strcpy(ground[2].groundname,"leo sports academy");
    strcpy(ground[2].cityname,"chennai");
    strcpy(ground[2].statename,"tamil nadu");
    strcpy(ground[2].games[0].gamename,"athletics");
    ground[2].games[0].hourlyrate=500;
    strcpy(ground[2].games[0].dates[0].availabledates,"2023-10-30");
    ground[2].games[0].dates[0].time=17;
    ground[2].games[0].dates[0].minutes=0;
    strcpy(ground[2].games[0].dates[1].availabledates,"2023-11-03");
    ground[2].games[0].dates[1].time=18;
    ground[2].games[0].dates[1].minutes=0;
    ground[2].games[0].dates[2].availabledates[0]='\0';
    ground[2].games[0].dates[2].time=0;
    ground[2].games[0].dates[2].minutes=0;
    strcpy(ground[2].games[0].fixed_dates[0].reserved_dates,"2023-11-01");
    strcpy(ground[2].games[0].fixed_dates[1].reserved_dates,"2023-11-02");
    ground[2].games[0].fixed_dates[2].reserved_dates[0]='\0';
   
    strcpy(ground[2].games[1].gamename,"cricket");
    ground[2].games[1].hourlyrate=2500;
    strcpy(ground[2].games[1].dates[0].availabledates,"2023-11-03");
    ground[2].games[1].dates[0].time=17;
    ground[2].games[1].dates[0].minutes=0;
    strcpy(ground[2].games[1].dates[1].availabledates,"2023-11-06");
    ground[2].games[1].dates[1].time=16;
    ground[2].games[1].dates[1].minutes=0;
    strcpy(ground[2].games[1].dates[1].availabledates,"2023-11-10");
    ground[2].games[1].dates[2].time=17;
    ground[2].games[1].dates[2].minutes=30;
    strcpy(ground[2].games[1].fixed_dates[0].reserved_dates,"2023-11-01");
    strcpy(ground[2].games[1].fixed_dates[1].reserved_dates,"2023-11-05");
    strcpy(ground[2].games[1].fixed_dates[2].reserved_dates,"2023-11-07");

    strcpy(ground[2].games[2].gamename,"baseball");
    ground[2].games[2].hourlyrate=3000;
    strcpy(ground[2].games[2].dates[0].availabledates,"2023-11-02");
    ground[2].games[2].dates[0].time=17;
    ground[2].games[2].dates[0].minutes=30;
    strcpy(ground[2].games[2].dates[1].availabledates,"2023-11-04");
    ground[2].games[2].dates[1].time=16;
    ground[2].games[2].dates[1].minutes=0;
    strcpy(ground[2].games[2].dates[1].availabledates,"2023-11-05");
    ground[2].games[2].dates[2].time=17;
    ground[2].games[2].dates[2].minutes=00;
    strcpy(ground[2].games[2].fixed_dates[0].reserved_dates,"2023-11-03");
    strcpy(ground[2].games[2].fixed_dates[1].reserved_dates,"2023-11-06");
    strcpy(ground[2].games[2].fixed_dates[2].reserved_dates,"2023-11-10");

    strcpy(ground[2].games[3].gamename,"basketball");
    ground[2].games[3].hourlyrate=2000;
    strcpy(ground[2].games[3].dates[0].availabledates,"2023-10-29");
    ground[2].games[3].dates[0].time=17;
    ground[2].games[3].dates[0].minutes=0;
    strcpy(ground[2].games[3].dates[1].availabledates,"2023-11-03");
    ground[2].games[3].dates[1].time=18;
    ground[2].games[3].dates[1].minutes=0;
    ground[2].games[3].dates[1].availabledates[0]='\0';
    ground[2].games[3].dates[2].time=0;
    ground[2].games[3].dates[2].minutes=0;
    strcpy(ground[2].games[3].fixed_dates[0].reserved_dates,"2023-10-30");
    strcpy(ground[2].games[3].fixed_dates[1].reserved_dates,"2023-11-01");
    ground[2].games[3].fixed_dates[2].reserved_dates[0]='\0';

    strcpy(ground[2].games[4].gamename,"swimming");
    ground[2].games[4].hourlyrate=2200;
    strcpy(ground[2].games[4].dates[0].availabledates,"2023-10-30");
    ground[2].games[4].dates[0].time=17;
    ground[2].games[4].dates[0].minutes=0;
    strcpy(ground[2].games[4].dates[1].availabledates,"2023-11-02");
    ground[2].games[4].dates[1].time=17;
    ground[2].games[4].dates[1].minutes=30;
    ground[2].games[4].dates[1].availabledates[0]='\0';
    ground[2].games[4].dates[2].time=0;
    ground[2].games[4].dates[2].minutes=0;
    strcpy(ground[2].games[4].fixed_dates[0].reserved_dates,"2023-11-05");
    ground[2].games[4].fixed_dates[1].reserved_dates[0]='\0';
    ground[2].games[4].fixed_dates[2].reserved_dates[0]='\0';
    int flag=0;
   for(int i = 0;i< MAX_NO_OF_GROUNDS && flag==0;i++)
   { 
   flag=1;
   for(int j=0;j< MAX_NO_OF_GROUNDS-i-1;j++)
      
     { if(strcmp(ground[j].groundname,ground[j+1].groundname)>0)
       {
            groundinfo temp=ground[j];
            ground[j]=ground[j+1];
            ground[j+1]=temp;  
            flag=0;  
       }
       else if(strcmp(ground[j].groundname,ground[j+1].groundname)==0)
       {
         if(strcmp(ground[j].cityname,ground[j+1].cityname)>0)
         {  groundinfo temp=ground[j];
            ground[j]=ground[j+1];
            ground[j+1]=temp;  
            flag=0; 
         }
       }
     }
    }
 for(int k=0;k< MAX_NO_OF_GROUNDS;k++)
 {    for(int i = 0;i< MAX_NO_OF_GAMES;i++)
     { 
         for(int j=0;j< MAX_NO_OF_GAMES-i-1&&ground[k].games[j].gamename[0]!='\0'&&ground[k].games[j+1].gamename[0]!='\0';j++)
           {  if(strcmp(ground[k].games[j].gamename,ground[k].games[j+1].gamename)>0) 
              {   gameschedule temp_1= ground[k].games[j];
                  ground[k].games[j]=ground[k].games[j+1];
                  ground[k].games[j+1]=temp_1;  
              }
           }
      }
      
  } 
  groundinfo temp_ground_1[MAX_NO_OF_GROUNDS];
  groundinfo temp_ground[MAX_NO_OF_GROUNDS];
  printf("Welcome to online grpund portal :\n");
  int flag_6=0;
  while(flag_6==0)
  {
    system("cls");
   printf("To get fixtures in city -> enter 1\n");
   printf("To get fixtures sorted on date entered-> enter 2\n");
   printf("To get available grounds-> enter 3\n");
   printf("To get unique sports in a ground-> enter4\n");
   printf("To find locations for a game-> enter 5\n");
   printf("To get clash of matches-> enter 6\n");
   printf("To get list of grounds having atleast k matches-> enter 7\n");
   printf("To sort on price for a game-> enter 8\n");
   int n,flag___=0;
   while(flag___==0)
   {
      printf("enter a valid number (1-8)  :"); 
      scanf("%d",&n);
      if(n<1||n>8)
      {
          printf("enter a valid number!!!\n");
      }
      else
      {
          flag___=1; 
      }
   }
 switch(n)
    {
      case 1: 
               printf("to get fixtures in the city, enter the following details\n");
               printf("enter city name: ");
               char cityname[50];
               scanf("%s",cityname);
               printf("enter begin date (YYYY-MM-DD): ");
               char begindate[11];
               scanf("%s",begindate);
               printf("enter end date (YYYY-MM-DD): ");
               char enddate[11];
               scanf("%s",enddate);
               getfixturesincity(ground,cityname,begindate,enddate);
               break;
     case(2):
               for(int i=0;i<MAX_NO_OF_GROUNDS;i++)
               {
                 temp_ground_1[i] = ground[i];
               }
               getFixuresSortedonDate(temp_ground_1);
               break;
     case(3):
                 for(int i=0;i<MAX_NO_OF_GROUNDS;i++)
                 {
                     temp_ground[i]=ground[i];
                 }
                 int flag1=0;
                 for(int i = 0;i< MAX_NO_OF_GROUNDS && flag1==0;i++)
                 { 
                  flag1=1;
                         for(int j=0;j< MAX_NO_OF_GROUNDS-i-1 && temp_ground[j].statename[0]!='\0' && temp_ground[j+1].statename[0]!='\0';j++)
       
                             { if(strcmp(temp_ground[j].statename,temp_ground[j+1].statename)>0)
                              {
                                 groundinfo temp_=temp_ground[j];
                                 temp_ground[j]=temp_ground[j+1];
                                 temp_ground[j+1]=temp_;  
                                 flag1=0;  
                               }
                               else if(strcmp(temp_ground[j].statename,temp_ground[j+1].statename)==0)
                               {
                                 if(strcmp(temp_ground[j].cityname,temp_ground[j+1].cityname)>0)
                                 {  
                                     groundinfo temp=temp_ground[j];
                                     temp_ground[j]=temp_ground[j+1];
                                     temp_ground[j+1]=temp;  
                                     flag1=0; 
                                 }
                               }
                            }
                  }    
                  printf("to get available in the city, enter the following details\n");
                  printf("enter gamename  - ");
                  char gamename[50];
                  scanf("%s",gamename);
                  printf("enter date(YYYY-MM-DD) ");
                  char date[11];
                  scanf("%s",date);
                  int time;
                  printf("enter time  - ");
                  scanf("%d",&time);
                  while(time < 0 || time > 23)
                  {
                    printf("enter valid time :");
                    scanf("%d",&time);
                  }
                  int minutes;
                  printf("Enter minutes : ");
                  scanf("%d",&minutes);
                  while(minutes < 0 || minutes > 59)
                  {
                    printf("enter valid minutes: ");
                    scanf("%d",&minutes);
                  }
                  isavailable(temp_ground,gamename,date,time,minutes);
                  break;
     case(4):    
                 printf("to get unique sports in each ground ,enter following details\n");
                 char ground_name[50];
                 printf("enter name of ground : ");
                 scanf("%[^\n]%*c", ground_name);
                 char city_name[50];
                 printf("enter name of city : ");
                 scanf("%s",city_name);
                 uniquesports(ground,ground_name,city_name);
                 break;
     case(5):
                 printf("If you want to find the location for a game w.r.t timem or date enter the following details\n");
                 char game__name[20];
                 printf("Enter the name of the game:");
                 scanf("%[^\n]%*c",game__name);
                 int flag_t=0,a;
                 while(flag_t==0)
                 {
                     printf("If you want to enter date(type 1) or time(type 2):");
                     scanf("%d",&a);
                     if(a!=1 && a!=2)
                     {
                         printf("Incorrect input value\nEnter either 1 or 2\n");
                     }
                     else
                     {
                         flag_t=1;
                     }
                 }
                 if(a==1)
                 {
                     char date_[11];
                     printf("Enter the date(YYYY-MM-DD):");
                     scanf("%[^\n]%*c",date_);
                     outputdates(ground,game__name,date);
  
                 } 
                 else
                 {
                     int hours_,minutes_;
                     int flag_1=0;
                     while(flag_1==0)
                     {
                         printf("Enter time in 24 hour format:\nenter hours:");
                         scanf("%d",&hours_);
                         if(hours_>23 || hours_<0)
                         {
                             printf("enter correct value\n");
                         }
                         else
                         {
                             printf("enter minutes:");
                             scanf("%d",&minutes_);
                             if(minutes_<0 || minutes_>59)
                             {
                                 printf("enter correct value\n");
                             }
                             else
                             {
                                 flag_1=1;
                                 outputtime(ground,game__name,hours_,minutes_);
                             }
                         }
                     }
                 }
                 break;
     case(6):
                 printf("to get clash of sports in ground ,enter following details\n");
                 int noofgrounds;
                 printf("enter no of grounds in the list\n");
                 fflush(stdin);
                 scanf("%d",&noofgrounds);
                 fflush(stdin);
                 char list_ground_name[MAX_NO_OF_GROUNDS][50];
                 for(int i=0;i<noofgrounds;i++)
                 {
                     fflush(stdin);
                     printf("enter name of ground : ");
                     scanf("%[^\n]%*c", list_ground_name[i]);
                     fflush(stdin);
                 }
                 char game_name[50];
                 printf("enter name of game : \n");
                 fflush(stdin);
                 scanf("%[^\n]%*c", game_name);
                 char dateofgame[11];
                 printf("enter the date of game (YYYY-MM-DD) :");
                 fflush(stdin);
                 scanf("%[^\n]%*c",dateofgame);
                 // list_ground_name[3][50]={"chepuk sports academy","leo sports academy","dharmasala sports academy"};
                 // char list_ground_name[3][50] = {
                 //     "chepuk sports academy",
                 //     "leo sports academy",
                 //     "dharmasala sports academy"
                 // };
                 clashofmatches(ground,list_ground_name,noofgrounds,dateofgame,game_name);
                 break;
     case(7):
                 printf("To get list of grounds having atleast k matches, enter the following data");
                 int noofgames ;
                 char gamelist[MAX_NO_OF_GAMES*MAX_NO_OF_GROUNDS][50];
                 printf("Enter no of Games");
                 fflush(stdin);
                 scanf("%d",&noofgames);
                 for(int i=0;i<noofgames;i++)
                 {
                     printf("Enter game name :");
                     fflush(stdin);
                     scanf("%[^\n]%*c",gamelist[i]);
                 }
                 char nameofcity[50];
                 printf("enter name of city :\n");
                 fflush(stdin);
                 scanf("%[^\n]%*c",nameofcity);
                 char gamedate[11];
                 printf("enter gamedate  :\n");
                 fflush(stdin);
                 scanf("%[^\n]%*c", gamedate);
                 int k;
                 printf("enter k\n");
                 fflush(stdin);
                 scanf("%d",&k);
                 givelistofgroundshavingatleastkmatches(ground,gamelist,gamedate,nameofcity,k,noofgames);
                 break;
     case(8):
             printf("If you want to sort the games based on the horly rate enter the following details\n");
             char nameOfGame_[20];
             printf("enter the name of the game:");
             fflush(stdin);
             scanf("%[^\n]*c",nameOfGame_);
             char gamedate_[11];
             printf("Enter the date(YYYY-MM-DD):");
             fflush(stdin);
             scanf("%[^\n]%*c",gamedate_);
             int hours_1,minutes_1;
             int flag_temp=0;
             while(flag_temp==0)
             {
                 printf("Enter time in 24 hour format:\nenter hours:");
                 scanf("%d",&hours_1);
                 if(hours_1>23 || hours_1<0)
                 {
                     printf("enter correct value\n");
                 }
                 else
                 {
                     printf("enter minutes:");
                     scanf("%d",&minutes_1);
                     if(minutes_1<0 || minutes_1>59)
                     {
                         printf("enter correct value\n");
                     }
                     else
                     {
                         flag_temp=1;
                         SortOnPriceForAGame(ground,nameOfGame_,gamedate_,hours_1,minutes_1);
                     }
                 }
             }
         break;
}
printf("Do you want to continue performing an operation?\n");
printf("enter y to continue or n to stop:");
char ch;
fflush(stdin);
scanf("%c",&ch);
if(ch=='n')
{
    flag_6=1;
}
}
system("cls");
printf("Thank you\n");
return 0;
}