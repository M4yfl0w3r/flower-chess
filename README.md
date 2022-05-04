## Flower Chess 

**Language**: C++ <br/>
**Library**: SFML <br/>

[Pieces images](https://commons.wikimedia.org/wiki/Category:PNG_chess_pieces/Standard_transparent)

### How to run

- Install SFML library (Arch Linux)<br/>

  ```
  sudo pacman -S sfml
  ```

- Install CMake (Arch Linux)

  ```
  sudo pacman -S cmake
  ```

- Clone the repository

  ```
  git clone https://github.com/M4yfl0w3r/flower-chess.git
  ```

- In flower-chess directory create build directory
  
  ```
  mkdir build 
  ```

- Go to the build directory and type
  
  ```
  cmake ..
  ```

- Run generated makefile

  ```
  make 
  ```

- Run the game 

  ```
  ./flower-chess
  ```


<br/>

### Known bugs
- if piece\_1 capture piece\_2 (then if you click random piece it will capture piece_1)

<br/>

### To do
- get rid of multiple map
- change pawn to other piece 
- king have to be captured to win a game
- add check



