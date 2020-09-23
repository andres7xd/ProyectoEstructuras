
#include "Pila.h"
#include "ListaTubo.h"
using namespace std;
Pila* pila = new Pila();
Pila* pila2 = new Pila();
Pila* pila3 = new Pila();
Pila* pila4 = new Pila();
float imageWidth = 0;
float radious = 0;
float imageHeight = 0;
float imageHeight2 = 0;
int tubosllenos = 0;

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

void devolverBola(int tubo, sf::Sprite sprite2, sf::Sprite sprite, sf::Sprite sprite3, sf::Sprite sprite4, sf::CircleShape shape, Bola* aux) {
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
            else {
                if (tubo == 4)
                {
                    guardarBola(pila4, sprite4, shape, aux->getColor());
                }
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
int validarRand(int num, int color[], int bol[], bool var, int n) {
    while (var != false)
    {
        bool b = true;
        while (b != false) {
            for (int j = 0; j < n; j++)
            {
                if (num == color[j]) {
                    b = false;
                }
            }
            if (b!=false) {
                num = 1 + rand() % 6;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (num == color[i]) {
                if (bol[i] >= 4) {
                    num = 1 + rand() % 6;
                }
                else
                {
                    var = false;
                }
            }
        }
    }
    if (num == color[0]) {
        bol[0] = bol[0] + 1;       
    }
    else {
        if (num == color[1]) {
            bol[1] = bol[1] + 1;         
        }
        else {
            if (num == color[2]) {
                bol[2] = bol[2] + 1;
            }
        }
    }
    return num;
}
bool verificarTubos(Pila* pila) {
    Bola* tubo = pila->top();
    int n = 0;
    Bola* aux = pila->top();
    while (tubo!=NULL)
    {
        if (tubo->getColor()==aux->getColor()) {
            n++;
        }else{
            return false;
        }
        aux = tubo;
        tubo = tubo->getAnt();
    }
    if (n==4) {
        tubosllenos++;
        return true;
    }
    return false;
}
void asignarColor(int n, int color[],int num, bool var) {
    bool var2 = false;
    for (int i = 0; i < n; i++)
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
            if (var2 == true) {
                num = 1 + rand() % 6;
                var2 = false;
            }
            else {
                var = false;
            }
        }
        color[i] = num;
    }
}
void nivel1() {
    int tubo = 0;
    int cantTubos = 3;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    sf::Texture image;
    image.loadFromFile("resourse\\Tubo4.png");
    sf::Sprite sprite(image);
    sprite.setScale(0.5f, 0.5f);

    sf::Texture image2;
    image2.loadFromFile("resourse\\TuboTope.png");
    sf::Sprite spriteTope(image2);
    spriteTope.setScale(0.5f, 0.5f);

    imageWidth = (sprite.getTexture()->getSize().x / 2) * 0.5f;
    float imageWidth2 = (sprite.getTexture()->getSize().x) * 0.5f;
    imageHeight = (sprite.getTexture()->getSize().y / 2) * 0.5f;
    imageHeight2 = (sprite.getTexture()->getSize().y) * 0.5f;
    float windowWidth = window.getSize().x / 2;
    float windowHeight = window.getSize().y / 2;


    sprite.setPosition(windowWidth - imageWidth, windowHeight - imageHeight);
    spriteTope.setPosition(windowWidth - imageWidth, windowHeight - imageHeight);

    sf::Sprite sprite2(image);
    sprite2.setScale(0.5f, 0.5f);

    sf::Sprite spriteTope2(image2);
    spriteTope2.setScale(0.5f, 0.5f);

    sprite2.setPosition(windowWidth - imageWidth - 150, windowHeight - imageHeight);
    spriteTope2.setPosition(windowWidth - imageWidth - 150, windowHeight - imageHeight);

    sf::Sprite sprite3(image);
    sf::Sprite sprite4(image);
    sprite3.setScale(0.5f, 0.5f);

    sf::Sprite spriteTope3(image2);
    spriteTope3.setScale(0.5f, 0.5f);

    sprite3.setPosition(windowWidth - imageWidth + 150, windowHeight - imageHeight);
    spriteTope3.setPosition(windowWidth - imageWidth + 150, windowHeight - imageHeight);

    sf::CircleShape shape2(imageWidth - 7);
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
    srand(time(0));
    int num = 0;
    int nivel = 1;
    int ncol = nivel + 1;
    int bol[6];
    int color[6];
    for (int i = 0; i < 6; i++)
    {
        bol[i] = 0;
        color[i] = 0;
    }
    int con = 0;
    bool var = true;
    
    
    asignarColor(ncol,color,num,var);
    var = true;
    for (int i = 0; i < 4; i++)
    {
        num = 1 + rand() % 6;
        var = true;
        num = validarRand(num, color, bol, var, ncol);
        llenarTubo(pila, sprite2, num);
        num = 1 + rand() % 6;
        var = true;
        num = validarRand(num, color, bol, var, ncol);
        llenarTubo(pila2, sprite, num);
    }
    Bola* aux = NULL;
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
                                pila->setTComp(verificarTubos(pila));
                            }
                            else
                            {
                                devolverBola(tubo, sprite2, sprite, sprite3, sprite4, shape2, aux);
                            }
                        }
                        else
                        {
                            guardarBola(pila, sprite2, shape2, aux->getColor());
                            pila->setTComp(verificarTubos(pila));
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
                                    pila2->setTComp(verificarTubos(pila2));
                                }
                                else
                                {
                                    devolverBola(tubo, sprite2, sprite, sprite3, sprite4, shape2, aux);
                                }
                            }
                            else
                            {
                                guardarBola(pila2, sprite, shape2, aux->getColor());
                                pila2->setTComp(verificarTubos(pila2));
                            }
                            tubo = 0;
                        }
                        else {
                            if (sprite3.getGlobalBounds().contains(mouseX, mouseY))
                            {
                                if (pila3->top() != NULL)
                                {
                                    if (pila3->getCantBol() < 4 && aux->getColor() == pila3->top()->getColor())
                                    {

                                        guardarBola(pila3, sprite3, shape2, aux->getColor());
                                        pila3->setTComp(verificarTubos(pila3));
                                    }
                                    else
                                    {
                                        devolverBola(tubo, sprite2, sprite, sprite3, sprite4, shape2, aux);
                                    }
                                }
                                else
                                {
                                    guardarBola(pila3, sprite3, shape2, aux->getColor());
                                    pila3->setTComp(verificarTubos(pila3));
                                }
                                tubo = 0;
                            }
                            else {
                                if (aux != NULL) {
                                    if (tubo != 0) {
                                        devolverBola(tubo, sprite2, sprite, sprite3, sprite4, shape2, aux);
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
            aux = new Bola();
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
                            if (pila3->top() != NULL) {
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
            if (aux != NULL) {
                shape2 = aux->getShape();
                shape2.setPosition(mouseX - radious, mouseY - radious);
                mouseClickedReleased = true;
            }
             mouseClickedTubo = false;
        }
        if (dragging == true)
        {
            mouseClickedReleased = true;
            if (aux != NULL) {
                shape2.setPosition(mouseX - radious, mouseY - radious);
            }
        }
        window.clear();
        window.draw(spriteTope);
        window.draw(spriteTope2);
        window.draw(spriteTope3);

        Bola* t = pila->top();
        while (t != NULL)
        {
            sf::CircleShape shap(0);
            shap = t->getShape();
            window.draw(shap);
            t = t->getAnt();
        }
        Bola* t2 = pila2->top();
        while (t2 != NULL)
        {
            sf::CircleShape shap(0);
            shap = t2->getShape();
            window.draw(shap);
            t2 = t2->getAnt();
        }
        Bola* t3 = pila3->top();
        while (t3 != NULL)
        {
            sf::CircleShape shap(0);
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

        if (tubosllenos == nivel + 1) {
            cout << "Nivel Completado" << endl;
            play = false;
            system("Pause");
        }
        window.display();
    }
    window.close();
}
void nivel2() {

    int tubo = 0;
    int cantTubos = 4;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    sf::Texture image;
    image.loadFromFile("resourse\\Tubo4.png");
    sf::Sprite sprite(image);
    sprite.setScale(0.5f, 0.5f);

    

    sf::Texture image2;
    image2.loadFromFile("resourse\\TuboTope.png");
    sf::Sprite spriteTope(image2);
    spriteTope.setScale(0.5f, 0.5f);

    imageWidth = (sprite.getTexture()->getSize().x / 2) * 0.5f;
    float imageWidth2 = (sprite.getTexture()->getSize().x) * 0.5f;
    imageHeight = (sprite.getTexture()->getSize().y / 2) * 0.5f;
    imageHeight2 = (sprite.getTexture()->getSize().y) * 0.5f;
    float windowWidth = window.getSize().x / 2;
    float windowHeight = window.getSize().y / 2;


    sprite.setPosition(windowWidth - imageWidth, windowHeight - imageHeight);
    spriteTope.setPosition(windowWidth - imageWidth, windowHeight - imageHeight);
    ///////////////////////////////////////////////////////////////////////////////sprite
    ListaTubo Lt;
    Lt.AgregarTubo(pila, sprite);
    Lt.AgregarTubo(pila2, sprite);
    cout << Lt.getIni()->getId();
    cout << Lt.getIni()->getSig()->getId();

    sf::Sprite sprite2(image);
    sprite2.setScale(0.5f, 0.5f);

    sf::Sprite spriteTope2(image2);
    spriteTope2.setScale(0.5f, 0.5f);

    sprite2.setPosition(windowWidth - imageWidth - 150, windowHeight - imageHeight);
    spriteTope2.setPosition(windowWidth - imageWidth - 150, windowHeight - imageHeight);


    sf::Sprite sprite3(image);
    sprite3.setScale(0.5f, 0.5f);

    sf::Sprite spriteTope3(image2);
    spriteTope3.setScale(0.5f, 0.5f);

    sprite3.setPosition(windowWidth - imageWidth + 150, windowHeight - imageHeight);
    spriteTope3.setPosition(windowWidth - imageWidth + 150, windowHeight - imageHeight);

    sf::Sprite sprite4(image);
    sprite4.setScale(0.5f, 0.5f);

    sf::Sprite spriteTope4(image2);
    spriteTope4.setScale(0.5f, 0.5f);

    sprite4.setPosition(windowWidth - imageWidth + 300, windowHeight - imageHeight);
    spriteTope4.setPosition(windowWidth - imageWidth + 300, windowHeight - imageHeight);

    sf::CircleShape shape2(imageWidth - 7);
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
    srand(time(0));
    int num = 0;
    int nivel = 2;
    int ncol = nivel + 1;
    int bol[6];
    int color[6];
    for (int i = 0; i < 6; i++)
    {
        bol[i] = 0;
        color[i] = 0;
    }
    int con = 0;
    bool var = true;


    asignarColor(ncol, color, num, var);
   /* cout << color[0];
    cout << color[1];
    cout << color[2]<<endl;*/
    var = true;
    for (int i = 0; i < 4; i++)
    {
        num = 1 + rand() % 6;
        var = true;
        num = validarRand(num, color, bol, var, ncol);
        llenarTubo(pila, sprite2, num);
        num = 1 + rand() % 6;
        var = true;
        num = validarRand(num, color, bol, var, ncol);
        llenarTubo(pila2, sprite, num);
        num = 1 + rand() % 6;
        var = true;
        num = validarRand(num, color, bol, var, ncol);
        llenarTubo(pila3, sprite3, num);
    }
    Bola* aux = NULL;
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
                            if (sprite4.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                                dragging = true;
                                tubo = 4;
                                mouseClickedTubo = true;
                            }
                            else {
                                tubo = 0;
                            }
                            
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
                                pila->setTComp(verificarTubos(pila));
                            }
                            else
                            {
                                devolverBola(tubo, sprite2, sprite, sprite3, sprite4, shape2, aux);
                            }
                        }
                        else
                        {
                            guardarBola(pila, sprite2, shape2, aux->getColor());
                            pila->setTComp(verificarTubos(pila));
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
                                    pila2->setTComp(verificarTubos(pila2));
                                }
                                else
                                {
                                    devolverBola(tubo, sprite2, sprite, sprite3, sprite4, shape2, aux);
                                }
                            }
                            else
                            {
                                guardarBola(pila2, sprite, shape2, aux->getColor());
                                pila2->setTComp(verificarTubos(pila2));
                            }
                            tubo = 0;
                        }
                        else {
                            if (sprite3.getGlobalBounds().contains(mouseX, mouseY))
                            {
                                if (pila3->top() != NULL)
                                {
                                    if (pila3->getCantBol() < 4 && aux->getColor() == pila3->top()->getColor())
                                    {

                                        guardarBola(pila3, sprite3, shape2, aux->getColor());
                                        pila3->setTComp(verificarTubos(pila3));
                                    }
                                    else
                                    {
                                        devolverBola(tubo, sprite2, sprite, sprite3, sprite4, shape2, aux);
                                    }
                                }
                                else
                                {
                                    guardarBola(pila3, sprite3, shape2, aux->getColor());
                                    pila3->setTComp(verificarTubos(pila3));
                                }
                                tubo = 0;

                            }
                            else {
                                
                                if (sprite4.getGlobalBounds().contains(mouseX, mouseY))
                                {
                                    if (pila4->top() != NULL)
                                    {
                                        if (pila4->getCantBol() < 4 && aux->getColor() == pila4->top()->getColor())
                                        {

                                            guardarBola(pila4, sprite4, shape2, aux->getColor());
                                            pila4->setTComp(verificarTubos(pila4));
                                        }
                                        else
                                        {
                                            devolverBola(tubo, sprite2, sprite, sprite3, sprite4, shape2, aux);
                                        }
                                    }
                                    else
                                    {
                                        guardarBola(pila4, sprite4, shape2, aux->getColor());
                                        pila4->setTComp(verificarTubos(pila4));
                                    }
                                    tubo = 0;
                                }
                                else {
                                    if (aux != NULL) {
                                        if (tubo != 0) {
                                            devolverBola(tubo, sprite2, sprite, sprite3, sprite4, shape2, aux);
                                            tubo = 0;
                                        }
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
            aux = new Bola();
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
                            if (pila3->top() != NULL) {
                                aux = pila3->pop();
                                pila3->setCantBol(pila3->getCantBol() - 1);
                            }

                        }
                        else {
                            if (tubo == 4) {
                                if (pila4->top() != NULL) {
                                    aux = pila4->pop();
                                    pila4->setCantBol(pila4->getCantBol() - 1);
                                }
                            }
                            else {
                                aux = NULL;
                            }
                            
                        }
                    }
                }
            }
            if (aux != NULL) {
                shape2 = aux->getShape();
                shape2.setPosition(mouseX - radious, mouseY - radious);
                mouseClickedReleased = true;
            }
            mouseClickedTubo = false;
        }
        if (dragging == true)
        {
            mouseClickedReleased = true;
            if (aux != NULL) {
                shape2.setPosition(mouseX - radious, mouseY - radious);
            }
        }
        window.clear();
        window.draw(spriteTope);
        window.draw(spriteTope2);
        window.draw(spriteTope3);
        window.draw(spriteTope4);

        Bola* t = pila->top();
        while (t != NULL)
        {
            sf::CircleShape shap(0);
            shap = t->getShape();
            window.draw(shap);
            t = t->getAnt();
        }
        Bola* t2 = pila2->top();
        while (t2 != NULL)
        {
            sf::CircleShape shap(0);
            shap = t2->getShape();
            window.draw(shap);
            t2 = t2->getAnt();
        }
        Bola* t3 = pila3->top();
        while (t3 != NULL)
        {
            sf::CircleShape shap(0);
            shap = t3->getShape();
            window.draw(shap);
            t3 = t3->getAnt();
        }
        Bola* t4 = pila4->top();
        while (t4 != NULL)
        {
            sf::CircleShape shap(0);
            shap = t4->getShape();
            window.draw(shap);
            t4 = t4->getAnt();
        }
        if (mouseClickedReleased == true)
        {
            window.draw(shape2);
        }
   
        window.draw(Lt.getIni()->getSf());
    /*    window.draw(sprite);*/
        window.draw(sprite2);
        window.draw(sprite3);
        window.draw(sprite4);

        if (tubosllenos == nivel + 1) {
            cout << "Nivel Completado" << endl;
            play = false;
            
        }
        window.display();
    }
    window.close();
}
int main()
{
    nivel1();
    tubosllenos = 0;
     imageWidth = 0;
     radious = 0;
     imageHeight = 0;
     imageHeight2 = 0;
    pila = new Pila();
    pila2 = new Pila();
    pila3 = new Pila();
    pila4 = new Pila();
    nivel2();

    
 

    return 0;
}

