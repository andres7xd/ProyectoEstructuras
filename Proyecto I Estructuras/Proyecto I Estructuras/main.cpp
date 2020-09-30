
#include "Pila.h"
#include "ListaTubo.h"

using namespace sf;
using namespace std;
ListaTubo* Lt;
float imageWidth = 0;
float radious = 0;
float imageHeight = 0;
float imageHeight2 = 0;
int tubosllenos = 0;
sf::Texture image;
sf::Texture image2;

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
        return true;
    }
    return false;
}
int contarBolasColor(Pila* pila) {
    Bola* tubo = pila->top();
    int n = 0;
    Bola* aux = pila->top();
    while (tubo != NULL)
    {
        if (tubo->getColor() == aux->getColor()) {
            n++;
        }
        else {
            return n;
        }
        aux = tubo;
        tubo = tubo->getAnt();
    }
    return n;
}
int contarBolas(Pila* pila) {
    Bola* tubo = pila->top();
    int n = 0;
    while (tubo != NULL)
    {
        n++;
        tubo = tubo->getAnt();
    }
    return n;
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
bool validar(Tubo* t,Tubo*t2, int ncol) {
    Tubo* t3 = t;

    if (t2!=NULL) {
        Pila* p = t2->getPila();
        if (p->top()!=NULL) {
            string color = t2->getPila()->top()->getColor();
            string color2 = t3->getPila()->top()->getColor();
            bool val = true;
            while (val == true)
            {
                if (t3 != t2) {
                    if (t3 == NULL ) {
                        val = false;
                    }
                    else {
                        if (color == color2 || t3->getPila()->top() == NULL) {
                            if (contarBolasColor(t2->getPila())<=(4-contarBolas(t3->getPila()))) {
                                Bola* b = t2->getPila()->pop();
                                t3->getPila()->push(b->getShape(), b->getColor());
                                if (verificarTubos(t3->getPila()))
                                {
                                    tubosllenos++;
                                }
                                
                            }
                            else {
                                Tubo* tt = t2->getSig();
                                if (validar(t, tt, ncol))
                                {
                                    return true;
                                }
                            }
                            
                            Tubo* ttt = t2;
                            if (validar(t, ttt, ncol))
                            {
                                return true;
                            }
                            val = false;
                        }
                        else {
                            t3 = t3->getSig();
                            color2 = t3->getPila()->top()->getColor();
                        }
                    }
                }
                else {
                    t3 = t3->getSig();
                    //color2 = t3->getPila()->top()->getColor();
                }

            }
            
        }
        
    }
    if (tubosllenos==ncol) {
        return true;
    }
    else {
        return false;
    }
    
}
void guardar(Tubo* tubo, sf::Sprite sprite, float x, float y) {
    if (sprite.getGlobalBounds().contains(x, y)) {
        string dato = "";
        ofstream file;
        file.open("save\\archivo.txt");
        
        while (tubo!=NULL)
        {
            dato = "!";
            Bola* b = tubo->getPila()->top();
            string dato2 = "";
            while (b!=NULL)
            {
                string color = b->getColor();
                if (color=="Blue") {
                    dato2 = "@" + dato2;
                }
                else if(color == "White"){
                    dato2 = "#" + dato2;
                }
                else if (color == "Green") {
                    dato2 = "$" + dato2;
                }
                else if (color == "Red") {
                    dato2 = "%" + dato2;
                }
                else if (color == "Magenta") {
                    dato2 = "&" + dato2;
                }
                else if (color == "Yellow") {
                    dato2 = "*" + dato2;
                }
                b = b->getAnt();
            }
            tubo = tubo->getSig();
            file << dato + dato2 + "\n";
        }
        file.close();
    }
    
}
void cargarPartida(float windowWidth, float windowHeight) {
   
    char cadena[5];
    int con = 0;
    int ncol = 0;
    char cadena2[5];
    ifstream fe2("save\\archivo.txt");
    while (!fe2.eof()) {
        ncol++;
        fe2 >> cadena2;
    }
    fe2.close();
    ncol -= 1;
    int n = (ncol) * 75;
    ifstream fe("save\\archivo.txt");
    int contador = 0;
    while (!fe.eof()) {
        fe >> cadena;
        if (contador < ncol) {
            sf::Sprite sprite(image);
            sprite.setScale(0.5f, 0.5f);
            sprite.setPosition((windowWidth - n) + con - imageWidth, windowHeight - imageHeight);
            Pila* p = new Pila();
            for (int i = 1; i < 5; i++)
            {

                switch (cadena[i])
                {
                case '@':
                    llenarTubo(p, sprite, 1);
                    break;
                case '#':
                    llenarTubo(p, sprite, 2);
                    break;
                case '$':
                    llenarTubo(p, sprite, 3);
                    break;
                case '%':
                    llenarTubo(p, sprite, 4);
                    break;
                case '&':
                    llenarTubo(p, sprite, 5);
                    break;
                case '*':
                    llenarTubo(p, sprite, 6);
                    break;
                case ' ':

                default: break;
                }
                cadena[i] = ' ';
            }
            Lt->AgregarTubo(p, sprite);
            con += 150;
        }
        contador++;
    }
    fe.close();
}
void nivel(int nivel) {
    //ListaTubo
    
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

    image.loadFromFile("resourse\\Tubo4.png");
    
    image2.loadFromFile("resourse\\TuboTope.png");

    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    sf::CircleShape shape2(imageWidth - 7);
    shape2.setFillColor(sf::Color::Green);

    
    sf::Sprite spri(image);
    spri.setScale(0.5f, 0.5f);

    

    

    imageWidth = (spri.getTexture()->getSize().x / 2) * 0.5f;
    float imageWidth2 = (spri.getTexture()->getSize().x) * 0.5f;
    imageHeight = (spri.getTexture()->getSize().y / 2) * 0.5f;
    imageHeight2 = (spri.getTexture()->getSize().y) * 0.5f;


    float windowWidth = window.getSize().x / 2;
    float windowHeight = window.getSize().y / 2;

    sf::Texture image3;
    image3.loadFromFile("resourse\\Guardar.png");
    sf::Sprite spri2(image3);
    spri.setScale(0.5f, 0.5f);
    spri2.setPosition((windowWidth*2) -80, 10);

    int n = (ncol) * 75;
    //bool cargar = true;
    bool cargar = false;
    bool play = true;
    radious = imageWidth - 7;
    if (cargar == true) {
        Lt = new ListaTubo();
        cargarPartida(windowWidth, windowHeight);
    }
    else {
        srand(time(NULL));

        for (int i = 0; i < 6; i++)
        {
            bol[i] = 0;
            color[i] = 0;
        }


        asignarColor(ncol, color, num, var);


        
        while (play == true)
        {
            for (int i = 0; i < 6; i++)
            {
                bol[i] = 0;
            }
            Lt = new ListaTubo();
            for (int i = 0; i < ncol + 1; i++)
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
            //if (validar(Lt->getIni(), Lt->getIni(),ncol))
            //{
            play = false;
            //}
        }
        play = true;
    }
    
    
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
                guardar(t, spri2, event.mouseButton.x, event.mouseButton.y);
                while (t!=NULL)
                {
                    if (t->getSf().getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                    {
                        if (!verificarTubos(t->getPila())) {
                            
                            tubo = t->getId();
                            mouseClickedTubo = true;
                        }
                        else
                        {
                            tubo = 0;
                        }
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
                                    if (verificarTubos(p))
                                    {
                                        p->setTComp(true);
                                        tubosllenos++;
                                    }
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
                                if (verificarTubos(p))
                                {
                                    p->setTComp(true);
                                    tubosllenos++;
                                }
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
                dragging = true;
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
                if (aux != NULL) {
                    shape2 = aux->getShape();
                    shape2.setPosition(mouseX - radious, mouseY - radious);
                    mouseClickedReleased = true;
                }
            }
            
            mouseClickedTubo = false;
        }
        if (dragging == true)
        {
            
            if (aux != NULL) {
                mouseClickedReleased = true;
                shape2.setPosition(mouseX - radious, mouseY - radious);
            }
        }
        
        window.clear();
        window.draw(spri2);
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
        
        if (tubosllenos==nivel+1)
        {
            //system("Pause");
            play = false;
        }

        
        window.display();
    }
    window.close();
}

void menuNiveles() {

    int fps = 60;

    Texture* nivel1;
    nivel1 = new Texture();
    Sprite* snivel1;
    snivel1 = new Sprite();
    Texture* nivel2;
    nivel2 = new Texture();
    Sprite* snivel2;
    snivel2 = new Sprite();
    Texture* nivel3;
    nivel3 = new Texture();
    Sprite* snivel3;
    snivel3 = new Sprite();
    Texture* nivel4;
    nivel4 = new Texture();
    Sprite* snivel4;
    snivel4 = new Sprite();
    Texture* nivel5;
    nivel5 = new Texture();
    Sprite* snivel5;
    snivel5 = new Sprite();
    Texture* atras;
    atras = new Texture();
    Sprite* satras;
    satras = new Sprite();
    Texture* img1;
    img1 = new Texture();
    Sprite* simg1;
    simg1 = new Sprite();
    Texture* img2;
    img2 = new Texture();
    Sprite* simg2;
    simg2 = new Sprite();
    Texture* titulo;
    titulo = new Texture();
    Sprite* stitulo;
    stitulo = new Sprite();

    RenderWindow* ventana2;

    nivel1->loadFromFile("resourse\\Nivel1.png");
    snivel1->setTexture(*nivel1);
    snivel1->setPosition(320, 150);
    snivel1->setScale(0.6f, 0.6f);

    nivel2->loadFromFile("resourse\\Nivel2.png");
    snivel2->setTexture(*nivel2);
    snivel2->setPosition(320, 230);
    snivel2->setScale(0.6f, 0.6);

    nivel3->loadFromFile("resourse\\Nivel3.png");
    snivel3->setTexture(*nivel3);
    snivel3->setPosition(320, 310);
    snivel3->setScale(0.6f, 0.6);

    nivel4->loadFromFile("resourse\\Nivel4.png");
    snivel4->setTexture(*nivel4);
    snivel4->setPosition(320, 390);
    snivel4->setScale(0.6f, 0.6);

    nivel5->loadFromFile("resourse\\Nivel5.png");
    snivel5->setTexture(*nivel5);
    snivel5->setPosition(320, 470);
    snivel5->setScale(0.6f, 0.6f);

    atras->loadFromFile("resourse\\Atras.png");
    satras->setTexture(*atras);
    satras->setPosition(30, 550);
    satras->setScale(0.6f, 0.6f);

    img1->loadFromFile("resourse\\Img1.png");
    simg1->setTexture(*img1);
    simg1->setPosition(700, 100);
    simg1->setScale(0.7f, 0.7);

    img2->loadFromFile("resourse\\Img2.png");
    simg2->setTexture(*img2);
    simg2->setPosition(70, 100);
    simg2->setScale(0.7f, 0.7f);

    titulo->loadFromFile("resourse\\Titulo.png");
    stitulo->setTexture(*titulo);
    stitulo->setPosition(175, 20);
    stitulo->setScale(0.8f, 0.8f);

    ventana2 = new RenderWindow(VideoMode(800, 600), "Menu principal");
    ventana2->setFramerateLimit(fps);

    Event evento1;

    while (ventana2->isOpen())
    {
        while (ventana2->pollEvent(evento1)) {
            Vector2i posMouse;
            posMouse = Mouse::getPosition(*ventana2);
            posMouse = (Vector2i)ventana2->mapPixelToCoords(posMouse);
            FloatRect corMouse(Vector2f(posMouse), { 10,10 });
            switch (evento1.type) {
            case Event::MouseButtonPressed:
                if (Mouse::isButtonPressed(Mouse::Left)) {
                    if (snivel1->getGlobalBounds().intersects(corMouse)) {
                        ventana2->close();
                        nivel(1);
                    }
                    if (snivel2->getGlobalBounds().intersects(corMouse)) {
                        ventana2->close();
                        nivel(2);
                    }
                    if (snivel3->getGlobalBounds().intersects(corMouse)) {
                        ventana2->close();
                        nivel(3);
                    }
                    if (snivel4->getGlobalBounds().intersects(corMouse)) {
                        ventana2->close();
                        nivel(4);
                    }
                    if (snivel5->getGlobalBounds().intersects(corMouse)) {
                        ventana2->close();
                        nivel(5);
                    }
                }
            }
            ventana2->clear();
            ventana2->draw(*snivel1);
            ventana2->draw(*snivel2);
            ventana2->draw(*snivel3);
            ventana2->draw(*snivel4);
            ventana2->draw(*snivel5);
            ventana2->draw(*simg1);
            ventana2->draw(*simg2);
            ventana2->draw(*stitulo);
            ventana2->display();
        }

    }
}

void menuPrincipal() {

    int fps = 60;

    Texture* titulo;
    titulo = new Texture();
    Sprite* stitulo;
    stitulo = new Sprite();
    Texture* imgIniciar;
    imgIniciar = new Texture();
    Sprite* simgIniciar;
    simgIniciar = new Sprite();
    Texture* imgPartidasGuardadas;
    imgPartidasGuardadas = new Texture();
    Sprite* simgPartidasGuardadas;
    simgPartidasGuardadas = new Sprite();
    Texture* salir;
    salir = new Texture();
    Sprite* ssalir;
    ssalir = new Sprite();
    Texture* img1;
    img1 = new Texture();
    Sprite* simg1;
    simg1 = new Sprite();
    Texture* img2;
    img2 = new Texture();
    Sprite* simg2;
    simg2 = new Sprite();

    RenderWindow* ventana1;

    titulo->loadFromFile("resourse\\Titulo.png");
    stitulo->setTexture(*titulo);
    stitulo->setPosition(150, 20);
    stitulo->setScale(0.8f, 0.8f);

    imgIniciar->loadFromFile("resourse\\Iniciar.png");
    simgIniciar->setTexture(*imgIniciar);
    simgIniciar->setPosition(295, 200);
    simgIniciar->setScale(0.3f, 0.3f);

    imgPartidasGuardadas->loadFromFile("resourse\\PartidaGuardada.png");
    simgPartidasGuardadas->setTexture(*imgPartidasGuardadas);
    simgPartidasGuardadas->setPosition(220, 300);
    simgPartidasGuardadas->setScale(0.5f, 0.5f);

    salir->loadFromFile("resourse\\Salir.png");
    ssalir->setTexture(*salir);
    ssalir->setPosition(310, 400);
    ssalir->setScale(0.3f, 0.3f);

    img1->loadFromFile("resourse\\Img1.png");
    simg1->setTexture(*img1);
    simg1->setPosition(700, 300);
    simg1->setScale(0.7f, 0.7);

    img2->loadFromFile("resourse\\Img2.png");
    simg2->setTexture(*img2);
    simg2->setPosition(70, 300);
    simg2->setScale(0.7f, 0.7f);

    ventana1 = new RenderWindow(VideoMode(800, 600), "Menu principal");
    ventana1->setFramerateLimit(fps);

    Event evento1;

    while (ventana1->isOpen())
    {
        while (ventana1->pollEvent(evento1)) {
            Vector2i posMouse;
            posMouse = Mouse::getPosition(*ventana1);
            posMouse = (Vector2i)ventana1->mapPixelToCoords(posMouse);
            FloatRect corMouse(Vector2f(posMouse), { 10,10 });
            switch (evento1.type) {
            case Event::MouseButtonPressed:
                if (Mouse::isButtonPressed(Mouse::Left)) {
                    if (simgIniciar->getGlobalBounds().intersects(corMouse)) {
                        ventana1->close();
                        menuNiveles();
                    }
                    if (ssalir->getGlobalBounds().intersects(corMouse)) {
                        ventana1->close();
                    }
                    if (simgPartidasGuardadas->getGlobalBounds().intersects(corMouse)) {
                        ventana1->close();
                        Lt = new ListaTubo();
                        cargarPartida(ventana1->getSize().x/2, ventana1->getSize().y/2);
                    }
                }
            }
        }
        ventana1->clear();
        ventana1->draw(*stitulo);
        ventana1->draw(*simgIniciar);
        ventana1->draw(*simgPartidasGuardadas);
        ventana1->draw(*ssalir);
        ventana1->draw(*simg1);
        ventana1->draw(*simg2);
        ventana1->display();
    }
}
int main()
{
    menuPrincipal();

    return 0;
}

