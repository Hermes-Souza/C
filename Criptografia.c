/*Este programa criptrografa uma string de 256 caracteres usando um tabela de 26 caracteres*/
# include <stdio.h>
# include <ctype.h>
# include <string.h>
# define TABELA	27
# define FRASE 257

int main(){
	char t[TABELA]={'\0'};
	char f[FRASE]={'\0'};
	int i=0, j=0, k=0;
	char c='\0';
	printf("Entre com a tabela: ");
	fgets(t, TABELA, stdin);
	for(i=0; i<strlen(t); i++){
		t[i]= tolower(t[i]);
	}
	if(strlen(t)==TABELA-1 && t[strlen(t)-1]!='\n'){
		do{
			c= getchar();
		}while(c!='\n');
	}
	printf("Entre com a frase a ser criptrografada: ");
	fgets(f, FRASE, stdin);
	if(f[strlen(f)-1]=='\n'){
		f[strlen(f)-1]='\0';
	}
	for(i=0; i<strlen(f); i++){
		if(f[i]<65 || (f[i]>90 && f[i]<97) || f[i]>122){
			
		}else{
			if(f[i]>=65 && f[i]<=90){
				j=65;
				k=-32;
			}else{
				j=97;
				k=0;
			}
			if(t[f[i]%j]<65 || (t[f[i]%j]>=90 && t[f[i]%j]<97)  || t[f[i]%j]>122){
				f[i]=t[f[i]%j];
			}else{
				f[i]=t[f[i]%j]+k;
			}
		}
	}
	printf("Frase criptografada: %s", f);
	return 0;
}