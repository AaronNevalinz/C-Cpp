#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct user{
	char name[20];
	char phone[20];
	char password[20];
	float balance;
};

int main(){
	int opt;
	struct user usr;
	char phone[20];
	char pword[20], filename[20];
	FILE *fp;
	
	printf("\nWhat do you want to do?");
	printf("\n1. Register an account");
	printf("\n2. Login to an account\n\n");
	
	printf("Your Choice:\t");
	scanf("%d", &opt);
	
	switch(opt){
		case 1:
			system("cls");
			printf("Enter name:\t\t");
			scanf("%s", &usr.name);
			printf("Enter Phone Number:\t");
			scanf("%s", &usr.phone);
			printf("Enter password:\t");
			scanf("%s", &usr.password);
			usr.balance = 0;
			char file_location[50];
			strcpy(file_location, "D:\\Work\\LAB\\C++ Projects\\Online Banking System\\accounts\\");
			strcpy(filename, file_location);
			strcpy(filename, usr.phone);
			fp = fopen(strcat(filename, ".bat"), "w");
			fwrite(&usr, sizeof(struct user), 1, fp);
			if(fwrite!=0){
				printf("Account successfully created...");
			}else{
				printf("Something went wrong, please try again.");
			}
			fclose(fp);
		break;
		case 2:
			system("cls");
			printf("Phone Number:\t");
			scanf("%s", &phone);
			printf("Password:\t");
			scanf("%s", &pword);
			strcpy(filename, phone);
			fp = fopen(strcat(filename, ".bat"), "r");
			fread(&usr, sizeof(struct user), 1, fp);
			fclose(fp);
			if(!strcmp(pword, usr.password)){
				printf("password matched");
			}
		break;
		default:
			printf("\n\nInvalid Option, please try again...\n\n");	
	}
	return 0;
}
