/* Simple C program that connects to MySQL Database server*/
#include <mysql.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

	MYSQL *conn;
	MYSQL_RES *res;
	MYSQL_ROW row;

	char *server = "localhost";
	char *user = "root";
	char *password = "dcf91981"; /* set me first */
	char *database = "Biblioteca";
	char q[1024];

int connectionA(char username)
{
	

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,
			user, password, database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	sprintf(q,"Select * from Alumnos Where idAlumnos='%s'",&username);

		 /* send SQL query */
	if (mysql_query(conn,q ))
	{
			fprintf(stderr, "%s\n", mysql_error(conn));
			exit(1);
		
	}


	res = mysql_use_result(conn);

	while ((row = mysql_fetch_row(res)) != NULL)
		{
			
			if(row[0] = "username")
			{	
				printf("\tBienvenido\t %s\n",row[1]);
				return 1;
				break;
			}
			
		}

		printf("\n\tEste Usuario no existe");
		printf("\nEntra tu id de usuario:\t");
		scanf("%s",&username);
		connectionA(username);  
}

int connectionE(char username)
{
	

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,
			user, password, database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	sprintf(q,"Select * from Encargados Where idEncargados='%s'",&username);

		 /* send SQL query */
	if (mysql_query(conn,q ))
	{
			fprintf(stderr, "%s\n", mysql_error(conn));
			exit(1);
		
	}


	res = mysql_use_result(conn);

	while ((row = mysql_fetch_row(res)) != NULL)
		{
			
			if(row[0] = "username")
			{  
				printf("\tBienvenido\t %s\n",row[1]);
				return 1;
				break;
			}
			
		}

		printf("\n\tEste Usuario no existe");
		printf("\nEntra tu id de usuario:\t");
		scanf("%s",&username);
		connectionE(username);
}

void insertA() 
{
	char *Nombre[60];
	char *idUsers="";

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,
			user, password, database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	getchar();

	printf("Escribe el nombre: ");
	fgets(&Nombre,60,stdin);
	strtok(&Nombre, "\n");

	sprintf(q,"Insert into Alumnos (Nombre) values ('%s')",&Nombre);

	/* send SQL query */
	if (mysql_query(conn,q ) )
	{
			fprintf(stderr, "%s\n", mysql_error(conn));
			insertA();
	}

	int id = mysql_insert_id(conn);
	printf("\nEl Alumno %s con id %i fue guardado satisfactoriamente\n",&Nombre,id);
	printf("Recuerda guardar bien el id, es lo que te identifica en el sistema de la escuela\n");

	menu();

	res = mysql_use_result(conn);


	mysql_free_result(res);
	mysql_close(conn);
}

void selectA() 
{
	char *Nombre="";
	char *idUsers="";

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,
			user, password, database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	sprintf(q,"Select * from Alumnos");

	/* send SQL query */
	if (mysql_query(conn,q ) )
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}


	res = mysql_use_result(conn);

	 //output table name 
	printf("\n-------------------------------------\n");
	printf("| %15s | %15s |\n","id","Nombre");
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		printf("-------------------------------------\n");
		printf("| %15s | %15s |\n", row[0],row[1]);
	}

	menu();
	 
	mysql_free_result(res);
	mysql_close(conn);
}

void deleteA(int id) 
{

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,user, password, database, 0, NULL, 0))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

  sprintf(q,"delete from Alumnos where idAlumnos= '%i'",id);
		  
  
	/* send SQL query */
	if (mysql_query(conn,q ) )
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	printf("Alumno Eliminado");
	menu();
	res = mysql_use_result(conn);

	 
	mysql_free_result(res);
	mysql_close(conn);
}

void editA(int id) 
{
	char *Nombre[60];

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,user, password, database, 0, NULL, 0))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	printf("\n\tCon esta herramienta solo se puede editar el nombre del Alumno\n");
	getchar();
	printf("Escribe el nombre correcto: ");
	fgets(&Nombre,60,stdin);
	strtok(&Nombre, "\n");

  sprintf(q,"Update Alumnos SET Nombre= '%s' where idAlumnos= '%i'",&Nombre,id);
		  
	/* send SQL query */
	if (mysql_query(conn,q ) )
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	printf("Alumno Editado\n");
	menu();
	res = mysql_use_result(conn);

	 
	mysql_free_result(res);
	mysql_close(conn);
}

void selectL() 
{
	char *Nombre="";
	char *idUsers="";

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,
			user, password, database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	printf("\n\tEsta opcion te permite consultar libros por Rama\n");

	getchar();
	printf("Escribe el id de Rama: ");
	fgets(&Nombre,60,stdin);
	strtok(&Nombre, "\n");

	sprintf(q,"Select Libros.idLibros,Libros.Nombre,Libros.Autor,Libros.Cantidad,Rama.Nombre From Libros inner join Rama On Libros.Rama_idRama=Rama.idRama WHERE Libros.Rama_idRama='%s'",&Nombre);

	/* send SQL query */
	if (mysql_query(conn,q ) )
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}


	res = mysql_use_result(conn);

	 //output table name 
	printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");
	printf("| %3s | %20s | %20s | %8s | %10s |\n","id","Nombre","Autor","Cantidad","Rama");
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		printf("---------------------------------------------------------------------------------------------------------------------------------\n");
		printf("| %s | %s | %s | %8s | %s |\n", row[0],row[1],row[2],row[3],row[4]);
	}
	 
	 menu();
	mysql_free_result(res);
	mysql_close(conn);
}

void insertL() 
{
		
		char *Rama[60];
		char *Autor[60];
		char *Nombre[60];
		char *Cantidad[60];
    	conn = mysql_init(NULL);

		/* Connect to database */
		if (!mysql_real_connect(conn, server,
				user, password, database, 0, NULL, 0)) {
			fprintf(stderr, "%s\n", mysql_error(conn));
			exit(1);
		}
			getchar();
		

	  printf("Nombre :");
	  fgets(&Nombre,60,stdin);
	  strtok(&Nombre, "\n");

	  printf("Autor :");
	  fgets(&Autor,60,stdin);
	  strtok(&Autor, "\n");

	  printf("Cantidad :");
	  fgets(&Cantidad,60,stdin);
	  strtok(&Cantidad, "\n");

	  printf("id de la Rama: ");
	  fgets(&Rama,60,stdin);
	  strtok(&Rama, "\n");


		sprintf(q,"insert into Libros(Nombre,Autor,Cantidad,Rama_idRama) values ('%s','%s','%s','%s')",&Nombre,&Autor,&Cantidad,&Rama);

		
	  ///send SQL query 
		if (mysql_query(conn,q ) )
		{
			fprintf(stderr, "%s\n", mysql_error(conn));
			insertL();
		}

		int id = mysql_insert_id(conn);
		printf("\nEl Libro %s con id %i fue guardado satisfactoriamente\n",&Nombre,id);
		printf("Recuerda guardar bien el id\n");

		menu();
		res = mysql_use_result(conn);

		
		mysql_free_result(res);
		mysql_close(conn);
}

void deleteL(int id) 
{

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,user, password, database, 0, NULL, 0))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

  sprintf(q,"delete from Libros where idLibros= '%i'",id);
		  
  
	/* send SQL query */
	if (mysql_query(conn,q ) )
	{
		printf("El libro %i no se puede elimnar",&id);
		exit(1);
	}

	printf("Libro Eliminado\n");
	menu();
	res = mysql_use_result(conn);

	 
	mysql_free_result(res);
	mysql_close(conn);
}

void editL(int id) 
{
	char *Nombre[60];
	int opcion;

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,user, password, database, 0, NULL, 0))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	getchar();
	printf("\n\tQue Deseas Editar del libro\n");
	printf("\n1)Nombre");
	printf("\n2)Autor");
	printf("\n3)Rama");
	printf("\n4)Cantidad\n");
	scanf("%i",&opcion);

	switch(opcion)
	{
		case 1:
		getchar();
		printf("Escribe el nombre correcto: ");
		fgets(&Nombre,60,stdin);
		strtok(&Nombre, "\n");
		sprintf(q,"Update Libros SET Nombre= '%s' where idLibros= '%i'",&Nombre,id);

		case 2:
		getchar();
		printf("Escribe el autor correcto: ");
		fgets(&Nombre,60,stdin);
		strtok(&Nombre, "\n");
		sprintf(q,"Update Alumnos SET Autor= '%s' where idLibros= '%i'",&Nombre,id);

		case 3:
		getchar();
		printf("Escribe la Rama correcta: ");
		fgets(&Nombre,60,stdin);
		strtok(&Nombre, "\n");
		sprintf(q,"Update Libros SET Rama_idRama= '%s' where idLibros= '%i'",&Nombre,id);

		case 4:
		getchar();
		printf("Escribe la Cantidad correcta: ");
		fgets(&Nombre,60,stdin);
		strtok(&Nombre, "\n");
		sprintf(q,"Update Libros SET Cantidad= '%s' where idLibros= '%i'",&Nombre,id);


	}
	
		  
	/* send SQL query */
	if (mysql_query(conn,q ) )
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	
	printf("Libro Editado\n");
	menu();

	res = mysql_use_result(conn);

	 
	mysql_free_result(res);
	mysql_close(conn);
}

void insertP() 
{
	char *idLibros="";
	char *idUsers="";
	int cantidad;
	int cantidad2;
	int a;
	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,user, password, database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	getchar();
	
	printf("Escribe el id de Alumnos : ");
	fgets(&idUsers,60,stdin);
	strtok(&idUsers, "\n");

	printf("Escribe el id del Libro que desees pedir prestado : ");
	fgets(&idLibros,60,stdin);
	strtok(&idLibros, "\n");
	a=atol(&idLibros);

	cantidad=checkP(a);


	if(cantidad==0)
	{
		printf("Este Libro Ya esta Prestado, pide otro");

		Prestamo();
	}
	else
	{
		cantidad2=cantidad-1;
		editP(a,cantidad2);
		sprintf(q,"insert into Prestamo (Alumnos_idAlumnos,Libros_idLibros,FechaP,FechaE) values ('%s','%s',NOW(), DATE_ADD(NOW(), INTERVAL 1 WEEK))",&idUsers,&idLibros);

		insertP();
	}

	//send SQL query 
	if (mysql_query(conn,q ) )
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);	
	}
	
	int id = mysql_insert_id(conn);
	printf("\nEl Prestamo %i se creo Satisfactoriamente\n",id);
	printf("Recuerda guardar bien el id, es lo que te permitira saber cuando regresarlo\n");

	res = mysql_use_result(conn);
	menu();

	menu();
	res = mysql_use_result(conn);


}


int checkP(int id) 
{

	int a=0;

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,
			user, password, database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	sprintf(q,"Select * from Libros WHERE idLibros = '%i'",id);

	/* send SQL query */
	if (mysql_query(conn,q ) )
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}


	res = mysql_use_result(conn);

	 //output table name 
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		a= atol(row[3]);
		return a;
	}
	 
}


void editP(int id,int cant) 
{
	char *Nombre="";

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,user, password, database, 0, NULL, 0))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

  sprintf(q,"Update Libros SET Cantidad= '%i' where idLibros= '%i'",cant,id);
		  
	/* send SQL query */
	if (mysql_query(conn,q ) )
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}


	res = mysql_use_result(conn);
}

void selectP() 
{
	char *Nombre="";
	char *idUsers="";

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,
			user, password, database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	sprintf(q,"Select Prestamo.Alumnos_idAlumnos,Alumnos.Nombre,Prestamo.Libros_idLibros,Libros.Nombre,Prestamo.FechaP ,Prestamo.FechaE  from Prestamo inner join Alumnos on Prestamo.Alumnos_idAlumnos=Alumnos.idAlumnos inner join Libros on Prestamo.Libros_idLibros=Libros.idLibros");

	/* send SQL query */
	if (mysql_query(conn,q ) )
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}


	res = mysql_use_result(conn);

	 //output table name 
	printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("| %5s | %15s | %5s | %60s | %17s | %17s |\n","idA","Alumno","idL","Libro","Fecha de Prestamo","Fecha de Entrega");
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("| %5s | %15s | %5s | %60s | %17s | %17s |\n", row[0],row[1],row[2],row[3],row[4],row[5]);
	}
	 menu();
	mysql_free_result(res);
	mysql_close(conn);
}

void insertE() 
{
	char *Nombre="";
	char *idUsers="";

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,
			user, password, database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	getchar();
	printf("Escribe el nombre: ");
	fgets(&Nombre,60,stdin);
	strtok(&Nombre, "\n");

	

	sprintf(q,"Insert into Encargados(Nombre) values ('%s')",&Nombre);

	/* send SQL query */
	if (mysql_query(conn,q ) )
	{
			fprintf(stderr, "%s\n", mysql_error(conn));
			insertE();
	}

	int id = mysql_insert_id(conn);
	printf("\nEl Encargado %s con id %i fue guardado satisfactoriamente\n",&Nombre,id);
	printf("Recuerda guardar bien el id, es lo que te identifica en el sistema de la escuela\n");

	res = mysql_use_result(conn);
	menu();

	mysql_free_result(res);
	mysql_close(conn);
}

void selectE() 
{
	char *Nombre="";
	char *idUsers="";

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,
			user, password, database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	sprintf(q,"Select * from Encargados");

	/* send SQL query */
	if (mysql_query(conn,q ) )
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}


	res = mysql_use_result(conn);

	 //output table name 
	printf("\n-------------------------------------\n");
	printf("| %15s | %15s |\n","id","Nombre");
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		printf("-------------------------------------\n");
		printf("| %15s | %15s |\n", row[0],row[1]);
	}
	 menu();
	mysql_free_result(res);
	mysql_close(conn);
}

void deleteE(int id) 
{

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,user, password, database, 0, NULL, 0))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

  sprintf(q,"delete from Encargados where idEncargados= '%i'",id);
		  
  
	/* send SQL query */
	if (mysql_query(conn,q ) )
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	printf("Encargado Eliminado");

	res = mysql_use_result(conn);

	 menu();
	mysql_free_result(res);
	mysql_close(conn);
}

void editE(int id) 
{
	char *Nombre="";

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,user, password, database, 0, NULL, 0))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	getchar();
	printf("Escribe el nombre correcto: ");
	fgets(&Nombre,60,stdin);
	strtok(&Nombre, "\n");

  sprintf(q,"Update Encargados SET Nombre= '%s' where idEncargados= '%i'",&Nombre,id);
		  
	/* send SQL query */
	if (mysql_query(conn,q ) )
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	printf("Encargado Editado\n");

	res = mysql_use_result(conn);

	 menu();
	mysql_free_result(res);
	mysql_close(conn);
}

void insertR() 
{
	char *Nombre="";
	char *idUsers="";

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,
			user, password, database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	getchar();

	printf("Escribe el nombre: ");
	fgets(&Nombre,60,stdin);
	strtok(&Nombre, "\n");

	

	sprintf(q,"Insert into Rama(Nombre) values ('%s')",&Nombre);

	/* send SQL query */
	if (mysql_query(conn,q ) )
	{
			fprintf(stderr, "%s\n", mysql_error(conn));
			insertE();
	}

	int id = mysql_insert_id(conn);
	printf("\nLa Rama %s con id %i fue guardado satisfactoriamente\n",&Nombre,id);
	printf("Recuerda guardar bien el id, es lo que la identifica en el sistema de la escuela\n");

	res = mysql_use_result(conn);
	menu();

	mysql_free_result(res);
	mysql_close(conn);
}

void selectR() 
{
	char *Nombre="";
	char *idUsers="";

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,
			user, password, database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	sprintf(q,"Select * from Rama");

	/* send SQL query */
	if (mysql_query(conn,q ) )
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}


	res = mysql_use_result(conn);

	 //output table name 
	printf("\n-------------------------------------\n");
	printf("| %15s | %15s |\n","id","Nombre");
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		printf("-------------------------------------\n");
		printf("| %15s | %15s |\n", row[0],row[1]);
	}
	 menu();
	mysql_free_result(res);
	mysql_close(conn);
}

void deleteR(int id) 
{

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,user, password, database, 0, NULL, 0))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

  sprintf(q,"delete from Rama where idRama= '%i'",id);
		  
  
	/* send SQL query */
	if (mysql_query(conn,q ) )
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	printf("Rama Eliminada");

	res = mysql_use_result(conn);

	 menu();
	mysql_free_result(res);
	mysql_close(conn);
}

void editR(int id) 
{
	char *Nombre[60];

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,user, password, database, 0, NULL, 0))
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	getchar();

	printf("Escribe el nombre correcto: ");
	fgets(&Nombre,60,stdin);
	strtok(&Nombre, "\n");

  sprintf(q,"Update Rama SET Nombre= '%s' where idRama= '%i'",&Nombre,id);
		  
	/* send SQL query */
	if (mysql_query(conn,q ) )
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}

	printf("Rama Editada\n");

	res = mysql_use_result(conn);

	 menu();
	mysql_free_result(res);
	mysql_close(conn);

}

void verL() 
{
	char *Nombre="";
	char *idUsers="";

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,
			user, password, database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	printf("\n\tEsta opcion te permite consultar libros por Rama\n");

	getchar();
	printf("Escribe el id de Rama: ");
	fgets(&Nombre,60,stdin);
	strtok(&Nombre, "\n");

	sprintf(q,"Select Libros.idLibros,Libros.Nombre,Libros.Autor,Libros.Cantidad,Rama.Nombre From Libros inner join Rama On Libros.Rama_idRama=Rama.idRama WHERE Libros.Rama_idRama='%s'",&Nombre);

	/* send SQL query */
	if (mysql_query(conn,q ) )
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}


	res = mysql_use_result(conn);

	 //output table name 
	printf("\n---------------------------------------------------------------------------------------------------------------------------------\n");
	printf("| %3s | %20s | %20s | %8s | %10s |\n","id","Nombre","Autor","Cantidad","Rama");
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		printf("---------------------------------------------------------------------------------------------------------------------------------\n");
		printf("| %s | %s | %s | %8s | %s |\n", row[0],row[1],row[2],row[3],row[4]);
	}
	 
	 menuA();
	mysql_free_result(res);
	mysql_close(conn);
}

void Prestamo() 
{
	char *idLibros="";
	char *idUsers="";
	int cantidad;
	int cantidad2;
	int a;
	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,user, password, database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	getchar();
	
	printf("Escribe tu id de Alumnos : ");
	fgets(&idUsers,60,stdin);
	strtok(&idUsers, "\n");

	getchar();
	printf("Escribe el id del Libro que desees pedir prestado : ");
	fgets(&idLibros,60,stdin);
	strtok(&idLibros, "\n");
	a=atol(&idLibros);

	cantidad=checkP(a);
	

	if(cantidad==0)
	{
		printf("Este Libro Ya esta Prestado, pide otro");
		Prestamo();
	}
	else
	{
		cantidad2=cantidad-1;
		editP(a,cantidad2);
		sprintf(q,"insert into Prestamo (Alumnos_idAlumnos,Libros_idLibros,FechaP,FechaE) values ('%s','%s',NOW(), DATE_ADD(NOW(), INTERVAL 1 WEEK))",&idUsers,&idLibros);
	}

	//send SQL query 
	if (mysql_query(conn,q ) )
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);	
	}
	
	int id = mysql_insert_id(conn);
	printf("\nEl Prestamo %i se creo Satisfactoriamente\n",id);
	printf("Recuerda guardar bien el id, es lo que te permitira saber cuando regresarlo\n");
	res = mysql_use_result(conn);
	menuA();
}

void verP() 
{
	char *Nombre="";
	char *idUsers[60];

	conn = mysql_init(NULL);

	/* Connect to database */
	if (!mysql_real_connect(conn, server,
			user, password, database, 0, NULL, 0)) {
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}
	getchar();

	printf("Escribe tu id de Usuarios: ");
	fgets(&idUsers,60,stdin);
	strtok(&idUsers, "\n");

	sprintf(q,"Select Prestamo.Alumnos_idAlumnos,Alumnos.Nombre,Prestamo.Libros_idLibros,Libros.Nombre,Prestamo.FechaP ,Prestamo.FechaE  from Prestamo inner join Alumnos on Prestamo.Alumnos_idAlumnos=Alumnos.idAlumnos inner join Libros on Prestamo.Libros_idLibros=Libros.idLibros WHERE Prestamo.Alumnos_idAlumnos= '%s'",&idUsers);

	/* send SQL query */
	if (mysql_query(conn,q ) )
	{
		fprintf(stderr, "%s\n", mysql_error(conn));
		exit(1);
	}


	res = mysql_use_result(conn);

	 //output table name 
	printf("\n------------------------------------------------------------------------------------------------------------------------------------------\n");
	printf("| %5s | %15s | %5s | %35s | %10s | %10s |\n","idA","Alumno","idL","Libro","Fecha de Prestamo","Fecha de Entrega");
	while ((row = mysql_fetch_row(res)) != NULL)
	{
		printf("------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("| %s | %s | %s | %s | %s | %s |\n", row[0],row[1],row[2],row[3],row[4],row[5]);
	}
	 menuA();
	mysql_free_result(res);
	mysql_close(conn);

}