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
            printf(" COBRA! %s perdeu!\n", (vez == 0) ? j1 : j2);
            break;
        } else if (caixa == botao) {
            printf(" BOTAO! %s venceu!\n", (vez == 0) ? j1 : j2);
            break;
        } else {
            printf("Caixa vazia...\n");
            vez = 1 - vez;
        }
    }
}

/* ===================== JOGO 3: GOUSMAS WAR ===================== */
void mostrarStatus(int g1[], int g2[]) {
    printf("\n--- STATUS ---\n");

    printf("Jogador 1:\n");
    for (int i = 0; i < 2; i++)
        printf("Gousma %d: %s\n", i, (g1[i] > 0) ? "Viva" : "Destruida");

    printf("\nJogador 2:\n");
    for (int i = 0; i < 2; i++)
        printf("Gousma %d: %s\n", i, (g2[i] > 0) ? "Viva" : "Destruida");
}

int perdeu(int g[]) {
    return g[0] == 0 && g[1] == 0;
}

void atacar(int a[], int d[]) {
    int x, y;

    printf("Sua Gousma (0-1): ");
    scanf("%d", &x);

    printf("Alvo (0-1): ");
    scanf("%d", &y);

    if (a[x] == 0 || d[y] == 0) {
        printf("Invalido!\n");
        return;
    }

    d[y] += a[x];

    if (d[y] > 5) {
        printf("💥 Desintegrou!\n");
        d[y] = 0;
    }
}

void dividir(int g[]) {
    int i, j = -1;

    printf("Qual dividir (0-1): ");
    scanf("%d", &i);

    if (g[i] <= 1) {
        printf("Nao pode!\n");
        return;
    }

    for (int k = 0; k < 2; k++)
        if (g[k] == 0) { j = k; break; }

    if (j == -1) {
        printf("Limite atingido!\n");
        return;
    }

    int metade = g[i] / 2;
    g[i] -= metade;
    g[j] = metade;
}

void gousmasWar() {
    int g1[2] = {1,1};
    int g2[2] = {1,1};
    int vez = 0, op;

    int turnos = 0;
    int MAX_TURNOS = 30; // limite

    while (1) {
        mostrarStatus(g1, g2);

        printf("\nJogador %d\n1-Atacar\n2-Dividir\n", vez+1);
        scanf("%d", &op);

        if (vez == 0) {
            if (op == 1) atacar(g1, g2);
            else dividir(g1);
        } else {
            if (op == 1) atacar(g2, g1);
            else dividir(g2);
        }

        // Verifica vitória
        if (perdeu(g1)) {
            printf("\n Jogador 2 venceu!\n");
            break;
        }

        if (perdeu(g2)) {
            printf("\n Jogador 1 venceu!\n");
            break;
        }

        // controle de turnos
        turnos++;
        if (turnos >= MAX_TURNOS) {
            printf("\n Empate! Limite de turnos atingido.\n");
            break;
        }

        vez = 1 - vez;
    }
}

/* ===================== MENU PRINCIPAL ===================== */
int main() {
    int opcao;
    char novamente;

    srand(time(NULL));

    do {
        printf("\n====== TITULO DO JOGO ======\n");
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
    