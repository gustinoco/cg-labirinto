
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
void display();
void desenhaLabirinto();
int linha,coluna,entradaLinha,entradaColuna,saidaLinha,saidaColuna;
int labirinto[100][100];

void teclado(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'q':
        exit(0);
        break;
    case 'r':
        glutDisplayFunc(desenhaLabirinto);
        printf("REINICIA");
        break;
    case 'a':
        glutDisplayFunc(travessiaLabirinto);
        glutPostRedisplay();
        printf("\nGera caminho do desenho");
        break;
    default:
        printf("\nevento de teclado\n");
        break;
    }
}

int main(int argc, char *argv)
{
    printf("Digite o as coluna ");
    scanf("%d",&coluna);
    printf("\nDigite a  qtd linha");
    scanf("%d",&linha);
    printf("\nImpressao do labirinto preenchido...\n\n\n");

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            labirinto[i][j] = 1;
            printf("%d ", labirinto[i][j]);
        }
        printf("\n");
    }


    printf("\n\n Digite a linha entrada de 0 ate' %d: ", linha -1);
    scanf("%d",&entradaLinha);
    printf("\n\n Digite a coluna entrada de 0 ate' %d: ", coluna -1);
    scanf("%d",&entradaColuna);
    printf("\n\n Digite a linha saida de 0 ate' %d: ", linha -1);
    scanf("%d",&saidaLinha);
    printf("\n\n Digite a coluna saida de 0 ate' %d: ",coluna -1);
    scanf("%d",&saidaColuna);



    labirinto[entradaLinha][entradaColuna] = 2;
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


    glutInit(&argc, &argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Labirinto");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, coluna + 1, linha + 1, -1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(display);
    glutKeyboardFunc(teclado);
    glutMainLoop();
}

void display()
{
    glColor3d(0, 0, 0);
    glClearColor(255, 255, 255, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    desenhaLabirinto();
}

void desenhaLabirinto()
{
    for (int i = 0; i<linha; i++)
        for (int j = 0; j<coluna; j++)
        {
            glBegin(GL_QUADS);
            if (labirinto[i][j] == 1)
                glColor3f(0.3, 0.3, 0.3);

            if(labirinto[i][j] == 0)
                glColor3f(0.0, 1.0, 1.0);

            if(labirinto[i][j] == labirinto[saidaLinha][saidaColuna])
                glColor3f(1.0, 0.0, 0.0);

            if(labirinto[i][j] == labirinto[entradaLinha][entradaColuna])
                glColor3f(0.3, 1.0, 0.0);

            glVertex2i(j, i);
            glVertex2i(j, i + 1);
            glVertex2i(j + 1, i + 1);
            glVertex2i(j + 1, i);
            glEnd();
            glBegin(GL_LINE_LOOP);
            glColor3f(0.6, 0.6, 0.6);
            glVertex2i(j, i);
            glVertex2i(j, i + 1);
            glVertex2i(j + 1, i + 1);
            glVertex2i(j + 1, i);
            glEnd();
        }
    glFlush();
}


//gera direcao
// 0 = ^^
// 1 = >>
// 2 = <<
// 3 = \/
int geraDirecao()
{
    int x = 0;
    srand( (unsigned)time(NULL) );
    x = rand() % 4;
    return x;
}
//int fr = 0;
void travessiaLabirinto()
{
    int fr = geraDirecao();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    switch(fr)
    {
    case 0:
        printf("\n0 ");
        printf("\n linha: %d",entradaLinha-1);
        printf("\n coluna: %d",entradaColuna);
        if(entradaLinha-1 > linha && entradaLinha-1 < 0  && labirinto[entradaLinha-1][entradaColuna] == 1)
        {
            labirinto[entradaLinha-1][entradaColuna] = 0;
            entradaLinha--;
        }
        else
        {
            printf("PAREDE 0");
        }
        break;
    case 1:
        printf("\n1");
            printf("\n linha: %d",entradaLinha);
            printf("\n coluna: %d",entradaColuna-1);
        if(labirinto[entradaLinha][entradaColuna-1] == 1)
        {
            labirinto[entradaLinha][entradaColuna-1] = 0;
            entradaColuna--;
        }
        else
        {
            printf("PAREDE 1");
        }
        break;
    case 2:
        printf("\n2");
            printf("\n linha: %d",entradaLinha+1);
            printf("\n coluna: %d",entradaColuna);
        if(labirinto[entradaLinha+1][entradaColuna] == 1)
        {
            labirinto[entradaLinha+1][entradaColuna] = 0;
            entradaLinha++;
        }
        else
        {
            printf("PAREDE 2");
        }
        break;
    case 3:

            printf("\n3");
            printf("\n linha: %d",entradaLinha);
            printf("\n coluna: %d",entradaColuna+1);
            if(labirinto[entradaLinha][entradaColuna+1] == 1)
        {
            labirinto[entradaLinha][entradaColuna+1] = 0;
            entradaColuna++;
        }
        else
        {
            printf("PAREDE 3");
        }
        break;
    }
    for (int i = 0; i<linha; i++)
        for (int j = 0; j<coluna; j++)
        {
            glBegin(GL_QUADS);
            if (labirinto[i][j] == 1)
                glColor3f(0.3, 0.3, 0.3);

            if(labirinto[i][j] == 0)
                glColor3f(1.0, 1.0, 1.0);

            if(labirinto[i][j] == labirinto[saidaLinha][saidaColuna])
                glColor3f(1.0, 0.0, 0.0);

            if(labirinto[i][j] == labirinto[entradaLinha][entradaColuna])
                glColor3f(0.3, 1.0, 0.0);

            glVertex2i(j, i);
            glVertex2i(j, i + 1);
            glVertex2i(j + 1, i + 1);
            glVertex2i(j + 1, i);
            glEnd();
            glBegin(GL_LINE_LOOP);
            glColor3f(0.6, 0.6, 0.6);
            glVertex2i(j, i);
            glVertex2i(j, i + 1);
            glVertex2i(j + 1, i + 1);
            glVertex2i(j + 1, i);
            glEnd();
        }
    glFlush();
}

