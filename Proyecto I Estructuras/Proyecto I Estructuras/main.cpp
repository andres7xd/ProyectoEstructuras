
#include "Pila.h"
using namespace std;

MenuInicio* m = new MenuInicio();
void guardarBola(Pila*& p, sf::Sprite sprite, sf::CircleShape shape, float radious, float imageWidth, float imageHeight2, Tubo* aux ) {
    if (p->top() != NULL)
    {
        shape.setPosition(sprite.getPosition().x + imageWidth - radious, (p->top()->getShape()).getPosition().y - 57);
        p->push(shape, aux->getColor());
    }
    else {
        shape.setPosition(sprite.getPosition().x + imageWidth - radious, sprite.getPosition().y + imageHeight2 - radious - 32);
        p->push(shape, aux->getColor());
    }
    p->setCantBol(p->getCantBol() + 1);
}
Pila* pila = new Pila();
Pila* pila2 = new Pila();
Pila* pila3 = new Pila();
void devolverBola(int tubo, sf::Sprite sprite2, sf::Sprite sprite, sf::Sprite sprite3, sf::CircleShape shape, float radious, float imageWidth, float imageHeight2, Tubo* aux) {
    if (tubo == 1)
    {
        guardarBola(pila, sprite2, shape, radious, imageWidth, imageHeight2, aux);
    }
    else {
        if (tubo == 2)
        {
            guardarBola(pila2, sprite, shape, radious, imageWidth, imageHeight2, aux);
        }
        else {
            if (tubo == 3)
            {
                guardarBola(pila3, sprite3, shape, radious, imageWidth, imageHeight2, aux);
            }
        }
    }
}
int main()
{
    
    int tubo = 0;
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
    float mouseX = 0;
    float mouseY = 0;

    float radious = imageWidth - 7;
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
            pila->push(shap1, "Green");
        }
        else {
            sf::CircleShape shap1(radious);
            shap1.setFillColor(sf::Color::Red);
            shap1.setPosition(sprite2.getPosition().x + imageWidth - radious, sprite2.getPosition().y + imageHeight2 - radious - 32);
            pila->push(shap1, "Red");
        }
        pila->setCantBol(pila->getCantBol() + 1);
    }


    for (int i = 0; i < 4; i++)
    {


        if (pila2->top() != NULL)
        {
            sf::CircleShape shap1(radious);
            shap1.setFillColor(sf::Color::Red);
            shap1.setPosition(sprite.getPosition().x + imageWidth - radious, (pila2->top()->getShape()).getPosition().y - 57);
            pila2->push(shap1, "Red");
        }
        else {
            sf::CircleShape shap1(radious);
            shap1.setFillColor(sf::Color::Green);
            shap1.setPosition(sprite.getPosition().x + imageWidth - radious, sprite.getPosition().y + imageHeight2 - radious - 32);
            pila2->push(shap1, "Green");
        }
        pila2->setCantBol(pila2->getCantBol() + 1);
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
    Tubo * aux = NULL;
    while (play == true)
    {
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                mouseClicked = true;
                if (sprite2.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    dragging = true;
                    tubo = 1;
                    mouseClickedTubo = true;
                }
                else {
                    if (sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        dragging = true;
                        tubo = 2;
                        mouseClickedTubo = true;
                    }
                    else {
                        if (sprite3.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                        {
                            dragging = true;
                            tubo = 3;
                            mouseClickedTubo = true;
                        }
                        else {
                            tubo = 0;
                        }
                    }
                }
                
                
                
            }
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                
                if (aux != NULL) {
                    if (sprite2.getGlobalBounds().contains(mouseX, mouseY))
                    {
                        if (pila->top() != NULL)
                        {
                            if (pila->getCantBol() < 4 && aux->getColor() == pila->top()->getColor()) {
                                guardarBola(pila, sprite2, shape2, radious, imageWidth, imageHeight2, aux);
                            }
                            else
                            {
                                devolverBola(tubo, sprite2, sprite, sprite3, shape2, radious, imageWidth, imageHeight2, aux);
                            }
                        }
                        else
                        {
                            guardarBola(pila, sprite2, shape2, radious, imageWidth, imageHeight2, aux);
                        }
                        
                        tubo = 0;
                    }
                    else {
                        if (sprite.getGlobalBounds().contains(mouseX, mouseY))
                        {
                            if (pila2->top() != NULL)
                            {
                                if (pila2->getCantBol() < 4 && aux->getColor() == pila2->top()->getColor())
                                {
                                    guardarBola(pila2, sprite, shape2, radious, imageWidth, imageHeight2, aux);
                                }
                                else
                                {
                                    devolverBola(tubo, sprite2, sprite, sprite3, shape2, radious, imageWidth, imageHeight2, aux);
                                }
                            }
                            else
                            {
                                guardarBola(pila2, sprite, shape2, radious, imageWidth, imageHeight2, aux);
                            }
                            tubo = 0;
                        }
                        else {
                            if (sprite3.getGlobalBounds().contains(mouseX, mouseY))
                            {
                                if (pila3->top()!=NULL)
                                {
                                    if (pila3->getCantBol() < 4 && aux->getColor() == pila3->top()->getColor())
                                    {
                                        guardarBola(pila3, sprite3, shape2, radious, imageWidth, imageHeight2, aux);
                                    }
                                    else
                                    {
                                        devolverBola(tubo, sprite2, sprite, sprite3, shape2, radious, imageWidth, imageHeight2, aux);
                                    }
                                }
                                else
                                {
                                    guardarBola(pila3, sprite3, shape2, radious, imageWidth, imageHeight2, aux);
                                }
                                tubo = 0;
                            }
                            else {
                                if (aux != NULL) {
                                    if (tubo != 0) {
                                        devolverBola(tubo, sprite2, sprite, sprite3, shape2, radious, imageWidth, imageHeight2, aux);
                                        tubo = 0;
                                    }
                                }
                            }
                        }
                    }
                    aux = NULL;
                }
                mouseClickedReleased = false;
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
            if (tubo != 0) {
                if (tubo == 1)
                {
                    if (pila->top() != NULL) {
                        aux = pila->pop();
                        pila->setCantBol(pila->getCantBol() - 1);
                    }
                }
                else {
                    if (tubo == 2) {
                        if (pila2->top() != NULL) {
                            aux = pila2->pop();
                            pila2->setCantBol(pila2->getCantBol() - 1);
                        }
                    }
                    else {
                        if (tubo == 3)
                        {
                            if (pila3->top()!=NULL) {
                                aux = pila3->pop();
                                pila3->setCantBol(pila3->getCantBol() - 1);
                            }
                            
                        }
                        else {
                            aux = NULL;
                        }
                    }
                }
            }
            /*sf::CircleShape shap(0);
            shap = aux->getShape();*/
            if (aux!=NULL) {
                //shape2 = shap;
                shape2 = aux->getShape();
                shape2.setPosition(mouseX -radious, mouseY -radious);
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
            mouseClickedReleased = true;
            if (aux != NULL) {
                shape2.setPosition(mouseX - radious, mouseY -radious);
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

        Tubo* t2 = pila2->top();
        while (t2 != NULL)
        {
            sf::CircleShape shap(0);
            //cout << " ciclo t" << endl;
            shap = t2->getShape();
            window.draw(shap);
            t2 = t2->getAnt();
        }

        Tubo* t3 = pila3->top();
        while (t3 != NULL)
        {
            sf::CircleShape shap(0);
            //cout << " ciclo t" << endl;
            shap = t3->getShape();
            window.draw(shap);
            t3 = t3->getAnt();
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

