#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países
// Tema: Comparação de Cartas de Cidades
// Objetivo: Permitir o cadastro de cidades e comparar cartas com base em atributos diversos

#define MAX_CIDADES 32 // Número máximo de cartas (8 estados * 4 cidades)

// Estrutura que representa uma carta de cidade
typedef struct {
    char estado[20];               // Nome do estado da cidade
    char codigo[4];                // Código identificador da cidade (ex: A01)
    char nome[30];                 // Nome da cidade
    int populacao;                 // População total
    float area;                    // Área em km²
    float pib;                     // PIB em milhões
    int pontos_turisticos;        // Quantidade de pontos turísticos
} Cidade;

// Vetor que armazena todas as cidades cadastradas
Cidade cidades[MAX_CIDADES];
int total_cidades = 0; // Contador de cidades cadastradas

// Função que permite o cadastro de uma nova cidade
void cadastrarCidade() {
    // Verifica se já atingiu o limite máximo de cidades
    if (total_cidades >= MAX_CIDADES) {
        printf("Limite de cidades atingido!\n");
        return;
    }

    // Criação de uma nova cidade temporária
    Cidade nova;

    // Coleta de dados do usuário para preencher a cidade
    printf("Digite o estado da cidade: ");
    scanf(" %[^\n]", nova.estado); // Lê string com espaços

    printf("Digite o código da cidade (ex: A01): ");
    scanf("%3s", nova.codigo); // Lê até 3 caracteres
    nova.codigo[3] = '\0';     // Garante término de string

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nova.nome);

    printf("Digite a população: ");
    scanf("%d", &nova.populacao);

    printf("Digite a área (em km²): ");
    scanf("%f", &nova.area);

    printf("Digite o PIB (em milhões): ");
    scanf("%f", &nova.pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &nova.pontos_turisticos);

    // Adiciona a nova cidade ao vetor
    cidades[total_cidades++] = nova;

    printf("Cidade cadastrada com sucesso!\n");
}

// Função auxiliar para exibir os dados de uma cidade formatada
void exibirCidade(Cidade c) {
    printf("Código: %s\n", c.codigo);
    printf("Estado: %s\n", c.estado);
    printf("Cidade: %s\n", c.nome);
    printf("População: %d\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f milhões\n", c.pib);
    printf("Pontos Turísticos: %d\n", c.pontos_turisticos);
    printf("-------------------------\n");
}

// Função para buscar o índice de uma cidade a partir do código
int buscarCidadePorCodigo(char codigo[4]) {
    for (int i = 0; i < total_cidades; i++) {
        if (strcmp(cidades[i].codigo, codigo) == 0)
            return i; // Retorna o índice se encontrar
    }
    return -1; // Retorna -1 se não encontrar
}

// Função que permite comparar duas cidades com base em um atributo
void compararCartas() {
    if (total_cidades < 2) {
        printf("Cadastre pelo menos duas cidades para comparar.\n");
        return;
    }

    // Leitura dos códigos das cidades a serem comparadas
    char cod1[4], cod2[4];
    printf("Digite o código da primeira cidade: ");
    scanf("%3s", cod1);
    printf("Digite o código da segunda cidade: ");
    scanf("%3s", cod2);

    // Busca os índices correspondentes no vetor
    int idx1 = buscarCidadePorCodigo(cod1);
    int idx2 = buscarCidadePorCodigo(cod2);

    // Validação das cidades
    if (idx1 == -1 || idx2 == -1) {
        printf("Uma ou ambas as cidades não foram encontradas.\n");
        return;
    }

    // Recupera as cidades selecionadas
    Cidade c1 = cidades[idx1];
    Cidade c2 = cidades[idx2];

    // Exibe menu de atributos disponíveis para comparação
    printf("Escolha o atributo para comparar:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos Turísticos\n");
    printf("5. Densidade Populacional (menor vence)\n");
    printf("Opção: ");

    int opcao;
    scanf("%d", &opcao);

    // Exibe as cidades selecionadas antes da comparação
    printf("\nComparando:\n");
    exibirCidade(c1);
    exibirCidade(c2);

    // Lógica de comparação baseada na opção escolhida
    switch (opcao) {
        case 1:
            // Maior população vence
            if (c1.populacao > c2.populacao)
                printf("Vencedora: %s (maior população)\n", c1.nome);
            else if (c2.populacao > c1.populacao)
                printf("Vencedora: %s (maior população)\n", c2.nome);
            else
                printf("Empate em população.\n");
            break;

        case 2:
            // Maior área vence
            if (c1.area > c2.area)
                printf("Vencedora: %s (maior área)\n", c1.nome);
            else if (c2.area > c1.area)
                printf("Vencedora: %s (maior área)\n", c2.nome);
            else
                printf("Empate em área.\n");
            break;

        case 3:
            // Maior PIB vence
            if (c1.pib > c2.pib)
                printf("Vencedora: %s (maior PIB)\n", c1.nome);
            else if (c2.pib > c1.pib)
                printf("Vencedora: %s (maior PIB)\n", c2.nome);
            else
                printf("Empate em PIB.\n");
            break;

        case 4:
            // Mais pontos turísticos vence
            if (c1.pontos_turisticos > c2.pontos_turisticos)
                printf("Vencedora: %s (mais pontos turísticos)\n", c1.nome);
            else if (c2.pontos_turisticos > c1.pontos_turisticos)
                printf("Vencedora: %s (mais pontos turísticos)\n", c2.nome);
            else
                printf("Empate em pontos turísticos.\n");
            break;

        case 5: {
            // Densidade populacional = população / área
            // Menor densidade vence
            float dens1 = c1.populacao / c1.area;
            float dens2 = c2.populacao / c2.area;
            if (dens1 < dens2)
                printf("Vencedora: %s (menor densidade populacional)\n", c1.nome);
            else if (dens2 < dens1)
                printf("Vencedora: %s (menor densidade populacional)\n", c2.nome);
            else
                printf("Empate em densidade populacional.\n");
            break;
        }

        default:
            printf("Opção inválida.\n");
    }
}

// Função principal: exibe menu e executa ações conforme a escolha do usuário
int main() {
    int opcao;

    do {
        // Exibe o menu principal do programa
        printf("\nMenu:\n");
        printf("1. Cadastrar Cidade\n");
        printf("2. Comparar Cartas\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        // Executa ação conforme opção escolhida
        switch (opcao) {
            case 1:
                cadastrarCidade(); // Cadastro de nova cidade
                break;
            case 2:
                compararCartas(); // Comparação entre duas cidades
                break;
            case 3:
                printf("Saindo do sistema... Obrigado por jogar!\n"); // Finalização do programa
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != 3); // Repetição até o usuário escolher sair

    return 0;
}
