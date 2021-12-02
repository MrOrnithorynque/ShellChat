//Not fully working for the moment (will update soon)

# ShellChat (In progress)
ShellChat is a little program to chat with your friend and play simple games within the same network.</br>
>*(will MAYBE update to enable chat trough internet)*

</br>

# How to use :
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
 
- Launch the client binary
  ```bash
  ./ShellChat_client [IP ADRESS] [PORT]
  ```

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
 
### Windows/Mac/Linux compatibility
I want to dockerise the app, I'm not sure if I will take the time to do it but for the moment it is in a side of my head.

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
