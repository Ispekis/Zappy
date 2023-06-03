import getopt
import myexeption

def parse_data(argv):
    port = None
    name = None
    machine = None
    shortopts = "p:n:h:"

    args, values = getopt.getopt(argv[1:], shortopts)
    for current_arg, current_value in args:
        if current_arg in "-p":
            if (port != None):
                raise myexeption.Exception("duplicated port's option")
            try:
                port = int(current_value)
            except:
                raise myexeption.Exception("drovide a valid port")
        elif current_arg in "-n":
            if (name != None):
                raise myexeption.Exception("duplicated name's option")
            name = current_value
        elif current_arg in "-h":
            if (machine != None):
                raise myexeption.Exception("duplicated machine's option")
            machine = current_value

    # Check if all values are valid
    if (port == None or port < 0):
        raise myexeption.Exception("provide a valid port")
    if (name == None):
        raise myexeption.Exception("provide a name")
    if (machine == None):
        machine = "localhost"
    return port, name, machine