#include <stdio.h>
#include <stdlib.h>

void imprime_histograma(char* his[], int vendas[], int qtd_categ);

void main(){

    int qtd_categ; // quantidade de categorias
    scanf("%d", &qtd_categ);
    
    int vendas[qtd_categ]; //valor das vendas em cada categoria
    char* histograma[qtd_categ]; // vetor com os ponteiros para char
    
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
    
    imprime_histograma(histograma, vendas, qtd_categ);
    
    for(int i = 0; i < qtd_categ; i++){
       free(histograma[i]);
    }
}

void imprime_histograma(char* his[], int vendas[], int qtd_categ){
    
    for(int i = 0; i < qtd_categ; i++){
        
       if(vendas[i] == 0){
        printf("0\n");
       }
       else{
           printf("%d ", vendas[i]);
           for(int j = 0; j < vendas[i]; j++){
                printf("%c", his[i][j]);
           }
           printf("\n");
       }
    }
    
    
}
