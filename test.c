#include <stdio.h>
int main(void){
	FILE *file;
	file=fopen("test.txt","r");
	char string[10];
	char num;
	int number;
	while(fgets(string,10,file)){
		for(int i = 0; i<10; i++){
			if(string[i]>='0'&&string[i]<='9'){
				num=string[i];
			}
		}
	}
	number=(int)num-48;
	printf("%d\n",number);
	printf("%d\n",((int)'1'-48)*10+(int)'2'-48);
}
