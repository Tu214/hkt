#include<stdio.h>
#include<string.h>

struct Contact{
	char name[50];
	char phoneNumber[15];
	char email[50];
};

void printfMenu();
void addContact(struct Contact list[], int *sizePtr);
void printfContact(struct Contact list[], int size);
void seachContact(struct Contact list[], int size);
void deleteContact(struct Contact list[], int *sizePtr);

int main(){
	struct Contact contact[100];
	int choice;
	int currentSize = 0;
	
	do{
		printfMenu();
		scanf("%d", &choice);
		
		switch(choice){
			case 1:{
				addContact(contact,&currentSize);
				break;
			}
			case 2:{
				printfContact(contact,currentSize);
				break;
			}
			case 3:{
				
				break;
			}
			case 4:{
				
				break;
			}
			case 5:{
				
				break;
			}
			default:{
				printf("lua chon khong hop le!\n");
				break;
			}
		}
	}while(choice!=5);
}

void printfMenu(){
	printf("\n+------------ MENU ------------+\n");
	printf("|1. them lien he moi           |\n");
	printf("|2. hien thi tat ca lien he    |\n");
	printf("|3. tim kiem theo ten          |\n");
	printf("|4. xoa lien he theo ten       |\n");
	printf("|5. thoat                      |\n");
	printf("+------------------------------+\n");
	printf(">> lua chon cua ban: ");
}

void addContact(struct Contact list[], int *sizePtr){
	if(*sizePtr >= 100){
		printf("danh ba da day!\n");
	}
	struct Contact newContact;
	int n;
	printf("nhap so lien he muon them: ");
	scanf("%d",&n);
	
	for(int i = 0 ; i < n ; i++){
		printf("----- Contact%d -----\n",i+1);
		
		printf("nhap ten: ");
		while(getchar() != '\n');
		fgets(newContact.name, sizeof(newContact.name), stdin);
		newContact.name[strcspn(newContact.name, "\n")] = 0;
		
		printf("nhap SDT: ");
		fgets(newContact.phoneNumber, sizeof(newContact.phoneNumber), stdin);
		newContact.phoneNumber[strcspn(newContact.phoneNumber, "\n")] = 0;
		
		printf("nhap email: ");
		fgets(newContact.email, sizeof(newContact.email), stdin);
		newContact.email[strcspn(newContact.email, "\n")] = 0;
	}
}

void printfContact(struct Contact list[], int size){
	char line[] = "+----------------------+----------------------+---------------------+\n";
	printf("%s",line);
	printf("| %-20s | %-20s | %-20s|\n", "Name", "Phone Number", "Email");
	printf("%s", line);
	
	for(int i = 0 ; i < size ; i++){
		printf("| %-20s | %-20s | %-20s|\n",list[i].name, list[i].phoneNumber, list[i].email);
		printf("%s",line);
	}
}
