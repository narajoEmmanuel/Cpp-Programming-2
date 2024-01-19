/*
Nombre: Emmanuel Naranjo
Fecha creacion:24/8/19
Ultima modificacion:29/8/19
*/
//Directivas para el compilador
#include <iostream>
#include <stdlib.h>
#include <string>
#include<math.h>

using namespace std;

//Declaraciones globales
const int tamano_vector = 20;
int m,n,numero,tamano;;
int matriz[tamano_vector][tamano_vector];
string vector1[5];
string vector2[3];

//Prototipo de funciones
int sumatoria_cuadrados(int inicio, int fin);//1
int multiplicatoria(int inicio, int fin);//2
int pares_amigables(int vector[]);//3
int suma_divisores(int num);
int factores_primos(int num);//4
int numero_abundante(int num);//5
void sumar_restar_vectores(int extension, const float arreglo1[], const float arreglo2[], float vector_resultante[], int operacion);//6
void leer_vector(int extension, float arreglo_leer[]);
void imprimir_vector(int extension, float arreglo_imprimir[]);
float multiplicar_vectores(int extension, const float arreglo1[], const float arreglo2[]);//7
int sumar_diagonal(int matriz[][tamano_vector],int tam, int diag);//8
void leer_matriz(int matriz[][tamano_vector],int fil, int col);
void primos_y_palindromos(int,int);//9
int saber_espejo(int num);
bool saber_palindromo(int num);
int convertir_bina_deci(int num);
int saber_primo(int num);
void triangulo_de_pascal(int num, int matriz[][tamano_vector]);//10
void imprimir_matriz(int num,int matriz[][tamano_vector]);
int factorial(int num);
int reemplazar(int num,int buscar, int rempl);//11
bool igualdad(int,int);//12
void maximos_y_minimos(int filas, int columnas,int matriz[][tamano_vector]);//13
void extraer_numeros(string);//14
string contar_palabras(string vector1[5], string vector2[3]);//15
string validar_subconjunto(string universo,string subconjunto);//16
string complemento(string universo, string complemento);
void leer_trozos(string vector[]);//17
int maximo(string vector[]);
int trozos_iguales(string vector[], string resultados[], int);
void imprimir_trozos(string resultados[],int,int);

//Definicion de la funcion main
int main(){
    int opcion;
    do{
        cout<<"\n\n\tMenu Principal\n\n";
        cout<<"1. Sumatoria de cuadrados\n";
        cout<<"2. Multiplicatoria\n";
        cout<<"3. Pares amigables\n";
        cout<<"4. Calcular factores primos\n";
        cout<<"5. Determinar si un numero es abundante\n";
        cout<<"6. Sumar y restar vectores\n";
        cout<<"7. Multiplicar vectores\n";
        cout<<"8. Sumar diagonal de una matriz cuadrada\n";
        cout<<"9. Numeros primos y palindromos\n";
        cout<<"10.Triangulo de Pascal\n";
        cout<<"11.Reemplazar numeros\n";
        cout<<"12.Igualdad de conjuntos\n";
        cout<<"13.Maximos y minimos de la matriz\n";
        cout<<"14.Extraer numeros\n";
        cout<<"15.Contar palabras\n";
        cout<<"16.Complemento de conjuntos\n";
        cout<<"17.Trozos iguales de strings\n";
        cout<<"18. Fin\n\n";
        cout<<"Opcion: ";
        cin>>opcion;
        switch (opcion) {
            case 1:
                cout << "\tSumatoria de cuadrados: "<<endl;
                cout<<"Inicio: "<<endl; cin>>m;
                cout<<"Fin: "<<endl; cin>>n;
                cout<<"Sumatoria de cuadrados: "<<sumatoria_cuadrados(m,n);
                break;
            case 2:
                cout << "\tMultiplicatoria:"<<endl;
                cout<<"Inicio: "<<endl;cin>>m;
                cout<<"Fin: "<<endl;cin>>n;
                cout<<"Multiplicatoria: "<<multiplicatoria(m,n);
                break;
            case 3:{
                int vector[10];//= {100, 1184, 220, 15, 18, 2, 1210, 284, 3, 25};
                cout<<"Datos del vector: "<<endl;
                int i=0;
                while(i<10){
                    cout<<i+1<<": ";
                    cin>>vector[i];
                    if (vector[i]>1){
                        int x=0;
                        while(x<i){
                            if(vector[x]==vector[i]){
                                cout<<"Los numeros del vector no se pueden repetir.";
                                cout<<"Coloque otro numero: ";cin>>vector[i];
                            }
                            else
                                x++;
                        }
                    }
                    else{cout<<"Los valores deben ser mayores que 1.";
                        cout<<"Coloque otro numero: ";cin>>vector[i];}
                    i++;
                }
                pares_amigables(vector);
                break;
            }
            case 4:
                cout << "\t Calcular factores primos"<<endl;
                cout<<"Calcular los factores primos de: ";cin>>numero;
                if (numero>=2){factores_primos(numero);
                }
                else {"El numero ingresado debe ser mayor o igual que 2.";}

                break;
            case 5:
                cout << "\tNumero Abundante"<<endl;
                cout<<"Numero para el calculo: ";cin>>numero;
                numero_abundante(numero);
                break;
            case 6:
                float arreglo1[tamano_vector],arreglo2[tamano_vector],vector_resultante[tamano_vector];
                int operacion;
                cout << "\tSumar y restar vectores"<<endl;
                cout<<"Tamano de los vectores: ";cin>>tamano;
                leer_vector(tamano,arreglo1);
                leer_vector(tamano,arreglo2);
                cout<<"Operacion (1-Suma, 2-Resta): ";cin>>operacion;
                sumar_restar_vectores(tamano,arreglo1,arreglo2,vector_resultante,operacion);
                cout<<"Vector resultante: \n";
                imprimir_vector(tamano,vector_resultante);
                break;
            case 7:
                float arreglo_mult1[tamano_vector],arreglo_mult2[tamano_vector];
                float resultado;
                cout << "\tMultiplicar vectores"<<endl;
                cout<<"Tamano de los vectores: ";cin>>tamano;
                leer_vector(tamano,arreglo_mult1);
                leer_vector(tamano,arreglo_mult2);
                resultado=multiplicar_vectores(tamano,arreglo_mult1,arreglo_mult2);
                cout<<"Multiplicacion: "<<resultado;
                break;
            case 8:
                cout << "\tSumar diagonal de matriz cuadrada"<<endl;

                int diagonal,respuesta;
                cout<<"Tamano de la matriz cuadrada: ";cin>>tamano;
                leer_matriz(matriz, tamano, tamano);
                cout<<"Numero de diagonal: ";cin>>diagonal;
                respuesta=sumar_diagonal(matriz,tamano,diagonal);
                cout<<"Suma de la diagonal: "<<respuesta;
                break;
            case 9:
                int inicio, fin;
                cout << "Numeros primos y palindromos";
                cout<<"Inicio del rango: ";cin>>inicio;
                cout<<"Fin del rango: ";cin>>fin;
                if (inicio>0 && fin>0 && inicio<=fin){
                    cout<<"Numeros que son primos y palindromos a la vez\n";
                    primos_y_palindromos(inicio,fin);
                }
                break;
            case 10:
                int nivel;
                cout << "\tTriangulo de Pascal"<<endl;
                cout<<"Nivel del triangulo: ";cin>>nivel;
                if (nivel>0 && nivel<20){
                    triangulo_de_pascal(nivel,matriz);
                    imprimir_matriz(nivel,matriz);
                }
                else {cout<<"El numero ingresado debe ser positivo y menor a 20.";}
                break;
            case 11:
                int buscar,reemplazo;
                long int num;
                cout << "\tReemplazar numeros"<<endl;
                cout<<"Buscar: ";cin>>buscar;
                cout<<"En el numero: ";cin>>num;
                cout<<"Reemplazar por: ";cin>>reemplazo;
                cout<<"Resultado: "<<reemplazar(num,buscar,reemplazo);
                break;
            case 12:
                int num1,num2;
                bool x;
                cout << "\tIgualdad de conjuntos "<<endl;
                cout<<"Conjunto 1: ";cin>>num1;
                cout<<"Conjunto 2: ";cin>>num2;
                x=igualdad(num1,num2);
                if(x){cout<<"Conjuntos iguales ";}
                else {cout<<"Conjuntos NO iguales ";}
                break;
            case 13:
                int filas, columnas;
                cout << "\tMáximos y mínimos de una matriz "<<endl;
                cout<<"Filas: ";cin>>filas;
                cout<<"Columnas: ";cin>>columnas;
                leer_matriz(matriz,filas,columnas);
                maximos_y_minimos(filas,columnas,matriz);
                break;
            case 14:
                {
                    string frase;
                    cout<<"\t Extraer numeros"<<endl;
                    cin.ignore();
                    cout<<"String a analizar: ";getline(cin,frase);
                    cout<<"Numeros encontrados: "<<endl;
                    extraer_numeros(frase);
                    break;
                }
            case 15:
                cout << "\t Contar palabras " << endl;
                cout << "Vector de palabras: " << endl;
                cin.ignore();
                for (auto &i : vector1) {
                    //cin.ignore();
                    getline(cin, i);
                }
                cout << "Vector de frases: " << endl;
                for (auto &j : vector2) {
                    //cin.ignore();
                    getline(cin, j);
                }
                cout << "Resultados: " << endl;
                contar_palabras(vector1, vector2);
                break;
            case 16:{
                cout << "\t Complemento de conjuntos "<<endl;
                string universo,subconjunto;
                string bandera;
                cout<<"Conjunto universo: ";cin>>universo;
                cout<<"Subconjunto: ";cin>>subconjunto;
                //cout<<validar_subconjunto(universo,subconjunto);
                cout<<complemento(universo,subconjunto);
                break;
            }

            case 17:{
                cout << "\tTrozos iguales de strings "<<endl;
                string vector[20]={"xyz","xyz","m","a","a","a","a","j","j","x1","x1","x1","x1","fin"};
                string resultados[20];
                int contador;
                //leer_trozos(vector);
                const int max=maximo(vector);
                contador=trozos_iguales(vector,resultados,max);
                imprimir_trozos(resultados,max,contador);
                break;
            }
            case 18:
                break;
            default:
                cout << "Error: La opcion no es valida.";
        }
    }while(opcion!=18);

    return 0;
}

//Definicion de funciones

//1.Esta función implementa una sumatoria de cuadrados empezando desde i = m hasta n.
//Entrada:inicio y fin de la sumatoria.
// Salidas:la sumatoria.
int sumatoria_cuadrados(int inicio, int fin) {
    int suma = 0;
    if (inicio >= 0 && fin >= 0 && inicio<=fin) {
        for (int i = inicio; i <= fin; i++) {
            suma += i * i;
        }
        return suma;
    }
    else
        cout << "Los valores ingresados deben ser numeros naturales. El inicio debe ser menor que el final.";
}

//2.Esta función implementa multiplica los terminos iniciando desde i = m hasta n.
//Entrada: inicio de la multiplicatoria.
// Salida: la multiplicatoria.
int multiplicatoria(int inicio, int fin) {
    int multiplicacion = 1;
    if (inicio >= 0 && fin >= 0 && inicio<=fin) {
        for (int i = inicio; i <= fin; i++) {
            multiplicacion *= i;
        }
    }
    else
        cout << "Los valores ingresados deben ser numeros naturales. El inicio debe ser menor que el final.";
    return multiplicacion;
}

//3.Esta función implementa determina los pares amigables de una lista de numeros.
////Entrada: vector con 10 numeros enteros.
/// Salida: imprime los numeros amigables.
int suma_divisores(int num){
    int i=1, suma=0;
    while (i < num){
        if (num % i == 0){
            suma+=i;
        }
        i++;
    }
    return suma;
}

int pares_amigables (int vector[]){
    int i=0, bandera=1;
    while (i<10){
        int x=i+1;
        while(x<10){
            //cout<<"\n~~"<<suma_divisores(vector[i])<<endl;
            //cout<<">>"<<vector[x]<<endl;
            if(vector[x]==suma_divisores(vector[i])){
                cout<<vector[i]<<" y "<<vector[x]<<endl;
                x++;bandera=2;
            }
            x++;
        }
        i++;
    }
    if (bandera==1){cout<<"No hay pares amigables.";}
}

//4.Esta función expresa los factores primos de un numero.
//Entrada: numero a factorizar.
// Salida: producto de factores primos del numero ingresado.
int factores_primos(int num){
    string band="F";
    int i=2;
    do{
        while(num%i==0){
            if(band!="F"){
                cout<<" X "<<i;
                num/=i;
            }
            else{
                cout<<i;
                num/=i;
                band="V";
            }
        }
        i++;
    }while(num>1);
}

//5.Esta función determina si un numero es abundante.
//Entrada: entero a calcular abundancia.
// Salida: Imprime los divisores del número, la suma de estos y si el número es abundante o no.
int numero_abundante(int num){
    int suma=0;
    if(num>=1){
        cout<<"Divisores: ";
        int i=1;
        while(i<=num){
            if(num%i==0) {
                cout<<i<<"  ";
                suma+=i;}
            i++;}
        cout<<"\nSuma de los divisores: "<<suma<<endl;
        if (suma>2*num){
            cout<<"Es un numero abundante."<<endl;
            cout<<"Abundancia: "<<suma-2*num;}
        else{
            cout<<"No es un numero abundante."<<endl;
            cout<<"Abundancia: no hay."<<endl;}}
    else
        cout<<"El número ingresado debe ser mayor o igual que 1.";
}

//6.Esta función suma y resta dos vectores y produce como resultado un vector.
//Entrada: 2 vectores del mismo tamano.
// Salida: Imprime el vector resultante.
void leer_vector(int extension, float arreglo_leer[]) {
    int i = 0;
    cout << "Valores del vector: \n";
    while (i<extension) {
        cin >> arreglo_leer[i];
        i++;
    }
}

void imprimir_vector(int extension, float arreglo_imprimir[]){
    int i=0;
    while (i<extension){
        cout<<arreglo_imprimir[i]<<"  ";
        i++;
    }
}

void sumar_restar_vectores(int extension, const float arreglo1[], const float arreglo2[], float vector_resultante[], int operacion) {
    if (operacion==1){
        int x=0;
        while(x<extension){
            vector_resultante[x]=arreglo1[x]+arreglo2[x];
            x++;
        }
    }
    else if (operacion==2){
        int i=0;
        while(i<extension){
            vector_resultante[i]=arreglo1[i]-arreglo2[i];
            i++;
        }
    }
}

//7.Esta función multiplica dos vectores y produce como resultado un único valor
//Entrada: 2 vectores del mismo tamano.
//Salida: retorna el resultado de la multiplicacion de vectores.
float multiplicar_vectores(int extension, const float arreglo1[], const float arreglo2[]){
    int x=0;
    float resultado=0;
    while(x<extension){
        resultado+=(arreglo1[x]*arreglo2[x]);
        x++;
    }
    return resultado;
}

//8.Esta función suma los valores de una de las diagonales de la matriz cuadrada.
//Entrada: Tamano de la matriz, la matriz y el numero de la diagonal a averiguar.
//Salida: Retorna la suma de los elementos de la diagonal.
void leer_matriz(int matriz[][tamano_vector],int fil, int col){
    cout<<"Valores de la matriz:\n";
    int i=0;
    while(i<fil){
        int j=0;
        while (j<col){
            cout<<"Fila "<<i+1<<" columna "<<j+1<<": ";
            cin>>matriz[i][j];
            j++;
        }
        i++;
    }
}

int sumar_diagonal(int matriz[][tamano_vector],int tam, int diag){
    int suma=0;
    if (diag>=0){
        int x=0, j=diag;
        while(x<tam && j<tam){
            suma+=matriz[x][j];
            x++;j++;
        }
    }
    else if (diag<0){
        int x=0,j=-(diag);
        while (j<tam){
            suma+=matriz[j][x];
            x++;j++;
        }
    }
    return suma;
}

//9.Esta función indica los números primos y palindromos dentro de un rango.
//Entrada: Recibe 2 numeros enteros, el inicio y el fin de un rango.
//Salida: Imprime los numeros primos y palindromos.
void primos_y_palindromos(int num1,int num2){
    int inicio,fin,x,c;
    string bandera="V";
    inicio=convertir_bina_deci(num1);
    fin=convertir_bina_deci(num2);
    while(inicio<=fin){
        x=saber_palindromo(inicio);
        if (x==1){
            c=saber_primo(inicio);
            if (c==1){
                cout<<inicio<<endl;
                bandera="F";
            }
        }
        inicio++;
    }
    if (bandera=="V"){cout<<"NO HAY NUMEROS CUYA REPRESENTACION DECIMAL SEA UN PRIMO Y PALINDROMO A LA VEZ \n";}
}

int saber_espejo(int num){
    int espejo=0;
    while(num > 0){
        espejo+= num % 10;
        espejo*=10;
        num/=10;
    }
    return espejo/10;
}

bool saber_palindromo(int num){
    if(num == saber_espejo(num))
        return true;
    else
        return false;
}

int convertir_bina_deci(int num){
    int decimal=0,digito, contador=0;
    while(num > 0){
        digito= num % 10;
        if(digito==1){
            decimal+=pow(2,contador);
        }
        contador++;
        num/=10;
    }
    return decimal;
}

int saber_primo(int num){
    //bool bandera=false;
    for(int i=2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

//10.Esta función imprime el triangulo de pascal
//Entrada: cantidad de niveles del triangulo de pascal.
//Salida: Triangulo de Pascal
int factorial(int num){
    int factorial=1;
    int i=1;
    while (i<=num){
        factorial*=i;
        i++;
    }
    return factorial;
}

void triangulo_de_pascal(int num, int matriz[][tamano_vector]){
    int numero;
    int i=0,j=0;
    for(int n=1;n<=num;n++){
        for (int k = 1; k <= n; k++) {
            numero = factorial(n - 1) / (factorial(k - 1) * factorial(((n - 1) - (k - 1))));
            matriz[i][j] = numero;
            j++;
        }
        i++;
    }
}

void imprimir_matriz(int num, int matriz[][tamano_vector]){
    int i=0,j=0;
    for(int n=1;n<=num;n++){
        for (int k = 1; k <= n; k++) {
            cout<<matriz[i][j]<<"  ";
            j++;
        }
        i++;cout<<endl;
    }
}


//11.Esta funcion funcion eemplaza numeros.
//Entrada: Numero, numero a buscar, numero a reemplazar
//Salida: nuevo numero
int reemplazar(int num,int buscar, int rempl){
    string result_str="";
    string original=to_string(num);
    string busco=to_string(buscar);
    string reemplazo=to_string(rempl);

    int i=0,j=0;
    while(i< original.size() && j<busco.size()){
        if(original[i]==busco[j]){
            j++;
            if (j==busco.size()){
                j=0;
                result_str+=reemplazo;
            }
        }
        else{result_str+=original[i];}
        i++;
    }
    int resultado=atoi(result_str.c_str());
    return resultado;
}


//12. Esta funcion comprueba la igualdad de dos conjuntos
//Entrada: dos conjuntos
//Salida: Si estos conjuntos son iguales.
bool igualdad(int num1,int num2) {
    string conjunto1 = to_string(num1);
    string conjunto2 = to_string(num2);
    int i = 0;
    bool c=true;
    if(conjunto1.size()==conjunto2.size()){
        while (i < conjunto1.size()) {
            for (int j = 0; j < conjunto2.size(); j++) {
                if (conjunto1[i] == conjunto2[j]) {
                    c = true;
                    break;
                }
                else{c=false;}
            }
            i++;
        }
        return c;
    }
    else {return false;}
}

//13.Esta funcion encuentra los maximos y minimos de cada fila y columna de una matriz.
//Entrada: matriz a analizar, fila y columnas
//Salida: valores maximos y minimos.
void maximos_y_minimos(int filas, int columnas,int matriz[][tamano_vector]) {
    int i = 0;
    while (i < filas) {
        int max_fil = 0, min_fil = 100000;
        int j = 0;
        while (j < columnas) {
            if (matriz[i][j] > max_fil) {
                max_fil = matriz[i][j];
            }
            if (matriz[i][j] < min_fil) {
                min_fil = matriz[i][j];
            }
            j++;
        }
        cout << "\n\nFila " << i + 1 << " maximo " << max_fil << "  minimo " << min_fil << endl;
        i++;
    }
    cout << endl;
    int x = 0;
    while (x < columnas) {
        int max_col = 0, min_col = 100000;
        int z = 0;
        while (z < filas) {
            if (matriz[z][x] > max_col) {
                max_col = matriz[z][x];
            }
            if (matriz[z][x] < min_col) {
                min_col = matriz[z][x];
            }
            z++;
        }
        cout << "\nColumna " << x + 1 << " maximo " << max_col << "  minimo " << min_col << endl;
        x++;
    }
}

//14.Esta funcion exrae los numeros de una cadena de caracteres.
//Entrada: cadena a analizar.
//Salida: los numeros encontrados.
void extraer_numeros(string frase){
    string resultado;
    int i=0,ver=0;
    while(i<frase.size()){
        if (isdigit(frase[i]) != 0){
            resultado+=frase[i];ver++;}
        if((isdigit(frase[i-1])!=0 && isalpha(frase[i])!=0) || frase[i] == ' '){
            cout<<resultado<<endl;
            resultado="";
        }i++;
    }cout<<resultado;
    if (ver==0){cout<<"Ninguno";}
}


//15. Esta funcion cuenta las palabras de un vector con frases.
//Entrada: Dos vectores, uno con las palabras a buscar y otro con las frases.
//Salida: la cantidad de palabras a buscar en las frases.
string contar_palabras(string vector1[5], string vector2[3]) {
    cout << "Cantidad de veces que aparece cada palabra en las frases: " << endl;
    int i = 0;
    while (i < 5) {
        int cantidad = 0;
        int j = 0;
        while (j < 3) {
            int found=-1;
            do{
                found=vector2[j].find(vector1[i],found+1);
                if(found!=-1){
                    if(found==0 || vector2[j][found-1]==' '){
                        cantidad+=1;}
                }
            }while(found!=-1);
            j++;
        }
        cout <<"\t"<<vector1[i] <<":  "<<cantidad<<endl;
        i++;
    }
}

//16. Esta funcion devuelve el complemento de un conjunto dado.
//Entrada: conjunto universo.
//Salida: el complemento del conjunto universo.
string validar_subconjunto(string universo,string subconjunto){
    int i=0; int bandera=1;
    string valores;
    while(i<subconjunto.size()){
        int j=0,band=1;
        while(j<universo.size()){
            if (subconjunto[i]==universo[j]){
                band=2;
            }
            j++;
        }
        if(band==1){valores+=subconjunto[i];}
        i++;bandera=2;
    }
    return valores;
}
string complemento(string universo, string complemento){
    string ver;
    ver=validar_subconjunto(universo,complemento);
    //cout<<isalpha(ver[0])<<endl;
    if(isalpha(ver[0]) != 0){
        cout<<"Simbolos que no estan en el conjunto universo: "<<ver;
        return "\nfalse";
    }
    string valores;
    int i=0;
    while(i<universo.size()){
        int j=0,band=1;
        while(j<universo.size()){
            if (universo[i]==complemento[j]){
                band=2;
            }
            j++;
        }
        if(band==1){valores+=universo[i];}
        i++;
    }
    cout<<"Complemento: "<<valores;
    return "\ntrue";
}

//17. Esta funcion  reciba un vector de strings  y retorne de ese vector  todos los trozos que tengan la longitud de trozo máxima.
//Entrada: vector de strings
//Salida: imprime los trozos de mayor cantidad.
void leer_trozos(string vector[]){
    int tam;
    cout<<"Tamano vector: \n";cin>>tam;
    cout<<"Vector de strings: ";
    for(int i=0; i<tam;i++){
        cin>>vector[i];
    }
}

int maximo(string vector[]){
    int i=0,maximo=0;
    string comparo;
    int contador=1;
    while(vector[i]!="fin"){
        comparo=vector[i];
        if (comparo==vector[i+1]){
            contador++;
        }
        else{
            if(contador>maximo){maximo=contador;}
            contador=1;
        }
        i++;
    }
    return maximo;
}

int trozos_iguales(string vector[],string resultados[], int max){
    int i=0, j=0,maximo=0;
    string comparo,vector_strigs;
    int contador=1;
    while(vector[i]!="fin"){
        vector_strigs+=vector[i]+",";
        comparo=vector[i];
        if (comparo==vector[i+1]){
            contador++;
        }
        else{
            if(contador>=maximo){
                maximo=contador;
                if(maximo==max){
                    resultados[j]=vector[i];j++;
                }
            }
            contador=1;
        }
        i++;
    }
    cout<<"Vector de strings: "<<vector_strigs<<endl;
    return j;
}

void imprimir_trozos(string resultados[],int max, int aux){
    int i=0;
    cout<<"\nResultados:"<<endl;
    while(i<aux){
        cout<<endl;
        int j=1;
        while(j<=max){
            cout<<resultados[i]<<"  ";
            j++;
        }
        i++;
    }
}





