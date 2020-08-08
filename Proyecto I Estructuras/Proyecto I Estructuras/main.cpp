#include <SFML/Graphics.hpp>
#include <string> 
#include <iostream> 
#include <SFML/Audio.hpp>
using namespace std;
int main()
{
    int cantTubos = 3;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    sf::Texture image;
    image.loadFromFile("resourse\\Tubo3.png");
    sf::Sprite sprite(image);
    sprite.setScale(0.5f,0.5f);
    float imageWidth = (sprite.getTexture()->getSize().x / 2) * 0.5f;
    float imageHeight = (sprite.getTexture()->getSize().y / 2) * 0.5f;
    float windowWidth = window.getSize().x/2;
    float windowHeight = window.getSize().y/2;
    sprite.setPosition(windowWidth - imageWidth, windowHeight - imageHeight);

    sf::Sprite sprite2(image);
    sprite2.setScale(0.5f, 0.5f);
    
    sprite2.setPosition(windowWidth - imageWidth-150, windowHeight - imageHeight);

    sf::Sprite sprite3(image);
    sprite3.setScale(0.5f, 0.5f);
    
    sprite3.setPosition(windowWidth - imageWidth+150, windowHeight - imageHeight);

    sf::CircleShape shape2(imageWidth-7);
    shape2.setFillColor(sf::Color::Green);

    
    bool play = true;
    sf::Event event;
    bool mouseClicked = false;
    bool mouseInsideRect = false;
    bool dragging = false;
    sf::Vector2f mouseRectOffset;
    int mouseX = 0;
    int mouseY = 0;
    //sf::RectangleShape rect;
    

   /* while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape2);
        window.draw(sprite);
        window.draw(sprite2);
        window.draw(sprite3);
        window.display();
    }*/
    
    while (play == true)
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                mouseClicked = true;
                if (shape2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    dragging = true;
                    mouseRectOffset.x = event.mouseButton.x - shape2.getGlobalBounds().left - shape2.getOrigin().x;
                    mouseRectOffset.y = event.mouseButton.y - shape2.getGlobalBounds().top - shape2.getOrigin().y;
                    
                }
                
            }
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                mouseClicked = false;
                dragging = false;
            }
            if (event.type == sf::Event::MouseMoved)
            {
                mouseX = event.mouseMove.x;
                mouseY = event.mouseMove.y;
            }
            if (event.type == sf::Event::Closed)
            {
                play = false;
            }
        }
        if (dragging == true)
        {
            shape2.setPosition(mouseX - mouseRectOffset.x, mouseY - mouseRectOffset.y);
            //cout << mouseX << endl;
            
            if ((mouseX >= sprite2.getPosition().x && mouseY >= sprite2.getPosition().y) && (mouseX <= sprite2.getPosition().x + imageWidth*2 && mouseY <= sprite2.getPosition().y + imageHeight*2)) {
                //cout << "hola SI entro al if";
                shape2.setPosition(sprite2.getPosition().x + imageWidth - shape2.getRadius(), sprite2.getPosition().y + imageHeight - shape2.getRadius());
                dragging = false;
            }
        }
        //cout << dragging << endl;
        window.clear();
        //window.draw(rect);
        
        window.draw(shape2);
        window.draw(sprite);
        window.draw(sprite2);
        window.draw(sprite3);
        
        
        window.display();
    }
    window.close();
    return 0;
}

