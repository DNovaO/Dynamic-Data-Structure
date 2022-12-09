#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

    //Estructura de ambas pilas, una sera la pila original(Nodo) y la otra sera una pila dinamica (Pila).
    struct Nodo{
        int dato;
        Nodo *siguiente;
    };

    struct Pila{
        int dato;
        Pila *siguiente;
    };

    Nodo *pila = NULL;
    Pila *pila2 = NULL;

    //Declaracion de funciones
    void AgregarNodo(Nodo *&pila, int num);
    void EliminarUnNodo(Nodo *&pila, int numero);
    void sacarNodoPilaDinamica(Pila *&pila, int numero);
    void sacarNodo(Nodo *&, int &);
    void MostrarPila(Nodo *&);
    void MostarPilaDinamica(Pila *&);
    void MostarTodasLasPilas(Nodo *&pila, Pila *&pila2);

    void EliminarNumerosRepetidos(Nodo *&pila,Pila *&pila2);
    void NumerosPares(Nodo *&pila, Pila *&pila2);
    void NumerosImpares(Nodo *&pila, Pila *&pila2);
    void NumerosPositivos(Nodo *&pila, Pila *&pila2);
    void NumerosNegativos(Nodo *&pila, Pila *&pila2);
    void AgregarNodosANuevaPila(Pila *&pila2, int num);
    
    //Declaracion de variables
    int numero,x,opc2,resp;


int main(){

    //basicamente hacemos un menu para que el usuario pueda seleccionar que funcion desea ejecutar.
    do{

        cout<<"Elige una opcion dentro del menu\n";
        cout<<"\n";
        cout<<"\t----------------MENU DE PILAS----------------\n";
        cout<<"1. Agregar Nodo a la pila\n";
        cout<<"2. Eliminar un solo Nodo\n";
        cout<<"3. Mostrar la pilas\n";
        cout<<"4. Eliminar toda la pila\n";
        cout<<"5. Salir\n";
        cin>>x;

        if(x == 1){ //Agregar Nodo a la pila

            cout<<"\n\nIngresa el elemento en el nodo: ";
	        cin>>numero;
		    AgregarNodo(pila, numero);


        }

        if(x == 2){ //Eliminar un numero de la pila, no importa en que posicion este.

            cout<<"Ingrese el numero que desea eliminar: ";
            cin>>numero;
            EliminarUnNodo(pila,numero);

        }

        if(x == 3){ //Despliega un Segundo menu, donde el usuario puede manejar las pilas a su gusto. 

            cout<<"\n\n";
            cout<<"Elige una opcion del Sub-Menu\n" ;
            cout<<"\n";
            cout<<"1. Mostrar toda la pila original.\n"; 
            cout<<"2. Mostrar los numeros no repetidos.\n";
            cout<<"3. Mostrar los numeros pares.\n";
            cout<<"4. Mostrar los numeros impares.\n";
            cout<<"5. Mostrar los numeros positivos.\n";
            cout<<"6. Mostrar los numeros negativos.\n";
            cout<<"7. Mostrar ambas pilas.\n";

            cin>>opc2;

            if(opc2==1){//Funcion que muestra la pila original.
                cout<<"Mostrando la pila original: \n";
                MostrarPila(pila);

			}

			if(opc2==2){ //Funcion que muestra los numeros no repetido todo esto ya con la pila dinamica
                cout<<"Mostrando los numeros no repetidos: \n";
                
                //antes de cada funcion eliminamos la pila dinamica para que no se acumulen los numeros. y evitar una sobrecarga de la pila dinamica
                while (pila2 != NULL) {
                    sacarNodoPilaDinamica(pila2, numero);
                        if(pila2 != NULL){
                        cout << numero << "";
                    } else { 
                        cout << numero << "\n";
                    }
                }

                EliminarNumerosRepetidos(pila,pila2);
                MostarPilaDinamica(pila2);
               
			}

			if(opc2==3){ //Funcion que muestra los numeros pares funciona recorriendo la pila original y comparando si el numero es par o no. 
                //De esta forma si cumple con la condicion este el numero se agrega a la pila dinamica.
                cout<<"Mostrando los numeros pares: \n";
                
                while (pila2 != NULL) {
                    sacarNodoPilaDinamica(pila2, numero);
                        if(pila2 != NULL){
                        cout << numero << "";
                    } else { 
                        cout << numero << "\n";
                    }
                }

                NumerosPares(pila,pila2);
                MostarPilaDinamica(pila2);
  
			}

			if(opc2==4){ //Funcion que muestra los numeros impares funciona recorriendo la pila original y comparando si el numero es impar o no.
                //De esta forma si cumple con la condicion este el numero se agrega a la pila dinamica.
                cout<<"Mostrando los numeros impares: \n";

                while (pila2 != NULL) {
                    sacarNodoPilaDinamica(pila2, numero);
                        if(pila2 != NULL){
                        cout << numero << "";
                    } else { 
                        cout << numero << "\n";
                    }
                }

                NumerosImpares(pila,pila2);
                MostarPilaDinamica(pila2);

			}

			if(opc2==5){//Funcion que muestra los numeros positivos funciona recorriendo la pila original y comparando si el numero es positivo o no.
                //De esta forma si cumple con la condicion este el numero se agrega a la pila dinamica.
                cout<<"Mostrando los numeros positivos: \n";

                while (pila2 != NULL) {
                    sacarNodoPilaDinamica(pila2, numero);
                        if(pila2 != NULL){
                        cout << numero << "";
                    } else { 
                        cout << numero << "\n";
                    }
                }
                NumerosPositivos(pila,pila2);
                MostarPilaDinamica(pila2);

			}

			if(opc2==6){//Funcion que muestra los numeros negativos funciona recorriendo la pila original y comparando si el numero es negativo o no.
                //De esta forma si cumple con la condicion este el numero se agrega a la pila dinamica.
                cout<<"Mostrando los numeros negativos: \n";

                while (pila2 != NULL) {
                    sacarNodoPilaDinamica(pila2, numero);
                        if(pila2 != NULL){
                        cout << numero << "";
                    } else { 
                        cout << numero << "\n";
                    }
                }
                NumerosNegativos(pila,pila2);
                MostarPilaDinamica(pila2);

			}

            if(opc2==7){// En esta funcion mostramos ambas pilas, la original y la dinamica. de tal forma que se puede apreciar como son 2 pilas diferentes.
                cout<<"Mostrando ambas pilas: \n";
                MostarTodasLasPilas(pila,pila2);
            }

        }

        if(x == 4){ //funcion que elimina ambas pilas. Tanto la original, como la dinamica.

            cout<<"Eliminando pila original: \n";
                while (pila != NULL) {
                    sacarNodo(pila, numero);
                    if(pila != NULL){
                    cout << numero << ", ";
                } else { 
                    cout << numero << ".\n";
                }
            }

            cout<<"Eliminando pila dinamica: \n";
                while (pila2 != NULL) {
                    sacarNodoPilaDinamica(pila2, numero);
                    if(pila2 != NULL){
                    cout << numero << ", ";
                } else { 
                    cout << numero << ".\n";
                }
            }
        }

    }while(x !=5);

    //sale del menu
    cout<<"Gracias por usar el menu de pilas. Hasta luego\n";
    exit(0);

}

    //implementacion de todas las funciones que se usan en el programa.

    //funcion para agregar los nodos a la pila original. 
    void AgregarNodo(Nodo *&pila, int num){

        Nodo *nuevo_nodo = new Nodo();
        nuevo_nodo -> dato = numero;
        nuevo_nodo -> siguiente = pila;
        pila = nuevo_nodo;
        cout << endl << " > Elemento " << pila->dato << " agregado correctamente." << endl << endl;
    }


    //funcion para sacar los nodos de la pila original, donde comparamos los numeros de la pila original y si concuerda con el dato que quiere quitar el usurio este nodo se elimina.
    void EliminarUnNodo(Nodo *&pila, int num){

        Nodo *aux = pila;
        Nodo *aux2 = pila;

        if(pila == NULL){
            cout << "La pila esta vacia" << endl;
        }

        else{
            while(aux != NULL){
                if(aux->dato == num){
                    aux2->siguiente = aux->siguiente;
                    delete aux;
                    cout << " > Elemento " << num << " eliminado correctamente." << endl << endl;
                    break;
                }
                aux2 = aux;
                aux = aux->siguiente;
            }
        }  
    }

    //funcion que elimina la pila original, donde recorremos la pila original y eliminamos los nodos.
    void sacarNodo(Nodo *&pila, int &num){

        Nodo *aux = pila;
        num = aux->dato;
        pila = aux->siguiente;
        delete aux;
    }

    //funcion que basicamente nos muestra la pila original.
    void MostrarPila(Nodo *&){
            
        Nodo *aux = pila;

        if(pila == NULL){
            cout << "La pila esta vacia" << endl;
        }

        else{
            while(aux != NULL){
                cout << " > Elemento " << aux->dato << endl;
                aux = aux->siguiente;
            }
        }  
    }

    //funcion que basicamente nos muestra la pila dinamica.
    void MostarPilaDinamica(Pila *&){

        Pila *aux = pila2;

        if(pila2 == NULL){
            cout << "La pila esta vacia" << endl;
        }

        else{
            while(aux != NULL){
                cout << " > Elemento " << aux->dato << endl;
                aux = aux->siguiente;
            }
        }  
    }

    //funcion que nos muestra ambas pilas. usando los principios para mostrar las pilas.
    void MostarTodasLasPilas(Nodo *&pila, Pila *&pila2){
            
        Nodo *aux = pila;
        Pila *aux2 = pila2;

        cout<<"\nPila Original:\n";

        if(pila == NULL){
            cout << "La pila esta vacia" << endl;
        }

        else{
            while(aux != NULL){
                cout << " > Elemento " << aux->dato << endl;
                aux = aux->siguiente;
            }
        }

        cout<<"\nPila dinamica:\n";

        if(pila2 == NULL){
            cout << "La pila esta vacia" << endl;
        }

        else{
            while(aux2 != NULL){
                cout << " > Elemento " << aux2->dato << endl;
                aux2 = aux2->siguiente;
            }
        }  
    }
    
    /*
        Bien a partir de esta funcion es donde nosotros generamos la pila dinamica con la condicion de que los numeros sean pares
        de tal forma nosotros recorremos los numeros de la pila original y aquellos que cumplan con la condicion seran agregados 
        como nodos a la pila dinamica con una funcion que agregara los nodos a la pila dinamica.
    */
    void NumerosPares(Nodo *&pila, Pila *&pila2){
            
        Nodo *aux = pila;
        int num;

        if(pila == NULL){
            cout << "La pila esta vacia" << endl;
        }

        else{
            while(aux != NULL){
                if(aux->dato % 2 == 0){
                    AgregarNodosANuevaPila(pila2, aux->dato);
                }
                aux = aux->siguiente;
            }
        }  
    }

    /*
        Sucede lo mismo en que en los numeros impares realmente generamos la pila dinamica por eso mismo se llama dinamica
        ya que se genera en base a las condiciones que quiere el usario. 
    */
    void NumerosImpares(Nodo *&pila, Pila *&pila2){
                
        Nodo *aux = pila;
        int num;

        if(pila == NULL){
            cout << "La pila esta vacia" << endl;
        }

        else{
            while(aux != NULL){
                if(aux->dato % 2 != 0){
                    AgregarNodosANuevaPila(pila2, aux->dato);
                }
                aux = aux->siguiente;
            }
        }  
    }

    //funcion de numeros positivos
    void NumerosPositivos(Nodo *&pila, Pila *&pila2){
                    
        Nodo *aux = pila;
        int num;

        if(pila == NULL){
            cout << "La pila esta vacia" << endl;
        }

        else{
            while(aux != NULL){
                if(aux->dato > 0){
                    AgregarNodosANuevaPila(pila2, aux->dato);
                }
                aux = aux->siguiente;
            }
        }  
    }

    //funcion de numeros negativos
    void NumerosNegativos(Nodo *&pila, Pila *&pila2){
                        
        Nodo *aux = pila;
        int num;

        if(pila == NULL){
            cout << "La pila esta vacia" << endl;
        }

        else{
            while(aux != NULL){
                if(aux->dato < 0){
                    AgregarNodosANuevaPila(pila2, aux->dato);
                }
                aux = aux->siguiente;
            }
        }   
    }

    //funcion de numeros que se encuentran repetidos, estos al estar repetidos no se agregan a la pila dinamica. con una condicion y un contador.
    void EliminarNumerosRepetidos(Nodo *&pila,Pila *&pila2){
                
        Nodo *aux = pila;        
        Pila *aux1 = pila2;
        Pila *aux2 = pila2;
        int cont=0;

        if(pila == NULL){
            cout << "La pila esta vacia" << endl;
        }

        else{
            while(aux != NULL){
                while(aux1 != NULL){
                    if(aux->dato == aux1->dato){
                        cont++;
                    }
                    aux1 = aux1->siguiente;
                }
                if(cont == 0){
                    AgregarNodosANuevaPila(pila2, aux->dato);
                }
                aux = aux->siguiente;
                aux1 = pila2;
                cont = 0;
            }
        }
    }
    
    /*
        en esta funcion basicamente es donde nosotros vamos a agregar todos los nuevos nodos a la nueva pila, aquellos que cumplen con
        la condicion que el usario ingrese.
    */
    void AgregarNodosANuevaPila(Pila *&pila2, int num){
            
        Pila *nuevo_nodo = new Pila();
        nuevo_nodo -> dato = num;
        nuevo_nodo -> siguiente = pila2;
        pila2 = nuevo_nodo;

    }
    
    //funcion que nos permite eliminar un nodo de la pila dinamica o tambien en su defecto, eliminar toda la pila dinamica 
    void sacarNodoPilaDinamica(Pila *&pila2, int num){
            
        Pila *aux = pila2;
        num = aux->dato;
        pila2 = aux->siguiente;
        delete aux; 
    }