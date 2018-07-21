# Prisoners-Dilemma

## AIM OF SOFTWARE:
To read and write files that can be interpreted as diffirent strategies for approaching the "prisoner's dilemma".

## Skills Demonstarted

A list of the skills demonstrated in the codebase.

* File IO
* Multi-threading
* Script Interpretation and Parsing
* basic C++ functionality (looping, memory management, data structures, etc...)

## Instructions

### Running the Project
Visual Studio is required to generate the executables, to generate them slect your configuration and platform and hit build or debug.
### Getting Started
When first started the user is provided with the option to choose to either generate strategies or generate them.
### Generating Strategies
When Generating Strategies, the user will be asked to pick a number of files to generate and the number of commands within those files, all files are written to the Strategies folder and are named Strategy_(x).txt where (x) is the id number of the file being generated starting with 0
### Testing the Strategies
When choosing to test, the user is asked to pick the number of strategies to be read and whether or not to automatically reading them. If the user decided to read the strategies automatically, the program looks for strategies named Strategy_(x).txt the Strategies folder where (x) is the file number, starting from 0 and going up to the number of files being read -1.
#### Single Game and Tournament Game
After the strategies are read they can be used in games, the user can pick between a single game and a tournament. When a single game is picked, only one match up as created and all files not needed for the match up will be ignored. When a tournament is picked all possible match ups are picked with the exception of a strategy being played against itself.
#### Individual strategies and Gang Strategies
Next, the user is offered to choose what sort of games to test. Individual strategies tests one strategy against annother, wheras gang strategies will test 5 strategies against each other where every member of a gang chooses whether or not to betray, and the majority decision is picked in the end.
