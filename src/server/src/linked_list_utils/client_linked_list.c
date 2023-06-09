/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** client_linked_list
*/

#include "server.h"

void print_client_list(node_t *head)
{
    node_t *current = head;

    while (current != NULL) {
        printf("Client fd: %i\n", current->client.fd);
        printf("Client is con: %i\n", current->client.is_conn);
        printf("Client is graph: %i\n\n", current->client.is_graphic);
        current = current->next;
    }
}

void remove_client_node(node_t **head, int fd)
{
    node_t *current = *head;
    node_t *previous = NULL;

    while (current != NULL) {
        if (current->client.fd == fd) {
            if (previous == NULL) {
                *head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

node_t *add_client_node(node_t **head)
{
    node_t *new_node = malloc(sizeof(node_t));
    node_t *current = NULL;

    new_node->client.fd = -1;
    new_node->client.is_conn = false;
    new_node->client.is_graphic = false;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
    } else {
        current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    return new_node;
}