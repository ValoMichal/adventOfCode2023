#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 255
int main(void){
	FILE *input;
	input=fopen("input.txt","r");
	int sum=0,boundary=0;
	char num[5]="0",prev[size]="",signal[size]="";
	int j=0;//debug
	fgets(signal,size,input);
	fgets(prev,size,input);
	while(fgets(signal,size,input)){
		for(int i=1;i<strlen(signal)-1;i++){
			if(prev[i]!='.'&&(prev[i]<'0'||prev[i]>'9')&&((signal[i-1]>='0'&&signal[i-1]<='9')||(signal[i]>='0'&&signal[i]<='9')||(signal[i+1]>='0'&&signal[i+1]<='9'))){//check numbers above
				int j=-3;
				while((i+j)<0){
					j++;
				}
				while((i+3-boundary)>(strlen(signal))){//first line being ignored
					boundary++;
				}
				for(;j<=3-boundary;j++){
					if(signal[i+j]>='0'&&signal[i+j]<='9'){
						strncat(num,&signal[i+j],1);
					}else if(j==-1){
						strcpy(num,"0");
					}else if(j==0){
						sum+=atoi(num);
						strcpy(num,"0");
					}else if(j>0){
						sum+=atoi(num);
						strcpy(num,"0");
						break;
					}
					
				}
				boundary=0;
				sum+=atoi(num);
				strcpy(num,"0");
			}
			if(signal[i]!='.'&&(signal[i]<'0'||signal[i]>'9')&&((prev[i-1]>='0'&&prev[i-1]<='9')||(prev[i]>='0'&&prev[i]<='9')||(prev[i+1]>='0'&&prev[i+1]<='9'))){//check numbers bellow
				int j=-3;
				while((i+j)<0){
					j++;
				}
				while((i+3-boundary)>(strlen(signal))){
					boundary++;
				}
					if(prev[i+j]>='0'&&prev[i+j]<='9'){
						strncat(num,&prev[i+j],1);
					}else if(j==-1){
						strcpy(num,"0");
					}else if(j==0){
						sum+=atoi(num);
						strcpy(num,"0");
					}else if(j>0){
						sum+=atoi(num);
						strcpy(num,"0");
						break;
					}
				}
				boundary=0;
				sum+=atoi(num);
				strcpy(num,"0");
			}
			if(signal[i]!='.'&&(signal[i]<'0'||signal[i]>'9')&&(signal[i-1]>='0'&&signal[i-1]<='9')){//check numbers on left
				int j=-3;
				while((i+j)<0){
					j++;
				}
					if(signal[i+j]>='0'&&signal[i+j]<='9'){
						strncat(num,&signal[i+j],1);
					}else{
						strcpy(num,"0");
					}
				}
				sum+=atoi(num);
				strcpy(num,"0");
			}
			if(signal[i]!='.'&&(signal[i]<'0'||signal[i]>'9')&&(signal[i+1]>='0'&&signal[i+1]<='9')){//check numbers on right
				int j=1;
				while((i+3-boundary)>(strlen(signal))){
					boundary++;
				}
				for(int j=1;j<=3-boundary;j++){
					if(signal[i+j]>='0'&&signal[i+j]<='9'){
						strncat(num,&signal[i+j],1);
					}else{
						sum+=atoi(num);
						strcpy(num,"0");
						break;
					}
				}
				boundary=0;
				sum+=atoi(num);
				strcpy(num,"0");
			}
		}
		strcpy(prev,signal);//copy old line before getting new line

		if(j<100){//debug
			printf("%d ",sum);//debug
			printf("%s",signal);//debug
		}//debug
		j++;//debug
	}
	printf("%d\n",sum);
}
//first line, find symbols. check if number above line. check if numbers on line. read new line. first line (now second) check if numbers above. repeat
//read first line outside loop, then override inside loop every time before reading new line
//
//get lower line and start loop of reading upper line, matching numbers from upper to lower, from lower to upper and from lower to lower line and then move upper line to lower line and repeat
