import tcp_client as tc
import myexception
import socket
import sys
from parsing import *
from player import Player
from movement import Movement
from macro import *

class AI:
    def __init__(self, port:str, machine:str, name:str):
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
        self.move = Movement()
        self.player:Player
        self.client_socket.send((name + "\n").encode())
        self.setPlayer()

    def setPlayer(self):
        recv_data = self.client_socket.recv(1024)
        print(recv_data.decode(), end="")
        rcv_data = self.client_socket.recv(1024)
        tmp = rcv_data.decode().split("\n")
        map_size = tmp[1].split(" ")
        self.player = Player(tmp[0], (map_size[0], map_size[1]), 1)

    def rcvServerResponse(self):
        """Set the sight, invetory and update the team slot free
        """

        self.client_socket.send(("Look\n").encode())
        self.player.sight = parseLook(self.client_socket.recv(1024).decode()[2:-2])
        # print(f'sight = {self.player.sight}', file=sys.stderr)
        self.client_socket.send(("Inventory\n").encode())
        self.player.inventory = parseInventory(self.client_socket.recv(1024).decode()[2:-2])
        # print(f'inventory = {self.player.inventory}')
        self.client_socket.send(("Connect_nbr\n").encode())
        self.player.nb_player = updateNbPlayer(self.client_socket.recv(1024).decode())
        # print(f'nbplayer = {self.player.nb_player}')

    def playerAction(self):
        self.client_socket.send((self.move.handleMovement() + "\n").encode())

    def run_ai(self):
        try:
            while True:
                self.rcvServerResponse()
                self.playerAction()
                rcv_data = self.client_socket.recv(1024)
                print(self.player.sight)
                if rcv_data.decode() == "dead\n":
                    break
        except KeyboardInterrupt:
            return SUCCESS
        return SUCCESS