
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void travessiaLabirinto();
int geradorLabirinto();
int pegaLado();
int verificaEntradaSaida(int entrada, int saida, int linha, int coluna);
int lado;
int main()
{
    int linha=0, coluna=0;


    printf("Digite o as coluna ");
    scanf("%d",&coluna);
    printf("\nDigite a  qtd linha");
    scanf("%d",&linha);
    printf("\nImpressao do labirinto preenchido...\n\n\n");

    int labirinto[linha][coluna];
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            labirinto[i][j] = 1;
            printf("%d ", labirinto[i][j]);
        }
        printf("\n");
    }

    int entradaLinha, entradaColuna, saidaLinha, saidaColuna;
    printf("\n\n Digite a linha entrada de 0 ate' %d: ", linha -1);
    scanf("%d",&entradaLinha);
    printf("\n\n Digite a coluna entrada de 0 ate' %d: ", coluna -1);
    scanf("%d",&entradaColuna);
    printf("\n\n Digite a linha saida de 0 ate' %d: ", linha -1);
    scanf("%d",&saidaLinha);
    printf("\n\n Digite a coluna saida de 0 ate' %d: ",coluna -1);
    scanf("%d",&saidaColuna);

    labirinto[entradaLinha][entradaColuna] = 0;
    labirinto[saidaLinha][saidaColuna] = -1;
    printf("\n\n\n IMPRESSAO COM ENTRADAS \n");
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            printf("%d ", labirinto[i][j]);
        }
        printf("\n");
    }

    int entrada[entradaLinha][entradaColuna];
    int d=entradaLinha,e=entradaColuna;

int fr = 0;
    while(entrada[d][e] != labirinto[saidaLinha][saidaColuna])
    {

        switch (fr)
        {
        case 0:
            printf("0 \n");
            if(entrada[d++][e] == 1)
            {
                entrada[d++][e] = 0;
                entrada[d][e] = entrada[d++][e];
            }
            break;
        case 1:
            if(entrada[d][e++] == 1)
            {
                entrada[d][e++] = 0;
                entrada[d][e] = entrada[d][e++];
                printf("1 \n");
            }
            break;
        case 2:
            if(entrada[d--][e] == 1){
                entrada[d--][e] = 0;
                entrada[d][e] = entrada[d--][e];
                printf("2 \n");
            }
            break;
        case 3:
            if(entrada[d][e--] == 1){
                entrada[d][e--] = 0;
            entrada[d][e] = entrada[d][e--];
            printf("3 \n");
            }
            break;

        }
        fr = fr +1;
    }


     for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            printf("%d ", labirinto[i][j]);
        }
        printf("\n");
    }
}


int verificaEntradaSaida(int entrada, int saida, int linha, int coluna)
{
    if(entrada == linha && entrada == coluna && saida == linha && saida == coluna )
    {
        return 1;
    }

    return 0;
}


void travessiaLabirinto()
{

}

int pegaLado()
{
  if(lado == 3)
    lado = 0;
    else lado++;
  return lado;
    //return rand() % 4;
    //return rand() % 4;

}

