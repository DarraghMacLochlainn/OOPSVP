//
//  enemies.hpp
//  20076319_OOPRS
//
//  Created by 20076319 on 07/11/2018.
//  Copyright © 2018 20076319. All rights reserved.
//

#ifndef enemies_hpp
#define enemies_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <math.h>   /* atan2 */

using namespace sf;

/*
//Abstract base class
class AbstractEnemy{
protected:
    virtual Vector2f m_Position;
    virtual Vector2f m_target;
    virtual float m_velocity = 0;
    virtual float m_angle = 0;
    virtual Sprite m_Sprite;
    virtual Texture m_Texture;
    
    
    //Enemy definition booleans
    virtual bool m_movesXAxis;
    virtual bool m_shootsBullets;
    virtual bool m_collidesWithPlayer;
    virtual bool m_collidesWithBullet;
    
    

private:
    //Variables
    virtual const float GRAVITY = 100;
    virtual const float STANDARD_VELOCITY = 100;

    //Functions
    virtual void moveYGravity(){
        m_Position.y += GRAVITY;
    }
    
    virtual void moveYVelocity(){
        m_Position.y += STANDARD_VELOCITY + m_velocity;
    }

    virtual void moveXVelocity(){
        m_Position.x += STANDARD_VELOCITY + m_velocity;
    }
    
public:
    virtual void update(float elapsedTime){
        moveYGravity();
        moveYVelocity();
        if(m_movesXAxis)
        {
            moveXVelocity();
        }
        if(m_shootsBullets){
            
        }
        if(m_collidesWithPlayer){
            
        }
        if(m_collidesWithBullet){
            
        }
    }
};

//Cloud class
class Cloud: AbstractEnemy{
private:
    m_movesXAxis = false;
    m_shootsBullets = false;
    m_collidesWithPlayer = false;
    m_collidesWithBullet = false;
    
    
public:
    Cloud();
    
};

//Company class
class Company: AbstractEnemy{
private:
    m_movesXAxis = false;
    m_shootsBullets = false;
    m_collidesWithPlayer = true;
    m_collidesWithBullet = false;
    
    
public:
    
};

//Pirate class
class Pirate: AbstractEnemy{
private:
    m_movesXAxis = ;
    m_shootsBullets = ;
    m_collidesWithPlayer = ;
    m_collidesWithBullet = ;
    
    
public:
    
};

//Plane
class Plane: AbstractEnemy{
private:
    m_movesXAxis = ;
    m_shootsBullets = ;
    m_collidesWithPlayer = ;
    m_collidesWithBullet = ;
    
    
public:
    
};

//UFO class
class UFO: AbstractEnemy{
private:
    m_movesXAxis = ;
    m_shootsBullets = ;
    m_collidesWithPlayer = ;
    m_collidesWithBullet = ;
    
public:
    
};
*/
#endif /* enemies_hpp */
