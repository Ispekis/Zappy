import tcp_client as tc
from macro import *
import myexception
import socket
from player import Player

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
        print(f"Map size {map_size[0]}, {map_size[1]}", end="")

    def run_ai(self):
        try:    
            while True:
                self.client_socket.send(("Look\n").encode())
                self.player.sight = self.client_socket.recv(1024).decode()
                self.client_socket.send(("Inventory\n").encode())
                self.player.inventory = self.client_socket.recv(1024).decode()
                rcv_data = self.client_socket.recv(1024)
                if rcv_data.decode() == "dead\n":
                    break
        except KeyboardInterrupt:
            return SUCCESS
        return SUCCESS