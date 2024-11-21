#include <stdio.h>
#include <stdlib.h>

void imprime_histograma(char* his[], int vendas[], int qtd_categ);
void preenche(char* his[], int tam_venda, int categoria);

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
            
            preenche(histograma, vendas[i], i);
            
    }

    if(qtd_categ == 0){
        printf("vazio");
    }
    else{
        imprime_histograma(histograma, vendas, qtd_categ);
    }
    
    
    for(int i = 0; i < qtd_categ; i++){
       free(histograma[i]);
    }
}

void preenche(char* his[], int tam_venda, int categoria){
    
    for(int j = 0; j< tam_venda; j++){
        his[categoria][j] = '*'; 
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
