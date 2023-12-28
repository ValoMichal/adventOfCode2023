#include <stdio.h>
#include <string.h>
#define size 50
int main(void){
	FILE *input;
	input=fopen("input.txt","r");
	char num1,num2;
	char signal[size]="";
	int num,sum = 0;
	int j=0;//debug
	while(fgets(signal,size,input)){
		num1='a';
		for(int i = 0; i<strlen(signal); i++){
			if(signal[i]>='0'&&signal[i]<='9'){
				if(num1=='a'){
					num1=signal[i];
				}
				num2=signal[i];
			}
		}
		num = ((int)num1-48)*10 + (int)num2-48;
		
		if(j<10){//debug
			printf("%d ",num);//debug
			printf("%s",signal);//debug
		}//debug
		j++;//debug
		sum +=num;
	}
	printf("%d\n",sum);
}
