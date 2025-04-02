#include<stdlib.h> /*Incluimos las Librerias*/
#include<stdio.h>
#include<conio.h>
#include<time.h> /*Incluimos la Librería <time.h>, para poder generar el número aleatorio que determinara el 1er Jugador (Podemos usar la funcion Time)*/
#include<string.h>
#include<ctype.h>

void IntrNum (char mat[3][3]); /*Declaramos los prototipos de las Funciones que usaremos*/
void tab (char mat[3][3]);
void Turno();
void partJvJ (char mat[3][3]);
void PosJvJ (char mat[3][3]);
void partJvC (char mat[3][3]);
void PosJ (char mat[3][3]);
void PosC (char mat[3][3]);
void partJvCNormal(char mat[3][3]);
void PosCNormal (char mat[3][3]);
void partJvCDificil (char mat[3][3]);
void PosCDificil (char mat[3][3]);
void PosAux(char mat[3][3]);
void PosAux1(char mat[3][3]);
void PosAux2(char mat[3][3]);
void PosAux3(char mat[3][3]);
void PosAux4(char mat[3][3]);
int win(char mat[3][3]);
void est();
void reg();

//Hecho por: Franco Rodríguez
//Realizado en Abril 2023

char nomb1[100], nomb2[100],jug1[100],jug2[100],jugX[100],jugO[100],nombC[]= "Computadora (O)"; /*Declaramos unas Cuentas Varibles globales, que nos ayudaran en varias Funciones*/
int opc,play,n=1,a,b,c,j,g,m;
float promX=0,promO=0,winX=0,winO=0,npart=0,emp=0,promE=0;
bool cic, ret;

int main(){
	int ram1,ram2; /*Declaramos las Varibles que usaremos en el main*/
	char mat[3][3];
	cic=false;
	
	printf ("######                                       ########      \n");
	printf ("#     #   ##   #    #  ###  ####          ####      ##  ## \n");
	printf ("#     #  #  #  ##   # #    #    #        ##           ##   \n");
	printf ("######  #    # # #  # #    #    #       ##     #####       \n");
	printf ("#       ###### #  # # #    #    #      ##     ##   ##      \n");
	printf ("#       #    # #   ## #    #    #     ####   ##     ##     \n");
	printf ("#       #    # #    #  ###  ####     ##  ##        ##      \n");
	printf ("                                    ################       \n");
	system ("timeout /t 2 /nobreak");
	
	do {
		system ("cls");
		printf (" ------------------------\n");
		printf ("| THE GAME OF %cLA VIEJA%c |\n", 34,34);
		printf (" ------------------------\n");
		
		printf ("\nSelecciona una Opci%cn:",162);
		printf ("\n(1) Jugador VS Jugador");
		printf ("\n(2) Jugador Vs Computadora");
		printf ("\n(3) Reglas");
		printf ("\n(4) Salir\n");
		scanf  ("%d",&opc);
		fflush(stdin);
	
		switch (opc) { /*Depende del valor de "opc" se ejecutara una serie de Acciones o no*/
		case 1:
			system ("cls");
			
			srand(time(NULL)); /*iniciamos el generador de numeros alatorios*/
	
			printf ("Vamos a Jugar %cLA VIEJA%c Jugador vs Jugador.-\n\n",34,34);
	
			printf ("%cCu%cl es el Nombre del Jugador 1?: ",168,160); /*Pedimos el Nombre del Jugador 1*/
			scanf ("%[^\n]",&nomb1); /*Guardamos el Nombre del Jugador 1 usando la Sintaxis "[^\n]" para almacenar X N° de carácteres hasta un Salto de Línea*/
			fflush(stdin); /*Usamos esta Instrucción para limpiar la memoria y evitar que se sobrepongan los datos*/

			ram1=rand()%6+1; /*Generamos un Número acotado del 1 hasta el 6 y el resultado se lo asignamos a esta variable*/
	
			printf ("%cCu%cl es el Nombre del Jugador 2?: ",168,160);
			scanf ("%[^\n]",&nomb2);
			fflush(stdin);
	
			ram2=rand()%6+1;
	
			do {
				if (ram1==ram2){ /*Si ram1 es igual a ram2 se vuelve a hacer el random*/
					ram1=rand()%6+1;
					ram2=rand()%6+1;
				}
		
				if (ram1>ram2){ /*El Primer Jugador sera aquel que tenga el Número más Alto*/
					printf ("\nEl Primer Jugador es: %s\n",&nomb1);
					strcat(nomb1, " (X)"); /*Añadimos al nomb1 (X) para evitar confusiones mas adelante*/
					strcat(nomb2, " (O)"); /*Añadimos al nomb2 (O) para evitar confusiones mas adelante*/
					strcpy( jug1, nomb1 ); /*Copiamos el valor de nomb1 a jug1 para mostrarlo mas adelante*/
					play=1; /*Identificador que nos ayudara mas adelante*/
				} else if (ram2>ram1){
					printf ("\nEl Primer Jugador es: %s\n",&nomb2);
					strcat(nomb1, " (O)");
					strcat(nomb2, " (X)");
					strcpy( jug1, nomb2 );
					play=2;
				}
			} while(ram1==ram2); /*El Bucle Termina cuando no sean Iguales, por lo que ya deberia de haber un Primer Jugador*/
	
			printf("\nPresiona enter para Empezar la Partida");
			getch();
			system ("cls");

			partJvJ (mat); /*Se llama a las Funciones que usaremos para el juego JvJ*/
		
			break;
		case 2:
			system ("cls");
			
			printf ("Vamos a Jugar %cLA VIEJA%c Jugador vs Computadora.-\n\n",34,34);
			printf ("%cCu%cl es el Nombre del Jugador 1?: ",168,160);
			scanf ("%[^\n]",&nomb1);
			fflush(stdin);
			strcat(nomb1, " (X)"); /*En este caso como es un Solo Jugador no se hace el Ramdon y directamente se le asigna (X)*/
			
			do{
				system ("cls");
				printf ("Selecciona una Dificultad:"); /*Le pedimos al usuario que escoja la dificultad, esto definira que funciones se usaran*/
				printf ("\n(1) F%ccil (Si pierdes, revisa %clas Reglas%c de nuevo)",160,34,34);
				printf ("\n(2) Normal (Entretenimiento para toda la Familia)");
				printf ("\n(3) Dif%ccil (JAJAJA Necesitas una estrategia para Ganar)\n",161);
				scanf  ("%d",&opc);
				fflush(stdin);
				
				switch (opc) {
				case 1:
					system ("cls");
					partJvC	(mat);
					ret=false;
					break;
				case 2:
					system ("cls");
					partJvCNormal (mat);
					ret=false;
					break;
				case 3:
					system ("cls");
					partJvCDificil (mat);
					ret=false;
					break;	
				default:
					printf ("\nEscoge una opci%cn correcta",162); /*Opcion default si no se selecciona una respuesta correcta*/
					system ("timeout /t 5");
					ret=true;	 /*Hacemos el valor de "ret" True para que se repita el bucle y regrese a la seleccion de dificultad*/
				}
			} while (ret!=false);
			break;
		case 3:
			system ("cls");
			printf ("----------------------\n");
			printf ("| Reglas de LA VIEJA |\n");
			printf ("----------------------\n");
			printf (" - Cada jugador tendr%c un %cnico s%cmbolo (X) o (O) que ser%c la ficha que usar%c en la partida.\n",160,163,161,160,160);
			printf (" - Se le pedira al usuario que ingrese el n%cmero de la casilla seg%cn el s%cmbolo (X) o (O).\n",163,163,161);
			printf (" - Cada jugador solo debe colocar su s%cmbolo una vez por turno y no debe ser sobre una casilla ya jugada.\n",161);
			printf (" - Se debe conseguir realizar una l%cnea recta o diagonal por s%cmbolo (X) o (O).\n",161,161);
			printf (" - El primer jugador que consiga marcar una l%cnea de tres s%cmbolos ser%c el ganador.\n",161,161,160);
			printf (" - En caso de que todas las casillas est%cn llenas y nadie haya marcado 3 en raya, ser%c un empate.\n",130,160);
			reg();	/*Se llama a la función del Retorno al Menú*/
			break;
		case 4:
			system ("cls"); /*Borramos la Pantalla*/
			printf ("Hasta la Pr%cxima...\n",162);
			cic=false;
			system ("timeout /t 5"); /*Cuenta regresiva para cerrar la Ventana*/
			break;
		default:
			printf ("\nEscoge una opci%cn correcta",162); /*Opcion default si no se selecciona una respuesta correcta*/
			system ("timeout /t 5");
			cic = true;	 /*Hacemos el valor de "cic" True para que se repita el bucle y regrese al menu*/
		}		
	} while (cic!=false); /*El valor de cic es false, pero por el trayecto se puede cambiar el valor y volver al menu*/
	
	return 0;
}

void partJvJ (char mat[3][3]){
	do{		
		m=0; /*Esta varible nos ayudara con el bucle de la partida e ira aumentando según se juegue*/
		cic=false; /*Esta Varible es la que nos permitira salir del bucle de jugar más partidas*/
		IntrNum(mat); /*Solo llamamos esta función una vez, ya que es la que le da valor al tablero*/
		do{
			system ("cls"); /*Limpiamos pantalla, cada vez que empieza el bucle, para mostrar el tablero actualizado*/
			tab(mat); /*Llamamos a la Función "Tab" que es la que muestra los valores actuales del tablero y se ira actualizando mediante siga el bucle*/
			PosJvJ(mat); /*Llamamos a esta Función que nos ayudara con las acciones en el tablero*/
			m++; /*Aumentamos el valor, cada vez que se repita el bucle, hasta llegar a 8, ya que estarían hechos los 9 movimiento máximos*/
			j=win(mat); /*El valor de la Función se le asignara a esta otra, normalmente esta en 2, pero si se hacen las condiciones para ganar cambia*/
			
		}while(m<=8 && j==2); /*Si se hacen los 9 movimientos Máximos sale del bucle o si se gana*/
		
		system ("cls"); /*Limpiamos Pantalla y Mostramos el estado final del tablero*/
		tab(mat);
		
		if(j==0){ /*Dependiendo de valor de "j" ganó X o ganó O o hubo un empate*/
			printf ("Gano el Jugador: %s",jug1);
			winX++; /*Guardamos el Número de Victorias de X, para las estadisticas*/
			strcpy( jugX, jug1 ); /*Copiamos el Nombre del jug1 actual en la variable jugX para las estadisticas*/
			Turno(); /*jug1 ahora sera O*/
			strcpy( jugO, jug1 ); /*entonces copiamos el nuevo valor de jug1 en el jugO*/
			Turno(); /*Volvemos a ejecutarla para dejarla como estaba antes*/
		}else if (j==1){
			printf ("Gano el Jugador: %s",jug1);
			winO++; /*Guardamos el Número de Victorias de O, para las estadisticas*/
			strcpy( jugO, jug1 );
			Turno();
			strcpy( jugX, jug1 );
			Turno();
		}else if (j==2){
			printf ("EMPATE XD");
			emp++; /*Guardamos el Número de Empates, para las estadisticas*/
		}
		npart++; /*Guardamos el Número de Partidas, para las estadisticas*/
		
		do{
			printf ("\n%cDeseas Jugar otra patida?\n",168); /*Depende de la respuesta saldrá o no del bucle*/
			ret=false;
			printf ("\n(1) Si");
			printf ("\n(2) No\n");
			scanf  ("%d",&opc);
			if (opc ==1){
				cic= true;
			} else if (opc ==2){
				cic= false;
			} else {
				printf ("\nEscoge una opci%cn correcta",162);
				ret = true;	
			}	
		} while (ret!=false);
	} while (cic!=false);
	
	if(winX==0 && winO==0){
		printf ("\nComo Nadie Ha Ganado no se pueden Mostrar las Estad%csticas Totales\n",161);
		printf ("Solamente las Partidas Jugadas, que ser%can: %.0f\n",161,npart);
	}else{
		est(); /*Se llama a la Funcion de las Estadisticas*/
	}
	reg(); /*Se llama a la Funcion del retorno al menu*/
}

void partJvC (char mat[3][3]){
	play=2; /*Le damos valor Par, ya que mas adelante nos ayudara a intercambiar turnos*/
	do{		
		m=0;
		cic=false;
		IntrNum(mat);
		do{
			if(play%2==0){ /*Como se Inicia en valor par entra directamente a aquí*/
			 	system ("cls"); /*Limipiamos Pantalla*/
				tab(mat);
				PosJ(mat); /*Llamamos a la Función del Jugador Solitario, que sera los movimientos de (X)*/
				system ("cls");
				tab(mat);
				j=win(mat);
				m++;
				if (m<=8 && j==2){ /*Mientras sea Empate o X no Gane se ejecutara lo del interior*/
					PosC(mat); /*Llamamos a la Funcion de los Movimientos de la Computadora*/
					j=win(mat);
					m++;	
				}
				/*Se aumenta el valor de "m" 2 veces y se le asigna el valor a "j" 2 veces, para evitar problemas con el bucle*/
				
			}else{ /*Si se juega de nuevo, la Computadora tendrá el Primer Turno*/
				system ("cls");
				tab(mat);
				PosC(mat);	/*Esta vez La computadora Empezara el Primer Juego*/
				system ("cls");
				tab(mat);
				j=win(mat);
				m++;
				if (m<=8 && j==2){
					PosJ(mat);
					j=win(mat);
					m++;
				}
			}
		}while(m<=8 && j==2);
		
		system ("cls");
		tab(mat);
		
		if(j==0){
			printf ("Gano el Jugador: %s",nomb1);
			winX++; /*Guardamos el Número de Victorias de X, para las estadisticas*/
			strcpy( jugX, nomb1 ); 
			strcpy( jugO, nombC );
		}else if (j==1){
			printf ("Gano el Jugador: %s",nombC);
			winO++; /*Guardamos el Número de Victorias de O, para las estadisticas*/
			strcpy( jugO, nombC );
			strcpy( jugX, nomb1 );
		}else if (j==2){
			printf ("EMPATE XD");
			emp++; /*Guardamos el Número de Empates, para las estadisticas*/
		}
		npart++; /*Guardamos el Número de Partidas, para las estadisticas*/
		play++; /*Varible que nos ayudara a la Rotacion de los Turnos de (X) y (O)*/
		
		do{
			printf ("\n%cDeseas Jugar otra patida?\n",168);
			ret=false;
			printf ("\n(1) Si");
			printf ("\n(2) No\n");
			scanf  ("%d",&opc);
			if (opc ==1){
				cic= true;
			} else if (opc ==2){
				cic= false;
			} else {
				printf ("\nEscoge una opci%cn correcta",162);
				ret = true;	
			}	
		} while (ret!=false);
	} while (cic!=false);
	
	if(winX==0 && winO==0){
		printf ("\nComo Nadie Ha Ganado no se pueden Mostrar las Estad%csticas Totales\n",161);
		printf ("Solamente las Partidas Jugadas, que ser%can: %.0f\n",161,npart);
	}else{
		est(); /*Se llama a la Funcion de las Estadisticas*/
	}
	reg(); /*Se llama a la Funcion del retorno al menu*/
}

void reg() { /*Esta Funcion nos ayudara para regresar o no al menu inicial*/
	do{
		printf ("\n%cDeseas Volver al Men%c?\n",168,163);
		ret=false;
		printf ("\n(1) Si");
		printf ("\n(2) No\n");
		scanf  ("%d",&opc);
		if (opc ==1){
			cic= true;
		} else if (opc ==2){
			cic= false;
			system ("cls"); /*Borramos la Pantalla*/
			printf ("Hasta la Pr%cxima...\n",162);
			system ("timeout /t 5"); /*Cuenta regresiva para cerrar la Ventana*/
		} else {
			printf ("\nEscoge una opci%cn correcta",162);
			ret = true;	
		}	
	} while (ret!=false);		
}

void IntrNum (char mat[3][3]){  /*Con esta Función lo que se va a hacer es darle valor a la Matriz 3x3*/
	int a,b; /*Se van a hacer 2 Bucles para darle los valores a la Matriz asi que deben de ser 2 variables*/
	char aux; /*La variable auxiliar nos ayudara a rellenar la matriz*/
	
	aux = '1'; /*Auxiliar va a empezar en 1, no en 0 para poder tener la matriz 1,2,3...9*/
	
	for(a=0;a<3;a++){ /*Iniciamos los Bucles que le daran el valor a la Matriz*/
		for(b=0;b<3;b++){
			mat[a][b]=aux++; /*Auxiliar va a ir aumentando mediante se repite el bucle*/
		}
	}
}

void Turno(){
	if(play%2==0){ /*Si el 2 Jugador es el que va Primero, se cumple lo que viene*/
		play--; /*Si 2 Jugador = 2, le restamos 1 para que la proxima vuelta sea falso*/
		strcpy( jug1, nomb2 ); /*Copiamos el Nombre del Jugador 2 a la variable para mostrarlo cuando se solicite*/
	}else{
		play++; /*Si 1 Jugador = 1, le sumamos 1 para que la proxima vuelta sea verdadero*/
		strcpy( jug1, nomb1 );
	}
}
		
void PosJvJ (char mat[3][3]){  /*Con esta Función Verificamos las Posiciones*/

	char pos;  /*Declaramos las Varibles que se usaran*/
		
	Turno(); /*Llamamos a la Función Turno, que determinara el valor de "jug1" y lo cambiara*/
	
	printf("Es Turno de: %s", jug1); /*Gracias al IF anterior mostramos el jugador del turno actual*/
	
	do{ /*2 Ciclos Do While que determinaran si la Posición está en el Rango Aceptado y/o Esta Ocupada*/
		do{
			printf("\n%cQu%c casilla jugar%cs?: ",168,130,160); /*Se le Pregunta al Jugador, donde va a poner la Figura*/
			fflush(stdin);
			scanf("%c",&pos);
			if (pos<'1' || pos>'9'){ /*Si la Posicion no esta en el Rango Aceptado, se devuelve y empieza denuevo*/
				printf("Posicion Incorrecta, intenta una del 1 al 9\n");
			}
		} while(pos<'1' || pos>'9'); /*Se toma solo el 1er Carácter, asi que si se introduce 897541 solo tomaría el 8*/
		
		c=0; /*Esta Variable nos ayudara a salir del bucle*/
		
		switch(pos){ /*Aqui compararemos las diversas posiciones de la Matriz*/
			case '1':
				b=0; /*Cambiando el valor de a y b asignamos el espacio de la matriz solicitado*/
				a=0;
				if (mat[a][b]=='X' || mat[a][b]=='O'){ /*Si la Posicion ya esta ocupada, muestra que hay un error y entra en un bucle*/
					c=1; /*La variable que nos ayuda a salir del bucle, le cambiamos el valor, para ir al inicio*/
					printf ("La Posicion ya esta Ocupada, Intenta otra\n\n");
				}
				break;
				
			case '2':
				b=1;
				a=0;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
					printf ("La Posicion ya esta Ocupada, Intenta otra\n\n");
				}
				break;			
				
			case '3':
				b=2;
				a=0;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
					printf ("La Posicion ya esta Ocupada, Intenta otra\n\n");
				}
				break;
				
			case '4':
				b=0;
				a=1;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
					printf ("La Posicion ya esta Ocupada, Intenta otra\n\n");
				}
				break;
				
			case '5':
				b=1;
				a=1;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
					printf ("La Posicion ya esta Ocupada, Intenta otra\n\n");
				}
				break;	
				
			case '6':
				b=2;
				a=1;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
					printf ("La Posicion ya esta Ocupada, Intenta otra\n\n");
				}
				break;	
			
			case '7':
				b=0;
				a=2;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
					printf ("La Posicion ya esta Ocupada, Intenta otra\n\n");
				}
				break;
			
			case '8':
				b=1;
				a=2;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
					printf ("La Posicion ya esta Ocupada, Intenta otra\n\n");
				}
				break;
				
			case '9':
				b=2;
				a=2;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
					printf ("La Posicion ya esta Ocupada, Intenta otra\n\n");
				}
				break;						
		}									
	} while (c==1);

	if(n%2==0){ /*La varible n esta inicia en 1 por lo cual va a ser Falso*/
		n--; /*Cuando se cumple, se le resta para que la proxima vuelta se falso*/
		mat[a][b] = 'O'; /*Como va a pasar en la 2da vuelta el jugador va a ser el 2do*/
	}else{
		n++; /*Como va a ser falso se suma 1 para que la proxima vez sea verdadero*/
		mat[a][b] = 'X'; /*Como va a pasar en la 1era vuelta el jugador va a ser el 1ero*/
	}
}

void partJvCNormal (char mat[3][3]){
	play=2; /*Le damos valor Par, ya que mas adelante nos ayudara a intercambiar turnos*/
	do{		
		m=0;
		cic=false;
		IntrNum(mat);
		do{
			if(play%2==0){ /*Como se Inicia en valor par entra directamente a aquí*/
			 	system ("cls"); /*Limipiamos Pantalla*/
				tab(mat);
				PosJ(mat); /*Llamamos a la Función del Jugador Solitario, que sera los movimientos de (X)*/
				system ("cls");
				tab(mat);
				j=win(mat);
				m++;
				if (m<=8 && j==2){ /*Mientras sea Empate o X no Gane se ejecutara lo del interior*/
					PosCNormal(mat); /*Llamamos a la Funcion de los Movimientos de la Computadora*/
					j=win(mat);
					m++;	
				}
				/*Se aumenta el valor de "m" 2 veces y se le asigna el valor a "j" 2 veces, para evitar problemas con el bucle*/
				
			}else{ /*Si se juega de nuevo, la Computadora tendrá el Primer Turno*/
				system ("cls");
				tab(mat);
				PosCNormal(mat); /*Esta vez La computadora Empezara el Primer Juego*/
				system ("cls");
				tab(mat);
				j=win(mat);
				m++;
				if (m<=8 && j==2){
					PosJ(mat);
					j=win(mat);
					m++;
				}
			}
		}while(m<=8 && j==2);
		
		system ("cls");
		tab(mat);
		
		if(j==0){
			printf ("Gano el Jugador: %s",nomb1);
			winX++; /*Guardamos el Número de Victorias de X, para las estadisticas*/
			strcpy( jugX, nomb1 ); 
			strcpy( jugO, nombC );
		}else if (j==1){
			printf ("Gano el Jugador: %s",nombC);
			winO++; /*Guardamos el Número de Victorias de O, para las estadisticas*/
			strcpy( jugO, nombC );
			strcpy( jugX, nomb1 );
		}else if (j==2){
			printf ("EMPATE XD");
			emp++; /*Guardamos el Número de Empates, para las estadisticas*/
		}
		npart++; /*Guardamos el Número de Partidas, para las estadisticas*/
		play++; /*Varible que nos ayudara a la Rotacion de los Turnos de (X) y (O)*/
		
		do{
			printf ("\n%cDeseas Jugar otra patida?\n",168);
			ret=false;
			printf ("\n(1) Si");
			printf ("\n(2) No\n");
			scanf  ("%d",&opc);
			if (opc ==1){
				cic= true;
			} else if (opc ==2){
				cic= false;
			} else {
				printf ("\nEscoge una opci%cn correcta",162);
				ret = true;	
			}	
		} while (ret!=false);
	} while (cic!=false);
	
	if(winX==0 && winO==0){
		printf ("\nComo Nadie Ha Ganado no se pueden Mostrar las Estad%csticas Totales\n",161);
		printf ("Solamente las Partidas Jugadas, que ser%can: %.0f\n",161,npart);
	}else{
		est(); /*Se llama a la Funcion de las Estadisticas*/
	}
	reg(); /*Se llama a la Funcion del retorno al menu*/
}

void partJvCDificil (char mat[3][3]){
	play=2; /*Le damos valor Par, ya que mas adelante nos ayudara a intercambiar turnos*/
	do{		
		m=0;
		cic=false;
		IntrNum(mat);
		do{
			if(play%2==0){ /*Como se Inicia en valor par entra directamente a aquí*/
			 	system ("cls"); /*Limipiamos Pantalla*/
				tab(mat);
				PosJ(mat); /*Llamamos a la Función del Jugador Solitario, que sera los movimientos de (X)*/
				system ("cls");
				tab(mat);
				j=win(mat);
				m++;
				if (m<=8 && j==2){ /*Mientras sea Empate o X no Gane se ejecutara lo del interior*/
					PosCDificil(mat); /*Llamamos a la Funcion de los Movimientos de la Computadora*/
					j=win(mat);
					m++;	
				}
				/*Se aumenta el valor de "m" 2 veces y se le asigna el valor a "j" 2 veces, para evitar problemas con el bucle*/
				
			}else{ /*Si se juega de nuevo, la Computadora tendrá el Primer Turno*/
				system ("cls");
				tab(mat);
				PosCDificil(mat); /*Esta vez La computadora Empezara el Primer Juego*/
				system ("cls");
				tab(mat);
				j=win(mat);
				m++;
				if (m<=8 && j==2){
					PosJ(mat);
					j=win(mat);
					m++;
				}
			}
		}while(m<=8 && j==2);
		
		system ("cls");
		tab(mat);
		
		if(j==0){
			printf ("Gano el Jugador: %s",nomb1);
			winX++; /*Guardamos el Número de Victorias de X, para las estadisticas*/
			strcpy( jugX, nomb1 ); 
			strcpy( jugO, nombC );
		}else if (j==1){
			printf ("Gano el Jugador: %s",nombC);
			winO++; /*Guardamos el Número de Victorias de O, para las estadisticas*/
			strcpy( jugO, nombC );
			strcpy( jugX, nomb1 );
		}else if (j==2){
			printf ("EMPATE XD");
			emp++; /*Guardamos el Número de Empates, para las estadisticas*/
		}
		npart++; /*Guardamos el Número de Partidas, para las estadisticas*/
		play++; /*Varible que nos ayudara a la Rotacion de los Turnos de (X) y (O)*/
		
		do{
			printf ("\n%cDeseas Jugar otra patida?\n",168);
			ret=false;
			printf ("\n(1) Si");
			printf ("\n(2) No\n");
			scanf  ("%d",&opc);
			if (opc ==1){
				cic= true;
			} else if (opc ==2){
				cic= false;
			} else {
				printf ("\nEscoge una opci%cn correcta",162);
				ret = true;	
			}	
		} while (ret!=false);
	} while (cic!=false);
	
	if(winX==0 && winO==0){
		printf ("\nComo Nadie Ha Ganado no se pueden Mostrar las Estad%csticas Totales\n",161);
		printf ("Solamente las Partidas Jugadas, que ser%can: %.0f\n",161,npart);
	}else{
		est(); /*Se llama a la Funcion de las Estadisticas*/
	}
	reg(); /*Se llama a la Funcion del retorno al menu*/
}

void PosJ (char mat[3][3]){  /*Con esta Función Verificamos la Posicion del Jugador Solitario*/
	int a,b,c; /*Declaramos las Varibles que se usaran*/
	char pos;
	
	printf("Es Turno de: %s", nomb1); /*El nombre no cambiara, asi que se pone directo el ingresado por el usuario*/
	
	do{ /*2 Ciclos Do While que determinaran si la Posicion esta en el Rango Aceptado y Esta Ocupada*/
		do{
			printf("\n%cQu%c Casilla Jugar%cs?: ",168,130,160); /*Se le Pregunta al Jugador, donde va a poner la Figura*/
			fflush(stdin);
			scanf("%c",&pos);
			if (pos<'1' || pos>'9'){ /*Si la Posicion no esta en el Rango Aceptado, se devuelve y empieza denuevo*/
				printf("Posicion Incorrecta, intenta una del 1 al 9\n");
			}
		} while(pos<'1' || pos>'9');
		
		c=0; /*Esta Variable nos ayudara a salir del bucle*/
		
		switch(pos){ /*Aqui compararemos las diversas posiciones de la Matriz*/
			case '1':
				b=0; /*Cambiando el valor de a y b asignamos el espacio de la matriz solicitado*/
				a=0;
				if (mat[a][b]=='X' || mat[a][b]=='O'){ /*Si la Posicion ya esta ocupada, muestra que hay un error y entra en un bucle*/
					c=1; /*La variable que nos ayuda a salir del bucle, le cambiamos el valor, para ir al inicio*/
					printf ("La Posicion ya esta Ocupada, Intenta otra\n\n");
				}
				break;
				
			case '2':
				b=1;
				a=0;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
					printf ("La Posicion ya esta Ocupada, Intenta otra\n\n");
				}
				break;			
				
			case '3':
				b=2;
				a=0;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
					printf ("La Posicion ya esta Ocupada, Intenta otra\n\n");
				}
				break;
				
			case '4':
				b=0;
				a=1;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
					printf ("La Posicion ya esta Ocupada, Intenta otra\n\n");
				}
				break;
				
			case '5':
				b=1;
				a=1;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
					printf ("La Posicion ya esta Ocupada, Intenta otra\n\n");
				}
				break;	
				
			case '6':
				b=2;
				a=1;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
					printf ("La Posicion ya esta Ocupada, Intenta otra\n\n");
				}
				break;	
			
			case '7':
				b=0;
				a=2;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
					printf ("La Posicion ya esta Ocupada, Intenta otra\n\n");
				}
				break;
			
			case '8':
				b=1;
				a=2;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
					printf ("La Posicion ya esta Ocupada, Intenta otra\n\n");
				}
				break;
				
			case '9':
				b=2;
				a=2;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
					printf ("La Posicion ya esta Ocupada, Intenta otra\n\n");
				}
				break;						
		}									
	} while (c==1);
	
	mat[a][b] = 'X'; /*Como solo se ejecutara con el Primero, no hay necesidad de intercambiar el valor a (O)*/
}		


void PosC (char mat[3][3]){ /*Con esta función verificamos la posición del Jugador Computador*/
	
	printf("Es Turno de: %s", nombC);
	do{ /*Un Ciclo Do While que determinara si la Posición Esta Ocupada*/

		opc=rand()%9+1; /*Se le asigna un numero ramdon entre el 1 y 9, que será la posición en la cual se pondrá (O)*/
		c=0;
		/*Como El Ramdon será entero no se puede usar como "Char" como se hizo anteriormente*/
		switch(opc){ /*Aqui compararemos las diversas posiciones de la Matriz*/
			case 1:
				b=0; /*Cambiando el valor de a y b asignamos el espacio de la matriz solicitado*/
				a=0;
				if (mat[a][b]=='X' || mat[a][b]=='O'){ /*Si la Posicion ya esta ocupada entra en un bucle*/
					c=1; /*La variable que nos ayuda a salir del bucle, le cambiamos el valor, para ir al inicio*/
				}
				break;
				
			case 2:
				b=1;
				a=0;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;			
				
			case 3:
				b=2;
				a=0;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;
				
			case 4:
				b=0;
				a=1;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;
				
			case 5:
				b=1;
				a=1;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;	
				
			case 6:
				b=2;
				a=1;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;	
			
			case 7:
				b=0;
				a=2;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;
			
			case 8:
				b=1;
				a=2;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;
				
			case 9:
				b=2;
				a=2;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;						
				}
	} while (c==1);
	
	mat[a][b] = 'O'; /*Computadora siempre sera (O)*/
	system ("timeout /t 3"); /*Una Pequeña cuenta regresiva, para simular que está preparando la Jugada*/
}

void PosAux(char mat[3][3]){ /*Las siguientes funciones auxiliares, ayudaran a la Computadora a bloquear una victoria de X o a Ganar uniendo 3*/
	if (mat[0][0]==mat[0][1] || mat[0][0]==mat[1][0] || mat[0][0]==mat[1][1] || mat[0][0]==mat[0][2] || mat[0][0]==mat[2][2] || mat[0][0]==mat[2][0] || mat[1][0]==mat[2][0] || mat[1][1]==mat[2][2] || mat[0][1]==mat[0][2]){ 
		/*Si alguna de estas posiciones son iguales, la computadora completara los 3 que necesita o bloqueara a X y no podra ganar*/
		if (g==0){ /*Este if me ayuda a lograr que todos se puedan ejecutar y no pongan varias fichas en un turno*/
			if (mat[0][0]==mat[0][1]){
				if (mat[0][2]!='O' && mat[0][2]!='X'){
					mat[0][2] = 'O';
					g=1;
				}
			}
		}
		
		if (g==0){
			if (mat[0][0]==mat[1][0]){
				if (mat[2][0]!='O' && mat[2][0]!='X'){
					mat[2][0] = 'O';
					g=1;	
				}	
			} 
		}
		
		if (g==0){
			if (mat[0][0]==mat[1][1]){
				if (mat[2][2]!='O' && mat[2][2]!='X'){
					mat[2][2] = 'O';
					g=1;
				}
			} 
		}
		
		if (g==0){
			if (mat[0][0]==mat[0][2]){
				if (mat[0][1]!='O' && mat[0][1]!='X'){
					mat[0][1] = 'O';
					g=1;
				}
			}
		}
		
		if (g==0){
			if (mat[0][0]==mat[2][2]){
				if (mat[1][1]!='O' && mat[1][1]!='X'){
					mat[1][1] = 'O';
					g=1;
				}
			}
		}
		
		if (g==0){
			if (mat[0][0]==mat[2][0]){
				if (mat[1][0]!='O' && mat[1][0]!='X'){
					mat[1][0] = 'O';
					g=1;
				}
			}
		}
		
		if (g==0){
			if (mat[0][1]==mat[0][2]){
				if (mat[0][0]!='O' && mat[0][0]!='X'){
					mat[0][0] = 'O';
					g=1;
				}
			}
		}
		
		if (g==0){
			if (mat[1][1]==mat[2][2]){
				if (mat[0][0]!='O' && mat[0][0]!='X'){
					mat[0][0] = 'O';
					g=1;
				}	
			} 
		}
		
		if (g==0){
			if (mat[1][0]==mat[2][0]){
				if (mat[0][0]!='O' && mat[0][0]!='X'){
					mat[0][0] = 'O';
					g=1;
				}
			}
		}
	}	
}

void PosAux1(char mat[3][3]){
	if (mat[0][1]==mat[2][1] || mat[0][1]==mat[1][1] || mat[2][1]==mat[1][1] ){
		if (g==0){
			if (mat[0][1]==mat[2][1]){
				if (mat[1][1]!='O' && mat[1][1]!='X'){
					mat[1][1] = 'O';
					g=1;
				}			
			}
		}
		
		if (g==0){
			if (mat[0][1]==mat[1][1]){
				if (mat[2][1]!='O' && mat[2][1]!='X'){
					mat[2][1] = 'O';
					g=1;	
				}				
			} 
		}
		
		if (g==0){
			if (mat[2][1]==mat[1][1]){
				if (mat[0][1]!='O' && mat[0][1]!='X'){
					mat[0][1] = 'O';
					g=1;	
				}	
			}
		}
	}
}

void PosAux2(char mat[3][3]){
	if (mat[0][2]==mat[1][2] || mat[0][2]==mat[2][2] || mat[0][2]==mat[1][1] || mat[0][2]==mat[2][0] || mat[2][0]==mat[1][1] || mat[2][2]==mat[1][2]){
		if (g==0){
			if (mat[0][2]==mat[1][2]){
				if (mat[2][2]!='O' && mat[2][2]!='X'){
					mat[2][2] = 'O';
					g=1;
				}		
			}
		}
		
		if (g==0){
			if (mat[0][2]==mat[2][2]){
				if (mat[1][2]!='O' && mat[1][2]!='X'){
					mat[1][2] = 'O';
					g=1;	
				}		
			}
		}
		
		if (g==0){
			if (mat[0][2]==mat[1][1]){
				if (mat[2][0]!='O' && mat[2][0]!='X'){
					mat[2][0] = 'O';
					g=1;	
				}				
			}
		}
		
		if (g==0){
			if (mat[0][2]==mat[2][0]){
				if (mat[1][1]!='O' && mat[1][1]!='X'){
					mat[1][1] = 'O';
					g=1;	
				}		
			}
		}
		
		if (g==0){
			if (mat[2][0]==mat[1][1]){
				if (mat[0][2]!='O' && mat[0][2]!='X'){
					mat[0][2] = 'O';
					g=1;
				}		
			}
		}
		
		if (g==0){
			if (mat[2][2]==mat[1][2]){
				if (mat[0][2]!='O' && mat[0][2]!='X'){
					mat[0][2] = 'O';
					g=1;
				}		
			}
		}
	}
}

void PosAux3(char mat[3][3]){
	if (mat[1][0]==mat[1][1] || mat[1][0]==mat[1][2] || mat[1][2]==mat[1][1] ){	
		if (g==0){		
			if (mat[1][0]==mat[1][1]){
				if (mat[1][2]!='O' && mat[1][2]!='X'){
					mat[1][2] = 'O';
					g=1;
				}		
			}
		}
		
		if (g==0){
			if (mat[1][0]==mat[1][2]){
				if (mat[1][1]!='O' && mat[1][1]!='X'){
					mat[1][1] = 'O';
					g=1;	
				}
			}
		}
		
		if (g==0){
			if (mat[1][2]==mat[1][1]){
				if (mat[1][0]!='O' && mat[1][0]!='X'){
					mat[1][0] = 'O';
					g=1;	
				}	
			}
		}
	}
}

void PosAux4(char mat[3][3]){
	if (mat[2][0]==mat[2][1] || mat[2][0]==mat[2][2] || mat[2][2]==mat[2][1] ){
		if (g==0){
			if (mat[2][0]==mat[2][1]){
				if (mat[2][2]!='O' && mat[2][2]!='X'){
					mat[2][2] = 'O';
					g=1;
				}
			}
		}
		
		if (g==0){
			if (mat[2][0]==mat[2][2]){
				if (mat[2][1]!='O' && mat[2][1]!='X'){
					mat[2][1] = 'O';
					g=1;	
				}				
			}
		}
		
		if (g==0){
			if (mat[2][2]==mat[2][1]){
				if (mat[2][0]!='O' && mat[2][0]!='X'){
					mat[2][0] = 'O';
					g=1;	
				}	
			}
		}
	}
}

void PosCNormal (char mat[3][3]){ /*Con esta función verificamos la posición del Jugador Computador*/
	
	printf("Es Turno de: %s", nombC);
	
	g=0; /*Esta variable nos ayudara a solo hacer 1 movimiento en el turno de la Computadora*/
					
	if (g==0){ /*Revisa las posibles casillas que hacen que X gane y evita esto*/
		if (mat[0][0]=='X' || mat[0][1]=='X' || mat[1][0]=='X' || mat[1][1]=='X' || mat[0][2]=='X' || mat[2][2]=='X' || mat[2][0]=='X' ){
			PosAux(mat);
		} 
	}			
	if (g==0){
		if (mat[0][1]=='X' || mat[1][1]=='X' || mat[2][1]=='X'){ 
			PosAux1(mat);
		}	
	}			 	
	if (g==0){
		if (mat[0][2]=='X' || mat[1][1]=='X' || mat[2][0]=='X' || mat[1][2]=='X' || mat[2][2]=='X'){ 
			PosAux2(mat);
		}	
	}	 	
	if (g==0){		
		if (mat[1][0]=='X' || mat[1][1]=='X' || mat[1][2]=='X'){ 
			PosAux3(mat);
		}	
	}	 		
	if (g==0){
		if (mat[2][0]=='X' || mat[2][1]=='X' || mat[2][2]=='X'){ 
			PosAux4(mat);
		}	
	}
			
	if (g==0){
		do{ /*1 Ciclo Do While que determinara si la Posición Esta Ocupada*/
		 	opc=rand()%9+1; /*Se le asigna un numero ramdon entre el 1 y 9, que será la posición en la cual se pondrá (O)*/
	 		c=0;
			 /*Como El Ramdon será entero no se puede usar como "Char" como se hizo anteriormente*/
			switch(opc){ /*Aqui compararemos las diversas posiciones de la Matriz*/
			case 1:
				b=0; /*Cambiando el valor de a y b asignamos el espacio de la matriz solicitado*/
				a=0;
				if (mat[a][b]=='X' || mat[a][b]=='O'){ /*Si la Posicion ya esta ocupada entra en un bucle*/
					c=1; /*La variable que nos ayuda a salir del bucle, le cambiamos el valor, para ir al inicio*/
				}
				break;
				
			case 2:
				b=1;
				a=0;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;			
				
			case 3:
				b=2;
				a=0;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;
				
			case 4:
				b=0;
				a=1;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;
				
			case 5:
				b=1;
				a=1;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;	
				
			case 6:
				b=2;
				a=1;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;	
			
			case 7:
				b=0;
				a=2;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;
			
			case 8:
				b=1;
				a=2;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;
				
			case 9:
				b=2;
				a=2;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;						
			}
		} while (c==1);
	
		mat[a][b] = 'O'; /*Computadora siempre sera (O)*/
	}
		
	system ("timeout /t 3"); /*Una Pequeña cuenta regresiva, para simular que está preparando la Jugada*/
}

void PosCDificil (char mat[3][3]){ /*Con esta función verificamos la posición del Jugador Computador*/
	
	printf("Es Turno de: %s", nombC);
	
	g=0; /*Esta variable nos ayudara a solo hacer 1 movimiento en el turno de la Computadora*/
	
	if (g==0){ /*Primero los movimientos que permitiran que O Gane. Usando las Funciones Auxiliares que declaramos antes*/
		if (mat[0][0]=='O' || mat[0][1]=='O' || mat[1][0]=='O' || mat[1][1]=='O' || mat[0][2]=='O' || mat[2][2]=='O' || mat[2][0]=='O'){
			PosAux(mat);
		}
	}
	if (g==0){
		if (mat[0][1]=='O' || mat[1][1]=='O' || mat[2][1]=='O'){
			PosAux1(mat);
		}
	}	
	if (g==0){
		if (mat[0][2]=='O' || mat[1][1]=='O' || mat[2][0]=='O' || mat[1][2]=='O' || mat[2][2]=='O'){ 
			PosAux2(mat);
		}	
	}	
	if (g==0){	
		if (mat[1][0]=='O' || mat[1][1]=='O' || mat[1][2]=='O'){ 
			PosAux3(mat);
		}	
	}			
	if (g==0){
		if (mat[2][0]=='O' || mat[2][1]=='O' || mat[2][2]=='O'){ 
			PosAux4(mat);
		}	
	}
					
	if (g==0){ /*Despues de revisar los movimientos que permitiran que O Gane. Si no hay forma de ganar, revisa las posibles casillas de X y no permite que esta gane*/
		if (mat[0][0]=='X' || mat[0][1]=='X' || mat[1][0]=='X' || mat[1][1]=='X' || mat[0][2]=='X' || mat[2][2]=='X' || mat[2][0]=='X' ){
			PosAux(mat);
		} 
	}			
	if (g==0){
		if (mat[0][1]=='X' || mat[1][1]=='X' || mat[2][1]=='X'){ 
			PosAux1(mat);
		}	
	}			 	
	if (g==0){
		if (mat[0][2]=='X' || mat[1][1]=='X' || mat[2][0]=='X' || mat[1][2]=='X' || mat[2][2]=='X'){ 
			PosAux2(mat);
		}	
	}	 	
	if (g==0){		
		if (mat[1][0]=='X' || mat[1][1]=='X' || mat[1][2]=='X'){ 
			PosAux3(mat);
		}	
	}	 		
	if (g==0){
		if (mat[2][0]=='X' || mat[2][1]=='X' || mat[2][2]=='X'){ 
			PosAux4(mat);
		}	
	}
			
	if (g==0){
		do{ /*1 Ciclo Do While que determinara si la Posicion Esta Ocupada*/
		 	opc=rand()%9+1; /*Se le asigna un numero ramdon entre el 1 y 9, que será la posición en la cual se pondrá (O)*/
	 		c=0;
			 /*Como El Ramdon será entero no se puede usar como "Char" como se hizo anteriormente*/
			switch(opc){ /*Aqui compararemos las diversas posiciones de la Matriz*/
			case 1:
				b=0; /*Cambiando el valor de a y b asignamos el espacio de la matriz solicitado*/
				a=0;
				if (mat[a][b]=='X' || mat[a][b]=='O'){ /*Si la Posicion ya esta ocupada entra en un bucle*/
					c=1; /*La variable que nos ayuda a salir del bucle, le cambiamos el valor, para ir al inicio*/
				}
				break;
				
			case 2:
				b=1;
				a=0;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;			
				
			case 3:
				b=2;
				a=0;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;
				
			case 4:
				b=0;
				a=1;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;
				
			case 5:
				b=1;
				a=1;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;	
				
			case 6:
				b=2;
				a=1;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;	
			
			case 7:
				b=0;
				a=2;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;
			
			case 8:
				b=1;
				a=2;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;
				
			case 9:
				b=2;
				a=2;
				if (mat[a][b]=='X' || mat[a][b]=='O'){
					c=1;
				}
				break;						
			}
		} while (c==1);
	
		mat[a][b] = 'O'; /*Computadora siempre sera (O)*/
	}
		
	system ("timeout /t 3"); /*Una Pequeña cuenta regresiva, para simular que está preparando la Jugada*/
}

void tab (char mat[3][3]){ /*Con esta Función lo que se va a hacer es mostrar los valores de la Matriz*/
	int a,b; /*Se van a hacer 2 Bucles para mostar los valores de la Matriz asi que deben de ser 2 variables*/

	printf (" ------------------------\n"); /*Mostramos el Encabezado del Juego, que no va a variar*/
	printf ("| THE GAME OF %cLA VIEJA%c |\n", 34,34);
	printf (" ------------------------\n");
	printf ("    _________________ \n");
	printf ("   |     |     |     |\n");
	
	for(a=0;a<3;a++){
		for(b=0;b<3;b++){
			if (b==0){ /*Con esta Condicion hacemos que la Parte Grafica del Juego no tenga unos Fallos*/
				printf("   |  %c  ",mat[a][b]);  /*Mostramos el valor de la Matriz del momento*/
			} else if (b==1){
				printf("|  %c  |",mat[a][b]);
			}else {
				printf("  %c  |",mat[a][b]);
			}
		}
		printf ("\n   |_____|_____|_____|\n");
		if (a<2){ /*Otra Condicion para que la Parte Grafica del Juego no tenga unos Fallos*/
				printf ("   |     |     |     |\n");
		}
	}
	
	printf("\n");
}

int win(char mat[3][3]){ /*Con esta Funcion lo que estamos haciendo es Validar el Resultado y Comprobar las Victorias*/
	if (mat[0][0]=='X' || mat[0][0]=='O'){ /*Validamos que si hay una X o Una O empieza a verficar las posiciones cercanas*/
			if (mat[0][0]==mat[0][1] && mat[0][0]==mat[0][2]){ /*Si se cumple que estas posiciones tienen el mismo valor, puede ser X u O*/
				if (mat[0][0] == 'X'){ /*Si vale X significa que en las 3 posiciones anteriores es igual, por lo que automaticamente ganan las X*/
					return 0; /*Regresamos un valor 0, que nos dira que las X ganaron*/
				} else { /*De lo Contrario seria O la que tiene las 3 posiciones Iguales, ganando automaticamente las O*/
					return 1; /*Regresamos un valor 1, que nos dira que las O ganaron*/
				}
			}
			if (mat[0][0]==mat[1][0] && mat[0][0]==mat[2][0]){
				if (mat[0][0]== 'X'){
					return 0;
				} else {
					return 1;
				}
			}
			if (mat[0][0]==mat[1][1] && mat[0][0]==mat[2][2]){
				if (mat[1][1]== 'X'){
					return 0;
				} else {
					return 1;
				}
			}	
		}
		if (mat[1][1] == 'X' || mat[1][1] =='O'){
			
			if (mat[1][0]==mat[1][1] && mat[1][0]==mat[1][2]){
				if (mat[1][1]== 'X'){
					return 0;
				}else{
					return 1;
				}
			}
			if (mat[1][1]==mat[2][0] && mat[1][1]==mat[0][2]){
				if (mat[1][1]== 'X'){
					return 0;
				}else{
					return 1;
				}
			}
			if (mat[1][1]==mat[0][1] && mat[1][1]==mat[2][1]){
				if (mat[1][1]== 'X'){
					return 0;
				}else{
					return 1;
				}
			}		
		}
		if (mat[2][2]== 'X' || mat[2][2]=='O'){
			if (mat[2][2]==mat[2][0] && mat[2][2]==mat[2][1]){
				if (mat[2][2]== 'X'){
					return 0;
				}else{
					return 1;
				}
			}
			if (mat[2][2]==mat[0][2] && mat[2][2]==mat[1][2]){
				if (mat[2][2]== 'X'){
					return 0;
				}else{
					return 1;
				}
			}	
		}
		
	return 2; /*Si Ninguna condicion se llegase a cumplir, se da por hecho que hay empate*/
}

void est(){
	system ("cls");
	printf ("----------------------------\n"); /*Mostramos el Encabezado de las estadísticas, que no va a variar*/
	printf ("| ESTAD%cSTICAS DE LA VIEJA |\n",214);
	printf ("----------------------------\n");
	
	printf ("\n - N%cmero de Partidas Jugadas: %.0f\n",163,npart); /*Con la variable del N de Partidas, lo mostramos*/
	printf (" - Victorias de %s: %.0f\n",jugX,winX); /*Con la variable del N de Partidas Ganadas por X, lo mostramos*/
	printf (" - Victorias de %s: %.0f\n",jugO,winO); /*Con la variable del N de Partidas Ganadas por O, lo mostramos*/
	printf (" - Empates: %.0f\n",emp); /*Con la variable del N de Partidas que quedaron en empate, lo mostramos*/
	
	promX=winX/npart; /*Calculamos el Promedio, dividiendo las victorias, por el numero de partidas en total*/
	promO=winO/npart;
	promE=emp/npart;
	
	printf (" - Porcentaje de Victorias de %s: %.2f\n",jugX,promX); /*Mostramos los Promedios Obtenidos con la operación anterior*/
	printf (" - Porcentaje de Victorias de %s: %.2f\n",jugO,promO);
	printf (" - Porcentaje de Empates: %.2f\n",promE);
	
	npart=0; /*Reiniciamos los valores de las Estadisticas, ya que se mostraran solo al final y asi no afecta si se juega otro modo de juego*/
	winX=0;
	winO=0;
	emp=0;
	promX=0;
	promO=0;
	promE=0;
}
