The proposed features that are implemented in our final version of 
Backgammon include:

- RNG through dice rolls.
- 2D Graphics that generate the image of the board and game state.
- Hitting/Entering ("capturing") pieces / determining what rolls are usable.
  Possible moves visually reflected in the "possible" command.
- Points system that keeps track of scores and determines winners.
- A doubling cube that multiplies the scores/increases the stakes. 

There is only keyboard/console input that currently works with our 
game so far, and not mouse input/interaction.

The class heirarchy that we ended up with is a main function that 
sets up the model and controller and view and gives control to the
controller. The IController interface is implemented by TextController,
which is the main controller we use, and contains a reference to the
model and view. The Model contains all the game data, which includes the
Board, both dice, the doubling cube, the points, both players, the color of
the victor (if there is one), and vectors of pieces that correspond to "captured" 
pieces. The Boardcontains a vector of Spaces that create the Board, and vectors 
of Pieces that are either captured or beared off into the end zone. The Spaces 
contain vectors of Pieces that correspond to the pieces that are currently on that 
Space, and a Color that specifies the color that the space currently is occupied by
(either BLACK, WHITE or EMPTY). The VisualBoard is used by the TextController to 
generate the visuals through a seperate setup involving SDL drawing graphics to a window. 
An array of values that represent the spacees, dice, indicators, and capture spots are taken
in by a function that draws them onto the window. When the user inputs a command, its effect
is reflected in the visual window.



The project allocates memory through the use of smart pointers (for the most part. We had to use new in some parts, but
those were easily taken care of with a quick delete). Thanks to the C++11 std smart pointers, we were able to get
0 bytes of data definitely lost, 0 bytes of data indirectly lost, 0 bytes of data possibly lost, and 0 bytes of data
suppressed according to Valgrind. However, also according to Valgrind, we have 2,976 bytes in 25 blocks STILL REACHABLE.
At first we were concerned, but after going to Valgrind's website and finding this page:
http://valgrind.org/docs/manual/faq.html#faq.reports
According to sections 4.1 and 5.2, the still reachable should be ok. So we believe that this program for the most
part has dynamic memory management.
