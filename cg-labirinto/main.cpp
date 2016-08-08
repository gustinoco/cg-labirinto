
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
void display();
void desenhaLabirinto();
int linha,coluna,entradaLinha,entradaColuna,saidaLinha,saidaColuna;
int labirinto[100][100];
void janela(void)
{

    printf("\nevento de desenho...\n");
}

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


    glutInit(&argc, &argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(400, 400);
    //glutInitWindowPosition(150, 150);
    glutCreateWindow("Labirinto");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, coluna + 1, linha + 1, -1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glutDisplayFunc(display);
    glutKeyboardFunc(teclado);
    glutMainLoop();

    /*

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
    }*/
}


int verificaEntradaSaida(int entrada, int saida, int linha, int coluna)
{
    if(entrada == linha && entrada == coluna && saida == linha && saida == coluna )
    {
        return 1;
    }

    return 0;
}


void display()
{
    glColor3d(0, 0, 0);
    glClearColor(255, 255, 255, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    desenhaLabirinto();
    //glFlush();
}

void desenhaLabirinto()
{
    for (int i = 0; i<linha; i++)
        for (int j = 0; j<coluna; j++)
        {
            glBegin(GL_QUADS);
            if (labirinto[i][j] == 0)
                glColor3f(1.0, 1.0, 1.0);
            else
                glColor3f(0.3, 0.3, 0.3);

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




void travessiaLabirinto()
{
    printf("entrou");
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();//inicializa matriz com a matriz identidade
    glClear(GL_COLOR_BUFFER_BIT);//Limpa janela

   for (int i = 0; i<linha; i++)
        for (int j = 0; j<coluna; j++)
        {
            glBegin(GL_QUADS);
            if (labirinto[i][j] == 0)
                glColor3f(1.0, 1.0, 1.0);
            else
                glColor3f(0.3, 0.3, 0.3);

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

int pegaLado()
{
    if(lado == 3)
        lado = 0;
    else lado++;
    return lado;
    //return rand() % 4;

}

