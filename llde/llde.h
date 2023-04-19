#ifndef LLDE_H
#define LLDE_H
#include "no.h"
#include <QString>

namespace Pedro
{
    class llde
    {
    private:
        int quantidadeElementos;
        no* inicio;
        no* fim;
    public:
        llde();
        bool estaVazia()const;
        void inserirInicio(int);
        QString obterDados();
        int getQuantidadeElementos();
        int acessarInicio();
        int retirarInicio();
    };
}

#endif // LLDE_H
