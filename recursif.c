#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d'un nœud
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour inverser la liste de manière récursive
Node* inverserListeRecursive(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* rest = inverserListeRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

// Fonction pour ajouter un nœud à la liste
void ajouterNoeud(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Fonction pour afficher la liste
void afficherListe(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // Ajouter des nœuds à la liste
    ajouterNoeud(&head, 5);
    ajouterNoeud(&head, 4);
    ajouterNoeud(&head, 3);
    ajouterNoeud(&head, 2);
    ajouterNoeud(&head, 1);

    printf("Liste originale : ");
    afficherListe(head);

    // Inverser la liste de manière récursive
    head = inverserListeRecursive(head);

    printf("Liste inversée (récursive) : ");
    afficherListe(head);

    return 0;
}
