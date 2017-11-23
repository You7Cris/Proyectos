#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>


void Introduccion()
{
    system("color f1");
    printf("\t \t \t TABLAS DE DEPORTES \n\n");
    printf("Este es un programa que permite agregar 2 distintos deportes, de futbol y baloncesto\n");
    printf("permitiendo agregar todos los equipos de la liga y sus respectivas victorias, derrotas y\n");
    printf("\t  mucho mas, cada liga tendra un numero maximo de 2 equipos\n");
    printf("\n\n");
    printf("Presione una tecla para entrar en el menu....\n");
    getch();
    system("cls");
    menu();

}

struct futbol
{
	int numGolesFavor;
	int numGolesContra;
	int numGolesGoleador;
	char nombreGoleador[50];
};

struct baloncesto
{
	int balonPerdido;
	int balonRecogido;
	int numTriple;
	char triplero[50];
};

struct equipos
{
	int victorias;
	int empates;
	int derrotas;
	char nombreEquipo[50];
	struct futbol datosFutbol;
	struct baloncesto datosBalon;
}equiposFutbol[2],equiposBaloncesto[2];



int main()
{
	system("color f0");
    Introduccion();
    return 0;
}

void menu()
{
	int cantidad;
	int opcion_1;
	system("color f3");
	printf("\t\t***************************************************\n");
	printf("\t\t*                 MENU PRINCIPAL                  *\n");
	printf("\t\t***************************************************\n");
	printf("\t\t*                Escoga una opcion:               *\n");
	printf("\t\t*                1.)Menu Guardado                 *\n");
	printf("\t\t*              2.)Crear Nueva Tabla               *\n");
	printf("\t\t*                  3.)Salir                       *\n");
	printf("\t\t***************************************************\n");
	printf("\n\tOpcion: ");
	scanf("%i",&opcion_1);
	switch (opcion_1) {
		case 1:
		    system("cls");
		    system("color f5");
		    printf("\t\t******************************\n");
            printf("\t\t*      Escoga una opcion:    *\n");
            printf("\t\t*        1.)Futbol           *\n");
            printf("\t\t*       2.)Baloncesto        *\n");
            printf("\t\t******************************\n");
            printf("\n\tOpcion: ");
            scanf("%i",&opcion_1);
						switch (opcion_1)
						{
							case 1:
                                system("cls");
                                mostrar_equipos_futbol();
                                break;
							case 2:
                                system("cls");
                                mostrar_equipos_baloncesto();
                                break;
                            default:
                                printf("Error al ingresar\n");
                                printf("\n\nPresione una tecla para volver al menu...");
                                getch();
                                system("cls");
                                menu();
						}
            break;
		case 2:
		    system("cls");
		    printf("\t\t**************************************\n");
		    printf("\t\t*        CREACION DE TABLAS          *\n");
		    printf("\t\t**************************************\n");
		    printf("\t\t*         Eliga un deporte:          *\n");
		    printf("\t\t*             1.)Futbol              *\n");
		    printf("\t\t*            2.)Baloncesto           *\n");
		    printf("\t\t*           3.)Volver al Menu        *\n");
            printf("\t\t**************************************\n");
            printf("\t Opcion: ");
            scanf("%i",&opcion_1);
            int numEquipos;
                        switch(opcion_1)
						{
							case 1:
                                system("cls");
                                printf("Ingrese el numero de equipos de la Liga: \n");
                                scanf("%i",&numEquipos);
                                ingresarInformacionFutbol(numEquipos);
                                system("cls");
                                break;
							case 2:
                                system("cls");
                                printf("cuantos equipos tiene la liga\n");
                                scanf("%i",&numEquipos);
                                printf("-----\n");
                                ingresarInformacionBaloncesto(numEquipos);
                                system("cls");
                                break;
                            case 3:
                                system("cls");
                                menu();
                                break;
                            default:
                                printf("Error al ingresar\n");
                                printf("\n\nPresiona una tecla para volver al menu...");
                                getch();
                                system("cls");
                                menu();
						}
            break;
		case 3:
		    system("cls");
		    printf("\n\n\t\t Gracias por usarla..");
		    getch();
            system("cls");
            break;
        default:
            printf("Error al ingresar\n");
            printf("\n\nPresiona una tecla para volver al menu...");
            getch();
            system("cls");
            menu();

	}

}

void ingresarInformacionBaloncesto(int cantidad)
{
    int Total_Partidos=0;
    int partidos_Baloncesto=0;
	int mayorTriplero=0;
	int pos = 0;
	system("cls");
	struct equipos equiposBaloncestoUsuario[cantidad];
	int i,j;
	printf("Ingrese el numero total de partidos de la temporada: ");
	scanf("%i",&partidos_Baloncesto);
	system("color f2");
	for (i=0;i<cantidad;i++)
        {
            printf("\t\tEquipo Numero: %i\n",i+1);
            fflush(stdin);
            printf("\nIngrese el nombre del equipo: ");
            gets(equiposBaloncestoUsuario[i].nombreEquipo);
            fflush(stdin);
            printf("\nIngresa la cantidad de victorias: ");
            scanf("%i",&equiposBaloncestoUsuario[i].victorias);
            if(equiposBaloncestoUsuario[i].victorias>partidos_Baloncesto)
            {
                printf("El numero de victorias es mayor que el numero de partidos jugados de la temporada\n");
                printf("\n\nPresione para volver a ingresar...");
                getch();
                system("cls");
                i--;
            }else if(equiposBaloncestoUsuario[i].victorias<0)
            {
                printf("Error...\n");
                printf("\n\nPresione una tecla para volver a ingresar...");
                getch();
                system("cls");
                i--;
            }
            fflush(stdin);
            printf("\nIngresa la cantidad de derrotas: ");
            scanf("%i",&equiposBaloncestoUsuario[i].derrotas);
            if(equiposBaloncestoUsuario[i].derrotas<0)
            {
                printf("Error...\n");
                printf("\n\nPresione una tecla para volver a ingresar...");
                getch();
                system("cls");
                i--;
            }
            Total_Partidos=equiposBaloncestoUsuario[i].victorias+equiposBaloncestoUsuario[i].derrotas;
            if(Total_Partidos>partidos_Baloncesto)
            {
                printf("Error, el numero de partidos jugados es mayor que el numero total partidos\n");
                printf("\n\nPresione una tecla para volver a ingresar...");
                getch();
                system("cls");
                i--;
            }else if(Total_Partidos<partidos_Baloncesto)
            {
                printf("Error, el numero de partidos jugados es menor que el numero total de partidos\n");
                printf("\n\nPresione una tecla para volver a ingresar...");
                getch();
                system("cls");
                i--;
            }
            printf("\nIngrese el numero de veces que se perdio el balon: ");
            scanf("%i",&equiposBaloncestoUsuario[i].datosBalon.balonPerdido);
            if(equiposBaloncestoUsuario[i].datosBalon.balonPerdido<0)
            {
                printf("Error...\n");
                printf("\n\nPresione una tecla para volver a ingresar...");
                getch();
                system("cls");
                i--;
            }
            fflush(stdin);
            printf("\nIngrese la cantidad de rebotes recuperados: ");
            scanf("%i",&equiposBaloncestoUsuario[i].datosBalon.balonRecogido);
            if(equiposBaloncestoUsuario[i].datosBalon.balonRecogido<0)
            {
                printf("Error...\n");
                printf("\n\nPresione una tecla para volver a ingresar...");
                getch();
                system("cls");
                i--;
            }
            fflush(stdin);
            printf("\nIngrese la cantidad de triples del mayor triplero: ");
            scanf("%i",&equiposBaloncestoUsuario[i].datosBalon.numTriple);
            if(equiposBaloncestoUsuario[i].datosBalon.numTriple<0)
            {
                printf("Error...\n");
                printf("\n\nPresione una tecla para volver a ingresar...");
                getch();
                system("cls");
                i--;
            }
            fflush(stdin);
            printf("\nIngrese el Nombre del Triplero del equipo: ");
            gets(equiposBaloncestoUsuario[i].datosBalon.triplero);
            system("cls");
	}
	for (j=0;j<cantidad;j++)
	{
		printf("\t Informacion ingresada\n\n");
		printf("\tNombre del equipo #%i: %s\n",j+1,equiposBaloncestoUsuario[j].nombreEquipo);
		printf("\n\tCantidad de victorias: %i\n",equiposBaloncestoUsuario[j].victorias );
		printf("\n\tCantidad de derrotas: %i\n",equiposBaloncestoUsuario[j].derrotas );
		printf("\n\tCantidad de veces que se perdio el balon : %i\n",equiposBaloncestoUsuario[j].datosBalon.balonPerdido);
		printf("\n\tCantidad de rebotes recuperados: %i\n",equiposBaloncestoUsuario[j].datosBalon.balonRecogido);
		printf("\n\tCantidad de triples del tripleador: %i\n",equiposBaloncestoUsuario[j].datosBalon.numTriple);
		printf("\n\tNombre del triplero: %s\n",equiposBaloncestoUsuario[j].datosBalon.triplero);
		getch();
		system("cls");
		if (equiposBaloncestoUsuario[j].datosBalon.numTriple  > mayorTriplero)
		{
			mayorTriplero=equiposBaloncestoUsuario[j].datosBalon.numTriple;
			pos = j;
		}
	}
	printf("\n\n");
	printf("\t**********************************\n");
	printf("\t*		Listado de tripleadores    *\n");
	printf("\t**********************************\n");
	for (i =0;i<cantidad;i++)
	{
		printf("\tEquipo: %s triplero: %s cantidad de triples: %i\n",equiposBaloncestoUsuario[i].nombreEquipo);
		printf("\tTriplero: %s \n",equiposBaloncesto[i].datosBalon.triplero);
		printf("\tCantidad de Triples: %i \n",equiposBaloncestoUsuario[i].datosBalon.numTriple);
		printf("\n");
	}
	getch();
    system("color f4");
    printf("\tEl triplero de la liga es: %s  equipo: %s\n\tCantidad de triples [%i]\n",equiposBaloncestoUsuario[pos].datosBalon.triplero);
    printf("\tEquipo: %s \n",equiposBaloncestoUsuario[pos].nombreEquipo);
    printf("\tCantidad de Triples: %i \n",mayorTriplero);
    getch();
    printf("\n\n");
    system("color f0");
    printf("presiona para volver al menu principal....");
    getch();
    system("cls");
    menu();
}

void ingresarInformacionFutbol(int cantidad)
{
    int total_Partidos=0,partidos_Jugados=0;
	int mayorGoleador=0;
	int pos = 0;
	system("cls");
	struct equipos equiposFutbolUsuario[cantidad];
	int i,j;
	system("color f1");
	printf("\tIngrese el numero total de partidos de la temporada: ");
	scanf("%i",&total_Partidos);
	for (i=0;i<cantidad; i++)
        {
            printf("\t\t Equipo: %i\n\n",i+1);
            printf("\tPartidos Jugados: %i\n",total_Partidos);
            fflush(stdin);
            printf("\tIngrese el nombre del equipo: ");
            gets(equiposFutbolUsuario[i].nombreEquipo);
            fflush(stdin);
            printf("\tIngresa Numero de victorias: ");
            scanf("%i",&equiposFutbolUsuario[i].victorias);
            if(equiposFutbolUsuario[i].victorias>total_Partidos)
            {
                printf("\n\nEl numero de victorias es mayor que el numero total de partidos\n");
                printf("\nPresione una tecla para volver a ingresar...");
                getch();
                system("cls");
                i--;
            }
            fflush(stdin);
            printf("\tIngresa Numero de empates: ");
            scanf("%i",&equiposFutbolUsuario[i].empates);
            if(equiposFutbolUsuario[i].empates>total_Partidos)
            {
                printf("\n\nEl numero de empates es mayor que el numero total de partidos\n");
                printf("\nPresione una tecla para volver a ingresar...");
                getch();
                system("cls");
                i--;
            }
            fflush(stdin);
            printf("\tIngresa Numero de derrotas: ");
            scanf("%i",&equiposFutbolUsuario[i].derrotas);
            if(equiposFutbolUsuario[i].derrotas>total_Partidos)
            {
                printf("\n\nEl numero de empates es mayor que el numero total de partidos\n");
                printf("\nPresione una tecla para volver a ingresar...");
                getch();
                system("cls");
                i--;
            }
            partidos_Jugados=equiposFutbolUsuario[i].victorias+equiposFutbolUsuario[i].empates+equiposFutbolUsuario[i].derrotas;
            if(partidos_Jugados>total_Partidos)
            {
                printf("El numero de partidos jugados es mayor que el numero total de partidos de la temporada\n");
                printf("\n\nPresione una tecla para volver a ingresar....");
                getch();
                system("cls");
                i--;
            }else if(partidos_Jugados<total_Partidos)
            {
                printf("El numero de partidos jugados es menor que el numero total de partidos de la temporada\n");
                printf("\n\nPresione una tecla para volver a ingresar...");
                getch();
                system("cls");
                i--;
            }
            fflush(stdin);
            printf("\tIngrese Goles a favor: ");
            scanf("%i",&equiposFutbolUsuario[i].datosFutbol.numGolesFavor);
            if(equiposFutbolUsuario[i].datosFutbol.numGolesFavor<0)
            {
                printf("Error...\n");
                printf("\n\nPresione para volver a ingresar...");
                getch();
                system("cls");
                i--;
            }else if(equiposFutbolUsuario[i].datosFutbol.numGolesFavor<0 && equiposFutbolUsuario[i].victorias>0)
            {
                printf("Error, deberia tener al menos un gol a favor ya que gano un partido\n");
                printf("\n\nPresione para volver a ingresar...");
                getch();
                system("cls");
                i--;
            }
            fflush(stdin);
            printf("\tIngresa Goles en contra: ");
            scanf("%i",&equiposFutbolUsuario[i].datosFutbol.numGolesContra);
            if(equiposFutbolUsuario[i].datosFutbol.numGolesContra<0)
            {
                printf("Error...\n");
                printf("\n\nPresione para volver a ingresar...");
                getch();
                system("cls");
                i--;
            }
            fflush(stdin);
            printf("\tIngresa los goles del goleador: ");
            scanf("%i",&equiposFutbolUsuario[i].datosFutbol.numGolesGoleador);
            if(equiposFutbolUsuario[i].datosFutbol.numGolesGoleador>equiposFutbolUsuario[i].datosFutbol.numGolesFavor)
            {
                printf("Error, el numero de goles del goleador es mayor que el numero de goles a favor del equipo\n");
                printf("\n\nPresione para volver a ingresar...");
                getch();
                system("cls");
                i--;
            }else if(equiposFutbolUsuario[i].datosFutbol.numGolesGoleador<=0)
            {
                printf("Error...");
                printf("\n\nPresione para volver a ingresar...");
                getch();
                system("cls");
                i--;
            }
            fflush(stdin);
            printf("\tNombre del Goleador: ");
            gets(equiposFutbolUsuario[i].datosFutbol.nombreGoleador);
            system("cls");
	}
	printf("\t\t  INFORMACION REGISTRADA \n");
	for (j=0;j<cantidad;j++)
	{
		printf("\tNombre del equipo #%i : %s\n",j+1,equiposFutbolUsuario[j].nombreEquipo);
		printf("\tNumero de victorias: %i\n",equiposFutbolUsuario[j].victorias );
		printf("\tNumero de empates  : %i\n",equiposFutbolUsuario[j].empates );
		printf("\tNumero de derrotas : %i\n",equiposFutbolUsuario[j].derrotas );
		printf("\tNumero de goles a favor : %i\n",equiposFutbolUsuario[j].datosFutbol.numGolesFavor );
		printf("\tNumero de goles en contra: %i\n",equiposFutbolUsuario[j].datosFutbol.numGolesContra );
		printf("\tGoles del goleador : %i\n",equiposFutbolUsuario[j].datosFutbol.numGolesGoleador );
		printf("\tNombre del goleador : %s\n",equiposFutbolUsuario[j].datosFutbol.nombreGoleador);
		printf("\n\nPresione una tecla para seguir...");
		getch();
		system("cls");
		if (equiposFutbolUsuario[j].datosFutbol.numGolesGoleador  > mayorGoleador)
		{
			mayorGoleador    = equiposFutbolUsuario[j].datosFutbol.numGolesGoleador ;
			pos = i;
		}
	}
    fflush(stdin);
    int equipoGanador=0,pos2=0,puntosGanador=0;
	for(i=0;i<cantidad;i++)
	{
		if (equiposFutbolUsuario[i].victorias > equipoGanador)
		{
			equipoGanador = equiposFutbolUsuario[i].victorias;
			pos2=i;
		}
	}
	puntosGanador = (equiposFutbolUsuario[pos2].victorias *3) + equiposFutbolUsuario[pos2].empates;
	fflush(stdin);
	system("color f4");
	system("cls");
	fflush(stdin);
	fflush(stdin);
	printf("El equipo ganador es: %s \n",equiposFutbolUsuario[pos2].nombreEquipo);
	printf("Puntos: [%i]\n",puntosGanador);
	printf("El Pos: %i\n\n",pos);
	printf("El goleador de la liga es : %s \n\tCantidad de goles [%i]\n",equiposFutbolUsuario[pos-1].datosFutbol.nombreGoleador,mayorGoleador);
	fflush(stdin);
	printf("presiona para volver al menu principal...");
	getch();
	system("color f0");
	system("cls");
	menu();
}

void mostrar_equipos_futbol()
{
    int mayorGoleador=0;
    int pos = 0;
    system("cls");
    llenar_equipos_datosGuardados_futbol();
    int i , j;
    for (i = 0; i < 3; i++)
        {
            printf("\n");
            printf("\t Nombre: [%s] \n \n",equiposFutbol[i].nombreEquipo);
            printf(" Victorias: [%i] Empates: [%i] Derrotas: [%i]\n",equiposFutbol[i].victorias,equiposFutbol[i].empates,equiposFutbol[i].derrotas);
            printf("\n");
            printf("Goles a Favor: [%i]\n Goles en Contra: [%i]\n",equiposFutbol[i].datosFutbol.numGolesFavor,equiposFutbol[i].datosFutbol.numGolesContra);
            printf("Nombre del goleador: %s \nCantidad de goles [%i]\n\n",equiposFutbol[i].datosFutbol.nombreGoleador,equiposFutbol[i].datosFutbol.numGolesGoleador);
            printf("\nPresiona una tecla para continuar...\n");
            getch();
            system("cls");
            if (equiposFutbol[i].datosFutbol.numGolesGoleador > mayorGoleador)
					{
						mayorGoleador=equiposFutbol[i].datosFutbol.numGolesGoleador;
						pos = i;
					}

			}
	int equipoGanador=0,pos2=0,puntosGanador=0;
	for(i=0;i<3;i++)
	{
		if (equiposFutbol[i].victorias > equipoGanador)
		{
			equipoGanador = equiposFutbol[i].victorias;
			pos2=i;
		}
	}
	puntosGanador = (equiposFutbol[pos2].victorias*3)+equiposFutbol[pos2].empates;
    system("color f4");
    system("cls");
    printf("\tEl goleador de la liga es : %s \n\tCantidad de goles [%i]\n",equiposFutbol[pos].datosFutbol.nombreGoleador,mayorGoleador);
    printf("\n");
    printf("El equipo ganador es: %s con [%i] puntos\n",equiposFutbol[pos2].nombreEquipo,puntosGanador);
    printf("presione una tecla para ir al menu principar\n");
    getch();
    system("color f0");
    system("cls");
    menu();
}

void mostrar_equipos_baloncesto()
{
	int numTriples=0;
	int pos = 0;
	system("cls");
    llenar_equipos_datosGuardados_baloncesto();
    int i , j;
    for (i = 0; i <3	; i++)
			{
				printf("\n");
				printf("\t Nombre: [%s] \n \n",equiposBaloncesto[i].nombreEquipo);
				printf(" Victorias: [%i] Derrotas: [%i]\n",equiposBaloncesto[i].victorias,equiposBaloncesto[i].derrotas);
				printf("\n");
				printf("Numero de perdida del balon: [%i]\n",equiposBaloncesto[i].datosBalon.balonPerdido);
				printf("cantidad de rebotes recuperados [%i]\n",equiposBaloncesto[i].datosBalon.balonRecogido);
				printf("Nombre del mayor anotador de triples: %s, cantidad de triples: [%i]\n",equiposBaloncesto[i].datosBalon.triplero,equiposBaloncesto[i].datosBalon.numTriple);
				printf("\nPresiona una tecla para ver el siguiente equipo...\n");
				getch();
				system("cls");
				if (equiposBaloncesto[i].datosBalon.numTriple > numTriples)
				{
					numTriples = equiposBaloncesto[i].datosBalon.numTriple;
					pos ++;
				}
			}
                printf("\t\t*****************************************\n");
				printf("\t\t*	  Listado de tripleadores           *\n");
				printf("\t\t*****************************************\n");
				for (i =0;i<3;i++)
				{
					printf("\t\t Equipo: %s \n",equiposBaloncesto[i].nombreEquipo);
					printf("\tTriplero: %s \t  Cantidad de Triples: %i \n",equiposBaloncesto[i].datosBalon.triplero,equiposBaloncesto[i].datosBalon.numTriple);
					printf("\n\n");
				}
			getch();
			system("color f4");
			printf("\n");
			printf("\tEl tripleador de la liga es : %s del equipo: %s \n\tCantidad de triples [%i]\n",equiposBaloncesto[pos-1].datosBalon.triplero,equiposBaloncesto[pos-1].nombreEquipo,numTriples);
			printf("\n");
			printf("presione una tecla para ir al menu principar\n");
			getch();
			system("color f0");
			system("cls");
			menu();
}

void llenar_equipos_datosGuardados_futbol()

{
	fflush(stdin);
	strcpy(equiposFutbol[0].nombreEquipo,"America FC ");
	fflush(stdin);
	equiposFutbol[0].victorias = 10;
	fflush(stdin);
	equiposFutbol[0].empates   = 0;
	fflush(stdin);
	equiposFutbol[0].derrotas  = 10;
	fflush(stdin);
	equiposFutbol[0].datosFutbol.numGolesFavor = 11;
	fflush(stdin);
	equiposFutbol[0].datosFutbol.numGolesContra = 5;
	fflush(stdin);
	equiposFutbol[0].datosFutbol.numGolesGoleador = 9 ;
	fflush(stdin);
	strcpy(equiposFutbol[0].datosFutbol.nombreGoleador,"Juan Molina");
	fflush(stdin);
	fflush(stdin);
	strcpy(equiposFutbol[1].nombreEquipo,"Atletico Nacional FC ");
	fflush(stdin);
	equiposFutbol[1].victorias = 15;
	fflush(stdin);
	equiposFutbol[1].empates   = 5;
	fflush(stdin);
	equiposFutbol[1].derrotas  = 5;
	fflush(stdin);
	equiposFutbol[1].datosFutbol.numGolesFavor = 19;
	fflush(stdin);
	equiposFutbol[1].datosFutbol.numGolesContra = 9;
	fflush(stdin);
	equiposFutbol[1].datosFutbol.numGolesGoleador = 18;
	fflush(stdin);
	strcpy(equiposFutbol[1].datosFutbol.nombreGoleador,"Cristian Gonzalez");
	fflush(stdin);
	fflush(stdin);
	strcpy(equiposFutbol[2].nombreEquipo,"FC Cartago ");
	equiposFutbol[2].victorias = 0;
	fflush(stdin);
	equiposFutbol[2].empates   = 10;
	fflush(stdin);
	equiposFutbol[2].derrotas  = 10;
	fflush(stdin);
	equiposFutbol[2].datosFutbol.numGolesFavor = 8;
	fflush(stdin);
	equiposFutbol[2].datosFutbol.numGolesContra = 15;
	fflush(stdin);
	equiposFutbol[2].datosFutbol.numGolesGoleador = 6 ;
	fflush(stdin);
	strcpy(equiposFutbol[2].datosFutbol.nombreGoleador,"Juan David Galviz");
	fflush(stdin);
}

void llenar_equipos_datosGuardados_baloncesto()
{
	fflush(stdin);
	strcpy(equiposBaloncesto[0].nombreEquipo,"Houston");
	fflush(stdin);
	equiposBaloncesto[0].victorias = 7;
	fflush(stdin);
	equiposBaloncesto[0].derrotas  = 6;
	fflush(stdin);
	fflush(stdin);
	equiposBaloncesto[0].datosBalon.balonPerdido = 16;
	fflush(stdin);
	equiposBaloncesto[0].datosBalon.balonRecogido = 11;
	fflush(stdin);
	equiposBaloncesto[0].datosBalon.numTriple =  20;
	fflush(stdin);
	strcpy(equiposBaloncesto[0].datosBalon.triplero,"Edwin Lopez");
	fflush(stdin);
	fflush(stdin);
	strcpy(equiposBaloncesto[1].nombreEquipo,"Los Angeles");
	fflush(stdin);
	equiposBaloncesto[1].victorias = 10;
	fflush(stdin);
	equiposBaloncesto[1].derrotas  = 3;
	fflush(stdin);
	fflush(stdin);
	equiposBaloncesto[1].datosBalon.balonPerdido = 15;
	fflush(stdin);
	equiposBaloncesto[1].datosBalon.balonRecogido = 20;
	fflush(stdin);
	equiposBaloncesto[1].datosBalon.numTriple =  19;
	fflush(stdin);
	strcpy(equiposBaloncesto[1].datosBalon.triplero,"Jhon Alejandro Chugfi");
	fflush(stdin);
	fflush(stdin);
	strcpy(equiposBaloncesto[2].nombreEquipo,"Cartago");
	fflush(stdin);
	equiposBaloncesto[2].victorias = 5;
	fflush(stdin);
	equiposBaloncesto[2].derrotas  = 8;
	fflush(stdin);
	fflush(stdin);
	equiposBaloncesto[2].datosBalon.balonPerdido = 8;
	fflush(stdin);
	equiposBaloncesto[2].datosBalon.balonRecogido = 11;
	fflush(stdin);
	equiposBaloncesto[2].datosBalon.numTriple =  18;
	fflush(stdin);
	strcpy(equiposBaloncesto[2].datosBalon.triplero,"Carlos Arroyabe");
	fflush(stdin);
}
