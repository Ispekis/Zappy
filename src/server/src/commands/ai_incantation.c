/*
** EPITECH PROJECT, 2023
** B-YEP-400-PAR-4-1-zappy-vincent.shao
** File description:
** ai_incantation
*/

#include "server.h"
#include "macro.h"

void remove_item_from_tile(int lvl, tile_t *tile)
{
    elevation_ritual_t requir = elev_requir[lvl - 1];

    tile->linemate.quantity -= requir.req_linemate;
    tile->deraumere.quantity -= requir.req_deraumere;
    tile->sibur.quantity -= requir.req_sibur;
    tile->mendiane.quantity -= requir.req_mendiane;
    tile->phiras.quantity -= requir.req_phiras;
    tile->thystame.quantity -= requir.req_thystame;
}

bool can_elevate(node_t *client, tile_t **map)
{
    client_t player = client->client;
    elevation_ritual_t requir = elev_requir[player.level - 1];

    int linemate = map[player.pos.y][player.pos.x].linemate.quantity;
    int deraumere = map[player.pos.y][player.pos.x].deraumere.quantity;
    int sibur = map[player.pos.y][player.pos.x].sibur.quantity;
    int mendiane = map[player.pos.y][player.pos.x].mendiane.quantity;
    int phiras = map[player.pos.y][player.pos.x].phiras.quantity;
    int thystame = map[player.pos.y][player.pos.x].thystame.quantity;
    int nb_player = get_nb_players_on_tile_w_lvl(player.pos, client,
    client->client.level);

    if (nb_player >= requir.req_player && linemate >= requir.req_linemate
    && deraumere >= requir.req_deraumere && sibur >= requir.req_sibur
    && mendiane >= requir.req_mendiane && phiras >= requir.req_phiras
    && thystame >= requir.req_thystame)
        return true;
    return false;
}

void elevate_player(node_t *client, data_t *data)
{
    if (can_elevate(client, data->map)) {
        remove_item_from_tile(client->client.level,
        &data->map[client->client.pos.y][client->client.pos.x]);
        client->client.level++;
        dprintf(client->client.fd, "Current level: %i\n",
        client->client.level);
        client->client.is_elevating = false;
    } else {
        dprintf(client->client.fd, "ko\n");
        client->client.is_elevating = false;
    }
}

void stop_incantation(node_t *player)
{
    player->client.is_elevating = false;
}
