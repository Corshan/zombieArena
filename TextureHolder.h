#ifndef textureHolder_h
#define textureHolder_h
#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;

class TextureHolder
{
public:
    TextureHolder(); //constructor
    static Texture& GetTexture(std::string const& filename); //retrieve texture for a given filename

private:
    std::map<std::string, Texture> m_Textures; //A map holding pairs of strings and Texture
    static TextureHolder* m_s_Instance; //pointer to the singleton
};

#endif