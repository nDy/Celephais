/*
 * TextureManager.hpp
 *
 *  Created on: May 30, 2015
 *      Author: ndy
 */

#ifndef UTILS_TEXTUREMANAGER_HPP_
#define UTILS_TEXTUREMANAGER_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class TextureManager {
private:
	/* Array of textures used */
	std::map<std::string, sf::Texture> textures;
public:
	TextureManager();

	/* Add a texture from a file */
	void loadTexture(const std::string& name, const std::string &filename);

	/* Translate an id into a reference */
	sf::Texture& getRef(const std::string& texture);

	virtual ~TextureManager();
};

#endif /* UTILS_TEXTUREMANAGER_HPP_ */
