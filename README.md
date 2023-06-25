# Zappy project

<h2>Project: </h2>

The goal of this project is to create a network game where several teams confront on a tiles map containing resources.<br>
The winning team is the first one where at least 6 players who reach the maximum elevation.<br>
The following pages describe all the details and constraints.

<h2>Usages :</h2>

<h4>Zappy server</h4>

    ./zappy_server –help
    ./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq
        port        is the port number
        width       is the width of the world
        height      is the height of the world
        nameX       is the name of the team X
        clientsNb   is the number of authorized clients per team
        freq        is the reciprocal of time unit for execution of actions

<h4>Zappy gui</h4>

    ./zappy_gui –help
    ./zappy_ai -p port -h machine
        port    is the port number
        machine is the name of the machine; localhost by default

<h4>Zappy ai</h4>

    ./zappy_ai –help
    ./zappy_ai -p port -n name -h machine
        port    is the port number
        name    is the name of the team
        machine is the name of the machine; localhost by default

<h2>Contributors :</h2>

- [Ispekis](https://github.com/Ispekis)
- [Jouzep](https://github.com/Jouzep)
- [BRENNS](https://github.com/BRENNS)
- [zvillon](https://github.com/zvillon)
- [jerasbertine](https://github.com/jerasbertine)
- [Aibbey](https://github.com/Aibbey)