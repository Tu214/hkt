#include<stdio.h>
#include<string.h>

struct Student{
	char name[50];
	int age;
	float grade;
};

void printfMenu();
void inputStudent(struct Student list[],int *sizePtr);
void printfStudent(struct Student list[], int size);
void averageGade(struct Student list[], int size);

int main(){
	struct Student student[50];
	int choice;
	int currentSize = 0;
	do{
		printfMenu();
		scanf("%d", &choice);
		
		switch(choice){
			case 1:{
				inputStudent(student, &currentSize);
				break;
			}
			case 2:{
				printfStudent(student, currentSize);
				break;
			}
			case 3:{
				averageGade(student,currentSize);
				break;
			}
			case 4:{
				printf("tam biet!\n");
				break;
			}
			default:{
				printf("lua chon khong hop le!\n");
				break;
			}
		}
	}while(choice != 4);
}

void printfMenu(){
	printf("\n+---------------- MENU -----------------+\n");
	printf("|1. nhap thong tin cua hoc sinh         |\n");
	printf("|2. hien thi thong tin cua hoc sinh     |\n");
	printf("|3. diem trung binh cua tat ca hoc sinh |\n");
	printf("|4. thoat                               |\n");
	printf("+---------------------------------------+\n");
	printf(">> lua chon cua ban: ");
}

void inputStudent(struct Student list[],int *sizePtr){
	struct Student student;
	int n;
	printf("so hoc sinh can nhap thong tin: ");
	scanf("%d",&n);
	
	for(int i = 0 ; i < n ; i++){
		printf("----- HS%d -----\n",i+1);
		while(getchar() != '\n');
		
		printf("nhap ten hs: ");
    	fgets(student.name, sizeof(student.name), stdin);
    	student.name[strcspn(student.name, "\n")] = 0;
    	
    	printf("nhap tuoi hs: ");
    	scanf("%d", &student.age);
    	
    	printf("nhap diem hs: ");
    	scanf("%f", &student.grade);
    	
    	list[*sizePtr] = student;
    	(*sizePtr)++;
	}
}

void printfStudent(struct Student list[], int size){
	if(size == 0){
		printf("mang rong!\n");
		return;
	}
	
	char line[]= "+----------------------+------------+------------+\n";
	printf("%s",line);
	printf("| %-20s | %-10s | %-10s |\n", "Ho va Ten", "Tuoi", "Diem");
	printf("%s",line);
	
	for(int i = 0 ; i < size ; i++){
		printf("| %-20s | %-10d | %-10.2f |\n",list[i].name, list[i].age, list[i].grade);
		printf("%s",line);
	}
}

void averageGade(struct Student list[], int size){
	if(size == 0){
		printf("khong co du lieu de tinh toan!\n");
		return;
	}
	float sum = 0;
	for(int i = 0 ; i < size ; i++){
		sum += list[i].grade;
	}
	printf(">> diem trung binh cua tat ca hoc sinh: %.2f",sum/size);
}
