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
	cout << "2. Red" << endl;
	cout << "3. Green" << endl;
	cout << "4. Blue" << endl;
	cout << "5. Black and White" << endl;
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
			Color pixColor = Color(accR / pixelCount, accG / pixelCount, accB / pixelCount);
			imgOut.setPixel(x, y, pixColor);
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

	if (choice > 1)
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
