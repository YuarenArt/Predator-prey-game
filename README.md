Predator-Prey Game is a thrilling step-by-step interactive simulation where players navigate a grid as either a predator or prey, aiming to survive against the odds. 

<h2>Game Environment</h2> The game environment is designed using Qt and C++. <h2>Game Features</h2> 
The game features a game board with various objects such as predators, prey, obstacles, etc. 
The goal of the game is to move the predator around the board in order to catch the prey. The predator and prey can only move to certain cells on the board, according to set rules. 

<h2>Technical Details</h2> 
The game consists of several classes, the main ones being:

<b>PredatorPreyGame</b> - the main game class, containing the game board, menu, control elements, etc.

<b>Field</b> - a class representing the game board. Contains a matrix of cells on which objects are located, and methods for moving them.

<b>ActorsInterface</b> - an interface describing basic methods for all objects located on the board.

<b>Predator</b> - a class representing the predator. Inherits from ActorsInterface.

<b>Prey</b> - a class representing the prey. Inherits from ActorsInterface.

<b>Zombie</b> - a class representing the zombie. Inherits from ActorsInterface.

<b>FieldSpriteVector</b> - a class representing a set of sprites that display the game board.

<b>FieldSprite</b> - a class representing a single sprite on the game board.

The game's main function initializes the game's objects and sets up the game's style, then starts the game loop. The game loop updates the game's state and re-renders the game board and other elements on each iteration. The game ends when the predator catches the prey or the player loses, at which point the game displays a game over or win message.

<h2>Getting Started</h2> To get a local copy of the project up and running, follow these steps:
Clone the repository

git clone https://github.com/your_username/Predator-Prey-Game.git

Open the project in Qt Creator 

or 

Microsoft Visual Studio with Qt extension

Build and run the project

<h2>Prerequisites</h2>

Qt 6.4.x or higher

C++14 or higher

<h2>Built With</h2>

Qt Creator - The IDE used for development

or

Microsoft Visual Studio with Qt extension
