#include <stdio.h>
#include <stdlib.h>

int main(){

    int qtd_categ; // quantidade de categorias
    scanf("%d", &qtd_categ);
    
    int vendas[qtd_categ]; //valor das vendas em cada categoria
    char* histograma[qtd_categ]; // vetor com os ponteiros
    
    for(int i = 0; i < qtd_categ; i++){
        
        scanf(" %d", &vendas[i]);
        
        if(vendas[i] == 0)
            histograma[i] = NULL;
        else
            histograma[i] = (char*) malloc(vendas[i] * sizeof(char));
            
            for(int j = 0; j < vendas[i]; j++){
                histograma[i][j] = '*';
            }
        
    }
    
    for(int i = 0; i < qtd_categ; i++){
        
       if(vendas[i] == 0){
        printf("0\n");
       }
       else{
           printf("%d ", vendas[i]);
           for(int j = 0; j < vendas[i]; j++){
                printf("%c", histograma[i][j]);
           }
           printf("\n");
       }
    }
    
    for(int i = 0; i < qtd_categ; i++){
       free(histograma[i]);
    }
    
    return 0;
}
