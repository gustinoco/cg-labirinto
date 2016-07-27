/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

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

    int entrada =0, saida = 0;
    printf("\n\n Digite a entrada: ");
    scanf("%d",&entrada);
    printf("\n\n Digite a saida: ");
    scanf("%d",&saida);
    if(verificaEntradaSaida(entrada, saida, linha, coluna) == 0)
    {
        printf("Entrada e saida invalidos");
    }

    printf("\n\nEntrada: %d   e saida  %d",entrada,saida);



}


int verificaEntradaSaida(int entrada, int saida, int linha, int coluna)
{
    if(entrada == linha && entrada == coluna && saida == linha && saida == coluna )
    {
        return 1;
    }
    else
        return 0;
}


void travessiaLabirinto()
{

}

int pegaLado()
{
    srand((unsigned)time(NULL));
    return rand() % 4;

}

