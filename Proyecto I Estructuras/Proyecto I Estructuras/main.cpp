
#include "Pila.h"
#include "ListaTubo.h"
using namespace std;
ListaTubo* Lt;
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

/*void devolverBola(int tubo, sf::Sprite sprite2, sf::Sprite sprite, sf::Sprite sprite3, sf::Sprite sprite4, sf::CircleShape shape, Bola* aux) {
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
}*/
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
    for (int i = 0; i < n; i++)
    {
        if (num == color[i]) {
            bol[i] = bol[i] + 1;
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

void nivel(int nivel) {
    //ListaTubo
    Lt = new ListaTubo();
    int tubo = 0;
    int cantTubos = 4;
    int ncol = nivel + 1;
    int num = 0;
    int bol[6];
    int color[6];
    int con = 0;
    bool var = true;

    imageWidth = 0;
    radious = 0;
    imageHeight = 0;
    imageHeight2 = 0;
    tubosllenos = 0;
    

    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    sf::CircleShape shape2(imageWidth - 7);
    shape2.setFillColor(sf::Color::Green);

    sf::Texture image;
    image.loadFromFile("resourse\\Tubo4.png");
    sf::Sprite spri(image);
    spri.setScale(0.5f, 0.5f);

    sf::Texture image2;
    image2.loadFromFile("resourse\\TuboTope.png");

    imageWidth = (spri.getTexture()->getSize().x / 2) * 0.5f;
    float imageWidth2 = (spri.getTexture()->getSize().x) * 0.5f;
    imageHeight = (spri.getTexture()->getSize().y / 2) * 0.5f;
    imageHeight2 = (spri.getTexture()->getSize().y) * 0.5f;

    float windowWidth = window.getSize().x / 2;
    float windowHeight = window.getSize().y / 2;

    int n = (ncol) * 75;


    radious = imageWidth - 7;
    srand(time(0));
    
    for (int i = 0; i < 6; i++)
    {
        bol[i] = 0;
        color[i] = 0;
    }
    

    asignarColor(ncol, color, num, var);
    
    for (int i = 0; i < ncol+1; i++)
    {
        sf::Sprite sprite(image);
        sprite.setScale(0.5f, 0.5f);
        sprite.setPosition((windowWidth - n) + con - imageWidth, windowHeight - imageHeight);

        Pila* pil = new Pila();
        var = true;
        if (i < ncol) {
            for (int i = 0; i < 4; i++)
            {
                num = 1 + rand() % 6;
                var = true;
                num = validarRand(num, color, bol, var, ncol);
                llenarTubo(pil, sprite, num);
            }
        }
        Lt->AgregarTubo(pil, sprite);
        con += 150;
    }

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
    
    Bola* aux = NULL;
    while (play == true)
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                mouseClicked = true;
                Tubo* t = Lt->getIni();
                while (t!=NULL)
                {
                    if (t->getSf().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        dragging = true;
                        tubo = t->getId();
                        mouseClickedTubo = true;
                    }
                    t = t->getSig();
                }
            }
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
            {
                if (aux != NULL) {
                    Tubo* t = Lt->getIni();
                    while (t != NULL)
                    {
                        if (t->getSf().getGlobalBounds().contains(mouseX, mouseY))
                        {
                            Pila*& p = t->getPila();
                            if (p->top() != NULL)
                            {
                                if (p->getCantBol() < 4 && aux->getColor() == p->top()->getColor()) {
                                    guardarBola(p, t->getSf(), shape2, aux->getColor());
                                    p->setTComp(verificarTubos(p));
                                }
                                else
                                {
                                    Tubo* t2 = Lt->getIni();
                                    while (tubo!=t2->getId()) {

                                        t2 = t2->getSig();
                                    }
                                    guardarBola(t2->getPila(), t2->getSf(), shape2, aux->getColor());
                                }
                            }
                            else
                            {
                                guardarBola(p, t->getSf(), shape2, aux->getColor());
                                p->setTComp(verificarTubos(p));
                            }
                            tubo = 0;
                        }
                        
                        t = t->getSig();
                    }
                    if (tubo!=0) {
                        if (aux != NULL) {
                            if (tubo != 0) {
                                Tubo* t2 = Lt->getIni();
                                while (tubo != t2->getId()) {

                                    t2 = t2->getSig();
                                }
                                guardarBola(t2->getPila(), t2->getSf(), shape2, aux->getColor());
                                tubo = 0;
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
                Tubo* t = Lt->getIni();
                while (tubo != t->getId()) {

                    t = t->getSig();
                }
                Pila*& p = t->getPila();
                if (p->top() != NULL) {
                    aux = p->pop();
                    p->setCantBol(p->getCantBol() - 1);
                }else {
                    aux = NULL;
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
        Tubo* t = Lt->getIni();
        while (t != NULL)
        {
            sf::Sprite spriteTope(image2);
            spriteTope.setScale(0.5f, 0.5f);
            spriteTope.setPosition(t->getSf().getPosition().x, t->getSf().getPosition().y);
            window.draw(spriteTope);

            t = t->getSig();
        }
        if (mouseClickedReleased == true)
        {
            window.draw(shape2);
        }
        Tubo*t2 = Lt->getIni();
        while (t2!=NULL)
        {
            Bola* b = t2->getPila()->top();
            while (b!=NULL)
            {
                window.draw(b->getShape());
                
                b = b->getAnt();
            }
            
            window.draw(t2->getSf());
            t2 = t2->getSig();
        }
        

        
        window.display();
    }
    window.close();
}
int main()
{
    nivel(1);
    nivel(2);
    nivel(3);
    nivel(4);
    nivel(5);
    
 

    return 0;
}

