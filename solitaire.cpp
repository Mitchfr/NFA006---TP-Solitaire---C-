
#include <iostream>
#include <array>
#include <time.h>
 #include <iomanip>

using namespace std;
const int NBCASES = 9;
array<array<int,NBCASES>,NBCASES> Grille;

// cette Enregistrement permet de stocker dans Coordonnées les valeurs de
// x,y, CoordDep, CoordSens
struct Coordonnees{
    int CoordX;                     // coordonnée x
    int CoordY;                     // coordonnée y
    char CoordDep;                  // coordonnée déplacement (H)orizontal ou (V)erticale
    char CoordSens;                 // coordonnée sens déplacement (B)as ou (H)aut
};

/*
*   Fonction qui remplie le tableau avec des '-1'
*  On fait 2 boucles: 1 pour parcourir les lignes et 1 pour les colonnes
*/

array<array<int,NBCASES>,NBCASES>  initGrille (array<array<int,NBCASES>,NBCASES> Grille){
   for (int i=0;i<NBCASES;i++){
        for (int x=0;x<NBCASES;x++){
            Grille[i][x]=-1;
                 }
    }
return Grille;

}

/*
*   Fonction qui remplie le tableau avec des '1'
*  On fait 2 boucles: 1 pour parcourir les lignes et 1 pour les colonnes
*  Ensuite on ajoute 1 chiffre 0 au milieu (en 4,4)
*/
array<array<int,NBCASES>,NBCASES>  remplirGrille(array<array<int,NBCASES>,NBCASES> Grille){
    for (int i=0;i<NBCASES;i++){             // on remplit uniquement les colonnes de 4 à 6 (indice 0 à 3)
        for (int x=3;x<6;x++){
            Grille[i][x]=1;
        }
    }

    for (int i=3;i<6;i++){                      // on remplit uniquement les ligne de 4 à 6 (indice 0 à 3)
        for (int x=0;x<NBCASES;x++){
            Grille[i][x]=1;
        }
    }
    Grille[4][4]=0;                             // on met un Zéro au centre
    return Grille;
}

/*
*  Fonction qui affiche le tableau formater

*/
array<array<int,NBCASES>,NBCASES>  afficherGrille(array<array<int,NBCASES>,NBCASES> Grille){

     for (int y=0;y<NBCASES;y++){
        for (int p=0;p<NBCASES;p++){
                    //int val =
            printf("%3d",Grille[y][p]);
        }
        cout <<" \n";
    }

    return Grille;
}


/*
*   saisir : fonction qui permet de saisir les coordonnées et le sens
*   Si on choisi H pour horizontal, le choix D (droite) ou G (gauche) sera proposé
*   Si le choix V pour vertcal est choisit, il sera demandé ensuite soit H pour Haut ou B pous Bas
*   on utilise une boucle while pour controler que la saisie est conforme
*   si elle ne l'est pas on met un message d'erreur et on redemande la saisie
*   On retournera les coordonnes dans 'coordonnees'
*/
Coordonnees  saisir(array<array<int,NBCASES>,NBCASES> Grille, int x, int y, char dep, char sens){

  Coordonnees coordonnees;
        do{

            cout <<"Entrer une ligne : ";
            cin >>x;
            if (x>NBCASES  || x<1){
                cout <<"ERREUR: saisir une position entre 1 et 9\n";
            }

        } while (x>NBCASES || x<1);

        do{

            cout <<"Entrer une colonne : ";
            cin >>y;
            if (y>NBCASES  || y<1){
                cout <<"ERREUR: saisir une position entre 1 et 9\n";
            }

        }while (y>NBCASES || y<1);

        do{

            cout <<"Entrer le déplacement (H ou V) : ";
            cin >>dep;
            if (dep!='h' && dep!='H' && dep!='v' && dep!='V'){
                  cout <<"ERREUR: saisir soit H ou V\n";
            }

        }while (dep!='h' && dep!='H' && dep!='v' && dep!='V');

        if  (dep=='h' || dep=='H'){
            do{
                cout <<"Entrer le déplacement (G ou D) : ";
                cin >>sens;
                if (sens!='g' && sens!='G' & sens!='d' && sens!='D'){
                    cout <<"ERREUR: saisir soit G ou D\n";
                }

            } while (sens!='g' && sens!='G' && sens!='d' && sens!='D');
        }
        else {
            do{
                cout <<"Entrer le déplacement (H ou B) : ";
                cin >>sens;
                if (sens!='h' && sens!='H' & sens!='b' && sens!='B'){
                    cout <<"ERREUR: saisir soit G ou D\n";
                }

            } while (sens!='h' && sens!='H' & sens!='b' && sens!='B');
        }


    // on stocke les coordonnees dans struct 'enregistrement
    coordonnees.CoordX=x;
    coordonnees.CoordY=y;
    coordonnees.CoordDep=dep;
    coordonnees.CoordSens=sens;

    return coordonnees;
}




/*
*   PriseHD : modifie la valeur des 3 cases. La position x,y =0
*   ensuite la position x,y+1=0 et x,y+2=1
*   nous avons donc déplacé le pion vers la droite
*/
array<array<int,NBCASES>,NBCASES>  priseHD(array<array<int,NBCASES>,NBCASES> Grille, int x, int y ){
         Grille[x][y]=0;
         Grille[x][y+1]=0;
         Grille[x][y+2]=1;
         return Grille;
}


/*
*   PriseHD : modifie la valeur des 3 cases. La position x,y =0
*   ensuite la position x,y-1=0 et x,y-2=1
*   nous avons donc déplacé le pion vers la gauche
*/
array<array<int,NBCASES>,NBCASES>  priseHG(array<array<int,NBCASES>,NBCASES> Grille, int x, int y ){
         Grille[x][y]=0;
         Grille[x][y-1]=0;
         Grille[x][y-2]=1;
         return Grille;
}

/*
*   PriseHD : modifie la valeur des 3 cases. La position x,y =0
*   ensuite la position x,y-1=0 et x,y-2=1
*   nous avons donc déplacé le pion vers le haut
*/
array<array<int,NBCASES>,NBCASES>  priseVH(array<array<int,NBCASES>,NBCASES> Grille, int x, int y ){
         Grille[x][y]=0;
         Grille[x-1][y]=0;
         Grille[x-2][y]=1;
         return Grille;
}


/*
*   PriseHD : modifie la valeur des 3 cases. La position x,y =0
*   ensuite la position x,y+1=0 et x,y+2=1
*   nous avons donc déplacé le pion vers le bas
*/
array<array<int,NBCASES>,NBCASES>  priseVB(array<array<int,NBCASES>,NBCASES> Grille, int x, int y ){
         Grille[x][y]=0;
         Grille[x+1][y]=0;
         Grille[x+2][y]=1;
         return Grille;
}


/*
*   Fonction qui vérifie si le pion peut être déplacer à l'horizontale
*   et à droite
*/
bool  estPriseHD(array<array<int,NBCASES>,NBCASES> Grille, int x, int y ){

        if (Grille[x][y+2]==0 && Grille[x][y+1]==1) {          // vérifie si la case +1 est egale à '1' et si la case +2 est égale à '0'

            return true;                                       // si vrai on peut déplacer le pion

        }
        else{

            return false;                                      // si faux, on ne peut pas

        }
}

/*
*   Fonction qui vérifie si le pion peut être déplacer à l'horizontale
*   et à gauche
*/
bool  estPriseHG(array<array<int,NBCASES>,NBCASES> Grille, int x, int y ){
   cout << "*-*-*-*-* "<<Grille[x][y]<<" * "<<Grille[x][y-1]<<" * "<<Grille[x][y-2];
        if (Grille[x][y-2]==0 && Grille[x][y-1]==1){           // vérifie si la case -1 est egale à '1' et si la case -2 est égale à '0'
                return true;                                   // si vrai on peut déplacer le pion

        }
        else{

            return false;                                      // si faux, on ne peut pas

        }
}

/*
*   Fonction qui vérifie si le pion peut être déplacer à la verticale
*   et en bas
*/
bool  estPriseVB(array<array<int,NBCASES>,NBCASES> Grille, int x, int y ){
        if (Grille[x+2][y]==0 && Grille[x+1][y]==1 ){          // vérifie si la case +1 est egale à '1' et si la case +2 est égale à '0'

           return true;                                        // si vrai on peut déplacer le pion
        }
        else{
            return false;                                      // si faux, on ne peut pas

        }
}
/*
*   Fonction qui vérifie si le pion peut être déplacer à la verticale
*   et en haut
*/
bool  estPriseVH(array<array<int,NBCASES>,NBCASES> Grille, int x, int y ){
        if (Grille[x-2][y]==0 && Grille[x-1][y]==1 ){           // vérifie si la case -1 est egale à '1' et si la case -2 est égale à '0'
            return true;                                        // si vrai on peut déplacer le pion


        }
        else{
            return false;                                       // si faux, on ne peut pas
        }
}

/*
*   Fonction qui vérifie si le pion peut être pris
*   on retourne la variable 'positionOK' qui sera vrai si on peut déplacer le pion sinon
*   elle sera à false si on ne peut pas.
*   on verifie pour chaque position choisie si le pion se trouve en dehors du jeu
*/

bool  estPrise(array<array<int,NBCASES>,NBCASES> Grille, int x, int y, char dep, char sens){
    bool positionOK;

            if (x>NBCASES-1 || x<0 || x>NBCASES || y<0 ||  x>NBCASES || Grille[x][y]==-1) {                // verifie que x est supérieur au bord gauche, y supérieur au bord haut et
                                                                                                           // que la position du pion contient 1     .
                                                                                                           // si c'est le cas on met un message d'erreur
                        cout <<"ATTENTION: Impossible de jouer ce coup \n";
                        positionOK=false;
            }

            else if ((dep =='h' || dep =='H') && (sens=='d' || sens=='D')){
                    if (y>=NBCASES-2){
                        cout <<"\n  ##################       Vous ne pouvez pas jouer ce coup à droite";
                    }
                    else{
                             positionOK = estPriseHD(Grille, x, y);
                    }
            }
            else if ((dep =='h' || dep =='H') && (sens=='g' || sens=='G')){
                        if (y<=1){
                        cout <<"\n  ##################       Vous ne pouvez pas jouer ce coup à gauche";
                    }
                    else{
                positionOK = estPriseHG(Grille, x, y);
            }
            }
            else if ((dep =='v' || dep =='V') && (sens=='h' || sens=='H')){
                    if (x<=1){
                        cout <<"\n  ##################       Vous ne pouvez pas jouer ce coup vers le haut";
                    }
                    else{
                positionOK = estPriseVH(Grille, x, y);
            }
            }
            else if ((dep =='v' || dep =='V') && (sens=='b' || sens=='B')){
                        if (x>=NBCASES-2){
                        cout <<"\n  ##################       Vous ne pouvez pas jouer ce coup vers le bas";
                    }
                    else{
                positionOK = estPriseVB(Grille, x, y);
            }
            }

    return positionOK;
}

/*
*   Fonction qui qui va enregistrer le coup si c'est possible
*   on regarde les choix de l'utilisateur et on redirige vers une fonction priseXX
*   en fonction du choix
*
*/
array<array<int,NBCASES>,NBCASES>  JouerCoup(array<array<int,NBCASES>,NBCASES> Grille, int x, int y, char dep, char sens){

    bool positionOK;
    positionOK = estPrise(Grille, x, y, dep, sens);
    if (estPrise){
            if ((dep=='h' || dep=='H') && (sens =='d' || sens=='D')){           // si Horizontal Droit
                    Grille=priseHD(Grille, x, y);                               // appel de la fonction qui enregistre la modification
                    positionOK=true;
            }
            if ((dep=='h' || dep=='H') && (sens =='g' || sens=='G')){           // si Horizontal gauche
                    Grille=priseHG(Grille, x, y);                               // appel de la fonction qui enregistre la modification
                    positionOK=true;
            }
            if ((dep=='v' || dep=='V') && (sens =='h' || sens=='H')){           // si vertical haut
                    Grille=priseVH(Grille, x, y);                               // appel de la fonction qui enregistre la modification
                    positionOK=true;
            }
            if ((dep=='v' || dep=='V') && (sens =='b' || sens=='B')){           // si vertical bas
                    Grille=priseVB(Grille, x, y);                               // appel de la fonction qui enregistre la modification
                    positionOK=true;
            }

    }
    else {
        positionOK=false;                                                   // enregistrement impossible
    }
    return Grille;
}


/*
*   Fonction qui compte le nombre de coups pour 1 position du pion
*   on regarde dans chaque direction les coups possibles
*   et on ajoute 1 si c'est faisable
*
*/

int  nbCoups(array<array<int,NBCASES>,NBCASES> Grille, int x, int y ){
    int compteur=0;                                     // variable pour comptabiliser les coups
            if (Grille[x][y]==1 && Grille[x-1][y]==1 && Grille[x-2][y]==0 && x>2){
                compteur++;
            }
            if (Grille[x][y]==1 && Grille[x+1][y]==1 && Grille[x+2][y]==0 && x<7){
                compteur++;
            }
            if (Grille[x][y]==1 && Grille[x][y-1]==1 && Grille[x][y-2]==0 && y>2){
                compteur++;
            }
            if (Grille[x][y]==1 && Grille[x][y+1]==1 && Grille[x][y+2]==0 && y<7){
                compteur++;
            }

    return compteur;                                                                // retourne le nombre de coup possible

}


/*
*   Fonction qui compte le nombre de coups total sur toute la grille
*   on utilise la fonction 'nbCoups' pour comptabiliser tous les coups possible
*   sur la grille
*
*/
int  nbCoupsTotal(array<array<int,NBCASES>,NBCASES> Grille){
    int compteur=0;                                     // variable pour comptabiliser les coups

            for (int x=0;x<NBCASES;x++){
                for (int y=0;y<NBCASES;y++){
                        if (Grille[x][y]!=-1){          // si la case ne contient pas -1 on lance la fonction 'nbCoups'
                             compteur= compteur+nbCoups(Grille,x,y);
                                                    }

            }

            }

  cout <<"\n  ##################       Nombre totale de coups possibles : "<<compteur<<"\n";                                                         // sinon c'est vrai, on peut éplacer le pio
    return compteur;
}

int main()

{

    setlocale(LC_CTYPE, "fra");     // pour afficher les carractère accentués
    int x,y,choix,compteur;         // x pour l'ordonnee, y l'abcisse, choix pour le choix fu menu, compteur pour le nombre de coups
    char dep,sens;                  // dep pour le sens horizontal ou vertical, sens pour haut et bas
    Coordonnees coordonnees;        // initialisation de la structure  'coordonnees'
    Grille = initGrille(Grille);    // initialisation de la structure
    Grille = remplirGrille(Grille);

    do{
        Grille = afficherGrille(Grille);    //  on affiche la grille
        coordonnees = saisir(Grille,x,y,dep,sens);  // saisie des coordonnées

        // on retire -1 pour le décalage entre la saisie de l'utilisateur et l'indice du tableau
        x=coordonnees.CoordX-1;
        y=coordonnees.CoordY-1;
        dep=coordonnees.CoordDep;
        sens=coordonnees.CoordSens;


        int estPriseChek = estPrise(Grille,x,y,dep,sens);       // verifie s'il est possible de déplacer le pion
                                                                // estPriseChek est vrai si c'est posible , si false c'est pas possible

        if (estPriseChek){                                      // si estPriseChek est vrai on enregistre le coup
            Grille = JouerCoup(Grille,x,y,dep,sens);
            cout <<"\n ##################        Coup enregistré\n";
        }
        else{                                                   // si estPriseChek est faux l'enregistrement n'est pas possible
            cout <<"\n ##################        Coup non enregistré\n";
        }

        int coups = nbCoupsTotal(Grille);                       // appel de la fonction 'nbCoupsTotal' qui stocke dans 'coups' le nombre total de coup possi
        if (coups<=0){                                          // si le nombre de coup est egale à zero, la partie est terminee
            /* On fait 2 boucles pour parcourir le tableau
            *  on verifie que la case est bien differente de -1
            *  et on met dans 'compteur' le nombre de coups qu'il reste.
            */
            for (int x=0;x<NBCASES;x++){
                for (int y=0;y<NBCASES;y++){
                    if (Grille[x][y]==1){
                        cout <<"\nVous avez Perdu !\n";
                        Grille = afficherGrille(Grille);
                        return 0;
                    }
                    else{
                        cout <<"\nBRAVO! vous avez gagné !\n";
                        Grille = afficherGrille(Grille);
                        return 0;
                    }
                }
            }
        }
        Grille = afficherGrille(Grille);                    // on affiche la grille

    // on reboucle tout le programme pou jouer le prochain coup
    // l'utilisateur peut sortir en faisant '0'
        cout <<"\n0 pour sortir - 1 pour continuer";
        cin >>choix;
    }while(choix!=0);

    return 0;

}
