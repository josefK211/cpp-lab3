#pragma once

#include "Stocznia.hpp"

unsigned int transportujFlota(unsigned int towar)
{
    if (towar == 0)
        return 0; // Jeœli towar = 0, nic nie transportujemy

    Stocznia     stocznia;
    unsigned int przetransportowanyTowar = 0;
    unsigned int liczbaZaglowcow         = 0;

    while (przetransportowanyTowar < towar) {
        Statek* statek = stocznia(); // Tworzymy statek przy u¿yciu fabryki
        przetransportowanyTowar += statek->transportuj();

        // Sprawdzamy, czy statek jest ¿aglowcem
        if (dynamic_cast< Zaglowiec* >(statek) != nullptr) {
            ++liczbaZaglowcow;
        }

        delete statek; // Usuwamy stworzony statek
    }

    return liczbaZaglowcow;
}