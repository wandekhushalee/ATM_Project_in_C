#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
struct atm{
  int pin;
  float balance;
  double accNo;
  int cardNo;
}c1,c2,c3,c4,c5;
void declaration(int card,int pin){
    c1.pin = 1234;
    c2.pin = 4567;
    c3.pin = 3456;
    c4.pin = 6789;
    c5.pin = 8765;
    c1.balance = 1000;
    c2.balance = 2000;
    c3.balance = 3000;
    c4.balance = 5000;
    c5.balance = 10000;
    c1.cardNo = 7043;
    c2.cardNo = 9021;
    c3.cardNo = 3408;
    c4.cardNo = 6454;
    c5.cardNo = 3397;
    c1.accNo = 2107013054;
    c2.accNo = 3446465436;
    c3.accNo = 2314856434;
    c4.accNo = 2646132442;
    c5.accNo = 2561789566;
}
void mainMenu(){
    printf("****Please choose one of the option below****\n\n");
    printf("< 1 >  Check Balance\n");
    printf("< 2 >  Deposit\n");
    printf("< 3 >  Withdraw\n");
    printf("< 4 >  Change Pin\n");
    printf("< 5 >  Exit\n\n");
    
}
void checkBalance(float balance,double accNo){
   int res;
   FILE *ptr;
   ptr = fopen("bank.txt","a");
   printf("**You choose to See your balance**\n\n");
   printf("Do you wants Recipt\n\n");
   printf("< 1 > Yes\n");
   printf("< 2 > No\n");
   scanf("%d",&res);
   if(res == 1){
   	    FILE *fp;
   	    fp = fopen("recipt.txt","w");
   	    fprintf(fp,"\t\t\t\t\t\t\tATM TRANSACTION RECORD\n");
   	    fprintf(fp,"----------------------------------------------------------------------------\n");
		time_t t;
     	time(&t);
     	fprintf(fp,"\tDATE AND TIME = \t%s",ctime(&t));
     	fprintf(fp,"-----------------------------------------------------------------------------\n");
     	fprintf(fp,"\tTRANSACTION:\t BALANCE ENQUIRY\n");
     	fprintf(fp,"\tCURENT BAL.:\t $%f\n",balance);
     	fprintf(fp,"\tAVAILABLE BAL.:\t $%f\n",balance);
     	fprintf(fp,"\t\t\t\t\t\t****THANK YOU****\n");
		fclose(fp);
   }
   printf("\n\n*********Available Balance is: %2.f *********\n\n",balance);
   fprintf(ptr,"%.0f  Balance Enquiry   -----\t\t\t\t%.2f\n",accNo,balance);
   fclose(ptr);
}
float moneyDeposit(float balance,double accNo){
	int res;
	FILE *ptr;
	float deposit;
	ptr = fopen("bank.txt","a");
    printf("**You choose to Deposit a money**\n\n");
    printf("Do you wants Recipt\n\n");
    printf("< 1 > Yes\n");
    printf("< 2 > No\n");
    scanf("%d",&res);
    printf("$$$$Your Balance is: $%.2f\n\n", balance);
    printf("****Enter your amount to Deposit\n");
    scanf("%f", &deposit);
    
    
    balance += deposit;
    if(res == 1){
   	    FILE *fp;
   	    fp = fopen("recipt.txt","w");
   	    fprintf(fp,"\t\t\t\t\t\t\tATM TRANSACTION RECORD\n");
   	    fprintf(fp,"----------------------------------------------------------------------------\n");
		time_t t;
     	time(&t);
     	fprintf(fp,"\tDATE AND TIME = \t%s",ctime(&t));
     	fprintf(fp,"-----------------------------------------------------------------------------\n");
     	fprintf(fp,"\tTRANSACTION:\t CASH DEPOSIT\n");
     	fprintf(fp,"\tAMOUNT.:\t $%f\n",deposit);
     	fprintf(fp,"\tCURENT BAL.:\t $%f\n",balance);
     	fprintf(fp,"\tAVAILABLE BAL.:\t $%f\n",balance);
     	fprintf(fp,"\t\t\t\t\t\t****THANK YOU****\n");
		fclose(fp);
   }
    printf("Your Money is Diposited Successfully\n");
    printf("\n****Your New Balance is: %.2f\n\n", balance);
    fprintf(ptr,"%.0f  Deposite          %.2f\t\t\t%.2f\n",accNo,deposit,balance);
    return balance;
    fclose(ptr);
}

float moneyWithdraw(float balance,double accNo) {
	int res;
	float new_balance;
    float withdraw;
    FILE *ptr;
    int flag = 0;
    ptr = fopen("bank.txt","a");
    printf("**You choose to Withdraw a money**\n\n");
    printf("Do you wants Recipt\n\n");
    printf("< 1 > Yes\n");
    printf("< 2 > No\n");
    scanf("%d",&res);
    printf("$$$$Your Balance is: $%.2f\n\n", balance);
    printf("Enter your amount to withdraw:\n");
    scanf("%f", &withdraw);
    
    
    if (withdraw < balance) {
    	new_balance = balance - withdraw;
        if(new_balance >= 500){
        printf("\n$$$$Your withdrawing money is:  $%.2f\n", withdraw);
        printf("****Your New Balance is:   $%.2f\n\n", new_balance);
        flag = 1;
        }
        else{
        printf("+++You don't have enough money+++\n");
        printf("Please contact to your Bank Customer Services\n\n");
        printf("****Your Balance is:   $%.2f\n\n", balance);
        }
    }
    
    else  {
        
        printf("+++You don't have enough money+++\n");
        printf("Please contact to your Bank Customer Services\n");
        printf("****Your Balance is:   $%.2f\n\n", balance);
    
    }
    if(flag == 1 && res == 1){
    	FILE *fp;
   	    fp = fopen("recipt.txt","w");
   	    fprintf(fp,"\t\t\t\t\t\t\tATM TRANSACTION RECORD\n");
   	    fprintf(fp,"----------------------------------------------------------------------------\n");
		time_t t;
     	time(&t);
     	fprintf(fp,"\tDATE AND TIME = \t%s",ctime(&t));
     	fprintf(fp,"-----------------------------------------------------------------------------\n");
     	fprintf(fp,"\tTRANSACTION:\t CASH WITHDRAWAL\n");
     	fprintf(fp,"\tAMOUNT.:\t$%f\n",withdraw);
     	fprintf(fp,"\tCURENT BAL.:\t $%f\n",new_balance);
     	fprintf(fp,"\tAVAILABLE BAL.:\t $%f\n",new_balance);
     	fprintf(fp,"\t\t\t\t\t\t\t****THANK YOU****\n");
		fclose(fp);
	}
    if(flag == 1){
    fprintf(ptr,"%.0f  Withdraw          %.2f\t\t\t%.2f\n",accNo,withdraw,new_balance);
    }
else{
      fprintf(ptr,"%.0f  Withdraw          -----\t\t\t\t%.2f\n",accNo,balance);
    }
  fclose(ptr);
    return new_balance;
}
int newPin(float balance,double accNo){
	FILE *ptr;
    ptr = fopen("bank.txt","a");
	int res,new_pin;
	printf("**Are You Sure You Want To Change the pin**\n");
	printf("< 1 > Yes\n");
    printf("< 2 > No\n");
    scanf(" %d",&res);
    if(res == 1){
    	printf("*****Enter your new pin ******\n");
    	scanf("%d",&new_pin);
	}
	else{
	exit(0);	
   }
   printf("****Your pin has been successfully changed****\n");
   fprintf(ptr,"%.0f  Pin changed       %d\t\t\t%.2f\n",accNo,new_pin,balance);
   fclose(ptr);
   return new_pin;
}
void menuExit() {
    printf("--------------Take your receipt!!!------------------\n");
    printf("-------Please Take Your Card-----------\n");
    printf("-----Thank you for Banking With Us!!!-----\n");  
}

int main(){
    int ch,new_pin;
	int i=0;
    char c;
	char pwd[30];
    int res;
    int new_no;
    printf("********Welcome To ATM Banking***********\n");
    printf("Enter the last four digit of your card No.\n");
    scanf("%d",&new_no);
    printf("Please Enter Your Pin\n");
    while((c = _getch()) !=13){
		pwd[i] = c;
		i++;
		printf("*");
	}
	 pwd[i] ='\0';
	 new_pin = atoi(pwd);
    declaration(new_no,new_pin);
    if(new_no == c1.cardNo && new_pin == c1.pin ){
       do
       {
          mainMenu();
          printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
          printf("Your Selection\n");
          scanf("%d",&ch);
          switch(ch)
          {
            case 1:
			    checkBalance(c1.balance,c1.accNo);
                break;
            
            case 2:
            	c1.balance = moneyDeposit(c1.balance,c1.accNo);
            	break;
            
            case 3:
            	c1.balance = moneyWithdraw(c1.balance,c1.accNo);
                break;
                
            case 4:
            	c1.pin = newPin(c1.balance,c1.accNo);
            	break;
            
            case 5:
            	menuExit();
                return 0;
          }
          printf("Would you like to do another transection:\n");
          printf("< 1 > Yes\n");
          printf("< 2 > No\n");
          scanf(" %d",&res);
          if(res == 2){
          	printf("--------------Take your receipt!!!------------------\n");
            printf("-------Please Take Your Card-----------\n");
            printf("-----Thank you for Banking With Us!!!-----\n");  
		  }
       }while(res == 1);
    }
    else if(new_pin == c2.pin && new_no == c2.cardNo){
       do
       {
          mainMenu();
          printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
          printf("Your Selection\n");
          scanf("%d",&ch);
          switch(ch)
          {
            case 1:
			    checkBalance(c2.balance,c2.accNo);
                break;
            
            case 2:
            	c2.balance = moneyDeposit(c2.balance,c2.accNo);
            	break;
            
            case 3:
            	c2.balance = moneyWithdraw(c2.balance,c2.accNo);
                break;
            
            case 4:
            	c2.pin = newPin(c2.balance,c2.accNo);
            	break;
            
            case 5:
            	menuExit();
                return 0;
          }
          printf("Would you like to do another transection:\n");
          printf("< 1 > Yes\n");
          printf("< 2 > No\n");
          scanf(" %d",&res);
          if(res == 2){
          	printf("--------------Take your receipt!!!------------------\n");
            printf("-------Please Take Your Card-----------\n");
            printf("-----Thank you for Banking With Us!!!-----\n");  
		    }
       }while(res == 1);
    }
    else if(new_pin == c3.pin && new_no == c3.cardNo){
    	do
       {
          mainMenu();
          printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
          printf("Your Selection\n");
          scanf("%d",&ch);
          switch(ch)
          {
            case 1:
			    checkBalance(c3.balance,c3.accNo);
                break;
            
            case 2:
            	c3.balance = moneyDeposit(c3.balance,c3.accNo);
            	break;
            
            case 3:
            	c3.balance = moneyWithdraw(c3.balance,c3.accNo);
                break;
                
            case 4:
            	c3.pin = newPin(c3.balance,c3.accNo);
            	break;
                
            case 5:
            	menuExit();
                return 0;
          }
          printf("Would you like to do another transection:\n");
          printf("< 1 > Yes\n");
          printf("< 2 > No\n");
          scanf(" %d",&res);
          if(res == 2){
          	printf("--------------Take your receipt!!!------------------\n");
            printf("-------Please Take Your Card-----------\n");
            printf("-----Thank you for Banking With Us!!!-----\n");  
		  }
       }while(res == 1);
    }
    else if(new_pin == c4.pin && new_no == c4.cardNo){
    	 do
       {
          mainMenu();
          printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
          printf("Your Selection\n");
          scanf("%d",&ch);
          switch(ch)
          {
            case 1:
			    checkBalance(c4.balance,c4.accNo);
                break;
            
            case 2:
            	c4.balance = moneyDeposit(c4.balance,c4.accNo);
            	break;
            
            case 3:
            	c4.balance = moneyWithdraw(c4.balance,c4.accNo);
                break;
            
            case 4:
            	c4.pin = newPin(c4.balance,c4.accNo);
            	break;
            
            case 5:
            	menuExit();
                return 0;
          }
          printf("Would you like to do another transection:\n");
          printf("< 1 > Yes\n");
          printf("< 2 > No\n");
          scanf(" %d",&res);
          if(res == 2){
          	printf("--------------Take your receipt!!!------------------\n");
            printf("-------Please Take Your Card-----------\n");
            printf("-----Thank you for Banking With Us!!!-----\n");  
		  }
       }while(res == 1);
    }
    else if(new_pin == c5.pin && new_no == c5.cardNo){
    	 do
       {
          mainMenu();
          printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
          printf("Your Selection\n");
          scanf("%d",&ch);
          switch(ch)
          {
            case 1:
			    checkBalance(c5.balance,c5.accNo);
                break;
            
            case 2:
            	c5.balance = moneyDeposit(c5.balance,c5.accNo);
            	break;
            
            case 3:
            	c5.balance = moneyWithdraw(c5.balance,c5.accNo);
                break;
            
            case 4:
            	c5.pin = newPin(c5.balance,c5.accNo);
            	break;
            
            case 5:
            	menuExit();
                return 0;
          }
          printf("Would you like to do another transection:\n");
          printf("< 1 > Yes\n");
          printf("< 2 > No\n");
          scanf(" %d",&res);
          if(res == 2){
          	printf("--------------Take your receipt!!!------------------\n");
            printf("-------Please Take Your Card-----------\n");
            printf("-----Thank you for Banking With Us!!!-----\n");  
		  }
       }while(res == 1);
    }
    else
    {
    	printf("***Your pin is invalid***\n");
    	printf("***Please Enter the correct Pin***\n");
	}
	return 0;
}
   


	



