/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** team_linked_list
*/

#include "server.h"

// void print_team_list(node_t *head)
// {
//     node_t *current = head;
//     while (current != NULL) {
//         printf("Team name: %s\n", current->team.name);
//         printf("Number of clients: %d\n\n", current->team.clients_nbr);
//         current = current->next;
//     }
// }

// void add_team_node(node_t **head, const char *name, int clients_nbr)
// {
//     node_t *new_node = malloc(sizeof(node_t));
//     node_t *current = NULL;

//     new_node->team.name = strdup(name);
//     new_node->team.clients_nbr = clients_nbr;
//     new_node->next = NULL;

//     if (*head == NULL) {
//         *head = new_node;
//     } else {
//         current = *head;
//         while (current->next != NULL) {
//             current = current->next;
//         }
//         current->next = new_node;
//     }
// }
