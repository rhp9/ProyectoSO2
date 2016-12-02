/* Simple C program that connects to MySQL Database server*/
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <math.h>
#include "headers.h"



	char *username;


int main(int argC, char *argV[])
{	
	int entrada;
	char password="umin16";
	
	printf("\n\tBienvenido a la Biblioteca de la UMIN");
	printf("\n1) Si eres Alumno 2) Si eres Encargado\t");
	scanf("%i",&entrada);

	if(entrada == 1)
	{
		printf("\nEntra tu id de usuario:\t");
		scanf("%s",&username);

		if(connectionA(username)==1)
		{
			menuA();
		}
	}
	else
	{
		if(entrada == 2)
		{
			printf("\nEntra tu id de usuario:\t");
			scanf("%s",&username);

			if(connectionE(username)==1)
			{
				char *pass = getpass("Password: ");


				if(pass = password)
				{
					menu();
				}
				else
				{
					printf("Contraseña incorrecta\n");
					exit(1);
				}
			}
			

		}
		else{exit(1);}
	}

	return 0;
}


void menu()
{
	char opcion;
	int opcion2;
	int opcion3;
	int opcion4;
	int opcion5;
	int id;
	int x=1;
	int cant;
	char *sobra;

	printf("\nEscoge la opcion a desear");
	printf("\nA)Inserta Alumnos");
	printf("\nB)Consulta Alumnos");
	printf("\nC)Edita un Alumno");
	printf("\nD)Consulta libros");
	printf("\nE)Ingresa Libros");
	printf("\nF)Edita un Libro");
	printf("\nG)Ingresar un Prestamo");
	printf("\nH)Consulta un Prestamo");
	printf("\nI)Inserta Encargados");
	printf("\nJ)Consulta Encargados");
	printf("\nK)Edita un Encargados");
	printf("\nL)Inserta Ramas");
	printf("\nM)Consulta Ramas");
	printf("\nN)Edita un Ramas");
   printf("\n1)Salir\n");
	scanf("%s",&opcion);


	switch(opcion)
	{
		case 'a': 
			printf("\n\tInserta Alumnos");
			insertA();
			break;

		case 'b': 
		printf("\n\tConsulta Alumnos");
			selectA();
			break;

		case 'c': 
			    printf("\n\tSi deseas Editar escribe 1 ,Si deseas Eliminar escribe 2\n");
				scanf("%i",&opcion2);
				
					if(opcion2==1)
					{
						printf("\n\tEdicion Alumnos");
						printf("\nIngresa el ID del Alumno que desees editar \n");
						scanf("%i",&id);
						editA(id);
						break;
					}
					else
					{
						if(opcion2==2)
						{
							printf("\n\tEliminacion Alumnos");
							printf("\nIngresa el ID del Alumno que desees eliminar \n");
							scanf("%d",&id);
							deleteA(id);
							break;
						}
						else
						{
							printf("elige una opcion correcta\n");
							x=1;
						}
					}		

		case 'd': 
			selectL();
			break;

		case 'e': 
			printf("\n\tIngresa libros\n"); 
			insertL();
			break;

		case 'f': 
			printf("\n\tSi deseas Editar escribe 1 ,Si deseas Eliminar escribe 2\n");
				scanf("%i",&opcion3);
				
					if(opcion3==1)
					{
						printf("\n\tEdicion Libros");
						printf("\nIngresa el ID del Libro que desees editar \n");
						scanf("%i",&id);
						editL(id);
						break;
					}
					else
					{
						if(opcion3==2)
						{
							printf("\n\tEdicion Libros");
							printf("\nIngresa el ID del Libro que desees eliminar \n");
							scanf("%d",&id);
							deleteL(id);
							break;
						}
						else
						{
							printf("elige una opcion correcta\n");
							x=1;
						}
					}	
		
		case 'g': 
			printf("\n\tIngresa prestamo\n");
			insertP();
			break;

		case 'h': 
			printf("\n\tConsulta prestamo\n"); 
			selectP();
			break;	

		case 'i': 
			printf("\n\tInserta Encargados");
			insertE();
			break;

		case 'j': 
		printf("\n\tConsulta Encargados");
			selectE();
			break;

		case 'k': 
			    printf("\n\tSi deseas Editar escribe 1 ,Si deseas Eliminar escribe 2\n");
				scanf("%i",&opcion2);
				
					if(opcion4==1)
					{
						printf("\n\tEdicion Encargados");
						printf("\nIngresa el ID del Encargado que desees editar \n");
						scanf("%i",&id);
						editE(id);
						break;
					}
					else
					{
						if(opcion4==2)
						{
							printf("\n\tEliminacion Encargados");
							printf("\nIngresa el ID del Encargado que desees eliminar \n");
							scanf("%d",&id);
							deleteE(id);
							break;
						}
						else
						{
							printf("elige una opcion correcta\n");
							x=1;
						}
					}		

		case 'l': 
			printf("\n\tInserta Ramas");
			insertR();
			break;

		case 'm': 
		printf("\n\tConsulta Ramas");
			selectR();
			break;

		case 'n': 
			    printf("\n\tSi deseas Editar escribe 1 ,Si deseas Eliminar escribe 2\n");
				scanf("%i",&opcion2);
				
					if(opcion5==1)
					{
						printf("\n\tEdicion Encargados");
						printf("\nIngresa el ID de la Rama que desees editar \n");
						scanf("%i",&id);
						editR(id);
						break;
					}
					else
					{
						if(opcion5==2)
						{
							printf("\n\tEliminacion Encargados");
							printf("\nIngresa el ID de la Rama que desees eliminar \n");
							scanf("%d",&id);
							deleteR(id);
							break;
						}
						else
						{
							printf("elige una opcion correcta\n");
							x=1;
						}
					}			
		default: 
			exit(1);
	}
}

void menuA()
{
	char opcion;

	printf("\nEscoge la opcion a desear");
	printf("\nA)Consulta libros");
	printf("\nB)Solicita un Prestamo");
	printf("\nC)Consulta tus Prestamos");
    printf("\n1)Salir\n");
	scanf("%s",&opcion);


	switch(opcion)
	{
		case 'a': 
			printf("Select Books\n"); 
			break;

		case 'b': 
			printf("ingresa Prestamos\n"); 
			break;

		case 'c': 
			printf("consulta prestamos\n");
			break;

		default: 
			exit(1);
	}
}		