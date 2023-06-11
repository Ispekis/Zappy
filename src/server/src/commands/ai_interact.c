/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_interact
*/

#include "server.h"

void ai_cmd_take_object(node_t *client, data_t *data, char **params)
{
    resource_t *tile_res = NULL;
    resource_t *inv_res = NULL;
    pos_t pos;

    if (params[0] == NULL) {
        dprintf(client->client.fd, "ko\n");
    } else {
        pos = client->client.pos;
        tile_res = get_resource_by_name_on_tile(params[0],
        &data->map[pos.y][pos.x]);
        inv_res = get_resource_by_name_in_inventory(params[0],
        &client->client.inventory);
        if ((tile_res != NULL && inv_res != NULL) && tile_res->quantity > 0) {
            tile_res->quantity--;
            inv_res->quantity++;
            dprintf(client->client.fd, "ok\n");
        } else {
            dprintf(client->client.fd, "ko\n");
        }
    }
}

void ai_cmd_set_object(node_t *client, data_t *data, char **params)
{
    resource_t *tile_res = NULL;
    resource_t *inv_res = NULL;
    pos_t pos;

    if (params[0] == NULL) {
        dprintf(client->client.fd, "ko\n");
    } else {
        pos = client->client.pos;
        tile_res = get_resource_by_name_on_tile(params[0],
        &data->map[pos.y][pos.x]);
        inv_res = get_resource_by_name_in_inventory(params[0],
        &client->client.inventory);
        if (tile_res != NULL && inv_res != NULL && inv_res->quantity > 0) {
            inv_res->quantity--;
            tile_res->quantity++;
            dprintf(client->client.fd, "ok\n");
        } else {
            dprintf(client->client.fd, "ko\n");
        }
    }
}

void ai_cmd_incantation(node_t *client, data_t *data,
char **params __attribute__((unused)))
{

}
