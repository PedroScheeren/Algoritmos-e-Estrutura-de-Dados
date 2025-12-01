#include <stdio.h>
#include <stdlib.h>


 struct ListNode {
    int val;
    struct ListNode *next;
 };
 
struct ListNode* rotateRight(struct ListNode* head, int k);
struct ListNode *girar(struct ListNode *head);

int main(){




    return 0;
}


struct ListNode* rotateRight(struct ListNode* head, int k) {
    
    struct ListNode *aux = head;    //ponteiro auxialar para receber a cabeça
    int q = 1;  //divisor de K para conferir o resto

    if (!head || !head->next || k==0){      //aqui estou conferindo se a lista esta null ou k = 0, se sim retorno a cabeça
        return head;
    }

    while (aux->next){
        aux = aux->next;
        q++;
    }
    
    k = k%q;

    if (k == 0)
        return head;

    for (int i = 0; i < k; i++)
        head = girar(head);

    return head;
        

}

struct ListNode *girar(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *atual = head;
    struct ListNode *anterior = NULL;

    while (atual->next != NULL) {
        anterior = atual;
        atual = atual->next;
    }

    anterior->next = NULL;
    atual->next = head;
    head = atual;

    return head;
}