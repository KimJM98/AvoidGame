#include <iostream>

#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

#include"Game.h"

int main()
{
	// Start up
	Game Avoid;

	// Game Loop
	while (Avoid.Running()) {

		// Up date
		Avoid.EventHandler();

		// Render
		Avoid.Render();
	}
}

