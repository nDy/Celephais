/*
 * TextureManager.cpp
 *
 *  Created on: May 30, 2015
 *      Author: ndy
 */

#include "TextureManager.hpp"

TextureManager::TextureManager() {
	// TODO Auto-generated constructor stub

}

void TextureManager::loadTexture(const std::string& name, const std::string& filename)
{
    /* Load the texture */
    sf::Texture tex;
    tex.loadFromFile(filename);

    /* Add it to the list of textures */
    this->textures[name] = tex;

    return;
}

sf::Texture& TextureManager::getRef(const std::string& texture)
{
    return this->textures.at(texture);
}

TextureManager::~TextureManager() {
	// TODO Auto-generated destructor stub
}

