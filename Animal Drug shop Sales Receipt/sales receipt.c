#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct item{
	char name[20];
	float price;
	float qty;	
};
void generateHeader(){
	printf("----------------------------------\n");
	printf("SALE RECEIPT\n\n");
	printf("Mwegwa Animal DrugShop\n\n");
	printf("aaronug421@gmail.com\n\n");
	printf("0777306662/0755004133\n");
	printf("----------------------------------\n\n\n");
}
void generateReceiptNo(){
	printf("----------------------------------\n");
	printf("Receipt No: 10928\n");
	printf("----------------------------------\n\n");
}
void generateFooter(){
	printf("----------------------------------\n");
	printf("1 item(s)\n");
	printf("served by: Dinah Angom\n");
	printf("Date: %s\n", __DATE__);
	printf("----------------------------------\n");
	printf("Thank you for shopping with us\n");
	printf("----------------------------------\n");
	printf("Powered By: Aaron Nevalinz Ogwal");
	printf("\n\n\n");
}
void generateBody(int count, struct item item[count]){
	int i;
	printf("sn\tItem\tQty\tPrice\n");
	for(i = 0; i<count; i++){
		printf("%i\t", i+1);
		printf("%s\t", item[i].name);
		printf("%.2f\t", item[i].qty);
		printf("%.2f\n\n", item[i].price);
	}
	
}
float total = 0, vat, discount, netTotal;
void generateTotalsAndTaxesAndDiscount(int count, struct item item[count]){
	int i;
	for(i = 0; i<count; i++){
		total += item[i].price;
	}
	discount = 0.1*total;
	netTotal = total - discount;
	vat = 0.00;
	printf("----------------------------------\n");
	printf("TOTAL VATABLE:\tUGX%.2f", vat);
	printf("\nTOTAL EXEMPT:\tUGX%.2f", total);
	printf("\n----------------------------------\n");
	printf("\nTOTAL AMOUNT:\tUGX%.2f", netTotal);
	printf("\n----------------------------------\n");
	printf("\nVAT AMOUNT:\tUGX%.2f", vat);
	printf("\n----------------------------------\n");
	printf("DISCOUNT:\tUGX%.2f", discount);
	printf("\n");
}





int main(){
	int count, i, opt;
	printf("Please Select Your Prefered Option\n\n");
	printf("1.Generate Sales Receipt:\n");
	printf("2.Show all Sales Receipt\n");
	printf("3.Search Invoice\n");
	printf("4.Exit\n\n");
	
	printf("Your Choice:\t");
	scanf("%d", &opt);
	 
	system("cls");
	
	switch(opt){
		case 1:
			generateHeader();
			printf("No of Item(s) Purchased:\t");
			scanf("%d", &count);
			printf("\n");
			struct item item[count];
			for(i =0; i<count; i++){
				printf("Item %i:\t\t", i+1);
				scanf("%s", &item[i].name);
				printf("Quantity:\t");
				scanf("%f", &item[i].qty);
				printf("Price:\t\t");
				scanf("%f", &item[i].price);
				printf("\n\n");
			}
			system("cls");
			generateHeader();
			generateBody(count, item);
			generateTotalsAndTaxesAndDiscount(count, item);
			generateFooter();
			break;
	}
	
	return 0;
}
