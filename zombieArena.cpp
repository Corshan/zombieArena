#include <SFML/Graphics.hpp>
#include "Player.h"
#include "zombieArena.h"

using namespace sf;

int main()
{
    //The game will always be in one of 4 states
    enum class State {PAUSED, LEVELING_UP, GAME_OVER, PLAYING};

    //Start with the GAME_OVER state
    State state = State::GAME_OVER;

    //Get the screen reslouction and create an SFML window
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    RenderWindow window(VideoMode(resolution.x,resolution.y), "Zombie Arena", Style::Default);

    //create an SFML Voiew for the main action
    View mainView(sf::FloatRect(0,0,resolution.x,resolution.y));

    //clock for timing everything
    Clock clock;

    //how long has the PLAYING state been active?
    Time gameTimeTotal;

    //where is the mouse in relation to the world coordinates?
    Vector2f mouseWorldPosition;

    //Where is the mouse in relation to screen coordinates?
    Vector2i mouseScreenPosition;

    //create an instance of the player
    Player player;

    //the boundaries of the arena
    IntRect arena;

    //Create the Background
    VertexArray background;

    //load the texture for our background vertex array
    Texture textureBackground;
    textureBackground.loadFromFile("graphics/background_sheet.png");

    //the main game loop
    while (window.isOpen())
    {
        /*
         *********************************************
         *
         *
         *       Handle Input
         *
         *
         *********************************************
         */
         
         //handle events
         Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::KeyPressed)
            {
                //Pause game while playing
                if (event.key.code == Keyboard::Return && state == State::PLAYING)
                {
                    state = State::PAUSED;
                }else if (event.key.code == Keyboard::Return && state == State::PAUSED) //Restart while paused
                {
                    state = State::PLAYING;
                    //reset the clock so there isn't a frame jump
                    clock.restart();
                }else if (event.key.code == Keyboard::Return && state == State::GAME_OVER)//start a new game while GAME_OVER state
                {
                    state = State::LEVELING_UP;
                }

                if (state == State::PLAYING)
                {
                    
                }
            }
        }

        //handle the player quitting
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        //handle controls while playing
        if (state == State::PLAYING)
        {
            //handle the pressing and releasing of the WASD keys
            if (Keyboard::isKeyPressed(Keyboard::W))
            {
                player.moveUp();
            }
            else
            {
                player.stopUp();
            }

            if (Keyboard::isKeyPressed(Keyboard::S))
            {
                player.moveDown();
            }else
            {
                player.stopDown();
            }

            if(Keyboard::isKeyPressed(Keyboard::A))
            {
                player.moveLeft();
            }else
            {
                player.stopLeft();
            }

            if (Keyboard::isKeyPressed(Keyboard::D))
            {
                player.moveRight();
            }else
            {
                player.stopRight();
            }
        }// end WASD while playing

        if (state == State::LEVELING_UP)
        {
            //handle the player leveling up
            if (event.key.code == Keyboard::Num1)
            {
                state = State::PLAYING;
            }

            if (event.key.code == Keyboard::Num2)
            {
                state = State::PLAYING;
            }

            if (event.key.code == Keyboard::Num3)
            {
                state = State::PLAYING;
            }

            if (event.key.code == Keyboard::Num4)
            {
                state = State::PLAYING;
            }

            if (event.key.code == Keyboard::Num5)
            {
                state = State::PLAYING;
            }

            if (event.key.code == Keyboard::Num6)
            {
                state = State::PLAYING;
            }

            if (state == State::PLAYING)
            {
                //prepare the level - we will update this later
                arena.width = 500;
                arena.height = 500;
                arena.left = 0;
                arena.top = 0; 

                //Pass the vertex array bt reference to the createbeackground funtion
                int tileSize = createBackground(background, arena);
                
                //Spawn the player in the middle of the arena
                player.spawn(arena,resolution,tileSize);

                //reset the clock so there isn't a frame jump
                clock.restart();
            }
        }

        /*
         *********************************************
         *
         *
         *       Update the frame
         *
         *
         *********************************************
         */

        if (state == State::PLAYING)
        {
            //Update the delta time
            Time dt = clock.restart();

            //update the total game time
            gameTimeTotal += dt;

            //make a decimal fraction of 1 from delta time
            float dtAsSeconds = dt.asSeconds();

            //Find the mouse pointer
            mouseScreenPosition = Mouse::getPosition(window);//note the call to a static funtion

            //Convert mouse position to world coordinates pf mainView
            mouseWorldPosition = window.mapPixelToCoords(Mouse::getPosition(), mainView);

            //update the player
            player.update(dtAsSeconds, Mouse::getPosition());

            //make a note of the player new position
            Vector2f playerPosition(player.getCenter());

            //make the view centre around the player
            mainView.setCenter(player.getCenter());
        }//end updating scene

        /*
         *********************************************
         *
         *
         *       Draw the scene
         *
         *
         *********************************************
         */

        if (state == State::PLAYING)
        {
            window.clear();

            //set the mainView to be displayed in the window
            //And draw everything related to it
            window.setView(mainView);

            //Draw the background
            window.draw(background, &textureBackground);

            //Draw the player
            window.draw(player.getSprite());
        }
        if (state == State::LEVELING_UP)
        {
            
        }
        if (state == State::PAUSED)
        {
            
        }
        if (state == State::GAME_OVER)
        {
            
        }

        window.display();
    }
    
    return 0;
}