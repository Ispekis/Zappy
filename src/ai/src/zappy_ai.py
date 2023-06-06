import tcp_client as tc
from macro import *
import myexeption
import socket
from player import Player

def run_ai(port:int, name:str, machine:str):
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
        client_socket = tc.connection(machine, port)
    except (socket.gaierror, ConnectionRefusedError) as e:
        raise myexeption.Exception(e)

    rcv_data = client_socket.recv(1024)
    client_socket.send((name + "\n").encode())
    rcv_data = client_socket.recv(1024)
    value = rcv_data.decode().split("\n")
    map_size = value[1].split(" ")
    tm = Player(name)
    print(f'{tm.food}')
    while True:
        rcv_data = client_socket.recv(1024)
        print(rcv_data.decode(), end="")
        continue
    return SUCCESS