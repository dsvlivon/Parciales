#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
* \param void
* \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria o el puntero al espacio reservado
*/
LinkedList* ll_newLinkedList(void){
    //Employee* this = (Employee*) malloc(sizeof(Employee));
    LinkedList* this=(LinkedList*)malloc(sizeof(LinkedList*));// se reserva el espacio de memoria
    ////////////////////////////////
    if(this != NULL)
    {
        this->size=0;// se setea los valores x deffault
        this->pFirstNode = NULL; // se setea los valores x deffault
    }
    return this;
}
/** \brief Retorna la cantidad de elementos de la lista
* \param this LinkedList* Puntero a la lista
* \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
*/
int ll_len(LinkedList* this){
    int auxReturn = -1;
    ////////////////////////////////
    if(this!= NULL)
    {
        auxReturn=this->size; // se evalua el size, se va a utilizar un contador
    }
    return auxReturn;
}
/** \brief  Obtiene un nodo de la lista
* \param this LinkedList* Puntero a la lista
* \param index int Indice del nodo a obtener
* \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista) (pNode) Si funciono correctamente
*/
static Node* getNode(LinkedList* this, int nodeIndex){
    Node* pNode = NULL;
    ////////////////////////////////
    if(this != NULL && nodeIndex >= 0 && nodeIndex < ll_len(this))//evaluar indice en rango
    {
        pNode=this->pFirstNode;
        while(nodeIndex>0)
        {
            pNode=pNode->pNextNode;
            nodeIndex--;// retrocedo buscando el indice cero y asignar el pFirst
        }
    }
    return pNode;
}
/** \brief  Permite realizar el test de la funcion getNode la cual es privada
* \param this LinkedList* Puntero a la lista
* \param index int Indice del nodo a obtener
* \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lisa) (pElement) Si funciono correctamente
*/
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}
/** \brief Agrega y enlaza un nuevo nodo a la lista
* \param this LinkedList* Puntero a la lista
* \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
* \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
* \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista (0) Si funciono correctamente
*/
static int addNode(LinkedList* this, int nodeIndex,void* pElement){
    int auxReturn = -1;
    Node* newNode = NULL;
    Node* auxNode = NULL;
    int xLen=0;
    ////////////////////////////////
    if(this!= NULL)
    {
        xLen = ll_len(this);
        if(nodeIndex>=0 && nodeIndex<= xLen) //evaluar indice en rango
        {
            //LinkedList* this=(LinkedList*)malloc(sizeof(LinkedList*));
            newNode = (Node*)malloc(sizeof(Node*)); // se reseva espacio de memoria para el nuevo nodo
            if(newNode!=NULL)
            {
                newNode-> pElement = pElement; // asigno puntero de parametros
                newNode-> pNextNode = NULL;//setero el next x deffault
                if(nodeIndex== 0)
                {
                    if(xLen>=1)//caso indice=0 c mas d un elemento en la lista:
                    {
                        newNode->pNextNode =getNode(this, nodeIndex);//asigno colmo siguiente al nodo indicado x index
                    }
                   this->pFirstNode = newNode;
                }
                else if(nodeIndex == xLen) // caso indice=largo: es el ultimo elemento de la lista
                {
                    auxNode = getNode(this, nodeIndex-1);//obtengo el anterior
                    auxNode->pNextNode = newNode;// y le asigno como next mi nuevo nodo
                }
                else // caso indice en el medio:
                {
                    newNode->pNextNode = getNode(this,nodeIndex);//asigno colmo siguiente al nodo indicado x index
                    auxNode = getNode(this,nodeIndex-1);//obtengo el anterior
                    auxNode->pNextNode = newNode;// y le asigno como next mi nuevo nodo
                }
            }
            this-> size++; // aumento el contador de size de la LL
            auxReturn = 0;
        }
    }
    return auxReturn;
}
/** \brief Permite realizar el test de la funcion addNode la cual es privada
* \param this LinkedList* Puntero a la lista
* \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
* \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
* \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)( 0) Si funciono correctamente
*/
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}
/** \brief  Agrega un elemento a la lista
* \param pList LinkedList* Puntero a la lista
* \param pElement void* Puntero al elemento a ser agregado
* \return int Retorna  (-1) Error: si el puntero a la lista es NULL (0) Si funciono correctamente
*/
int ll_add(LinkedList* this, void* pElement){
    int auxReturn= -1;
    int xLen;
    ////////////////////////////////ll_add llama a addnode
    if(this!=NULL)
    {
        xLen = ll_len(this);
        if(addNode(this,xLen,pElement)==0)
        {
            auxReturn=0;
        }
    }

    return auxReturn;
}
/** \brief Permite realizar el test de la funcion addNode la cual es privada
* \param this LinkedList* Puntero a la lista
* \param nodeIndex int Ubicacion del elemento a obtener
* \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista) (pElement) Si funciono correctamente
*/
void* ll_get(LinkedList* this, int index){
    void* auxReturn = NULL; // retorno tipo puntero
    Node* auxNode = NULL;
    int xLen;
    ////////////////////////////////
    if(this!=NULL)
    {
        xLen = ll_len(this);
        if(index<=xLen && index>=0)//evaluar indice en rango
        {
            auxNode =getNode(this, index);//obtengo el nodo indicado x index
            if(auxNode!=NULL)
            {
                auxReturn = auxNode->pElement;//guardo el puntero para devolverlo
            }
        }
    }
    return auxReturn;
}
/** \brief Modifica un elemento de la lista
* \param this LinkedList* Puntero a la lista
* \param nodeIndex int Ubicacion del elemento a modificar
* \param pElement void* Puntero al nuevo elemento
* \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista) (0) Si funciono correctamente
*/
int ll_set(LinkedList* this, int index,void* pElement){
    int auxReturn = -1;
    Node* auxNode = NULL;
    int xLen;
    ////////////////////////////////
    if(this!=NULL)
    {
        xLen = ll_len(this);
        if(index<=xLen && index>=0)//evaluar indice en rango
        {
            auxNode =getNode(this, index);//obtengo el nodo indicado x index
            if(auxNode!=NULL)
            {
                auxNode->pElement = pElement;
                auxReturn = 0;
            }
        }
    }
    return auxReturn;
}
/** \brief Elimina un elemento de la lista
* \param this LinkedList* Puntero a la lista
* \param nodeIndex int Ubicacion del elemento a eliminar
* \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)( 0) Si funciono correctamente
*/
int ll_remove(LinkedList* this,int index){
    int auxReturn = -1;
    Node* auxNode = NULL;
    Node* lNode = NULL;//nodo previo
    Node* rNode = NULL;//nodo a borrar
    int xLen, node;
    ////////////////////////////////
    if(this != NULL)
    {
        xLen = ll_len(this);
        if(index<xLen && index >= 0 && xLen > 0)//evaluar indice en rango
        {
            rNode = getNode(this,index);//obtengo el nodo indicado x index y lo guardo en el aux a borrar
            node = index + 1; // aigno al indice node, la posicion siguiente al index por parametro
            if(node == xLen && rNode!= NULL && index > 0)
            {
                auxNode = getNode(this,index-1); //obtengo el nodo anterior
                auxNode -> pNextNode = NULL;// seteo el pnext en null
            }
            else if( node== xLen && rNode != NULL && index == 0)
            {
                this->pFirstNode = NULL; //corto la cadena
            }
            else if(rNode != NULL && index > 0)
            {
                auxNode = rNode->pNextNode;//guardo el pnext del nodo a borrar
                lNode = getNode(this,index-1);//obtengo el nodo anterior
                lNode ->pNextNode = auxNode;// y le asigno el pnext del nodo a borrar
            }
            free(rNode);
            this->size--;
            auxReturn = 0;
        }
    }
    return auxReturn;
}
/** \brief Elimina todos los elementos de la lista
* \param this LinkedList* Puntero a la lista
* \return int Retorna  (-1) Error: si el puntero a la lista es NULL( 0) Si funciono correctamente
*/
int ll_clear(LinkedList* this){
    int auxReturn = -1;
    int i, xLen;
    int counter=0;
    ////////////////////////////////
    if(this!=NULL)
    {
        xLen = ll_len(this);
        if(xLen>=0)//evaluar indice en rango
        {
            for(i=0; i<xLen;i++)
            {
                if(ll_remove(this,i)==0)
                {
                    counter++;// cada vez q remueve un elemento cuenta
                }
            }
            if(xLen==counter)// si y solo si son iguales los marcadores retorna 0
            {
                auxReturn=0;// ojo c el elemento 0 q aparecia en el tp3
            }
        }
    }
    return auxReturn;
}
/** \brief Elimina todos los elementos de la lista y la lista
* \param this LinkedList* Puntero a la lista
* \return int Retorna  (-1) Error: si el puntero a la lista es NULL( 0) Si funciono correctamente
*/
int ll_deleteLinkedList(LinkedList* this){
    int auxReturn = -1;
    ////////////////////////////////
    if(this!=NULL)
    {
        if(ll_clear(this)==0)//llama al clear
        {
            free(this);
            auxReturn=0;
        }
    }
    return auxReturn;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
* \param this LinkedList* Puntero a la lista
* \param pElement void* Puntero al elemento
* \return int Retorna  (-1) Error: si el puntero a la lista es NULL(indice del elemento) Si funciono correctamente*
*/
int ll_indexOf(LinkedList* this, void* pElement){
    int auxReturn = -1;
    int i,xLen;
    void* auxPelement= NULL;
    ////////////////////////////////
    if(this!=NULL)
    {
        xLen=ll_len(this);
        if(xLen>0)//evaluar indice en rango
        {
            for(i=0;i<xLen;i++)//recorre la LL
            {
                auxPelement = ll_get(this,i); // obtiene el elemento del indice i
                if(auxPelement == pElement) // y lo compara
                {
                    auxReturn = i;
                    break;// si es el elemento q busca rompe para no seguir iterando
                }
            }
        }
    }
    return auxReturn;
}
/** \brief Indica si la lista esta o no vacia
* \param this LinkedList* Puntero a la lista
* \return int Retorna  (-1) Error: si el puntero a la lista es NULL ( 0) Si la lista NO esta vacia ( 1) Si la lista esta vacia
*/
int ll_isEmpty(LinkedList* this){
    int xLen;
    int auxReturn = -1;//si el puntero a la lista es NULL
    ////////////////////////////////
    if(this!=NULL)
    {
        xLen=ll_len(this);
        if(xLen>0)
        {
            auxReturn=0;//Si la lista NO esta vacia
        }
        else
        {
            auxReturn=1;//Si la lista esta vacia
        }
    }
    return auxReturn;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
* \param this LinkedList* Puntero a la lista
* \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
* \param pElement void* Puntero al nuevo elemento
* \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)( 0) Si funciono correctamente
*/
int ll_push(LinkedList* this, int index, void* pElement){
    int auxReturn = -1;
    int xLen;
    ////////////////////////////////
    if(this!= NULL)
    {
        xLen = ll_len(this);
        if(index>=0 && index<= xLen)//evaluar indice en rango
        {
            if(addNode(this, index, pElement)==0)//llama al add para agregar un nodo
            {
               auxReturn=0;
            }
        }
    }
    return auxReturn;
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
* \param this LinkedList* Puntero a la lista
* \param nodeIndex int Ubicacion del elemento eliminar
* \return void* Retorna (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista) (pElement) Si funciono correctamente
*/
void* ll_pop(LinkedList* this,int index){
    void* auxReturn = NULL; // auxiliar de retorno tipo puntero!!!
    void* buffer = NULL;
    int xLen;
    ////////////////////////////////
    if(this!=NULL)
    {
        xLen=ll_len(this);
        if(index>=0 && index<=xLen)//evaluar indice en rango
        {
            buffer = ll_get(this, index);//obtengo ele puntero del nodo indicado x index
            if(ll_remove(this,index)==0)
            {
                auxReturn=buffer;//si se lo pudo eliminar, retorno el puntero de dnd estaba
            }
        }
    }
    return auxReturn;
}

/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
* \param this LinkedList* Puntero a la lista
* \param pElement void* Puntero del elemento a verificar
* \return int Retorna  (-1) Error: si el puntero a la lista es NULL ( 1) Si contiene el elemento (0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement){
    int auxReturn = -1;//si el puntero a la lista es NULL
    int aux;
    //////////////////////////
    if(this!=NULL)
    {
        aux = ll_indexOf(this, pElement);//guardo el indice del elemento pasado como parametro
        if(aux>=0)
        {
            auxReturn=1;//Si contiene el elemento
        }
        else
            auxReturn=0;//si No contiene el elemento
    }
    return auxReturn;
}

/** \brief  Determina si todos los elementos de la lista (this2) estan contenidos en la lista (this)
* \param this LinkedList* Puntero a la lista
* \param this2 LinkedList* Puntero a la lista
* \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2){
    int auxReturn = -1;
    int xLen,i;
    int counter=0;
    //////////////////////////
    void* buffer = NULL;//tipo puntero
    //void* buffer2 = NULL;
    if(this!=NULL && this2!=NULL)
    {
        xLen = ll_len(this2);

        for (i=0;i<xLen;++i)//recorres la LL
        {
            buffer = ll_get(this2, i); //obtenes el nodo segun posicion de indice i
            if(ll_contains(this,buffer)==1) //comprobas si existe ene la LL
            {
                counter++;// y contas
            }
            else
            {
                break;
            }
        }
        if(counter==xLen)//si los marcadores son iguales
        {
            auxReturn=1;

        }
        else
        {
            auxReturn=0;
        }
    }
    return auxReturn;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
* \param pList LinkedList* Puntero a la lista
* \param from int Indice desde el cual se copian los elementos en la nueva lista
* \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
* \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to){
    LinkedList* cloneArray = NULL;
    void* buffer = NULL;//puntero
    int xLen,i;
    int auxReturn=-1;
    //////////////////////////
    if(this!=NULL)
    {
        xLen=ll_len(this);
        if(xLen>= 0)
        {
            if(from>=0 && from<=xLen)//compruebo que FROM este en rango
            {
                if(to>=0 && to<=xLen)//compruebo que TO este en rango
                {
                    if(from <= to)//FROM nunca puede suer mayor que TO
                    {
                        cloneArray=ll_newLinkedList();//llamo a newLL para asignar espacio de memoria
                    }
                }
            }
        }
        if(cloneArray!=NULL)//verifico
        {
            for(i=0;i<to;i++)// recorro la LL
            {
                buffer=ll_get(this, i); //guardo el elemento de la posicion i
                if(ll_add(cloneArray, buffer)==0)
                {
                    auxReturn=0;//agrego el elemento y "levanto un flag"
                }
                else
                {
                    auxReturn=-1;//si la operacion falla lo bajo
                }
            }
        }
        if(auxReturn!=0)//si el flag informa falla
        {
            ll_deleteLinkedList(cloneArray);// libero la lista
            cloneArray=NULL;//
        }
    }
    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
* \param pList LinkedList* Puntero a la lista
* \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this){
    LinkedList* cloneArray = NULL;
    int xLen,i=0;
    //////////////////////////
    if(this!=NULL)
    {
        xLen=ll_len(this);
        //for(i=0;i<xLen;i++)
        if(xLen>=0)
        {
            cloneArray =ll_subList(this, i, xLen);//llamo a sublist pasando como parametros //i=FROM y xLen=TO
            //va a recorrer la lista clonando cada posicion hasta los limites pasados en la cloneArray
        }
    }
    return cloneArray;
}

/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
* \param pList LinkedList* Puntero a la lista
* \param pFunc (*pFunc) Puntero a la funcion criterio
* \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
* \return int Retorna  (-1) Error: si el puntero a la listas es NULL (0) Si ok
*/
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order){
    int auxReturn =-1;
    void* pBufferA;
    void* pBufferB;
    void* pBufferC;
    int i, flag, xLen;
    ////////////////////////////////
    if(this!=NULL && pFunc!= NULL)
    {
        if(order == 0 || order == 1)
        {
            xLen = ll_len(this);
            if(xLen > 0)
            {
                do//iteracion
                {
                    flag= 0;
                    for(i=0; i<xLen-1; i++)
                    {
                        pBufferA = ll_get(this,i);//obtengo la posicion segun i
                        pBufferB = ll_get(this,i+1);// y la siguiente posicion a esa

                        if(order==0 && pFunc(pBufferA, pBufferB)<0)//verifico parametros de ordenamiento
                        {
                            pBufferC = pBufferA;//guardo elemento A en C
                            ll_set(this,i,pBufferB);//copio B en A
                            ll_set(this,i+1,pBufferC);//copio C(A) en B
                            flag=1;
                        }
                        else if(order==1 && pFunc(pBufferA, pBufferB)>0)
                        {
                            pBufferC = pBufferA;//guardo elemento A en C
                            ll_set(this,i,pBufferB);//copio B en A
                            ll_set(this,i+1,pBufferC);//copio C(A) en B
                            flag=1;
                        }
                    }
                }
                while(flag==1);//rompo el ciclo
                auxReturn=0;
            }
        }
    }
    return auxReturn;
}
