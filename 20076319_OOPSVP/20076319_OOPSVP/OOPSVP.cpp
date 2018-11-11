
/*
 *  Project Name:       OOP Shoot 'Em Up
 *
 *  Student Name:       Darragh Mac Lochlainn
 *  Student Number:     20076319
 *  Module Name:        C++ For Games Development
 *
 *  Description:        .
 *
 *  Bugs:               N/A
 *
 *  README:             .
 */

#include <sfml/Graphics.hpp>
#include "player.hpp"
#include <iostream>


using namespace sf;
using namespace std;
Sprite enemies[10];

int main() {
    //Create game window using computer resolution
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	RenderWindow window(VideoMode(resolution.x, resolution.y), "Ships Vs Plane", Style::Fullscreen);
	window.setMouseCursorVisible(false);

    //Create a SFML View for the main action
    View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));
    
    //Clock for timing everything
    Clock clock;
    
    //Create an instance of the Player class
    Player player;
    
    //Spawn the player in the middle of the arena
    player.spawn(resolution);
    
    //Test Cloud
    Texture textureCloud;
    textureCloud.loadFromFile("../Resources/graphics/cloud.png");
    int resoutionWidth = static_cast<int>(resolution.x);
    srand((int)time(0));
    for(int i = 0; i < 10; i++){
        enemies[i].setTexture(textureCloud);
        enemies[i].setPosition((rand()%resoutionWidth), ((rand()%4000)-5000));
        //Set the sprite's origin to dead centre
        //We can then spin it round without changing its position
        enemies[i].setOrigin(225, 180);
    }
    
    //Make the view cente around the player
    mainView.setCenter(player.getCenter());
    while(window.isOpen()){
        /*
        /*
         ******************
         HANDLE PLAYER INPUT
         ******************
         */
        
        
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
            window.close();
        }
        if (Keyboard::isKeyPressed(Keyboard::W)) {
            player.moveUp();
        }
        else{
            player.stopUp();
        }
        if (Keyboard::isKeyPressed(Keyboard::S)) {
            player.moveDown();
        }
        else{
            player.stopDown();
        }
        if (Keyboard::isKeyPressed(Keyboard::A)) {
            player.moveLeft();
        }
        else{
            player.stopLeft();
        }
        if (Keyboard::isKeyPressed(Keyboard::D)) {
            player.moveRight();
        }
        else{
            player.stopRight();
        }
        if (Keyboard::isKeyPressed(Keyboard::E)) {
            player.rotateRight();
        }
        else{
            player.stopRotateRight();
        }
        if (Keyboard::isKeyPressed(Keyboard::Q)) {
            player.rotateLeft();
        }
        else{
            player.stopRotateLeft();
        }
        
        /*
         ******************
         UPDATE THE FRAME
         ******************
         */
        
        //Update the delta time
        Time dt = clock.restart();
        //Make a decimal fraction of 1 from the delta time
        float dtAsSeconds = dt.asSeconds();

        //Update the player
        player.update(dtAsSeconds);
        
        //loop enemies
        for (int i = 0; i < 10; i++) {
            if (enemies[i].getPosition().y > resolution.y+100) {
                enemies[i].setPosition((rand()%resoutionWidth), ((rand()%300)-600));
            }
        }

        
        //move enemies
        for (int i = 0; i < 10; i++) {
            enemies[i].setPosition(enemies[i].getPosition().x, enemies[i].getPosition().y + 1.5);
        }
        /*
         ******************
         DRAW THE SCENE
         ******************
         */

        window.clear();
        //set the mainView to be displayed in the window
        //And draw everything related to it
        window.setView(mainView);
        
        //Draw the player
        window.draw(player.getSprite());

        for(int i = 0; i<10; i++){
            window.draw(enemies[i]);
        }

        window.display();
    }
    return 0;
}
