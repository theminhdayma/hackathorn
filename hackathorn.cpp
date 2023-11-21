#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int n,m;
	printf("Nhap so hang:");
	scanf("%d",&n);
	printf("Nhap so cot:");
	scanf("%d",&m);
	int numbers[n][m];
	int count;
	int max,min;
	int sumNumbers;
	int isPrime;
	int number,temp; 
	int key,a;
	do{
		printf("************MENU************\n");
		printf("1.Nhap gia tri cac phan tu cua mang\n");
		printf("2.In gia tri cac phan tu trong mang theo ma tran\n");
		printf("3.Tinh so luong cac phan tu le chia het cho 5 trong mang\n");
		printf("4.In ra cac phan tu co gi tri lon nhat, nho nhat nam tren duong bien, duong cheo chinh,duong cheo phu\n");
		printf("5.Su dung cac thuat toan sap xep lua chon sap xep cac phan tu giam dan trong mang\n");
		printf("6.Tinh tong cac phan tu la so nguyen to trong mang\n");
		printf("7.Su dung thuat toan chen sap xep cac phan tu tren duong cheo phu cua mang tang dan\n");
		printf("8.Nhap gia tri 1 mang 1 chieu gom n phan tu va chi so cot muon chen vao mang, thuc hien chen vao mang 2 chieu\n");
		printf("9.Thoat\n");
		int choice;
		printf("Moi ban chon: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Nhap vao gia tri choa cac phan tu: \n");
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++){
						printf("numbers[%d][%d]= ",i,j);
						scanf("%d",&numbers[i][j]);
					}
				}
				break;
			case 2:
				printf("Cac gia tri co trong mang la: \n");
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++){
						printf("\t%d",numbers[i][j]);
					}
					printf("\n");
				}
				break;
			case 3:
				count=0;
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++){
						if(numbers[i][j]%2==1 && numbers[i][j]%5==0){
							count++;
						}
					}
				}
				printf("\nCo %d gia tri trong mang la so le chia het cho 5\n",count);
				break;
			case 4:
				max=numbers[0][0];
				min=numbers[0][0];
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++){						
						if(i==0||i==n-1||j==0||j==m-1){							
							if(max<numbers[i][j]){
								max=numbers[i][j];
							}
							if(min>numbers[i][j]){
								min=numbers[i][j];
							}
						}
					}
				}
				printf("Gia tri lon nhat tren duong bien la: %d\n",max);
				printf("Gia tri nho nhat tren duong bien la: %d\n",min);
				max=numbers[0][n-1];
				min=numbers[0][n-1];
				if(n==m){
					for(int i=0;i<n;i++){
						for(int j=0;j<m;j++){
							if(i==j){								
								if(max<numbers[i][j]){
									max=numbers[i][j];
								}
								if(min>numbers[i][j]){
									min=numbers[i][j];
								}								
							}
						}
					}
					printf("Gia tri lon nhat tren duong chao chinh la: %d\n",max);
					printf("Gia tri nho nhat tren duong chao chinh la: %d\n",min);
					max=numbers[0][m-1];
					min=numbers[0][m-1];
					for(int i=0;i<n;i++){
						for(int j=0;j<m;j++){
							if(i+j==n-1){
								if(max<numbers[i][j]){
									max=numbers[i][j];
								}
								if(min>numbers[i][j]){
									min=numbers[i][j];
								}
							}
						}
					}
					printf("Gia tri lon nhat tren duong chao phu la: %d\n",max);
					printf("Gia tri nho nhat tren duong chao phu la: %d\n",min);
				}else{
					printf("Khong co duong cheo chinh va duong cheo phu\n");
				}
				break;
			case 5:
				// Sap xep lua chon(giam dan)
                for(int i=0;i<n;i++){
        			for(int j=0;j<m-1;j++){
            			number=j;
            			for(int k=j+1;k<m;k++){
                			if(numbers[i][k]>numbers[i][number]){
                    			number=k;
                			}
            			}
            			temp=numbers[i][number];
            			numbers[i][number]=numbers[i][j];
            			numbers[i][j]=temp;
        			}
    			}
				break;
			case 6:
				sumNumbers=0;
				for(int i=0;i<n;i++){
					for(int j=0;j<m;j++){
						isPrime=0;
						if(numbers[i][j]>=2){
							for(int k=2;k<=sqrt(numbers[i][j]);k++){
								if(numbers[i][j]%k==0){
									isPrime=1;
									break;
								}
							}
						}else{
							isPrime=1;
						}
						if(isPrime==0){
							sumNumbers+=numbers[i][j];
						}
					}
				}
				printf("Tong cac so nguyen to trong mang la: %d\n",sumNumbers);
				break;
			case 7:
				//Sap xep tang dan(chen)
				for(int i=0;i<n;i++){
        			for(int j=0;j<m;j++){
            			if(i+j==n-1){
                			key=numbers[i][j];
                			a=i+j;
                			while(a>0&&key<numbers[a-1][n-1-(a-1)]){
                    			numbers[a][n-1-a]=numbers[a-1][n-1-(a-1)];
                    			a--;
                			}
                			numbers[a][n-1-a]=key;
            			}
        			}
   				}
                break;
			case 8:				
				break;
			case 9:
				printf("Ket thuc chuong trinh");
				exit(0);
			default:
				printf("Khong hop le. Vui long chon tu 1-9");
		}
	}while(1==1);
}
