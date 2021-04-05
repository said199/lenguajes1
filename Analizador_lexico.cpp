#include <iostream>

using namespace std;

int main()
{
	char caracter ;
int i=0;

 char textoExtraido[200][200];

FILE *fichero, *guardar;
   fichero= fopen("lenguaje.txt","rt");

     if (fichero==NULL) {// si fichero no falla coge un letra dle fichero
        cout << "Error al abrir el archivo lenguaje.txt"  <<  endl;

    } else {


    	  for ( i = 0; i <200; i++)
    {



fscanf(fichero, "%s" , &textoExtraido[i]);


string Cadena = textoExtraido[i];



string TablaSimbolos[10]={"mientras", "si", "sino", "fin","inicio", "entero", "racional", "entonces",
                          "imprima", "repetir"};

string TablaOperando[11]={"<", ">", "+", "-",">=", "<=", "!=", "==","/","*","="};

enum TEstado{q0, q1, q2,q3,q4,q5,qe};

TEstado Estado;


int  Simbolo;

int k;
int longitud;

k= longitud=0;
Estado= q0;



longitud= Cadena.size();

while (longitud > k and Estado !=qe){
	Simbolo = Cadena[k];


	switch (Estado){
		case q0:
			if (Simbolo >= 'a' && Simbolo <='z' || Simbolo >= 'A' && Simbolo <='Z'){
				Estado=q1;
			}else
			if(Simbolo >= '0' && Simbolo <= '9'){
				Estado = q3;
			}else if(Simbolo=='='||Simbolo=='+'||Simbolo=='-'||Simbolo=='<'||Simbolo=='<'||Simbolo=='>'
			||Simbolo=='!'||Simbolo=='*'||Simbolo=='/'){
				Estado=q5;
			}else{
				Estado=qe;
			}


			break;

			case q1:
				if(Simbolo >= 'a' && Simbolo <='z'|| Simbolo >= 'A' && Simbolo <='Z'){
					Estado = q1;
				}
				else{
					Estado = qe;
				}
				break;

			  case q2:
            //si es un digito
            if(Simbolo >= '0' && Simbolo <= '9'){
                Estado= q3;
            }
            break;
        case q3:
            //si es un digito
            if(Simbolo >= '0' && Simbolo <= '9'){
                Estado= q3;
            }
            else{
			if(Simbolo == '.'){
                    Estado= q4;


                }
            }
            break;
        case q4:
            //si es un digito
            if(Simbolo >= '0' && Simbolo <= '9' ){


                Estado= q4;
				}

            break;

            case q5:

            if(Simbolo=='='||Simbolo=='+'||Simbolo=='-'||Simbolo=='<'||Simbolo=='<'||Simbolo=='>'||Simbolo=='!'
			||Simbolo=='*'||Simbolo=='/'){
				Estado=q5;
			}
	}
	k++;



}

      int conta=0;
	   for(int t=0; t<longitud; t++){
       	for(int j=0; j<longitud; j++){
       if(Cadena[t]==Cadena[j+1] ){
	   if(Cadena[t]=='.'){

        	conta++;
        		if(conta>2){

			 Estado= qe;

		break;
		}

		 }

        }

		}
	}






if(Estado==q1){

	cout <<"\n ["<<Cadena<< "] es: Cadena aceptada";


	int j;
	int TamanioArreglo=sizeof TablaSimbolos/ sizeof TablaSimbolos[0];
	for(j=0; j< TamanioArreglo; j++){
		if(Cadena.compare(TablaSimbolos[j])==0){
			cout<<" y Palabra reservada" ;

			break;

		}

	}
}

else if(Estado== q4){


	cout <<"\n ["<<Cadena<< "] es: Numero Racional";


}else if(Estado==q5){





	int j;
	int TamanioArreglo=sizeof TablaOperando/ sizeof TablaOperando[0];
	for(j=0; j< TamanioArreglo; j++){
		if(Cadena.compare(TablaOperando[j])==0){

				cout <<"\n ["<<Cadena<< "] es: Operando";

			break;

		}

	}
}


else{

	cout << "\n Existe un error en: "<<Cadena;
	cout << " Programa detenido ";
	break;

}


if(Cadena=="fin"){

		cout << "\n\n Fin del programa"<<endl;

    break;


     }
 }
}
    fclose(fichero);

cout<<("\n\n********************************************************************");
cout<<("\n resumen de los elementos léxicos encontrados")<<endl;

guardar = fopen("elementos_léxicos.txt", "rb");
for (i =0 ;i<20;i++)
{
fscanf(guardar, "%s" , &textoExtraido[i]);

cout << "\n"<<	textoExtraido[i];
}

 fclose(guardar);



}
