#include "Game.h"
// Startup
Game::Game()
{
	// ������ �ʱ�ȭ �� ����
	this->InitWindowPointer();
	this->InitWindow();

	// Player �ʱ�ȭ
	this->InitPlayer();

	// Enemy �ʱ�ȭ
	this->InitEnemy();
	this->InitSpawn();

	// Point �ʱ�ȭ
	this->Point = 0;

	// Font �ʱ�ȭ
	this->InitFont();

	// Text �ʱ�ȭ
	this->InitPointText();

	this->InitGameOverText();

	// GameOverState �ʱ�ȭ
	this->GameOverState = false;
}

void Game::InitWindowPointer()
{
	// ������ ���� �ʱ�ȭ
	this->Window = nullptr;
}

void Game::InitWindow()
{	
	// ������ ���� ����
	this->Window = new RenderWindow(VideoMode(1280, 720), "Avoid Game", Style::Titlebar | Style::Close);
	
	// �����ϰ� �ݺ� ����
	this->Window->setFramerateLimit(60);


}

// Update
const bool Game::Running() const
{
	return this->Window->isOpen();
}

void Game::EventHandler()
{
	// �̺�Ʈ �߻� ����
	while (this->Window->pollEvent(Event)) {
		// �̺�Ʈ ���� �Ǵ�
		switch (Event.type) {
			//����
		case Event::Closed:
			this->Window->close();
			break;
		case Event::KeyPressed:
			if (Event.key.code == Keyboard::Escape) this->Window->close();
			break;
		}
	}
}

void Game::Update()
{
	this->EventHandler();
	
	if(!this->GameOverState)
	{
		this->UpdatePlayer();
		this->UpdateEnemy();
		this->CollisionCheck();
		this->UpdatePointText();
	}
}

// Render
void Game::Render()
{
	// Clear => �� ����Ʈ�� �� �ٽ� ĥ�� ����� �� => ������ �����ִ� ȿ���� �� ���� 
	this->Window->clear(Color(60, 60, 60, 255));

	// Draw Player
	this->Window->draw(this->Player);

	// Draw Enemy
	for (int i = 0; i < this->EnemyArray.size(); i++) {
		this->Window->draw(this->EnemyArray[i]);
	}

	// Draw Text
	this->Window->draw(this->PointText);

	// Display
	this->Window->display(); // ����
}

// Shut Down
Game::~Game()
{
	this->DeleteWindow();

}

void Game::DeleteWindow()
{
	// ������ �޸𸮿��� ����
	delete this->Window;
}

// Player
void Game::InitPlayer()
{
	this->Player.setRadius(15.0f);
	this->Player.setFillColor(Color::Green);
	this->Player.setPosition(this->Window->getSize().x/2-15.0f, this->Window->getSize().y/2-15.0f);

}

void Game::UpdatePlayer()
{
	if (Keyboard::isKeyPressed(Keyboard::Left)) {
		this->Player.move(-5.0f, 0.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Right)) { // elas if ���� �����¿츸 �� , �밢 X
		this->Player.move(5.0f, 0.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Up)) {
		this->Player.move(0.0f, -5.0f);
	}
	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		this->Player.move(0.0f, 5.0f);
	}
}

// Enemy
void Game::InitEnemy()
{
	this->Enemy.setSize(Vector2f(30.0f, 30.0f));
	this->Enemy.setFillColor(Color::White);
	this->Enemy.setPosition(100, 100);
}

void Game::InitSpawn()
{
	this->EnemyMax = 600;
	this->IntervalMax = 5.0f;
	this->IntervalStart = 0.0f;
}

void Game::SpawnEnemy()
{
	this->Enemy.setPosition(static_cast<float>(rand() % 1280),0.0);
	this->EnemyArray.push_back(this->Enemy);
}

void Game::UpdateEnemy()
{
	// Enemy Maximum
	if (this->EnemyArray.size() <= this->EnemyMax) {
		// Enemy Spawn Interval Delay
		if (this->IntervalMax <= this->IntervalStart) {
			this->SpawnEnemy();
			this->IntervalStart = 0.0f;
		}
		else {
			this->IntervalStart += 1.0f;
		}
	}

	for (int i = 0; i < this->EnemyArray.size(); i++) {
		this->EnemyArray[i].move(0.0f, 6.0f);
	}

	for (int i = 0; i < this->EnemyArray.size(); i++) {
		// Window �ٱ����� ����� Enemy ����
		if (this->EnemyArray[i].getPosition().y >= this->Window->getSize().y) {
			EnemyArray.erase(this->EnemyArray.begin() + i);
			// �����Ǵ� Enemy ���� => ����
			Point++;
		}
	}
}

// Collision Check
void Game::CollisionCheck()
{
	for (int i = 0; i < EnemyArray.size(); i++)
	{
		if (this->Player.getGlobalBounds().intersects(this->EnemyArray[i].getGlobalBounds())) {
			// �浹 : ture, ��������
			this->GameOverState = true;
			this->PrintGameOverText();
		}

	}
}

// Font
void Game::InitFont()
{
	if (this->Font.loadFromFile("Font/NanumGothicBold.ttf")) {
		cout << "Load Complete" << endl;
	}
	else {
		cout << "Load Fail" << endl;
	}
}

// Text
void Game::InitPointText()
{
	this->PointText.setFont(this->Font);
	this->PointText.setCharacterSize(20);
	this->PointText.setFillColor(Color::White);
	this->PointText.setPosition(this->Window->getSize().x-80, this->Window->getSize().y-30);
}

void Game::UpdatePointText()
{
	stringstream pt;

	pt << "Point : " << Point;

	this->PointText.setString(pt.str());
}

void Game::InitGameOverText()
{
	this->GameOverText.setFont(this->Font);
	this->GameOverText.setCharacterSize(200);
	this->GameOverText.setFillColor(Color::Red);
	this->GameOverText.setPosition(this->Window->getSize().x/2-250, this->Window->getSize().y/2-100);
}

void Game::PrintGameOverText()
{
	stringstream pt;

	pt << "Game Over";

	this->GameOverText.setString(pt.str());
}