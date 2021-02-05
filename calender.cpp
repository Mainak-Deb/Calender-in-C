#include<stdio.h>
#include<conio.h>
void calender_print(int y){
	int cal[12][42],i=0,mn,wk,j,l,k=1,m=11,d=(y%100)-1,c=y/100,f,x;
	char month[12][20]={"January   ","February  ","March     ","April     ","May       ","June      ","July      ","August    ","September ","October   ","November  ","December  "};
	char day[7][4]={"Mo","Tu","we","Th","Fr","Sa","Su"};
	int md[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	f=k+ ((13*m-1)/5) +d+ (d/4)+(c/4)-(2*c) ;
	f=f%7;
	f=(f+6)%7;
	if(y%100==0){if(y%400==0) md[1]++;}
	else if(y%4==0) md[1]++;
	for(i=0;i<12;i++){
		k=1;
		for(j=0;j<42;j++){
		
			if((j>=f)&&((j-f+1)<=md[i])){cal[i][j]=k;k++;
			} 
			else cal[i][j]=0;
		}
		f=(f+(md[i]-28))%7;
	}printf("\n\n");
	for(l=0;l<78;l++) printf("_");printf("\n");
	printf("                                    %d\n",y);
	for(l=0;l<78;l++) printf("_");printf("\n\n");
	for(i=0;i<4;i++){
		for(mn=0;mn<3;mn++) printf("       %s           ",month[(i*3)+mn]);printf("\n");
		for(wk=0;wk<21;wk++) {printf(" %s",day[(wk%7)]);if((wk%7)==6) printf("  |   ");}printf("\n");		
		for(j=0;j<6;j++){
			for(k=0;k<3;k++){
				for(l=0;l<7;l++){
					x=cal[(i*3)+k][(j*7)+l];
					if(x==0) printf("   ");
					else{if(x<10) printf("  %d",x);
						else  printf(" %d",x);	}											
				}printf("  |   ")	;			
			}printf("\n");			
		}
		for(l=0;l<78;l++) printf("_");printf("\n");
	}	
}
int main(){
	int y;
	printf("Enter the year= ");
	scanf("%d",&y);
	calender_print(y);
	getch();
	return 0;
}
