#include <iostream>

#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

#include"Game.h"

int main()
{
	// 랜덤값 사용 시작 : 초기값 설정
	// time값 사용 : 실행할 때 마다 초기값을 다른값으로 사용
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


