#include "Play.h"     
#include "Editable.h"

// Return true to swap the spider for the rocket, false for normal game play
bool IsRocketTutorial() 
{
	return true;
}

// Controls the number of asteroids (in level 1)
int DefaultNumAsteroids()
{
	return 5;
}

// Controls the number of fiery meteors (in level 1)
int DefaultNumMeteors()
{
	return 1;
}

// Controls the initial movement speed of the spider when flying
float DefaultPlayerSpeed()
{
	return 5.5f;
}

// Controls the movement speed of asteroids
float DefaultAsteroidSpeed()
{
	return 4.0f;
}

// Controls the movement speed of fiery meteors
float DefaultMeteorSpeed()
{
	return 5.0f;
}

// Controls the movement of the rocket ship in the tutorial mode
void UpdatePlayerMovement( float& x, float& y, float& angle, float& speed )
{
	//speed = 2.5;
	//angle = 2.5;

	//          1.57      5.5
	x = x + sin(angle) * speed;
	y = y - cos(angle) * speed;

	// my version of the gradually slowing down rocket (friction effect)
	/*
	if (!(Play::KeyDown(VK_UP)) && speed >= 0)
	{
		speed -= 0.05;
	}
	*/

	speed *= 0.99f;

	if (Play::KeyDown(VK_RIGHT))
	{
		//x += 5;
		angle += 0.1f;
	}
	if (Play::KeyDown(VK_LEFT))
	{
		//x -= 5;
		angle -= 0.1f;
	}

	if (Play::KeyDown(VK_UP))
	{
		//y -= 5;
		speed += 0.1f;
	}
	

	if (Play::KeyDown(VK_DOWN))
	{
		//y += 5;
		//speed -= 0.1;
		speed *= 0.9f;
	}

	if (Play::KeyPressed(VK_SPACE))
	{
		CreateLaser(x, y, angle, speed + 10);
	}
}

// Controls the movement of lasers in the tutorial mode
void UpdateLaserMovement( float& x, float& y, float& angle, float& speed )
{
	x = x + sin(angle) * speed;
	y = y - cos(angle) * speed;
}

// Tests to see if a laser has collided with an asteroid
bool IsLaserCollidingWithAsteroid( float laserX, float laserY, float asteroidX, float asteroidY )
{
	float xDiff = asteroidX - laserX;
	float yDiff = asteroidY - laserY;

	float dist = sqrt(xDiff * xDiff + yDiff * yDiff);

	if (dist < 100)
	{
		return true;
	}

	// Can you declare a new float variable called dist and us it to calculate the distance?

	// Then you need to return true if dist is small enough to be considered to be colliding.

	return false;
	// Don't put any code after the return - it won't do anything!
}
