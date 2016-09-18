#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void travessiaLabirinto();
int geradorLabirinto();

void display();
void ganhou();
void desenhaLabirinto();
void mostraParedeOuDirecao(int fr,int direcao);
int linha,coluna,entradaLinha,entradaColuna,saidaLinha,saidaColuna;
int labirinto[100][100];
int pilha[100][100];
void exibePilha();


void teclado(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'Q':
    case 'q':
        exit(0);
        break;
    case 'A':
    case 'a':
        glutDisplayFunc(travessiaLabirinto);
        glutPostRedisplay();
        break;
    case 'p':
    case 'P':
        exibePilha();
    }
}

void exibePilha(){
//    printf("%d",pilha[0]);
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            if(pilha[i][j]==1)
                printf("%d ", pilha[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv)
{

    printf("Digite a quantidade de colunas: ");
    scanf("%d",&coluna);
    printf("\nDigite a quantidade de linhas: ");
    scanf("%d",&linha);
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            labirinto[i][j] = 1;
        }
    }


    printf("\nDigite a linha entrada de 0 ate' %d: ", linha -1);
    scanf("%d",&entradaLinha);
    printf("\n\n Digite a coluna entrada de 0 ate' %d: ", coluna -1);
    scanf("%d",&entradaColuna);
    printf("\n\n Digite a linha saida de 0 ate' %d: ", linha -1);
    scanf("%d",&saidaLinha);
    printf("\n\n Digite a coluna saida de 0 ate' %d: ",coluna -1);
    scanf("%d",&saidaColuna);



    labirinto[entradaLinha][entradaColuna] = 2;
    labirinto[saidaLinha][saidaColuna] = -1;
    printf("\n\n\n Como sera' o labirinto... \n");
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
    glutDisplayFunc(travessiaLabirinto);
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


int geraDirecao()
{
    int x = 0;
    srand( (unsigned)time(NULL) );
    x = rand() % 4;
    return x;
}
void travessiaLabirinto()
{
while(1){
Sleep(200);
    int fr = geraDirecao();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    switch(fr)
    {
    case 0:
        mostraParedeOuDirecao(fr,0);
        printf("\n linha: %d",entradaLinha-1);
        printf("\n coluna: %d",entradaColuna);
        if(labirinto[entradaLinha-1][entradaColuna] != -1)
        {
            if(labirinto[entradaLinha-1][entradaColuna] == 1)
            {
                labirinto[entradaLinha-1][entradaColuna] = 0;
                entradaLinha--;
                pilha[entradaLinha-1][entradaColuna] = 1;
            }
            else
            {
                mostraParedeOuDirecao(fr,1);
            }
        }
        else
        {
            ganhou();
        }
        break;
    case 1:
        mostraParedeOuDirecao(fr,0);
        printf("\n linha: %d",entradaLinha);
        printf("\n coluna: %d",entradaColuna-1);

        if(labirinto[entradaLinha-1][entradaColuna] != -1)
        {
            if(labirinto[entradaLinha][entradaColuna-1] == 1)
            {
                labirinto[entradaLinha][entradaColuna-1] = 0;
                entradaColuna--;
                pilha[entradaLinha][entradaColuna-1] = 1;
            }
            else
            {
                mostraParedeOuDirecao(fr,1);
            }
        }
        else
        {
            ganhou();
        }
        break;
    case 2:
        mostraParedeOuDirecao(fr,0);
        printf("\n linha: %d",entradaLinha+1);
        printf("\n coluna: %d",entradaColuna);
        if(labirinto[entradaLinha+1][entradaColuna] != -1)
        {
            if(labirinto[entradaLinha+1][entradaColuna] == 1)
            {
                labirinto[entradaLinha+1][entradaColuna] = 0;
                entradaLinha++;
                pilha[entradaLinha+1][entradaColuna] = 1;
            }
            else
            {
                mostraParedeOuDirecao(fr,1);
            }
        }
        else
        {
            ganhou();
        }
        break;
    case 3:
        mostraParedeOuDirecao(fr,0);
        printf("\n linha: %d",entradaLinha);
        printf("\n coluna: %d",entradaColuna+1);
        if(labirinto[entradaLinha][entradaColuna+1] != -1)
        {
            if(labirinto[entradaLinha][entradaColuna+1] == 1)
            {
                labirinto[entradaLinha][entradaColuna+1] = 0;
                entradaColuna++;
                pilha[entradaLinha][entradaColuna+1] = 1;
            }
            else
            {
                mostraParedeOuDirecao(fr,1);
            }
        }
        else
        {
            ganhou();
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
}
void mostraParedeOuDirecao(int fr, int direcao)
{/*// 0 = ^^
// 1 = <<
// 2 = \/
// 3 = >>*/
    char mensagem[] = "";
    switch(fr)
    {
    case 0:
        strcat(mensagem, "Norte");
        break;
    case 1:
        strcat(mensagem, "Oeste");

        break;
    case 2:
        strcat(mensagem, "Sul");

        break;
    case 3:
        strcat(mensagem, "Leste");
        break;
    }
    if(direcao == 0)
    {
        char direcaoMensagem[] = "\n\nDirecao apontada sentido: ";
        strcat(direcaoMensagem, mensagem);
        printf ("%s", direcaoMensagem);
    }
    else
    {
        if(direcao == 1)
        {
            char direcaoMensagem[] = "\nParede encontrada no sentido:";
            strcat(direcaoMensagem, mensagem);
            printf ("%s", direcaoMensagem);
        }
    }
}
void ganhou()
{

    printf("\nParabe'ns, voce ganhou!");
    //return 0;
    exit(0);
}

