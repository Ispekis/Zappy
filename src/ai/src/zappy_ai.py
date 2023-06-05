import tcp_client as tc
from macro import *
import myexeption
import socket
from map import Map
from team import Team

def init_value(nb_player, x, y):
    tm = Team(int(nb_player) + 1)
    mp = Map(x, y)
    print(f'map size = x = {mp.map_x} y = {mp.map_y}')

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

    # print("port = %i" % (port))
    # print("name = %s" % (name))
    # print("machine = %s" % (machine))
    rcv_data = client_socket.recv(1024)
    print(rcv_data.decode(), end="")
    client_socket.send((name + "\n").encode())
    # while True:
        # rcv_data = client_socket.recv(1024)
        # print(rcv_data.decode(), end="")
        # continue
    rcv_data = client_socket.recv(1024)
    value = rcv_data.decode().split("\n")
    map_size = value[1].split(" ")
    init_value(value[0], map_size[0], map_size[1])
    return SUCCESS