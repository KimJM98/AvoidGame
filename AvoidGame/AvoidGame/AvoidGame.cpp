#include <iostream>

#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

#include"Game.h"

int main()
{
	// ������ ��� ���� : �ʱⰪ ����
	// time�� ��� : ������ �� ���� �ʱⰪ�� �ٸ������� ���
	srand(time(NULL));

	// Start up
	Game Avoid;

	// Game Loop
	while (Avoid.Running()) {

		// Up date
		Avoid.Update();

		// Render
		Avoid.Render();
	}
}


