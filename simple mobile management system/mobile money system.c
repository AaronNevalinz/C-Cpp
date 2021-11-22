#include<stdio.h>
#define MIN 500     		         //minimum amount of money the user can send
#define MAX 5000000			//maximum amount of money the user can send

void send_money();
void mobile_user();
void east_africa();
void amount();
void enter_pin();
void momopay();
void airtime();
void payments();
void savings();
void financial_services();
void withdraw_money();
void my_account();
//global variable
int amt, number;
int main()
{
	int option;// option for the mobile money system, page one
	
	printf("MTN mobile money\n");
	printf("1) Send money\n");
	printf("2) Airtime & bundles\n");
	printf("3) MomoPay\n");
	printf("4) Payments\n");
	printf("5) Savings & loans\n");
	printf("6) Financial Services\n");
	printf("7) Withdraw money\n");
	printf("8) My Account\n\n");
	
	scanf("%d", &option);
	switch(option)
	{
		case 1:
			send_money();
			break;
		case 2:
			airtime();
			break;
		case 3:
			momopay();
			break;
		case 4:
			payments();
			break;
		case 5:
			savings();
			break;
		case 6:
			financial_services();
			break;
		case 7:
			withdraw_money();
			break;
		case 8:
			my_account();
			break;
		default:
			printf("Enter options 1-8:");
			break;
	}
	
	return (0);
}
/**********************************************************************************************
The send money options for the user
displays the various send money options for the user
***********************************************************************************************/


void send_money()
{	
	int x;/* options under send money*/
	
	printf("Send Money\n");
	printf("1) mobile user\n");
	printf("2) East africa\n");
	printf("3) Rest of Africa\n");
	printf("4) send with care\n");
	printf("5) Donations\n");
	
	scanf("%d", &x);
	switch(x)
	{
		case 1:
			mobile_user();
			break;
		case 2:
//			east_africa();
			break;
		default:
			printf("Enter 1 or 2:");
			break;
	}
	
}
/****************************************************************************************************************
mobile_user
void
purpose: prompts for and reads the tel-number entered by the user
if the number is not exactly a 10 digit length, the program displays invalid digit length then terminates
*****************************************************************************************************************/
void mobile_user()
{
	int count = 0;
	int number;
	printf("Enter number you are sending to:\n");
	scanf("%d", &number);
	
	while(number != 0)
	{
		number = number/10;
		++count;
	}
	if(count == 9)
		amount();
	else if(count < 9)
		printf("invalid phone number length");
	else
		printf("invalid phone number length");
		
}

/**************************************************************************************************
amount
prompts for and reads the amount of money to be sent
if the amount is less than the range or more than the range, program terminates
***************************************************************************************************/

void amount()
{
	int amt;
	
	printf("Enter amount:\n");
	scanf("%d", &amt);
	
	if((amt>=MIN)&&(amt<=MAX))
	 	enter_pin();
	else
		printf("Y'ello. Transaction failed. Enter amount range(500-5M).\nPlease try again ");
}
/*****************************************************************************************************
enter_pin
prompts for and reads the pin entered by the user
if the pin length is less than or even more than designed pin length of 5
program prints invalid pin length and terminates
******************************************************************************************************/
void enter_pin()
{
	int count = 0;
	int pin;
	printf("You are sending %d to %d\n", amt, number);
	printf("Enter PIN to confirm:\n");
	scanf("%d", &pin);
	
	while(pin != 0)
	{
		pin = pin/10;
		++count;
	}
	if(count == 5)
		printf("initializng transaction");
	else 
		printf("invalid PIN length");
	
}

/*******************************************************************************************************
*airtime bundle option
********************************************************************************************************/
void airtime()
{
	printf("Airtime and Bundles\n");
	printf("1) Airtime\n");
	printf("2) voice bundles\n");
	printf("3) internet bundles\n");
	printf("4) internet with ott\n");
	printf("5) special bundles\n");
	printf("6) pay ott tax\n");
	printf("7) buy airtime stock\n");
	
}
/***************************************************************************************************
	momopay
		-ask the user to enter the merchant code
****************************************************************************************************/
void momopay()
{
	printf("Enter the merchant code:\n");
}
/***************************************************************************************************
	payments
		-a choice of the various payment options
****************************************************************************************************/
void payments()
{
	printf("Payments\n");
	printf("1) utilities\n");
	printf("2) pay TV\n");
	printf("3) School fees\n");
	printf("4) Goods and Services\n");
	printf("5) Fees and Taxes\n");
	printf("6) Lotto and sports betting\n");
	printf("7) music and video\n");
}
/*************************************************************************************************
	savings
		-saving options
***************************************************************************************************/
void savings()
{
	printf("Savings & Loans\n");
	printf("1) MoKash\n");
	printf("2) Device loan\n");
}
/**************************************************************************************************
	financial_services
		-financial services available
***************************************************************************************************/
void financial_services()
{
	printf("Financial Services\n");
	printf("1) Bank deposits\n");
	printf("2) Bank withdrawals\n");
	printf("3) SACCO\n");
	printf("4) Pension schemes\n");
	printf("5) MTN momocards\n");
	printf("0) Back\n");
}
/**************************************************************************************************
	with_draw money
		- withdraw money options
****************************************************************************************************/
void withdraw_money()
{
	printf("Withdraw Money\n");
	printf("1) From ATM\n");
	printf("2) From western union\n");
}
/***************************************************************************************************
	my_account
		- user's account options
****************************************************************************************************/
void my_account()
{
	printf("My Account\n");
	printf("1) check balance\n");
	printf("2) My approvals\n");
	printf("3) My transactions\n");
	printf("4) Change PIN\n");
	printf("5) PIN reset\n");
	printf("6) Change language\n");
	printf("7) Pre approval\n");
	printf("8) Info\n");
	printf("0) Back\n");
}
