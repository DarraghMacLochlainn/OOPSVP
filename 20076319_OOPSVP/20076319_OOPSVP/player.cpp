//
//  player.cpp
//  20076319_OOPRS
//
//  Created by 20076319 on 05/11/2018.
//  Copyright © 2018 20076319. All rights reserved.
//

#include "player.hpp"

Player::Player(){
    m_Speed = SPEED;
    m_Health = MAX_HEALTH;
    
    //Associate a texture with the sprite
    m_Texture.loadFromFile("../Resources/graphics/player.png");
    m_Sprite.setTexture(m_Texture);
	m_Sprite.setScale(.5, .5);
    
    //Set the origin of the sprite to the centre for smooth rotation
    m_Sprite.setOrigin(142.5, 99);
}

void Player::spawn(Vector2f resolution){
    //Place the player in the middle of the arena
    m_Position.x = resolution.x/2;
    m_Position.y = resolution.y/2;
    
    
    //Store the resolution for future use
    m_Resolution.x = resolution.x;
    m_Resolution.y = resolution.y;
}

void Player::resetPlayerStats(){
    m_Speed = SPEED;
    m_Health = MAX_HEALTH;
}

Time Player::getLastHitTime(){
    return m_LastHit;
}

bool Player::hit(Time timeHit){
    if(timeHit.asMilliseconds() - m_LastHit.asMilliseconds() > 200){
        m_LastHit = timeHit;
        m_Health -= 10;
        return true;
    }
    else{
        return false;
    }
}

FloatRect Player::getPosition(){
    return m_Sprite.getGlobalBounds();
}

Vector2f Player::getCenter(){
    return m_Position;
}

float Player::getRotation(){
    return m_Sprite.getRotation();
}

Sprite Player::getSprite(){
    return m_Sprite;
}

int Player::getHealth(){
    return m_Health;
}

void Player::moveLeft(){
    m_LeftPressed = true;
}

void Player::moveRight(){
    m_RightPressed = true;
}

void Player::moveUp(){
    m_UpPressed = true;
}

void Player::moveDown(){
    m_DownPressed = true;
}

void Player::rotateLeft(){
    m_QPressed = true;
}

void Player::rotateRight(){
    m_EPressed = true;
}

void Player::stopLeft(){
    m_LeftPressed = false;
}

void Player::stopRight(){
    m_RightPressed = false;
}

void Player::stopUp(){
    m_UpPressed = false;
}

void Player::stopDown(){
    m_DownPressed = false;
}

void Player::stopRotateLeft(){
    m_QPressed = false;
}

void Player::stopRotateRight(){
    m_EPressed = false;
}

void Player::update(float elapsedTime){
    if (m_UpPressed) {
        m_Position.y -= m_Speed * elapsedTime;
    }
    if (m_DownPressed) {
        m_Position.y += m_Speed * elapsedTime;
    }
    if (m_RightPressed) {
        m_Position.x += m_Speed * elapsedTime;
    }
    if (m_LeftPressed) {
        m_Position.x -= m_Speed * elapsedTime;
    }
    
    //Player must stay within screen
    if (m_Position.x > m_Resolution.x - SCREEN_BORDER) {
        m_Position.x = m_Resolution.x - SCREEN_BORDER;
    }
    if (m_Position.x < 0 + SCREEN_BORDER){
        m_Position.x = 0 + SCREEN_BORDER;
    }
    if (m_Position.y > m_Resolution.y - SCREEN_BORDER) {
        m_Position.y = m_Resolution.y - SCREEN_BORDER;
    }
    if (m_Position.y < 0 + SCREEN_BORDER) {
        m_Position.y = 0 + SCREEN_BORDER;
    }

    if (m_EPressed) {
        m_angle += ROTATION_SPEED;
    }
    if (m_QPressed) {
        m_angle -= ROTATION_SPEED;
    }
    if (m_angle < MAX_ROTATION * -1) {
        m_angle = MAX_ROTATION * -1;
    }
    if (m_angle > MAX_ROTATION) {
        m_angle = MAX_ROTATION;
    }
    
    m_Sprite.setPosition(m_Position);
    m_Sprite.setRotation(m_angle);
}

void Player::increaseHealthLevel(int amount){
    m_Health += amount;
    
    //But not beyond the maximum
    if (m_Health > m_MaxHealth) {
        m_Health = m_MaxHealth;
    }
}
