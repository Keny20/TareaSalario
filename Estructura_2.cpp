//Hecho por:
//Keny Lisbeth Chavez Torres---CT18009

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <ctype.h>

using namespace std ;

struct empleado { //estructura 1
/*En esta estructura se tomaran los datos del empleado*/
	char cod [5] ;
	string nombre;
	int edad ;
	float salBase ;
	float salLiquido ;
	float isss ;
	float afp ;
	float renta ;
	float totalPrestamo ;
	string departamento;
	string puesto;	
	
} ;

struct sucursal { //estructura 2
/*Simplemente se agregaran pequeños datos de la sucursal*/
	int numSucursal ; 
	string nomSucursal; 
};

/*funcion para el calculo del ISSS del salario del empleado*/
float calIsss (float sal, float tope)
{
	float isss = 0 ;
	/*Si el salario del empleado es mayor o igual a 1000 se le aplica el 30%
	y si es menor solo se le aplica el 3%*/
	if (sal >= 1000) 
		isss=sal * 0.30 ;
	else 
		isss=sal*0.03 ;
return isss ; //retorna el valor de la variable isss
}

/*funcion para el calculo del AFP del salario del empleado*/
float calAfp (float sal)
{
	float afp = 0 ;
	afp = sal * 0.0725 ;
	return afp ; //retorna el valor de la variable afp	
}

/*funcion para el calculo de la renta del salario del empleado 
basandose con el total del ISSS y el AFP*/
float calRenta (float sal, float isss, float afp )
{
	
 	float renta = 0 ;
 	//se resta al salario la suma del afp y el isss
 	renta = (sal - isss + afp) ;
 	/*Se hacen las condiciones para la renta, dependiendo de ello se le resta
 	el salario en exceso luego se multiplica el porciento que le corresponde
	 y se le suma la cuota fija*/
	 
 	if (renta >= 0.01 && renta <= 472)
	 renta = 0;
	 else if (renta >= 472.01 && renta <= 895.24)	
	 renta = (renta - 472.00) * 0.1 +17.67  ; 
	 else if (renta >= 895.25 && renta <= 2038.10)	
	 renta = (renta - 895.24) * 0.2 + 60.00  ;
	 else if (renta >= 2038.11 )
	 renta = (renta - 2038.10) * 0.3 + 288.57  ;
	 
 return renta ; //retorna el valor de la variable renta
}

/*Validacion que permite al usuario no ingresar
letras donde corresponden numeros*/
int validacion(){
	int var ;
	while (cin.fail() ){
    cin.clear() ;
    cin.ignore(1000, '\n') ;
    cout << "Has introducido un dato incorrecto, vuelve a intentarlo" << endl ;
   
	}
	return var ; //retorna el valor de la variable
}

void a() ; /*ejecuta--- declaracion de funcion no retorna/no resibe ningun valor*/

/*Se crea una validacion para que los datos de letra no acepten numeros*/
string validacion_text_only(string texto){
	
	string nombre;
	int i = 0;
	bool bandera = true; //retorna un valor verdadero
	/*la funcion se repite hasta que la variable bandera sea verdadero*/
	do{
			cout << texto << endl ;
			cin >> nombre ; //lectura de variable desde la estructura
			
				while(nombre[i]){
					if(isalpha(nombre[i])){ /*isalpha solo pemite caracteres de letras, no simbolos ni numeros*/
					
					}else{
						
						cout<<"Dato no valido"<<endl;
						bandera = true;
						break;
					}
					i++;
					bandera = false;
				}
		}while(bandera);
		
		return nombre;
	
}

//inicio de el programa
int main (){
	
	bool bandera = true ;
	int i =0;
	int n ; //variable para el ingreso de cantidad de empleados
	a(); //llamada de funcion
	
	sucursal s ;//llamada de estructura numero 2
	
	/*Primero se pedira el ingreso del nombre de la sucursal
	luego el numero y ese dato se guardara y se mostrara de ultimo*/
	system("color 71"); //color de pantalla
	cout << "SUCURSAL" << endl ;
		
		s.nomSucursal = validacion_text_only("Ingrese el nombre de la sucursal"); //llamada de funcion
		
		/*se crea un ciclo repetitivo llamando funcion de validacion
		y para que se repita mientras ingresen un numero menor o igual
		a cero*/
		do {
			validacion(); //llamada de funcion
			cout << "Numero de sucursal: " << endl ;
		cin >> s.numSucursal ;//lectura de variable desde la estructura
	}while(s.numSucursal<=0) ;//condicion
		
		a(); //llamada de funcion
		system("color b1"); //color de pantalla
		
		
		//seguidamente se pediran los datos del empleado
		
	cout << "DATOS DE EMPLEADOS" << endl ;
	
	/*se crea un ciclo repetitivo llamando funcion de validacion
		y para que se repita mientras ingresen un numero menor o igual
		a cero*/
		do {
		validacion () ; //llamada de funcion
	cout << "Cuantos empleados tiene?" << endl ;
	cin >> n ; //lectura de variable
	}while (n <= 0) ; //condicion
	
	
	empleado e [n];
	int canPres ; //cantidad de prestamo
	int contador ; //contador para los prestamos
	
	//inicio de ciclo para los datos
	for (int i = 0 ; i < n ; i++)
	{
		cout << "Dato # " << i+1 << endl ; 
		
		cout << "Codigo:" << endl ;
		cin >> e [i].cod ; //lectura de variable desde la estructura
		
						
				cout << "Nombre:" <<endl ;
				//llamada de funcion
			e[i].nombre = validacion_text_only("Ingrese el nombre del Empleado: ") ; //lectura de variable desde la estructura

				
	
		/*se crea un ciclo repetitivo llamando funcion de validacion
		y para que se repita mientras ingresen un numero que sea menor a 18 o mayor a 70
		*/
		do{	
		validacion ();
		cout << "Edad:" << endl ;
		cin >> e [i].edad ; //lectura de variable desde la estructura
		a(); //llamada funcion	
	}while (e [i].edad <18 || e [i].edad >70 ) ; //condicion
		
		
		cout << "Departamento: " << endl ;
		//llamada de funcion
		e[i].departamento = validacion_text_only("Ingrese el departamento: "); //lectura de variable desde la estructura
		fflush (stdin) ; //espacio en el texto
		//llamada de funcion
		cout << "Puesto: " << endl ;
		e[i].puesto = validacion_text_only("Ingrese el Puesto: "); //lectura de variable desde la estructura
		fflush (stdin) ; //espacio en el texto
		a();//llamada funcion
		
		
		//ingreso de salario
		do {
		validacion (); //llamada funcion
		cout << "Salario Base:" << endl ;
		cin >> e [i].salBase; //lectura de variable desde la estructura
		e[i].isss = calIsss (e [i].salBase, 0.03); //llamada de funcion para el calculo del ISSS
		e[i].afp = calAfp (e[i].salBase);//llamada de funcion para el calculo del AFP
		e[i].renta = calRenta (e[i].salBase, e[i].isss,e[i].afp) ; //llamada de funcion para el calculo de la RENTA
		a(); //Llamada de funcion
		} while (e [i].salBase <= 0); //condicion
		
		
		//cotizacin de prestamo
		/*Validando que si el prestamo es mayor o igual a 5 no se le puede dar prestamo*/
		cout <<"Cantidad de prestamo del empleado:"<<endl;
		cin >>canPres; //lectura de variable
		//contador=0; //inicializado en cero
		
		if (canPres >=5){ //condicion
			cout <<"No se le puede acreditar prestamo"<<endl<<endl;
			e[i].totalPrestamo=0;
		}
		
		else {//si es menor de 5 se pide el monto del prestamo
		float pres; //prestamo
		float totPres=0; //total de prestamo
		canPres = 0;
		contador = 0;
		//ciclo para el contador
		while(contador <= canPres )
		 {
		 	
		 	cout <<"Ingrese el monto del prestamo:"<<endl;
			cin >>pres; //lectura de variable
			/*se condicion que si el total de el salario es aceptable 
			al prestamo solicitado se le brindara*/
			if (e [i].salBase*0.2 > (totPres + pres))
			{
				totPres = totPres + pres ;
				e[i].totalPrestamo=totPres + pres;
			}
			contador ++ ;//el contador incrementa
		}
	}	
}	

	system("color 71"); //color
	/*Muestra de los datos de  la sucursal*/
	cout << "Nombre Sucursal Numero Sucursal\n" ;
		cout << "       " << s.nomSucursal << "\t" ; //impresion de variable
		cout << "       " << s.numSucursal << "\n\n" ; //impresion de variable
		
		/*Ciclo para impresion de variables*/
	for (int i =0 ; i < n ; i++)
	{		
		cout <<"Codigo\tNombre\tEdad\tDepartamento\tPuesto\tSalBase\tISSS\tAFP\tRENTA\tPrestamo\n";
		cout << e [i].cod << "\t" ; //impresion de variable
		cout << e [i].nombre << "\t" ;//impresion de variable
		cout << e [i].edad << "\t" ; //impresion de variable
		cout << e[i].departamento << "\t\t" ; //impresion de variable
		cout << e[i].puesto << "\t" ; //impresion de variable
		cout << e [i].salBase << "\t" ; //impresion de variable
		cout << e [i].isss << "\t" ; //impresion de variable
		cout << e [i].afp << "\t" ; //impresion de variable
		cout << e [i].renta << "\t" ; //impresion de variable
		cout << e [i].totalPrestamo;	 //impresion de variable
		cout << endl;
	}
	
	system ("pause"); //pausa
	 a ();//llamada de funcion
	 system("color e1");
	cout <<"Desarrollado por Keny Chavez" <<endl;//fue creado por
	cout <<"N° Carnet: CT18009" <<endl;//numero de carnet
	cout <<"Universidad de El Salvador" <<endl<<endl; //universidad
	
	
	
	
	return 0 ;
}
 void a (){ //declaracion de funcion
	system ("cls"); //limpiar
	cout << "|||||||||||||||*********|||||||||||||||" << endl; //decoracion
	cout << "             SUCURSALES S.A" << endl ; //decoracion
	cout << "|||||||||||||||*********|||||||||||||||" << endl ; //decoracion
}
	
