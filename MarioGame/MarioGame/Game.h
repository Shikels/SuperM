#pragma once
class Game
{
private:

	const int width = 800;
	const int length = 500;
	int in_x;
	int in_y;
public:
	Game();
	~Game();
	void drawMario(int,int);
	void moveMario(int,int);
	void drawEnemys(int=0,int=0);


};

