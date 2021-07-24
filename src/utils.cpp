#include "main.h"

BANDO parsearTextoABando(string texto)
{
    toLower(texto);

    if (texto == S_HUMANO || texto == S_HUMANO_CV || texto == S_VANESA)
        return HUMANOS;

    if (texto == S_VAMPIRELLA || texto == S_VAMPIRO || texto == S_NOSFERATU || texto == S_ZOMBI)
        return MONSTRUOS;

    return OBJETO;
}

ENUM_OBJETOS parsearTextoAObjeto(string texto)
{
    toLower(texto);

    if (texto == S_HUMANO)
        return HUMANO;
    else if (texto == S_HUMANO_CV)
        return HUMANO_CV;
    else if (texto == S_ZOMBI)
        return ZOMBIE;
    else if (texto == S_VAMPIRO)
        return VAMPIRO;
    else if (texto == S_VAMPIRELLA)
        return VAMPIRELLA;
    else if (texto == S_NOSFERATU)
        return NOSFERATU;
    else if (texto == S_VANESA)
        return VANESA;
    else if (texto == S_AGUA_BENDITA)
        return AGUA_BENDITA;
    else if (texto == S_CRUZ)
        return CRUZ;
    else if (texto == S_ESTACA)
        return ESTACA;
    else if (texto == S_ESCOPETA)
        return ESCOPETA;
    else
        return BALAS;
}

ID parseId(int id)
{
    if (id == ID_VANESA)
        return ID_VANESA;

    if (id == ID_VAMPIRELLA)
        return ID_VAMPIRELLA;

    if (id == ID_NOSFERATU)
        return ID_NOSFERATU;

    if (id >= ID_HUMANO && id < ID_HUMANO_CV)
        return ID_HUMANO;

    else if (id >= ID_HUMANO_CV && id < ID_ZOMBIE)
        return ID_HUMANO_CV;

    else if (id >= ID_ZOMBIE && id < NOSFERATU)
        return ID_ZOMBIE;

    else if (id >= ID_VAMPIRO && id < ID_AGUA_BENDITA)
        return ID_VAMPIRO;

    else if (id >= ID_AGUA_BENDITA && id < ID_CRUZ)
        return ID_AGUA_BENDITA;

    else if (id >= ID_CRUZ && id < ID_ESCOPETA)
        return ID_CRUZ;

    else if (id >= ID_ESCOPETA && id < ID_BALAS)
        return ID_ESCOPETA;

    else if (id >= ID_BALAS && id < ID_ESTACA)
        return ID_BALAS;

    else if (id >= ID_ESTACA && id < ID_NO_VALIDO)
        return ID_ESTACA;

    return ID_NO_VALIDO;
}

bool esIdValido(int id, ENUM_OBJETOS objeto)
{
    switch (objeto)
    {
    case VANESA:
        return id == ID_VANESA;
    case HUMANO:
        return id >= ID_HUMANO && id < ID_HUMANO_CV;
    case HUMANO_CV:
        return id >= ID_HUMANO_CV && id < ID_ZOMBIE;
    case ZOMBIE:
        return id >= ZOMBIE && id < ID_NOSFERATU;
    case NOSFERATU:
        return id == ID_NOSFERATU;
    case VAMPIRELLA:
        return id == ID_VAMPIRELLA;
    case VAMPIRO:
        return id >= ID_VAMPIRO && id < ID_AGUA_BENDITA;
    case AGUA_BENDITA:
        return id >= ID_AGUA_BENDITA && id < ID_CRUZ;
    case CRUZ:
        return id >= ID_CRUZ && id < ID_ESCOPETA;
    case ESCOPETA:
        return id >= ID_ESCOPETA && id < ID_BALAS;
    case BALAS:
        return id >= ID_BALAS && id < ID_ESTACA;
    case ESTACA:
        return id >= ID_ESTACA && id < ID_NO_VALIDO;
    default:
        return false;
    }
}

void toLower(string &str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}