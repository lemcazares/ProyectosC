#include<stdio.h>
#include<math.h> //Inclui esta biblioteca para usar pow, pero no se puede usar en linux, o no supe como, asi que lo implemente con un for

#define p printf
#define s scanf

int menu();
int suma();
int resta();
int multiplicacion();
float division();
long int potencia();
int factorial();

int main(){

	int i=1;
printf("\n\nHOLA BIENVENIDO A LA CALCULADORA\n\n");

do{
menu();
p("\n\nQuieres realizar otra operacion? \n\n\t1. Si\n\n\t2. No\n\n");
s("\n\t%d",&i);
}while(i==1);

printf("\n\nHASTA LUEGO\n\n");

getchar();
return 0;
}

int menu(){

    int opcion=0;

 
    p("\n\nPor favor ingresa la operacion que quieres realizar:\n\n");
    p("\n\n\t1.\tSuma\n\n\t2.\tResta\n\n\t3.\tMultiplicacion\n\n\t4.\tDivision\n\n\t5.\tPotencia\n\n\t6.\tFactorial\n\n\t7.\tSalir\n\n");
    s("\n\n%d", &opcion);

    switch(opcion){


        case 1:
        
        		p("\n\n El resultado es: %d", suma());
			break;

        case 2:

        		p("\n\n El resultado es: %d", resta());
        		break;
        case 3:
        		p("\n\n El resultado es: %d", multiplicacion());
        		break;

        case 4:
        		p("\n\n El resultado es: %.2f", division());
        		break;
        case 5:
        		p("\n\n El resultado es: %li", potencia());
        		break;

        case 6: 
        		p("\n\n El resultado es: %d", factorial());
        		break;		

        case 7:
     
        		break;

        default:
        		p("\n\nIngresa una opcion valida\n\n");
        		break;
    }

 return opcion;
}

int suma(){

	int x=0,y=0, i,res=0;

	p("\n\nIngresa la cantidad de numeros a sumar: ");
	s("%d",&y);

	for(i=0; i<y;i++){
	
		p("\n\nIngresa un numero entero:  ");
		s("%d", &x);
		res += x;

	}

return res;

}

int resta(){

	int x=0,y=0, i,res=0;

	p("\n\nIngresa la cantidad de numeros a restar: ");
	s("%d",&y);

		p("\n\nIngresa un numero entero:  ");
		s("%d", &x);

		res = x - res ;

	for(i=0; i<y-1;i++){
	
		p("\n\nIngresa un numero entero:  ");
		s("%d", &x);

		res = res - x;

	}

return res;

}

int multiplicacion(){
	int x=0,y=0, i,res=1;

	p("\n\nIngresa la cantidad de numeros a multiplicar: ");
	s("%d",&y);

	for(i=0; i<y;i++){
	
		p("\n\nIngresa un numero entero:  ");
		s("%d", &x);
		res = res * x;

	}

	return res;
}

float division(){

		float x=0,y=0, i;

	
		p("\n\nIngresa el dividendo:  ");
		s("%f", &x);

		do{
		p("\n\nIngresa el divisor:  ");
		s("%f", &y);

		if (y=0){
			p("\n\nNo se puede dividir entre 0!!\n\nIngresalo de nuevo\n\n");
			i=0;

		}
		else{
			i=1;
			return x/y;
		}

	}while(i==0);
}

long int potencia(){

	long int base, exp, i;
	long int res;

	p("\n\nPor favor introduce un numero entero como la base:   ");
	s("%li", &base);
	p("\n\nPor favor introduce un numero entero como el exponente:   ");
	s("%li", &exp);
/*
	res= pow(base, exp); NO SE PUEDE EJECUTAR EN LINUX
*/

	res = base;

	if(exp==0){
		res=1;
	}
	else{

		for(i = 0; i<exp-1; i++){

		res=base*res;
		}
	}

	return res;
	
}

int factorial(){//es

	
  int x, y, res = 1;

  	p("\n\nIngresa un numero:  ");

	  s("%d\n\n", &x);

  for (y = x; y > 1; y--){

    res = res * y;
	}
 
  return res;

}

