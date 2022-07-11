/*
									PROJECT ON ATM BANKING SYSTEM- By Debapriya Karmakar
*/
#include<stdio.h>
#include<stdlib.h>

float balance = 0;

void transaction_withdraw()
{
	float amount_to_withdraw;
	char ch;
	printf("\n\tPlease enter the amount to be withdrawn: ");
	scanf("%f",&amount_to_withdraw);
	if(amount_to_withdraw > balance)
	{
		printf("\n\tInsufficient fund in your account!");
	}
	else
	{
		//this implies that some amount of money is to be withdrawn from the user's account	
		//After the money is withdrawn, the balance in the user's account is updated
		balance = balance - amount_to_withdraw;
				
		printf("\n\tYou have successfully withdrawn %.2f!!", amount_to_withdraw);
		
		printf("\n\tDo you want your current balance to be displayed on the screen?(y/Y/n/N)   ");
		scanf(" %c",&ch);
		if(ch=='y' || ch=='Y')
		{
			printf("\n\tYour current balance is %.2f",balance);
		}
					
	}
	
}

void transaction_deposit()
{
	float amount_to_deposit;
	char ch;
	printf("\n\tEnter the amount to be deposited: ");
	scanf("%f",&amount_to_deposit);
			
	balance = balance + amount_to_deposit;
			
	printf("\n\tThank you for depositing!!");
	
	printf("\n\tDo you want your current balance to be displayed on the screen?(y/Y/n/N)   ");
	scanf(" %c",&ch);
	if(ch=='y' || ch=='Y')
	{
		printf("\n\tYour current balance is %.2f",balance);
	}
}

void check_balance()
{

	printf("\n\tYour account balance is %.2f", balance);		
	
}

void transaction()
{
	int choice;
	printf("\n\t-------------------------------------------------------------");
	printf("\n\tPlease follow the following instructions before your actions.");
	printf("\n\tPress '1' for withdrawl of money.");
	printf("\n\tPress '2' for money deposit.");
	printf("\n\tPress '3' for checking balance in your account.");
	printf("\n\n\tPlease enter your choice (1/2/3): ");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:							//first option should be to withdraw
			transaction_withdraw();
				
			break;
			
		case 2:							//For money deposit
			transaction_deposit();
			
			break;
			
		case 3:							//For checking account balance
			check_balance();
			
			break;
			
		default:
			printf("\n\tWRONG CHOICE!!");
			printf("\n\tPlease read the initial instructions carefully and press either 1 or 2 or 3!!");
			
	}
}

int main(void)
{
	int another_transaction , PIN, pin, ctr=0 , flag=0 , chances = 3;
	char name[100];
	printf("\n\tWelcome to SBI!");
	printf("\n\tPlease enter your name to complete the first process towards your account creation: ");
	gets(name);
	printf("\n\tWelcome %s!!",name);
	printf("\n\tPlease set your pin to create your account: ");
	scanf("%d",&pin);
	PIN = pin;
	
	printf("\n\tOkay %s, to start your transaction please enter your pin: ",name);
	
	label:
		if(ctr <= 3)
		{
			if(flag != 0 && ctr <= 2)
			{
				printf("\n\tPlease re-enter your pin (%d more attempts are left): ", chances);
				chances--;
			}
			else if(flag != 0 && (chances == 1))
			{
				printf("\n\tPlease re-enter your pin (this is your last and final attempt!): ");
			}
			scanf("%d",&pin);
			if(pin == PIN)
			{
				transaction();
				while(1)
				{		
					printf("\n\n\tDo you want another transaction?");				//Requesting the user for another transaction
					printf("\n\tIf yes, press '1' to proceed else '2' to exit. ");
					scanf("%d",&another_transaction);
					
					if(another_transaction == 1)
					{			
						transaction();					//transaction() function is called here once again for another transaction	
					}
					else if(another_transaction == 2)
					{
						break;
					}
				}
			}
			else
			{
				printf("\n\tWRONG PIN!!");
				ctr++;
				flag++;
				goto label;
			}
		}
	
	if(ctr > 3)
	{
		printf("\n\tSeems like you are not an authenticated customer!!");
		printf("\n\tAll the ATM facilities have been stopped for 48 hours from now and an e-mail has been sent to the authenticated customer warning him to take the desired actions!!");
		exit(0);
	}
	
	
	printf("\n\tTHANK YOU!!");
	return 0;
}
