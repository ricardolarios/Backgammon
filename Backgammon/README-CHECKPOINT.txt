11/9/17 Backgammon Release by Group BCC

NOTE:
Makefile may currently only work with CLion.

Checklist of features (from proposal):
- RNG through the dice rolls
- 2D graphics, which will generate the image of the board/player pieces
- Working implementation of the capture pieces mechanic and determining which rolls are useable
- A points system to keep track of the scores between games and determine a winner
- A doubling cube, which will act as a score multiplier that the players can decide to use
- If possible, deterministic AI for the user to play against

Implemented features:
- Board spaces and player pieces objects, with different colors for each side
- Semi-determining the useable rolls (pieces won't move without valid roll)
- Points system (basic keeping count, adding points to player totals, returning winner, and creating new scoreboards on followup games)
- Doubling cube doublable up to 64 and connects to the points system (function to be called at the end of the game will multiply int score in Points by the currentvalue of the DoublingCube)
- Dice able to roll and double (number of dice) if their values are the same

Remaining features:
- 2D graphics
- Dice implementation into game
- Capturing zone/pieces not implemented yet
- Finish determining the useable roll
- Moving pieces
- Finishing the commands for being able to run a game, so that it does not crash.
- Finishing implementing methods.

Unexpected Difficulties:
- Moving pieces can throw exceptions
- Hard to implement 2D graphics (currently)

Resulting Changes:
- Text output in place of the visual (currently)
- Changing from OpenGL to SDL for graphics
