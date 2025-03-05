#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct customer
{
	char cust_name[20];
	int age;
	char gender[10];
	long long int number;
	int expenses;
};
struct fertilizer
{
	char ferti_name[20];
	char box[20];
	int quantity;
	int mdate;
	int edate;
	int price;
};
void updater();
void deleter();
void sorter();
void update();
void see();
void search();
void display();
void design();
void billdesign();
void edit();
void bill_updater();
int nummed=0,ash=0,count=0;
int i,n,j;
struct fertilizer med[100];
struct fertilizer bill[20];
struct customer cust[100];
FILE *f1;
main()
{
	char ch;
	f1=fopen("fertilizers.txt","r");
	for(i=0;fscanf(f1,"%s%s%d%d%d%d",med[i].ferti_name,med[i].box,&med[i].quantity,&med[i].mdate,&med[i].edate,&med[i].price)!=EOF;i++);
	nummed=i;
	fclose(f1);
	f1=fopen("C:/editor/medicalbill.txt","r");
	for(i=0;fscanf(f1,"%s%s%d%lld%d",cust[i].cust_name,cust[i].gender,&cust[i].age,&cust[i].number,&cust[i].expenses)!=EOF;i++);
	count=i;
	fclose(f1);
	goto hero;
	start: printf("\n\t\t\t\t\tEnter anything to start -> ");
	scanf("%c",&ch);
	system("cls");
	hero:
	design();
	printf("\n\n\n\t\t\t\t\t List of options");
	printf("\n\t\t\t\t\t1.add new Fertilizer\n\t\t\t\t\t2.see Fertilizers list\n\t\t\t\t\t3.search customer's Fertilizer");
	printf("\n\t\t\t\t\t4.print bill\n\t\t\t\t\t5.delete\n\t\t\t\t\t6.sort by expiry date");
	printf("\n\t\t\t\t\t7.edit any Fertilizer details\n\t\t\t\t\t8.Exit\n");
	printf("\n\n\n\t\t\t\t\tEnter the option :  ");
	n=9;
	scanf("%d",&n);
	system("cls");
	design();
	switch(n)
	{
		case 1:update();
		break;
		case 2:see();
		break;
		case 3:search();
		break;
		case 4:display();
		break;
		case 5:deleter();
		break;
		case 6:sorter();
		break;
		case 7:edit();
		break;
		case 8:
		goto end;
		break;
		default:printf("\n\t\t\t\t\tEnter proper option");
		goto star;
	}
	printf("\n\n\t\t\t\t\t Enter anything to continue -> ");
	getch();
	star:
	goto start;
end: printf("\t\t\t\t\tTask has completed........\n\n\n\n\n\n\n\n\n\n");
updater();
bill_updater();
}
void update()
{
		printf("\n\t\t\t\t\t\tENTER  FERTILIZER  DETAILS\n");
		printf("\t\t\t\t\tEnter fertilizer name:  ");
		scanf("%s",med[nummed].ferti_name);
		
		printf("\t\t\t\t\tEnter fertilizer box:  ");
		scanf("%s",med[nummed].box);
		
		printf("\t\t\t\t\tEnter fertilizer quantity: ");
		scanf("%d",&med[nummed].quantity);
		
		printf("\t\t\t\t\tEnter fertilizer manufacturing date:  ");
		scanf("%d",&med[nummed].mdate);
		
		printf("\t\t\t\t\tEnter fertilizer expiry date: ");
		scanf("%d",&med[nummed].edate);
		
		printf("\t\t\t\t\tEnter fertilizer price:  ");
		scanf("%d",&med[nummed].price);
		
		nummed++;
	printf("\t\t\t\t\tFertilizer added sucessfully");
	updater();
}
void see()
{
	printf("\t\t\t\t\tFertilizers available in our store:");
	printf("\n\t\t\t\t\t");
	for(j=0;j<83;j++)
			printf("-");
	printf("\n\t\t\t\t\t|%-5s|%-20s|%-5s|%-8s|%-10s|%-10s|%-6s|\n","s.no.","Fertilizer_name","box","quantity","Mfg date","exp date","price");
	for(i=0;i<nummed;i++)
	{
		printf("\t\t\t\t\t");
		for(j=0;j<83;j++)
			printf("-");
		printf("\n\t\t\t\t\t|%-5d|%-20s|%-5s|%-8d|%4d-%-5d|%4d-%-5d|%-6d|\n",i+1,med[i].ferti_name,med[i].box,med[i].quantity,med[i].mdate/100,med[i].mdate%100,med[i].edate/100,med[i].edate%100,med[i].price);
	}
	printf("\t\t\t\t\t");
	for(j=0;j<83;j++)
			printf("-");
}
void search()
{
	printf("\n\t\t\t\t\tENTER THE CUSTOMER DETAILS :\n\n ");
	printf("\n\t\t\t\t\tNAME : ");
	scanf("%s",cust[count].cust_name);
	printf("\n\t\t\t\t\tAGE : ");
	scanf("%d",&cust[count].age);
	printf("\n\t\t\t\t\tCONTACT NO : ");
	scanf("%lld",&cust[count].number);
	printf("\n\t\t\t\t\tGENDER(M/F) : ");
	scanf(" %s",cust[count].gender);
	printf("\n\t\t\t\t\tEnter the Fertilizers Customer required\n\n");
	char b[20];
	int ch;
	int flag=0,k=9,p=0,x,bil=-0,lil=-0;
	do{
	p=0;
	printf("\t\t\t\t\tEnter the Fertilizer name : ");
	scanf("%s",b);
	for(i=0;i<ash;i++)
	{
		if(strcmp(bill[i].ferti_name,b)==0)
		{
			bil=i;
			for(j=0;j<nummed;j++)
			{
				if(strcmp(med[j].ferti_name,b)==0)
				{
				lil=j;
				break;
				}
			}
			p=1;
			break;
		}
	}
	if(p==1)
	{	
		printf("\t\t\t\t\tEnter quantity to update  : ");
		scanf("%d",&x);
		bill[bil].quantity+=x;
		med[lil].quantity=med[lil].quantity-x;
		bill[bil].price=med[lil].price*bill[bil].quantity;
	}
	else
	{
	flag=0;
	for(i=0;i<nummed;i++)
	{
		k=5;
		k=strcmp(b,med[i].ferti_name);
		if(k==0)
		{
			bill[ash]=med[i];
			printf("\t\t\t\t\tEnter quantity : ");
			scanf("%d",&bill[ash].quantity);
			med[i].quantity=med[i].quantity-bill[ash].quantity;
			bill[ash].price=bill[ash].price*bill[ash].quantity;
			ash++;
			flag=2;
			break;
		}
	}
	if(flag!=2)
	printf("\n\t\t\t\t\t Fertilizer not available\n");
	}
	printf("\n\n\t\t\t\t\tEnter 1 to add another fertilizer");
	scanf("%d",&ch);
	}while(ch==1);
}
void display()
{
	system("cls");
	billdesign();
	printf("\n\t\t\t\t\tCUSTOMER DETAILS  :\n");
	printf("\n\t\t\t\t\tNAME : %s",cust[count].cust_name);
	printf("\t\t\t\tGENDER : %s",cust[count].gender);
	printf("\n\n\t\t\t\t\tAGE : %d",cust[count].age);
	printf("\t\t\t\tCONTACT NO : %lld",cust[count].number);
	printf("\n\n\n\t\t\t\t\tTHE BILL :\n");
	cust[count].expenses=0;
	printf("\n\t\t\t\t");
	for(j=0;j<93;j++)
			printf("-");
	printf("\n\t\t\t\t|%-5s|%-20s|%-8s|%-10s|%-10s|%-15s|%-10s|%-6s|\n","s.no.","Fertilizer_name","quantity","Mfg date","exp date","Taxable Amount","CGST-18%","price");
	for(i=0;i<ash;i++)
	{
		printf("\t\t\t\t");
		for(j=0;j<93;j++)
			printf("-");
		printf("\n\t\t\t\t|%-5d|%-20s|%-8d|%4d-%-5d|%4d-%-5d|%-15.2f|%-10.2f|%-6d|\n",i+1,bill[i].ferti_name,bill[i].quantity,bill[i].mdate/100,bill[i].mdate%100,bill[i].edate/100,bill[i].edate%100,(float)((float)bill[i].price-(float)bill[i].price/100.0*18),(float)bill[i].price/100*18,bill[i].price);
	}
	printf("\t\t\t\t");
	for(j=0;j<93;j++)
			printf("-");
	for(j=0;j<3;j++)
		cust[count].expenses+=bill[j].price;
	printf("\n\n\t\t\t\t\t\t\t\t\t\t\t\t\tTOTAL PRICE:%6d",cust[count].expenses);
	count++;
}
void updater()
{
	f1=fopen("fertilizers.txt","w+");
	for(i=0;i<nummed;i++)
	{
	fprintf(f1,"%-15s\t%-15s\t%-10d\t%-10d\t%-10d\t%-10d\n",med[i].ferti_name,med[i].box,med[i].quantity,med[i].mdate,med[i].edate,med[i].price);
	}
	fclose(f1);
}
void deleter()
{
	char b[10];
	int check=0;
	printf("\t\t\t\t\tHere is a list of Fertilizers in our store\n\t\t\t\t\t");
	for(i=0;i<nummed;i++)
	{
		printf("%-20s\t",med[i].ferti_name);
		if(i%4==0)
		printf("\n\t\t\t\t\t");
	}
	printf("\n\n\n\t\t\t\t\tEnter the fertilizer to delete: ");
	scanf("%s",b);
	for(i=0;i<nummed;i++)
	{
		if(strcmp(med[i].ferti_name,b)==0)
		{
			for(j=i;j<nummed;j++)
			{
				med[j]=med[j+1];
			}
			nummed--;
			check=1;
			printf("\n\t\t\t\t\tFertilizer sucessfully deleted");
			break;
		}
	}
	if(check==0)
	{
		printf("\n\t\t\t\t\tFertilizer not available in our store");
	}
}
void sorter()
{
	struct fertilizer tab;
	int m,y,x[nummed],p;
	for(i=0;i<nummed;i++)
	{
		y=med[i].edate%100;
		m=med[i].edate/100;
		x[i]=y*100+m;
	}
	for(i=0;i<nummed;i++)
	{
		for(j=i+1;j<nummed;j++)
		{
			if(x[i]>x[j])
			{
				p = x[i];
				tab=med[i];
				x[i] = x[j];
				med[i]=med[j];
				x[j] = p;
				med[j]=tab;
			}
		}
	}
	printf("\n");
	see();
}
 void design()
{
	printf("\t\t\t\t\t|========================================================================|\n");
	printf("\t\t\t\t\t|                                                                        |\n");
	printf("\t\t\t\t\t|                    ----------------------------------                  |\n");
	printf("\t\t\t\t\t|                       FERTILIZER BILLING SYSTEM                        |\n");
	printf("\t\t\t\t\t|                    ----------------------------------                  |\n");
	printf("\t\t\t\t\t|                                                                        |\n");
	printf("\t\t\t\t\t|========================================================================|\n\n\n");
}
void edit()
{
	char b[20];
	int p=0;
	printf("\t\t\t\t\tHere is a list of Fertilizers in our store\n\t\t\t\t\t");
	for(i=0;i<nummed;i++)
	{
		printf("%-20s\t",med[i].ferti_name);
		if(i%4==0)
		printf("\n\t\t\t\t\t");
	}
	printf("\n\n\t\t\t\t\tEnter the Fertilizer name to edit : ");
	scanf("%s",b);
	for(i=0;i<nummed;i++)
	{
		if(strcmp(med[i].ferti_name,b)==0)
		{
		printf("\t\t\t\t\tEnter the updates\n");
		printf("\t\t\t\t\tEnter Fertilizer name:  ");
		scanf("%s",med[i].ferti_name);
		
		printf("\t\t\t\t\tEnter Fertilizer box:  ");
		scanf("%s",med[i].box);
		
		printf("\t\t\t\t\tEnter Fertilizer quantity: ");
		scanf("%d",&med[i].quantity);
		
		printf("\t\t\t\t\tEnter Fertilizer manufacturing date:  ");
		scanf("%d",&med[i].mdate);
		
		printf("\t\t\t\t\tEnter Fertilizer expiry date: ");
		scanf("%d",&med[i].edate);
		
		printf("\t\t\t\t\tEnter Fertilizer price:  ");
		scanf("%d",&med[i].price);
		p=1;
		break;
		}
	}
	if(p==0)
	printf("\n\t\t\t\t\tFertilizer not available in our store");
}
void billdesign()
{
	printf("\t\t\t\t|=========================================================================================|\n");
	printf("\t\t\t\t|                                                                                         |\n");
	printf("\t\t\t\t|                            ----------------------------------                           |\n");
	printf("\t\t\t\t|                               FERTILIZER BILL RECIEPT                                   |\n");
	printf("\t\t\t\t|                            ----------------------------------                           |\n");
	printf("\t\t\t\t|                                                                                         |\n");
	printf("\t\t\t\t|=========================================================================================|\n\n\n");
}
void bill_updater()
{
	f1=fopen("C:/editor/medicalbill.txt","w");
	for(i=0;i<count;i++)
	fprintf(f1,"%-20s\t%-5s\t%-5d\t%-15lld\t%-10d\n",cust[i].cust_name,cust[i].gender,cust[i].age,cust[i].number,cust[i].expenses);
	fclose(f1);
}