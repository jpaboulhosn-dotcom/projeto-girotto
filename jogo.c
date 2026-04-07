#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ===================== JOGO 1: QUIZ ===================== */
void quiz() {
    char r;
    int acertos = 0;

    printf("\n1) Linguagem usada?\nA) Java\nB) C\nC) Python\nD) PHP\n");
    scanf(" %c", &r);
    if (r=='B'||r=='b'){ printf("Correto!\n"); acertos++; }
    else printf("Errado! Resposta: B\n");

    printf("\n2) 2+2?\nA)3\nB)4\nC)5\nD)6\n");
    scanf(" %c", &r);
    if (r=='B'||r=='b'){ printf("Correto!\n"); acertos++; }
    else printf("Errado! Resposta: B\n");

    printf("\n3) Capital do Brasil?\nA)SP\nB)RJ\nC)Brasilia\nD)Salvador\n");
    scanf(" %c", &r);
    if (r=='C'||r=='c'){ printf("Correto!\n"); acertos++; }
    else printf("Errado! Resposta: C\n");

    printf("\n4) Comentario em C?\nA)//\nB)#\nC)<!-- -->\nD)**\n");
    scanf(" %c", &r);
    if (r=='A'||r=='a'){ printf("Correto!\n"); acertos++; }
    else printf("Errado! Resposta: A\n");

    printf("\n5) 1 byte tem?\nA)4\nB)8\nC)16\nD)32\n");
    scanf(" %c", &r);
    if (r=='B'||r=='b'){ printf("Correto!\n"); acertos++; }
    else printf("Errado! Resposta: B\n");

    printf("\nVoce acertou %d/5\n", acertos);
}

/* ===================== JOGO 2: COBRA NA CAIXA ===================== */
void cobraNaCaixa() {
    char nomes[7][20] = {
        "Ana", "Bruno", "Carlos",
        "Diana", "Eduardo", "Fernanda", "Gabriel"
    };

    int e1, e2;
    char j1[20], j2[20];

    printf("\nEscolha o Jogador 1:\n");
    for (int i = 0; i < 7; i++)
        printf("%d - %s\n", i, nomes[i]);

    scanf("%d", &e1);

    printf("\nEscolha o Jogador 2:\n");
    scanf("%d", &e2);

    sprintf(j1, "%s", nomes[e1]);
    sprintf(j2, "%s", nomes[e2]);

    int vez = rand() % 2;

    printf("\nExploradores: %s vs %s\n", j1, j2);
    printf("Quem comeca: %s\n", (vez == 0) ? j1 : j2);

    int cobra = rand() % 5;
    int botao;

    do {
        botao = rand() % 5;
    } while (botao == cobra);

    int caixa;

    while (1) {
        printf("\nVez de %s\n", (vez == 0) ? j1 : j2);
        printf("Escolha uma caixa (0 a 4): ");
        scanf("%d", &caixa);

       if (caixa == cobra) {
        printf(" COBRA! ");

        if (vez == 0)
            printf("%s perdeu!\n", j1);
        else
            printf("%s perdeu!\n", j2);

        break;

    } else if (caixa == botao) {
        printf(" BOTAO! ");

        if (vez == 0)
            printf("%s venceu!\n", j1);
        else
            printf("%s venceu!\n", j2);

        break;

    } else {
        printf("Caixa vazia...\n");
        vez = 1 - vez;
    }
}
/* ===================JOGO 3: GOUSMAS WAR=================== */
/* ===================== MOSTRAR STATUS ===================== */
void mostrarStatus(int g1[], int g2[]) {

    printf("\n====================\n");
    printf("STATUS DO JOGO\n");
    printf("====================\n");

    // Jogador 1
    printf("Jogador 1:\n");

    if (g1[0] > 0) {
        printf("Gousma 0 = %d\n", g1[0]);
    } else {
        printf("Gousma 0 = X (morta)\n");
    }

    if (g1[1] > 0) {
        printf("Gousma 1 = %d\n", g1[1]);
    } else {
        printf("Gousma 1 = X (morta)\n");
    }

    // Jogador 2
    printf("\nJogador 2:\n");

    if (g2[0] > 0) {
        printf("Gousma 0 = %d\n", g2[0]);
    } else {
        printf("Gousma 0 = X (morta)\n");
    }

    if (g2[1] > 0) {
        printf("Gousma 1 = %d\n", g2[1]);
    } else {
        printf("Gousma 1 = X (morta)\n");
    }

    printf("\n");
}

/* ===================== VERIFICAR DERROTA ===================== */
int perdeu(int g[]) {

    // Se as duas forem 0, perdeu
    if (g[0] == 0) {
        if (g[1] == 0) {
            return 1;
        }
    }

    return 0;
}

/* ===================== ATAQUE ===================== */
void atacar(int atacante[], int defensor[]) {

    int escolhaMinha;
    int escolhaInimigo;

    printf("\n--- ATAQUE ---\n");

    printf("Escolha sua gousma (0 ou 1): ");
    scanf("%d", &escolhaMinha);

    printf("Escolha qual atacar (0 ou 1): ");
    scanf("%d", &escolhaInimigo);

    // Verificar se escolhas são válidas
    if (escolhaMinha != 0 && escolhaMinha != 1) {
        printf("Escolha invalida!\n");
        return;
    }

    if (escolhaInimigo != 0 && escolhaInimigo != 1) {
        printf("Escolha invalida!\n");
        return;
    }

    // Verificar se as gousmas existem
    if (atacante[escolhaMinha] == 0) {
        printf("Sua gousma esta morta!\n");
        return;
    }

    if (defensor[escolhaInimigo] == 0) {
        printf("Gousma inimiga ja esta morta!\n");
        return;
    }

    // Fazer ataque
    int valorAtaque = atacante[escolhaMinha];
    int valorDefesa = defensor[escolhaInimigo];

    int resultado = valorDefesa + valorAtaque;

    defensor[escolhaInimigo] = resultado;

    printf("Ataque realizado!\n");

    // Verificar se morreu
    if (defensor[escolhaInimigo] > 5) {
        defensor[escolhaInimigo] = 0;
        printf("A gousma inimiga morreu!\n");
    }
}

/* ===================== DIVIDIR ===================== */
void dividir(int g[]) {

    int escolha;

    printf("\n--- DIVIDIR ---\n");

    printf("Qual gousma voce quer dividir (0 ou 1): ");
    scanf("%d", &escolha);

    if (escolha != 0 && escolha != 1) {
        printf("Escolha invalida!\n");
        return;
    }

    if (g[escolha] <= 1) {
        printf("Nao pode dividir essa gousma!\n");
        return;
    }

    // Verificar espaço
    if (g[0] != 0 && g[1] != 0) {
        printf("Nao ha espaco para dividir!\n");
        return;
    }

    int metade;
    metade = g[escolha] / 2;

    g[escolha] = g[escolha] - metade;

    // Colocar a nova gousma
    if (g[0] == 0) {
        g[0] = metade;
    } else {
        g[1] = metade;
    }

    printf("Divisao realizada!\n");
}

/* ===================== JOGO ===================== */
void gousmasWar() {

    int g1[2];
    int g2[2];

    
    g1[0] = 1;
    g1[1] = 1;

    g2[0] = 1;
    g2[1] = 1;

    int jogadorAtual = 0;
    int opcao;
    int contadorTurnos = 0;

    while (1) {

        mostrarStatus(g1, g2);

        printf("\n====================\n");
        printf("Vez do jogador %d\n", jogadorAtual + 1);
        printf("====================\n");

        printf("1 - Atacar\n");
        printf("2 - Dividir\n");

        scanf("%d", &opcao);

        // Jogador 1
        if (jogadorAtual == 0) {

            if (opcao == 1) {
                atacar(g1, g2);
            }

            if (opcao == 2) {
                dividir(g1);
            }
        }

        // Jogador 2
        if (jogadorAtual == 1) {

            if (opcao == 1) {
                atacar(g2, g1);
            }

            if (opcao == 2) {
                dividir(g2);
            }
        }

        // Verificar vitória
        if (perdeu(g1) == 1) {
            printf("\nJogador 2 venceu!\n");
            break;
        }

        if (perdeu(g2) == 1) {
            printf("\nJogador 1 venceu!\n");
            break;
        }

        // Contador de turnos
        contadorTurnos = contadorTurnos + 1;

        if (contadorTurnos == 30) {
            printf("\nEmpate!\n");
            break;
        }

        // Trocar jogador
        if (jogadorAtual == 0) {
            jogadorAtual = 1;
        } else {
            jogadorAtual = 0;
        }
    }
}


/* ===================== MENU PRINCIPAL ===================== */
int main() {
    int opcao;
    char novamente;

    srand(time(NULL));

    do {
        printf("\n======= TITULO DO JOGO =======\n");
        printf("1: Pergunta e Resposta\n");
        printf("2: Cobra na Caixa\n");
        printf("3: Gousmas War\n");
        printf("4: Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                do {
                    quiz();
                    printf("Jogar novamente? (s/n): ");
                    scanf(" %c",&novamente);
                } while(novamente=='s'||novamente=='S');
                break;

            case 2:
                do {
                    cobraNaCaixa();
                    printf("Jogar novamente? (s/n): ");
                    scanf(" %c",&novamente);
                } while(novamente=='s'||novamente=='S');
                break;

            case 3:
                do {
                    gousmasWar();
                    printf("Jogar novamente? (s/n): ");
                    scanf(" %c",&novamente);
                } while(novamente=='s'||novamente=='S');
                break;

        }

    } while(opcao != 4);

    printf("Saindo...\n");
    return 0;
}
    
