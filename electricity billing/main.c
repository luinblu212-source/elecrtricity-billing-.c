#include <stdio.h>
#include <stdlib.h>

int main()
{
      //customer information
      char name[100];
      char meternumber[30];
      char unpaid;
      char anothercustomer;

      //whole number variables
      int units;
      int customers=0;

      //billing variables
      float energycost;
      float servicecharge=150;
      float penalty;
      float totalbill;
      float totalrevenue=0;


      printf("\n========================================\n");
           printf("   ELECTRICITY BILL SYSTEM\n");
      printf("==========================================\n");
      do
      {



      printf("\nenter customer full name\n");
      fgets(name,sizeof(name),stdin);

      printf("Enter meter number\n");
      scanf("%29s",meternumber);

      printf("enter electricity units consumed");
      scanf("%d",&units);

      while(units<=0)
      {
          printf("invalid units!enter units greater than zero");
          scanf("%d",&units);

      }
      if(units<=50)
      {
          energycost=units*10;
      }
      else if(units<=150)
      {
          energycost=(50*10)+((units-50)*15);
      }
      else if(units<=300)
      {
         energycost=(50*10)+(100*15)+((units-150)*20);

      }
      else
      {
          energycost=(50*10)+(100*15)+(150*20)+((units-300)*25);
      }
      /*add service charge*/
      totalbill=energycost+servicecharge;

      /*check previous bill payment*/

      printf("was the previous bill unpaid?(Y/N):");
      scanf(" %c",&unpaid);

      if(unpaid=='Y'||unpaid=='y')
      {
          penalty=totalbill*0.10;
      }
      else
      {
          penalty=0;
      }
      totalbill=totalbill+penalty;

      //display customer bill



            printf("\n================CUSTOMER BILL================\n");
                  printf("customer name:%s",name);
                  printf("meternumber:%s\n",meternumber);
                  printf("units consumed:%d\n",units);
                  printf("electricitycost:ksh%.2f\n",energycost);
                  printf("service charge:ksh%.2f\n",servicecharge);
                  printf("late penalty:ksh%.2f\n",penalty);
                  printf("total bill:ksh%.2f\n",totalbill);
                  printf("\n===========================================\n");
                  //update customer count and revenue

                  customers++;
                  totalrevenue=totalrevenue+totalbill;


                  printf("\nRegister another customer?(Y/N)");
                  scanf(" %c",&anothercustomer);

                  getchar();
      }
      while(anothercustomer=='Y'||anothercustomer=='y');

      //summary

      printf("\n=========BILLING SUMMARY=============\n");
      printf("total customers:%d\n",customers);
      printf("totalrevenue:ksh%.2f\n",totalrevenue);
      printf("==========================================\n");












     return 0;
}
