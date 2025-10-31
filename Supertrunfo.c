#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do jogo
typedef struct {
    char nome[50];
    float populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
} Carta;

int main() {
    Carta carta1, carta2; // Duas cartas para comparar
    int atributo1, atributo2;
    float valor1_c1, valor1_c2;
    float valor2_c1, valor2_c2;
    float soma1, soma2;
    int vencedor1, vencedor2;

    printf("=============================================\n");
    printf("           SUPER TRUNFO - DESAFIO FINAL      \n");
    printf("=============================================\n\n");

    // Cadastro da primeira carta
    printf("=== Cadastro da Carta 1 ===\n");
    printf("Nome do pais: ");
    scanf(" %[^\n]", carta1.nome); // Lê o nome com espaços
    printf("Populacao (em milhoes): ");
    scanf("%f", &carta1.populacao);
    printf("Area (em mil km²): ");
    scanf("%f", &carta1.area);
    printf("PIB (em bilhoes de US$): ");
    scanf("%f", &carta1.pib);
    printf("Pontos turisticos: ");
    scanf("%d", &carta1.pontosTuristicos);
    printf("Densidade demografica (hab/km²): ");
    scanf("%f", &carta1.densidadeDemografica);

    printf("\n=== Cadastro da Carta 2 ===\n");
    printf("Nome do pais: ");
    scanf(" %[^\n]", carta2.nome);
    printf("Populacao (em milhoes): ");
    scanf("%f", &carta2.populacao);
    printf("Area (em mil km²): ");
    scanf("%f", &carta2.area);
    printf("PIB (em bilhoes de US$): ");
    scanf("%f", &carta2.pib);
    printf("Pontos turisticos: ");
    scanf("%d", &carta2.pontosTuristicos);
    printf("Densidade demografica (hab/km²): ");
    scanf("%f", &carta2.densidadeDemografica);

    // Mostra as cartas cadastradas
    printf("\n=============================================\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n", carta2.nome);
    printf("=============================================\n");

    // Menu para escolher o primeiro atributo
    printf("\nEscolha o PRIMEIRO atributo para comparar:\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turisticos\n");
    printf("5 - Densidade Demografica\n");
    printf("Opcao: ");
    scanf("%d", &atributo1);

    // Menu dinâmico para o segundo atributo (sem repetir)
    printf("\nEscolha o SEGUNDO atributo (diferente do primeiro):\n");

    switch (atributo1) {
        case 1:
            printf("2 - Area\n3 - PIB\n4 - Pontos Turisticos\n5 - Densidade Demografica\n");
            break;
        case 2:
            printf("1 - Populacao\n3 - PIB\n4 - Pontos Turisticos\n5 - Densidade Demografica\n");
            break;
        case 3:
            printf("1 - Populacao\n2 - Area\n4 - Pontos Turisticos\n5 - Densidade Demografica\n");
            break;
        case 4:
            printf("1 - Populacao\n2 - Area\n3 - PIB\n5 - Densidade Demografica\n");
            break;
        case 5:
            printf("1 - Populacao\n2 - Area\n3 - PIB\n4 - Pontos Turisticos\n");
            break;
        default:
            printf("Opcao invalida! Programa encerrado.\n");
            return 0;
    }

    printf("Opcao: ");
    scanf("%d", &atributo2);

    // Impede escolher o mesmo atributo duas vezes
    if (atributo1 == atributo2) {
        printf("\nNao pode escolher o mesmo atributo duas vezes!\n");
        return 0;
    }

    // Pega o valor do primeiro atributo das duas cartas
    switch (atributo1) {
        case 1: valor1_c1 = carta1.populacao; valor1_c2 = carta2.populacao; break;
        case 2: valor1_c1 = carta1.area; valor1_c2 = carta2.area; break;
        case 3: valor1_c1 = carta1.pib; valor1_c2 = carta2.pib; break;
        case 4: valor1_c1 = carta1.pontosTuristicos; valor1_c2 = carta2.pontosTuristicos; break;
        case 5: valor1_c1 = carta1.densidadeDemografica; valor1_c2 = carta2.densidadeDemografica; break;
    }

    // Pega o valor do segundo atributo das duas cartas
    switch (atributo2) {
        case 1: valor2_c1 = carta1.populacao; valor2_c2 = carta2.populacao; break;
        case 2: valor2_c1 = carta1.area; valor2_c2 = carta2.area; break;
        case 3: valor2_c1 = carta1.pib; valor2_c2 = carta2.pib; break;
        case 4: valor2_c1 = carta1.pontosTuristicos; valor2_c2 = carta2.pontosTuristicos; break;
        case 5: valor2_c1 = carta1.densidadeDemografica; valor2_c2 = carta2.densidadeDemografica; break;
    }

    // Usa o operador ternário para decidir o vencedor de cada atributo
    vencedor1 = (atributo1 == 5) ? 
        (valor1_c1 < valor1_c2 ? 1 : (valor1_c1 > valor1_c2 ? 2 : 0)) :
        (valor1_c1 > valor1_c2 ? 1 : (valor1_c1 < valor1_c2 ? 2 : 0));

    vencedor2 = (atributo2 == 5) ? 
        (valor2_c1 < valor2_c2 ? 1 : (valor2_c1 > valor2_c2 ? 2 : 0)) :
        (valor2_c1 > valor2_c2 ? 1 : (valor2_c1 < valor2_c2 ? 2 : 0));

    // Soma dos dois atributos de cada carta
    soma1 = valor1_c1 + valor2_c1;
    soma2 = valor1_c2 + valor2_c2;

    // Mostra os resultados
    printf("\n=============== RESULTADO FINAL ===============\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n\n", carta2.nome);

    printf("Atributo 1 (%d): %.2f x %.2f\n", atributo1, valor1_c1, valor1_c2);
    printf("Atributo 2 (%d): %.2f x %.2f\n", atributo2, valor2_c1, valor2_c2);
    printf("----------------------------------------------\n");
    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", carta1.nome, soma1);
    printf("%s: %.2f\n", carta2.nome, soma2);
    printf("----------------------------------------------\n");

    // Decide quem venceu no total
    if (soma1 > soma2) {
        printf("Vencedor: %s\n", carta1.nome);
    } else if (soma2 > soma1) {
        printf("Vencedor: %s\n", carta2.nome);
    } else {
        printf("Empate!\n");
    }

    printf("==============================================\n");

    return 0;
}
