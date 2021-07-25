#include "../../src/main.h"

const string ESPACIO = " ";

Parser::Parser(const string &linea)
{
    this->cantidad = 0;

    istringstream linea_s(linea);

    string especial;
    string posicion_x;
    string posicion_y;
    string basura;
    string id;

    // NOMBRE
    getline(linea_s, this->nombre, ' ');

    // CANTIDAD
    getline(linea_s, especial, '(');

    // BORRA EL ESPACIO DE LA CANTIDAD SI NO ESTA VACIA
    if (!especial.empty())
        especial.erase(especial.find(' '));

    getline(linea_s, posicion_x, ',');

    getline(linea_s, basura, ' ');

    getline(linea_s, posicion_y, ')');

    getline(linea_s, id, '\n');

    id.erase(remove(id.begin(), id.end(), ' '), id.end());

    this->clave = stoi(id);

    this->asignar_especial(especial);

    this->pos = new Posicion(stoi(posicion_x, nullptr), stoi(posicion_y, nullptr));

    this->objeto_obtenido = this->obtener_objeto_del_texto(this->nombre, this->clave);
}

Objeto *Parser::obtenerObjeto()
{
    return this->objeto_obtenido;
}

int Parser::getClave()
{
    return this->clave;
}

Objeto *Parser::obtener_objeto_del_texto(string texto, int clave)
{
    Objeto *nuevo_objeto;

    transform(texto.begin(), texto.end(), texto.begin(), ::tolower);

    if (texto == S_HUMANO)
    {
        nuevo_objeto = new Humano(clave);
    }
    else if (texto == S_HUMANO_CV)
    {
        nuevo_objeto = new Humano_cazador(clave);
    }
    else if (texto == S_ZOMBI)
    {
        nuevo_objeto = new Zombi(clave);
    }
    else if (texto == S_VAMPIRO)
    {
        nuevo_objeto = new Vampiro(clave);
    }
    else if (texto == S_VAMPIRELLA)
    {
        nuevo_objeto = new Vampirella();
    }
    else if (texto == S_NOSFERATU)
    {
        nuevo_objeto = new Nosferatu();
    }
    else if (texto == S_VANESA)
    {
        nuevo_objeto = new Vanesa();
    }
    else if (texto == S_ESCOPETA)
    {
        nuevo_objeto = new Escopeta(clave);
    }
    else if (texto == S_ESTACA)
    {
        nuevo_objeto = new Estaca(clave);
    }
    else if (texto == S_CRUZ)
    {
        nuevo_objeto = new Cruz(clave);
    }
    else if (texto == S_AGUA_BENDITA)
    {
        nuevo_objeto = new Agua_bendita(this->cantidad, clave);
    }
    else if (texto == S_BALA)
    {
        nuevo_objeto = new Bala(this->cantidad, clave);
    }
    else
    {
        throw Excepcion_error("No se pudo identificar un objeto en el archivo");
    }

    return nuevo_objeto;
}

void Parser::asignar_especial(const string &especial)
{
    bool caza_vampiros = especial == "CV";
    if (!caza_vampiros && !especial.empty())
    {
        this->cantidad = stoi(especial);
    }
    else if (caza_vampiros)
    {
        this->nombre += ESPACIO + especial;
    }
}

Posicion *Parser::obtener_posicion()
{
    return this->pos;
}

Parser::~Parser()
{
    delete this->pos;
}

Parser::Parser(ENUM_OBJETOS enum_objeto)
{
    if (enum_objeto == HUMANO)
    {
        this->nombre = S_HUMANO;
    }
    else if (enum_objeto == HUMANO_CV)
    {
        this->nombre = S_HUMANO_CV;
    }
    else if (enum_objeto == ZOMBIE)
    {
        this->nombre = S_ZOMBI;
    }
    else if (enum_objeto == VAMPIRO)
    {
        this->nombre = S_VAMPIRO;
    }
    else if (enum_objeto == VAMPIRELLA)
    {
        this->nombre = S_VAMPIRELLA;
    }
    else if (enum_objeto == NOSFERATU)
    {
        this->nombre = S_NOSFERATU;
    }
    else if (enum_objeto == VANESA)
    {
        this->nombre = S_VANESA;
    }
    else if (enum_objeto == AGUA_BENDITA)
    {
        this->nombre = S_AGUA_BENDITA;
    }
    else if (enum_objeto == CRUZ)
    {
        this->nombre = S_CRUZ;
    }
    else if (enum_objeto == ESTACA)
    {
        this->nombre = S_ESTACA;
    }
    else if (enum_objeto == ESCOPETA)
    {
        this->nombre = S_ESCOPETA;
    }
    else if (enum_objeto == BALAS)
    {
        this->nombre = S_BALA;
    }
    else
    {
        throw invalid_argument("No se puede dar de alta nuevo objeto");
    }
    this->cantidad = 0;
    this->objeto_obtenido = NULL;
    this->pos = NULL;
}

string Parser::obtener_nombre()
{
    return this->nombre;
}

Parser::Parser(const string &nombre, int cantidad)
{
    this->cantidad = cantidad;
    this->nombre = nombre;
    this->pos = NULL;
    this->objeto_obtenido = this->obtener_objeto_del_texto(this->nombre, this->clave);
}
