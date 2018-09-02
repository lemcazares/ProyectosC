//Incluimos las bibliotecas a usar

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Me da un poco de flojera poner printf asi que siempre o casi siempre lo sustituyo por algo mas corto

#define p printf
#define s scanf


//Aqui declaro mis funciones que voy a usar


float media();
float mediana();
float moda();
float varianza();
float desviacion();
float rango();
int menu();
void array();
float comparacion(const void* x, const void* y); // esta funcion aprendi a hacerla en internet, para que funcionara qsort

float arreglo[10]; //tengo un poco de problema con los apuntadores, asi que como solucion declare el arreglo que usaran 
//todas las funciones como global :)


/*En cuanto al main, me gusta hacerlos cortos, siento que facilitan la lectura del programa*/

int main(){

    int i=1, j=1;

    do{
        array();

        do{
        menu();
        p("\n\nQuieres realizar otra operacion con el mismo arreglo? \n\n\t1. Si\n\n\t2. No\n\n");
        s("\n\t%d",&j);

            if (j!=1){
            break;
            }

        }while(j=1);

    p("\n\nQuieres realizar otra operacion declarando otro arreglo? \n\n\t1. Si\n\n\t2. No\n\n");
    s("\n\t%d",&i);

            if (i!=1){
            break;
            }

    }while(i==1);

    p("\n\nHASTA LUEGO\n\n");



    getchar();
    return 0;
}

/*Use una funcion para realizar el menu, y no tener que estar tirando mucho codigo cuando se quiere volver a elegir*/
int menu(){

    int opcion=0;
    


    p("\n\nPor favor ingresa la operacion que quieres realizar:\n\n");
    p("\n\n\t1.\tMedia\n\n\t2.\tMediana\n\n\t3.\tModa\n\n\t4.\tDesviacion Estandar\n\n\t5.\tVariacion\n\n\t6.\tRango\n\n\t7.\tSalir\n\n");
    s("\n\n%d", &opcion);

    switch(opcion){


        case 1:
        
        		p("\n\n La media es: %.1f\n\n", (media()));
			break;

        case 2:

        		p("\n\n La mediana es: %.1f\n\n", (mediana()));
        		break;
        case 3:
        		moda();
        		break;

        case 4:
        		p("\n\n El resultado es: %.2f\n\n", desviacion());
        		break;
                
        case 5:
        		p("\n\n El resultado es: %.2f\n\n", varianza());
        		break;

        case 6: 
        		p("\n\n El resultado es: %.1f\n\n", rango());
        		break;		

        case 7:
     
        		break;

        default:
        		p("\n\nIngresa una opcion valida\n\n");
        		break;
    }

 return opcion;
}

void array(){

  //  float arreglo[10];
    int i, j=1, z;


    do{

        p("\n\nVamos a declarar un arreglo: \n\n\n");

        for(i=0; i<10;  i++){
    
        p("\n\nIngresa el numero %d:  ", i+1);
        s("%f", &arreglo[i]);

    }
    
        for(i=0; i<10;  i++){
    
        p("\n\nTu numero %d es: %.1f:  ", i+1, arreglo[i]);

    }

        do{
        p("\n\n\nSon correctos los numeros?\n\n\t1.\tSi\n\n\t2.\tNo\n\n");
        int y;
        s("\n  %d",&y);
        if(y==1){
            j=2;
            z=2;
            break;
        }
        else{
            if(y==2){
                j=1;
                z=2;
            }
            else{
                p("\n Ingresa una opcion validan\n\n");
                z=1;
                j=1;
            }
        }
    }while(z==1);
    }while(j==1);
}

float media(){

    int i, promedio=0;
    for(i=0; i<10; i++){

        promedio = promedio + arreglo[i];

    }

    return promedio/10;
}

float mediana(){

    int n;

    float med = 0;

    n = sizeof(arreglo)/sizeof(int);

    qsort(arreglo, n, sizeof(float), comparacion);


    med = (arreglo[4] + arreglo[5]) / 2;

    return med;

}

float moda(){       // La moda no pude hacer que funcionara :(
   /* float aux[10];
    float num=0, max=0;
    int cont=0;
    int i, j, k, l=0;


 
    for (i = 0; i < 10; i++){

        for (j = 0; j < 10; j++){

            if (arreglo[i] == arreglo[j]){

                if (i != j){
                    
                    aux[l] = arreglo[i];
                    l++;
                    
                    
                }
            }
        }
    }
    for (i = 0; i < 10; i++)
    {
    printf("%.0f\n", aux[i]);
    }
    */

    /*typedef struct{

    float contenido;
    int posicion; 
    int repeticiones;
    }elemento;


    typedef struct{

    elemento arre[10];

    }arre;

    int i;

    for(i=0; i<10; i++){

    arre

    }


    */

}

float comparacion(const void* x, const void* y){ //Funcion auxiliar para usar qsort()

    float *xx, *yy;
    int res;
    xx = (float *)x;
    yy = (float *)y;
    res = *xx - *yy;
    return (res);
}

float varianza(){

    float suma=0;
    int i;


    for (int i = 0; i < 10; i++)
    {
        suma = suma + ((arreglo[i] - media())*(arreglo[i] - media()));
    }

return suma/10;
}

float rango(){

    float ran=0;
    int n;

    n = sizeof(arreglo)/sizeof(float);

    qsort(arreglo, n, sizeof(float), comparacion);


    ran = (arreglo[9] - arreglo[0]);

    return ran;

}

float desviacion(){

    float desv=0;

    desv = sqrt(varianza());

    return desv;
}