# Chess

A Chess game that can be played solo against the computer or between two devices as server and client.

X Windows


![This is an image](https://github.com/matthewJamesAbbott/Chess/blob/master/ChessWindow.png)


Terminal


![This is an image](https://github.com/matthewJamesAbbott/Chess/blob/bd3f1cef25c8cccd0c85fb408daf26480bd0f984/chess%20logo.png)

There are two executables which can be found in cmake-build-debug directory

one build with SDL functions and X Windows GUI or optional Terminal via input argument the other a pure Terminal game without SDL dependancy

compiled on linux 64 bit intel with cmake.


Chess --help
Usage: Chess [OPTION] ... [IP ADDRESS]
Chess will run with no arguments as a standalone game in XWindows or with arguements in the terminal as solo, client and server
   -ai                 run Chess in Terminal and play Computer AI
   -s                  run Chess as server
   -c [IP ADDRESS]     run Chess as client connecting to [IP ADDRESS]


Bottom left square changes between game and options (options in SDL are a work in progress)

Enter 10 in the terminal game to give the following

Welcome to Abbotts Chess 

Chess allows all regulation moves by asking the user for input of the four co-ordinates in succession
required for the move. Numeric and then alpha co-ordinates for the piece player wishes to move and then
numeric followed by alpha co-oridnates for square piece is to be moved to.

Castling is accomplished by using the kings starting position followed by the position the king would
land after move as co-ordinates. Rook will move to position next to king automatically. Castling is only
available if both left rook and king have not been moved over the game.

Enpassant is accomplished when a pawn is in correct position and an opposing pawn one square to the
left or right in its starting position moves two squares therefor overtaking the player pawns position.
The square that the opposing pawn moved over will become available as a move for the players pawn
allowing enpassant taking of pawns.

10 Help Screen you are seeing now 
11 Save Game State
12 Restore Game State
13 Reinitialize Board (new game)
14 Set Server to wait for Client
15 Connect to Server as Client
16 Reset Game and change side/colour
17 Clear Screen toggle

22 Take move back

9 Exit game

Please enter number for piece you wish to move or 10 for help


