
#include "Pila.h"
using namespace std;

MenuInicio* m = new MenuInicio();

int main()
{
    Pila* pila = new Pila();
    //cout << "hola";
    int cantTubos = 3;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    sf::Texture image;
    image.loadFromFile("resourse\\Tubo4.png");
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
    bool mouseClickedReleased = false;
    bool mouseClickedTubo = false;
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
                if (sprite2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    mouseClickedTubo = true;
                }
                
            }
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                mouseClicked = false;
                dragging = false;
                if (sprite2.getGlobalBounds().contains(mouseX, mouseY))
                {
                    sf::CircleShape shape(0);
                    shape = shape2;
                    shape.setFillColor(sf::Color::Red);
                    pila->push(shape);
                    shape2.setPosition(sprite2.getPosition().x + imageWidth - shape2.getRadius(), sprite2.getPosition().y + imageHeight - shape2.getRadius());
                    //shape2 = NULL;

                    //dragging = false;
                }
                else {
                    sf::CircleShape shape(0);
                    shape = shape2;
                    shape.setFillColor(sf::Color::Red);
                    pila->push(shape);
                    shape2.setPosition(sprite2.getPosition().x + imageWidth - shape2.getRadius(), sprite2.getPosition().y + imageHeight - shape2.getRadius());
                }
                mouseClickedReleased = true;
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
            
        }
        if (mouseClickedTubo == true) {
            
            sf::CircleShape shap(0);
            shap = pila->pop();
            if (shap.getRadius()!=0) {
                shape2 = shap;
                shape2.setPosition(sprite2.getPosition().x + imageWidth - shape2.getRadius(), sprite2.getPosition().y + imageHeight - shape2.getRadius()b);
            }
            
            //cout << mouseX << endl;
            //cout << pila->pop() << endl;
            //window.draw(shap);
            dragging = true;
            mouseClickedTubo = false;
            
        }
        if (mouseClickedReleased == true) 
        {
            
            mouseClickedReleased == false;
        }
        
        //cout << dragging << endl;
        window.clear();
        //window.draw(rect);
        
        window.draw(shape2);
        window.draw(sprite);
        window.draw(sprite2);
        window.draw(sprite3);
        /*Tubo* t = pila->top();
        while (t!=NULL)
        {
            sf::CircleShape shap(0);
            shap = t->getShape();
            window.draw(shap);
            t->getAnt();
        }*/
        
        window.display();
    }
    window.close();
    //m->vistaInicio();
    
    
    /*pila->push();
    pila->push();
    cout << pila->pop()<<endl;
    cout << pila->pop() << endl;*/


    return 0;
}

