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

![image](https://github.com/user-attachments/assets/52f8eb49-c171-4320-abf6-7dbf83123af6)

Direction of the rays = Sum(direction vector of the camera +  a part of the plane vector of the camera), For example the third red ray on the image, goes through the right part of the camera plane at the point about 1/3th of its length. So the direction of this ray is dir + plane*1/3. This ray direction is the vector rayDir, and the X and Y component of this vector are then used by the DDA algorithm.

### FOV
The two outer lines, are the left and right border of the screen, and the angle between those two lines is called the Field Of Vision or FOV. The FOV is determinated by the ratio of the length of the direction vector, and the length of the plane. 
Different FOV's:
  - If the direction vector and the camera plane vector have the same length, the FOV will be 90°
  - If the direction vector is much longer than the camera plane, the FOV will be much smaller than 90°, and you'll have a very narrow vision.
  - If the direction vector is shorter than the camera plane, the FOV will be larger than 90° (180° is the maximum, if the direction vector is close to 0), and you'll have a much wider vision, like zooming out

### Rotations

When the player rotates, the camera has to rotate, so both the direction vector and the plane vector have to be rotated. Then, the rays will all automaticly rotate as well.
To rotate a vector, multiply it with the rotation matrix :
[ cos(a) -sin(a) ]
[ sin(a)  cos(a) ]

