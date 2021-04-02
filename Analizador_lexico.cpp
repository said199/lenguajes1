#include <iostream>




using namespace std;

int main()
{
	char caracter ;
int i=0;

 char textoExtraido[200][200];

FILE *fichero;
   fichero= fopen("lenguaje.txt","rt");
  
     if (fichero==NULL) {// si fichero no falla coge un letra dle fichero
        cout << "Error al abrir el archivo lenguaje.txt"  <<  endl;

    } else {
    
    	
    	 for ( i = 0; i <200; i++)
    {

        	
        	 
fscanf(fichero, "%s" , &textoExtraido[i]);
 
       	 
string Cadena = textoExtraido[i];


   
string TablaSimbolos[9]={"mientras", "si", "sino", "fin","inicio", "entero", "racional", "entonces",
                          "imprima"};

enum TEstado{q0, q1, qe};

TEstado Estado;


int  Simbolo;

int i;
int longitud;

i= longitud=0;
Estado= q0;



longitud= Cadena.size();

while (longitud > i and Estado !=qe){
	Simbolo = Cadena[i];
	switch (Estado){
		case q0:
			if (Simbolo >= 'a' && Simbolo <='z'){
				Estado=q1;
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
	}
	i++;
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
else{
	cout << " Existe un error en: "<<Cadena;
	cout << " Programa detenido ";
	break;
	
}


 
if(Cadena=="fin"){
	
		cout << "\n\n Fin del programa";

    break;
    
    
     }
 }
}
    fclose(fichero);



}
