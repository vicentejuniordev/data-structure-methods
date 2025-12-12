#include <stdio.h>
#include <string.h>

// Definindo a estrutura
typedef struct{
    char titulo[50];
    char genero[20];
    int anoLancamento;
}Jogo;

// Definindo a constante para o tamanho maximo do array
#define MAX 5
int qtd = 0; // Variavel para controlar a quantidade de jogos no array

// Declarando o array de jogos
 Jogo jogos[MAX];


// Método para adicionar um novo Jogo | Estrutura Fila
void adicionarJogoFila(Jogo novoJogo){
    if(qtd < MAX){
        // Desloca todos os elementos uma posicao para tras
        for(int i = qtd; i > 0; i--){
            jogos[i] = jogos[i - 1];
        }
        // Adiciona o novo jogo na primeira posicao
        jogos[0] = novoJogo;
        qtd++;
        printf("Jogo adicionado com sucesso na fila!\n");
    } else {
        printf("Capacidade maxima atingida. Nao e possivel adicionar mais jogos.\n");
    }
}

// Método para adiconar um novo Jogo | Estrutura Pilha
void adicionarJogoPilha(Jogo novoJogo){
    if(qtd < MAX){
        jogos[qtd] = novoJogo;
        qtd++;
        printf("Jogo adicionado com sucesso na pilha!\n");
    } else {
        printf("Capacidade maxima atingida. Nao e possivel adicionar mais jogos.\n");
    }
}

// Método para listar todos os jogos
void listarJogos(){
    if(qtd == 0){
        printf("Nenhum jogo cadastrado.\n");
        return;
    }
    for(int i = 0; i < qtd; i++){
        printf("Jogo %d:\n", i + 1);
        printf("Titulo: %s\n", jogos[i].titulo);
        printf("Genero: %s\n", jogos[i].genero);
        printf("Ano de Lançamento: %d\n", jogos[i].anoLancamento);
        printf("-----------------------\n");
    }
}



// Método para remover um jogo | Estrutura Fila
void removerJogoFila(){
    if(qtd == 0){
        printf("Nenhum jogo para remover.\n");
        return;
    }
    // Desloca todos os elementos uma posicao para frente
    for(int i = 0; i < qtd - 1; i++){
        jogos[i] = jogos[i + 1];
    }
    qtd--;
    printf("Jogo removido com sucesso da fila!\n");
}

// Método para remover um jogo | Estrutura Pilha
void removerJogoPilha(){
    if(qtd == 0){ 
        printf("Nenhum jogo para remover.\n");
        return;
    }
    qtd--;
    printf("Jogo removido com sucesso da pilha!\n");
}

// Método bara buscar jogos por título | Busca Linear
void buscarJogoPorTitulo(char titulo[]){
    int encontrado = 0;
    for(int i = 0; i < qtd; i++){
        if(strcmp(jogos[i].titulo, titulo) == 0){
            printf("Jogo encontrado:\n");
            printf("Titulo: %s\n", jogos[i].titulo);
            printf("Genero: %s\n", jogos[i].genero);
            printf("Ano de Lançamento: %d\n", jogos[i].anoLancamento);
            encontrado = 1;
            break;
        }
    }
    if(!encontrado){
        printf("Jogo com o titulo '%s' nao encontrado.\n", titulo);
    }
}

// Método para buscar jogos por título | Busca Binária
void buscarJogoPorTituloBinaria(char titulo[]){
    //Verifica se o array está ordenado, se não estiver, retorna uma mensagem de erro
    for(int i = 0; i < qtd - 1; i++){
        if(strcmp(jogos[i].titulo, jogos[i + 1].titulo) > 0){
            printf("Erro: O array de jogos nao esta ordenado. A busca binaria nao pode ser realizada.\n");
            return;
        }
    }       
    // Busca binária
    int esquerda = 0;
    int direita = qtd - 1;
    int encontrado = 0;
    while(esquerda <= direita){
        int meio = esquerda + (direita - esquerda) / 2;
        int cmp = strcmp(jogos[meio].titulo, titulo);
        if(cmp == 0){
            printf("Jogo encontrado:\n");
            printf("Titulo: %s\n", jogos[meio].titulo);
            printf("Genero: %s\n", jogos[meio].genero);
            printf("Ano de Lançamento: %d\n", jogos[meio].anoLancamento);
            encontrado = 1;
            break;
        } else if(cmp < 0){
            esquerda = meio + 1;
        } else {
            direita = meio - 1;
        }
    }
    if(!encontrado){
        printf("Jogo com o titulo '%s' nao encontrado.\n", titulo);
    }
}

// Método para buscar jogos pelo título | Busca Sentinela
void buscarJogoPorTituloSentinela(char titulo[]){
    if(qtd == 0){
        printf("Nenhum jogo cadastrado.\n");
        return;
    }
    // Adiciona o sentinela
    Jogo sentinela;
    strcpy(sentinela.titulo, titulo);
    jogos[qtd] = sentinela; // Coloca o sentinela na posição qtd
    int i = 0;
    // Busca até encontrar o sentinela
    while(strcmp(jogos[i].titulo, titulo) != 0){
        i++;
    }
    // Verifica se encontrou dentro dos jogos cadastrados
    if(i < qtd){
        printf("Jogo encontrado:\n");
        printf("Titulo: %s\n", jogos[i].titulo);
        printf("Genero: %s\n", jogos[i].genero);        
        printf("Ano de Lançamento: %d\n", jogos[i].anoLancamento);
    } else {
        printf("Jogo com o titulo '%s' nao encontrado.\n", titulo);
    }
}

// Metodo para ordenar jogos por título | Bubble Sort
void ordenarJogosPorTitulo(){
    for(int i = 0; i < qtd - 1; i++){
        for(int j = 0; j < qtd - i - 1; j++){   
            if(strcmp(jogos[j].titulo, jogos[j + 1].titulo) > 0){
                // Troca os jogos
                Jogo temp = jogos[j];
                jogos[j] = jogos[j + 1];
                jogos[j + 1] = temp;
            }
        }
    }
    printf("Jogos ordenados por titulo com sucesso!\n");
}   

// Método para ordenar jogos por título | Selection Sort
void ordenarJogosPorTituloSelection(){
    for(int i = 0; i < qtd - 1; i++){
        int minIndex = i;
        for(int j = i + 1; j < qtd; j++){
            if(strcmp(jogos[j].titulo, jogos[minIndex].titulo) < 0){
                minIndex = j;
            }
        }
        // Troca os jogos
        Jogo temp = jogos[i];
        jogos[i] = jogos[minIndex];
        jogos[minIndex] = temp;
    }
    printf("Jogos ordenados por titulo com sucesso (Selection Sort)!\n");
}

// Método para ordenar jogos por título | Insertion Sort
void ordenarJogosPorTituloInsertion(){
    for(int i = 1; i < qtd; i++){
        Jogo key = jogos[i];
        int j = i - 1;
        while(j >= 0 && strcmp(jogos[j].titulo, key.titulo) > 0){
            jogos[j + 1] = jogos[j];
            j--;
        }
        jogos[j + 1] = key;
    }
    printf("Jogos ordenados por titulo com sucesso (Insertion Sort)!\n");
}

void menu(){
    printf("=== Menu de Gerenciamento de Jogos ===\n");
    printf("1. Adicionar Jogo (Fila)\n");
    printf("2. Adicionar Jogo (Pilha)\n");
    printf("3. Remover Jogo (Fila)\n");
    printf("4. Remover Jogo (Pilha)\n");
    printf("5. Listar Jogos\n");
    printf("6. Buscar Jogo por Titulo (Busca Linear)\n");
    printf("7. Buscar Jogo por Titulo (Busca Binaria)\n");
    printf("8. Buscar Jogo por Titulo (Busca Sentinela)\n");
    printf("9. Ordenar Jogos por Titulo (Bubble Sort)\n");
    printf("10. Ordenar Jogos por Titulo (Selection Sort)\n");
    printf("11. Ordenar Jogos por Titulo (Insertion Sort)\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");

}

// Função principal
int main(){
    int opcao;
    do{
        menu();
        
        scanf("%d", &opcao);
        switch(opcao){
            case 1:{
                Jogo novoJogo;
                printf("Digite o titulo do jogo: ");
                scanf("%s", novoJogo.titulo);
                printf("Digite o genero do jogo: ");
                scanf("%s", novoJogo.genero);
                printf("Digite o ano de lancamento do jogo: ");
                scanf("%d", &novoJogo.anoLancamento);
                adicionarJogoFila(novoJogo);
            }
            break;
            case 2:{
                Jogo novoJogo;
                printf("Digite o titulo do jogo: ");
                scanf("%s", novoJogo.titulo);
                printf("Digite o genero do jogo: ");
                scanf("%s", novoJogo.genero);
                printf("Digite o ano de lancamento do jogo: ");
                scanf("%d", &novoJogo.anoLancamento);
                adicionarJogoPilha(novoJogo);
            }
            break;
            case 3:{
                removerJogoFila();
            }
            break;
            case 4:{
                removerJogoPilha();
            }
            break;
            case 5:{
                listarJogos();
            }
            break;
            case 6:{
                char titulo[50];
                printf("Digite o titulo do jogo para buscar: ");
                scanf("%s", titulo);
                buscarJogoPorTitulo(titulo);
            }
            break;
            case 7:{
                char titulo[50];
                printf("Digite o titulo do jogo para buscar: ");
                scanf("%s", titulo);
                buscarJogoPorTituloBinaria(titulo);
            }
            break;
            case 8:{
                char titulo[50];
                printf("Digite o titulo do jogo para buscar: ");
                scanf("%s", titulo);
                buscarJogoPorTituloSentinela(titulo);
            }
            break;
            case 9:{
                ordenarJogosPorTitulo();    
            }
            break;
            case 10:{
                ordenarJogosPorTituloSelection();
            }
            break;
            case 11:{
                ordenarJogosPorTituloInsertion();
            }
            break;
            case 0:{
                printf("Saindo do programa...\n");
            }
            break;
            default:{
                printf("Opcao invalida. Tente novamente.\n");
            }
            break;
        }
    }while(opcao != 0);
}
