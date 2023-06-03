import tcp_client as tc
from macro import *
import myexeption
import socket

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
    # while True:
    rcv_data = client_socket.recv(1024)
    print(rcv_data.decode())
    client_socket.send(name.encode())
    while True:
        continue

    return SUCCESS