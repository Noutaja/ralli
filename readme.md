# ralli
 
A small rally racing game. Made with C++.
![Ralli screenshot](/images/ralli.png)

## Features
* Racing!
* Fastest time tracking
* Custom tracks
* Console interface
* 4 tracks out of the box

## How to play
The goal of the game is to END YOUR TURN on an F tile; passing through doesn't count.
The car (represented by the letter O) has speed on both x and y axis, and you can change one of those speeds by one on a given turn.
The keys 2, 4, 6 and 8 are used the change speeds, while 5 keeps your current speed. Alternate control scheme is wasd+space.

## Custom tracks
The game supports custom tracks. They can be loaded by dragging a .trk file onto the executable.
The track files are simple to make. They have the following layout:
```
startX startY record
mapdata
```
You can open one of the included tracks in notepad for reference.

## To-do
* Remake the rendering to get rid of flickering
* More racing features
