// final215.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

void printMenu(int& choice)
{
	cout << "Please make your selection" << endl;
	cout << "1. Blur" << endl;
	cout << "2. Black and White" << endl;
	cout << "3. Red" << endl;
	cout << "4. Green" << endl;
	cout << "5. Blue" << endl;
	cout << "6. Invert" << endl;
	cout << "Your selection:";
	cin >> choice;
}

void Blur(Image imgIn, Image& imgOut)
{

	int width = imgIn.getSize().x;
	int height = imgIn.getSize().y;

	for (int y = 0; y < height - 1; y++) {
		for (int x = 0; x < width - 1; x++) {
			int minX = max(x - 1, 0);
			int maxX = min(x + 1, width - 1);
			int minY = max(y - 1, 0);
			int maxY = min(y + 1, height - 1);
			int pixelCount = 0;
			int accR = 0;
			int accB = 0;
			int accG = 0;
			for (int pixY = minY; pixY <= maxY; pixY++) {
				for (int pixX = minX; pixX <= maxX; pixX++) {
					pixelCount++;
					Color pixColor = imgIn.getPixel(pixX, pixY);
					accR += pixColor.r;
					accG += pixColor.g;
					accB += pixColor.b;
				}
			}
			Color blurColor = Color(accR / pixelCount, accG / pixelCount, accB / pixelCount);
			imgOut.setPixel(x, y, blurColor);
		}
	}
}

void blackAndWhite(Image imgin, Image& bawImg)
{
	int width = imgin.getSize().x;
	int height = imgin.getSize().y;

	for (int y = 0; y < height - 1; y++)
	{
		for (int x = 0; x < width - 1; x++)
		{
			Color bawColor = imgin.getPixel(x, y);
			int brightness = (bawColor.r / 3) + (bawColor.g / 3) + (bawColor.b / 3);
			bawColor = Color(brightness, brightness, brightness);
			bawImg.setPixel(x, y, bawColor);
		}
	}
}

void red(Image imgIn, Image& redImg)
{
	int width = imgIn.getSize().x;
	int height = imgIn.getSize().y;

	for (int y = 0; y < height - 1; y++)
	{
		for (int x = 0; x < width - 1; x++)
		{
			Color redColor = imgIn.getPixel(x, y);
			redColor.g = 0;
			redColor.b = 0;
			redImg.setPixel(x, y, redColor);
		}
	}
}

void green(Image imgIn, Image& redImg)
{
	int width = imgIn.getSize().x;
	int height = imgIn.getSize().y;

	for (int y = 0; y < height - 1; y++)
	{
		for (int x = 0; x < width - 1; x++)
		{
			Color greenColor = imgIn.getPixel(x, y);
			greenColor.r = 0;
			greenColor.b = 0;
			redImg.setPixel(x, y, greenColor);
		}
	}
}

void blue(Image imgIn, Image& blueImg)
{
	int width = imgIn.getSize().x;
	int height = imgIn.getSize().y;

	for (int y = 0; y < height - 1; y++)
	{
		for (int x = 0; x < width - 1; x++)
		{
			Color blueColor = imgIn.getPixel(x, y);
			blueColor.r = 0;
			blueColor.g = 0;
			blueImg.setPixel(x, y, blueColor);
		}
	}
}

void invert(Image imgIn, Image& invertImg)
{
	int width = imgIn.getSize().x;
	int height = imgIn.getSize().y;

	for (int y = 0; y < height - 1; y++)
	{
		for (int x = 0; x < width - 1; x++)
		{
			Color invertColor = imgIn.getPixel(x, y);
			invertColor.r = 255 - invertColor.r;
			invertColor.g = 255 - invertColor.g;
			invertColor.b = 255 - invertColor.b;
			invertImg.setPixel(x, y, invertColor);
		}
	}
}

int main()
{
	int choice;
	printMenu(choice);
	Image img;
	img.loadFromFile("images/landscape.png");
	Image outImg;
	outImg.create(img.getSize().x, img.getSize().y);

	if (choice == 1)
	{

		Blur(img, outImg);
		outImg.saveToFile("blur.png");

		//show image
		Texture tex1;
		tex1.loadFromImage(outImg);
		if (!tex1.loadFromFile("blur.png"))
		{
			cout << "Could not load image";
			exit(1);
		}
		RenderWindow window(VideoMode(outImg.getSize().x, outImg.getSize().y), "Show me a picture");
		Sprite sprite1;
		sprite1.setTexture(tex1);
		window.draw(sprite1);
		window.display();

		while (true);

	}

	if (choice == 2)
	{
		blackAndWhite(img, outImg);
		outImg.saveToFile("blackandwhite.png");

		//show image
		Texture bawTex;
		bawTex.loadFromImage(outImg);
		if (!bawTex.loadFromFile("blackandwhite.png"))
		{
			cout << "Could not load image";
			exit(1);
		}

		RenderWindow window(VideoMode(outImg.getSize().x, outImg.getSize().y), "Show me a picture");
		Sprite bawSprite;
		bawSprite.setTexture(bawTex);
		window.draw(bawSprite);
		window.display();

		while (true);

	}

	if (choice == 3)
	{
		red(img, outImg);
		outImg.saveToFile("red.png");

		//show image
		Texture redTex;
		redTex.loadFromImage(outImg);
		if (!redTex.loadFromFile("red.png"))
		{
			cout << "Could not load image";
			exit(1);
		}

		RenderWindow window(VideoMode(outImg.getSize().x, outImg.getSize().y), "Show me a picture");
		Sprite redSprite;
		redSprite.setTexture(redTex);
		window.draw(redSprite);
		window.display();

		while (true);
	}

	if (choice == 4)
	{
		green(img, outImg);
		outImg.saveToFile("green.png");

		//show image
		Texture greenTex;
		greenTex.loadFromImage(outImg);
		if (!greenTex.loadFromFile("green.png"))
		{
			cout << "Could not load image";
			exit(1);
		}

		RenderWindow window(VideoMode(outImg.getSize().x, outImg.getSize().y), "Show me a picture");
		Sprite greenSprite;
		greenSprite.setTexture(greenTex);
		window.draw(greenSprite);
		window.display();

		while (true);
	}

	if (choice == 5)
	{
		blue(img, outImg);
		outImg.saveToFile("blue.png");

		//show image
		Texture blueTex;
		blueTex.loadFromImage(outImg);
		if (!blueTex.loadFromFile("blue.png"))
		{
			cout << "Could not load image";
			exit(1);
		}

		RenderWindow window(VideoMode(outImg.getSize().x, outImg.getSize().y), "Show me a picture");
		Sprite blueSprite;
		blueSprite.setTexture(blueTex);
		window.draw(blueSprite);
		window.display();

		while (true);
	}

	if (choice == 6)
	{
		invert(img, outImg);
		outImg.saveToFile("invert.png");

		//show image
		Texture invertTex;
		invertTex.loadFromImage(outImg);
		if (!invertTex.loadFromFile("invert.png"))
		{
			cout << "Could not load image";
			exit(1);
		}

		RenderWindow window(VideoMode(outImg.getSize().x, outImg.getSize().y), "Show me a picture");
		Sprite invertSprite;
		invertSprite.setTexture(invertTex);
		window.draw(invertSprite);
		window.display();

		while (true);
	}

	if (choice > 6)
	{
		cout << "Sorry, cannot perform that function" << endl;
		exit(1);
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
