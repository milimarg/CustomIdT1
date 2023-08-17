# CustomIdT1

Prototype of Id Tech 1 engine: move around in a pseudo-3D world, using x, y and z axis. <br>
Create a world more easily using a config file, an example is available below. <br>
The rendering is made using the CSFML library and a bit of OpenGL.

## Compilation

```shell
make -C ./CustomIdT1/
gcc main.c -o CustomIdT1 -L./CustomIdT1/ -lmy-idt1 -lcsfml-graphics -lcsfml-window -lcsfml-system -lGL -lGLU -lm
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
