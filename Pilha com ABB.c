#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
//criação da estrutura da pilha, com o valor e um ponteiro para o anterior
typedef struct pilhao{
int valor;
struct pilhao *anterior;}pilhao;
//criação do topo da pilha que se atualiza com a inserção
typedef struct toppilha
{
pilhao *topo;
}toppilha;
//cria a pilha apontando o topo dela pra null, ou seja, vazia
void criarPilha(toppilha *p){
p->topo = NULL;
}
//função para conferir se a pilha ta vazia, se esta recebendo null ele
//retorna 1 caso nao esteja vazia retorna 0
int pilhaVazia(toppilha *p){
if(p->topo == NULL)
return 1;
else
return 0;
}
//função para empilhar o elemento, recebe a pilha e o valor recebido la
//no main
void empilharElemento(toppilha *p, int valor){
//cria um ponteiro do tipo pilhao
pilhao *novo = malloc(sizeof(pilhao));
//o novo que aponta para o valor dele vai receber o valor que recebe
//la no main
novo->valor = valor;
//o novo que aponta o anterior vai receber o p que aponta para o topo
novo->anterior = p->topo;
//p que aponta o topo vai receber o novo que acabei de criar
p->topo = novo;
//dou free no novo
novo=NULL;
free(novo);}
//função para mostrar a pilha recebe apenas a pilha
void mostrarPilha(toppilha *p){
//se a função pilhavazia retornou zero (tem elemento)
if(pilhaVazia(p) == 0){
//cria um auxiliar do tipo pilhao
pilhao *aux;
//o auxiliar vai receber o p que aponta pro topo
aux = p->topo;
//enquanto o auxiliar nao achar um null
while (aux != NULL)
{
//printa o auxiliar setando valor
printf("\n %d", aux->valor);
//o auxiliar recebe o anterior dele
aux = aux->anterior;
}
printf("\n\n");
}
else{
printf("\n===Pilha vazia===\n");
}
}
//função para desempilhar elemento
void desempilha(toppilha *p){
//cria um auxiliar do tipo pilhao
pilhao *aux;
//o auxiliar recebe o p que seta topo
aux=p->topo;
//o p que seta topo recebe o auxiliar que seta o anterior
p->topo = aux->anterior;
//o auxiliar que seta o anterior recebe o null
aux->anterior=NULL;
//da free o auxiliar
free(aux);}
//menu principal
int menu(){
int opc;
printf("\n\n1 - Inserir em uma pilha");
printf("\n2 - Mostrar a pilha");
printf("\n3 - Inserir em uma arvore");
printf("\n4 - Consultar no em uma arvore");
printf("\n0 - Sair\n");
printf("\n-> ");
fflush(stdin);
scanf("%d", &opc);
return opc;
}
/*definição da estrutura que representará cada elemento da árvore
binária
será uma árvore que armazenará inteiros.*/
struct No{
int num; /*será uma árvore que armazenará inteiros*/
struct No *esq, *dir; /*ponteiros para fazer a ligação entre nós a
esquerda e a direita*/
};
typedef struct No No;
struct Arvore{
struct No *raiz; /*ponteiro que irá apontar para a raiz da árvore*/
};
typedef struct Arvore Arvore;
struct Elemento{
struct No *num;
struct Elemento *prox;
};
typedef struct Elemento Elemento;
/*registro do tipo Pilha contento um ponteiro "topo" do tipo Elemento
para controlar a pilha*/
struct Pilha{
struct Elemento *topo; /*aponta para o elemento qu esta no topo da
pilha*/};
typedef struct Pilha Pilha;
/*ponteiros auxiliares*/
No *aux;
No *aux1;
No *novo;
No *anterior;
Elemento *aux2;
Arvore* cria_arvore(){
/*alocação do ponteiro arv para controlar a árvore*/
Arvore* arv = (Arvore*) malloc(sizeof(Arvore));
if(arv != NULL){
arv->raiz= NULL; /*a pilha inicia-se vazia, portanto seu topo
é igual a NULL*/
}
return arv;
}
Pilha* cria_pilha(){
/*alocação do ponteiro pi para controlar a pilha*/
Pilha* pi = (Pilha*) malloc(sizeof(Pilha));
if(pi != NULL){
pi->topo= NULL; /*a pilha inicia-se vazia, portanto seu topo é
igual a NULL*/
}
return pi;
}
void insere_elemento(Arvore *arv) {
/*a cada inserção alocamos dinamicamente um espaço para um novo
elemento*/
No *novo =(No*) malloc(sizeof(No));
printf("Digite o numero a ser inserido na arvore: ");
scanf("%d",&novo->num);
novo->esq = NULL;
novo->dir = NULL;
/*caso a árvore esteja vazia, o elemento inserido será a raiz */
if(arv->raiz == NULL){
arv->raiz = novo;
/*caso a árvore já contenha algum elemento*/
}else{
/*variável para verificação*/
int achou;
/*aux aponta para o mesmo endereço de raiz*/aux = arv->raiz;
achou = 0;
/*é feita uma busca em toda árvore para saber onde novo deve ser
enserido*/
while(achou == 0){
/*caso o novo numero a ser inserido seja menor que aux-> num*/
if(novo->num < aux->num){
/*caso não aja nenhum elemento a esquerda de aux, novo
será inserido a esquerda dele*/
if(aux->esq == NULL){
aux->esq = novo;
achou = 1;
/*caso já exista um elemento a esquerda de aux, aux aponta
para este elemento e uma nova iteração será realizada*/
}else{
aux = aux->esq;
}
/*caso o novo numero a ser inserido seja maior ou igual a aux->
num*/
}else if(novo->num >= aux->num){
/*caso não aja nenhum elemento a direita de aux, novo será
inserido a direita dele*/
if(aux->dir == NULL){
aux->dir = novo;
achou = 1;
}else{
/*caso já exista um elemento a direita de aux, aux aponta
para este elemento e uma nova iteração será realizada*/
aux = aux->dir;
}
}
}
}
printf("\nNumero inserido na arvore!");
getch();
}
void consulta_no(Arvore *arv){
/*caso a árvore esteja vazia*/
if(arv->raiz == NULL){
printf("\nArvore Vazia!!");
}else{
int numero, achou;
printf("Digite o numero a ser consultado: ");
scanf("%d", &numero);
achou = 0;
/*aux aponta para o mesmo endereço de raiz*/aux = arv->raiz;
/*enquanto aux não apontar para NULL e achou for igual a
0 será feita uma busca na árvore*/
while(aux != NULL && achou == 0){
/*caso aux-> seja igual o número buscado*/
if(aux->num == numero){
printf("Numero %d encontrado!", numero);
achou = 1;
/*do contrário verificamos se o número está a direita
ou a esquerda de aux->num e atualizamos aux*/
}else if(numero < aux->num){
aux = aux->esq;
}else{
aux = aux->dir;
}
}
if(achou == 0) printf("Numero nao encontrado!");
}
getch();
}
int main (){
//aloca a pilha
toppilha *pi1 = malloc(sizeof(pilhao));
Arvore *arv = cria_arvore();
int opc = 0;
int valor = 0;
//cria ela
criarPilha(pi1);
do{
opc = menu();
switch (opc)
{
case 1:
printf("Insira o valor a ser empilhado: ");fflush(stdin);
scanf("%d", &valor);
empilharElemento(pi1, valor);
break;
case 2:
printf("\npilha 1 : ");
mostrarPilha(pi1);
break;
case 3:
insere_elemento(arv);
break;
case 4:
consulta_no(arv);
break;
}
}while(opc != 0);
return 0;
}
