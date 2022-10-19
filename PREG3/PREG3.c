#include "omp.h"
#include "stdio.h"
#include "string.h"

#define TAM 40
         
char palindrome[TAM];
int i, c, cont = 0;
         
int main(){
    	printf("\nIntroduzca palabra a verificar si es palindromo: ");
    	scanf("%s",palindrome);
    	c=strlen(palindrome);

	{
		int nh = omp_get_thread_num();
            	if(nh != 0){
            		printf("\nHilo %d : ", nh);
          	}
            	
		for(i = c - 1 ; i >= 0 ; i--)

		{
			if(palindrome[i] == palindrome[cont])
				cont++;
		}

		{
			if(nh == 0){
				if(cont == c){					
					printf("\nPalabra palindrome: Verdadero");					
				}else{
					printf("\nPalabra palindrome: Falso");					
				}
			}
		}
	}
	printf("\n");
	return 0;
}
