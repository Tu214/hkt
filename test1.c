#include<stdio.h>

int main(){
	
	int arr[100],size,choice,i,j,value,index;
	
	do{
		printf("\n================MENU QUAN LY BANG SO NGUYEN============\n");
		printf("1. nhap so phan tu va gia tri phan tu\n");
		printf("2. in gia tri pha tu ca mang\n");
		printf("3. tong va trung binh cong cac phan tu cua mang\n");
		printf("4. sap sep mang selection sort giam dan\n");
		printf("5. tim kiem phan tu\n");
		printf("6. xoa phan tu theo chi so\n");
		printf("7. chen phan tu vao mang\n");
		printf("8. xoa tat ca phan tu co gia tri nhat dinh\n");
		printf("9. thoat\n");
		printf("=========================================================\n");
		printf("nhap lua chon:");
		scanf("%d",&choice);
		
		switch(choice){
			case 1://nhap so phan tu va gia tri 
				printf("nhap so phan tu cua mang:");
				scanf("%d",&size);
				while(size<0||size>100){
					printf("loi vui long nhap lai!!");
				}
				for(i=0;i<size;i++){
					printf("nhap gia tri arr[%d]:",i);
					scanf("%d",&arr[i]);
				}
				break;
			
			case 2://in gia tri cac phan tu cua mang
				if(size==0){
					printf("mang rong");
				}else{
					for(i=0;i<size;i++){
						printf(" %d |",arr[i]);
					}
				}
				break;
				
			case 3://tong trung binh cong
				if(size==0){
					printf("mang rong\n");
					break;
				}else{
					int sum=0;
					for(i=0;i<size;i++){
						sum+=arr[i];
					}
					printf("tong=%d\n",sum);
					printf("trung bing cong=%.2f\n",(float)sum/size);
				}
				break;
			
			case 4://sap sep giam dan selection sort
				if(size==0){
					printf("mang rong\n");
					break;
				}else{
					int maxIndex,temp;
					for(i=0;i<size-1;i++){
						maxIndex=i;
						for(j=i+1;j<size;j++){
							if(arr[j]>arr[maxIndex]){
								maxIndex=j;
							}	
						}
						temp=arr[i];
						arr[i]=arr[maxIndex];
						arr[maxIndex]=temp;
					}
					printf("gia tri da duoc sap sep giam dan\n");	
				}
				break;
				
				
				
				case 4://sap sep bubble sort
				if(size==0){
					printf("mang rong!!");
				}else{
					for(i=0 ; i<size-1 ; i++){
						for(j=0 ; j < size - i- 1 ; j++){
							if(arr[j] > arr[j + 1]){
								int temp = arr[j];
								arr[j] = arr[j + 1];
								arr[j + 1] = temp;
							}
						}
					}
					printf("mang da duoc sap sep");
				}
				break;	
				
				
				
				
				
				
	case 4: // Sap xep mang tang dan theo Insertion Sort
    if(size == 0){
        printf("Mang rong!\n");
    } else {
        int key;
        for(i = 1; i < size; i++){
            key = arr[i];
            j = i - 1;

            while(j >= 0 && arr[j] > key){
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = key;
        }

        printf("Mang da duoc sap xep tang dan (Insertion Sort):\n");
        for(i = 0; i < size; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    break;

				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
			case 5://tim kiem theo thuat toan binary seach
	    	  	if(size==0){
					printf("mang rong\n");
					break;
				}else{
					int left=0,right=size-1,mid,found=0;
					printf("nhap gia tri can tim trong mang:");
					scanf("%d",&value);
					while(left<=right){
						mid=(left+right)/2;
						if(arr[mid] == value){
							printf("tim thay gia tri %d tai vi tri arr[%d]\n",value,mid);
			                found=1;
			                break;
						}
						else if(arr[mid] < value){
							right = mid - 1;
						}else{
							left = mid+1;
						}
					}
					if(!found){
						printf("khong tim thay phan tu!!\n");
					}					
				}
				break;
				
				case 5://linear seach
				if(size==0){
					printf("mang rong!!");
				}else{
					int value,found=0;
					printf("nhap gai tri can tim:");
					scanf("%d",&value);
					for(i=0 ; i<size ; i++){
						if(arr[i]==value){
							printf("tim thay gia tri %d tai arr[%d]",value,i);
							found=1;
						}
					}
					if(!found){
						printf("khong tim thay phan tu");
					}
				}
				break;
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
			case 6://xoa phan tu theo chi so
				if(size==0){
				printf("mang rong\n");
				break;
				}else{
					int index;
					printf("nhap chi so muon xoa trong mang:");
					scanf("%d",&index);
					if(index<0||index>=size){
						printf("chi so khong hop le!!\n");
					}else{
						for(i=index;i<size-1;i++){
							arr[i]=arr[i+1];
							size--;
						}
						printf("da xoa phan tu tai arr[%d]",index);
					}
				}
				break;
			case 7://chen gia tri bat ky vao chi so trong mang
				if(size>=100){
				printf("mang da day!!\n");
				}else{
					printf("nhap chi so muon chen: ");
					scanf("%d",&index);
					printf("nhap gia tri muon chen: ");
					scanf("%d",&value);
					if(index<0||index>size){
						printf("chi so khong hop le!!\n");
					}else{
						for(i=size;i>index;i--){
							arr[i]=arr[i-1];
							arr[index]=value;
							size++;
							printf("da chen gia tri %d vao arr[%d].\n",value,index);
						}
					}
				}
				break;
				
			case 8://xoa tat ca phan tu co gia tri nhap tu ban phim
				if(size==0){
				printf("mang rong\n");
				}else{
					printf("nhap gia tri can xoa: ");
					scanf("%d",&value);
					int count=0;
					for(i=0;i<size;i++){
						if(arr[i]==value){
							for(j=i;j<size-1;j++){
								arr[j]=arr[j+1];
								size--;
								i--;
								count++;
							}
						}
					}
					if(count==0){
						printf("khong co phan tu nao co gia tri %d",value);
					}else{
						printf("da xoa %d co gia tri %d trong mang\n",count,value);
					}
				}
				break;
			case 9:
				printf("thoat chuong trinh. ");
				
			default:
				printf("lua chon khong hop le!!\n");
		}
	}while(choice!=9);
	return 0;
}
