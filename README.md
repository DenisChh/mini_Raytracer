# mini_Raytracer

* A software that renders 3D images using Raytracing calculations and basic objects such as squares, spheres, planes,
cylinders and triangles
* To render a visible scene, you will need at least a light source, a camera and a basic geometric form
* The characteristics of these objects (suck as light direction/intensity, camera position/rotation, object position...)
must be written in a .rt configuration file. You can find some config files with different scenes to render in 
the 'scenes' folder, or create your own following certain rules described below
* The way raytracing works is it emulates real light behaviour after hitting objects in a scene. A fraction
of the light will get absorbed by the different objects in the scene, while another amount will be reflected. 
After a certain amount of reflections, the light will eventually hit the viewer's eye (here, the camera(s)) 
and the objects will appear in different colors to the viewer, depending on the portion of red/white/blue 
remaining in the light beam.

## Intallation
Use make to compile the project, then execute ./minirt. The executable needs a parameter which has to be a .rt
configuration file. You can use the ones provided in the 'scene' folder or create your own.

```bash
make
./mini_rt config_file.rt
```

## Usage
### Object Selection
* press 'l' to select a light source. Press 'l' again to change light source
* press 'o' to select an object in the scence. Press 'o' again to change object
* press 'c' to select the camera. Press 'tab' to change camera

### Moving
* Once a scene tool is selected, press 'zqsd' to move it along the x-axis
* press 'ctrl' to move the object down the y-axis
* press 'space' to move the object up the y-axis

### Rotating 
* Select an object
* Press 't' to toggle rotation mode
* Press 'zqsd' to rotate the object

### Other
* Press 'ESC' to close the window

## Rules to create a configuration file
* Each type of element can be separated by one or more line break(s)
* Each type of information from an element can be separated by one or more space(s)
* Each type of element can be set in any order in the file
* Elements which are defined by a capital letter can only be declared once in the scene
* Each element first's information is the type identifier (composed by one or two character(s)), followed by
all specific information for each object in a strict order such as :

**Ambient lighting**
```bash
A 0.2 255,255,255
```
* identifier: A
* ambient lighting ratio in range [0.0, 1.0]: 0.2
* R,G,B colors in range [0-255]: 255,255,255

**Camera**
```bash
C -50.0,0,20 0,0,1 70
```
* identifier: C
* x,y,z coordinates of the view point: -50.0,0,20
* 3d normalized orientation vector. In range [-1,1] for each x,y,z axis:
0.0,0.0,1.0
* FOV : Horizontal field of view in degrees in range [0,180]: 70

**Light**
```bash
L -40.0,50.0,0.0 0.6 10,0,255
```
* identifier: L
* x,y,z coordinates of the light point: -40.0,50.0,0.0
* the light brightness ratio in range [0.0,1.0]: 0.6
* (unused in mandatory part)R,G,B colors in range [0-255]: 10, 0, 255

**Sphere**
```bash
sp 0.0,0.0,20.6 12.6 10,0,255
```
* identifier: sp
* x,y,z coordinates of the sphere center: 0.0,0.0,20.6
* the sphere diameter: 12.6
* R,G,B colors in range [0-255]: 10, 0, 255

**Plane**
```bash
pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
```
* identifier: pl
* x,y,z coordinates of a point in the plane: 0.0,0.0,-10.0
* 3d normalized normal vector. In range [-1,1] for each x,y,z axis: 0.0,1.0,0.0
* R,G,B colors in range [0-255]: 0,0,225

**Cylinder**
```bash
cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
```
* identifier: cy
* x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6
* 3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis:
0.0,0.0,1.0
* the cylinder diameter: 14.2
* the cylinder height: 21.42
* R,G,B colors in range [0,255]: 10, 0, 255
