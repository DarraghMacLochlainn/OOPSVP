//
//  player.hpp
//  20076319_OOPRS
//
//  Created by 20076319 on 05/11/2018.
//  Copyright © 2018 20076319. All rights reserved.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <math.h>   /* atan2 */

using namespace sf;

class Player
{
private:
    const float SPEED = 700;
    const float MAX_HEALTH = 100;
    const float MAX_ROTATION = 50;
    const float ROTATION_SPEED = .2f;
    const float SCREEN_BORDER = 150;
    
    //Where is the player?
    Vector2f m_Position;
    float m_angle = 0;
    
    //Player sprite
    Sprite m_Sprite;
    
    //Player texture
    Texture m_Texture;
    
    //What is the screen resolution?
    Vector2f m_Resolution;
    
    //Which directions is the player currently moving in?
    bool m_UpPressed;
    bool m_DownPressed;
    bool m_LeftPressed;
    bool m_RightPressed;
    bool m_QPressed;
    bool m_EPressed;
    
    //How much health has the player got?
    int m_Health;
    
    //What is the maximum health the player can have?
    int m_MaxHealth;
    
    //When was the player last hit?
    Time m_LastHit;
    
    //Speed in pixels per second
    float m_Speed;
    
public:
    Player();
    
    void spawn(Vector2f resolution);
    
    //Called at the end of game
    void resetPlayerStats();
    
    //Handle the player getting hit by a zombie
    bool hit(Time timeHit);
    
    //How long since player hit?
    Time getLastHitTime();
    
    //Where is the player?
    FloatRect getPosition();
    
    //Where is the centre of the player?
    Vector2f getCenter();
    
    //Which angle is the player facing?
    float getRotation();
    
    //Send a copy of the sprite to main
    Sprite getSprite();
    
    //How much health has the player currently got?
    int getHealth();
    
    //Move the player
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void rotateRight();
    void rotateLeft();
    
    //Stop the player moving in a specific direction
    void stopLeft();
    void stopRight();
    void stopUp();
    void stopDown();
    void stopRotateRight();
    void stopRotateLeft();
    
    //Called every frame
    void update(float elapsedTime);
    
    //Increase the maximum amount of health the player can have
    void increaseHealthLevel(int amount);
};
    
    
#endif /* player_hpp */
