#include "Game.h"

Game::Game()
{
	// 윈도우 초기화 및 생성
	this->InitWindowPointer();
	this->InitWindow();

	// Player 초기화
	this->InitPlayer();
}

Game::~Game()
{
	this->DeleteWindow();

}

void Game::InitWindowPointer()
{
	// 포인터 변수 초기화
	this->Window = nullptr;
}

void Game::InitWindow()
{	
	// 윈도우 동적 생성
	this->Window = new RenderWindow(VideoMode(1280, 720), "Avoid Game", Style::Titlebar | Style::Close);

	
}

void Game::DeleteWindow()
{
	// 윈도우 메모리에서 제거
	delete this->Window;
}

const bool Game::Running() const
{
	return this->Window->isOpen();
}

void Game::EventHandler()
{
	// 이벤트 발생 감지
	while (this->Window->pollEvent(Event)) {
		// 이벤트 종류 판단
		switch (Event.type) {
			//동작
		case Event::Closed:
			this->Window->close();
			break;
		case Event::KeyPressed:
			if (Event.key.code == Keyboard::Escape) this->Window->close();
			break;
		}
	}
}

void Game::Render()
{
	// Clear => 흰 페인트로 위 다시 칠해 지우는 것 => 배경색을 정해주는 효과줄 수 있음 
	this->Window->clear(Color(60, 60, 60, 255));

	// Draw
	this->Window->draw(this->Player);

	// Display
	this->Window->display(); // 적용
}

// Player
void Game::InitPlayer()
{
	this->Player.setRadius(15.0f);
	this->Player.setFillColor(Color::Green);
	this->Player.setPosition(625,550);

}