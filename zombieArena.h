#include <SFML/Graphics/BlendMode.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include "Zombies.h"

using namespace sf;

int createBackground(VertexArray& rVA, IntRect arena);

Zombie* createHorde(int numZombies, IntRect areana);