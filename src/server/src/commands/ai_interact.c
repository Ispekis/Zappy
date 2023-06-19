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
            send_res_cd(client, COOLDOWN_TAKE, data->freq);
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
            send_res_cd(client, COOLDOWN_SET, data->freq);
        } else {
            dprintf(client->client.fd, "ko\n");
        }
    }
}

void ai_cmd_incantation(node_t *client, data_t *data,
char **params __attribute__((unused)))
{
    if (can_elevate(client, &data->map)
    && client->client.level < MAX_LEVEL) {
        dprintf(client->client.fd, "Elevation underway\n");
        set_cooldown_in_nanosec(client,
        sec_to_nanosec(((double) 7 / (double) data->freq)));
        client->client.is_elevating = true;
    } else {
        dprintf(client->client.fd, "ko\n");
    }
}
