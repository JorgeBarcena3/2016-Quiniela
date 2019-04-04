#include <stdio.h>
#include <stdlib.h>
//JORGE BARCENA LUMBRERAS

int menu(){
	
	int opc = 3;
	
	do{//INICIO DEL CONTROL ERRORES
		
		
		system("cls");
		
		if(opc < 1 || opc > 3){ //EN CASO DE ERROR
			
			printf("ERROR: EL NUMERO INTRODUCIDO DEBE ESTAR ENTRE 1 y 3\n\n");
			
		}	
			
		printf("Bienvenido, que deseas hacer?\n\n");
		printf("1.- Introducir predicciones de partidos\n");
		printf("2.- Comprobar resultado de partidos\n");
		printf("3.- Salir\n\n");
		printf("Escoge una opcion:	");
		fflush(stdin); scanf("%i", &opc);
		
	}while(opc < 1 || opc > 3); //INICIO DEL CONTROL DE ERRORES
	
	return opc; //DEVUELVO AL MAIN LA OPCION ESCOGIDA.
	
}

void porcentajes(char partidos[5][14]){
	
	int i, j;
	float ganar = 0, perder = 0, empate = 0;
	
	for(i = 0; i <= 4; i++){
		
		ganar = perder = empate = 0;
		
		for(j = 0; j <= 14; j++){

			
			switch (partidos[i][j]){
				
				case '1':
					
					ganar++;
					
					break;
					
				case '2':
					
					perder++;
					
					break;
					
				case 'x':
					
					empate++;
					
					break;
					
				}
			
		
		}

		printf("JUGADOR %i\nVictorias: %.2f\nDerrotas: %.2f\nEmpates: %.2f\n\n", i+1 , (ganar * 100 / 15), (perder * 100 / 15), (empate * 100 / 15) );		
	}
	
}
	
void introducir_predicciones(char partidos[5][14]){
	
	int j, i;
	
	for(i = 0; i <= 4; i++){
		
		for(j = 0; j <= 14; j++){
			
			do{
			
				system("cls");
				printf("JUGADOR %i: introduce el resultado del partido %i: ", i+1 , j+1);
				fflush(stdin); partidos[i][j] = getche();
				system("cls");
				
			}while(partidos[i][j] != '1' && partidos[i][j] != '2' && partidos[i][j] != 'x');
		}
			
	}
	
	porcentajes(partidos);
	system("pause");
}

void comprobacion_finales ( char partidos [5][14]){
	
	int i, j;
	int aciertos = 0;
	
	system("cls");
	
	for(i = 0; i <= 4; i++){
		
		aciertos = 0;
		
		for(j = 0; j <= 14; j++){

			
			if(partidos[i][j] == partidos[5][j]){
				
				aciertos++;
				
			}

		}
	
		printf("JUGADOR %i\nHa acertado %i partidos\n\n", i+1 , aciertos );	
	
	}
	
}
		
void almacenar_resultados_rnd(char partidos [5][14]){

	int j, i;
	char aleatorio;
	int int_aleatorio;
	
	for(i = 5; i <= 5; i++){
		
		for(j = 0; j <= 14; j++){
			
				int_aleatorio = rand() % (2 - 0  + 1) + 0;
				
				switch (int_aleatorio) {
					
					case 0:
					
						aleatorio = 'x';
						break;
					
					case 1:
						
						aleatorio = '1';
						break;
						
					case 2:
						
						aleatorio = '2';
						break;
								
					
				}
				
				partidos[5][j] = aleatorio;

		
		}
			
	}
	
	comprobacion_finales(partidos);
	system("pause");

}
		
int main(int argc, char *argv[]) {
	
	char partidos [5][14]; //DECLARO UN ARRAY DE CADENAS PARA ALMACENAR TODOS LOS PARTIDOS
	int opc;
	
	
	
	do{
		
		opc = menu(); //LLAMO A LA FUNCION MENU, PARA ESCOJER UNA OPCION
	
		switch (opc) {
			
			case 1:
				
				introducir_predicciones(partidos);
				break;
				
			case 2: 
			
				almacenar_resultados_rnd(partidos); 
				break;
			
		}
		
		
	}while(opc != 3); //SI ES UN 3 SE ACABA EL PROGRAMA
	
	
	
	
	return 0;
}
