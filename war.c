// Importa bibliotecas padrão da linguagem C
#include <stdio.h>      // Funções de entrada e saída (printf, scanf, etc)
#include <string.h>     // Funções para manipular strings (ex: strlen, strcpy, strcspn)

// Define uma constante com o número máximo de territórios permitidos
#define MAX_TERRITORIO 5

// Criação de um novo tipo de dado 'Territorio' usando typedef e struct
typedef struct {
    char nome[30];   // Nome do território (string com até 29 caracteres + '\0')
    char cor[10];    // Cor da tropa (string com até 9 caracteres + '\0')
    int tropa;       // Quantidade de tropas no território
} Territorio;

// Função principal do programa
int main() {
    Territorio territorios[MAX_TERRITORIO]; // Declara um vetor de estruturas 'Territorio' com o tamanho máximo definido
    int totalTerritorio = 0; // Variável que controla quantos territórios foram cadastrados
    int opcao; // Variável usada para armazenar a opção do menu escolhida pelo usuário

    // Mensagem inicial do jogo
    printf("===================================\n");
    printf("------Bem vindo ao WAR------\n");
    printf("Voce esta pronto? Vamos la!\n");

    // Estrutura de repetição que exibe o menu até o usuário escolher sair (opção 3)
    do {
        // Exibe o menu principal
        printf("===================================\n");
        printf("------MENU WAR------\n");
        printf("1. Cadastrar um territorio.\n");
        printf("2. Lista de territorio.\n");
        printf("3. Sair.\n");
        printf("===================================\n");       
        
        scanf(" %d", &opcao); // Lê a opção digitada pelo usuário
        getchar(); // Limpa o caractere de nova linha (\n) do buffer

        // Estrutura condicional para tratar a opção escolhida
        switch(opcao) {
            case 1:
                // Opção 1: Cadastrar um novo território
                if (totalTerritorio < MAX_TERRITORIO){ // Verifica se ainda há espaço disponível
                    printf("Digite o nome seu territorio: "); // Lê o nome do território (permite espaços)                  
                    fgets(territorios[totalTerritorio].nome, 30, stdin);
                    
                    printf("Digite a cor do seu territorio: "); // Lê a cor da tropa
                    fgets(territorios[totalTerritorio].cor, 10, stdin);

                    printf("Digite o tamanho da sua tropa: "); // Lê a quantidade de tropas (inteiro)
                    scanf(" %d", &territorios[totalTerritorio].tropa);
                    getchar(); // Limpa o buffer

                    // Remove o '\n' deixado pelo fgets
                    territorios[totalTerritorio].nome[strcspn(territorios[totalTerritorio].nome, "\n")] = '\0';
                    territorios[totalTerritorio].cor[strcspn(territorios[totalTerritorio].cor, "\n")] = '\0';

                    totalTerritorio++;  // Incrementa o contador de territórios cadastrados

                    printf("Novo territorio criado com sucesso!\n"); // Mensagem de confirmação
                } else {                 
                    printf("Pode nao, ja tem territorio demais.\n"); // Caso já tenha atingido o limite máximo de territórios
                    getchar();// Limpa o buffer
                }
                break;

            case 2: // Opção 2: Exibir lista de territórios cadastrados
                printf("===Lista de Territorios criados===\n");

                if (totalTerritorio == 0) { // Verifica se há territórios cadastrados
                    printf("Nao ha registro de territorio.\n");
                } else {
                    for (int i = 0; i < totalTerritorio; i++) {// Percorre todos os territórios cadastrados e mostra suas informações
                        printf("===================================\n");
                        printf("Territorio %d\n", i + 1);
                        printf("Nome da tropa: %s\n", territorios[i].nome);
                        printf("Cor: %s\n", territorios[i].cor);
                        printf("Soldados: %d\n", territorios[i].tropa);
                    }
                }
                break;

            case 3:// Opção 3: Sair do programa
                printf("Saindo do jogo...\n");
                break;

            default:
                printf("Opcao invalida!\n"); // Caso o usuário digite uma opção inválida
        }

    } while (opcao != 3); // Continua repetindo até que o usuário escolha sair
    
    return 0;
}
