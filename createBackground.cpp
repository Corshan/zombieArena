#include <SFML/Graphics.hpp>
#include "zombieArena.h"

int createBackground(VertexArray& rVA, IntRect arena)
{
    //How big is each tile/texture
    const int TILE_SIZE = 50;
    const int TILE_TYPE = 3;
    const int VERTS_IN_QUAD =4;

    int worldWidth = arena.width/TILE_SIZE;
    int worldHeight = arena.height/TILE_SIZE;

    //What type of primitive are we using?
    rVA.setPrimitiveType(Quads);

    //Set the size of the vertex array
    rVA.resize(worldWidth*worldHeight*VERTS_IN_QUAD);

    //start at the beginning of the vertex array
    int currentVertex = 0;
    srand((int)time(0));

    for (int w =0; w < worldWidth; w++)
    {
        for (int h = 0; h < worldHeight; h++)
        {
            //Position each vertex in the cureent quad
            rVA[currentVertex+0].position = Vector2f(w * TILE_SIZE, h*TILE_SIZE);

            rVA[currentVertex+1].position = Vector2f((w*TILE_SIZE) + TILE_SIZE, h* TILE_SIZE);

            rVA[currentVertex+2].position = Vector2f((w*TILE_SIZE) + TILE_SIZE, (h*TILE_SIZE) + TILE_SIZE);

            rVA[currentVertex+3].position = Vector2f((w * TILE_SIZE), (h*TILE_SIZE) + TILE_SIZE);

            if (h == 0 || h == worldHeight-1 || w == 0 || w ==worldWidth-1)
            {
                rVA[currentVertex+0].texCoords = Vector2f(0,0+TILE_TYPE*TILE_SIZE);
                rVA[currentVertex+1].texCoords = Vector2f(TILE_SIZE,0 +TILE_TYPE*TILE_SIZE);
                rVA[currentVertex+2].texCoords = Vector2f(TILE_SIZE,TILE_SIZE+TILE_TYPE*TILE_SIZE);
                rVA[currentVertex+3].texCoords = Vector2f(0, TILE_SIZE +TILE_TYPE *TILE_SIZE);
            }else
            {
                int mOrG = (rand()% TILE_TYPE);
                int verticalOffSet = mOrG *TILE_SIZE;

                rVA[currentVertex+0].texCoords = Vector2f(0, 0 +verticalOffSet);
                rVA[currentVertex+1].texCoords = Vector2f(TILE_SIZE,0 +verticalOffSet);
                rVA[currentVertex+2].texCoords = Vector2f(TILE_SIZE,TILE_SIZE +verticalOffSet);
                rVA[currentVertex+3].texCoords = Vector2f(0, TILE_SIZE +verticalOffSet);
            }

            //Position ready for next four vertices
            currentVertex = currentVertex+VERTS_IN_QUAD;
        }
    }

    return TILE_SIZE;
}