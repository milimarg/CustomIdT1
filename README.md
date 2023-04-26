# my_idt1

Prototype of id Tech 1 engine: move around in a pseudo-3D world, using x, y and z axis. <br>
Create a world more easily using a config file, a example is available below. <br>
The rendering is made using the CSFML library and a bit of OpenGL.

## Compilation

```shell
make re -C ./my_idt1/
gcc main.c -o my_idt1 -L./my_idt1/ -lmy-idt1 -lcsfml-graphics -lcsfml-window -lcsfml-system
```

## Config file

```
<SHAPE> <POS x, y, z> <SIZE x, y, z>
```

- `<SHAPE>`: shape to create
  - `rectangle` <br>
`more to come!`

```
rectangle 50 30 0 10 10 10
```

### Want to make it work? Check the wiki!
