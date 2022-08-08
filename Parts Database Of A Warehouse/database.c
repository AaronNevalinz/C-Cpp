#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define NAME_LEN 20
#define MAX_PARTS 100

struct part{
	int part_number;
	char part_name[NAME_LEN];
	int on_hand;
}inventory[MAX_PARTS];

int num_part = 0;

int find_part(int number){
	int i;
	for(i=0; i<num_part; i++){
		if(inventory[i].part_number == number)
			return 1;
	}
	return -1;
}
void print_database(){
	int i;
	printf("Part Number\tPart Name\tOn hand\n");
	for(i = 0; i < num_part + 1; i++){
		printf("%d\t%s\t%d\n", inventory[i].part_number, inventory[i].part_name, inventory[i].on_hand);
	}
}
void generateDatabaseHeader(){
	printf("--------------------------------------\n");
	printf("DataBase Info:\n");
	printf("NEVALINZ.CO DEPARTMENT OF WAREHOUSING\n");
	printf("%s\n", __DATE__);
	printf("--------------------------------------\n\n");
}
void generateDatabaseFooter();
int main(){
	int opt;
	FILE *fp;
	char *filename;
	
	generateDatabaseHeader();
	
	printf("Enter Your Prefered Option:\n\n");
	printf("1. Insert New Data\n");
	printf("2. Search For Data\n");
	printf("3. Updata Database\n");
	printf("4. Print Database\n");
	printf("5. Exit\n\n");
	
	printf("Your Choice:\t");
	scanf("%d", &opt);
	printf("\n\n");
	system("cls");
	switch(opt){
		case 1:
			generateDatabaseHeader();
			printf("New Stock Added to Warehouse\n\n");
			if(num_part == MAX_PARTS){
				printf("DataBase is full; Can't add new stock. Talk to admin");
				break;
			}
			int part_num;
			printf("Enter part Number:\t");
			scanf("%s", &part_num);
			inventory[num_part].part_number = part_num;
			printf("Enter part name:\t");
			scanf("%s", &inventory[num_part].part_name);
			filename = inventory[num_part].part_name;
			fp = fopen(strcat(filename, ".bat"), "w");
			
			fclose(fp);
			printf("Enter Quantity at hand:\t");
			scanf("%d", &inventory[num_part].on_hand);
			num_part++;
			break;
		case 2:
			generateDatabaseHeader();
			printf("Search For Data\n\n");
			printf("Enter part Name to search:\t");
			char *search_name;
			scanf("%s", search_name);
			break;
		case 4:
			generateDatabaseHeader();
			print_database();
			break;
	}
	return 0;
}
