//Not perfetlcy working for the moment (will update very soon)

# ShellChat (In progress)
ShellChat is a little program to chat with your friend and play simple games within the same network for __Linux__ and __Windows__.</br>
>*(will MAYBE update to enable chat trough internet)*

</br>

# How to use :
If you are on Linux follow the instructions bellow.
>note that if you don't want to install all the dependencies you can follow the Windows docker part.
- Build the project
  ```bash
  make
  ```

  Two binaries will be created :
  ```bash
  Binaries
  ├───ShellChat_server
  └───ShellChat_client
  ```

- Launch the server binary
  ```bash
  ./ShellChat_server [IP ADRESS] [PORT]
  ```
  And wait for the client(s) to connect.
 
- Launch the client(s) binary(ies)
  ```bash
  ./ShellChat_client [IP ADRESS] [PORT]
  ```
And now, if you are on Windows.
- Make sure you have docker installed.
- Switch to Linux containers.
- Build the project
  ```bash
  make docker
  ```
  This command will build the docker and launch it for you.</br>
  Now you are on a Linux environment so follow the Linux instruction you have seen upward.

</br>

# What is comming next ?
### Games
Yes, I want the possibility to play with other users on the same game. </br>
__But, which games ?__ </br>
  - Connect4
  - Tron
  - CityBomber (RTX EDITION)
  - Navy
  - And maybe a SFML game.

### Better interface
I will still keep a minimalist shell-like interface but probably give it a little bit more character.

</br>

# Doc
## ShellChat_server
Usage :</br>
	./ShellChat_server [IP_ADRESS] [PORT] [-OPTION]</br>

Options :</br>
	-h --help 	Display help.</br>
	-a --auto	Find host ip adress and available port.</br>
	-s --silent	No sound.</br>
 
## ShellChat_client
