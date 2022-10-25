#ifndef player_hpp
#define player_hpp

#include <SFML/Graphics.hpp>

using namespace sf;

class Player
{
public:
    Player();

    void spawn(IntRect arena, Vector2f resolution, int tileSize);

    //Called at end of game
    void resetPlayerStats();

    //handle the player getting hit by a zombie
    bool hit(Time timeHit);

    //how long since player hit?
    Time getLastHitTime();

    //where is the player?
    FloatRect getPosition();

    //Where is the centre of the player?
    Vector2f getCenter();

    //which angle is the player facing>
    float getRotation();

    //send a copy of the sprite to main
    Sprite getSprite();

    //how much has the player currently got?
    int getHealth();

    //Move the player
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    //Stop the player moving in a specific direction
    void stopLeft();
    void stopRight();
    void stopUp();
    void stopDown();

    //called every frame
    void update(float elapsedTime, Vector2i mousePosition);

    //Give player a speed boost - used for leveling up
    void upgradeSpeed();

    //increase max health used for leveling up
    void upgradeHealth();

    //increase health - collision with med kit
    void increaseHealthLevel(int amount);
    
private:
    const float START_SPEED = 200;
    const float START_HEALTH = 100;

    //Where is the player?
    Vector2f m_position;

    //Player sprite
    Sprite m_sprite;

    //Player texture
    Texture m_texture;

    //What is the screen resolution?
    Vector2f m_resolution;

    //How big is the current arena?
    IntRect m_arena;
    
    //How big is each tile of the arena?
    int m_tileSize;

    //Which directions is the player currently moving in?
    bool m_upPressed;
    bool m_downPressed;
    bool m_leftPressed;
    bool m_rightPressed;

    //How mush health has the player got?
    int m_health;

    //What is the maximum health the player can have?
    int m_maxHealth;

    //When was the player last hit?
    Time m_lastHit;

    //Speed in pixels per second
    float m_speed;
};

#endif
