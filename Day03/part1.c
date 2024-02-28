#include <stdio.h>
#include <string.h>
#define size 256
int main(void){
	int red = 12;
	int green = 13;
	int blue = 14;
	FILE *input;
	input=fopen("input.txt","r");
	int num,sum=0;
	char signal[size]="";
	int j=0;//debug
	while(fgets(signal,size,input)){
		num=-1;
		for(int i = strlen(signal); i>0; i--){
			if(i<8){
				num=-1;
				if(signal[7]!=':'&&signal[7]!=' '){
					num=(int)signal[7]-48;
				}
				if(signal[6]!=':'&&signal[6]!=' '){
					if(num!=-1){
						num+=((int)signal[6]-48)*10;
					}else{
						num=(int)signal[6]-48;
					}
				}
				if(num==-1){
					num=(int)signal[5]-48;
				}else if(signal[7]!=':'&&signal[7]!=' '){
					num+=((int)signal[5]-48)*100;
				}else{
					num+=((int)signal[5]-48)*10;
				}
			}else if(signal[i]==' '){
				if(signal[i+1]=='r'){
					num=(int)signal[i-1]-48;
					if(signal[i-2]!=' '){
						num+=((int)signal[i-2]-48)*10;
					}
					if(num>red){
						num=0;
						break;	
					}
				}else if(signal[i+1]=='g'){
					num=(int)signal[i-1]-48;
					if(signal[i-2]!=' '){
						num+=((int)signal[i-2]-48)*10;
					}
					if(num>green){
						num=0;
						break;
					}
				}else if(signal[i+1]=='b'){
					num=(int)signal[i-1]-48;
					if(signal[i-2]!=' '){
						num+=((int)signal[i-2]-48)*10;
					}
					if(num>blue){
						num=0;
						break;
					}
				}
			}
		}
		sum+=num;
		
		if(j>90){//debug
			printf("%d %d ",sum,num);//debug
			printf("%s",signal);//debug
		}//debug
		j++;//debug
	}
	printf("%d\n",sum);
}
