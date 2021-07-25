#include "../../src/main.h"

const string ESPACIO = " ";

Parser::Parser(const string &linea)
{
    this->cantidad = 0;

    istringstream linea_s(linea);

    string especial, posicionX, posicionY, basura, id;

    // NOMBRE
    getline(linea_s, this->nombre, ' ');

    // CANTIDAD
    getline(linea_s, especial, '(');

    // BORRA EL ESPACIO DE LA CANTIDAD SI NO ESTA VACIA
    if (!especial.empty())
        especial.erase(especial.find(' '));

    getline(linea_s, posicionX, ',');

    getline(linea_s, basura, ' ');

    getline(linea_s, posicionY, ')');

    getline(linea_s, id, '\n');

    id.erase(remove(id.begin(), id.end(), ' '), id.end());

    this->clave = stoi(id);

    this->setEspecial(especial);

    this->pos = new Posicion(stoi(posicionX, nullptr), stoi(posicionY, nullptr));

    this->objeto = this->obtenerObjetoDelTexto(this->nombre, this->clave, this->pos->getFila(), this->pos->getColumna());
}

Objeto *Parser::getObjeto()
{
    return this->objeto;
}

int Parser::getId()
{
    return this->clave;
}

Objeto *Parser::obtenerObjetoDelTexto(string texto, int clave, int fila, int columna)
{
    Objeto *nuevoObjeto;

    transform(texto.begin(), texto.end(), texto.begin(), ::tolower);

    if (texto == S_HUMANO)
    {
        nuevoObjeto = new Humano(clave, fila, columna);
    }
    else if (texto == S_HUMANO_CV)
    {
        nuevoObjeto = new Humano_cazador(clave, fila, columna);
    }
    else if (texto == S_ZOMBI)
    {
        nuevoObjeto = new Zombi(clave, fila, columna);
    }
    else if (texto == S_VAMPIRO)
    {
        nuevoObjeto = new Vampiro(clave, fila, columna);
    }
    else if (texto == S_VAMPIRELLA)
    {
        nuevoObjeto = new Vampirella(fila, columna);
    }
    else if (texto == S_NOSFERATU)
    {
        nuevoObjeto = new Nosferatu(fila, columna);
    }
    else if (texto == S_VANESA)
    {
        nuevoObjeto = new Vanesa(fila, columna);
    }
    else if (texto == S_ESCOPETA)
    {
        nuevoObjeto = new Escopeta(clave, fila, columna);
    }
    else if (texto == S_ESTACA)
    {
        nuevoObjeto = new Estaca(clave, fila, columna);
    }
    else if (texto == S_CRUZ)
    {
        nuevoObjeto = new Cruz(clave, fila, columna);
    }
    else if (texto == S_AGUA_BENDITA)
    {
        nuevoObjeto = new Agua_bendita(this->cantidad, clave, fila, columna);
    }
    else if (texto == S_BALA)
    {
        nuevoObjeto = new Bala(this->cantidad, clave, fila, columna);
    }
    else
    {
        throw Excepcion_error("No se pudo identificar un objeto en el archivo");
    }

    return nuevoObjeto;
}

void Parser::setEspecial(const string &especial)
{
    bool cazaVampiros = especial == "CV";
    if (!cazaVampiros && !especial.empty())
    {
        this->cantidad = stoi(especial);
    }
    else if (cazaVampiros)
    {
        this->nombre += ESPACIO + especial;
    }
}

Posicion *Parser::getPosicion()
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
    this->objeto = NULL;
    this->pos = NULL;
}

string Parser::getNombre()
{
    return this->nombre;
}

Parser::Parser(const string &nombre, int cantidad, int fila, int columna)
{
    this->cantidad = cantidad;
    this->nombre = nombre;
    this->pos = NULL;
    this->objeto = this->obtenerObjetoDelTexto(this->nombre, this->clave, (fila + 1), (columna + 1));
}
