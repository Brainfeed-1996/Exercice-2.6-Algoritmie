#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d'un nœud
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour inverser la liste de manière itérative
void inverserListeIterative(Node** head) {
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next; // Stocker le nœud suivant
        current->next = prev; // Inverser le pointeur du nœud actuel
        prev = current;       // Avancer prev et current d'un nœud
        current = next;
    }
    *head = prev; // Mettre à jour la tête de la liste
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

    // Inverser la liste de manière itérative
    inverserListeIterative(&head);

    printf("Liste inversée (itérative) : ");
    afficherListe(head);

    return 0;
}
