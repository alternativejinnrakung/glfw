#include <iostream>
#include <ctime>
#include <memory>

#include <GLFW/glfw3.h>

#include "WorldClock.hpp"

const float ROTATE[12] = { 1.0f, 0.0f, 1.0f ,
						0.0f, 1.0f, 1.0f ,
						1.0f, 1.0f, 0.0f ,
						0.5f, 0.3f, 0.7f };

const int RED = 0;
const int YELLOW = 1;
const int GREEN = 2;
const int BLUE = 3;
const int WHITE = 4;
const int GRAY = 5;

const float COLOR[18] = { 0.0f, 0.3f, 0.3f ,
						0.0f, 0.0f, 0.3f ,
						0.3f, 0.0f, 0.3f ,
						0.3f, 0.3f, 0.0f ,
						-0.3f, -0.3f, -0.3f,
						0.3f, 0.3f, 0.3f };

void coloring(int color, float suffix) {
	glColor3f(suffix - COLOR[3 * color], suffix - COLOR[(3 * color) + 1], suffix - COLOR[(3 * color) + 2]);
}

void drawMovingBlock(int COLORTYPE) {
	glBegin(GL_TRIANGLE_FAN);
	coloring(COLORTYPE, 0.4f);
	glVertex3f(0.0625f, 0.0625f, -0.0625f);
	coloring(COLORTYPE, 0.5f);
	glVertex3f(0.0625f, -0.0625f, -0.0625f);
	coloring(COLORTYPE, 0.6f);
	glVertex3f(-0.0625f, -0.0625f, -0.0625f);
	coloring(COLORTYPE, 0.7f);
	glVertex3f(-0.0625f, 0.0625f, -0.0625f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.4f - COLOR[3 * COLORTYPE], 0.4f - COLOR[(3 * COLORTYPE) + 1], 0.4f - COLOR[(3 * COLORTYPE) + 2]);
	glVertex3f(0.0625f, 0.0625f, 0.0625f);
	glColor3f(0.5f - COLOR[3 * COLORTYPE], 0.5f - COLOR[(3 * COLORTYPE) + 1], 0.5f - COLOR[(3 * COLORTYPE) + 2]);
	glVertex3f(0.0625f, -0.0625f, 0.0625f);
	glColor3f(0.6f - COLOR[3 * COLORTYPE], 0.6f - COLOR[(3 * COLORTYPE) + 1], 0.6f - COLOR[(3 * COLORTYPE) + 2]);
	glVertex3f(-0.0625f, -0.0625f, 0.0625f);
	glColor3f(0.7f - COLOR[3 * COLORTYPE], 0.7f - COLOR[(3 * COLORTYPE) + 1], 0.7f - COLOR[(3 * COLORTYPE) + 2]);
	glVertex3f(-0.0625f, 0.0625f, 0.0625f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.4f - COLOR[3 * COLORTYPE], 0.4f - COLOR[(3 * COLORTYPE) + 1], 0.4f - COLOR[(3 * COLORTYPE) + 2]);
	glVertex3f(0.0625f, 0.0625f, -0.0625f);
	glColor3f(0.5f - COLOR[3 * COLORTYPE], 0.5f - COLOR[(3 * COLORTYPE) + 1], 0.5f - COLOR[(3 * COLORTYPE) + 2]);
	glVertex3f(0.0625f, 0.0625f, 0.0625f);
	glColor3f(0.6f - COLOR[3 * COLORTYPE], 0.6f - COLOR[(3 * COLORTYPE) + 1], 0.6f - COLOR[(3 * COLORTYPE) + 2]);
	glVertex3f(-0.0625f, 0.0625f, 0.0625f);
	glColor3f(0.7f - COLOR[3 * COLORTYPE], 0.7f - COLOR[(3 * COLORTYPE) + 1], 0.7f - COLOR[(3 * COLORTYPE) + 2]);
	glVertex3f(-0.0625f, 0.0625f, -0.0625f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.4f - COLOR[3 * COLORTYPE], 0.4f - COLOR[(3 * COLORTYPE) + 1], 0.4f - COLOR[(3 * COLORTYPE) + 2]);
	glVertex3f(0.0625f, 0.0625f, -0.0625f);
	glColor3f(0.5f - COLOR[3 * COLORTYPE], 0.5f - COLOR[(3 * COLORTYPE) + 1], 0.5f - COLOR[(3 * COLORTYPE) + 2]);
	glVertex3f(0.0625f, 0.0625f, 0.0625f);
	glColor3f(0.6f - COLOR[3 * COLORTYPE], 0.6f - COLOR[(3 * COLORTYPE) + 1], 0.6f - COLOR[(3 * COLORTYPE) + 2]);
	glVertex3f(0.0625f, -0.0625f, 0.0625f);
	glColor3f(0.7f - COLOR[3 * COLORTYPE], 0.7f - COLOR[(3 * COLORTYPE) + 1], 0.7f - COLOR[(3 * COLORTYPE) + 2]);
	glVertex3f(0.0625f, -0.0625f, -0.0625f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.4f - COLOR[3 * COLORTYPE], 0.4f - COLOR[(3 * COLORTYPE) + 1], 0.4f - COLOR[(3 * COLORTYPE) + 2]);
	glVertex3f(-0.0625f, 0.0625f, -0.0625f);
	glColor3f(0.5f - COLOR[3 * COLORTYPE], 0.5f - COLOR[(3 * COLORTYPE) + 1], 0.5f - COLOR[(3 * COLORTYPE) + 2]);
	glVertex3f(-0.0625f, 0.0625f, 0.0625f);
	glColor3f(0.6f - COLOR[3 * COLORTYPE], 0.6f - COLOR[(3 * COLORTYPE) + 1], 0.6f - COLOR[(3 * COLORTYPE) + 2]);
	glVertex3f(-0.0625f, -0.0625f, 0.0625f);
	glColor3f(0.7f - COLOR[3 * COLORTYPE], 0.7f - COLOR[(3 * COLORTYPE) + 1], 0.7f - COLOR[(3 * COLORTYPE) + 2]);
	glVertex3f(-0.0625f, -0.0625f, -0.0625f);
	glEnd();
}

void key_callback(GLFWwindow* window, int key, int scancode, int action) {
	if (key == GLFW_KEY_E && action == GLFW_PRESS) {
		std::cout << "I pressed E" << std::endl;
	}
}

void drawManyDot(int color) {
	float randx, randy, randz;
	for (int i = 0; i < 10; i++) {
		randx = ((static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * 2.0f) - 1.0f;
		randy = ((static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * 2.0f) - 1.0f;
		randz = ((static_cast <float> (rand()) / static_cast <float> (RAND_MAX)) * 2.0f) - 1.0f;
		glPushMatrix();
		glTranslatef(randx, randy, randz);
		glScalef(0.1f, 0.1f, 0.1f);
		drawMovingBlock(color);
		glPopMatrix();
	}
}

void drawFloorTile(int color) {
	glBegin(GL_TRIANGLE_FAN);
	coloring(color, 0.4f);
	glVertex3f(1.0f, 0.0f, -0.25f);
	coloring(color, 0.5f);
	glVertex3f(1.0f, -0.75f, -0.25f);
	coloring(color, 0.6f);
	glVertex3f(-1.0f, -0.75f, -0.25f);
	coloring(color, 0.7f);
	glVertex3f(-1.0f, 0.0f, -0.25f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	coloring(color, 0.4f);
	glVertex3f(1.2f, 0.0f, 0.25f);
	coloring(color, 0.5f);
	glVertex3f(1.2f, -0.75f, 0.25f);
	coloring(color, 0.6f);
	glVertex3f(-1.0f, -0.75f, 0.25f);
	coloring(color, 0.7f);
	glVertex3f(-1.0f, 0.0f, 0.25f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	coloring(color, 0.4f);
	glVertex3f(1.0f, 0.0f, -0.25f);
	coloring(color, 0.5f);
	glVertex3f(1.2f, 0.0f, 0.25f);
	coloring(color, 0.6f);
	glVertex3f(-1.2f, 0.0f, 0.25f);
	coloring(color, 0.7f);
	glVertex3f(-1.0f, 0.0f, -0.25f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	coloring(color, 0.4f);
	glVertex3f(1.0f, 0.0f, -0.25f);
	coloring(color, 0.5f);
	glVertex3f(1.2f, 0.0f, 0.25f);
	coloring(color, 0.6f);
	glVertex3f(1.2f, -0.75f, 0.25f);
	coloring(color, 0.7f);
	glVertex3f(1.0f, -0.75f, -0.25f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	coloring(color, 0.4f);
	glVertex3f(-1.0f, 0.0f, -0.25f);
	coloring(color, 0.5f);
	glVertex3f(-1.2f, 0.0f, 0.25f);
	coloring(color, 0.6f);
	glVertex3f(-1.2f, -0.75f, 0.25f);
	coloring(color, 0.7f);
	glVertex3f(-1.0f, -0.75f, -0.25f);
	glEnd();
}

void drawWallTile() {
	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(0.25f, 0.75f, -0.25f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(0.25f, -0.75f, -0.25f);
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(-0.25f, -0.75f, -0.25f);
	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.25f, 0.75f, -0.25f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(0.25f, 0.75f, 0.25f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(0.25f, -0.75f, 0.25f);
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(-0.25f, -0.75f, 0.25f);
	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.25f, 0.75f, 0.25f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(0.25f, 0.75f, -0.25f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(0.25f, 0.75f, 0.25f);
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(-0.25f, 0.75f, 0.25f);
	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.25f, 0.75f, -0.25f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(0.25f, 0.75f, -0.25f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(0.25f, 0.75f, 0.25f);
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(0.25f, -0.75f, 0.25f);
	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(0.25f, -0.75f, -0.25f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(-0.25f, 0.75f, -0.25f);
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(-0.25f, 0.75f, 0.25f);
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(-0.25f, -0.75f, 0.25f);
	glColor3f(0.8f, 0.8f, 0.8f);
	glVertex3f(-0.25f, -0.75f, -0.25f);
	glEnd();
}

void drawEnemyObject(int color) {
	glBegin(GL_TRIANGLE_FAN);
	coloring(color, 0.4f);
	glVertex3f(0.0625f, 0.0625f, -0.0625f);
	coloring(color, 0.5f);
	glVertex3f(0.0625f, -0.0625f, -0.0625f);
	coloring(color, 0.6f);
	glVertex3f(-0.0625f, -0.0625f, -0.0625f);
	coloring(color, 0.7f);
	glVertex3f(-0.0625f, 0.0625f, -0.0625f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	coloring(color, 0.4f);
	glVertex3f(0.0625f, 0.0625f, 0.0625f);
	coloring(color, 0.5f);
	glVertex3f(0.0625f, -0.0625f, 0.0625f);
	coloring(color, 0.6f);
	glVertex3f(-0.0625f, -0.0625f, 0.0625f);
	coloring(color, 0.7f);
	glVertex3f(-0.0625f, 0.0625f, 0.0625f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	coloring(color, 0.4f);
	glVertex3f(0.0625f, 0.0625f, -0.0625f);
	coloring(color, 0.5f);
	glVertex3f(0.0625f, 0.0625f, 0.0625f);
	coloring(color, 0.6f);
	glVertex3f(-0.0625f, 0.0625f, 0.0625f);
	coloring(color, 0.7f);
	glVertex3f(-0.0625f, 0.0625f, -0.0625f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	coloring(color, 0.4f);
	glVertex3f(0.0625f, 0.0625f, -0.0625f);
	coloring(color, 0.5f);
	glVertex3f(0.0625f, 0.0625f, 0.0625f);
	coloring(color, 0.6f);
	glVertex3f(0.0625f, -0.0625f, 0.0625f);
	coloring(color, 0.7f);
	glVertex3f(0.0625f, -0.0625f, -0.0625f);
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	coloring(color, 0.4f);
	glVertex3f(-0.0625f, 0.0625f, -0.0625f);
	coloring(color, 0.5f);
	glVertex3f(-0.0625f, 0.0625f, 0.0625f);
	coloring(color, 0.6f);
	glVertex3f(-0.0625f, -0.0625f, 0.0625f);
	coloring(color, 0.7f);
	glVertex3f(-0.0625f, -0.0625f, -0.0625f);
	glEnd();
}

float randomFloat(float from, float to) {
	return from + ((float)rand() * (to - from) / (RAND_MAX));
}

int main() {
	srand(static_cast<unsigned int>(time(nullptr)));
	GLFWwindow *window = nullptr;

	//initialize glfw system
	if (!glfwInit()) {
		glfwTerminate();
		return -1;
	}

	//create window
	window = glfwCreateWindow(640, 480, "My Game", nullptr, nullptr);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	//make context to window
	glfwMakeContextCurrent(window);

	//Initialize Game Variables
	float wallmove = 0.0f;
	float playerposition = 0.0f;
	int direction = 1;
	bool keyIsPressing = false;
	float spawntimer = randomFloat(1.0f,3.0f);
	float timer = 0.0f;
	float rdsp = 0.0f; //Random Spawn Point
	bool IsSpawningEnemy = false;
	float enemymove = 0.0f;
	float gamescore = 0.0f;
	
	std::shared_ptr<WorldClock> Time = std::make_shared<WorldClock>();
	Time->startClock();

	//Game Loop
	while (!glfwWindowShouldClose(window)) {	//while window should not close
		glClear(GL_COLOR_BUFFER_BIT);			//Render color
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

		Time->runClock();
		wallmove -= 3.0f * Time->diffClock();

		if (!IsSpawningEnemy) {
			timer += Time->diffClock();
		}

		for (float layer = -0.9f; layer < 1.5f; layer += 0.3f) {
			if (wallmove <= -0.3f) {
				wallmove = 0.0f;
			}
			//Draw Floor
			glPushMatrix();
			glRotatef(30.0f, 1.0f, 0.0f, 0.0f);
			glTranslatef(0.0f, 0.0f, layer + wallmove);
			drawFloorTile(BLUE);
			glPopMatrix();

			//Draw Left Wall
			glPushMatrix();
			glRotatef(30.0f, 1.0f, -0.5f, 0.0f);
			glTranslatef(-0.9f, 0.0f, layer + wallmove);
			drawWallTile();
			glPopMatrix();

			//Draw Right Wall
			glPushMatrix();
			glRotatef(30.0f, 1.0f, 0.5f, 0.0f);
			glTranslatef(0.9f, 0.0f, layer + wallmove);
			drawWallTile();
			glPopMatrix();
		}
		
		//If Spawn Timer reach
		if (timer > spawntimer) {
			timer = 0.0f;
			spawntimer = randomFloat(0.5f, 1.5f);
			IsSpawningEnemy = true;
			rdsp = randomFloat(-0.7f, 0.7f); //Random Spawn Point
		}

		//Summon an Enemy
		if (IsSpawningEnemy) {
			enemymove -= 3.0f * Time->diffClock();
			glPushMatrix();
			glRotatef(30.0f, 1.0f, 0.5f * (rdsp / 0.9f), 0.0f);
			glTranslatef(rdsp, 0.0f, 0.9f + enemymove);
			drawEnemyObject(RED);
			glPopMatrix();
		}

		//Respawn enemy when reach end wall
		if (enemymove < -2.6f) {
			enemymove = 0.0f;
			IsSpawningEnemy = false;
		}

		playerposition += (0.75f * direction * Time->diffClock());

		//Draw Player
		glPushMatrix();
		glTranslatef(playerposition, 0.6f, 0);
		glRotatef(30.0f, 1.0f, 0.0f, 0.0f);
		drawMovingBlock(GREEN);
		glPopMatrix();

		//Player lose if he hits the wall
		if (playerposition > 0.35f || playerposition < -0.35f) {
			std::cout << "You eat the wall for the breakfast." << std::endl;
			break;
		}

		//Player lose if he hit the enemy
		if (playerposition - rdsp < 0.2f && playerposition - rdsp > -0.2f) {
			if (enemymove < -2.28f && enemymove > -2.32f) {
				std::cout << "You were tickled by the enemy." << std::endl;
				break;
			}
		}

		int state = glfwGetKey(window, GLFW_KEY_E);
		if (state == GLFW_PRESS) {
			if (!keyIsPressing) {
				keyIsPressing = true;
				direction *= -1;
			}
		}
		else {
			keyIsPressing = false;
		}
		gamescore += Time->diffClock();

		//End Update Duty
		Time->startClock();
		glfwSwapBuffers(window);
		glfwPollEvents();						//Keyboard event renderer
	}
	glfwTerminate();

	std::cout << "YOU DIED" << std::endl << "You survived " << gamescore << " seconds" << std::endl;
	system("pause");
	return 0;
}