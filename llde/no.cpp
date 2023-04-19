#include "no.h"

namespace Pedro
{
    no::no() : dado(0),
               proximo(0),
               anterior(0)
    {
    }

    no::no(int dado) : dado(dado),
                       proximo(0),
                       anterior(0)
    {
    }

    no *no::getProximo() const
    {
        return proximo;
    }

    void no::setProximo(no *newProximo)
    {
        this->proximo = newProximo;
    }

    no *no::getAnterior() const
    {
        return anterior;
    }

    void no::setAnterior(no *newAnterior)
    {
        this->anterior = newAnterior;
    }

    int no::getDado() const
    {
        return dado;
    }
}
