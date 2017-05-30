#pragma once

#include "stdafx.h"
#include "pocisk.h"

class wrog
{
public:
	int x = 0;
	int y = 0;
	int id_wroga = 0;
	int id_pocisku = 0;
	//int zuzyty = 0;
	int id_poc = 0;
	bool uzytypocisk[8];//true=used, false=non-used
	int w_kierunek = 0;
	int w_predkosc = 4;
	string tekstury[5] = { "grafika/wrogus1.png","grafika/wrogus2.png","grafika/enemy1_dostal.png","grafika/wrogus2_dostal.png","" };
	int hp = 100;
	int id_skin = 0;

	sf::Texture t_wrog;
	sf::Sprite s_wrog;

	int wrog::dodaj(int a, int b, int c, int d, int e);
	int wrog::stworz(int id, int id_skin);
	int wrog::pozycja(int a, int b);
	int wrog::wyswietl(sf::RenderWindow & renderWindow);
	int wrog::strzelaj(sf::RenderWindow & renderWindow, pocisk ** bullet, int id_pocisku, int x, int y);
	int wrog::wystrzal(pocisk ** bullet);
	int wrog::posx();
	int wrog::posy();
	int wrog::zmien_teksture();
	sf::Sprite wrog::zwroc();
	int wrog::ruch();
	int wrog::kolizja_sciana(sf::Sprite sprite1, sf::Sprite sprite2);
};