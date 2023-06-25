import tcp_client as tc
import myexception
import socket
import sys
from parsing import *
from player import Player
from movement import Movement
from items import Items
from macro import *
from level import levelUp
from fork import *

class AI:
    def __init__(self, port:str, machine:str, name:str) -> None:
        """Run the AI script

        Args:
            port (int): Port parameter
            name (str): Team name
            machine (str): Machine parameter

        Returns:
            int: 1 if an error occurs, 0 if not
        """
        # Connecting to server
        try:
            self.client_socket = tc.connection(machine, port)
        except (socket.gaierror, ConnectionRefusedError) as e:
            raise myexception.Exception(e)
        self.client_socket.send((name + "\n").encode())
        self.itemHandling = Items(self.client_socket)
        self.player:Player
        self.setPlayer(name)
        self.move = Movement(self.client_socket, self.player.item_needed)

    def setPlayer(self, name:str) -> None:
        recv_data = self.client_socket.recv(1024)
        print(recv_data.decode(), end="")
        rcv_data = self.client_socket.recv(1024)
        tmp = rcv_data.decode().split("\n")
        map_size = tmp[1].split(" ")
        try:
            self.client_socket.send((f'Broadcast {name}').encode())
            self.player = Player(tmp[0], (map_size[0], map_size[1]), 1)
        except IndexError:
            print(f"Error while creating the player, check if team name is correct", file=sys.stderr)

    def rcvServerResponse(self) -> None:
        """Set the sight, invetory and update the team slot free
        """

        self.client_socket.send(("Look\n").encode())
        self.player.sight = parseLook(self.client_socket.recv(1024).decode()[2:-2])
        # print(f'sight = {self.player.sight}')
        # print(f'inventory = {self.player.inventory}')
        self.client_socket.send(("Connect_nbr\n").encode())
        self.player.nb_player = updateNbPlayer(self.client_socket.recv(1024).decode())
        # print(f'nbplayer = {self.player.nb_player}')
        self.client_socket.send(("Inventory\n").encode())
        self.player.inventory = parseInventory(self.client_socket.recv(1024).decode()[2:-2])

    def level_up(self) -> None:
        if levelUp(self.player.obj_list, self.player.sight[0]):
            self.client_socket.send(("Incantation\n").encode())
            # if self.client_socket.recv(1024).decode() != "ko":
            print(self.client_socket.recv(1024).decode())

    def push(self) -> None:
        if self.player.multiplePlayerTile():
            self.client_socket.send(("push\n").encode())
            rcv_data = self.client_socket.recv(1024)

    def reproduction(self) -> None:
        if check_if_need_fork(self.player, self.player.sight):
            self.client_socket.send("fork\n".encode())
            rcv_data = self.client_socket.recv(1024)

    def playerAction(self) -> None:
        self.itemHandling.takeItem(self.player.sight, self.player.item_needed, self.player.needList, self.player.inventory)
        self.push()
        self.level_up()
        self.reproduction()
        self.itemHandling.needsFood(self.player.inventory, self.player.needList)
        self.move.handleMovement(self.player.sight, self.player.needList)

    def run_ai(self) -> int:
        try:
            while True:
                self.rcvServerResponse()
                self.playerAction()
                print(self.player.inventory)
        except KeyboardInterrupt:
            return SUCCESS
        except BrokenPipeError:
            print("Your are dead !")
            return FAILURE
        return SUCCESS