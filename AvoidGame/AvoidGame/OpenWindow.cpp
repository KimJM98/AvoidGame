#include<SFML/Audio.hpp>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

using namespace sf;

void OpenWindow()
{
	RenderWindow Window(VideoMode(1280, 720), "Avoid Game", Style::Titlebar | Style::Close );

	Event Event;


	// 윈도우 창이 떠있을 때 프로그램이 종료 되지 않도록
	// 무한루프 -> while(true){}
	while (Window.isOpen())
	{
		// 이벤트 발생 감지
		while (Window.pollEvent(Event)) {
			// 이벤트 종류 판단
			switch (Event.type) {
				//동작
			case Event::Closed:
				Window.close();
				break;
			case Event::KeyPressed:
				if (Event.key.code == Keyboard::Escape) Window.close();
				break;
			}
		}
		// Clear => 흰 페인트로 위 다시 칠해 지우는 것 => 배경색을 정해주는 효과줄 수 있음 
		Window.clear(Color(60,60,60,255));
		// Display
		Window.display(); // 적용
	}
}
/*
	* 이벤트(Event) : 발생된 사건
	=> 소프트웨어, 어플리케이션의 상태 변화 : 사용자(가 바꾸어 줌) => 이로 인해 생긴 반응은 이벤트가 아님.

	* Interface 장치와 관련된 이벤트 : 키보드, 마우스, 터치스크린
		- 키보드 이벤트 : 키 입력(Press), 각각의 키 내용을 if로 구분
		- 마우스 이벤트 : 클릭(Press/Release), 휠 스크롤, 더블 클릭, 마우스의 움직임, 드래그(Press+Move)
		- 터치 스크린 : 터치, 스와이프, 핀치

	* Interface 장치와 관련이 없는 이벤트
		- 로딩 이벤트 : 데이터나 소프트웨어의 화면 구성 요소가 모두 화면에 띄워지면 발생되는 이벤트

	이벤트 발생시 이벤트 감지 => 해당 이벤트에 적절한 동작

	Event Listening : 이벤트 감지
	Event Handling : 감지된 이벤트에 대해서 적절한 동작
*/
