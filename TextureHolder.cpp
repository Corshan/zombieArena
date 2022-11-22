#include "TextureHolder.h"
#include <assert.h>

using namespace sf;
using namespace std;

TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder()
{
    assert(m_s_Instance == nullptr);
    m_s_Instance = this;
}

Texture& TextureHolder::GetTexture(std::string const& filename)
{
    //get a reference to the m_Textures map using the m_s_instance pointer
    auto& m = m_s_Instance->m_Textures;

    //create an iterator and search m for the passed in filename

    auto keyValuePair = m.find(filename);

    if (keyValuePair != m.end())
    {
        //if found return the texture
        return keyValuePair->second;
    }//if
    else
    {
        //create a new key value pair using a filname
        auto& texture = m[filename];
        //load the texture from file into map beside its filename
        texture.loadFromFile(filename);
        return texture;
    }//else
}//getTexture function



