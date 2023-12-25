#include <stdlib.h>
#include <stdio.h>
#include<time.h>

void affichage(char M[3][3])
{
    printf("      1     2     3  \n");
    printf(" 1    %c  |  %c  |  %c  \n",M[0][0],M[0][1],M[0][2]);
    printf("    ------------------\n");
    printf(" 2    %c  |  %c  |  %c  \n",M[1][0],M[1][1],M[1][2]);
    printf("    ------------------\n");
    printf(" 3    %c  |  %c  |  %c  \n",M[2][0],M[2][1],M[2][2]);
}
void remlire(char M[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            M[i][j] = ' ' ;
        }
    }
}
int plain(char M[3][3])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
           if(M[i][j] == ' ')
           {
               return 0;
           }
        }
    }
    return 1;
}
void jouee(char M[3][3] , char c1)
{
    int l , c ;
    do
    {
        printf("La ligne : ");
        scanf("%d",&l);
        printf("La colone : ");
        scanf("%d",&c);
        l = l - 1 ;
        c = c - 1 ;
    }while(l<0 || l>2 || c<0 || c>2 || M[l][c] != ' ');
    M[l][c] = c1 ;
}
int gagne(char M[3][3])
{
    for(int i=0;i<3;i++)
    {
        if((M[i][0] == 'X' && M[i][1] == 'X' && M[i][2] == 'X') || (M[i][0] == 'O' && M[i][1] == 'O' && M[i][2] == 'O'))
        {
            return 1;
        }
    }
     for(int j=0;j<3;j++)
    {
        if((M[0][j] == 'X' && M[1][j] == 'X' && M[2][j] == 'X') || (M[0][j] == 'O' && M[1][j] == 'O' && M[2][j] == 'O'))
        {
            return 1;
        }
    }
    if((M[0][0] == 'X' && M[1][1] == 'X' && M[2][2] == 'X') || (M[0][0] == 'O' && M[1][1] == 'O' && M[2][2] == 'O'))
    {
        return 1;
    }
    if((M[2][0] == 'X' && M[1][1] == 'X' && M[0][2] == 'X') || (M[2][0] == 'O' && M[1][1] == 'O' && M[0][2] == 'O'))
    {
        return 1;
    }
    return 0;
}
void machine(char M[3][3] , char c1)
{
    int l , c , i ;
    //meilleur position (ligne)
    for(i=0;i<3;i++)
    {
        if(M[i][0] == ' ' || M[i][1] == ' ' || M[i][2] == ' ')
        {
            if(M[i][0] == ' ')
            {
                if((M[i][1] == M[i][2] && M[i][2] == 'O') || (M[i][1] == M[i][2] && M[i][2] == 'X'))
                {
                    M[i][0] = c1 ;
                    if(gagne(M) == 1)
                    {
                        return;
                    }
                    else
                    {
                        M[i][0] = ' ' ;
                        l = i ;
                    }
                }
            }
            else if(M[i][1] == ' ')
                 {
                    if((M[i][0] == M[i][2] && M[i][2] == 'O') || (M[i][0] == M[i][2] && M[i][2] == 'X'))
                    {
                        M[i][1] = c1 ;
                        if(gagne(M) == 1)
                        {
                            return;
                        }
                        else
                        {
                            M[i][1] = ' ' ;
                            l = i ;
                        }
                    }
                 }
                 else
                 {
                     if((M[i][0] == M[i][1] && M[i][1] == 'O') || (M[i][0] == M[i][1] && M[i][1] == 'X'))
                     {
                        M[i][2] = c1 ;
                        if(gagne(M) == 1)
                        {
                            return;
                        }
                        else
                        {
                            M[i][2] = ' ' ;
                            l = i ;
                        }
                     }
                 }
        }
    }
    for(i=2;i>=0;i--)
    {
        if(M[i][0] == ' ' || M[i][1] == ' ' || M[i][2] == ' ')
        {
            if(M[i][0] == ' ')
            {
                if((M[i][1] == M[i][2] && M[i][2] == 'O') || (M[i][1] == M[i][2] && M[i][2] == 'X'))
                {
                    if(i>l)
                        l = i ;
                    M[l][0] = c1 ;
                    return ;
                }
            }
            else if(M[i][1] == ' ')
                 {
                    if((M[i][0] == M[i][2] && M[i][2] == 'O') || (M[i][0] == M[i][2] && M[i][2] == 'X'))
                    {
                        if(i>l)
                            l = i ;
                        M[l][1] = c1 ;
                        return ;
                    }
                 }
                 else
                 {
                     if((M[i][0] == M[i][1] && M[i][1] == 'O') || (M[i][0] == M[i][1] && M[i][1] == 'X'))
                     {
                        if(i>l)
                            l = i ;
                        M[l][2] = c1 ;
                        return ;
                     }
                 }
        }
    }
    //meilleur position (colone)
    for(i=0;i<3;i++)
    {
        if(M[0][i] == ' ' || M[1][i] == ' ' || M[2][i] == ' ')
        {
            if(M[0][i] == ' ')
            {
                if((M[1][i] == M[2][i] && M[2][i] == 'O') || (M[1][i] == M[2][i] && M[2][i] == 'X'))
                {
                    M[0][i] = c1 ;
                    if(gagne(M) == 1)
                    {
                        return;
                    }
                    else
                    {
                        M[0][i] = ' ' ;
                        l = i ;
                    }
                }
            }
            else if(M[1][i] == ' ')
                 {
                    if((M[0][i] == M[2][i] && M[2][i] == 'O') || (M[0][i] == M[2][i] && M[2][i] == 'X'))
                    {
                        M[1][i] = c1 ;
                        if(gagne(M) == 1)
                        {
                            return;
                        }
                        else
                        {
                            M[1][i] = ' ' ;
                            l = i ;
                        }
                    }
                 }
                 else
                 {
                     if((M[0][i] == M[1][i] && M[1][i] == 'O') || (M[0][i] == M[1][i] && M[1][i] == 'X'))
                     {
                        M[2][i] = c1 ;
                        if(gagne(M) == 1)
                        {
                            return;
                        }
                        else
                        {
                            M[2][i] = ' ' ;
                            l = i ;
                        }
                     }
                 }
        }
    }
    for(i=2;i>=0;i--)
    {
        if(M[0][i] == ' ' || M[1][i] == ' ' || M[2][i] == ' ')
        {
            if(M[0][i] == ' ')
            {
                if((M[1][i] == M[2][i] && M[2][i] == 'O') || (M[1][i] == M[2][i] && M[2][i] == 'X'))
                {
                    if(i>l)
                        l = i ;
                    M[0][l] = c1 ;
                    return ;
                }
            }
            else if(M[1][i] == ' ')
                 {
                    if((M[0][i] == M[2][i] && M[2][i] == 'O') || (M[0][i] == M[2][i] && M[2][i] == 'X'))
                    {
                        if(i>l)
                            l = i ;
                        M[1][l] = c1 ;
                        return ;
                    }
                 }
                 else
                 {
                     if((M[0][i] == M[1][i] && M[1][i] == 'O') || (M[0][i] == M[1][i] && M[1][i] == 'X'))
                     {
                        if(i>l)
                            l = i ;
                        M[2][l] = c1 ;
                        return ;
                     }
                 }
        }
    }
    //position diagonale principale
    if(M[0][0] == ' ' || M[1][1] == ' ' || M[2][2] == ' ')
    {
        if(M[0][0] == ' ')
        {
            if((M[1][1] == M[2][2] && M[2][2] == 'O') || (M[1][1] == M[2][2] && M[2][2] == 'X'))
            {
                M[0][0] = c1 ;
                return ;
            }
        }
        else if(M[1][1] == ' ')
        {
            if((M[0][0] == M[2][2] && M[2][2] == 'O') || (M[0][0] == M[2][2] && M[2][2] == 'X'))
            {
                M[1][1] = c1 ;
                return ;
            }
        }
        else
        {
            if((M[1][1] == M[0][0] && M[0][0] == 'O') || (M[1][1] == M[0][0] && M[0][0] == 'X'))
            {
                M[2][2] = c1 ;
                return ;
            }
        }
    }
    //position diagonale secondaire
    if(M[0][2] == ' ' || M[1][1] == ' ' || M[2][0] == ' ')
    {
        if(M[0][2] == ' ')
        {
            if((M[1][1] == M[2][0] && M[2][0] == 'O') || (M[1][1] == M[2][0] && M[2][0] == 'X'))
            {
                M[0][2] = c1 ;
                return ;
            }
        }
        else if(M[1][1] == ' ')
        {
            if((M[0][2] == M[2][0] && M[2][0] == 'O') || (M[0][2] == M[2][0] && M[2][0] == 'X'))
            {
                M[1][1] = c1 ;
                return ;
            }
        }
        else
        {
            if((M[1][1] == M[0][2] && M[0][2] == 'O') || (M[1][1] == M[0][2] && M[0][2] == 'X'))
            {
                M[2][0] = c1 ;
                return ;
            }
        }
    }
    //aleatoire position (1 ere fois )
    srand(time(0));
    do
    {
        l = rand() % 3  ;
        c = rand() % 3  ;
    }while(l<0 || l>2 || c<0 || c>2 || M[l][c] != ' ');
    M[l][c] = c1 ;
}

int main()
{
    char M[3][3] ;
    int choix , commence , copie_choix ;
    printf("___________________________________________________________________________");
    printf("\n                            TIC TAC TOE (X O)                              ");
    printf("\n___________________________________________________________________________\n");
    printf("\n1 - 1JOUEURE \n2 - 2JOUEURES \n");
    do
    {
        printf("\nDonnez votre choix ( 1 ou 2 ) : ");
        scanf("%d",&choix);
    }while(choix != 1 && choix != 2);
    if(choix == 1)
    {
        /*printf("\nQui commece le premier : ");
        printf("\n1 - VOUS \n2 - LA MACHINE");
        do
        {
            printf("\nLa reponse ( 1 ou 2 ) : ");
            scanf("%d",&commence);
        }while(commence != 1 && commence != 2);*/
        do
        {
            srand(time(0));
            commence = rand() % 3 ;
        }while(commence == 0);
    }
    copie_choix = choix ;
    remlire(M);
    do
    {
        printf("\r");
        if((choix == 2) || (choix == 1 && commence == 1))
        {
            if(plain(M) != 1)
            {
                printf("----------JOUEURE 1 (X)-------------\n");
                affichage(M);
                jouee(M,'X');
                if(gagne(M) == 1)
                {
                    printf("\n********************************************\n");
                    printf("LE JOUEURE 1 A GAGNEE \n");
                    affichage(M);
                    return 0;
                }
            }
            choix = 2 ;
        }
        if((choix == 2) || (copie_choix == 1 && commence == 2))
        {
            if(plain(M) != 1)
            {
                if(copie_choix == 1)
                {
                    printf("----------LA MACHINE (O)-------------\n");
                    affichage(M);
                    machine(M,'O');
                }
                else
                {
                    printf("----------JOUEURE 2 (O)-------------\n");
                    affichage(M);
                    jouee(M,'O');
                }
                if(gagne(M) == 1)
                {
                    printf("\n********************************************\n");
                    if(copie_choix == 1)
                    {
                        printf("LA MACHINE A GAGNEE \n");
                    }
                    else
                    {
                        printf("LE JOUEURE 2 A GAGNEE \n");
                    }
                    affichage(M);
                    return 0;
                }
            }
            choix = 2 ;
        }
    }while(plain(M) != 1);
    printf("\n_______________________________________________________\n");
    printf("\t MATCH NULL \n");
    affichage(M);
    return 0;
}
