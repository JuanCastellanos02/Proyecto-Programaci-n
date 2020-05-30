#include <stdio.h>
#include <string.h>
#include <cctype>
///El Struct
struct Cliente{
	char numerocliente[50];
	char nombre[50];
	char email[50];
	char calle[50];
	char numerocasa[50];
	char postal[50];
	char colonia[50];
	char municipio[50];
	char estado[50];
	char pais[50];
}cliente[100];
////Funciones
void alta();


////Otras cosas
int salir=0,varstruct=0;
char opcion;

int main(){
	printf("Clientes de un Hotel");
	while(salir==0){
	printf("\nA. Alta de clientes\nB. Cambio de cliente\nC. Borrado de cliente\nD. Reportes de clientes\nE. Localizar cliente\nF. Manual de Usuario\nG. Salir\n\nOpcion:");
	_flushall();
	scanf("%c",&opcion);
	switch (opcion){
		case 'A': case 'a':
			alta();
			break;
		case 'B': case 'b':
			break;
		case 'C': case 'c':
			break;
		case 'D': case 'd':
			break;
		case 'E': case 'e':
			break;
		case 'F': case 'f':
			break;
		case 'G': case 'g':
			salir=1;
			break;
		default:
			printf("\nNo valido\n");
	varstruct++;
	}
}
	
}
//// Fin/Funciones
void alta(){
	int i,lon=0,dig=0,espacio=0;
	char cadena[50];
	while(lon==0 || dig==0){
		lon=1;
		dig=1;
		printf("\nIngrese el numero de cliente:");
		_flushall();
		scanf("%s",&cadena);
		if (strlen(cadena)<4 || strlen(cadena)>6){
			lon=0;
			printf("\nError, longitud erronea");
		}
		for(i=0;i<strlen(cadena);i++){
			if (isdigit(cadena[i])==0)
			dig=0;
		}
		if(dig==0)
		printf("\nError, solo ingrese numeros");
	}
	strcpy(cliente[varstruct].numerocliente,cadena);
	while(espacio==0){
		printf("\nIngrese el nombre del cliente:");
		_flushall();
		fgets(cadena, 50, stdin);
		for(i=0;i<strlen(cadena);i++){
		if(cadena[i]==' '){
		espacio++;
	}
		}
		if(espacio==0)
		printf("\nError, no hay espacios");
	}
	strcpy(cliente[varstruct].nombre ,cadena);
		////Copiamos la validación de correo
	int corr1=0,corr2=0,corr3=1,m,n,corr4=0,num;
	char *pch;
	while(corr1==0 || corr2==0 || corr3==0 || corr4==0){
		////Iniciamos las variables para validar correctamente cada ciclo
		corr1=0;
		corr2=0;
		corr3=1;
		corr4=0;
		////Verificamos la terminación
		printf("\nEscriba el correo:");
		scanf("%s",&cadena);
		 pch=strstr(cadena,".com");
		 if (pch!=NULL)
		 corr1=1;
		 pch=strstr(cadena,".net");
		 if (pch!=NULL)
		 corr1=1;
		 pch=strstr(cadena,".es");
		 if (pch!=NULL)
		 corr1=1;
		 pch=strstr(cadena,".mx");
		 if (pch!=NULL)
		 corr1=1;
		 /////Verificamos el sitio
		 pch=strstr(cadena,"@yahoo");
		 if (pch!=NULL)
		 corr2=1;
		 pch=strstr(cadena,"@outlook");
		 if (pch!=NULL)
		 corr2=1;
		 pch=strstr(cadena,"@hotmail");
		 if (pch!=NULL)
		 corr2=1;
		 pch=strstr(cadena,"@gmail");
		 if (pch!=NULL)
		 corr2=1;
		 ////Obtenemos la posicion de @ si es que existe, y la validamos
		 pch=strchr(cadena,'@');
		 n=pch-cadena;
		 if (n<17)
		 corr4=1;
		 ////Validamos las minusculas
		 for(m=0;m<n;m++){
		 	int num= cadena[m];
			if (num>122 || num<97)
			corr3=0;
		}
	}
	strcpy(cliente[varstruct].email ,cadena);
	///Direccion
	printf("\nIngrese Pais:");
	_flushall();
	fgets(cadena, 50, stdin);
	strcpy(cliente[varstruct].pais ,cadena);
	printf("\nIngrese Estado:");
	_flushall();
	fgets(cadena, 50, stdin);
	strcpy(cliente[varstruct].estado ,cadena);
	printf("\nIngrese Municipio:");
	_flushall();
	fgets(cadena, 50, stdin);
	strcpy(cliente[varstruct].municipio ,cadena);
	printf("\nIngrese Colonia:");
	_flushall();
	fgets(cadena, 50, stdin);
	strcpy(cliente[varstruct].colonia ,cadena);
	printf("\nIngrese Calle:");
	_flushall();
	fgets(cadena, 50, stdin);
	strcpy(cliente[varstruct].calle ,cadena);
	printf("\nIngrese Numero de casa:");
	_flushall();
	fgets(cadena, 50, stdin);
	strcpy(cliente[varstruct].numerocasa ,cadena);
	printf("\nIngrese Codigo postal:");
	_flushall();
	fgets(cadena, 50, stdin);
	strcpy(cliente[varstruct].postal ,cadena);
}
