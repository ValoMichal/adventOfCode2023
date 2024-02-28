#include <stdio.h>
#include <string.h>
#define size 256
int main(void){
	int red,green,blue,num,sum=0;
	FILE *input;
	input=fopen("input.txt","r");
	char signal[size]="";
	int j=0;//debug
	while(fgets(signal,size,input)){
		red=1;
		green=1;
		blue=1;
		for(int i = strlen(signal); i>0; i--){
			if(signal[i]==' '){
				if(signal[i+1]=='r'){
					num=(int)signal[i-1]-48;
					if(signal[i-2]!=' '){
						num+=((int)signal[i-2]-48)*10;
					}
					if(num>red){
						red=num;	
					}
				}else if(signal[i+1]=='g'){
					num=(int)signal[i-1]-48;
					if(signal[i-2]!=' '){
						num+=((int)signal[i-2]-48)*10;
					}
					if(num>green){
						green=num;
					}
				}else if(signal[i+1]=='b'){
					num=(int)signal[i-1]-48;
					if(signal[i-2]!=' '){
						num+=((int)signal[i-2]-48)*10;
					}
					if(num>blue){
						blue=num;
					}
				}
			}
		}
		num=red*green*blue;
		sum+=num;
		
		if(j>90){//debug
			printf("%d %d ",sum,num);//debug
			printf("%s",signal);//debug
		}//debug
		j++;//debug
	}
	printf("%d\n",sum);
}
