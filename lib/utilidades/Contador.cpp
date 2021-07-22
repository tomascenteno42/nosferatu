#include "../../src/main.h"

Contador::Contador()
{
}

int Contador::obtener_cantidad_existentes(const string &nombre)
{
    int cantidad = 0;
    if (nombre == S_BALA)
    {
        cantidad = Bala::obtener_existentes();
    }
    else if (nombre == S_CRUZ)
    {
        cantidad = Cruz::obtener_existentes();
    }
    else if (nombre == S_ESTACA)
    {
        cantidad = Estaca::obtener_existentes();
    }
    else if (nombre == S_AGUA_BENDITA)
    {
        cantidad = Agua_bendita::obtener_existentes();
    }
    else if (nombre == S_HUMANO)
    {
        cantidad = Humano::obtener_existentes();
    }
    else if (nombre == S_HUMANO_CV)
    {
        cantidad = Humano_cazador::obtener_existentes();
    }
    else if (nombre == S_VAMPIRO)
    {
        cantidad = Vampiro::obtener_existentes();
    }
    else if (nombre == S_VAMPIRELLA)
    {
        cantidad = Vampirella::obtener_existentes();
    }
    else if (nombre == S_ZOMBI)
    {
        cantidad = Zombi::obtener_existentes();
    }
    else if (nombre == S_NOSFERATU)
    {
        cantidad = Nosferatu::obtener_existentes();
    }
    else if (nombre == S_VANESA)
    {
        cantidad = Vanesa::obtener_existentes();
    }
    else if (nombre == S_ESCOPETA)
    {
        cantidad = Escopeta::obtener_existentes();
    }
    return cantidad;
}

float Contador::obtener_porcentaje(const string &nombre)
{
    int sobre_total = 0;
    if (nombre == S_HUMANO_CV || nombre == S_HUMANO || nombre == S_VAMPIRO || nombre == S_ZOMBI)
    {
        sobre_total = Humano::obtener_existentes() + Vampiro::obtener_existentes() + Zombi::obtener_existentes();
    }
    else if (nombre == S_BALA || nombre == S_ESCOPETA)
    {
        sobre_total = Escopeta::obtener_existentes();
    }
    else if (nombre == S_ESCOPETA)
    {
        sobre_total = Bala::obtener_existentes();
    }
    else if (nombre == S_CRUZ || nombre == S_AGUA_BENDITA || nombre == S_ESTACA)
    {
        sobre_total = Cruz::obtener_existentes() + Agua_bendita::obtener_existentes() + Estaca::obtener_existentes();
    }
    int cantidad_existentes = this->obtener_cantidad_existentes(nombre);
    if (sobre_total > 0)
    {
        return ((float)cantidad_existentes / (float)sobre_total);
    }
    else
    {
        return 0;
    }
}
