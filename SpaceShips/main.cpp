//SpaceShips

//Biblioteki
#include "stdatx.h"
#include "wrog.h"
#include "pocisk.h"

//Deklaracja funkcji
void keyboard();

//Obiekty
sf::RenderWindow renderWindow(sf::VideoMode(1280, 720), "SpaceShips");
//sf::RenderWindow renderWindow(sf::VideoMode(1280, 720), "Gra 2D", sf::Style::Fullscreen);
sf::Event event;
wrog* enemy = new wrog[5];//Wrog
pocisk** bullet = new pocisk*[5];//Pocisk wroga

								 //Zmienne
								 //Statek
int statek_x = 500;
int statek_y = 580;

//Testowy pocisk
int t_pocisk_x = 0;
int t_pocisk_y = 0;

int main()
{
	sf::Clock clock;
	sf::Time t1 = clock.getElapsedTime();

	sf::Clock clock2;
	sf::Time t2 = clock2.getElapsedTime();

	//Inicjacja//
	renderWindow.setFramerateLimit(60);

	//Ladowanie tekstur
	sf::Texture t_tlo;
	if (!t_tlo.loadFromFile("grafika/tlo.png"))
		return EXIT_FAILURE;
	sf::Sprite tlo;
	tlo.setTexture(t_tlo);

	sf::Texture t_statek;
	if (!t_statek.loadFromFile("grafika/statek.png"))
		return EXIT_FAILURE;
	sf::Sprite statek;
	statek.setTexture(t_statek);
	//Inicjacja//

	//Tworzenie wrogow
	for (int i = 0; i < 5; i++)
	{
		enemy[i].stworz(i);
		enemy[i].pozycja(i * 250, 100);
	}

	//Tworzenie pociskow
	for (int i = 0; i < 5; ++i)
		bullet[i] = new pocisk[5];

	/*bullet[0][0].pozycja(0, 100);
	bullet[0][1].pozycja(250, 100);
	bullet[0][2].pozycja(500, 100);
	bullet[0][3].pozycja(750, 100);
	bullet[0][4].pozycja(1000, 100);

	bullet[1][0].pozycja(0, 200);
	bullet[1][1].pozycja(250, 200);
	bullet[1][2].pozycja(500, 200);
	bullet[1][3].pozycja(750, 200);
	bullet[1][4].pozycja(1000, 200);

	bullet[2][0].pozycja(0, 300);
	bullet[2][1].pozycja(250, 300);
	bullet[2][2].pozycja(500, 300);
	bullet[2][3].pozycja(750, 300);
	bullet[2][4].pozycja(1000, 300);*/

	

	//Fizyka gry---------------------------------------------------------------------------
	while (renderWindow.isOpen())
	{
		renderWindow.clear();//Czyszczenie ekranu

		sf::Time t1 = clock.getElapsedTime();
		sf::Time t2 = clock2.getElapsedTime();
		

		
			if (t2.asSeconds() > 0.5f)
			{
				for (int i = 0; i < 5; i++)
				{
				cout << t2.asSeconds() << endl;
				//enemy[i].pozycja(enemy[i].posx(), enemy[i].posy()+20);
				clock2.restart();
				}
			}
		
		
		keyboard();//Sprawdzanie klawiatury

		statek.setPosition(statek_x, statek_y);//Ustalenie pozycji statku

		

							 //Rysowanie sprite'ow
		renderWindow.draw(tlo);
		renderWindow.draw(statek);


		//Rysowanie wrogow
		for (int i = 0; i < 5; i++)
		{
			enemy[i].wyswietl(renderWindow);
		}
		


		//Zmiana pozycji pociskow

		enemy[3].pozycja(750, 400);

		//if(pocisk wystrzelony to nie strzelaj nim wiecej) etc
		/*
		for (int i = 0; i < 5; i++)
		{
			enemy[i].strzelaj(renderWindow, bullet, 0, enemy[i].posx() + 85, enemy[i].posy() + 140);
		}

		for (int i = 0; i < 5; i++)
		{
			enemy[i].strzelaj(renderWindow, bullet, 1, enemy[i].posx() + 85, enemy[i].posy() + 240);
		}

		for (int i = 0; i < 5; i++)
		{
			enemy[i].strzelaj(renderWindow, bullet, 2, enemy[i].posx() + 85, enemy[i].posy() + 340);
		}

		bullet[2][0].pozycja(sf::Mouse::getPosition(renderWindow).x, sf::Mouse::getPosition(renderWindow).y);
		*/

		
		

		//sf::Mouse::GetPosition(TestWindow).x;
		
		//system("cls");
		for (int i = 0; i<5; i++)
		{
			//cout << i<< ":" << enemy[i].posx() << "x" << enemy[i].posy() << endl;
		}
		//cout << "Pocisk" << t_pocisk_x << "x" << t_pocisk_y << endl;
		//cout << "Statek" << statek_x << "x" << statek_y << endl;

		/*
		

		*/
		//Klawisz B
		bullet[0][0].pozycja(t_pocisk_x, t_pocisk_y);

		//Wyswietlenie pociskow
		for (int i = 0; i < 5; i++)
		{
			bullet[0][i].wyswietl(renderWindow);
		}

		for (int i = 0; i < 5; i++)
		{
			bullet[1][i].wyswietl(renderWindow);
		}

		for (int i = 0; i < 5; i++)
		{
			bullet[2][i].wyswietl(renderWindow);
		}

		for (int i = 0; i < 5; i++)
		{
			bullet[3][i].wyswietl(renderWindow);
		}

		for (int i = 0; i < 5; i++)
		{
			bullet[4][i].wyswietl(renderWindow);
		}

		
		bullet[1][0].ruch();
		bullet[1][1].ruch();
		bullet[1][2].ruch();
		bullet[4][0].ruch();
		bullet[4][1].ruch();
		bullet[4][2].ruch();


		//Rysowanie calej gry
		renderWindow.display();

		for (int i = 0; i < 5; i++)
		{
			if (Collision::PixelPerfectTest(statek, enemy[i].zwroc(), 0))
			{
				std::cout << "[" << t1.asSeconds() << "] " << "Enemy" << std::endl;
			}
			else
			{
				//printf("0\n");
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (Collision::PixelPerfectTest(statek, bullet[i][j].zwroc(), 0))
				{
					std::cout << "[" << t1.asSeconds() << "] " << "Bullet" << std::endl;
				}
				else
				{
					//printf("0\n");
				}
			}
			
		}

		
		
		

		//_getch();
	}
	//_getch();
}

void keyboard()
{
	while (renderWindow.pollEvent(event)) {
		if (event.type == sf::Event::EventType::Closed)
			renderWindow.close();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			renderWindow.close();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		statek_x -= 5;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		statek_x += 5;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::T))
	{
		enemy[1].wystrzal(bullet);
		enemy[4].wystrzal(bullet);
		Sleep(200);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
	{
		t_pocisk_x = rand() % 1280;
		t_pocisk_y = rand() % 720;
		cout << t_pocisk_x << "x" << t_pocisk_y << endl;
	}
}
