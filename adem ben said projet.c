#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct pile{
    char element ;
    struct pile * suivant ;
}pile ;

typedef pile * PILE ;

typedef struct pile_entier{
    float element ;
    struct pile_entier * suivant ;
}pile_entier ;

typedef pile_entier * PILE1 ;

PILE empiler(PILE p,char e){
PILE pt;
pt=malloc(sizeof(pile));
pt->element=e;
pt->suivant=p;
p=pt;
return p;
}
PILE1 empiler1(PILE1 p,float e){
PILE1 nvelement1;
nvelement1 = malloc(sizeof(pile_entier));
nvelement1->element = e ;
nvelement1->suivant=p;
p=nvelement1;
return p;
}


int pilevide(PILE p){
    return p == NULL ;
}

PILE initpile(){
    PILE  monpile ;
    monpile = NULL ;

    return monpile ;
}

PILE1 affiche(PILE1 p){
    PILE1 v=p ;
    if(v==NULL){
    	printf("pile vide\n");
    }
    else{
    	while(v!=NULL){
		printf("%f",v->element);
		v=v->suivant;
		
		
	}
    }
   
}
PILE affiche1(PILE p){
    PILE v=p ;
    if(v==NULL){
    	printf("pile vide\n");
    }
    else{
    	while(v!=NULL){
		printf("%c",v->element);
		v=v->suivant;
		
		
	}
    }
 
}




PILE depiler1(PILE p,char *a){
    PILE v=p;
    *a=p->element;
	p=p->suivant;
	free(v);
	return p;
}
PILE1 depiler(PILE1 p,int *a){
    PILE1 v=p;
    *a=p->element;
	p=p->suivant;
	free(v);
	return p;
}

int pilevide1(PILE1 p){
    return p == NULL ;
}

PILE1 initpile1(){
    PILE1  monpile ;
    monpile = NULL ;

    return monpile ;
}




int main()
{
    PILE  pile1;
    PILE1  pile2;
    PILE  pile3;
    char nvelement ;
    float nvelement1 ;
    int elm1 ;
    int elm2 ;
    char operateur , parenthese ;
    float result ;
    char operation[25] ;
    char entier[10] = "" ;
    int i , j,resu ;
    float floatconvertion ;


    pile1 = initpile() ;
    pile2 = initpile1() ;
    pile3 = initpile() ;

    printf("Entrer une operation >>> ");
    gets(operation);


    i = 0 ;
    while(i < strlen(operation)){
        if(operation[i] == '(' ){
        	 
            pile1=empiler(pile1,operation[i]);
        }else if(operation[i] >= '0' && operation[i] <= '9'){
            j = 0 ;
            while(operation[i] >= '0' && operation[i] <= '9' && i < strlen(operation)){
                entier[j] = operation[i] ;
                j++ ;
                i++ ;
            }
            entier[j] = '\0';
            i-- ;
            //puts(entier);
            floatconvertion = atof(entier);
            pile2=empiler1(pile2,floatconvertion);
        }else if(operation[i] == '+' || operation[i] == '-' || operation[i] == '/' || operation[i] == '*'){
        	
           pile3= empiler(pile3,operation[i]);
           
        }else {
            pile1=empiler(pile1,')');
           
            pile3 = depiler1(pile3,&operateur) ;
            pile2 = depiler(pile2,&elm1) ;
            pile2 = depiler(pile2,&elm2) ;
            switch(operateur){
                case '+' :
                    nvelement1 = elm2 + elm1 ;
                    pile2=empiler1(pile2,nvelement1) ;
                    break ;

                case '-' :
                     nvelement1 = elm2 - elm1 ;
                    pile2=empiler1(pile2,nvelement1) ;
                    break ;

                case '*' :
                    nvelement1 = elm2 *elm1 ;
                    pile2=empiler1(pile2,nvelement1) ;
                    break ;

                case '/' :
                    nvelement1 = (float)elm2 / elm1 ;
                    pile2=empiler1(pile2,nvelement1) ;
                    break ;
            }
        
        }

        i++ ;
    }
  pile2=depiler(pile2,&resu);
    printf("%s=%d",operation,resu);
   
    return 0;
}
