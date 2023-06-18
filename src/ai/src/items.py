import sys
import socket

class Items:
    def __init__(self, client_socket:socket) -> None:
        self.client_socket:socket = client_socket
    
    def takeItem(self, sight:str, objectives:list, needs:list) -> None:
        for i in range(len(objectives)):
            try:
                sight[0].index(objectives[i])
                self.client_socket.send(("Take " + objectives[i] + "\n").encode())
            except ValueError:
                continue