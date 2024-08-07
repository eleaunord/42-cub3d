# 42-cub3d

## Introduction to Raycasting

Raycasting is a rendering technique to create a 3D perspective in a 2D map. Raycasting can go very fast, because only a calculation has to be done for every vertical line of the screen.

### 2D calculations

General principle : for every x of the screen (i.e. for every vertical stripe of the screen), send out a ray that starts at the player location and with a direction that depends on both the player's looking direction, and the x-coordinate of the screen. Then, let this ray move forward on the 2D map, until it hits a map square that is a wall. If it hit a wall, calculate the distance of this hit point to the player, and use this distance to calculate how high this wall has to be drawn on the screen: the further away the wall, the smaller it's on screen, and the closer, the higher it appears to be. 

Finding a wall : start at the player's position, and then all the time, check whether or not the ray is inside a wall. 
-> inside a wall (hit)  : the loop can stop, calculate the distance, and draw the wall with the correct height. 
-> not in a wall : trace it further: add a certain value to its position, in the direction of the direction of this ray, and for this new position, again check if it's inside a wall or not. Keep doing this until finally a wall is hit


Digital Differential Analysis (DDA) algorithm.

### Vectors 

Position of the player = direction vector ; every point of the line going from the pos of the player to where they are looking  is the sum of the position of the player, and a multiple of the direction vector. Points inside the screen.

Camera plane vector = line rpz with a single vector ; perpendicular on the directtion vector. Rpz the surface of the computer screen.

![alt text]([http://url/to/img.png](https://lodev.org/cgtutor/images/raycastingcamera.gif))

