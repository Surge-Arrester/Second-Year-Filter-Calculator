#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BL 14


int main(void)
{
    
/*******************************************************************************
Initialising the variables
*******************************************************************************/

long channel_0_ave, channel_1_ave, channel_2_ave, clock, r, s, u;

char chan_0_count[BL], chan_1_count[BL], chan_2_count[BL];

int a=0, b, c, d, t0, t1, t2, samples, temp, iteration, i;

/*******************************************************************************
Initialising the program and creating arrays
*******************************************************************************/

printf("\nWelcome to the program for the three dimensional location of an\
accoustic event\n\n");

printf("Please enter the clock frequency you are using with the hardware in MHz\n\n");
scanf("%i", &clock);

clock=clock*1E6;
printf("\n%.0d Hz clock speed inputted\n\n", clock);

printf("Please enter how many samples you would like to take for your average\nin this run\n\n");
scanf("%i", &samples);

long channel_0[samples], channel_1[samples], channel_2[samples];


/*******************************************************************************
Sending out the initial pulse
*******************************************************************************/
while (a!=1) 
      {
      printf("\nEnter 1 to send the initial pulse\n\n");
      scanf("%i", &a);
      }


for (iteration=0;iteration<samples;iteration++)
{
    printf("    _\n___| |___ has been sent\n\nWaiting for input from microphones");
    t0=t1=t2=1;
    a=b=c=d=0;
    
    
    /*******************************************************************************
    Testing for the T-Type to fall and reading in values
    *******************************************************************************/
    
    for (a=0;a!=3;)
    
    {  
        printf("\n\nType either 0, 1 or 2 to simulate that channels t-type falling to zero. \nCurrently Channel 0 is %d, Channel 1 is %d and Channel 2 is %d\n\n",t0, t1, t2);
        scanf("%d", &temp);
        { 
       if (temp<=2 && temp>=0)                                                  /*makes sure the user has entered a valid number*/
       
          { 
           if (temp==0)                                                         /*Standard if decision between three channels*/
                       {
                       printf("\nChannel 0 has fallen\n");
                       t0=0;
                       r=0;
                       printf("Enter the binary input of the number of counts \n(between 0 and 10011100010000)\n\n"); /*this is the same as 10,000 in binary*/
                       scanf("%s", &chan_0_count);                              /***Enters a binary value as  a string, will be altered later to take in value from pins*/         
                       for(i = 0; i < BL; i++)                                  /*For loop converts binary string into a standard integer*/
                       
                         {
                           r = r * 2 + (chan_0_count[i] == '1' ? 1 : 0);        /*works its way through the string, saves value in r*/
                         }
                         
                       printf("channel 0 is %i", r);                            /*gives user the decimal value entered*/
                       
                       b=1;                                                     /*tells program this channel has fallen*/
                       }
                       
            else if (temp==1)
                       {
                       printf("\nChannel 1 has fallen\n");
                       
                       t1=0;
                       s=0;
                       
                       printf("Enter the binary input of the number of counts \n(between 0 and 10011100010000)\n\n");/*this is the same as 10,000 in binary********************************************/
                       scanf("%s", &chan_1_count);                                                                   /*which is used as 10,000 counts measures 10cm, our estimated length of container*/
                      
                       for(i = 0; i < BL; i++)
                         {
                           s = s * 2 + (chan_1_count[i] == '1' ? 1 : 0);        /*works its way through the string, saves value in s*/
                         }
                         
                       printf("channel 1 is %i", s);
                       c=1;
                       }
                       
            else if (temp==2)
                       {   
                       printf("\nChannel 2 has fallen\n");
                       
                       t2=0;
                       u=0;
                       
                       printf("Enter the binary input of the number of counts \n(between 0 and 10011100010000)\n\n"); /*this is the same as 10,000 in binary*/
                       scanf("%s", &chan_2_count);
                       
                       
                       for(i = 0; i < BL; i++)
                         {
                           u = u * 2 + (chan_2_count[i] == '1' ? 1 : 0);        /*works its way through the string, saves value in u*/
                         }
                       
                       printf("channel 2 is %i", u);
                       
                       d=1;
                       }
           }
        }
        a=b+c+d;                                                                /*makes sure it doesn't move on until all three channels are zero*/
    }
       
    
/*******************************************************************************
 Taking these values and saving them in the correct bit of the array 
*******************************************************************************/
 channel_0[iteration]=r;
 channel_1[iteration]=s;
 channel_2[iteration]=u;       
 
 printf("\n\nt0=%d t1=%d t2=%d\n\n", t0, t1, t2);
 printf("\n\n%d  %d  %d\n\n", channel_0[iteration], channel_1[iteration], channel_2[iteration]);

}   

/*******************************************************************************
printing these values of the array 
*******************************************************************************/

printf("\n\nThe values of channel zero are: \n\n");

for (iteration=0;iteration<samples;iteration++)
    {
     printf("%d\n", channel_0[iteration]);
     }

printf("\n\nThe values of channel one are: \n\n");

for (iteration=0;iteration<samples;iteration++)
    {
     printf("%d\n", channel_1[iteration]);
     }

printf("\n\nThe values of channel two are: \n\n");

for (iteration=0;iteration<samples;iteration++)
    {
     printf("%d\n", channel_2[iteration]);
     }

printf("\n\n\nWe Have Finished Gathering Samples.\n\n");

/*******************************************************************************
Averaging this number to get a more accurate result
*******************************************************************************/

r=0;
for(iteration=0;iteration<samples;iteration++)                                  /*simply using r to add them all together, then divide by samples*/
                                              { 
                                              r+=channel_0[iteration];
                                              }
channel_0_ave=(r/samples);                                                      /*channel zero average calulated*/
printf("\n\n%i is the value of r, divided by %i samples gives the average of\
 channel 0:\n\n %i\n\n", r, samples, channel_0_ave);

s=0;
for(iteration=0;iteration<samples;iteration++)                                  /*simply using s to add them all together, then divide by samples*/
                                              { 
                                              s+=channel_1[iteration];
                                              }
channel_1_ave=(r/samples);                                                      /*channel one calculated*/
printf("\n\n%i is the value of r, divided by %i samples gives the average of\
 channel 0:\n\n %i\n\n", r, samples, channel_1_ave);

u=0;
for(iteration=0;iteration<samples;iteration++)                                  /*simply using u to add them all together, then divide by samples*/
                                              { 
                                              u+=channel_2[iteration];
                                              }
channel_2_ave=(r/samples);                                                      /*channel two calculated*/
printf("\n\n%i is the value of r, divided by %i samples gives the average of\
 channel 0:\n\n %i\n\n", r, samples, channel_2_ave);

/*******************************************************************************
Meat of the program
*******************************************************************************/


system ("PAUSE");
return 0;
}
