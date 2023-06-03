import tcp_client as tc

def run_ai(port:int, name:str, machine:str):
    # Connecting to server
    client_socket = tc.connection(machine, port)
    print("port = %i" % (port))
    print("name = %s" % (name))
    print("machine = %s" % (machine))
    return 0