import getopt
from myexeption import CustomException

def parse_data(argv):
    port = None
    name = None
    machine = None
    shortopts = "p:n:h:"

    args, values = getopt.getopt(argv[1:], shortopts)
    for current_arg, current_value in args:
        if current_arg in "-p":
            if (port != None):
                raise CustomException("duplicated port's option")
            try:
                port = int(current_value)
            except:
                raise CustomException("drovide a valid port")
        elif current_arg in "-n":
            if (name != None):
                raise CustomException("duplicated name's option")
            name = current_value
        elif current_arg in "-h":
            if (machine != None):
                raise CustomException("duplicated machine's option")
            machine = current_value

    # Check if all values are valid
    if (port == None or port < 0):
        raise CustomException("provide a valid port")
    if (name == None):
        raise CustomException("provide a name")
    if (machine == None):
        machine = "localhost"
    return port, name, machine