
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
    float imageWidth2 = (sprite.getTexture()->getSize().x) * 0.5f;
    float imageHeight = (sprite.getTexture()->getSize().y / 2) * 0.5f;
    float imageHeight2 = (sprite.getTexture()->getSize().y) * 0.5f;
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

    int radious = imageWidth - 7;
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
    for (int i = 0; i < 4; i++)
    {
        

        if (pila->top()!=NULL)
        {
            sf::CircleShape shap1(radious);
            shap1.setFillColor(sf::Color::Green);
            shap1.setPosition(sprite2.getPosition().x + imageWidth - radious, (pila->top()->getShape()).getPosition().y - 57);
            pila->push(shap1);
        }
        else {
            sf::CircleShape shap1(radious);
            shap1.setFillColor(sf::Color::Red);
            shap1.setPosition(sprite2.getPosition().x + imageWidth - radious, sprite2.getPosition().y + imageHeight2 - radious - 32);
            pila->push(shap1);
        }
    }
    /*sf::CircleShape shap1(radious);
    shap1.setFillColor(sf::Color::Green);
    shap1.setPosition(sprite2.getPosition().x + imageWidth - radious, sprite2.getPosition().y + imageHeight2 - radious-32);

    sf::CircleShape shap2(radious);
    shap2.setFillColor(sf::Color::Red);
    shap2.setPosition(sprite2.getPosition().x + imageWidth - radious, shap1.getPosition().y-57);

    sf::CircleShape shap3(radious);
    shap3.setFillColor(sf::Color::Blue);
    shap3.setPosition(sprite2.getPosition().x + imageWidth - radious, shap2.getPosition().y - 57);

    sf::CircleShape shap4(radious);
    shap4.setFillColor(sf::Color::White);
    shap4.setPosition(sprite2.getPosition().x + imageWidth - radious, shap3.getPosition().y - 57);
    */
    Tubo* aux = NULL;
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
                    dragging = true;
                    if (aux!=NULL) {
                        mouseRectOffset.x = event.mouseButton.x - aux->getShape().getGlobalBounds().left - aux->getShape().getOrigin().x;
                        mouseRectOffset.y = event.mouseButton.y - aux->getShape().getGlobalBounds().top - aux->getShape().getOrigin().y;
                    }
                    
                    mouseClickedTubo = true;
                }
                
            }
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                
                if (aux != NULL) {
                    if (sprite2.getGlobalBounds().contains(mouseX, mouseY))
                    {
                        /*sf::CircleShape shape(0);
                        shape = shape2;
                        shape.setFillColor(sf::Color::Red);*/

                        /*aux->getShape().setPosition(sprite2.getPosition().x + imageWidth - radious, sprite2.getPosition().y + imageHeight - radious);
                        pila->push(aux->getShape());*/

                        if (pila->top() != NULL)
                        {

                            aux->getShape().setPosition(sprite2.getPosition().x + imageWidth - radious, (pila->top()->getShape()).getPosition().y - 57);
                            pila->push(aux->getShape());
                        }
                        else {
                            aux->getShape().setPosition(sprite2.getPosition().x + imageWidth - radious, sprite2.getPosition().y + imageHeight2 - radious - 32);
                            pila->push(aux->getShape());
                        }
                        //shape2 = NULL;
                        
                        //dragging = false;
                    }
                    else {
                        /* sf::CircleShape shape(0);
                         shape = shape2;
                         shape.setFillColor(sf::Color::Red);*/
                        if (pila->top() != NULL)
                        {

                            aux->getShape().setPosition(sprite2.getPosition().x + imageWidth - radious, (pila->top()->getShape()).getPosition().y - 57);
                            pila->push(aux->getShape());
                        }
                        else {
                            aux->getShape().setPosition(sprite2.getPosition().x + imageWidth - radious, sprite2.getPosition().y + imageHeight2 - radious - 32);
                            pila->push(aux->getShape());
                        }
                        /*aux->getShape().setPosition(sprite2.getPosition().x + imageWidth - radious, sprite2.getPosition().y + imageHeight - radious);
                        pila->push(aux->getShape());*/
                        mouseClickedReleased = false;
                    }
                    aux = NULL;
                }
                mouseClicked = false;
                dragging = false;
                mouseClickedTubo = false;
                
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
        
        if (mouseClickedTubo == true) {
            aux = new Tubo();
            aux = pila->pop();
            
            /*sf::CircleShape shap(0);
            shap = aux->getShape();*/
            if (aux!=NULL) {
                //shape2 = shap;
                shape2 = aux->getShape();
                shape2.setPosition(mouseX - mouseRectOffset.x-radious, mouseY - mouseRectOffset.y-radious);
                mouseClickedReleased = true;
            }

            //cout << mouseX << endl;
            //cout << pila->pop() << endl;
            //window.draw(shap);
            //dragging = true;
            
            mouseClickedTubo = false;

        }
        if (dragging == true)
        {
            if (aux != NULL) {
                shape2.setPosition(mouseX - mouseRectOffset.x-radious, mouseY - mouseRectOffset.y-radious);
            }


        }
        
        
        
        
        //cout << dragging << endl;
        window.clear();
        //window.draw(rect);
        /*window.draw(shap1);
        window.draw(shap2);
        window.draw(shap3);
        window.draw(shap4);*/
        if (mouseClickedReleased == true)
        {
            window.draw(shape2);
        }

        
        window.draw(sprite);
        window.draw(sprite2);
        window.draw(sprite3);
        Tubo* t = pila->top();

        
        while (t!=NULL)
        {
            sf::CircleShape shap(0);
            //cout << " ciclo t" << endl;
            shap = t->getShape();
            window.draw(shap);
            t=t->getAnt();
        }
        //cout << " ciclo a" << endl;
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

