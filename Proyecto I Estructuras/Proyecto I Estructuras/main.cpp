
#include "Pila.h"
using namespace std;
Pila* pila = new Pila();
Pila* pila2 = new Pila();
Pila* pila3 = new Pila();
float imageWidth = 0;
float radious = 0;
float imageHeight = 0;
float imageHeight2 = 0;

MenuInicio* m = new MenuInicio();


void guardarBola(Pila*& p, sf::Sprite sprite, sf::CircleShape shape, string color ) {
    if (p->top() != NULL)
    {
        shape.setPosition(sprite.getPosition().x + imageWidth - radious, (p->top()->getShape()).getPosition().y - 57);
        p->push(shape, color);
    }
    else {
        shape.setPosition(sprite.getPosition().x + imageWidth - radious, sprite.getPosition().y + imageHeight2 - radious - 32);
        p->push(shape, color);
    }
    p->setCantBol(p->getCantBol() + 1);
}

void devolverBola(int tubo, sf::Sprite sprite2, sf::Sprite sprite, sf::Sprite sprite3, sf::CircleShape shape, Tubo* aux) {
    if (tubo == 1)
    {
        guardarBola(pila, sprite2, shape, aux->getColor());
    }
    else {
        if (tubo == 2)
        {
            guardarBola(pila2, sprite, shape, aux->getColor());
        }
        else {
            if (tubo == 3)
            {
                guardarBola(pila3, sprite3, shape, aux->getColor());
            }
        }
    }
}
void llenarTubo(Pila*& pila, sf::Sprite sprite, int num)
{
    sf::CircleShape shap1(radious);
    switch (num)
    {
    case 1:
        shap1.setFillColor(sf::Color::Blue);
        guardarBola(pila, sprite, shap1, "Blue");
        break;
    case 2: 
        shap1.setFillColor(sf::Color::White);
        guardarBola(pila, sprite, shap1, "White");
        break;
    case 3: 
        shap1.setFillColor(sf::Color::Green);
        guardarBola(pila, sprite, shap1, "Green");
        break;
    case 4:
        shap1.setFillColor(sf::Color::Red);
        guardarBola(pila, sprite, shap1, "Red");
        break;
    case 5:
        shap1.setFillColor(sf::Color::Magenta);
        guardarBola(pila, sprite, shap1, "Magenta");
        break;
    case 6:
        shap1.setFillColor(sf::Color::Yellow);
        guardarBola(pila, sprite, shap1, "Yellow");
        break;
    default: break;
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

    sf::Texture image2;
    image2.loadFromFile("resourse\\TuboTope.png");
    sf::Sprite spriteTope(image2);
    spriteTope.setScale(0.5f, 0.5f);

    


    imageWidth = (sprite.getTexture()->getSize().x / 2) * 0.5f;
    float imageWidth2 = (sprite.getTexture()->getSize().x) * 0.5f;
    imageHeight = (sprite.getTexture()->getSize().y / 2) * 0.5f;
    imageHeight2 = (sprite.getTexture()->getSize().y) * 0.5f;
    float windowWidth = window.getSize().x/2;
    float windowHeight = window.getSize().y/2;


    sprite.setPosition(windowWidth - imageWidth, windowHeight - imageHeight);
    spriteTope.setPosition(windowWidth - imageWidth, windowHeight - imageHeight);

    sf::Sprite sprite2(image);
    sprite2.setScale(0.5f, 0.5f);

    sf::Sprite spriteTope2(image2);
    spriteTope2.setScale(0.5f, 0.5f);
    
    sprite2.setPosition(windowWidth - imageWidth-150, windowHeight - imageHeight);
    spriteTope2.setPosition(windowWidth - imageWidth - 150, windowHeight - imageHeight);

    sf::Sprite sprite3(image);
    sprite3.setScale(0.5f, 0.5f);

    sf::Sprite spriteTope3(image2);
    spriteTope3.setScale(0.5f, 0.5f);
    
    sprite3.setPosition(windowWidth - imageWidth+150, windowHeight - imageHeight);
    spriteTope3.setPosition(windowWidth - imageWidth + 150, windowHeight - imageHeight);

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

    radious = imageWidth - 7;
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
    srand(time(0));
    int num = 0;
    int nivel = 1;
    int bol[6];
    int color[6];
    for (int i = 0; i < 6; i++)
    {
        bol[i] = 0;
        color[i] = 0;
    }
    int con = 0;
    bool var = true;
    bool var2 = false;
    for (int i = 0; i < nivel+1; i++)
    {
        num = 1 + rand() % 6;
        var = true;
        while (var != false)
        {
            for (int j = 0; j < 6; j++)
            {
                if (color[j] == num) {
                    var2 = true;
                }
            }
            if (var2==true) {
                num = 1 + rand() % 6;
                var2 = false;
            }
            else {
                var = false;
            }
        }
        color[i] = num;
        //cout<< num << endl;
    }
    
    cout<< color[0];
    cout<< color[1] << endl;
    var = true;
    for (int i = 0; i < 4; i++)
    {   
        num = 1 + rand() % 6;
        var = true;
        while (var!=false)
        {
            if (num!=color[0] && num != color[1]) {
                num = 1 + rand() % 6;
            }
            else {
                var = false;
            }
        }
        if (num == color[0]) {
            if (bol[0]<4) {
                bol[0] = bol[0] + 1;
            }
        }
        else {
            if (num == color[1]) {
                if (bol[1] < 4) {
                    bol[1] = bol[1] + 1;
                }
            }
        }
        llenarTubo(pila, sprite2, num);
        cout << num ;
        num = 1 + rand() % 6;
        var = true;
        while (var != false)
        {
            if (num != color[0] && num != color[1]) {
                num = 1 + rand() % 6;
            }
            else {
                var = false;
            }
        }
        if (num == color[0]) {
            if (bol[0] < 4) {
                bol[0] = bol[0] + 1;
            }
        }
        else {
            if (num == color[1]) {
                if (bol[1] < 4) {
                    bol[1] = bol[1] + 1;
                }
            }
        }
        llenarTubo(pila2, sprite, num);
        cout << num << endl;
        
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
                                guardarBola(pila, sprite2, shape2, aux->getColor());
                            }
                            else
                            {
                                devolverBola(tubo, sprite2, sprite, sprite3, shape2, aux);
                            }
                        }
                        else
                        {
                            guardarBola(pila, sprite2, shape2, aux->getColor());
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
                                    guardarBola(pila2, sprite, shape2, aux->getColor());
                                }
                                else
                                {
                                    devolverBola(tubo, sprite2, sprite, sprite3, shape2, aux);
                                }
                            }
                            else
                            {
                                guardarBola(pila2, sprite, shape2, aux->getColor());
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
                                        guardarBola(pila3, sprite3, shape2, aux->getColor());
                                    }
                                    else
                                    {
                                        devolverBola(tubo, sprite2, sprite, sprite3, shape2, aux);
                                    }
                                }
                                else
                                {
                                    guardarBola(pila3, sprite3, shape2, aux->getColor());
                                }
                                tubo = 0;
                            }
                            else {
                                if (aux != NULL) {
                                    if (tubo != 0) {
                                        devolverBola(tubo, sprite2, sprite, sprite3, shape2, aux);
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
        window.draw(spriteTope);
        window.draw(spriteTope2);
        window.draw(spriteTope3);

        Tubo* t = pila->top();
        while (t != NULL)
        {
            sf::CircleShape shap(0);
            //cout << " ciclo t" << endl;
            shap = t->getShape();
            window.draw(shap);
            t = t->getAnt();
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


        if (mouseClickedReleased == true)
        {
            window.draw(shape2);
        }

        
        window.draw(sprite);
        window.draw(sprite2);
        window.draw(sprite3);

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

